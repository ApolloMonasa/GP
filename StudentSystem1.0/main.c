#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define STU_NUM 50 //学生数量上限
#define COURSE_NUM 10 //课程数量上限
#define NAME_LEN 30 //学生名字长度
#define POS_X1 35 //菜单页第一列功能选项的初始的X位置  排序后输出结果的X位置
#define POS_X2 40 //功能提示语句的X位置
#define POS_X3 50 //警告提示的初始X位置
#define POS_X4 65 //菜单页第二列功能选项的初始的X位置
#define POS_Y 3 //排序后输出结果的Y位置
typedef struct student {
	long num;//学号
	char name[NAME_LEN];
	float score[COURSE_NUM];
	float sum;
	float aver;
	struct student* next;
}STU;
// 自定义函数声明
int Menu(void);
// 操作菜单
void SetPosition(int x, int y);
//创建链表
STU* CreatNode(int num);
// 设置输出内容在控制台窗口中的起始位置
void InputRecord(int* n, int* m, STU* stu);
// 输入学生信息
void AppendRecord(int* n, int m, STU* stu);
// 增加学生信息
int DeleteRecord(int* n, int m, STU* stu);
// 删除学生信息（指删除整条记录）
void SearchbyNum(int n, int m, STU* stu);
// 按学号查询学生信息
void SearchbyName(int n, int m, STU* stu);
// 按姓名查询学生信息
void ModifyRecord(int n, int m, STU* stu);
// 修改学生信息
void CalculateScoreOfStudent(int n, int m, STU* stu);
// 计算学生的总分和平均分
void CalculateScoreOfCourse(int n, int m, STU* stu);
// 计算某门课程的总分和平均分
void CalculateScoreOfCourse(int n, int m, STU* stu);
// 按学号排序
STU* SortbyNum(int n, int m, STU* stu);
// 按姓名排序
STU* SortbyName(int n, int m, STU* stu);
// 按每个学生平均分进行排序
STU* SortbyScoreA(int n, int m, STU* stu);
// 升序排序
STU* SortbyScoreB(int n, int m, STU* stu);
// 降序排序
void StatisticAnalysis(int n, int m, STU* stu);
// 打印学生成绩
void PrintRecord(int n, int m, STU* stu);
// 将学生信息保存至文件中
void WriteToFile(int n, int m, STU* stu);
// 将学生信息从文件中读出，存入内存，方便对学生信息进行处理
int ReadfromFile(int* n, int* m, STU* stu, int* first);
//改变链表顺序函数,将会用于链表的冒泡排序
void ChangeOrder(STU* p1,STU* p2,STU* q1,STU* q2);
int main()
{
	int first=1,n = 0,m=0,i,j;
	int ch; STU* stu; STU* pre;
	stu=CreatNode(STU_NUM);
	system("mode con cols=130 lines=60");
	system("color 0E");
	while (1)
	{
		system("cls");
		ch = Menu();
		switch (ch)
		{
		case 1:
			system("cls");
			InputRecord(&n,&m,stu);
			first = 0;
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
			CalculateScoreOfStudent(n,m,stu);
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
			stu=SortbyNum(n, m, stu);
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
			stu=SortbyName(n, m, stu);
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
			stu=SortbyScoreB(n, m, stu);
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
			WriteToFile(n, m, stu);
			getch();
			break;
		case 16:
			system("cls");
			if (ReadfromFile(&n, &m, stu, &first) || first)
			{
				SetPosition(POS_X1, 10);
				printf("尚未输入学生信息或文件打开失败，请先检查！\n");
				getch();
				break;
			}
			getch();
			break;
		case 0:
			system("cls");
			printf("退出系统!\n");
			STU* temp = stu; stu = stu->next;
			while (stu != NULL)
			{
				free(temp); temp = stu; stu = stu->next;
			}
			free(temp);
			exit(0);
		default:
			system("cls");
			printf("输入错误，请重新选择操作!\n");
			system("pause");
		}
	}
	return 0;
}
int Menu(void)
{
	int posy = 5;
	int option; // 保存用户输入的操作代号的变量
	int i, j;
	SetPosition(POS_X3, posy);
	printf("学生成绩管理系统\n"); // 输出系统名字
	// 输出系统名字和功能说明之间的两行短横线
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	// 输出系统支持的功能和对应的功能代号
	SetPosition(POS_X1, ++posy);
	printf("1. 输入学生信息");
	SetPosition(POS_X4, posy);
	printf("2. 增加学生成绩");
	SetPosition(POS_X1, posy += 2);
	printf("3. 删除学生信息");
	SetPosition(POS_X4, posy);
	printf("4. 按学号查找记录");
	SetPosition(POS_X1, posy += 2);
	printf("5. 按姓名查找记录");
	SetPosition(POS_X4, posy);
	printf("6. 修改学生信息");
	SetPosition(POS_X1, ++posy);
	printf("7. 计算学生成绩");
	SetPosition(POS_X4, posy);
	printf("8. 计算课程成绩");
	SetPosition(POS_X1, posy += 2);
	printf("9. 按学号排序");
	SetPosition(POS_X4, posy);
	printf("10. 按姓名排序");
	SetPosition(POS_X1, posy += 2);
	printf("11. 按总成绩降序排序");
	SetPosition(POS_X4, posy);
	printf("12. 按总成绩升序排序");
	SetPosition(POS_X1, posy += 2);
	printf("13. 学生成绩统计");
	SetPosition(POS_X4, posy);
	printf("14. 打印学生记录");
	SetPosition(POS_X1, posy += 2);
	printf("15. 学生记录存盘");
	SetPosition(POS_X4, posy);
	printf("16. 从磁盘读取学生记录");
	SetPosition(POS_X1, posy += 2);
	printf("0. 退出");
	// 输出系统支持的功能与输入提示语之间的两行短横线
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	// 提示用户输入所要执行的功能代号
	SetPosition(POS_X1, ++posy);
	printf("请选择你想要进行的操作[0~16]：");
	scanf("%d", &option);
	return option;
}
void SetPosition(int x, int y)
{
	HANDLE hOut;
	COORD pos;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}
