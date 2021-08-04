#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


void menu()
{
	printf("-------------------------------\n");
	printf("---------  通讯录2.0    -------\n");
	printf("--------- 1.增加联系人---------\n");
	printf("----------2.删除联系人---------\n");
	printf("----------3.查找联系人---------\n");
	printf("----------4.修改联系人---------\n");
	printf("----------5.查看通讯录---------\n");
	printf("----------6.保存文档 ----------\n");
	printf("----------7.随机载入联系人 -----\n");
	printf("----------0.退出通讯录---------\t文件版本 自动保存\n");
	printf("-------------------------------\t已自动排序 按年龄大小\n");
}

int main(void)
{
	contact ct;
	contactinitialize(&ct);
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
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
			printf("已退出程序\n");
			break;
		}
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	freecontact(&ct);
	return 0;
}