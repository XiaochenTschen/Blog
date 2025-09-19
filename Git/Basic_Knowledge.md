### 本地Git的三个区域

#### Working Directory
能够看到的，可进行编辑所谓实际文件。
`git status` 可以查看哪些文件有改动或被新创建了。
`git restore --file` 可以丢弃在工作去对该文件的改动。

#### Index / Staging Area
索引区，也是暂存区，可以使用`git add`把修改放到这里，告诉Git"这些修改我想要commit"。
`git add .` 将所有的改动放到暂存区。
`git add directory/file` 将文件夹内部的改动的文件，或某个特定的文件，放到暂存区。
`git restore --staged file` 将文件从暂存区移除。

#### Local Repository
本地仓库，存放commit对象，分支，tag等的数据库。
`git commit` 可以把暂存区的内容打包成一个commit，放进本地的仓库。

### 远端仓库 Remote Repository
`git push` 把本地仓库的commit上传到远端。
`git fetch` 将远端的commit下载到本地仓库，但不更新工作区。(如果只有一个远端， `git fetch`和`git fetch origin`是一样的效果；如果有多个远端，如果不指明远端，`git fetch`会下载所有的远端信息)。
`git fetch origin` 之后，如果想引用从远端获取的branch，需要使用`origin/branch_name`

### Origin vs Upstream
`origin`是默认远端名，当使用`git clone`克隆一个仓库到本地的时候，git会自动把这个远端取名为`origin`. 使用`git remote -v`可以产看origin链接。

`upstream`常见于fork工作流，当fork其他人的仓库，对fork仓库clone后，`origin`就是远端的fork仓库，如果想跟随上游作者的更新，就手动添加上游官方仓库为`upstream`. 通常对`upstream`只有读权限(fetch/pull)，没有push权限。
添加`upstream`的示例方法：`git remote add upstream https://github.com/original/project.git`.

除此之外，`upstream`也能表示“当前本地分支所追踪的远端分支”。比如本地创建了一个分支，远端还没有这个分支，把该分支推送到远端的时候就需要让两者建立联系，可以使用：`git push -u origin branch`. 当然也可以不使用upstream，只不过后续使用push/pull的时候就得写上远端分支的名字：`git pull origin branch`.

#### Merge vs Rebase
Rebase会将本分支上未在目标分支上的commit逐个重新放到目标分支最新提交的头部，这些commit的SHA会发生改变，这样commit历史会呈现直线，push的时候需要强推。

Merge的时候会把另一个分支的内容合并到当前分支上。如果可以快进，只需要将指针前移，不能快进则会创建一个merge commit. 
Merge的commit历史会呈现分叉和合并点(如果一直快进的话也会呈现快进)，因为没有改写既有的提交，只是多了一个merge commit，所以也不需要强推。

