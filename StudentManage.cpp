#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.cpp"

int main()
{
	while(1)
	{
		Menu();				//��ʾ��ʼ�˵�
		char c= getchar();
		while(c!= '1' && c!= '2' && c!= '3' && c!= '4')
		{
			printf("������󣡣����ٴ����룡\n");
			fflush(stdin);
			c= getchar();
		}
		MenuChoice(c);			//�Գ�ʼ�˵����д���
		system("cls");
	}

	system("pause");
	return 0;
}