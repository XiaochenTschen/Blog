``
#### Log
`git log --oneline` : 用单行显示commit记录
`git log -5 --oneline` : 用单行显示最近5条commit记录

#### Patch
使用场景： 如果在某个分支修改的代码无法push，这个时候可以生成一个diff文件发送给其他人，其他人就可以通过patch将改动应用到自己的代码中。
生成diff文件： `git diff commit_sha > patch.diff`

#### Checkout
如果不小心修改了某个文件，想要将该文件改回最开始的状态，或者将它恢复成跟main分支相同的状态，可以使用如下指令： `git checkout origin/main -- .vscode/launch.json`. 其中 `--` 用来分隔分支名和文件名。
