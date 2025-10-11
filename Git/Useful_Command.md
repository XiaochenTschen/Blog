``
#### Log
`git log --oneline` : 用单行显示commit记录
`git log -5 --oneline` : 用单行显示最近5条commit记录

#### Patch
使用场景： 如果在某个分支修改的代码无法push，这个时候可以生成一个diff文件发送给其他人，其他人就可以通过patch将改动应用到自己的代码中。
生成diff文件： `git diff commit_sha > patch.diff`