``
**tar**: Unix/Linux默认安装的，主要功能是进行归档(打包)，也可以配合压缩算法进行压缩/解压。
- -c：创建归档（create）
- -x: 解包，回复(extract)
- -f: 指定归档的文件名
- -z: 结合gzip进行压缩
- -v: 显示详细过程(verbose)

使用范例：
- `tar -czfv archive.tar.gz path/to/dir`: 创建gzip压缩包
- `tar -xzfv archive.tar.gz`: 解压到当前目录
----

**find**: 查找文件和文件夹
`find [path] [options] [expression]`
- -type: f(file), d(directory)
- -name: 支持通配符(e.g. "*.cpp")
- -size: e.g. +1M
- -exec: 对查找结果执行指令，e.g. -exec rm {} \;
---

**rg**
- -g: glob, e.g. -g "*.cpp"
- -n: 显示匹配内容所在的行号
- -H: 显示文件名
- -i: 忽略大小写
---

**ln**
`ln -s /path/to/file ./link_name`: 创建软链接

**ls**
- -l: 长格式列表，显示权限，大小，修改时间
- -h: 人类可读的大小格式
- -a: 显示隐藏文件
- -S: 按照大小排序
- -t: 按照修改时间排序

`du -sh file_or_dir`: 显示文件或者文件夹大小