下面是一个CMocka测试框架构建和测试的CMakeLists，通过逐行的解释来学习CMake指令在实际项目中的应用。

下面是一个顶层的CMakeLists文件内容：

```cmake
# 设置CMake的最低版本
cmake_minimum_required(VERSION 3.5.0)
#设置CMP048策略为NEW，表示项目版本号由project()命令的VERSION子选项处理
cmake_policy(SET CMP0048 NEW)

# Specify search path for CMake modules to be loaded by include() and find_package()
# 将 ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules 路径添加到 CMAKE_MODULE_PATH 中，使 CMake 可以在这个路径下查找模块文件。
# CMAKE_MODULE_PATH是CMake的一个内置变量，这个变量用于CMake查找模块文件的路径，模块文件通常是以.cmake为结尾的脚本文件
# list()用来操作和管理列表类型的数据，可以根据需求选择不同的操作方式，比如APPEND,SET,DELETE等
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")

### Add defaults for cmake
### 包含自定义的CMake配置文件
# 包含一个名为 DefineCMakeDefaults.cmake 的文件，这个文件通常用于设置一些默认的 CMake 配置。
# These defaults need to be included before the project() call.
include(DefineCMakeDefaults)

# This will provide -DCMAKE_BUILD_TYPE=Profiling
# and -DCMAKE_BUILD_TYPE=AddressSanitizer
# 包含 DefineCompilerFlags.cmake 文件，这个文件可能定义了用于不同编译模式的编译器标志。
include(DefineCompilerFlags)
# 包含 DefinePlatformDefaults.cmake 文件，设置平台相关的默认值。
include(DefinePlatformDefaults)

project(cmocka VERSION 1.1.7 LANGUAGES C)

# global needed variables
# 定义 APPLICATION_NAME 变量，并将其值设置为 PROJECT_NAME（即 cmocka）
set(APPLICATION_NAME ${PROJECT_NAME})

# SOVERSION scheme: CURRENT.AGE.REVISION
#   If there was an incompatible interface change:
#     Increment CURRENT. Set AGE and REVISION to 0
#   If there was a compatible interface change:
#     Increment AGE. Set REVISION to 0
#   If the source code was changed, but there were no interface changes:
#     Increment REVISION.
set(LIBRARY_VERSION "0.8.0")
set(LIBRARY_SOVERSION "0")

# include cmake files
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(DefineOptions.cmake)
include(CPackConfig.cmake)
include(CompilerChecks.cmake)

# disallow in-source build
# 这段代码确保项目不能在源目录中构建，要求用户在独立的构建目录中进行构建。这样可以防止源代码被构建产生的文件污染。
include(MacroEnsureOutOfSourceBuild)
macro_ensure_out_of_source_build("${PROJECT_NAME} requires an out of source build. Please create a separate build directory and run 'cmake /path/to/${PROJECT_NAME} [options]' there.")

# config.h checks
include(ConfigureChecks.cmake)
# 将 config.h.cmake 文件配置为 config.h，并将其输出到构建目录中。这通常用于生成项目的配置头文件。
configure_file(config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)

# MinGW DLL Naming Workaround
if (MINGW)
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
endif (MINGW)

# check subdirectories
# add_subdirectory() 命令用于递归构建子目录中的 CMakeLists.txt 文件
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(doc)

include(AddCMockaTest)
if (UNIT_TESTING)
    add_subdirectory(tests)
endif (UNIT_TESTING)

if (WITH_EXAMPLES)
    add_subdirectory(example)
endif ()

# pkg-config file
configure_file(cmocka.pc.cmake ${CMAKE_CURRENT_BINARY_DIR}/cmocka.pc @ONLY)
install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/cmocka.pc
  DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/pkgconfig
  COMPONENT
    pkgconfig
)

write_basic_package_version_file(${PROJECT_NAME}-config-version.cmake
                                 COMPATIBILITY
                                     AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
        COMPONENT devel)

# Add 'make dist' target which makes sure to invoke cmake before
add_custom_target(dist
                  COMMAND ${CMAKE_MAKE_PROGRAM} package_source)

# Link combile database for clangd
execute_process(COMMAND cmake -E create_symlink
                "${cmocka_BINARY_DIR}/compile_commands.json"
                "${cmocka_SOURCE_DIR}/compile_commands.json")

```
---

下面这段代码是在example文件夹下的CMakeLists里面的。
```cmake
project(cmocka-examples C)

# 这段代码为 calculator.c、allocate_module.c 和 assert_module.c 设置编译属性，将它们的 COMPILE_DEFINITIONS 变量设置为 UNIT_TESTING=1
# 这通常用于在编译这些文件时定义一个 UNIT_TESTING 宏，启用某些仅在测试模式下使用的代码片段
set_source_files_properties(calculator.c
                            allocate_module.c
                            assert_module.c
                            PROPERTIES
                                COMPILE_DEFINITIONS
                                    UNIT_TESTING=1)


### The most simple test
add_cmocka_test(simple_test #定义一个名为 simple_test 的 CMocka 测试
                SOURCES simple_test.c # 指定该测试使用的源文件是 simple_test.c
                COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS} #设置测试的编译选项，使用项目中默认的 C 编译标志
                LINK_OPTIONS ${DEFAULT_LINK_FLAGS} #设置测试的链接选项，使用项目中默认的链接标志
                LINK_LIBRARIES cmocka::cmocka) #将 CMocka 库链接到测试中
# 为测试 simple_test 设置适当的环境变量，确保在 Windows 上 DLL 能被正确找到
add_cmocka_test_environment(simple_test)

### Allocate module test
# 设置 allocate_module_test 的属性，标记这个测试为预期会失败 (WILL_FAIL 1)。这意味着在测试失败时不会被认为是错误，因为这是预期的行为
add_cmocka_test(allocate_module_test
                SOURCES allocate_module.c allocate_module_test.c
                COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
                LINK_OPTIONS ${DEFAULT_LINK_FLAGS}
                LINK_LIBRARIES cmocka::cmocka)
add_cmocka_test_environment(allocate_module_test)

set_tests_properties(allocate_module_test
                     PROPERTIES
                        WILL_FAIL 1)

### Assert macro test
add_cmocka_test(assert_macro_test
                SOURCES assert_macro.c assert_macro_test.c
                COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
                LINK_OPTIONS ${DEFAULT_LINK_FLAGS}
                LINK_LIBRARIES cmocka::cmocka)
add_cmocka_test_environment(assert_macro_test)

set_tests_properties(assert_macro_test
                     PROPERTIES
                        WILL_FAIL 1)

### Assert module test
add_cmocka_test(assert_module_test
                SOURCES assert_module.c assert_module_test.c
                COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
                LINK_OPTIONS ${DEFAULT_LINK_FLAGS}
                LINK_LIBRARIES cmocka::cmocka)
add_cmocka_test_environment(assert_module_test)

set_tests_properties(assert_module_test
                     PROPERTIES
                        WILL_FAIL 1)

if (NOT WIN32)
    add_subdirectory(mock)
endif()

```
