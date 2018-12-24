#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <io.h>			//��ͷ�ļ��������ڴ洢�ļ���Ϣ�Ľṹ��Ͷ�ȡ�ļ��ĸ��ֲ�����

typedef struct Course
{
	char course[10];		//�γ�����
	int score;				//�γ̷���
}Course;

typedef struct stu
{
	int stu_id;				//ѧ����ѧ��
	char name[10];			//ѧ������
	int classnum;			//�༶
	int grade;				//�꼶
	int num;				//�γ���Ŀ
	Course cour[10];		//�޵Ŀγ�
	struct stu *next;
}STU;

void AddStudent();				    		//���ѧ����Ϣ
void DelStudent();							//ɾ��ѧ����Ϣ
void AddCourse();							//Ϊָ��ѧ�����ָ���Ŀγ�
void AddCoursePro(char *path, char *course);//��ָ�����ļ������¿γ�
void DelCourse();							//ɾ��ָ��ѧ����ָ���γ�
void DelCoursePro(char *path, char *course);//��ָ�����ļ�ɾ���¿γ�
void AddAllCourse();						//Ϊ����ѧ�����ָ���γ�
void DelAllCourse();						//ɾ������ѧ����ָ���γ�

void GiveStuScore();						//��ĳѧ��ĳ�ſεĳɼ�
void CountScore();							//��ѯĳ�γ̼����ʺ�ƽ������											
void PrintCourse();							//�鿴����ѧ��ĳ�ſεĳɼ�

void StuMessage();							//ѧ����Ϣ��ѯ

void dirhandle(STU *head);					//��data�ļ������ļ����ж�ȡ���������ݴ�������


//------------------------------------------�Թ���ԱȨ������-----------------------------------

void AddStudent()				//���ѧ����Ϣ
{
	STU stu;
	int i;

	//��ʾ�������
	printf("\n\t������ѧ�ţ�");
	scanf_s("%d", &stu.stu_id);
	//����ѧ����½�˺�����
	FILE *fpstu;
	fopen_s(&fpstu, "password/students.data", "a");
	fprintf(fpstu, "\n%d\n", stu.stu_id);
	fprintf(fpstu, "%d\n", stu.stu_id);
	fclose(fpstu);

	printf("\t������������");
	scanf_s("%s", stu.name, 10);
	printf("\t������༶��");
	scanf_s("%d", &stu.classnum);
	printf("\t�������꼶��");
	scanf_s("%d", &stu.grade);
	printf("\t������γ���Ŀ��");
	scanf_s("%d", &stu.num);
	for (i = 1; i <= stu.num; i++)
	{
		printf("\t�������ѧ���ĵ�%d���γ�����", i);
		scanf_s("%s", stu.cour[i].course, 10);
		printf("\t�������ѧ����%d���γ̳ɼ���", i);
		scanf_s("%d", &stu.cour[i].score);
	}

	//�����ļ�����
	char path[20] = "data/";
	char filename[20];
	//������ת�����ַ�
	snprintf(filename, sizeof(filename), "%d", stu.stu_id);
	//�����ļ�·��
	strcat_s(filename, ".data");
	strcat_s(path, filename);

	//�ļ���
	FILE *fp;
	fopen_s(&fp, path, "w");
	if (!fp)
	{
		printf("Cannot open this file\n");
		exit(1);
	}
	//�����ݶ����ļ�
	fprintf(fp, "%d\n", stu.stu_id);
	fprintf(fp, "%s\n", stu.name);
	fprintf(fp, "%d\n", stu.classnum);
	fprintf(fp, "%d\n", stu.grade);
	fprintf(fp, "%d\n", stu.num);
	for (i = 1; i <= stu.num; i++)
	{
		fprintf(fp, "%s\n", stu.cour[i].course);
		fprintf(fp, "%d\n", stu.cour[i].score);
	}
	//�ر��ļ�
	fclose(fp);
	printf("\n    ��ѧ���Ѿ������ϣ�����,�����Ӻ��Զ���ת����");
	Sleep(2000);
	while ((getchar()) != '\n');

	return;
}

void DelStudent()			//ɾ��ѧ����Ϣ
{
	STU stu;

	printf("\n\t������ѧ�ţ�");
	scanf_s("%d", &stu.stu_id);

	//�����ļ�����
	char path[20] = "data/";
	char filename[20];
	//������ת�����ַ�
	snprintf(filename, sizeof(filename), "%d", stu.stu_id);
	//�����ļ�·��
	strcat_s(filename, ".data");
	strcat_s(path, filename);

	if(remove(path) == 0)
		printf("\n    �Ѿ�ɾ����ѧ������Ϣ��");
	else
		printf("Removed Error\n");

	printf("�����Ӻ��Զ���ת����\n");
	Sleep(2000);
	while ((getchar()) != '\n');
	return;
}

