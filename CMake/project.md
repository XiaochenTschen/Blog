**project** 是 CMake 中的一个命令，它用于定义当前正在处理的项目的信息。这个命令对于大多数 CMake 项目都是必要的，因为它定义了许多有用的变量，这些变量在后续的 CMake 命令中经常使用。
当调用 project 时，它可以接受许多参数，但最常见的参数是项目名称，以及可选的版本号和所支持的语言。

这里是一些基本用法：

```cmake
project(MyProject) #设置项目名称，这里默认的工作语言是C和C++
project(MyProject LANGUAGES CXX) #设置项目名称，设置工作语言是C++
project(MyProject VERSION 1.2.3) #设置项目名称，设置项目版本
```

调用 project 会设置一系列的变量，包括但不限于：
1. PROJECT_NAME: 项目名称。
2. PROJECT_SOURCE_DIR 和 PROJECT_BINARY_DIR: 项目的源代码和构建目录的路径。

*PROJECT_SOURCE_DIR:*
这个变量指向你的项目的源码根目录，也就是最顶层的 CMakeLists.txt 文件所在的地方。如果在项目的子目录中有其他 CMakeLists.txt 文件，那么在这些子目录中 PROJECT_SOURCE_DIR 仍然指向顶层目录。

*PROJECT_BINARY_DIR:*
这个变量指向你的项目的构建根目录。当你运行 cmake 命令来配置项目时，你会指定一个构建目录，这通常是一个空目录，用于存放所有构建产生的文件（如编译后的对象文件、可执行文件等）。PROJECT_BINARY_DIR 就是这个构建目录的路径。
通常，为了保持源码的清洁，开发者会在源码目录之外选择一个构建目录，这种方式称为“外部构建”（out-of-source build）。但是，如果你直接在源码目录中运行 cmake，则源码目录和构建目录会相同，这称为“内部构建”（in-source build）。外部构建是推荐的方式，因为它不会将构建产生的文件混合到源代码中。

比如有如下的文件结构：
```bash
/my_project/             <-- 源码根目录
    CMakeLists.txt       <-- 顶层的 CMakeLists.txt
    /src/
    /include/
/build/                  <-- 构建目录
```
如果你在 /build/ 目录中运行 cmake ..，那么：
PROJECT_SOURCE_DIR 会指向 /my_project/
PROJECT_BINARY_DIR 会指向 /build/

___

下面是一个CMakeList的简单示例
```cmake
project(code) # 设置项目名称为code

add_library(${PROJECT_NAME}
    code.cpp
)
```

在CMake中，\${...} 用于变量替换或变量展开。
$: 它指示后面是一个变量名，需要进行变量替换。
{...}: 花括号用于围绕变量的名称，它们定义了变量名的开始和结束。这是非常有用的，尤其是当变量名的后面紧跟其他字符时，花括号可以明确标明变量的边界，避免混淆。

add_library将会单独介绍用法。