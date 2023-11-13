```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++ - Build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "g++ build active file",
            "miDebuggerPath": "/usr/bin/gdb"
        }
    ]
}
```

### 必须严格设置的选项
"type": 指定了调试器的类型。对于C++，通常是 "cppdbg"（对于使用GDB或LLDB的情况）。这个选项是必须的，因为它告诉VS Code使用哪种类型的调试器。

"request": 指定了请求的类型。对于启动新的调试会话，应该使用 "launch"。这个选项是必须的，因为它定义了调试会话的基本模式。

"program": 指定了要调试的可执行文件的路径。这应该指向你的编译输出（例如，编译好的.exe文件）。路径可以是硬编码的，也可以包含变量，如 "${workspaceFolder}/path/to/your/executable"。

"miDebuggerPath": 指定了MI（Machine Interface）兼容调试器的路径，通常是GDB或LLDB。这个路径必须正确，否则VS Code无法启动调试器。

### 可以自定义的选项
"name": 这是在VS Code用户界面中显示的调试配置的名称。这个值可以根据你的喜好来自定义，不会影响调试过程的实际运行。

"args": 这个数组包含了传递给程序的命令行参数。这取决于你的程序是否需要命令行参数以及它们的具体值。

"stopAtEntry": 一个布尔值，决定了调试器是否在程序入口处自动暂停。设置为 true 时，调试会在程序开始执行的地方暂停。

"cwd": 指定了程序的当前工作目录。这通常设置为 "${workspaceFolder}"，表示程序将在项目的根目录下执行。

"environment": 一个对象数组，用于设置额外的环境变量。这些环境变量仅在调试会话中有效。

"externalConsole": 一个布尔值，用于控制是否在外部控制台/终端中运行调试的程序。这取决于你是否想在外部终端中查看程序的输出或与之交互。

"setupCommands": 这个数组包含了一系列在启动调试会话时自动执行的GDB/LLDB命令。这些通常用于配置调试器的行为，例如启用整洁打印。

"preLaunchTask": 这是在启动调试会话之前自动执行的任务的名称，通常用于编译程序。它引用了tasks.json中定义的一个任务。