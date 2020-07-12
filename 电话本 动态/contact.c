#define  _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void InitContact(Contact *pCon)
{
	pCon->capticty = DEFAULT_SIZE;
	pCon->usedSize = 0;
	pCon->per = (PersonInfo *)malloc(sizeof(PersonInfo)* pCon->capticty);
	assert(pCon->per != NULL);
	memset(pCon->per, 0, sizeof(PersonInfo)* pCon->capticty);
}
static int CheckFull(Contact *pCon)
{
	PersonInfo *ptr = NULL;
	if (pCon->usedSize == pCon->capticty)
	{
		ptr = (PersonInfo *)realloc(pCon->per, 
			sizeof(PersonInfo)* pCon->capticty * 2);
	}
	if (ptr != NULL)
	{
		pCon->per = ptr;
	}
	
}
void AddContact(Contact *pCon)
{

}