void AddCourse()					//Ϊָ��ѧ�����ָ���Ŀγ�
{
	int num, id;
	printf("\n\t������ѧ�ţ�");
	scanf_s("%d", &id);

	//�����ļ�����
	char path[20] = "data/";
	char filename[20];
	//������ת�����ַ�
	snprintf(filename, sizeof(filename), "%d", id);
	//�����ļ�·��
	strcat_s(filename, ".data");
	strcat_s(path, filename);

	char course[10][10];
	printf("\n\t��������Ҫ��ӵĿγ���Ŀ��");
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++)
	{
		printf("\n\t������Ҫ��ӵĿγ�%d��", i+1);
		scanf_s("%s", course[i], 10);
		AddCoursePro(path, course[i]);
	}
	printf("\n\t    �γ���ӳɹ��������Ӻ��Զ���ת����\n");
	Sleep(2000);
	while ((getchar()) != '\n');
	return;
}

void AddCoursePro(char *path, char *course)				//��ָ�����ļ������¿γ�
{
	STU stu;
	int i;

	//�ļ���
	FILE *fp;
	fopen_s(&fp, path, "r");
	if (!fp)
	{
		printf("Cannot open this file\n");
		exit(1);
	}
	//�������ļ��������ļ�
	FILE *fpnew;
	fopen_s(&fpnew, "data/tmp.data", "w");
	if (!fp)
	{
		printf("Cannot open this file\n");
		exit(1);
	}

	//��ԭ�������ݶ��뵽�ڴ�
	fscanf_s(fp, "%d\n", &stu.stu_id);
	fscanf_s(fp, "%s\n", stu.name, 10);
	fscanf_s(fp, "%d\n", &stu.classnum);
	fscanf_s(fp, "%d\n", &stu.grade);
	fscanf_s(fp, "%d\n", &stu.num);
	for (i = 1; i <= stu.num; i++)
	{
		fgets(stu.cour[i].course, 10, fp);
		stu.cour[i].course[strlen(stu.cour[i].course) - 1] = '\n';
		fscanf_s(fp, "%d\n", &stu.cour[i].score);
	}
	//��ԭ�������ݴ��ڴ洫�����ļ�
	fprintf(fpnew, "%d\n", stu.stu_id);
	fprintf(fpnew, "%s\n", stu.name);
	fprintf(fpnew, "%d\n", stu.classnum);
	fprintf(fpnew, "%d\n", stu.grade);
	fprintf(fpnew, "%d\n", stu.num + 1);
	for (i = 1; i <= stu.num; i++)
	{
		fprintf(fpnew, "%s", stu.cour[i].course);
		fprintf(fpnew, "%d\n", stu.cour[i].score);
	}
	fprintf(fpnew, "%s\n", course);
	fprintf(fpnew, "%d\n", 0);

	//�ر��ļ�
	fclose(fp);
	fclose(fpnew);

	//ɾ��ԭ�ļ��������ļ�����Ϊfilename
	if (remove(path))
		printf("Removed Error\n");
	rename("data/tmp.data", path);

	printf("\n\t    �γ���ӳɹ���һ���Ӻ��Զ���ת����\n");
	Sleep(1000);
}

void DelCourse()					//ɾ��ָ��ѧ����ָ���γ�
{
	int i, num, id;
	printf("\n\t������ѧ�ţ�");
	scanf_s("%d", &id);

	//�����ļ�����
	char path[20] = "data/";
	char filename[20];
	//������ת�����ַ�
	snprintf(filename, sizeof(filename), "%d", id);
	//�����ļ�·��
	strcat_s(filename, ".data");
	strcat_s(path, filename);

	char course[10][10];
	printf("\n\t��������Ҫɾ���Ŀγ���Ŀ��");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++)
	{
		printf("\n\t������Ҫɾ���Ŀγ�%d��", i + 1);
		scanf_s("%s", course[i], 10);
		DelCoursePro(path, course[i]);
	}
	printf("\n\t    �γ���ӳɹ��������Ӻ��Զ���ת����\n");
	Sleep(2000);
	while ((getchar()) != '\n');
	return;
}