void ChangeOrder(STU* p1, STU* p2, STU* q1, STU* q2)
{
	STU* temp;//两个前驱指针p1,q1相互交换next值,两个目标指针p2,q2相互交换next值即可实现换位。
	temp = p1->next; p1->next = q1->next; q1->next = temp;
	temp = p2->next; p2->next = q2->next; q2->next = temp;
}
void InputRecord(int* n, int* m, STU* stu)
{
	int i, j, posy = 6;
	SetPosition(POS_X2, posy);
	printf("输入学生人数(n<%d):",STU_NUM);
	scanf("%d", n);
	SetPosition(POS_X2,posy+=2);
	printf("输入课程门数(m<%d):",COURSE_NUM);
	scanf("%d", m);
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	SetPosition(POS_X2, ++posy);
	printf("输入学生的学号、姓名和各门课程成绩：");
	for (i = 0; i < *n; i++)
	{
		SetPosition(POS_X2, ++posy);
		printf("输入第%d个学生信息：\t", i + 1);
		scanf("%ld%s", &stu->num, stu->name); 
		for (j = 0; j < *m; j++)
		{
			scanf("%f", &stu->score[j]);
		}
		stu = stu->next;
	}
}
void CalculateScoreOfStudent(int n, int m, STU* stu)
{
	int i, j;
	printf("每个学生各门课程的总分和平均分为：\n");
	for (i = 0; i < n; i++)
	{
		stu->sum = 0;
		for (j = 0; j < m; j++)
		{
			stu->sum += stu->score[j];
		}
		stu->aver = stu->sum / m; 
		printf("第%d个学生：总分=%.2f，平均分=%.2f\n", i + 1, stu->sum, stu->aver);
        stu = stu->next;
	}
}
void CalculateScoreOfCourse(int n, int m, STU* stu)
{
	int i, j;
	float sum[COURSE_NUM], aver[COURSE_NUM];
	int posy = 7;
	SetPosition(POS_X1, posy);
	printf("各门课程的总分和平均分的计算结果为：");
	for (j = 0; j < m; j++)
	{
		sum[j] = 0;
		for (i = 0; i < n; i++)
		{
			sum[j] += stu->score[j]; stu = stu->next;
		}
		aver[j] = sum[j] / n;
		SetPosition(POS_X1, ++posy);
		printf("第%d 门课程：总分 = %.2f，平均分 = %.2f\n", j + 1, sum[j], aver[j]);
	}
}
void WriteToFile(int n, int m, STU*stu)
{
	int i, j;
	FILE* fp;
	// 打开文件，指定对文件的处理方式为写入，并让指针指向文件
	if ((fp = fopen("VSVS.testSTUmanagmntsysstudent.txt", "w")) == NULL)
	{
		printf("文件 student.txt 无法正常打开！");
		exit(0);
	}
	// 将数据按指定格式写入文件，包括学生人数 n，课程门数 m 以及每个学生的信息
	fprintf(fp, "%10d%10d\n", n, m);
	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%10ld%10s\n", stu->num, stu->name);
		for (j = 0; j < m; j++)
		{
			fprintf(fp, "%10.1f", stu->score[j]);
		}
		fprintf(fp, "%10.1f%10.1f\n", stu->sum, stu->aver);
		stu = stu->next;
	}
	// 关闭文件
	fclose(fp);
	// 提示用户存盘操作完毕
	printf("存盘完毕！\n");
}
int ReadfromFile(int* n, int* m, STU *stu, int* first)
{
	// 定义文件指针
	FILE* fp;
	int i, j;
	int posy = 8;
	SetPosition(POS_X1, posy);
	// 打开文件，指定对文件的处理方式为读操作，并让指针指向文件
	if ((fp = fopen("VSVS.testSTUmanagmntsysstudent.txt", "r")) == NULL)
	{
		printf("磁盘文件 student.txt 无法打开");
		return 1;
	}
	// 将数据按指定格式从磁盘文件读出，包括学生人数 n，课程门数 m 以及每位学生的信息
	fscanf(fp, "%10d%10d", n, m);
	for (i = 0; i < *n; i++)
	{
		fscanf(fp, "%10ld", &stu->num);
		fscanf(fp, "%10s", stu->name);
		for (j = 0; j < *m; j++)
		{
			fscanf(fp, "%10f", &stu->score[j]);
		}
		fscanf(fp, "%10f%10f", &stu->sum, &stu->aver); stu = stu->next;
	}
	*first = 0; // 修改标志变量
	// 关闭文件
	fclose(fp);
	printf("数据从磁盘读取完毕!");
	return 0;
}
void AppendRecord(int* n, int m, STU *stu)
{
	int i, j;
	int num_record;
	printf("请输入需要增加的学生记录条数：");
	scanf("%d", &num_record);
	while (*n + num_record > STU_NUM) // 判断新增记录与原有记录之和是否小于设定上限
	{
		printf("要增加的记录条数太多，请重新输入：");
		scanf("%d", &num_record);
	}
	for (i = 0; i < *n; i++)
	{
		stu = stu->next;
	}
	for (i = *n; i < *n + num_record; i++)
	{
		printf("输入第%d个学生信息(学号+姓名+%d门成绩)：\t", i + 1,m);
		scanf("%ld%s", &stu->num, stu->name);
		for (j = 0; j < m; j++)
		{
			scanf("%f", &stu->score[j]);
		}
		stu = stu->next;
	}
	*n = *n + num_record;
	printf("添加完毕！\n");
	return;
}
//创建链表
STU* CreatNode(int num)
{
	STU*now; STU* head; STU* next; int i;
	head = (STU*)malloc(sizeof(STU)); now = head;
	if (head == NULL)
	{
		printf("内存分配失败，即将退出程序!\n");
		exit(0);
	}
	for (i = 1; i < num; i++)
	{
		next= (STU*)malloc(sizeof(STU));
		now->next = next; now = next;
	}
	now->next = NULL; return head;
}
void SearchbyNum(int n, int m, STU* stu)
{
	long id;
	int i, j;
	printf("请输入你要查找的学生的学号：");
	scanf("%ld", &id);
	for (i = 0; i < n; i++)
	{
		if (stu->num == id)
		{
			printf("找到了，该学号对应的学生信息为：\n");
			printf("%10ld%15s", stu->num, stu->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", stu->score[j]);
			}
			printf("%10.2f%10.2f", stu->sum, stu->aver);
			return;
		}
		stu = stu->next;
	}
	printf("未找到这个学号对应的学生记录\n");
	return;
}
void SearchbyName(int n, int m, STU* stu)
{
	int flag = 1;
	int i, j;
	int k = 0;
	char name[NAME_LEN];
	printf("请输入你要查找的学生的姓名：");
	scanf("%s", name);
	for (i = 0; i < n; i++)
	{
		if (strcmp(stu->name, name) == 0)
		{
			printf("找到了，第%d 个学生信息为：\n", ++k);
			printf("%10ld%15s", stu->num, stu->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", stu->score[j]);
			}
			printf("%10.2f%10.2f\n", stu->sum, stu->aver);
			flag = 0;
		}
		stu = stu->next;
	}
	if (flag)
	{
		printf("未找到这个姓名对应的学生记录\n");
	}
	return;
}
int DeleteRecord(int* n, int m, STU* stu)
{
	int i, j;
	long id;
	char ch;
	STU* pre=stu;//前驱节点
	printf("请输入你要删除学生信息对应的学号：");
	scanf("%ld", &id);
	for (i = 0; i < *n; i++)
	{
		if (stu->num == id)
		{
			printf("找到了该生记录，信息为：\n");
			printf("%10ld%15s", stu->num, stu->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", stu->score[j]);
			}
			printf("%10.2f%10.2f\n", stu->sum, stu->aver);
			printf("请确认是否需要删除这条记录？(Y/y或N/n)：");
			getchar();
			scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y')
			{
				if (i == 0) { return 1; }
				pre->next = stu->next; free(stu);
				return 0;
			}
			else if (ch == 'N' || ch == 'n')
			{
				printf("找到了该学生记录，但不删除\n");
				return 0;
			}
			else
			{
				printf("输入出错！\n");
				return 0;
			}
		}
		pre=stu; stu = stu->next;
	}
	printf("未找到该生记录！\n");
	return;
}
void ModifyRecord(int n, int m, STU* stu)
{
	int i, j;
	long id;
	char ch;
	printf("请输入需要修改信息对应的学号：");
	scanf("%ld", &id);
	for (i = 0; i < n; i++)
	{
		if (stu->num == id)
		{
			printf("找到了该生记录，信息为：\n");
			printf("%10ld%15s", stu->num, stu->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", stu->score[j]);
			}
			printf("%10.2f%10.2f\n", stu->sum, stu->aver);
			printf("请确认是否需要修改？(Y/N 或 y/n)：");
			getchar();
			scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y')
			{
				printf("请输入要修改的学生信息：（学号+姓名+成绩）");
				scanf("%ld%s", &stu->num, stu->name);
				stu->sum = 0;
				for (j = 0; j < m; j++)
				{
					scanf("%f", &stu->score[j]);
					stu->sum += stu->score[j];
				}
				stu->aver = stu->sum / m;
				printf("修改完毕\n");
				return;
			}
			else if (ch == 'N' || ch == 'n')
			{
				printf("找到了该生记录，但不修改\n");
				return;
			}
			else
			{
				printf("输入出错！\n");
				return;
			}
		}
		stu = stu->next;
	}
	printf("未找到该生记录！\n");
	return;
}
void PrintRecord(int n, int m, STU* stu)
{
	int i, j;
	printf("学号\t\t姓名\t\t");
	for (j = 0; j < m; j++)
	{
		printf("课程%d\t\t", j + 1);
	}
	printf("总分\t\t平均分\n");
	for (i = 0; i < n; i++)
	{
		printf("%-16ld%-16s", stu->num, stu->name);
		for (j = 0; j < m; j++)
		{
			printf("%-16.1f", stu->score[j]);
		}
		printf("%-16.1f%-16.1f\n", stu->sum, stu->aver);
		stu = stu->next;
	}
	return;
}
STU* SortbyName(int n, int m, STU* stu)
{
	int i, j, flag = 0;
	STU* temp;
	STU* newhead=stu;//存储新的头节点
	STU* houpre = stu;//后面一个目标节点的前驱节点。
	STU* hou = stu->next;//后面的目标节点。
	STU* headpre; headpre = (STU*)malloc(sizeof(STU)); headpre->next = stu; STU* freehead = headpre;
	//创建新指针和结构体，其next值指向头节点，充当头节点的前驱指针，同时充当前面一个目标节点的前驱节点。
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(stu->name, hou->name) > 0)
			{
				ChangeOrder(headpre, stu, houpre, hou); flag = 1;
			}
			houpre = hou; hou = hou->next;
		}
		if (flag == 1 && i == 0)
		{
			newhead = headpre->next;
		}
		headpre = stu; stu = stu->next;
	}
	printf("按姓名字典对学生记录排序完毕");
	free(freehead);
	return newhead;
}
STU* SortbyNum(int n, int m, STU* stu)
{
	int i, j,flag=0;
	STU* temp;
	STU* newhead=stu;//存储新的头节点
	STU* houpre=stu;//后面一个目标节点的前驱节点。
	STU* hou=stu->next;//后面的目标节点。
	STU* headpre; headpre = (STU*)malloc(sizeof(STU)); headpre->next = stu; STU* freehead = headpre;
	//创建新指针和结构体，其next值指向头节点，充当头节点的前驱指针，同时充当前面一个目标节点的前驱节点。
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (hou->num < stu->num)
			{
				ChangeOrder(headpre, stu, houpre, hou); flag = 1;
			}
			houpre= hou; hou = hou->next;
		}
		if (flag== 1&&i==0)
		{
			newhead = headpre->next;
		}
		headpre = stu; stu = stu->next;
	}
	printf("按学号从小到大对学生记录排序完毕");
	free(freehead);
	return newhead;
}
STU* SortbyScoreA(int n, int m, STU* stu)
{
	int i, j, flag = 0;
	STU* temp;
	STU* newhead=stu;//存储新的头节点
	STU* houpre = stu;//后面一个目标节点的前驱节点。
	STU* hou = stu->next;//后面的目标节点。
	STU* headpre; headpre = (STU*)malloc(sizeof(STU)); headpre->next = stu; STU* freehead = headpre;
	//创建新指针和结构体，其next值指向头节点，充当头节点的前驱指针，同时充当前面一个目标节点的前驱节点。
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (hou->sum < stu->sum)
			{
				ChangeOrder(headpre, stu, houpre, hou); flag = 1;
			}
			houpre = hou; hou = hou->next;
		}
		if (flag == 1 && i == 0)
		{
			newhead = headpre->next;
		}
		headpre = stu; stu = stu->next;
	}
	printf("按总分从小到大对学生记录排序完毕");
	free(freehead);
	return newhead;
}
STU* SortbyScoreB(int n, int m, STU* stu)
{
	int i, j, flag = 0;
	STU* temp;
	STU* newhead=stu;//存储新的头节点
	STU* houpre = stu;//后面一个目标节点的前驱节点。
	STU* hou = stu->next;//后面的目标节点。
	STU* headpre; headpre = (STU*)malloc(sizeof(STU)); headpre->next = stu; STU* freehead = headpre;
	//创建新指针和结构体，其next值指向头节点，充当头节点的前驱指针，同时充当前面一个目标节点的前驱节点。
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (hou->sum > stu->sum)
			{
				ChangeOrder(headpre, stu, houpre, hou); flag = 1;
			}
			houpre = hou; hou = hou->next;
		}
		if (flag == 1 && i == 0)
		{
			newhead = headpre->next;
		}
		headpre = stu; stu = stu->next;
	}
	printf("按总分从大到小对学生记录排序完毕");
	free(freehead);
	return newhead;
}
void StatisticAnalysis(int n, int m, STU* stu)
{
	int i, j, t[6];STU* head=stu;
	for (j = 0; j < m; j++)
	{
		printf("\n课程%d 成绩统计结果为：\n", j + 1);
		printf("分数段\t人数\t占比\n");
		memset(t, 0, sizeof(t));
		for (i = 0; i < n; i++)
		{
			if (stu->score[j] >= 0 && stu->score[j] < 60)
				t[0]++;
			else if (stu->score[j] < 70)
				t[1]++;
			else if (stu->score[j] < 80)
				t[2]++;
			else if (stu->score[j] < 90)
				t[3]++;
			else if (stu->score[j] < 100)
				t[4]++;
			else if (stu->score[j] == 100)
				t[5]++;
			stu = stu->next;
		}
		for (i = 0; i < 6; i++)
		{
			if (i == 0)
				printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
			else if (i == 5)
				printf("100\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
			else
				printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / n * 100);
		}
	}
	printf("\n学生成绩平均分统计结果为：\n");
	printf("分数段\t人数\t占比\n");
	memset(t, 0, sizeof(t));
	stu = head;
	for (i = 0; i < n; i++)
	{
		if (stu->aver >= 0 && stu->aver < 60)
			t[0]++;
		else if (stu->aver < 70)
			t[1]++;
		else if (stu->aver < 80)
			t[2]++;
		else if (stu->aver < 90)
			t[3]++;
		else if (stu->aver < 100)
			t[4]++;
		else if (stu->aver == 100)
			t[5]++;
		stu = stu->next;
	}
	for (i = 0; i < 6; i++)
	{
		if (i == 0)
			printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
		else if (i == 5)
			printf("100\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
		else
			printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / n * 100);
	}
}