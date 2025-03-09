#include "snake.h"

void SetPos(short x, short y) {
	//获得标准输出设备的句柄
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//定位光标的位置
	COORD pos = { x, y };
	SetConsoleCursorPosition(houtput, pos);
	return;
}
void WelcomeToGame() {
	SetPos(50, 14);
	wprintf(L"欢迎来到贪吃蛇小游戏\n");
	SetPos(52, 20);
	system("pause");
	system("cls");
	SetPos(50, 14);
	wprintf(L"用↑、↓、←、→ 来控制蛇的移动，按F3加速，F4减速");
	SetPos(50, 15);
	wprintf(L"加速可以得到更高的分数");
	SetPos(50, 20);
	system("pause");
	system("cls");
}

void CreateMap() {
	//上
	for (int i = 0; i < LENTH + 2; i++) { 
		wprintf(L"%lc", WALL);
	}
	//下
	SetPos(0, LENTH - 1);
	for (int i = 0; i < LENTH + 2; i++) {
		wprintf(L"%lc", WALL);
	}
	//左
	for (int i = 1; i <= LENTH - 2; i++) {
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	//右
	for (int i = 1; i <= LENTH - 2; i++) {
		SetPos(LENTH * 2 + 2, i);
		wprintf(L"%lc", WALL);
	}
	return;
}

void printSnake(pSnakeNode cur) {
	SetPos(cur->x, cur->y);
	wprintf(L"%lc", HEAD);
	cur = cur->next;
	while (cur) {
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
}

void InitSnake(pSnake ps) {
	pSnakeNode cur = NULL;

	for (int i = 0; i < INIT_LEN; i++) {
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (!cur) {
			perror("InitSnake()::malloc()\n");
			return;
		}
		cur->next = NULL;
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;
		//头插法
		if (!ps->_pSnake) {
			ps->_pSnake = cur;
		}
		else {
			cur->next = ps->_pSnake;
			ps->_pSnake = cur;
		}
	}
	//print
	cur = ps->_pSnake;
	printSnake(cur);
	//设置蛇的属性
	ps->_dir = RIGHT;//默认向右
	ps->_score = 0;
	ps->_sleep_time = 180;//ms
	ps->_status = OK;
	//设置障碍物
	for (int i = 0; i < 10; i++) {
		int k = rand() % (LENTH * 2 - 1) + 2;
		ps->Obstacle[i][0] = k % 2 == 0 ? k:k+1;
		ps->Obstacle[i][1] = rand() % (LENTH - 2) + 1;
		SetPos(ps->Obstacle[i][0], ps->Obstacle[i][1]);
		wprintf(L"%lc", WALL);
	}
}

void CreateFood(pSnake ps) {
	int x = 0, y = 0, ind = 0;
	//生成x是偶数且，点在地图内
again:
	do {
		int k= rand() % (LENTH * 2 - 1) ;
		x = k % 2 == 0 ? k : k + 1;
		y = rand() % (LENTH - 2) + 1;
	} while (x % 2);
	//不能与蛇身重合
	pSnakeNode cur = ps->_pSnake;
	while (cur) {
		if (x == cur->x && y == cur->y) {
			goto again;
		}
		cur = cur->next;
	}
	//不能与障碍物重合
	for (; ind < NUM_OF_OBSTACLE;) {
		if (x == ps->Obstacle[ind][0] && y == ps->Obstacle[ind][1]) {
			goto again;
		}
		ind++;
	}
	//创建食物的节点
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (!pFood) {
		perror("CreateFood()::malloc()");
		return;
	}
	ps->_pFood = pFood;
	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;
	//print
	SetPos(x, y);
	// 获取当前控制台属性（包括背景色）
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(out, &csbi); // 初始化csbi
	switch (rand() % 4) {
		case 0: { 
			ps->_food_weight = 12;
			break;
		}
		case 1: { 
			ps->_food_weight = 22;
			// 设置文本颜色为蓝色
			SetConsoleTextAttribute(out, FOREGROUND_BLUE | FOREGROUND_INTENSITY | (csbi.wAttributes & 0xF0));
			break;
		}
		case 2: { 
			ps->_food_weight = 32;
			// 设置文本颜色为红色
			SetConsoleTextAttribute(out, FOREGROUND_RED | FOREGROUND_INTENSITY | (csbi.wAttributes & 0xF0));
			break;
		}
		case 3: { 
			ps->_food_weight = 42;
			// 设置文本颜色为紫色
			SetConsoleTextAttribute(out, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY | (csbi.wAttributes & 0xF0));
			break;
		}
	}
	wprintf(L"%lc", FOOD);
	// 恢复默认颜色（可选）
	SetConsoleTextAttribute(out, csbi.wAttributes);
}

void GameStart(pSnake ps) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	//0.设置窗口，光标隐藏
	system("mode con cols=120 lines=40");//设置窗口大小 
	system("title 贪吃蛇");//设置窗口标题
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(out, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false;//隐藏控制台光标
	SetConsoleCursorInfo(out, &CursorInfo);//设置控制台光标状态
	//1.打印欢迎界面和功能介绍
	WelcomeToGame();
	//2.绘制地图
	CreateMap();
	//3.初始化蛇
	InitSnake(ps);
	//4.创建食物
	CreateFood(ps);
	return;
}

void PrintHelpInfo() {
	//RankingBoard
	// 获取当前控制台属性（包括背景色）
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(out, &csbi);
	SetConsoleTextAttribute(out, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY | (csbi.wAttributes & 0xF0));
	SetPos(LENTH * 2 + 10, 5);
	printf("RankingBoard");
	SetPos(LENTH * 2 + 10, 6);
	print_line("data.txt", 1);
	SetPos(LENTH * 2 + 10, 7);
	print_line("data.txt", 2);
	SetPos(LENTH * 2 + 10, 8);
	print_line("data.txt", 3); 
	// 恢复默认颜色（可选）
	SetConsoleTextAttribute(out, csbi.wAttributes);


	SetPos(LENTH * 2 + 10, 20);
	wprintf(L"%ls", L"不能穿墙，不能咬到自己");
	SetPos(LENTH * 2 + 10, 21);
	wprintf(L"%ls", L"用↑、↓、←、→ 来控制蛇的移动");
	SetPos(LENTH * 2 + 10, 22);
	wprintf(L"%ls", L"按F3加速，F4减速");
	SetPos(LENTH * 2 + 10, 23);
	wprintf(L"%ls", L"按ESC退出游戏，按空格暂停游戏");
	// 设置文本颜色为红色
	GetConsoleScreenBufferInfo(out, &csbi);
	SetConsoleTextAttribute(out, FOREGROUND_RED | FOREGROUND_INTENSITY |(csbi.wAttributes &0xF0));

	SetPos(LENTH * 2 + 10, 25);
	wprintf(L"%ls", L"   Author:HDU.Apollo");
	SetPos(LENTH * 2 + 10, 26);
	wprintf(L"%ls", L"Email:xyl6716@outlook.com");

	// 恢复默认颜色（可选）
	SetConsoleTextAttribute(out, csbi.wAttributes);
}

void Pause() {
	while (1) {
		Sleep(200);
		if (KEY_PRESS(VK_SPACE)) break;
	}
}

int IsNextFood(pSnakeNode pn, pSnake ps) {
	return (ps->_pFood->x == pn->x && ps->_pFood->y == pn->y);
}

int growth = 0; //记录应该增长的长度

void EatFood(pSnakeNode pn, pSnake ps) {
	//头插法把食物节点挂上去
	ps->_pFood->next = ps->_pSnake;
	ps->_pSnake = ps->_pFood;
	//释放下一个位置的节点
	free(pn);
	pn = NULL;
	//打印
	pSnakeNode cur = ps->_pSnake;
	printSnake(cur);
	//记录长度
	growth += (ps->_food_weight / 10);
	ps->_score += ps->_food_weight;
	//重新创建食物
	CreateFood(ps);
}

void NoFood(pSnakeNode pn, pSnake ps) {
	//头插法
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;
	pSnakeNode cur = pn;
	SetPos(cur->x, cur->y);
	wprintf(L"%lc", HEAD);
	//如果不需要增长，尾删法
	//如果需要增长，不删
	if(growth == 0) {
		cur = cur->next;
		while (cur->next->next) {
			SetPos(cur->x, cur->y);
			wprintf(L"%lc", BODY);
			cur = cur->next;
		}
		SetPos(cur->next->x, cur->next->y);
		printf("  ");
		free(cur->next);
		cur->next = NULL;
	}
	else {
		growth--;
	}
}


void KillByWall(pSnake ps) {
	if (ps->_pSnake->x == 0) {
		ps->_pSnake->x = 2 * LENTH + 1; SetPos(0, ps->_pSnake->y);wprintf(L"%lc", WALL);
	}
	else if (ps->_pSnake->x == 2 * LENTH + 2) { ps->_pSnake->x = 1; SetPos(2 * LENTH + 2, ps->_pSnake->y); wprintf(L"%lc", WALL);
	}
	else if (ps->_pSnake->y == 0) { ps->_pSnake->y = LENTH - 2; SetPos(ps->_pSnake->x, 0); wprintf(L"%lc", WALL);
	}
	else if (ps->_pSnake->y == LENTH - 1) {ps->_pSnake->y = 1; SetPos(ps->_pSnake->x, LENTH - 1); wprintf(L"%lc", WALL);
	}
}

void KillByObstacle(pSnake ps) {
	for (int i = 0; i < NUM_OF_OBSTACLE; i++) {
		if (ps->_pSnake->x == ps->Obstacle[i][0] && ps->_pSnake->y == ps->Obstacle[i][1]) {
			ps->_status = KILL_BY_OBSTACLE;
		}
	}
}

void KillBySelf(pSnake ps) {
	pSnakeNode cur = ps->_pSnake->next;
	while (cur) {
		if (cur->x == ps->_pSnake->x && cur->y == ps->_pSnake->y) {
			//ps->_status = KILL_BY_SELF;
			//增添咬断蛇身的效果
			pSnakeNode tmp = cur->next;
			cur->next = NULL;
			cur = tmp;
			while (cur) {
				SetPos(cur->x, cur->y);
				printf("  ");
				pSnakeNode Get = cur->next;
				free(cur);
				cur = Get;
			}
			return;
		}
		cur = cur->next;
	}
}
int nofood_cnt = 0;//用来记录蛇吃不到食物的次数
int SnakeMove(pSnake ps,int count) {
	//创建一个节点，表示蛇即将到的下一个节点
	pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode)); int flag = 0;
	if (!pNextNode) {
		perror("SnakeMove()::malloc()");
		return;
	}
	switch (ps->_dir) {
	case UP: {
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y - 1;
		break;
	}
	case DOWN: {
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y + 1;
		break;
	}
	case LEFT: {
		pNextNode->x = ps->_pSnake->x - 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	}
	case RIGHT: {
		pNextNode->x = ps->_pSnake->x + 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	}
	}	//检查下一个位置是不是食物或墙
	if (pNextNode->x == 0) { flag = 1; pNextNode->x = 2 * LENTH; }
	else if (pNextNode->x == 2 * LENTH + 2) { flag = 1; pNextNode->x = 2; }
	else if (pNextNode->y == 0) { flag = 1; pNextNode->y = LENTH - 2; }
	else if (pNextNode->y == LENTH - 1) { flag = 1; pNextNode->y = 1; }
	if (IsNextFood(pNextNode, ps)) {
		EatFood(pNextNode, ps);
		nofood_cnt = 0;
	}
	else {
		if (flag) { NoFood(pNextNode, ps); }
		else {
			NoFood(pNextNode, ps);
			nofood_cnt++;
		}
	}
	//检查是否咬到自己
	KillBySelf(ps);
	//检查是否撞到障碍物
	KillByObstacle(ps);
	//检查吃不到食物的次数
	if (nofood_cnt > 100) {
		nofood_cnt = 0;
		//覆盖原食物
		SetPos(ps->_pFood->x, ps->_pFood->y);
		wprintf(L"%lc", WALL);
		ps->Obstacle[count][0] = ps->_pFood->x;
		ps->Obstacle[count][1] = ps->_pFood->y;
		//重新创建食物
		CreateFood(ps);
		return 1;
	}

}

