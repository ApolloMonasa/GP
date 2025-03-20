#include"Stu.h"
int MenuStu(void)
{
	int posy = 5;
	int option; // 保存用户输入的操作代号的变量
	int i, j;
	SetPosition(POS_X3, posy);
	printf("学生成绩管理系统学生界面\n"); // 输出系统名字
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
	printf("1. 按学号查找记录(输入数字4)");
	SetPosition(POS_X4, posy);
	printf("2. 按姓名查找记录(输入数字5)");
	SetPosition(POS_X1, posy += 2);
	printf("3. 按学号排序(输入数字9)");
	SetPosition(POS_X4, posy);
	printf("4. 按姓名排序(输入数字10)");
	SetPosition(POS_X1, posy += 2);
	printf("5. 按总成绩降序排序(输入数字11)");
	SetPosition(POS_X4, posy);
	printf("6. 按总成绩升序排序(输入数字12)");
	SetPosition(POS_X1, ++posy);
	printf("7. 打印学生记录(输入数字14)");
	SetPosition(POS_X4, posy);
	printf("8. 从磁盘读取学生记录(输入数字16)");
	SetPosition(POS_X1, posy += 2);
	printf("9. 模糊查询(输入数字17)");
	SetPosition(POS_X4, posy);
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
	printf("请选择你想要进行的操作[0~17]：");
	scanf("%d", &option);
	return option;
}
int MenuTea(void)
{
	int posy = 5;
	int option; // 保存用户输入的操作代号的变量
	int i, j;
	SetPosition(POS_X3, posy);
	printf("学生成绩管理系统教师系统\n"); // 输出系统名字
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
	printf("17. 模糊查询");
	SetPosition(POS_X4, posy);
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
	printf("请选择你想要进行的操作[0~17]：");
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
void ChangeOrder(STU* p1, STU* p2, STU* q1, STU* q2) {
	// 处理相邻节点的情况（p2的下一个节点是q2）
	if (p2->next == q2) {
		p1->next = q2;
		p2->next = q2->next;
		q2->next = p2;
	}
	else {
		// 处理非相邻节点
		p1->next = q2;
		STU* temp = q2->next;
		q2->next = p2->next;

		q1->next = p2;
		p2->next = temp;
	}
}
void InputRecord(int* n, int* m, STU** head) {
	// 清空原有链表
	while (*head != NULL) {
		STU* tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;

	// 输入学生人数和课程数
	printf("输入学生人数(n<%d):", STU_NUM);
	scanf("%d", n);
	printf("输入课程门数(m<%d):", COURSE_NUM);
	scanf("%d", m);

	// 动态构建链表
	STU* tail = NULL;
	for (int i = 0; i < *n; i++) {
		STU* newNode = CreateNode();
		printf("输入第%d个学生信息(学号 姓名 成绩1 成绩2 ...):\t", i + 1);
		scanf("%ld %s", &newNode->num, newNode->name);
		for (int j = 0; j < *m; j++) {
			scanf("%f", &newNode->score[j]);
		}

		// 链接到链表
		if (*head == NULL) {
			*head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	// 计算总分和平均分
	CalculateScoreOfStudent(*n, *m, *head);
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
void WriteToFileBinary(int n, STU* stu)
{
	int i;
	FILE* fp;
	// 打开文件，指定对文件的处理方式为写入，并让指针指向文件
	if ((fp = fopen("data.dat", "wb")) == NULL)
	{
		printf("文件 data.dat 无法正常打开！");
		exit(0);
	}
	for (i = 0; i < n; i++)
	{
		fwrite(stu, sizeof(STU), 1, fp);
		stu = stu->next;
	}
	// 关闭文件
	fclose(fp);
	// 提示用户存盘操作完毕
	printf("存盘完毕！\n");
}
int ReadfromFileBinary(int* pn, STU* stu, int* first)
{
	// 定义文件指针
	FILE* fp;
	int i;
	int posy = 8;
	SetPosition(POS_X1, posy);
	// 打开文件，指定对文件的处理方式为读操作，并让指针指向文件
	if ((fp = fopen("data.dat", "rb")) == NULL)
	{
		printf("磁盘文件 data.dat 无法打开");
		return 1;
	}
	long offset = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	while (fread(stu, sizeof(STU), 1, fp) == 1)
	{
		(*pn) += 1;
		stu->next = (STU*)malloc(sizeof(STU));
		stu = stu->next;
	}
	*first = 0; // 修改标志变量
	// 关闭文件
	fclose(fp);
	printf("数据从磁盘读取完毕!");
	return 0;
}
void AppendRecord(int* n, int m, STU* stu)
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
		printf("输入第%d个学生信息(学号+姓名+%d门成绩)：\t", i + 1, m);
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
STU* CreateNode() {
	STU* node = (STU*)malloc(sizeof(STU));
	if (node == NULL) {
		printf("内存分配失败!\n");
		exit(EXIT_FAILURE);
	}
	memset(node->name, 0, NAME_LEN);   // 清空姓名字段
	node->num = 0;                     // 初始化学号
	node->sum = 0.0f;                  // 初始化总分
	node->aver = 0.0f;                 // 初始化平均分
	node->next = NULL;                 // 初始化指针
	return node;
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
	STU* pre = stu;//前驱节点
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
		pre = stu; stu = stu->next;
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
	while (stu)
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
// 交换相邻节点的简化实现（冒泡排序）
STU* SortbyName(int n, int m, STU* head) {
	if (head == NULL || head->next == NULL) return head;

	STU* dummy = (STU*)malloc(sizeof(STU));
	dummy->next = head;
	int swapped;

	for (int i = 0; i < n; i++) {
		swapped = 0;
		STU* prev = dummy, * curr = prev->next, * nextNode = curr->next;

		while (nextNode != NULL) {
			if (strcmp(curr->name, nextNode->name) > 0) {
				// 交换curr和nextNode
				prev->next = nextNode;
				curr->next = nextNode->next;
				nextNode->next = curr;
				swapped = 1;
				prev = nextNode;  // 更新prev
				nextNode = curr->next;
			}
			else {
				prev = curr;
				curr = nextNode;
				nextNode = nextNode->next;
			}
		}
		if (!swapped) break;
	}

	STU* newHead = dummy->next;
	free(dummy);
	printf("按姓名字典排序完毕\n");
	return newHead;
}

// 具体排序函数
STU* SortbyNum(int n, int m, STU* stu) {
	STU* result = SortByXXX(n, m, stu, CompareByNumAsc);
	printf("按学号排序完毕\n");
	return result;
}

STU* SortbyScoreA(int n, int m, STU* stu) {
	STU* result = SortByXXX(n, m, stu, CompareBySumAsc);
	printf("按总分升序排序完毕\n");
	return result;
}

STU* SortbyScoreB(int n, int m, STU* stu) {
	STU* result = SortByXXX(n, m, stu, CompareBySumDesc);
	printf("按总分降序排序完毕\n");
	return result;
}
void StatisticAnalysis(int n, int m, STU* stu)
{
	int i, j, t[6]; STU* head = stu;
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
STU* SortByXXX(int n, int m, STU* head, int (*compare)(STU*, STU*)) {
	if (head == NULL || head->next == NULL) return head;

	STU* dummy = (STU*)malloc(sizeof(STU));
	dummy->next = head;
	int swapped;

	for (int i = 0; i < n; i++) {
		swapped = 0;
		STU* prev = dummy, * curr = prev->next, * nextNode = curr->next;

		while (nextNode != NULL) {
			if (compare(curr, nextNode)) { // 根据比较条件决定是否交换
				// 交换相邻节点
				prev->next = nextNode;
				curr->next = nextNode->next;
				nextNode->next = curr;
				swapped = 1;
				prev = nextNode;  // 更新prev
				nextNode = curr->next;
			}
			else {
				prev = curr;
				curr = nextNode;
				nextNode = nextNode->next;
			}
		}
		if (!swapped) break;
	}

	STU* newHead = dummy->next;
	free(dummy);
	return newHead;
}
void FuzzyQuery(int n, int m, STU* head)
{
	printf("请输入要查询的学号前缀：");
	long id;
	scanf("%ld", &id);
	STU* p = head;
	while (p) {
		long num = p->num;
		while (num > id) num /= 10;
		if (id == num) {
			PrintRecord(1, m, p);
		}
		p = p->next;
	}
	return;
}
int CompareByNumAsc(STU* a, STU* b) { return a->num > b->num; }
int CompareBySumAsc(STU* a, STU* b) { return a->sum > b->sum; }
int CompareBySumDesc(STU* a, STU* b) { return a->sum < b->sum; }