void DelCoursePro(char *path, char *course)
{
	STU stu;
	int i;

	//�ļ���
	FILE *fp;
	fopen_s(&fp, path, "r");
	if (!fp)
	{
		printf("Cannot open this file\n");
		exit(1);
	}
	//�������ļ��������ļ�
	FILE *fpnew;
	fopen_s(&fpnew, "data/tmp.data", "w");
	if (!fpnew)
	{
		printf("Cannot open this file\n");
		exit(1);
	}

	//��ԭ�������ݶ��뵽�ڴ�
	fscanf_s(fp, "%d\n", &stu.stu_id);
	fscanf_s(fp, "%s\n", stu.name, 10);
	fscanf_s(fp, "%d\n", &stu.classnum);
	fscanf_s(fp, "%d\n", &stu.grade);
	fscanf_s(fp, "%d\n", &stu.num);
	for (i = 1; i <= stu.num; i++)
	{
		//fgets(stu.cour[i].course, 10, fp);
		//��fgets��ȡ�ĻὫ�ո񣬻��з�����
		fscanf_s(fp, "%s\n", stu.cour[i].course, 10);
		fscanf_s(fp, "%d\n", &stu.cour[i].score);
	}
	//��ԭ�������ݴ��ڴ洫�����ļ�
	fprintf(fpnew, "%d\n", stu.stu_id);
	fprintf(fpnew, "%s\n", stu.name);
	fprintf(fpnew, "%d\n", stu.classnum);
	fprintf(fpnew, "%d\n", stu.grade);
	//�Կγ���Ŀ���д���
	for (i = 1; i <= stu.num; i++)
	{
		if (strcmp(stu.cour[i].course, course) == 0)
		{
			fprintf(fpnew, "%d\n", stu.num - 1);
			break;
		}
	}
	if(i == stu.num + 1)
		fprintf(fpnew, "%d\n", stu.num);
	//��ɾ����Ŀγ����Լ���Ӧ����д�����ļ�
	for (i = 1; i <= stu.num; i++)
	{
		if (strcmp(stu.cour[i].course, course) == 0)
			continue;			
		fprintf(fpnew, "%s\n", stu.cour[i].course);
		fprintf(fpnew, "%d\n", stu.cour[i].score);
	}

	//�ر��ļ�
	fclose(fp);
	fclose(fpnew);

	//ɾ��ԭ�ļ��������ļ�����Ϊfilename
	if (remove(path))
		printf("Removed Error\n");
	else
		rename("data/tmp.data", path);

	printf("\n\t    �γ�ɾ���ɹ���һ���Ӻ��Զ���ת����\n");
	Sleep(1000);
}

void AddAllCourse()					//Ϊ����ѧ�����ָ���γ�
{
	STU *p, *head;
	head = (STU *)malloc(sizeof(STU));
	dirhandle(head);
	p = head->next;

	//�õ�����
	char course[10];
	printf("\n\t����������Ϊ��������ӵĿγ̣�");
	scanf_s("%s", course, 10);

	char path[25] = "data/";
	char filename[20];

	while (p != NULL)
	{
		//�����ļ�·��
		snprintf(filename, sizeof(filename), "%d", p->stu_id);//������ת�����ַ�
		strcat_s(filename, ".data");
		strcat_s(path, filename);

		AddCoursePro(path, course);

		strcpy_s(path, "data/");
		p = p->next;
	}

	printf("\n\t�����˵Ŀγ�ȫ����ӳɹ��������Ӻ��Զ���ת����\n");
	Sleep(2000);
	while ((getchar()) != '\n');

	return ;
}

void DelAllCourse()					//ɾ������ѧ����ָ���γ�
{
	STU *p, *head;
	head = (STU *)malloc(sizeof(STU));
	dirhandle(head);
	p = head->next;

	//�õ�����
	char course[10];
	printf("\n\t����������Ϊ������ɾ���Ŀγ̣�");
	scanf_s("%s", course, 10);

	char path[25] = "data/";
	char filename[20];

	while (p != NULL)
	{
		//�����ļ�·��
		snprintf(filename, sizeof(filename), "%d", p->stu_id);//������ת�����ַ�
		strcat_s(filename, ".data");
		strcat_s(path, filename);

		DelCoursePro(path, course);

		strcpy_s(path, "data/");
		p = p->next;
	}

	printf("\n\t�����˵Ŀγ�ȫ��ɾ���ɹ��������Ӻ��Զ���ת����\n");
	Sleep(2000);
	while ((getchar()) != '\n');

	return;
}

//--------------------------------------------------------------------------------------

//-------------------------------------�Խ�ʦȨ������------------------------------------

