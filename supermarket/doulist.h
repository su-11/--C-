#ifndef _DOULIST_H
#define _DOULIST_H
//其他头文件
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//定义结构体
//定义复杂数据类型

typedef struct 
{
    char name[50];
}DATA;


typedef struct Node
{
    DATA data; //(数据类型自适用)  //存储数据---数据域
    struct Node * prev;
    struct Node * next;//存储下一个节点地址----指针域
}NODE;

//对节点进行重命名
//typedef struct Node NODE;

//创建链表头节点
//NODE* doulist_create(DATA data);
int doulist_create(DATA data,NODE **head);

//插入数据--头插法
int doulist_addHead(NODE **head,DATA data);
//插入数据--尾插法
int doulist_addTail(NODE **head,DATA data);
//int doulist_addTail1(NODE **head,DATA data);
//插入数据--中间插入（在指定数据的位置插入）
int doulist_addMiddle(NODE **head,DATA data, DATA posData);

//查询链表--根据指定数据查询该数据在链表中的节点，并返回该节点的地址
//NODE * doulist_findNode(NODE* head,DATA posData);
//查询链表--根据指定数据查询该数据在链表中的节点，并返回该节点的地址
int  doulist_findNode(NODE* head,DATA posData,NODE ** findNode);
//修改操作--根据指定的数据查找在链表中的节点，并用新的数据修改该节点上的数据
int doulist_updateNode(NODE* head, DATA posData,DATA newData);

//删除操作
int doulist_deleteNode(NODE **head,DATA posData);

//清空链表--清空链表中的所有节点
void doulist_clear(NODE **head);

//遍历链表中节点中的数据
void doulist_showAll(NODE* head);

//如果链表中的节点有增加和删除时，形式参数要传递二级指针

#endif