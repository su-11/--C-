//文件读写操作
#include "file.h"

//读取用户数据存储到链表中
int read_User(STREE** root)
{
    //创建文件
    FILE *fp = fopen("user.txt","a+");
    //非空校验
    if(!fp)
    {
        puts("文件创建失败");
        return -1;
    }
    USER user;
    //从文件中读取user数据
    while(fread(&user,sizeof(USER),1,fp)==1)
    {
        stree_add(root,user);
    }
    //关闭文件
    fclose(fp);
    return 0;
}

//读取商品信息存储到链表中
int read_Product(FLIST** product)
{
    //打开文件
    FILE* fp = fopen("product.txt","r+");
    //非空校验
    if(!fp)
    {
        puts("文件打开失败");
        return -1;
    }
    //创建商品信息
    GOODS productData;
    while(fread(&productData,sizeof(GOODS),1,fp) == 1)
    {
        flist_insert(product,productData);
    }
    //关闭文件
    fclose(fp);
    return 0;
}
//读取root-用户菜单，保存在链表中
int read_Rootmenu(NODE** root_head)
{
    //打开文件
    FILE* fp = fopen("root.txt","r");
    if(!fp)
    {
        puts("文件打开失败");
        return 0;
    }
    DATA root_data;
    while(fread(&root_data,sizeof(DATA),1,fp)==1)
    {
        //int doulist_addTail(NODE **head,DATA data)
        doulist_addTail(root_head,root_data);
    }
    //关闭文件
    fclose(fp);
    return 0;
}
//读取root-用户菜单，保存在链表中
int read_Usermenu(NODE** user_head)
{
    //打开文件
    FILE* fp = fopen("user_menu.txt","r");
    if(!fp)
    {
        puts("文件打开失败");
        return 0;
    }
    DATA root_data;
    while(fread(&root_data,sizeof(DATA),1,fp)==1)
    {
        //int doulist_addTail(NODE **head,DATA data)
        doulist_addTail(user_head,root_data);
    }
    //关闭文件
    fclose(fp);
    return 0;
}
//将数据保存到文件中---函数
void save_startShow(STREE *root,FILE* fp)
{
    if(root == NULL)
    {
        return ;
    }
    if(fwrite(&(root->data),sizeof(USER),1,fp)!=1)
        puts("error");
    //递归调用，遍历左子树上的数据
    save_startShow(root->left,fp);
    //递归调用，遍历右子树上的数据
    save_startShow(root->right,fp);
}
//保存用户数据到文件中
int save_User(STREE** root)
{
    if(!*root)
    {
        puts("没有需要存入的数据");
        return -1;
    }
    //打开文件
    FILE *fp = fopen("user.txt","w");
    //非空校验
    if(!fp)
    {
        puts("文件打开失败");
        return -1;
    }
    //将数据写入文件
    save_startShow(*root,fp);

    //关闭文件
    fclose(fp);
    return 0;

}

//遍历链表中节点中的数据
void save_showAll(FLIST* product,FILE* fp)
{
    //定义当前指针指向指向头节点
    FLIST * current =product;
    if(current ==NULL)
    {
        puts("flist is empty");
        return ;
    }
    do
    { 
        fwrite(&(current->data),sizeof(GOODS),1,fp);
        current = current->next;    //移动当前指针到下一个节点
    } while (current != product);//判断当前指针不是头节点，就执行循环体语句
    printf("\n");
    return ;
}

//保存商品信息到链表中
int save_Product(FLIST** product)
{
    if(!*product)
    {
        puts("没有需要写入的数据");
        return -1;
    }
    //打开文件
    FILE* fp = fopen("product.txt","w+");
    //非空校验
    if(!fp)
    {
        puts("文件打开失败");
        return -1;
    }

    //将链表中的数据写入到文件中、
    save_showAll(*product,fp);

    //关闭文件
    fclose(fp);
    return 0;

}

//遍历链表中节点中的数据
void doulist_showAll1(NODE* head,FILE* fp)
{
    //定义当前指针指向头节点
    NODE* current = head;
    //判断头结点是否存在
    if(current==NULL)
    {
        //头节点不存在，链表为空
        puts("链表为空");
        return ;
    }
    //遍历数据--移动指针
    while (current!=NULL)
    {
        //当节点不为空，取当前节点数据
        //printf("%p--%p--%s--%p, ",current,current->prev,current->data,current->next);
        fwrite(&(current->data),sizeof(DATA),1,fp);
        current = current->next;
    }
    printf("\n");
}
//遍历链表中节点中的数据
void doulist_showAll2(NODE* head,FILE* fp)
{
    //定义当前指针指向头节点
    NODE* current = head;
    //判断头结点是否存在
    if(current==NULL)
    {
        //头节点不存在，链表为空
        puts("链表为空");
        return ;
    }
    //遍历数据--移动指针
    while (current!=NULL)
    {
        //当节点不为空，取当前节点数据
        //printf("%p--%p--%s--%p, ",current,current->prev,current->data,current->next);
        fwrite(&(current->data),sizeof(DATA),1,fp);
        current = current->next;
    }
    printf("\n");
}

//读取root-链表，保存在文件中
int save_Rootmenu(NODE** root_head)
{
    if(!*root_head)
    {
        puts("没有需要写入的数据");
        return -1;
    }
    FILE* fp = fopen("root.txt","w+");
    if(!fp)
    {
        return -1;
    }

    doulist_showAll1(*root_head,fp);
    //关闭文件
    fclose(fp);
    return 0;

}
//读取root-链表，保存在文件中
int save_Usermenu(NODE** user_head)
{
    if(!*user_head)
    {
        puts("没有需要写入的数据");
        return -1;
    }
    FILE* fp = fopen("user_menu.txt","w+");
    if(!fp)
    {
        return -1;
    }

    doulist_showAll2(*user_head,fp);
    //关闭文件
    fclose(fp);
    return 0;

}