void GiveStuScore()			//��ĳѧ��ĳ�ſεĳɼ�
{
	int i, id, score;
	char course[10];
	printf("\n\t�������ѧ����ѧ�ţ�");
	scanf_s("%d", &id);
	printf("\n\t������Ҫ���ֵĿγ̣�");
	scanf_s("%s", course, 10);
	printf("\n\t������ÿγ̵ķ�����");
	scanf_s("%d", &score);

	//�����ļ�����
	char path[20] = "data/";
	char filename[20];
	//������ת�����ַ�
	snprintf(filename, sizeof(filename), "%d", id);
	//�����ļ�·��
	strcat_s(filename, ".data");
	strcat_s(path, filename);

	//�ļ���
	FILE *fp;
	fopen_s(&fp, path, "r");
	if (!fp)
	{
		printf("Cannot open this file\n");
		exit(1);
	}
	//�������ļ��������ļ�
	FILE *fpnew;
	fopen_s(&fpnew, "data/tmp.data", "w");
	if (!fp)
	{
		printf("Cannot open this file\n");
		exit(1);
	}

	STU stu;
	//��ԭ�������ݶ��뵽�ڴ�
	fscanf_s(fp, "%d\n", &stu.stu_id);
	fscanf_s(fp, "%s\n", stu.name, 10);
	fscanf_s(fp, "%d\n", &stu.classnum);
	fscanf_s(fp, "%d\n", &stu.grade);
	fscanf_s(fp, "%d\n", &stu.num);
	for (i = 1; i <= stu.num; i++)
	{
		fscanf_s(fp, "%s\n", stu.cour[i].course, 10);
		fscanf_s(fp, "%d\n", &stu.cour[i].score);
	}
	//��ԭ�������ݴ��ڴ洫�����ļ�
	fprintf(fpnew, "%d\n", stu.stu_id);
	fprintf(fpnew, "%s\n", stu.name);
	fprintf(fpnew, "%d\n", stu.classnum);
	fprintf(fpnew, "%d\n", stu.grade);
	fprintf(fpnew, "%d\n", stu.num);
	for (i = 1; i <= stu.num; i++)
	{
		if (strcmp(stu.cour[i].course, course))
		{
			fprintf(fpnew, "%s\n", stu.cour[i].course);
			fprintf(fpnew, "%d\n", stu.cour[i].score);
		}
		else
		{
			fprintf(fpnew, "%s\n", stu.cour[i].course);
			fprintf(fpnew, "%d\n", score);
		}	
	}

	//�ر��ļ�
	fclose(fp);
	fclose(fpnew);

	//ɾ��ԭ�ļ��������ļ�����Ϊfilename
	if (remove(path))
		printf("Removed Error\n");
	rename("data/tmp.data", path);

	printf("\n\tΪ��ѧ�����ֳɹ��������Ӻ��Զ���ת����\n");
	Sleep(2000);
	while ((getchar()) != '\n');
	return;
}

void CountScore()				//��ѯĳ�γ̼����ʺ�ƽ������
{
	int num = 0, score = 0, high_num = 0;
	double pass_rate, average_score;	//�����ʣ�ƽ������

	char course[10];
	printf("\n\t������Ҫͳ�ƵĿγ̣�");
	scanf_s("%s", course, 10);

	STU *p, *head;
	head = (STU *)malloc(sizeof(STU));
	dirhandle(head);
	p = head->next;

	//��������
	while (p != NULL)
	{
		for (int i = 1; i <= p->num; i++)
		{
			if (!strcmp(p->cour[i].course, course))
			{
				num ++;
				score += p->cour[i].score;
				if (p->cour[i].score >= 60)
					high_num ++;
			}
		}
		p = p->next;
	}
	//��������
	pass_rate = (double)high_num / num;
	average_score = (double)score / num;
	printf("\n\t%s�γ̼������ǣ�%.2lf", course, pass_rate);
	printf("\n\t%s�γ�ƽ�����ǣ�%.2lf", course, average_score);

	printf("\n\n\t");
	system("pause");
	while ((getchar()) != '\n');		
	return;
}

void PrintCourse()				//�鿴����ѧ��ĳ�ſεĳɼ�
{
	char course[10];
	printf("\n\t������Ҫͳ�ƵĿγ̣�");
	scanf_s("%s", course, 10);

	STU *p, *head;
	head = (STU *)malloc(sizeof(STU));
	dirhandle(head);
	p = head->next;

	printf("\n\t  ѧ��      ����       ����\n");
	//��������
	while (p != NULL)
	{
		for (int i = 1; i <= p->num; i++)
		{
			if (!strcmp(p->cour[i].course, course))
			{
				printf("\n\t%8d   %-10s   %d\n", p->stu_id, p->name, p->cour[i].score);
			}
		}
		p = p->next;
	}

	printf("\n\n\t");
	system("pause");
	while ((getchar()) != '\n');
	return;
}

