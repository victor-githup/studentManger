#ifndef __STUDENT_H__
#define _STUDENT_H__

/*
* ͷ�ļ�����
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//#include <dos.h>

/*
* �ṹ�嶨��
*/
struct student {
	int num;			//ѧ��
	char name[10];		//����
	double expe;		//ʵ���
	double exec;		//ѡ�޿�
	double requ;		//���޿�
	double sum;			//�ܷ�
};

/*
* �궨��
*/
#define FORMAT "%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n"
#define LEN sizeof(struct student)
#define DATA stu[i].num,stu[i].name,stu[i].exec,stu[i].expe,stu[i].requ,stu[i].sum

/*
* ȫ�ֱ�������
*/
struct student stu[1000];
/*

* ��������
*/
//¼��ѧ���ɼ�
void in(void);
//��ʾѧ����Ϣ
void show(void);
//�����ܷ�����
void order(void);
//ɾ��ѧ���ɼ���Ϣ
void del(void);
//�޸�ѧ���ɼ���Ϣ
void modify(void);
//���˵�
void menu(void);
//����ѧ����Ϣ
void insert(void);
//����������
void total(void);
//����ѧ����Ϣ
void search(void);

#endif
