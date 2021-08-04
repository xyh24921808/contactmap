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



void contactinitialize(contact* ps);  //��ʼ��ct

void addcontact(contact* ps);  //������ϵ��

void detcontact(contact* ps);  //ɾ��ĳ����ϵ��

void findcontact(contact* ps); //������ϵ��

void changecontact(contact* ps); //�޸�ĳ����ϵ��

void showcontact(contact* ps);  //չʾͨѶ¼

void savetxtcontact(contact* ps); //����ͨѶ¼�ĵ�

void logincontact(contact* ps); //����ͨѶ¼�ĵ�

void randcontact(contact* ps); //���������ϵ��

void freecontact(contact* ps); //�ͷ��ڴ�
