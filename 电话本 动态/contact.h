#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

#define DEFAULT_SIZE 2
#define MAX_NAME  20
#define MAX_TEL      11
#define MAX_ADDR  15
#define MAX_SEX      3

typedef struct PersonInfo
{
	//name  age   tele  addr   sex
	char name[MAX_NAME];
	short age;
	char tele[MAX_TEL];
	char addr[MAX_TEL];
	char sex[MAX_SEX];
}PersonInfo;

typedef struct Contact
{
	PersonInfo *per;
	int usedSize;
	int capticty;
}Contact;