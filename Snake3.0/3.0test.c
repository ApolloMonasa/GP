/*************************************************************************
	> File Name: 3.0test.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 26 Feb 2025 05:01:49 PM CST
 ************************************************************************/
#include "3.0snake.h"

//完成游戏的测试逻辑
void test() {
	int ch = 0;
	do
	{
	system("cls");
	//创建贪吃蛇
	Snake snake = { 0 };
	//初始化游戏
	GameStart(&snake);
	//运行游戏
	GameRun(&snake);
	//结束游戏（善后工作）
	GameEnd(&snake);
	//询问是否再来一局
	SetPos(LENTH, LENTH / 2 + 1);
	wprintf(L"再来一局？[Y/N]:");
	while((ch = getchar()) == ' ');
	while(getchar() != '\n');//清理回车
	} while (ch == 'Y' || ch == 'y');
}

int main() {
	//设置随机种子
	srand((unsigned int)time(0));
	//适配本地化
	setlocale(LC_ALL, "");
	test();
	SetPos(LENTH * 2, LENTH);
	return 0;
}
