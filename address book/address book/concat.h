#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<vld.h>

#ifndef  __CONTACT__H__
#define __CONTACT__H__

enum Option
{
	EXIT,
	ADD,
	SEAR,
	DEL,
	SHOW,
	CLEAR,
	SORT,
	AME,
	DEST,
	SAVE
};

#define MAX_NAME  20
#define MAX_TEL      11
#define MAX_ADDR  15
#define MAX_SEX      3
#define DEFAULT_SIZE 2

#define MAX_NUMPERSON      1000
//个人信息
typedef struct PersonInfo
{
	//name  age   tele  addr   sex
	char name[MAX_NAME];
	short age;
	char tele[MAX_TEL];
	char addr[MAX_TEL];
	char sex[MAX_SEX];
}PersonInfo;
//通讯录
typedef struct Contact
{
	PersonInfo *per;
	int usedSize;//被使用的个数
	int capticty;
}Contact;

void InitContact(Contact *pCon);
void AddContact(Contact *pCon);
int SearchContact(Contact *pCon);
void DelContact(Contact *pCon);
void ShowContact(Contact *pCon);
void  ClearContact(Contact *pCon);
void SortContact(Contact *pCon);
void AmeContact(Contact *pCon);
void Destroycontact(Contact* pCon);
void Savecontact(Contact *pCon);
void Loadcontact(Contact *pCon);
#endif// __CONTACT__H__
