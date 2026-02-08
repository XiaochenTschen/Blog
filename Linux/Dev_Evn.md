### PATH
命令行中分行打印PATH变量
```bash
echo $PATH | tr ':' '\n'
```
PATH变量分为全局配置和用户配置，全局的PATH变量需要修改/etc/profile文件，用户配置可以修改~/.bashrc文件，比如需要添加新的变量可以使用如下指令:
```bash
export PATH=$PATH:/your/new/directory
```