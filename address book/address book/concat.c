#define  _CRT_SECURE_NO_WARNINGS 1
#include"concat.h"
void InitContact(Contact *pCon)
{
	assert(pCon != NULL);
	pCon->capticty = DEFAULT_SIZE;
	pCon->usedSize = 0;
	pCon->per = (PersonInfo *)malloc(sizeof(PersonInfo)* pCon->capticty);
	assert(pCon->per != NULL);
	memset(pCon->per, 0, sizeof(PersonInfo)* pCon->capticty);
	Loadcontact(pCon);
}


void AddContact(Contact *pCon)
{
	int ret = Isfull(pCon);
	assert(pCon != NULL);
	if (ret == 0)
	{
		printf("����ʧ��\n");
		return;
	}
	printf("����������=>\n");
	scanf("%s", pCon->per[pCon->usedSize].name);	
	printf("�������Ա�=>\n");
	scanf("%s", pCon->per[pCon->usedSize].sex);
	printf("����������=>\n");
	scanf("%d", &(pCon->per[pCon->usedSize].age));
	printf("������绰=>\n");
	scanf("%s", pCon->per[pCon->usedSize].tele);
	printf("�������ַ=>\n");
	scanf("%s", pCon->per[pCon->usedSize].addr);
	pCon->usedSize++;
	printf("��ӳɹ�\n");
}

int SearchContact(Contact *pCon)
{
	int i = 0;
	char arr[MAX_NAME];
	assert(pCon != NULL);
	if (pCon->usedSize == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return -1;
	}
	printf("����������=>\n");
	scanf("%s", arr);
	for (i = 0; i < pCon->usedSize; i++)
	{
		if (!strcmp(pCon->per[i].name, arr))
		{
			return i;
		}
	}
	return -1;
}
void DelContact(Contact *pCon)
{
	int i = 0;
	int j = 0;
	char name[MAX_NAME];
	int p = pCon->usedSize;
	assert(pCon != NULL);
	printf("����������=>\n");
	scanf("%s", name);
	for (i = 0; i < pCon->usedSize; i++)
	{
		if (!strcmp(pCon->per[i].name, name))
		{
			pCon->usedSize--;
			for (j = i; j < pCon->usedSize - 1; j++)
			{
				pCon->per[j] = pCon->per[j + 1];
			}
			printf("ɾ���ɹ�\n");
			return;
		}
	}
	if (p >= pCon->usedSize)
	{
		printf("��������\n");
	}
}
void ShowContact(Contact *pCon)
{
	int i = 0;
	assert(pCon != NULL);
	printf("%-20s%-10s%-10s%-11s%-15s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (i = 0; i < pCon->usedSize; i++)
	{
		printf("%-20s%-10s%-10d%-11s%-15s\n", 
			pCon->per[i].name,
			pCon->per[i].sex, 
			pCon->per[i].age, 
			pCon->per[i].tele,
			pCon->per[i].addr);
		
	}
}
void  ClearContact(Contact *pCon)
{
	assert(pCon != NULL);
	pCon->usedSize = 0;
	printf("����ɹ�\n");
}
void menu1()
{
	printf("         �޸��������£�        \n");
	printf(" 1.����                2.�Ա�  \n");
	printf(" 3.����                4.�绰  \n");
	printf(" 5.��ַ                0.�˳�  \n");
}
void AmeContact(Contact *pCon)
{
	int ret = 0;
	int input = 0;
	assert(pCon != NULL);
	ret = SearchContact(pCon);
	if (ret == -1)
	{
		printf("��������\n");
	}
	else
	{
		do
		{
			menu1();
			printf("���������ѡ��\n");
			scanf("%d", &input);
			switch (input)
			{
			case 0:
				break;
			case 1:
				printf("���ĺ�����֣�\n");
				scanf("%s", pCon->per[ret].name);
				break;
			case 2:
				printf("���ĺ���Ա�\n");
				scanf("%s", pCon->per[ret].sex);
				break;
			case 3:
				printf("���ĺ�����䣺\n");
				scanf("%d", pCon->per[ret].age);
				break;
			case 4:
				printf("���ĺ�ĵ绰��\n");
				scanf("%s", pCon->per[ret].tele);
				break;
			case 5:
				printf("���ĺ�ĵ�ַ��\n");
				scanf("%s", pCon->per[ret].addr);
				break;
			default:
				printf("��������\n");
				break;
			}
		} while (input);
		
	}
}
void SortContact(Contact *pCon)
{
	int i = 0;
	int j = 0;
	if (pCon->usedSize == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	assert(pCon != NULL);
	for (i = 0; i < pCon->usedSize - 1; i++)
	{
		for (j = 0; j < pCon->usedSize - 1 - i; j++)
		{
			if (strcmp(pCon->per[j].name, pCon->per[j + 1].name) > 0)
			{
				PersonInfo temp;
				temp = pCon->per[j];
				pCon->per[j] = pCon->per[j + 1];
				pCon->per[j + 1] = temp;

			}
		}
	}
}

void Loadcontact(Contact *pCon)
{
	FILE *pf = fopen("contact.per.txt", "rb");
	PersonInfo temp = { 0 };
	int i = 0;
	if (pf == NULL)
	{
		printf("�ļ�Ϊ��\n");
		return;
	}
	while (fread(&temp, sizeof(PersonInfo), 1, pf))
	{
		Isfull(pCon);
		pCon->per[pCon->usedSize++] = temp;
	}
	fclose(pf);
	pf = NULL;

}
static int Isfull(Contact *pCon)
{
	PersonInfo *ptr;
	assert(pCon != NULL);
	if (pCon->capticty == pCon->usedSize)
	{
		ptr = (PersonInfo *)realloc
			(pCon->per, sizeof(PersonInfo)*pCon->capticty * 2);
		if (ptr != NULL)
		{
			pCon->per = ptr;
			pCon->capticty *= 2;
			printf("���ݳɹ���\n");
			return 1;
		}
		else
		{
			return 0;
		}

	}
	return 1;
}
void Destroycontact(Contact* pCon)
{
	assert(pCon != NULL);
	Savecontact(pCon);
	free(pCon->per);
	pCon->per = NULL;
	pCon->capticty = 0;
	pCon->usedSize = 0;

}
void Savecontact(Contact *pCon)
{
	int i = 0;
	assert(pCon != NULL);
	FILE *pw = fopen("contact.per.txt", "wb");
	
	for (i = 0; i < pCon->usedSize; i++)
	{
		fwrite(pCon->per + i, sizeof(PersonInfo),
			1, pw);
	}
	fclose(pw);
	pw = NULL;

}
