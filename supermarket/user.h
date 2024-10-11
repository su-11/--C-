#ifndef __USER_H
#define __USER_H

#include   <stdlib.h>
#include "stree.h"
#include "super_menu.h"
#include "file.h"
#include "flist.h"
#include "product.h"


//用户验证（verify）  权限0/1(Permissions)
//权限为1   普通用户
//权限为0   超级用户

//用户注册
void root_registered(STREE** root);

//用户管理
void user_manage(STREE* root);
//root菜单功能实现；
void function_rootmenu(STREE* root,FLIST* product,FLIST* shopcart,NODE* user_head,NODE* root_head);

//购物车功能实现；
void shop_cart(FLIST* shopcart,FLIST* product,STREE* root,NODE* user_head,USER user_data);

#endif