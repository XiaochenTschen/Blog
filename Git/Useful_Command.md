``
#### Config
``` bash
git config --global user.name "Vorname Nachname"
git config --global user.mail "email@address"
git config --global init.defaultBranch main
git config --global core.editor "vim"
git config --global credential.helper store

git config --list
```

#### Branch
`git branch -m new-branch name` : change the branch name
`git remote -v` : list repo remote url 
#### Log
`git log --oneline` : 用单行显示commit记录
`git log -5 --oneline` : 用单行显示最近5条commit记录
`git show commit_hash` : 这个命令会显示commit的详细信息，包括作者、日期、commit信息和改动的文件内容。


#### Patch
使用场景： 如果在某个分支修改的代码无法push，这个时候可以生成一个diff文件发送给其他人，其他人就可以通过patch将改动应用到自己的代码中。
生成diff文件： `git diff commit_sha > patch.diff`

diff指令也可以用来比较分支之间的差别：
`git diff origin/main`: 比较当前分支和远端main分支的区别
`git diff origin/main -- path_to_file`: 只比较某一个文件

#### Checkout
如果不小心修改了某个文件，想要将该文件改回最开始的状态，或者将它恢复成跟main分支相同的状态，可以使用如下指令： `git checkout origin/main -- .vscode/launch.json`. 其中 `--` 用来分隔分支名和文件名。

#### Clean
`git clean`: 清理工作区的文件，配合以下参数
`-f`: 跟git的设置有关，有该参数使得clean成为可能。
`-d`: 没有该参数只会删除untancked file, 有了该参数可以删除tracked directory.
`-x`: 可以删除被ignore的文件。
`-n`: 可以先观察有哪些文件和文件夹可以被删除。