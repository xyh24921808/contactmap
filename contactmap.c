#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

int cmp(const void* base1, const void* base2)
{
	return (*(info*)base1).age > (*(info*)base2).age;
}

void contactinitialize(contact* ps)
{
	ps->data = (info*)malloc(sizeof(info) * 4);
	if (ps->data == NULL)
	{
		return;
	}
	ps->capacity = 4;
	ps->size = 0;
	logincontact(ps);
}

void logincontact(contact* ps)
{
	FILE* fw = fopen("contact.txt", "rb");
	if (fw == NULL)
	{
		printf("���ش���:%s\n", strerror(errno));
		printf("�����һ������û��contact.txt,���Զ������ĵ�����\n");
		return;
	}

	info tmp = { 0 };
	while (fread(&tmp, sizeof(info), 1, fw))
	{
		if (ps->size >= ps->capacity)
		{
			info* tmp = (info*)realloc(ps->data, sizeof(info) * ps->capacity * 2);
			if (tmp == NULL)
			{
				printf("cperro");
				return;
			}
			ps->data = tmp;
			ps->capacity *= 2;
		}
		ps->data[ps->size] = tmp;
		ps->size++;
	}
	fclose(fw);
	fw = NULL;
	return;
}


void addcontact(contact* ps)
{
	if (ps->size >= ps->capacity)
	{
		info*tmp = (info*)realloc(ps->data, sizeof(info) * ps->capacity * 2);
		if (tmp == NULL)
		{
			printf("cperro");
			return;
		}
		ps->data = tmp;
		ps->capacity *= 2;
	}
	printf("����������:>");
	scanf("%s", ps->data[ps->size].name);
	printf("�������Ա�:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("����������:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("���������:>");
	scanf("%d", &(ps->data[ps->size].height));
	printf("���������ϵ�˵ĵ绰:>");
	scanf("%s", ps->data[ps->size].phonenumber);
	printf("�������ַ:>");
	scanf("%s", ps->data[ps->size].address);
	ps->size++;
	qsort(ps->data, ps->size, sizeof(info), cmp);
	return;
}

int findct(contact* ps,char*tmp)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (!strcmp(ps->data[i].name, tmp))
		{
			return i;
		}
	}
	return -1;
}

void detcontact(contact* ps)
{
	char tmp[NAME_MAX];
	printf("������Ҫɾ����ϵ�˵�����:>");
	scanf("%s", tmp);
	int ret = findct(ps, tmp);
	if (ret == -1)
	{
		printf("�޷�ɾ��������ϵ��\n");
		return;
	}
	else
	{
		for (int i = ret; i < ps->size-1; i++)
		{
			ps->data[i] = ps->data[i + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
		qsort(ps->data, ps->size, sizeof(info), cmp);
		return;
	}
}

void findcontact(contact* ps)
{
	char tmp[NAME_MAX];
	printf("������Ҫ������ϵ�˵�����:>");
	scanf("%s", tmp);
	int ret = findct(ps, tmp);
	if (ret == -1)
	{
		printf("�޷����Ҹ���ϵ��\n");
		return;
	}
	else
	{
		printf("���ҳɹ� ����\n");
		printf("%-20s\t%-5s\t%-5s\t%-5s\t%-15s\t%-20s\n", "����", "�Ա�", "����", "���", "�绰", "סַ");
		printf("%-20s\t%-5s\t%-5d\t%-5d\t%-15s\t%-20s\n", ps->data[ret].name, ps->data[ret].sex, ps->data[ret].age,
			ps->data[ret].height, ps->data[ret].phonenumber, ps->data[ret].address);
		return;
	}
}

void changecontact(contact* ps)
{
	char tmp[NAME_MAX];
	printf("������Ҫ�޸���ϵ�˵�����:>");
	scanf("%s", tmp);
	int ret = findct(ps, tmp);
	if (ret == -1)
	{
		printf("�޷��޸ĸ���ϵ��\n");
		return;
	}
	else
	{
		printf("���������ϵ���޸ĺ���Ϣ\n");
		printf("����������:>");
		scanf("%s", ps->data[ret].name);
		printf("�������Ա�:>");
		scanf("%s", ps->data[ret].sex);
		printf("����������:>");
		scanf("%d", &(ps->data[ret].age));
		printf("���������:>");
		scanf("%d", &(ps->data[ret].height));
		printf("���������ϵ�˵ĵ绰:>");
		scanf("%s", ps->data[ret].phonenumber);
		printf("�������ַ:>");
		scanf("%s", ps->data[ret].address);
		qsort(ps->data, ps->size, sizeof(info), cmp);
	}
}

void showcontact(contact* ps)
{
	if (ps->size == 0)
	{
		printf("û����ϵ�˿�չʾ\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-5s\t%-15s\t%-20s\n", "����", "�Ա�", "����", "���(cm)", "�绰", "סַ");
		for (int i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-5s\t%-5d\t%-5d\t%-15s\t%-20s\n", ps->data[i].name, ps->data[i].sex, ps->data[i].age,
				ps->data[i].height, ps->data[i].phonenumber, ps->data[i].address);
		}
		return;
	}
}

void savetxtcontact(contact* ps)
{
	FILE* fp = fopen("contact.txt", "wb");
	if (fp == NULL)
	{
		printf("�������:%s\n", strerror(errno));
		return;
	}
	for (int i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]),sizeof(info),1, fp);
	}
	printf("����ɹ�\n");
	fclose(fp);
	fp = NULL;
	return;
}

void randcontact(contact* ps)
{
	int size = 0;
	printf("�����������������:>");
	scanf("%d", &size);
	if (size < 0)
	{
		printf("��������С��0��\n");
		return;
	}
	info*tmp = (info*)realloc(ps->data,sizeof(info) * size*2);
	if (tmp == NULL)
	{
		return;
	}
	ps->data = tmp;
	ps->capacity += size;
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
	{
		int age = rand()/2;
		char sex[5] = { 0 };
		char name[NAME_MAX] = { 0 };
		int height = rand();
		char number[PHONE_MAX] = { 0 };
		char home[HOME_MAX] = { 0 };
		if (rand() % 2 == 0)
		{
			sprintf(sex, "%s","��");
		}
		else
		{
			sprintf(sex, "%s", "Ů");
		}
		sprintf(name, "%d", rand());
		sprintf(number, "%d", rand()/2);
		sprintf(home, "%d", rand() - 2);
		ps->data[ps->size].age = age;
		strcpy(ps->data[ps->size].name,name);
		ps->data[ps->size].height = height;
		strcpy(ps->data[ps->size].sex,sex);
		strcpy(ps->data[ps->size].phonenumber, number);
		strcpy(ps->data[ps->size].address,home);
		ps->size++;
	}
	qsort(ps->data,size, sizeof(info), cmp);
	return;
}


void freecontact(contact* ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->size = 0;
	ps->capacity = 0;
	return;
}