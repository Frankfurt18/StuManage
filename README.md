# StuManage
简易的学生管理系统

1、简介：
			              学院级学生管理系统
（1）  每个学生的信息包括：学号，姓名，班级，年级，修的课程，每门课程的成绩；
（2）  支持添加、删除学生功能，将该学生相关的所有信息删除（管理员权限）；
（3）  支持添加、删除课程的功能，需要将该课程的所有分数信息都删除（管理员权限）；
（4）  支持输入某个学生某门课程的分数的功能（教师权限）；
（5）  支持分数统计，可统计每门课程的及格率，平均分数（教师权限）；
（6）  支持列表输出:将所有学生的某门功课成绩作成表格输出（简单文本格式）（教师权限）;
（7）  支持学生信息的查询、保存为磁盘文件（学生权限）。  

2、环境：
  VS2017、win10、面向过程编程
  
3、vertion:  2018/12/24/1.1/

4、相关问题：
  a、一开始运行时出现野指针就是缺少数据文件（data文件夹，password文件夹）；
  b、程序突然奔溃基本上就是因为你输入的字符串超过了程序中定义的大小；
  c、文件出现乱码要么是你输入的字符串超过了程序中定义的大小；要么就是你用其他的编辑器打开了.data文件并将其转码了，
     据我目前所知，好像只支持ANSI码

5、缺陷：
  a、各数组设置的太小，容易因为用户的输入出问题；最好用指针代替数组；
  b、代码量啰嗦，重复代码太多，看起来很臃肿，有很多算法值得简化；
  c、未对各种异常做出处理；
