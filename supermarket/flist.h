#ifndef __FLIST_H
#define __FLIST_H
//其他头文件
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stree.h"


//定义结构体
//定义复杂数据类型

typedef struct 
{
    int product_num;    //产品编号
    char product_name[20]; //产品名称
    double product_price;//产品单价
    int product_amount;//产品数量
    char product_category[15];//产品类别
    int product_integral; //产品积分
}GOODS;

// typedef int GOODS;

typedef struct flist
{
    GOODS data; //(数据类型自适用)  //存储数据---数据域
    struct flist * next;//存储下一个节点地址----指针域
}FLIST;

//对节点进行重命名
//typedef struct Node FLIST;

//创建链表头节点
int flist_create(GOODS data,FLIST **head);

//插入数据
int flist_insert(FLIST **head,GOODS data);

//插入数据--中间插入（在指定数据的位置插入）
int flist_addMiddle(FLIST **head,GOODS data, GOODS posData);

//查询链表--根据指定数据查询该数据在链表中的节点，并返回该节点的地址
FLIST * flist_findNode(FLIST* head,GOODS posData);
//查询链表--根据指定数据查询该数据在链表中的节点，并返回该节点的地址---根据商品编号比较信息
FLIST * flist_findNodenum(FLIST* head,GOODS posData);
int flist_findnode1(FLIST* head,GOODS posData,FLIST** address);
//修改操作--根据指定的数据查找在链表中的节点，并用新的数据修改该节点上的数据
int flist_updateNode(FLIST* head, GOODS posData,GOODS newData);

//删除操作
int flist_deleteNode(FLIST **head,GOODS posData);

//清空链表--清空链表中的所有节点
void flist_clear(FLIST **head);

//遍历链表中节点中的数据
void flist_showAll(FLIST* head);

//如果链表中的节点有增加和删除时，形式参数要传递二级指针

//单向链表中元素的排序
void flist_Bubble(FLIST *head);
//单向链表中元素的反转
void flist_Rumination(FLIST **head);

//添加到购物车功能，即将查询商品信息链表，复制数据
int flist_insertshopCart(FLIST* head, FLIST** shopcart ,GOODS posData,int porduct_number);
//换货操作
//修改操作--根据指定的数据查找在链表中的节点，并用新的数据修改该节点上的数据
int flist_updateCart(FLIST* head, GOODS posData,GOODS newData);

//计算总价
double flist_priceSum(STREE* root,FLIST* shopcart,USER *user_data);


#endif