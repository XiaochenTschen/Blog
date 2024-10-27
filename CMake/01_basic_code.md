**'#'**: 
- 添加一行注释

**'#[[]]'**：
- 在中括号中可以添加多行的注释

**cmake_minimum_required(VERSION 3.0)**:
- 指定最低版本的cmkae

**project()**
- 设置项目的名称，项目源文件使用的语言。指明语言对于混合编程的项目很重要
- project(MySocketProject C CXX)

**set()**
- set指令可以设置不同的信息，最常见的是设置编程语言的标准
- set(CMAKE_C_STANDARD 99)
- set(CMAKE_C_STANDARD_REQUIRED ON)

**add_libraries()**
- 创建一个目标库(静态，共享，动态)，并指定构建该库所需要的源文件，这些源文件会一起编译形成一个库文件，然后会和其他的目标进行链接，最终形成可执行文件或其他库。下面是几个使用例子。
  add_library(MyLibrary STATIC src/mylibrary.cpp src/anotherfile.cpp) # 静态库
  add_library(MyLibrary SHARED src/mylibrary.cpp src/anotherfile.cpp) # 共享库
  add_library(MyPlugin MODULE src/plugin.cpp) # 模块库

**add_executable()**
- 定义和创建一个可执行文件目标。这个命令告诉 CMake 需要生成一个可执行文件，并指定该可执行文件所需要的源文件,基本的使用方法如下所示
  add_executable(app_name, source_file_name) # template
  add_executable(app add.c div.c main.c mult.c sub.c)
  add_executable(app add.c;div.c;main.c;mult.c;sub.c)

**target_link_libraries()**
- 定义完可执行文件目标后，可以使用该指令将使用add_libraries()生成的库或者其他本地的库文件链接到可执行文件中
- 使用add_libraries()生成库，那么在add_executable()指令的时候就不用将该库的源文件作为参数传递进去

**include_directories()**
- 指定编译器在编译源文件时应该搜索的头文件目录。它告诉编译器，当遇到 #include 预处理指令时，应该去哪些目录中查找头文件

**target_include_directories()**
- 如果只想设置某个编译目标搜索头文件的路径，可以使用target_include_directories()指令，其中也可以设置该头文件是不是对其他编译目标可见，控制更加精确
- include_directories()设置的路径对于当前的CMake和其下的subdirectories都是可见的。

**add_subdirectory()**:
- 添加子目录，并执行子模块下面的CMakeLists.txt文件

**include()**: 
- 包含并执行相应的cmake脚本文件

---

**configure_file()**:
- configure_file 是 CMake 中的一个指令，用于将一个输入文件（通常是一个模板文件）处理后输出为另一个文件。这个过程可以包括替换模板文件中的变量、条件处理等。通常用于生成配置文件、头文件或者其他需要根据构建环境动态生成的文件

**target_compile_options()**
- 使用该指令为特定的目标设置编译选项


