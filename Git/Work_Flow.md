``
### 对Repo有读写权限的

#### Git Clone
`git clone`之后进入repo，会默认到main分支，通常情况下不应该对main分支的代码进行修改，这样做的话会对后面的同步造成很大的问题，应该根据开发任务创建相应的分支，在开发分支上进行代码开发。

#### Git Branch
首先可以先确认一下自己处于正确的分支上： `git branch`.

确认好分支以后，保险期间同步一下远端代码，防止有新的更新被推送到远端。
```bash
git fetch origin
git switch main # skip if already in main
git pull --ff-only # 确保本地main和远端main保持一致，也就是本地没有对main做任何修改
```

基于main分支创建新的开发分支： `git switch -c feature/my_task main`.
或者`git fetch origin`后，不需要更新本地main分支，直接创建新分支：`git switch -c feature/my_task origin/main`

开发任务完成后，将该分支推送到远端： `git push -u origin feature/my_task`

#### Stash
如果在开发过程中，需要临时完成一个其他的功能，这种情况下可以先将当前branch的内容保存起来，切换回main分支，拉取最新的更新，然后创建新的分支完成PR，最后返回之前的分支，导出之前的内容继续工作。
```bash
git stash push -m "message" # 只保存已跟踪的文件的修改
# git stash push -u -m "message" # 未跟踪的文件也一起保存

git switch main
git pull --ff-only

git switch -c feature/new-pr

git switch feature/dev_branch
git stash pop
```

#### Rebase
在开发分支上工作的时候会遇到这样的情况，main分支推送了更新，里面含有开发需要的代码，或者开发分支需要同步代码以便完成PR，这个时候就需要进行rebase.

首先下载最新的更新：`git fetch origin`.

下载完更新后，在开发分支下进行交互式rebase：`git rebase -i origin/main`.

Rebase会将开发分支上所有的commit放到main分支commit的前面，这个时候可以在打开的文本编辑器里面选择对每一个开发分支commit的操作：

1. pick(p): 选择保留该commit及其message
2. fixup(f): 丢弃该commit的message，将该commit的代码改动合并到上一个pick的提交。
3. sqush(s): 将该commit的代码改动合并到上一个pick的提交，但是保留该commit的message，并和上一个message合并，下一步允许手动编辑合并后的message.
4. drop(d): 放弃该commit，包括对代码所作的修改和commit message.

这个时候列出的commit从上到下是按照时间从旧到新的顺序，需要注意的是最上面的信息是需要pick的，否则会报错。Sqush的信息会合并到上一个(旧的)commit里面，并且在接下来的编辑界面中可以进行编辑。

如果有文件内容发生冲突的话，解决冲突。
使用`git status`查看有哪些文件存在冲突。通常会看到两类冲突类型，一类是`both modified`, 比如同一个文件的同一个地方有不同的修改；一类是`both added`, 比如同时添加了相同的文件。
可以打开有冲突的文件，手动删除导致冲突的代码，或者使用VS Code提供的插件选择使用哪部代码分，或者使用git指令：
```bash
git checkout --ours -- path/to/file   #保留main的内容 OURS
git checkout --theirs -- path/to/file #保留开发分支的内容 THEIRS
```

保存解决完冲突的文件，并添加该文件：`git add path/to/file`. 需要注意，解决一个冲突文件，add相应的文件，直到 `git status` 不显示存在冲突文件了。
继续rebase: `git rebase --continue`.

完成rebase后，将改动推送到远端：`git push -f`.
或者使用更安全的指令先检查远端分支是否有人在你 rebase 期间又推了新的提交，如果有，它会拒绝覆盖，避免误删同事的工作： `git push --force-with-lease`.

