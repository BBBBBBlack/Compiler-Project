# 简单的Git合作教程
1. 安装Git
首先，你需要在你的计算机上安装Git。你可以从[git官方网站](https://git-scm.com/downloads)上下载适合你操作系统的版本，并按照提示进行安装 ~~一路next~~。

2. 克隆仓库
在你的本地计算机上，打开终端或命令行工具，使用git clone命令克隆仓库到本地。例如，执行以下命令：
```
git clone https://gitee.com/yJader/fzu_compiler_front-end.git
```

3. 切换分支
使用git checkout命令创建并切换到一个新的分支，这样你就可以在该分支上开展工作。例如，执行以下命令：

git checkout -b <分支名称>
将<分支名称>替换为你想要创建的分支名称。

4. 进行修改
在你的本地仓库目录中进行你的工作。你可以添加、修改或删除文件，根据需求进行编码和开发。

5. 提交更改
当你完成一部分工作后，使用以下命令将更改提交到你的本地仓库：
```
git add .
git commit -m "提交说明" # 如 完成字符转换模块
```
其中，.表示提交所有更改，提交说明是对你所做更改的简要描述。
第一次使用的时候可能要求你填写name和email
```
*** Please tell me who you are.

Run

  git config --global user.email "you@example.com"
  git config --global user.name "Your Name"

to set your account's default identity.
Omit --global to set the identity only in this repository.
```
按照要求执行
```
git config --global user.email "<你的邮箱>" # 邮箱可以随意
git config --global user.name "<你的名字>"
```

6. 推送到远程仓库
使用git push命令将你的本地更改推送到远程仓库。例如：
```
git push origin <分支名称>
```
将<分支名称>替换为你正在工作的分支名称。

7. 合并代码
如果你想将你的更改合并到主分支（如main或master），可以在代码托管平台上发起一个Pull Request（PR）。其他成员将对你的代码进行审查，并讨论是否接受你的更改。

8. 更新拉取
在开始工作之前，记得执行以下命令将远程仓库的最新更改拉取到你的本地仓库：
```
git pull origin <分支名称> # (通常是master)
```