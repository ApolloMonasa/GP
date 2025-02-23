/*************************************************************************
	> File Name: 2.snake.h
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 23 Feb 2025 05:25:54 PM CST
 ************************************************************************/
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define LENTH 27
#define WALL L'□'
#define BODY L'●'
#define HEAD L'◆'
#define FOOD L'★'
#define INIT_LEN 5
#define POS_X 24
#define POS_Y 5
#include<locale.h>
#include<windows.h>
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
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
void SnakeMove(pSnake ps);
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
