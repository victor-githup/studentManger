#ifndef __STUDENT_H__
#define _STUDENT_H__

/*
* 头文件包含
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//#include <dos.h>

/*
* 结构体定义
*/
struct student {
	int num;			//学号
	char name[10];		//姓名
	double expe;		//实验课
	double exec;		//选修课
	double requ;		//必修课
	double sum;			//总分
};

/*
* 宏定义
*/
#define FORMAT "%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n"
#define LEN sizeof(struct student)
#define DATA stu[i].num,stu[i].name,stu[i].exec,stu[i].expe,stu[i].requ,stu[i].sum

/*
* 全局变量声明
*/
struct student stu[1000];
/*

* 函数声明
*/
//录入学生成绩
void in(void);
//显示学生信息
void show(void);
//按照总分排序
void order(void);
//删除学生成绩信息
void del(void);
//修改学生成绩信息
void modify(void);
//主菜单
void menu(void);
//插入学生信息
void insert(void);
//计算总人数
void total(void);
//查找学生信息
void search(void);

#endif
