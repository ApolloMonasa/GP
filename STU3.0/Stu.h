#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define STU_NUM 50 //ѧ����������
#define COURSE_NUM 10 //�γ���������
#define NAME_LEN 30 //ѧ�����ֳ���
#define POS_X1 35 //�˵�ҳ��һ�й���ѡ��ĳ�ʼ��Xλ��  �������������Xλ��
#define POS_X2 40 //������ʾ����Xλ��
#define POS_X3 50 //������ʾ�ĳ�ʼXλ��
#define POS_X4 65 //�˵�ҳ�ڶ��й���ѡ��ĳ�ʼ��Xλ��
#define POS_Y 3 //�������������Yλ��
typedef struct student {
	long num;//ѧ��
	char name[NAME_LEN];
	float score[COURSE_NUM];
	float sum;
	float aver;
	struct student* next;
}STU;
// �Զ��庯������
int MenuStu(void);
int MenuTea(void);
// �ȽϺ����ưͽڵ�
int CompareByNumAsc(STU* a, STU* b);
int CompareBySumAsc(STU* a, STU* b);
int CompareBySumDesc(STU* a, STU* b);
// �����˵�
void SetPosition(int x, int y);
//��������
STU* CreateNode();
// ������������ڿ���̨�����е���ʼλ��
void InputRecord(int* n, int* m, STU** head);
// ����ѧ����Ϣ
void AppendRecord(int* n, int m, STU* stu);
// ����ѧ����Ϣ
int DeleteRecord(int* n, int m, STU* stu);
// ɾ��ѧ����Ϣ��ָɾ��������¼��
void SearchbyNum(int n, int m, STU* stu);
// ��ѧ�Ų�ѯѧ����Ϣ
void SearchbyName(int n, int m, STU* stu);
// ��������ѯѧ����Ϣ
void ModifyRecord(int n, int m, STU* stu);
// �޸�ѧ����Ϣ
void CalculateScoreOfStudent(int n, int m, STU* stu);
// ����ѧ�����ֺܷ�ƽ����
void CalculateScoreOfCourse(int n, int m, STU* stu);
// ����ĳ�ſγ̵��ֺܷ�ƽ����
// ��ѧ������
STU* SortbyNum(int n, int m, STU* stu);
// ����������
STU* SortbyName(int n, int m, STU* head);
// ��ÿ��ѧ��ƽ���ֽ�������
STU* SortbyScoreA(int n, int m, STU* stu);
// ��������
STU* SortbyScoreB(int n, int m, STU* stu);
// ��������
void StatisticAnalysis(int n, int m, STU* stu);
// ��ӡѧ���ɼ�
void PrintRecord(int n, int m, STU* stu);
// ��ѧ����Ϣ�������ļ���
void WriteToFileBinary(int n, STU* stu);
int ReadfromFileBinary(int* pn, STU* stu, int* first);
// ��ѧ����Ϣ���ļ��ж����������ڴ棬�����ѧ����Ϣ���д���
//�ı�����˳����,�������������ð������
void ChangeOrder(STU* p1, STU* p2, STU* q1, STU* q2);
STU* SortByXXX(int n, int m, STU* head, int (*compare)(STU*, STU*));
//�����ܻ�
void FuzzyQuery(int n, int m, STU* head);
//ģ����ѯ