//---------------------------------------------------------------------------------------

//--------------------------------------��ѧ��Ȩ������------------------------------------

void StuMessage()						//ѧ����Ϣ��ѯ
{
	STU stu;
	int i;

	//����ѧ��
	printf("\n\t����������ѧ�ţ�");
	scanf_s("%d", &stu.stu_id);
	//�����ļ�·��������
	char path[20] = "data/";
	char filename[15];
	snprintf(filename, sizeof(filename), "%d", stu.stu_id);//������ת�����ַ�
	strcat_s(filename, ".data");
	strcat_s(path, filename);

	//���ļ�
	FILE *fp;
	fopen_s(&fp, path, "r");
	if (!fp)
	{
		printf("Cannot open this file\n");
		exit(1);
	}
	//��ȡ�ļ������ݵ��ڴ�
	fscanf_s(fp, "%d\n", &stu.stu_id);
	fscanf_s(fp, "%s\n", stu.name, 10);
	fscanf_s(fp, "%d\n", &stu.classnum);
	fscanf_s(fp, "%d\n", &stu.grade);
	fscanf_s(fp, "%d\n", &stu.num);
	for (i = 1; i <= stu.num; i++)
	{
		fgets(stu.cour[i].course, 10, fp);
		fscanf_s(fp, "%d\n", &stu.cour[i].score);
	}
	//�ر��ļ�
	fclose(fp);

	printf("\n\t\t������Ϣ���£�\n\n");
	printf("\tѧ�ţ�%d\n", stu.stu_id);
	printf("\t������%s\n", stu.name);
	printf("\t�༶��%d��\n", stu.classnum);
	printf("\t�꼶��%d��\n", stu.grade);
	printf("\t��һ��ѧ��%d�ſ�\n", stu.num);
	for (i = 1; i <= stu.num; i++)
	{
		printf("\t   ��%d�ſ��ǣ�%s", i, stu.cour[i].course);
		printf("\t   �ÿεķ����ǣ�%d\n\n", stu.cour[i].score);
	}

	printf("\n\t���������������");
	while ((getchar()) != '\n');
	_kbhit();
	return;
}

//---------------------------------------------------------------------------------------

void dirhandle(STU *head)
{
	//��ʼ�������β�ڵ�
	STU *rear, *s;
	rear = head;

	char filename[50][15];

	//�ļ��洢��Ϣ�ṹ�� 
	struct _finddata_t fileinfo;
	//�����ļ���� 
	long fHandle;
	//�ļ�����¼��
	int filenum = 0;
	//��ȡ�ļ������ļ�
	if ((fHandle = _findfirst("data/*.data", &fileinfo)) == -1L)
	{
		printf("\n\tdataĿ¼��û��ѧ�������ļ�\n");
	}
	//�洢��ȡ�����ļ���
	do {
		strcpy_s(filename[filenum], fileinfo.name);
		filenum++;
	} while (_findnext(fHandle, &fileinfo) == 0);

	//���ļ����в���
	FILE *fp;
	char path[25] = "data/";
	for (int i = 0; i<filenum; i++)
	{
		//���ļ�
		strcat_s(path, filename[i]);
		fopen_s(&fp, path, "r");
		strcpy_s(path, "data/");
		if (!fp)
		{
			printf("Cannot open %s file\n", filename[i]);
			exit(1);
		}
		//���ļ������ݴ�������
		s = (STU *)malloc(sizeof(STU));
		rear->next = s;
		rear = s;
		//�����ݶ�������
		fscanf_s(fp, "%d\n", &s->stu_id);
		fscanf_s(fp, "%s\n", s->name, 10);
		fscanf_s(fp, "%d\n", &s->classnum);
		fscanf_s(fp, "%d\n", &s->grade);
		fscanf_s(fp, "%d\n", &s->num);
		for (int j = 1; j <= s->num; j++)
		{
			//fgets(s->cour[j].course, 10, fp);
			fscanf_s(fp, "%s\n", &s->cour[j].course, 10);
			fscanf_s(fp, "%d\n", &s->cour[j].score);
		}
		fclose(fp);
	}
	rear->next = NULL;

	//�ر��ļ����
	_findclose(fHandle);
}