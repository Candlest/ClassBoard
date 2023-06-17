# Class Board

  **Class Board**是一款使用Qt/C++开发的，针对**SEEWO**及其它教学一体机设计的，用于**显示教学信息**的壁纸软件。

**！！！WINDOWS ONLY！！！**

- [Class Board](#class-board)
  * [Background](#background)
  * [Install](#install)
  * [Contributors](#contributors)
  * [License](#license)

<small><i><a href='http://ecotrust-canada.github.io/markdown-toc/'>Table of contents generated with markdown-toc</a></i></small>

## Background

  大概是2023年4月，我在Github发现了这个项目：[ClassTool](https://github.com/IcariaWorks/ClassTools)

> ClassTool
> 
> 一个用在班级电脑上面的动态壁纸系统，显示高考倒计时、作业、课程表、值日生等

  作为电教，在班级电脑上使用了一下，遇到了很多问题。其中，最大的问题是ClassTool的桌面背景层实现不能在Windows 7上运行。

  我校希沃大概是17左右引进的，在上面编写一个可用的桌面壁纸软件需要面对以下问题：

#### Windows 7

  Windows 7意味着失去支持，我们无法使用：

- Qt 6
- WebView2（最新的WebView2已经停止对Windows 7支持，这意味着Tarui + Rust方案无法使用）
- 最新的WinUI 3
- 轻便的UWP

#### 冰点还原

  一个Windows 7尚可接受，因为我们可以自行安装相关库为它“续命”。不过我们还有冰点还原，这意味着：

- 一切不提供portable版本Runtime的都无法使用，比如.NET Framework的高版本库（>4.0）、WebView2
- 我们的软件必须是portable的，并且失去了开机自启的natural right（笑）。

#### 校园白名单机制

  一体机接入校园网，只能访问少数网站，比如希沃官网，学校官网，百度首页。这让天气显示，每日一言等功能的实现更加困难了。

#### 性能羸弱（NVIDIA GT720）

  GT720的卡，跑3k分辨率都会降帧到10~30fps，所以实现动态壁纸的优先级会很低。

  使用.NET Framework完成了初版，目前已经使用Qt重构，完成了一些基础功能

## Install

   可以从Release下载打包好的portable版本，也可以自行git clone，使用Qbs编译。

#### 从源代码安装

  先决条件：

- Qt Creator

- MSVC

- Qt 5.15.2 LTS（其他版本不保证可以通过编译）
  
  克隆本项目，在Qt Creator打开，设置好编译环境后，编译、打包即可。

## Usage

  解压Release压缩包，有如下文件：

| Name           | Type |
| -------------- | ---- |
| Background_Set | DIR  |
| kb.csv         | 课表文件 |
| ClassBoard.exe | 程序本体 |

*TO DO*

## Related Efforts

  本项目是对前辈ClassTool的拙劣模仿。ClassTool使用Electron + Vue.JS构建，美观简洁而大方。

> #### [ClassTool](https://github.com/IcariaWorks/ClassTools)
> 
> 一个用在班级电脑上面的动态壁纸系统，显示高考倒计时、作业、课程表、值日生等

  本项目使用C++/Qt构建，仅有`win32mod.cpp`实现插入背景层使用到了Win32API，Qt的可靠稳定、成熟高雅，从来不会让人失望Thanks♪(･ω･)ﾉ

> #### [Qt| Tools for Each Stage of Software Development Lifecycle](qt.io)
> 
> All the essential tools for all stages of Software Development Lifecycle: planning, design, development, testing, and deployment.

## Contributors

[@Candlest](https://github.com/Candlest)

  欢迎任何的贡献！

## License

  本项目使用**GPLv3**开源
