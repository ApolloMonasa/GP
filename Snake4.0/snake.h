#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define USERNAME "Apollo"//设置玩家名字
#define LENTH 30//地图的边长
#define NUM_OF_OBSTACLE 100//障碍物的数量
#define WALL L'□'//墙
#define BODY L'●'//蛇的身体
#define HEAD L'◆'//蛇的头
#define FOOD L'★'//食物
#define INIT_LEN 5//初始蛇的长度
#define POS_X 24//蛇的初始位置
#define POS_Y 5//蛇的初始位置
#include<locale.h>
#include<windows.h>
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

//Ranking宏
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000//最大记录数
#define NAME_WIDTH   10//名字的宽度
#define NUMBER_WIDTH 5//数字的宽度
#define TIME_WIDTH   25//时间的宽度




#define KEY_PRESS(VK) ( (GetAsyncKeyState(VK) & 0x1) ? 1 : 0 )
//类型声明

//蛇的方向
enum DIRECTION {
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

//蛇的状态
enum GAME_STATUS {
	OK,
	KILL_BY_WALL,
	KILL_BY_SELF,
	KILL_BY_OBSTACLE,
	END_NORMAL
};

typedef struct SnakeNode {
	int x;
	int y;
	struct SnakeNode* next;
} SnakeNode, *pSnakeNode;

//typedef struct SnakeNode* pSnakeNode;

//贪吃蛇
typedef struct Snake
{
	//指向蛇头的指针
	pSnakeNode _pSnake;
	//指向食物节点的指针
	pSnakeNode _pFood;
	//指向障碍物节点的指针
	int Obstacle[NUM_OF_OBSTACLE][2];
	//蛇的方向
	enum DIRECTION _dir;
	//游戏状态
	enum GAME_STATUS _status;
	//分数
	int _food_weight;//食物的权重
	int _score;//总分
	int _sleep_time;//休息时间，控制速度
}Snake, *pSnake;

//函数声明
//游戏初始化
void GameStart(pSnake ps);
//欢迎界面的打印
void WelcomeToGame();
//定位光标
void SetPos(short x, short y);
//创建地图
void CreateMap();
//初始化蛇
void InitSnake(pSnake ps);
//创建食物
void CreateFood(pSnake ps);
//游戏运行
void GameRun(pSnake ps);
//打印帮助信息
void PrintHelpInfo();
//暂停
void Pause();
//行走
int SnakeMove(pSnake ps,int count);
//判断下一个是不是食物
int IsNextFood(pSnakeNode pn, pSnake ps);
//吃食物
void EatFood(pSnakeNode pn, pSnake ps);
//打印蛇
void printSnake(pSnakeNode cur);
//没有食物
void NoFood(pSnakeNode pn, pSnake ps);
//检查
void KillByWall(pSnake ps);
void KillBySelf(pSnake ps);
//游戏结束
void GameEnd(pSnake ps);
//释放链表内存
void Free(pSnakeNode ps);

//RatingRecord
typedef struct {
	char name[NAME_WIDTH + 1];
	int number;
	char time[TIME_WIDTH + 1];
} Entry;

// 函数声明
void rtrim(char* str);
int compare_entries(const void* a, const void* b);
void write_to_file(const char* filename, Entry* entries, int count);
void get_current_time(char* time_str);
int read_entries_from_file(const char* filename, Entry* entries);
void add_entry(const char* filename, const char* name, int number);
void print_line(const char* filename, int line_number);
void print_all(const char* filename);


//障碍
void KillByObstacle(pSnake ps);