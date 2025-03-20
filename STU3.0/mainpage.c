#include"Stu.h"
int main()
{
	int first = 1, n = 0, m = 0, i, j,k;
	int ch; STU* stu=NULL; STU* pre;
	system("mode con cols=130 lines=60");
	system("color 0E");
	system("cls");
	SetPosition(POS_X3, 5);
	printf("请输入您的身份:1.学生 2.老师:");
	scanf("%d", &k);
	while (1)
	{
		system("cls");
		if (k == 1) { ch = MenuStu(); }
		else { ch = MenuTea(); }
		switch (ch)
		{
		case 1:
			system("cls");
			InputRecord(&n, &m, &stu);
			first = 0;
			CalculateScoreOfStudent(n, m, stu);
			break;
		case 2:
			system("cls");
			if (first)
			{
				printf("系统中尚无学生成绩信息，请先输入！\n");
				system("pause");
				break;
			}
			AppendRecord(&n, m, stu);
			system("pause");
			break;
		case 3:
			system("cls");
			if (first)
			{
				printf("系统中尚无学生成绩信息，请先输入！\n");
				system("pause");
				break;
			}
			if (DeleteRecord(&n, m, stu)) { pre = stu; stu = stu->next; free(pre); }
			n = n - 1;
			system("pause");
			break;
		case 4:
			system("cls");
			if (first)
			{
				printf("系统中尚无学生成绩信息，请先输入!\n");
				system("pause");
				break;
			}
			SearchbyNum(n, m, stu);
			system("pause");
			break;
		case 5:
			system("cls");
			if (first)
			{
				printf("系统中尚无学生成绩信息，请先输入！\n");
				system("pause");
				break;
			}
			SearchbyName(n, m, stu);
			system("pause");
			break;
		case 6:
			system("cls");
			if (first)
			{
				printf("系统中尚无学生成绩信息，请先输入！\n");
				system("pause");
				break;
			}
			ModifyRecord(n, m, stu);
			system("pause");
			break;
		case 7:
			system("cls");
			if (first)
			{
				printf("系统中尚无学生成绩信息，请先输入!\n");
				system("pause");
				break;
			}
			CalculateScoreOfStudent(n, m, stu);
			system("pause");
			break;
		case 8:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("系统中尚无学生成绩信息，请先输入！\n");
				getch();
				break;
			}
			CalculateScoreOfCourse(n, m, stu);
			getch();
			break;
		case 9:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("系统中尚无学生成绩信息，请先输入！\n");
				getch();
				break;
			}
			stu = SortbyNum(n, m, stu);
			getch();
			break;
		case 10:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("系统中尚无学生成绩信息，请先输入！\n");
				getch();
				break;
			}
			stu = SortbyName(n, m, stu);
			getch();
			break;
		case 11:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("系统中尚无学生成绩信息，请先输入！\n");
				getch();
				break;
			}
			stu = SortbyScoreB(n, m, stu);
			getch();
			break;
		case 12:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("系统中尚无学生成绩信息，请先输入！\n");
				getch();
				break;
			}
			stu = SortbyScoreA(n, m, stu);
			getch();
			break;
		case 13:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("系统中尚无学生成绩信息，请先输入！\n");
				getch();
				break;
			}
			StatisticAnalysis(n, m, stu);
			getch();
			break;
		case 14:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("系统中尚无学生成绩信息，请先输入！\n");
				getch();
				break;
			}
			PrintRecord(n, m, stu);
			getch();
			break;
		case 15:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("系统中尚无学生成绩信息，请先输入！\n");
				getch();
				break;
			}
			WriteToFileBinary(n, stu);
			getch();
			break;
		case 16:
			system("cls");
			if (ReadfromFileBinary(&n, stu, &first) || first)
			{
				SetPosition(POS_X1, 10);
				printf("尚未输入学生信息或文件打开失败，请先检查！\n");
				getch();
				break;
			}
			getch();
			break;
		case 17:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("系统中尚无学生成绩信息，请先输入！\n");
				getch();
				break;
			}
			FuzzyQuery(n, m, stu);
			getch();
			break;
		case 0:
			system("cls");
			printf("退出系统!\n");
			//释放链表空间
			while (stu->next != NULL)
			{
				pre = stu;
				stu = stu->next;
				free(pre);
			}
			exit(0);
		default:
			system("cls");
			printf("输入错误，请重新选择操作!\n");
			system("pause");
		}
	}
	return 0;
}