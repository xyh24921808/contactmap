#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<time.h>

#define NAME_MAX 10
#define PHONE_MAX 20
#define HOME_MAX 20

enum OP
{
	EXIT,
	ADD,
	DET,
	FIND,
	CHANGER,
	SHOW,
	SAVE,
	RAND
};

typedef struct
{
	char name[NAME_MAX];
	int age;
	char sex[5];
	int height; //cm
	char phonenumber[PHONE_MAX];
	char address[HOME_MAX];
}info;

typedef struct contact
{
	info* data;
	int size;
	int capacity;
}contact;



void contactinitialize(contact* ps);  //初始化ct

void addcontact(contact* ps);  //增加联系人

void detcontact(contact* ps);  //删除某个联系人

void findcontact(contact* ps); //查找联系人

void changecontact(contact* ps); //修改某个联系人

void showcontact(contact* ps);  //展示通讯录

void savetxtcontact(contact* ps); //保存通讯录文档

void logincontact(contact* ps); //加载通讯录文档

void randcontact(contact* ps); //随机载入联系人

void freecontact(contact* ps); //释放内存
