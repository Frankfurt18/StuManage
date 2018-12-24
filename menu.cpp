#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operate.cpp"

void Menu();					//��ʾ��ʼ�˵�
void MenuChoice(char ch);		//�˵�ѡ��Ȩ�޵�½

void AdminMenu();				//��ʾ����Ա�˵�������
void AdminMenuChoice();			//����Ա�˵�������

void TeacherMenu();				//��ʾ��ʦ�˵�������
void TeacherMenuChoice();		//��ʦ�˵�������

void StudentMenu();				//��ʾѧ���˵�������
void StudentMenuChoice();		//ѧ���˵�������

void Menu()								//��ʼ�˵�
{
	system("color A0");
	printf("\n\n\tѧԺ��ѧ������ϵͳ\n\n");
	printf("\t\t1.���ǹ���Ա\n\n");
    printf("\t\t2.���ǽ�ʦ\n\n");
    printf("\t\t3.����ѧ��\n\n");  
    printf("\t\t4.�˳�ϵͳ\n\n"); 	
}

void MenuChoice(char c)					//�˵�ѡ��Ȩ�޵�½
{
	while (getchar() != '\n');		//��ջ�����
	printf("\t������");

	int ret;
	char account[20];		//�˻�
	char password[20];		//����	

	switch(c)
	{
		case '1':										//����Ա��½
		{
			char stdacc[20];		//���ñ�׼�˻�������
			char stdpass[20];
			strcpy_s(stdacc, "linshujing");
			strcpy_s(stdpass, "password");

			printf(" ����Ա�˺ţ�\n");
			gets_s(account,20);
			while((ret= strcmp(account, stdacc))!= 0)
			{
				printf("û�д˹���Ա�˺ţ���Ǹ�����������룡\n");
				gets_s(account);
			}
			printf("\t             ���룺\n");
			gets_s(password,20);
			if((ret= strcmp(password, stdpass))!= 0)
			{
				printf("����Ա��������������������룡\n");
				gets_s(password);
			}
			AdminMenuChoice();
			break;
		}
		case '2':									//��ʦ��½
		{
			int i, num = 0;
			//��ȡ�ļ�
			FILE *fp;
			fopen_s(&fp, "password/teachers.data", "r");
			char stdacc[20][20];
			char stdpass[20][20];
			while (!feof(fp))
			{
				num++;
				fscanf_s(fp, "%s\n", stdacc[num], 20);
				fscanf_s(fp, "%s\n", stdpass[num], 20);
			}
			bool flag = true;
			printf(" ��ʦ�˺ţ�\n");
			gets_s(account,20);
			//���ʺŽ����ж�
			do {
				for (i = 1; i <= num; i++)
				{
					if (!strcmp(account, stdacc[i]))
					{
						flag = false;
						break;
					}
				}
				if (i == num + 1)
				{
					printf("û�д���ʦ�˺ţ���Ǹ�����������룡\n");
					gets_s(account);
				}
			} while (flag);

			printf("\t           ���룺\n");
			gets_s(password,20);
			while (strcmp(password, stdpass[i]))
			{
				printf("����ʦ�˺���������������������룡\n");
				gets_s(password);
			}
			TeacherMenuChoice();
			break;
		}
		case '3':									//ѧ����½
		{
			int i, num = 0;
			//��ȡ�ļ�
			FILE *fp;
			fopen_s(&fp, "password/students.data", "r");
			char stdacc[20][20];
			char stdpass[20][20];
			while (!feof(fp))
			{
				num++;
				fscanf_s(fp, "%s\n", stdacc[num], 20);
				fscanf_s(fp, "%s\n", stdpass[num], 20);
			}
			bool flag = true;
			printf(" ѧ���˺ţ�\n");
			gets_s(account, 20);
			//���ʺŽ����ж�
			do {
				for (i = 1; i <= num; i++)
				{
					if (!strcmp(account, stdacc[i]))
					{
						flag = false;
						break;
					}
				}
				if (i == num + 1)
				{
					printf("û�д�ѧ���˺ţ���Ǹ�����������룡\n");
					gets_s(account);
				}
			} while (flag);

			printf("\t           ���룺\n");
			gets_s(password, 20);
			while (strcmp(password, stdpass[i]))
			{
				printf("��ѧ���˺���������������������룡\n");
				gets_s(password);
			}
			StudentMenuChoice();
			break;
		}
		case '4':
			exit(0);
	}
	while ((getchar()) != '\n');
}

void AdminMenu()							//��ʾ����Ա�˵�������
{
	system("cls");
	printf("\n\n\t����Ա�����˵�\n\n");
	printf("\t\t1.���ѧ����Ϣ\n\n");
    printf("\t\t2.ɾ��ѧ����Ϣ\n\n");
    printf("\t\t3.Ϊָ��ѧ�����ָ���Ŀγ�\n\n");  
    printf("\t\t4.ɾ��ָ��ѧ����ָ���γ�\n\n"); 
    printf("\t\t5.Ϊ����ѧ�����ָ���γ�\n\n"); 
    printf("\t\t6.ɾ������ѧ����ָ���γ�\n\n"); 
	printf("\t\t7.����\n\n"); 
}

void AdminMenuChoice()							//����Ա�˵�������
{
	char ch;
	while(1)
	{
		AdminMenu();
		printf("��ѡ�� ");
		ch= getchar();
		while(ch!= '1' && ch!= '2' && ch!= '3' && ch!= '4' && ch!= '5'&& ch != '6' && ch != '7')
		{
			printf("������󣡣����ٴ����룡\n");
			ch= getchar();
		}
		if(ch == '7')
			break;
		AdminOperate(ch);
	}
}

void TeacherMenu()						//��ʾ��ʦ�˵�������
{
	system("cls");
	printf("\n\n\t��ʦ�����˵�\n\n");
	printf("\t\t1.Ϊĳ��ѧ��ĳ�ſθ���\n\n");
    printf("\t\t2.�鿴ĳ�ſμ����ʣ�ƽ����\n\n");
    printf("\t\t3.�鿴ĳ�ſ�����ѧ���ɼ�\n\n");  
    printf("\t\t4.����\n\n"); 
}

void TeacherMenuChoice()						//��ʦ�˵�������
{
	char ch;
	while(1)
	{
		TeacherMenu();
		printf("��ѡ�� ");
		ch= getchar();
		while(ch!= '1' && ch!= '2' && ch!= '3' && ch!= '4')
		{
			printf("������󣡣����ٴ����룡\n");
			ch= getchar();
		}
		if(ch == '4')
			break;
		TeacherOperate(ch);		
	}
}

void StudentMenu()						//��ʾѧ���˵�������
{
	system("cls");
	printf("\n\n\tѧ�������˵�\n\n");
	printf("\t\t1.�鿴�ҵ���Ϣ\n\n");
    printf("\t\t2.����\n\n");
}

void StudentMenuChoice()						//ѧ���˵�������
{
	char ch;
	while(1)
	{
		StudentMenu();
		printf("��ѡ�� ");
		ch= getchar();
		while(ch!= '1' && ch!= '2')
		{
			fflush(stdin);
			printf("������󣡣����ٴ����룡\n");
			ch= getchar();
		}
		if(ch == '2')
			break;
		StudentOperate(ch);
	}
}



