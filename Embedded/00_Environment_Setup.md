使用开源软件进行嵌入式软件开发，MCU选择stm32F401系列，stm32nucleo开发板，自带ST-LINK.

### 软件编译工具
使用开源的Arm GNU Toolchain. 下载并解压工具包，将arm-gnu-toolchain文件夹放到/usr/local/文件夹下并保证该路径已经添加到PATH变量中。

### Debugger
使用ST-LINK,相应的驱动软件可以git自行下载编译安装：
```bash
git clone https://github.com/stlink-org/stlink.git
cd stlink

cmake -DCMAKE_BUILD_TYPE=Release .
make
sudo make install
sudo ldconfig
```
为了确保不需要 root 权限就能访问 ST-Link 设备，你可能需要安装 UDEV 规则,ST-Link仓库中通常包含了一个 UDEV 规则文件，你可以将它复制到 /etc/udev/rules.d/ 目录下：
```bash
sudo cp config/udev/rules.d/49-stlinkv*.rules /etc/udev/rules.d/
sudo udevadm control --reload
```
使用usb连接开发板，执行st-info检测是否正常运行。
使用st-util可以启动一个debuger服务器，这个时候如果在新的命令行中调试代码 arm-none-eabi-gdb ./firmware.elf， 可以检测debugger是否能正常工作。
需要注意的是，新的Ubuntu系统使用的是libncursesw.so.6,但是rm-none-eabi-gdb需要libncursesw.so.5,解决方法是创建一个libncursesw.so.5软链接指向libncursesw.so.6.

### 第三方库
使用libopencm3

### VS Code
需要安装Cortex-Debug扩展，并准备相应的配置文件。

```json
// c_cpp_properties.json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [
                "STM32F4",
                "__ARM_ARCH_7EM__"
            ],
            "compilerPath": "/usr/local/arm-gnu-toolchain/bin/arm-none-eabi-gcc",
            "cStandard": "c99",
            "cppStandard": "c++14",
            "intelliSenseMode": "gcc-arm"
        }
    ],
    "version": 4
}

// tasks.json
{
    "version": "2.0.0",
    "tasks": [
      {
        "type": "shell",
        "label": "build_debug",
        "options": {
          "cwd": "app"
        },
        "command": "make bin",
        "problemMatcher": "$gcc"
      }
    ]
}

// launch.json
{
    "configurations": [
      {
        "name": "ST-Link: Debug Application",
        "cwd": "${workspaceFolder}/app",
        "executable": "./firmware.elf",
        "servertype": "stutil",
        "request": "launch",
        "type": "cortex-debug",
        "device": "STM32F401xD",
        "runToEntryPoint": "main",
        "interface": "swd",
        "preLaunchTask": "build_debug"
      },
      {
        "name": "ST-Link: Attach to Application",
        "cwd": "${workspaceFolder}/app",
        "executable": "./firmware.elf",
        "servertype": "stutil",
        "request": "attach",
        "type": "cortex-debug",
        "device": "STM32F401xD",
        "runToEntryPoint": "main",
        "interface": "swd"
      },
    ]
}
```