#pragma once
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
int MenuStu(void);
int MenuTea(void);
// 比较函数哑巴节点
int CompareByNumAsc(STU* a, STU* b);
int CompareBySumAsc(STU* a, STU* b);
int CompareBySumDesc(STU* a, STU* b);
// 操作菜单
void SetPosition(int x, int y);
//创建链表
STU* CreateNode();
// 设置输出内容在控制台窗口中的起始位置
void InputRecord(int* n, int* m, STU** head);
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
// 按学号排序
STU* SortbyNum(int n, int m, STU* stu);
// 按姓名排序
STU* SortbyName(int n, int m, STU* head);
// 按每个学生平均分进行排序
STU* SortbyScoreA(int n, int m, STU* stu);
// 升序排序
STU* SortbyScoreB(int n, int m, STU* stu);
// 降序排序
void StatisticAnalysis(int n, int m, STU* stu);
// 打印学生成绩
void PrintRecord(int n, int m, STU* stu);
// 将学生信息保存至文件中
void WriteToFileBinary(int n, STU* stu);
int ReadfromFileBinary(int* pn, STU* stu, int* first);
// 将学生信息从文件中读出，存入内存，方便对学生信息进行处理
//改变链表顺序函数,将会用于链表的冒泡排序
void ChangeOrder(STU* p1, STU* p2, STU* q1, STU* q2);
STU* SortByXXX(int n, int m, STU* head, int (*compare)(STU*, STU*));
//排序总汇
void FuzzyQuery(int n, int m, STU* head);
//模糊查询