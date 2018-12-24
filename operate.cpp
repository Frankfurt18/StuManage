#include <stdio.h>
#include "student.cpp"

void AdminOperate(char ch);						//����Ա����
void TeacherOperate(char ch);					//��ʦ����
void StudentOperate(char ch);					//ѧ������

void AdminOperate(char ch)			//����Ա����
{
	switch(ch)
	{
		case '1':						//���ѧ����Ϣ
		{
			AddStudent();
			break;
		}
		case '2':						//ɾ��ѧ����Ϣ
		{
			
			DelStudent();
			break;
		}
		case '3':										//Ϊָ��ѧ�����ָ���Ŀγ�
		{
			AddCourse();
			break;
		}
		case '4':										//ɾ��ָ��ѧ����ָ���γ�
		{
			DelCourse();
			break;
		}
		case '5':										//Ϊ����ѧ�����ָ���γ�
		{
			AddAllCourse();
			break;
		}
		case '6':										//ɾ������ѧ����ָ���γ�
		{
			DelAllCourse();
			break;
		}
	}	
}

void TeacherOperate(char ch)			//��ʦ����
{
	while ((getchar()) != '\n');
	switch(ch)
	{
		case '1':					//Ϊĳ��ѧ��ĳ�ſθ���
		{		
			GiveStuScore();
			break;
		}
		case '2':							//�鿴ĳ�ſμ����ʣ�ƽ����
		{
			CountScore();
			break;
		}
		case '3':									//�鿴ĳ�ſ�����ѧ���ɼ�
		{
			PrintCourse();
			break;
		}
	}
}

void StudentOperate(char ch)			//ѧ������
{
	while ((getchar()) != '\n');	//�鿴�ҵ���Ϣ
	if(ch == '1')
	{	
		StuMessage();	
	}
	while ((getchar()) != '\n');
}