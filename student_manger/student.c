#include "student.h"

//¼��ѧ���ɼ�
void in(void)
{
	int m = 0;
	char ch[2];
	FILE *fp;
	fp = fopen("data.txt","a+");
	if (fp == NULL) {
		printf("�ļ�������\n");
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
		printf("�ļ���û�м�¼\n");
	} else {
		show();
	}
	printf("����ѧ����Ϣ?(y/n)\n");
	fflush(stdin);
	scanf("%s", ch);
	fp = fopen("data.txt","a");
	if (fp == NULL) {
		printf("�ļ�������\n");
	return;
	}
	while (strncmp(ch,"Y",1) == 0 || strncmp(ch,"y",1) == 0) {
		printf("������¼��ѧ��Id:");
		fflush(stdin);
		scanf("%d", &stu[m].num);
		for(int i = 0; i < m; i++) {
			if (stu[i].name == stu[m].name) {
				printf("��ѧ��ID�ѱ�����\n");
				getch();
			fclose(fp);
			return;
			}
		}
		printf("��¼��ѧ������:");
		fflush(stdin);
		scanf("%s",stu[m].name);
		printf("��¼��ѧ��ʵ��γɼ�:");
		fflush(stdin);
		scanf("%lf",&stu[m].expe);
		printf("��¼��ѧ��ѡ�޿γɼ�:");
		fflush(stdin);
		scanf("%lf", &stu[m].exec);
		printf("��¼��ѧ�����޿γɼ�:");
		fflush(stdin);
		scanf("%lf", &stu[m].requ);
		stu[m].sum = stu[m].exec + stu[m].expe + stu[m].requ;
		if (fwrite(&stu[m], LEN, 1, fp) != 1) {
			printf("����ʧ��\n");
			getch();
		} else {
			printf("%s����Ϣ��¼��\n",stu[m].name);
			m++;
		}
		printf("�Ƿ����¼����Ϣ?(y/n)\n");
		fflush(stdin);
		scanf("%s",ch);
	}
	fclose(fp);
	printf("ѧ����Ϣ���سɹ�\n");
	getch();
}
//��ʾѧ����Ϣ
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
	printf("ID--------����--------ѡ��--------ʵ��--------���޿�--------�ܷ�\n");
	for (int i = 0; i < m; i++) {
		printf(FORMAT,DATA);
	}
	getch();
}

//�����ܷ�����
void order(void)
{

}
//ɾ��ѧ���ɼ���Ϣ
void del(void)
{
	FILE *fp;
	int snum;
	int i,j;
	int m = 0;
	char ch[2];
	
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("�ļ�������\n");
		return;
	}
	while (!feof(fp)) {
		if(fread(&stu[m], LEN, 1, fp) == 1) {
			m++;
		}
	}
	fclose(fp);
	fp == NULL;
	
	printf("������ѧ��:");
	fflush(stdin);
	scanf("%d",&snum);
	for (i = 0; i < m; i++) {
		if (snum == stu[i].num) {
			printf("���ҵ���ѧ����¼���Ƿ�ɾ����(y/n)");
			scanf("%s",ch);
			if (strncmp(ch, "Y", 1) == 0 || strncmp(ch, "y", 1) == 0) {
				for (j = i; j < m; j++) {
					stu[j] = stu[j+1];
				}
				m--;
				fp = fopen("data.txt","wb");
				if (fp == NULL) {
					printf("�ļ�������\n");
					return;
				}
				for (j = 0; j < m; j++) {
					if (fwrite(&stu[j], LEN, 1, fp) !=1) {
						printf("can not save data\n");
						getch();
					}
				}
				fclose(fp);
				fp = NULL;
				printf("��ɾ��\n");
			} else {
				printf("δɾ����ѧ����Ϣ\n");
				break;
			}
		}
	}
	if (i == m + 1) {
		printf("û���ҵ���ѧ��\n");
	}
	getch();
	

}
//�޸�ѧ���ɼ���Ϣ
void modify(void)
{
	
}
//���˵�
void menu(void)
{
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t|------------------ѧ������ϵͳ-----------------|\n");
	printf("\t\t|\t\t\t\t\t        |\n");
	printf("\t\t|\t\t 1.¼��ѧ����Ϣ\t\t\t|\n");
	printf("\t\t|\t\t 2.����ѧ����Ϣ\t\t\t|\n");
	printf("\t\t|\t\t 3.ɾ��ѧ����Ϣ\t\t\t|\n");
	printf("\t\t|\t\t 4.�޸�ѧ����Ϣ\t\t\t|\n");
	printf("\t\t|\t\t 5.����ѧ����Ϣ\t\t\t|\n");
	printf("\t\t|\t\t 6.����ѧ����Ϣ\t\t\t|\n");
	printf("\t\t|\t\t 7.ͳ��ѧ������\t\t\t|\n");
	printf("\t\t|\t\t 8.��ʾ����ѧ��\t\t\t|\n");
	printf("\t\t|\t\t 0.�˳�ѧ��ϵͳ\t\t\t|\n");
	printf("\t\t|\t\t\t\t\t        |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\t ��ѡ��(0-8)");

}
//����ѧ����Ϣ
void insert(void)
{
	
}
//����������
void total(void)
{
	FILE *fp;
	int cnt = 0;;
	int m = 0;
	fp = fopen("data.txt","r");
	if (fp == NULL) {
		printf("û���ļ�\n");
		return;
	}
	while (!feof(fp)) {
		if (fread(&stu[m], LEN, 1, fp) == 1) {
			cnt++;
		}
	}
	printf("һ����%dλѧ��\n",cnt);
	getch();
}
//����ѧ����Ϣ
void search(void)
{
	FILE *fp;
	int snum;
	int m = 0;
	int i = 0;
	fp = fopen("data.txt","r");
	if (fp == NULL) {
		printf("�ļ�������\n");
		return;
	}
	while (!feof(fp)) {
		if (fread(&stu[m], LEN, 1, fp) == 1) {
			m++;
		}
	}
	fclose(fp);
	if(m == 0) {
		printf("�ļ���û�м�¼\n");
		return;
	}
	printf("������ѧ��ID:");
	fflush(stdin);
	scanf("%d", &snum);
	for (i = 0; i < m; i++) {
		if (snum == stu[i].num) {
			printf(FORMAT,DATA);
			break;
		}
	}
	if(i == m) {
		printf("û�и�ѧ��\n");
	}
	getch();
}
