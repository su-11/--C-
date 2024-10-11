#include <stdio.h>
#include "super_menu.h"
#include "file.h"
#include "stree.h"
#include "user.h"
#include "flist.h"
#include "product.h"
#include "doulist.h"


int main(int argc, char const *argv[])
{
    //欢迎页面
    system("clear");
    printf_Superwelcome();
    while(getchar()!='\n');
    system("clear");
    //登录页面
    //使用树结构，存储用户信息
    STREE* root = NULL;
    // USER data = {"root","qwer1234",0,"百香","春风起","女",100,0};
    // stree_create(&root,data);
    //使用双向链表结构 定义用户菜单和root菜单
    NODE* user_head = NULL;
    NODE* root_head = NULL;
    
    //product 商品信息  使用单链表结构存储，初始化
    FLIST* product = NULL;
    //定义购物车链表-单向循环链表
    FLIST* shopcart = NULL;
    // GOODS data = {1011,"乳酸君",2.5,100,"乳饮",1};
    // flist_create(data,&product);
    // DATA root_data1 =  {"用户管理"};
    // doulist_create(root_data1,&root_head);
    // DATA user_data1 =  {"商品信息"};
    // doulist_create(user_data1,&user_head);

    
    read_User(&root);
    read_Product(&product);
    read_Rootmenu(&root_head);
    read_Usermenu(&user_head);
    // DATA root_data1 =  {"查看购物车  "};
    // doulist_addTail(&user_head,root_data1);
    //登录注册校验
    printf_Login();
    //root菜单功能实现；
    function_rootmenu(root,product,shopcart,user_head,root_head);
    //保存信息到文件
    save_User(&root);
    save_Product(&product);

    save_Rootmenu(&root_head);
    //读取user-链表，保存在文件中
    save_Usermenu(&user_head);

    return 0;
}
