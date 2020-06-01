#include "student.h"

//录入学生成绩
void in(void)
{
	int m = 0;
	char ch[2];
	FILE *fp;
	fp = fopen("data.txt","a+");
	if (fp == NULL) {
		printf("文件不存在\n");
		return;
	}
	while (!feof(fp)) {
		if (fread (&stu[m], LEN, 1,fp) == 1) {
			m++;
		}
	}
	fclose(fp);
	fp = NULL;
	if (m == 0) {
		printf("文件中没有记录\n");
	} else {
		show();
	}
	printf("输入学生信息?(y/n)\n");
	fflush(stdin);
	scanf("%s", ch);
	fp = fopen("data.txt","a");
	if (fp == NULL) {
		printf("文件不存在\n");
	return;
	}
	while (strncmp(ch,"Y",1) == 0 || strncmp(ch,"y",1) == 0) {
		printf("请输入录入学生Id:");
		fflush(stdin);
		scanf("%d", &stu[m].num);
		for (int i = 0; i < m; i++) {
			if (stu[i].name == stu[m].name) {
				printf("该学生ID已被征用\n");
				system("pause");
			fclose(fp);
			return;
			}
		}
		printf("请录入学生姓名:");
		fflush(stdin);
		scanf("%s",stu[m].name);
		printf("请录入学生实验课成绩:");
		fflush(stdin);
		scanf("%lf",&stu[m].expe);
		printf("请录入学生选修课成绩:");
		fflush(stdin);
		scanf("%lf", &stu[m].exec);
		printf("请录入学生必修课成绩:");
		fflush(stdin);
		scanf("%lf", &stu[m].requ);
		stu[m].sum = stu[m].exec + stu[m].expe + stu[m].requ;
		if (fwrite(&stu[m], LEN, 1, fp) != 1) {
			printf("保存失败\n");
			system("pause");
		} else {
			printf("%s的信息已录入\n",stu[m].name);
			m++;
		}
		printf("是否继续录入信息?(y/n)\n");
		fflush(stdin);
		scanf("%s",ch);
	}
	fclose(fp);
	printf("学生信息加载成功\n");
	system("pause");
}
//显示学生信息
void show(void)
{
	FILE *fp;
	int m = 0;
	fp = fopen("data.txt","rb");
	while (!feof(fp)) {
		if (fread(&stu[m], LEN, 1, fp) == 1) {
			m++;
		}
	}
	fclose(fp);
	printf("ID--------姓名--------选修--------实验--------必修课--------总分\n");
	for (int i = 0; i < m; i++) {
		printf(FORMAT,DATA);
	}
	system("pause");
}

