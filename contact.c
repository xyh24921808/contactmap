#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


void menu()
{
	printf("-------------------------------\n");
	printf("---------  ͨѶ¼2.0    -------\n");
	printf("--------- 1.������ϵ��---------\n");
	printf("----------2.ɾ����ϵ��---------\n");
	printf("----------3.������ϵ��---------\n");
	printf("----------4.�޸���ϵ��---------\n");
	printf("----------5.�鿴ͨѶ¼---------\n");
	printf("----------6.�����ĵ� ----------\n");
	printf("----------7.���������ϵ�� -----\n");
	printf("----------0.�˳�ͨѶ¼---------\t�ļ��汾 �Զ�����\n");
	printf("-------------------------------\t���Զ����� �������С\n");
}

int main(void)
{
	contact ct;
	contactinitialize(&ct);
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
		{
			system("cls");
			addcontact(&ct);
			break;
		}
		case DET:
		{
			system("cls");
			detcontact(&ct);
			break;
		}
		case FIND:
		{
			system("cls");
			findcontact(&ct);
			break;
		}
		case CHANGER:
		{
			system("cls");
			changecontact(&ct);
			break;
		}
		case SHOW:
		{
			system("cls");
			showcontact(&ct);
			break;
		}
		case SAVE:
		{
			savetxtcontact(&ct);
			break;
		}
		case RAND:
		{
			randcontact(&ct);
			break;
		}
		case EXIT:
		{
			savetxtcontact(&ct);
			printf("���˳�����\n");
			break;
		}
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	freecontact(&ct);
	return 0;
}