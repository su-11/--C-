#ifndef __FILE_H
#define __FILE_H

//文件读写操作
#include "file.h"
#include "stree.h"
#include "flist.h"
#include "doulist.h"

//读取用户数据存储到链表中
int read_User(STREE** root);
//读取商品信息存储到链表中
int read_Product(FLIST** product);
//读取菜单数据到链表中
int read_Rootmenu(NODE** root_head);
//读取user-用户菜单，保存在链表中
int read_Usermenu(NODE** user_head);


//保存用户数据到链表中
int save_User(STREE** root);
//遍历链表中节点中的数据
void save_showAll(FLIST* product,FILE* fp);
//保存商品信息到链表中
int save_Product(FLIST** product);
//保存菜单数据到链表中
int save_Rootmenu(NODE** root_head);
//读取user-链表，保存在文件中
int save_Usermenu(NODE** user_head);
#endif