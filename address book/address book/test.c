#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "concat.h"
#if 1
/*
1. �����ϵ����Ϣ
2. ɾ��ָ����ϵ����Ϣ
3. ����ָ����ϵ����Ϣ
5. ��ʾ������ϵ����Ϣ
6. ���������ϵ��
7. ����������������ϵ��
8. ������ϵ�˵��ļ�
9. ������ϵ��
*/
void menu()
{
	printf("*********1.add*************2.search**********\n");
	printf("*********3.del*************4.show************\n");
	printf("*********5.clear***********6.sort************\n");
	printf("*********0.exit************7.amend***********\n");
	printf("*********8.dest************9.save************\n");
}

void start()
{
	int ret = 0;
	int in = 0;
	//��ʼ��ͨѶ¼   ����   usedSize
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("��������Ĳ���>>");
		scanf("%d",&in);
		switch(in)
		{
		case  ADD:
			AddContact(&con);
			break;
		case SEAR:
			ret = SearchContact(&con);
			if (ret == -1)
			{
				printf("����ʧ��\n");
			}
			else
			{
				printf("���ҳɹ�\n");
				ShowContact(&(con));
			}
			break;
		case DEL:
			DelContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case CLEAR:
			ClearContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case AME:
			AmeContact(&con);
			break;
		case DEST:
		    Destroycontact(&con);
			break;
		case SAVE:
			Savecontact(&con);
			break;
		default :
			printf("�������\n");
			break;
		}
	}while(in);
}

int main()
{
	start();
	return 0;
}
#endif