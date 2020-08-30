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
		printf("增容失败\n");
		return;
	}
	printf("请输入姓名=>\n");
	scanf("%s", pCon->per[pCon->usedSize].name);	
	printf("请输入性别=>\n");
	scanf("%s", pCon->per[pCon->usedSize].sex);
	printf("请输入年龄=>\n");
	scanf("%d", &(pCon->per[pCon->usedSize].age));
	printf("请输入电话=>\n");
	scanf("%s", pCon->per[pCon->usedSize].tele);
	printf("请输入地址=>\n");
	scanf("%s", pCon->per[pCon->usedSize].addr);
	pCon->usedSize++;
	printf("添加成功\n");
}

int SearchContact(Contact *pCon)
{
	int i = 0;
	char arr[MAX_NAME];
	assert(pCon != NULL);
	if (pCon->usedSize == 0)
	{
		printf("通讯录为空\n");
		return -1;
	}
	printf("请输入名字=>\n");
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
	printf("请输入名字=>\n");
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
			printf("删除成功\n");
			return;
		}
	}
	if (p >= pCon->usedSize)
	{
		printf("输入有误\n");
	}
}
void ShowContact(Contact *pCon)
{
	int i = 0;
	assert(pCon != NULL);
	printf("%-20s%-10s%-10s%-11s%-15s\n", "姓名", "性别", "年龄", "电话", "地址");
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
	printf("清除成功\n");
}
void menu1()
{
	printf("         修改内容如下：        \n");
	printf(" 1.名字                2.性别  \n");
	printf(" 3.年龄                4.电话  \n");
	printf(" 5.地址                0.退出  \n");
}
void AmeContact(Contact *pCon)
{
	int ret = 0;
	int input = 0;
	assert(pCon != NULL);
	ret = SearchContact(pCon);
	if (ret == -1)
	{
		printf("输入有误\n");
	}
	else
	{
		do
		{
			menu1();
			printf("请输入你的选择\n");
			scanf("%d", &input);
			switch (input)
			{
			case 0:
				break;
			case 1:
				printf("更改后的名字：\n");
				scanf("%s", pCon->per[ret].name);
				break;
			case 2:
				printf("更改后的性别：\n");
				scanf("%s", pCon->per[ret].sex);
				break;
			case 3:
				printf("更改后的年龄：\n");
				scanf("%d", pCon->per[ret].age);
				break;
			case 4:
				printf("更改后的电话：\n");
				scanf("%s", pCon->per[ret].tele);
				break;
			case 5:
				printf("更改后的地址：\n");
				scanf("%s", pCon->per[ret].addr);
				break;
			default:
				printf("输入有误\n");
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
		printf("通讯录为空\n");
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
		printf("文件为空\n");
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
			printf("增容成功！\n");
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
