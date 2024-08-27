### 如何使用VS Code进行debug
使用VS Code进行debug，需要在项目根目录的.vscode文件夹下配置launch.json文件。
用C语言的项目举例，要对程序进行debug，launch文件可以按照如下的示例进行设置。
```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug CMake Project",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/build/myProgram", // 编译后的可执行文件路径
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "CMake Build", // 在调试前执行 CMake 构建任务
      "miDebuggerPath": "/usr/bin/gdb",
      "logging": { "engineLogging": false },
      "internalConsoleOptions": "openOnSessionStart"
    }
  ]
}
```
在launch配置文件中，必须要进行配置的选项包括：

1. "name": 同一个launch文件可以设置不同的debug配置，通过名称可以在debug选项列表中选择合适的调试选项。
2. "type": 指定调试器的类型，对于C/C++项目，通常是cppdbg。
3. "request": 调试的请求类型，通常是launch，代表着将程序启动并进行调试。
4. "program": 指定要调试的可执行文件的路径。
5. "cwd": 指定程序运行时的当前工作目录。
6. "MIMode": 调试器模式，通常是GDB。
7. "miDebuggerPath": 指定GDB的路径，如果该路径已经在系统路径中，那么可以忽略这个选项。

可以进行选配的项目包括：

1. "args": 传递给程序的命令行参数。如果你的程序在运行时需要参数，可以在这里指定.
2. "stopAtEntry": 如果设置为 true，调试器将在程序入口处（通常是 main 函数）停止。可以帮助你在程序开始时立即控制调试。
3. "preLaunchTask": 在调试会话开始之前执行的任务，通常是由task.json文件设置好的。对于已经编译好的程序，这通常不需要设置，使用CMake管理编译的程序也不需要设置。