void GameRun(pSnake ps) {
	int count = 10;
	//打印帮助信息
	PrintHelpInfo();
	//扫描按键并操作
	do {
		//打印总分和食物分值
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(out, &csbi);
		SetConsoleTextAttribute(out, FOREGROUND_BLUE | FOREGROUND_INTENSITY | (csbi.wAttributes & 0xF0));
		SetPos(LENTH * 2 + 10, 2);
		wprintf(L"总分数：%d\n", ps->_score);
		SetPos(LENTH * 2 + 10, 3);
		wprintf(L"当前食物分数：%2d\n", ps->_food_weight);
		SetConsoleTextAttribute(out, csbi.wAttributes);

		if (KEY_PRESS(VK_UP) && ps->_dir != DOWN) {
			ps->_dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->_dir != UP) {
			ps->_dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_dir != RIGHT) {
			ps->_dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_dir != LEFT) {
			ps->_dir = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE)) {
			//暂停
			Pause();
		}
		else if (KEY_PRESS(VK_ESCAPE)) {
			//正常退出
			ps->_status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_F3)) {
			//加速
			if (ps->_sleep_time > 20) {
				ps->_sleep_time -= 20;
				ps->_food_weight += 2;
			}
		}
		else if (KEY_PRESS(VK_F4)) {
			//减速
			if (ps->_food_weight > 2) {
				ps->_sleep_time += 20;
				ps->_food_weight -= 2;
			}
		}
		//走起来
		if (SnakeMove(ps, count)) { count++; }
		Sleep(ps->_sleep_time);
	} while (ps->_status == OK);
}

void Free(pSnakeNode ps) {
	if (ps == NULL) return; // 递归终止条件：当前节点为空
	Free(ps->next);        // 先递归释放后续节点
	free(ps);             // 再释放当前节点
}

void GameEnd(pSnake ps) {
	SetPos(LENTH, LENTH / 2);
	switch (ps->_status) {
	case END_NORMAL:
		wprintf(L"您主动结束游戏\n");
		break;
	case KILL_BY_WALL:
		wprintf(L"您撞到墙上，游戏结束\n");
		break;
	case KILL_BY_SELF:
		wprintf(L"您咬到自己，游戏结束\n");
		break;
	}
	//更新RatingRecord
	add_entry("data.txt", USERNAME, ps->_score);
	//释放蛇身链表
	Free(ps->_pSnake);
}