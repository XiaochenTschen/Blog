在使用add_libraries()或者add_executable()时，如果要列举的源文件数量比较多，可以使用file()来简化这部分工作。
**注意：在实际的项目中为了让文件依赖更加清晰，还是推荐将需要添加的文件依次列举出来**

假设项目结构如下：
```lua
/my_project
  |-- src/
      |-- file1.c
      |-- file2.c
      |-- subdir/
          |-- file3.c
  |-- CMakeLists.txt
```
在cmake文件中可以如下配置
```cmake
project(MyProject)
set(CMAKE_C_STANDARD 99)

# 使用 GLOB 获取 src 文件夹下的所有 .c 文件
file(GLOB SRC_FILES "src/*.c")

add_executable(MyExecutable ${SRC_FILES})
```

如果子文件夹下面的源文件也要一起添加，可以使用GLOB_RECURSE参数。
```cmake
# 递归获取 src 文件夹下的所有 .c 文件，包括子目录
file(GLOB_RECURSE SRC_FILES "src/*.c")
```

file()可以获取多个文件夹下面的文件。假设项目中src和lib文件夹下面都有要添加的文件，那么可以使用下面的指令
```cmake
# 获取 src 和 lib 文件夹中的所有 .c 文件
file(GLOB SRC_FILES "src/*.c" "lib/*.c")
```

如果除了文件夹下面的文件，还有一些额外的文件需要添加，可以使用list(APPEND)指令。
需要注意的是，被添加的文件可能会有文件路径的问题，利用camke定义的宏可以简化路径制定工作。
```cmake
# 获取 src 和 lib 文件夹中的所有 .c 文件
list(APPEND SRC_FILES "extra1.c" "extra2.c")
```