//按照总分排序
void order(void)
{
	FILE *fp;
	struct student t;
	int i = 0;
	int j = 0;
	int m = 0;
	fp = fopen("data.txt", "r+");
	if (fp == NULL) {
		printf("文件不存在\n");
		return;
	}
	while (!feof(fp)) {
		if (fread(&stu[m], LEN, 1, fp) == 1) {
			m++;
		}
	}
	fclose(fp);
	fp == NULL;
	if (m == 0) {
		printf("文件中没有记录\n");
		return;
	}
	for (i = 0; i< (m - 1); i++) {
		for (j = (i + 1); j < m; j++) {
			if (stu[i].sum < stu[j].sum) {
				t = stu[i];
				stu[i] = stu[j];
				stu[j] = t;
			}
		}
	}
	fp = fopen("data.txt", "wb");
	if (fp == NULL) {
		printf("文件不存在\n");
		return ;
	}
	for(i = 0; i < m; i++) {
		if(fwrite(&stu[i], LEN, 1, fp) != 1) {
			printf("未正确保存\n");
			system("pause");
		}
	}
	fclose(fp);
	printf("保存成功\n");
	system("pause");
}
//删除学生成绩信息
void del(void)
{
	FILE *fp;
	int snum;
	int i,j;
	int m = 0;
	char ch[2];
	
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("文件不存在\n");
		return;
	}
	while (!feof(fp)) {
		if(fread(&stu[m], LEN, 1, fp) == 1) {
			m++;
		}
	}
	fclose(fp);
	fp == NULL;
	
	printf("请输入学号:");
	fflush(stdin);
	scanf("%d",&snum);
	for (i = 0; i < m; i++) {
		if (snum == stu[i].num) {
			printf("已找到该学生记录，是否删除？(y/n)");
			scanf("%s",ch);
			if (strncmp(ch, "Y", 1) == 0 || strncmp(ch, "y", 1) == 0) {
				for (j = i; j < m; j++) {
					stu[j] = stu[j+1];
				}
				m--;
				fp = fopen("data.txt","wb");
				if (fp == NULL) {
					printf("文件不存在\n");
					return;
				}
				for (j = 0; j < m; j++) {
					if (fwrite(&stu[j], LEN, 1, fp) !=1) {
						printf("can not save data\n");
						system("pause");
					}
				}
				fclose(fp);
				fp = NULL;
				printf("已删除\n");
			} else {
				printf("未删除该学生信息\n");
				break;
			}
		}
	}
	if (i == m + 1) {
		printf("没有找到该学生\n");
	}
	system("pause");
	

}
//修改学生成绩信息
void modify(void)
{
	FILE *fp;
	struct student t;
	fp = fopen("data.txt", "r+");
	if (fp == NULL) {
		printf("文件不存在\n");
		return;
	}
	int m = 0;
	while (!feof(fp)) {
		if (fread(&stu[m], LEN, 1, fp) == 1) {
			m++;
		}
	}
	if (m == 0) {
		printf("文件中没有记录\n");
		fclose(fp);
		return;
	}
	fclose(fp);
	show ();
	printf("请输入要修改的学生ID:");
	int sNum;
	scanf("%d", &sNum);
	int i = 0;
	for (i = 0; i < m; i++) {
		//find this student
		if (sNum == stu[i].num) {
			printf("已找到该学生,可以修改信息\n");
			printf("name:");
			scanf("%s", stu[i].name);
			printf("elective:");
			scanf("%lf", &stu[i].exec);
			printf("experiment:");
			scanf("%lf", &stu[i].expe);
			printf("required course:");
			scanf("%lf", &stu[i].requ);
			printf("修改成功\n");
			stu[i].sum = stu[i].exec + stu[i].expe + stu[i].requ;
			fp = fopen("data.txt", "wb");
			if (fp == NULL) {
				printf("文件不存在\n");
				return;
			}
			for (int i = 0; i < m; i++) {
				if (fwrite(&stu[i], LEN, 1, fp) != 1) {
					printf("数据保存失败\n");
					system("pause");
				}
			}
			fclose(fp);
			break;
		}
	}
	if (i == m) {
		printf("没有找到该学生\n");
	}
	system("pause");
}
//主菜单
void menu(void)
{
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t|------------------学生管理系统-----------------|\n");
	printf("\t\t|\t\t\t\t\t        |\n");
	printf("\t\t|\t\t 1.录入学生信息\t\t\t|\n");
	printf("\t\t|\t\t 2.查找学生信息\t\t\t|\n");
	printf("\t\t|\t\t 3.删除学生信息\t\t\t|\n");
	printf("\t\t|\t\t 4.修改学生信息\t\t\t|\n");
	printf("\t\t|\t\t 5.插入学生信息\t\t\t|\n");
	printf("\t\t|\t\t 6.排序学生信息\t\t\t|\n");
	printf("\t\t|\t\t 7.统计学生总数\t\t\t|\n");
	printf("\t\t|\t\t 8.显示所有学生\t\t\t|\n");
	printf("\t\t|\t\t 0.退出学生系统\t\t\t|\n");
	printf("\t\t|\t\t\t\t\t        |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\t 请选择(0-8)");

}
//插入学生信息
void insert(void)
{
	
}
//计算总人数
void total(void)
{
	FILE *fp;
	int cnt = 0;;
	int m = 0;
	fp = fopen("data.txt","r");
	if (fp == NULL) {
		printf("没有文件\n");
		return;
	}
	while (!feof(fp)) {
		if (fread(&stu[m], LEN, 1, fp) == 1) {
			cnt++;
		}
	}
	printf("一共有%d位学生\n",cnt);
	system("pause");
}
//查找学生信息
void search(void)
{
	FILE *fp;
	int snum;
	int m = 0;
	int i = 0;
	fp = fopen("data.txt","r");
	if (fp == NULL) {
		printf("文件不存在\n");
		return;
	}
	while (!feof(fp)) {
		if (fread(&stu[m], LEN, 1, fp) == 1) {
			m++;
		}
	}
	fclose(fp);
	if(m == 0) {
		printf("文件中没有记录\n");
		return;
	}
	printf("请输入学生ID:");
	fflush(stdin);
	scanf("%d", &snum);
	for (i = 0; i < m; i++) {
		if (snum == stu[i].num) {
			printf(FORMAT,DATA);
			break;
		}
	}
	if(i == m) {
		printf("没有该学生\n");
	}
	system("pause");
}

