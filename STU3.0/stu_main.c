#include"Stu.h"
int MenuStu(void)
{
	int posy = 5;
	int option; // �����û�����Ĳ������ŵı���
	int i, j;
	SetPosition(POS_X3, posy);
	printf("ѧ���ɼ�����ϵͳѧ������\n"); // ���ϵͳ����
	// ���ϵͳ���ֺ͹���˵��֮������ж̺���
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	// ���ϵͳ֧�ֵĹ��ܺͶ�Ӧ�Ĺ��ܴ���
	SetPosition(POS_X1, ++posy);
	printf("1. ��ѧ�Ų��Ҽ�¼(��������4)");
	SetPosition(POS_X4, posy);
	printf("2. ���������Ҽ�¼(��������5)");
	SetPosition(POS_X1, posy += 2);
	printf("3. ��ѧ������(��������9)");
	SetPosition(POS_X4, posy);
	printf("4. ����������(��������10)");
	SetPosition(POS_X1, posy += 2);
	printf("5. ���ܳɼ���������(��������11)");
	SetPosition(POS_X4, posy);
	printf("6. ���ܳɼ���������(��������12)");
	SetPosition(POS_X1, ++posy);
	printf("7. ��ӡѧ����¼(��������14)");
	SetPosition(POS_X4, posy);
	printf("8. �Ӵ��̶�ȡѧ����¼(��������16)");
	SetPosition(POS_X1, posy += 2);
	printf("9. ģ����ѯ(��������17)");
	SetPosition(POS_X4, posy);
	printf("0. �˳�");
	// ���ϵͳ֧�ֵĹ�����������ʾ��֮������ж̺���
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	// ��ʾ�û�������Ҫִ�еĹ��ܴ���
	SetPosition(POS_X1, ++posy);
	printf("��ѡ������Ҫ���еĲ���[0~17]��");
	scanf("%d", &option);
	return option;
}
int MenuTea(void)
{
	int posy = 5;
	int option; // �����û�����Ĳ������ŵı���
	int i, j;
	SetPosition(POS_X3, posy);
	printf("ѧ���ɼ�����ϵͳ��ʦϵͳ\n"); // ���ϵͳ����
	// ���ϵͳ���ֺ͹���˵��֮������ж̺���
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	// ���ϵͳ֧�ֵĹ��ܺͶ�Ӧ�Ĺ��ܴ���
	SetPosition(POS_X1, ++posy);
	printf("1. ����ѧ����Ϣ");
	SetPosition(POS_X4, posy);
	printf("2. ����ѧ���ɼ�");
	SetPosition(POS_X1, posy += 2);
	printf("3. ɾ��ѧ����Ϣ");
	SetPosition(POS_X4, posy);
	printf("4. ��ѧ�Ų��Ҽ�¼");
	SetPosition(POS_X1, posy += 2);
	printf("5. ���������Ҽ�¼");
	SetPosition(POS_X4, posy);
	printf("6. �޸�ѧ����Ϣ");
	SetPosition(POS_X1, ++posy);
	printf("7. ����ѧ���ɼ�");
	SetPosition(POS_X4, posy);
	printf("8. ����γ̳ɼ�");
	SetPosition(POS_X1, posy += 2);
	printf("9. ��ѧ������");
	SetPosition(POS_X4, posy);
	printf("10. ����������");
	SetPosition(POS_X1, posy += 2);
	printf("11. ���ܳɼ���������");
	SetPosition(POS_X4, posy);
	printf("12. ���ܳɼ���������");
	SetPosition(POS_X1, posy += 2);
	printf("13. ѧ���ɼ�ͳ��");
	SetPosition(POS_X4, posy);
	printf("14. ��ӡѧ����¼");
	SetPosition(POS_X1, posy += 2);
	printf("15. ѧ����¼����");
	SetPosition(POS_X4, posy);
	printf("16. �Ӵ��̶�ȡѧ����¼");
	SetPosition(POS_X1, posy += 2);
	printf("17. ģ����ѯ");
	SetPosition(POS_X4, posy);
	printf("0. �˳�");
	// ���ϵͳ֧�ֵĹ�����������ʾ��֮������ж̺���
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	// ��ʾ�û�������Ҫִ�еĹ��ܴ���
	SetPosition(POS_X1, ++posy);
	printf("��ѡ������Ҫ���еĲ���[0~17]��");
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
	// �������ڽڵ�������p2����һ���ڵ���q2��
	if (p2->next == q2) {
		p1->next = q2;
		p2->next = q2->next;
		q2->next = p2;
	}
	else {
		// ��������ڽڵ�
		p1->next = q2;
		STU* temp = q2->next;
		q2->next = p2->next;

		q1->next = p2;
		p2->next = temp;
	}
}
void InputRecord(int* n, int* m, STU** head) {
	// ���ԭ������
	while (*head != NULL) {
		STU* tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;

	// ����ѧ�������Ϳγ���
	printf("����ѧ������(n<%d):", STU_NUM);
	scanf("%d", n);
	printf("����γ�����(m<%d):", COURSE_NUM);
	scanf("%d", m);

	// ��̬��������
	STU* tail = NULL;
	for (int i = 0; i < *n; i++) {
		STU* newNode = CreateNode();
		printf("�����%d��ѧ����Ϣ(ѧ�� ���� �ɼ�1 �ɼ�2 ...):\t", i + 1);
		scanf("%ld %s", &newNode->num, newNode->name);
		for (int j = 0; j < *m; j++) {
			scanf("%f", &newNode->score[j]);
		}

		// ���ӵ�����
		if (*head == NULL) {
			*head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	// �����ֺܷ�ƽ����
	CalculateScoreOfStudent(*n, *m, *head);
}
void CalculateScoreOfStudent(int n, int m, STU* stu)
{
	int i, j;
	printf("ÿ��ѧ�����ſγ̵��ֺܷ�ƽ����Ϊ��\n");
	for (i = 0; i < n; i++)
	{
		stu->sum = 0;
		for (j = 0; j < m; j++)
		{
			stu->sum += stu->score[j];
		}
		stu->aver = stu->sum / m;
		printf("��%d��ѧ�����ܷ�=%.2f��ƽ����=%.2f\n", i + 1, stu->sum, stu->aver);
		stu = stu->next;
	}
}
void CalculateScoreOfCourse(int n, int m, STU* stu)
{
	int i, j;
	float sum[COURSE_NUM], aver[COURSE_NUM];
	int posy = 7;
	SetPosition(POS_X1, posy);
	printf("���ſγ̵��ֺܷ�ƽ���ֵļ�����Ϊ��");
	for (j = 0; j < m; j++)
	{
		sum[j] = 0;
		for (i = 0; i < n; i++)
		{
			sum[j] += stu->score[j]; stu = stu->next;
		}
		aver[j] = sum[j] / n;
		SetPosition(POS_X1, ++posy);
		printf("��%d �ſγ̣��ܷ� = %.2f��ƽ���� = %.2f\n", j + 1, sum[j], aver[j]);
	}
}
void WriteToFileBinary(int n, STU* stu)
{
	int i;
	FILE* fp;
	// ���ļ���ָ�����ļ��Ĵ���ʽΪд�룬����ָ��ָ���ļ�
	if ((fp = fopen("data.dat", "wb")) == NULL)
	{
		printf("�ļ� data.dat �޷������򿪣�");
		exit(0);
	}
	for (i = 0; i < n; i++)
	{
		fwrite(stu, sizeof(STU), 1, fp);
		stu = stu->next;
	}
	// �ر��ļ�
	fclose(fp);
	// ��ʾ�û����̲������
	printf("������ϣ�\n");
}
int ReadfromFileBinary(int* pn, STU* stu, int* first)
{
	// �����ļ�ָ��
	FILE* fp;
	int i;
	int posy = 8;
	SetPosition(POS_X1, posy);
	// ���ļ���ָ�����ļ��Ĵ���ʽΪ������������ָ��ָ���ļ�
	if ((fp = fopen("data.dat", "rb")) == NULL)
	{
		printf("�����ļ� data.dat �޷���");
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
	*first = 0; // �޸ı�־����
	// �ر��ļ�
	fclose(fp);
	printf("���ݴӴ��̶�ȡ���!");
	return 0;
}
void AppendRecord(int* n, int m, STU* stu)
{
	int i, j;
	int num_record;
	printf("��������Ҫ���ӵ�ѧ����¼������");
	scanf("%d", &num_record);
	while (*n + num_record > STU_NUM) // �ж�������¼��ԭ�м�¼֮���Ƿ�С���趨����
	{
		printf("Ҫ���ӵļ�¼����̫�࣬���������룺");
		scanf("%d", &num_record);
	}
	for (i = 0; i < *n; i++)
	{
		stu = stu->next;
	}
	for (i = *n; i < *n + num_record; i++)
	{
		printf("�����%d��ѧ����Ϣ(ѧ��+����+%d�ųɼ�)��\t", i + 1, m);
		scanf("%ld%s", &stu->num, stu->name);
		for (j = 0; j < m; j++)
		{
			scanf("%f", &stu->score[j]);
		}
		stu = stu->next;
	}
	*n = *n + num_record;
	printf("�����ϣ�\n");
	return;
}
//��������
STU* CreateNode() {
	STU* node = (STU*)malloc(sizeof(STU));
	if (node == NULL) {
		printf("�ڴ����ʧ��!\n");
		exit(EXIT_FAILURE);
	}
	memset(node->name, 0, NAME_LEN);   // ��������ֶ�
	node->num = 0;                     // ��ʼ��ѧ��
	node->sum = 0.0f;                  // ��ʼ���ܷ�
	node->aver = 0.0f;                 // ��ʼ��ƽ����
	node->next = NULL;                 // ��ʼ��ָ��
	return node;
}
void SearchbyNum(int n, int m, STU* stu)
{
	long id;
	int i, j;
	printf("��������Ҫ���ҵ�ѧ����ѧ�ţ�");
	scanf("%ld", &id);
	for (i = 0; i < n; i++)
	{
		if (stu->num == id)
		{
			printf("�ҵ��ˣ���ѧ�Ŷ�Ӧ��ѧ����ϢΪ��\n");
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
	printf("δ�ҵ����ѧ�Ŷ�Ӧ��ѧ����¼\n");
	return;
}
void SearchbyName(int n, int m, STU* stu)
{
	int flag = 1;
	int i, j;
	int k = 0;
	char name[NAME_LEN];
	printf("��������Ҫ���ҵ�ѧ����������");
	scanf("%s", name);
	for (i = 0; i < n; i++)
	{
		if (strcmp(stu->name, name) == 0)
		{
			printf("�ҵ��ˣ���%d ��ѧ����ϢΪ��\n", ++k);
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
		printf("δ�ҵ����������Ӧ��ѧ����¼\n");
	}
	return;
}
int DeleteRecord(int* n, int m, STU* stu)
{
	int i, j;
	long id;
	char ch;
	STU* pre = stu;//ǰ���ڵ�
	printf("��������Ҫɾ��ѧ����Ϣ��Ӧ��ѧ�ţ�");
	scanf("%ld", &id);
	for (i = 0; i < *n; i++)
	{
		if (stu->num == id)
		{
			printf("�ҵ��˸�����¼����ϢΪ��\n");
			printf("%10ld%15s", stu->num, stu->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", stu->score[j]);
			}
			printf("%10.2f%10.2f\n", stu->sum, stu->aver);
			printf("��ȷ���Ƿ���Ҫɾ��������¼��(Y/y��N/n)��");
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
				printf("�ҵ��˸�ѧ����¼������ɾ��\n");
				return 0;
			}
			else
			{
				printf("�������\n");
				return 0;
			}
		}
		pre = stu; stu = stu->next;
	}
	printf("δ�ҵ�������¼��\n");
	return;
}
void ModifyRecord(int n, int m, STU* stu)
{
	int i, j;
	long id;
	char ch;
	printf("��������Ҫ�޸���Ϣ��Ӧ��ѧ�ţ�");
	scanf("%ld", &id);
	for (i = 0; i < n; i++)
	{
		if (stu->num == id)
		{
			printf("�ҵ��˸�����¼����ϢΪ��\n");
			printf("%10ld%15s", stu->num, stu->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", stu->score[j]);
			}
			printf("%10.2f%10.2f\n", stu->sum, stu->aver);
			printf("��ȷ���Ƿ���Ҫ�޸ģ�(Y/N �� y/n)��");
			getchar();
			scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y')
			{
				printf("������Ҫ�޸ĵ�ѧ����Ϣ����ѧ��+����+�ɼ���");
				scanf("%ld%s", &stu->num, stu->name);
				stu->sum = 0;
				for (j = 0; j < m; j++)
				{
					scanf("%f", &stu->score[j]);
					stu->sum += stu->score[j];
				}
				stu->aver = stu->sum / m;
				printf("�޸����\n");
				return;
			}
			else if (ch == 'N' || ch == 'n')
			{
				printf("�ҵ��˸�����¼�������޸�\n");
				return;
			}
			else
			{
				printf("�������\n");
				return;
			}
		}
		stu = stu->next;
	}
	printf("δ�ҵ�������¼��\n");
	return;
}
void PrintRecord(int n, int m, STU* stu)
{
	int i, j;
	printf("ѧ��\t\t����\t\t");
	for (j = 0; j < m; j++)
	{
		printf("�γ�%d\t\t", j + 1);
	}
	printf("�ܷ�\t\tƽ����\n");
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
// �������ڽڵ�ļ�ʵ�֣�ð������
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
				// ����curr��nextNode
				prev->next = nextNode;
				curr->next = nextNode->next;
				nextNode->next = curr;
				swapped = 1;
				prev = nextNode;  // ����prev
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
	printf("�������ֵ��������\n");
	return newHead;
}

// ����������
STU* SortbyNum(int n, int m, STU* stu) {
	STU* result = SortByXXX(n, m, stu, CompareByNumAsc);
	printf("��ѧ���������\n");
	return result;
}

STU* SortbyScoreA(int n, int m, STU* stu) {
	STU* result = SortByXXX(n, m, stu, CompareBySumAsc);
	printf("���ܷ������������\n");
	return result;
}

STU* SortbyScoreB(int n, int m, STU* stu) {
	STU* result = SortByXXX(n, m, stu, CompareBySumDesc);
	printf("���ֽܷ����������\n");
	return result;
}
void StatisticAnalysis(int n, int m, STU* stu)
{
	int i, j, t[6]; STU* head = stu;
	for (j = 0; j < m; j++)
	{
		printf("\n�γ�%d �ɼ�ͳ�ƽ��Ϊ��\n", j + 1);
		printf("������\t����\tռ��\n");
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
	printf("\nѧ���ɼ�ƽ����ͳ�ƽ��Ϊ��\n");
	printf("������\t����\tռ��\n");
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
			if (compare(curr, nextNode)) { // ���ݱȽ����������Ƿ񽻻�
				// �������ڽڵ�
				prev->next = nextNode;
				curr->next = nextNode->next;
				nextNode->next = curr;
				swapped = 1;
				prev = nextNode;  // ����prev
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
	printf("������Ҫ��ѯ��ѧ��ǰ׺��");
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