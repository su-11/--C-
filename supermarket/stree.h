#ifndef __STREE_H
#define __STREE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct 
{
    char account[15];//用户账号
    char password[15];//用户密码
    int  permissions; //权限
    char name[20]; //用户姓名
    char signature[40];//个性签名
    char sex[3];    //用户性别
    int  integral;//积分
    double sum_money;//金额总计

}USER;
// typedef int USER;

typedef struct stree
{
    USER data;//节点上的数据域
    struct stree* left;//该节点左侧子节点的地址
    struct stree* right;//该节点右侧子节点的地址
}STREE;
/*
1.
*/
//1.创建树的根节点
int stree_create(STREE** head,USER data);
//2.给根节点添加子节点
int stree_add(STREE** root,USER newdata);
//3.前序遍历（根左右）
void stree_startShow(STREE *root);
//4.中序遍历（左根右）
void stree_middleShow(STREE* root);
//5.后序遍历(左右根)
void stree_endShow(STREE* root);
//6.查询指定位置的指针
STREE* stree_searchdata(STREE* root,USER findata);
//7.修改数据
int stree_updateData(STREE* root,USER data,USER newdata);
//8.清空树中的节点
void stree_free(STREE** root);
//9.删除指定数据位置的节点
int stree_deleteNode(STREE** root,USER data);
//10.删除指定位置的节点--递归
void stree_delete(STREE** root,USER deldata);
//将修改的数据更新到链表中
int stree_updatecart(STREE* root,USER data,USER newdata);

#endif