#include "snake.h"

//�����Ϸ�Ĳ����߼�
void test() {
	int ch = 0;
	do
	{
	system("cls");
	//����̰����
	Snake snake = { 0 };
	//��ʼ����Ϸ
	GameStart(&snake);
	//������Ϸ
	GameRun(&snake);
	//������Ϸ���ƺ�����
	GameEnd(&snake);
	//ѯ���Ƿ�����һ��
	SetPos(LENTH, LENTH / 2 + 1);
	wprintf(L"����һ�֣�[Y/N]:");
	while((ch = getchar()) == ' ');
	while(getchar() != '\n');//����س�
	} while (ch == 'Y' || ch == 'y');
}

int main() {
	//�����������
	srand((unsigned int)time(0));
	//���䱾�ػ�
	setlocale(LC_ALL, "");
	test();
	SetPos(LENTH * 2, LENTH);
	return 0;
}