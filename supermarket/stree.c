#include "stree.h"

//1.创建树的根节点
int stree_create(STREE** root,USER data)
{
    //判断根节点是否存在
    if (*root != NULL)
    {
        //根节点存在，无需创建，直接返回失败标记，给用户提示
        puts("根节点存在");
        return -1; 
    }
    //申请内存
    STREE * pNew = (STREE*)malloc(sizeof(STREE));
    //判断内存是否申请成功
    if(!pNew)
    {
        perror("memory apply failed");
        return -1;
    }
    //给新节点中的成员初始化
    pNew->data = data;
    pNew->left = NULL;
    pNew->right = NULL;
    //将新节点作为根节点
    *root = pNew;
    return 0; 
}

//2.给根节点添加子节点
int stree_add(STREE** root,USER newdata)
{
    //判断根节点是否存在
    if(*root == NULL)
    {
        //根节点不存在，1.将新节点作为根节点2.提示并返回失败标记
        STREE* pNew = (STREE*)malloc(sizeof(STREE));
        //非空校验
        if(!pNew)
        {
            perror("memory apply failed");
            return -1;
        }
        //初始化新节点的成员
        pNew->data = newdata;
        pNew->left = NULL;
        pNew->right = NULL;
        //新节点作为根节点
        *root = pNew;
        //返回成功标记0；
        return 0;
    }
    else
    {
        //根节点存在
        //将要添加的数据和树中节点上的数据大小比较
        /*
        1.如果是字符串，应该用strcmp比较大小
        2.如果是整形数据，用比较运算符比较大小
        3.如果是浮点型数据，数据类型相同时，可以用比较运算符比较；如果数据类型相同，用相减的方式比较大小
        4.如果是结构体类型，用memcmp比较大小，但是有很小的可能性比较不准确
        */
       int flag = strcmp(newdata.account,(*root)->data.account);
       if(flag>0)
       {
            //新增加的数据比当前根节点上的数据大
            //递归调用，尝试在当前节点的右侧尝试插入
            stree_add(&(*root)->right,newdata);

       }
       else if(flag < 0)
       {
            //新增加的数据比当前根节点上的数据小
            //递归调用
            stree_add(&(*root)->left,newdata);
       }
       else
       {
            //新增加的数据和当前根节点上的数据相同,搜索二叉树中不允许有相同的数据
            //puts("用户已存在已存在，无法添加，请重新输入");
            return -1;
       }
    }
    return 0;
}

//3.前序遍历(根左右)
void stree_startShow(STREE *root)
{
    if(root == NULL)
    {
        //puts("树中根节点不存在");
        return ;
    }
    //打印根节点上的数据
    printf("|%-15s|%-15s|%-15d|%-20s|%-15s|%-15d|%-15.2f|%-40s \n",root->data.account,root->data.password,root->data.permissions,root->data.name,root->data.sex,root->data.integral,root->data.sum_money,root->data.signature);
    printf("————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
    //递归调用，遍历左子树上的数据
    stree_startShow(root->left);
    //递归调用，遍历右子树上的数据
    stree_startShow(root->right);

}

// //4.中序遍历
// void stree_middleShow(STREE* root)
// {
//     //判断当前节点是否为空
//     if(root ==NULL)
//     {
//         //当前节点为空
//         return ;//递归出口，当递归到叶子节点的左侧或右侧一定为空

//     }
//     //递归遍历左子树
//     stree_middleShow(root->left);
//     //打印当前数据
//     printf("%d, ",root->data);
//     //递归遍历右子树
//     stree_middleShow(root->right);

// }


// //5.后序遍历
// void stree_endShow(STREE* root)
// {
//     //判断当前节点是否为空
//     if(root == NULL)
//     {
//         return ;
//     }
//     //递归遍历左子树
//     stree_endShow(root->left);
//     //递归遍历右子树
//     stree_endShow(root->right);
//     //打印当前根节点
//     printf("%d, ",root->data);
// }

//6.查询数据
STREE* stree_searchdata(STREE* root,USER findata)
{
    //判断当前根节点是否为空--递归出口
    if (root == NULL)
    {
        return NULL;
    }
    //当前根节点上的数据和要查询的数据比较
    int flag = strcmp(root->data.account,findata.account);
    if(flag == 0)
    {
        //当前根节点上的数据和要查询的数据相等，找到了对应数据的节点
        //返回当前节点的地址
        return root;
    }
    else if(flag > 0)
    {
        //当前根节点上的数据比要查询的数据大，就取当前节点的左子树上找
        //递归调用
        return stree_searchdata(root->left,findata);
    }
    else if(flag < 0)
    {
        //当前根节点上的数据比要查询的数据大，就取当前节点的右子树上找
        //递归调用
        return stree_searchdata(root->right,findata);
    }
}

//7.修改数据
int stree_updateData(STREE* root,USER data,USER newdata)
{
    //调用查询函数，找到需要修改数据的地址
    STREE* find = stree_searchdata(root,data);
    if(find == NULL)
    {
        puts("在树中没有找到要修改的数据，修改失败");
        return -1;
    }
    //修改查找到的节点的数据
    strcpy(find->data.account,newdata.account);
    //返回成功标记
    return 0;
}

// //8.清空树中的节点
// void stree_free(STREE** root)
// {
//     //判断当前根节点是否为空
//     if(*root == NULL)
//     {
//         return ; // 递归出口
//     }
//     //递归调用,释放当前根节点左子树上的节点
//     stree_free(&(*root)->left);
//     //递归调用，释放当前根节点右子树上的节点
//     stree_free(&(*root)->right);
//     //测试代码
//     printf("free:%d\n",(*root)->data);
//     //释放当前节点
//     free(*root);
//     *root = NULL;
// }

//9.删除指定数据位置的节点
int stree_deleteNode(STREE** root,USER data)
{
    //定义局部的临时变量
    STREE* del = *root;//指向待删除节点
    STREE* parent = NULL;//指向实际删除节点的父节点
    STREE* replace = NULL;//指向实际删除的节点
    while (del != NULL)
    {
        //当前根节点存在
        //比对数据
        int flag = strcmp(data.account,del->data.account);
        if (flag<0)
        {
            //要删除的数据在当前节点的左子树上
            parent = del;
            //当前带判断的节点就移动在左侧的节点上
            del = del->left;
        }
        else if(flag >0)
        {
            //要删除的数据在当前节点的右子树上
            //当前节点作为父节点
            parent = del;
            //当前待判断的节点就移动到右侧节点上
            del = del->right;
        }
        else if(flag == 0)
        {
            //当前节点就是要删除的节点----找到要删除的节点，还要判定当前节点是否叶子结点
            //叶子结点的做指针和右指针为空（叶子结点没有左子树，也没有右子树，就是没有子节点
            if(del->left != NULL)
            {
                //待删除的节点有左子树
                parent = del;
                replace = del->left;
                while (replace->right != NULL)
                {
                    parent = replace;
                    replace = replace->right;
                }
                //将待删除的节点数据和replace的数据交换
                del->data = replace->data;
                //待删除的节点左子树上有左子树和右子树
                if(parent->right == replace)
                {
                    //实际删除的节点在其父节点的右子树上的
                    parent->right = replace->left;
                }
                else
                {
                    //实际删除的节点在其父节点的左子树上
                    parent->left =  replace->left;
                }
                //回收叶子结点
                free(replace);
                replace = NULL;
                return 0;
            }
            else if(del->right != NULL)
            {
                //待删除的节点有右子树
                parent = del;
                replace = replace->right;//待删除的右侧；
                //找右子树中的最小数的节点
                while (replace->left != NULL)
                {
                    parent = replace;
                    replace = replace->left;
                }
                //待删除节点的数据和右子树上的数据交换
                del->data = replace->data;
                if(parent->right== replace)
                {
                    parent->right = replace->right;
                }
                else{
                    parent->left = replace->right;
                }
                //回收replace指向的节点
                free(replace);
                replace = NULL;
                return 0;
            }
            else{
                //待删除的节点没有右子树，也没有左子树，是叶子节点
                //叶子结点直接删除
                if(parent == NULL)
                {
                    //叶子结点没有父节点，说明带删除的节点是唯一节点（既是叶子节点，也是根节点）
                    free(del);
                    del = NULL;
                    *root = NULL;//跟指针指向空
                    return 0;//返回删除成功标记
                }
                if(parent->left == del)
                {
                    //带删除的节点是父节点的左侧节点
                    parent->left = NULL;
                }
                else if(parent->right==del)
                {
                    //待删除的节点是父节点的右侧节点
                    parent->right = NULL;
                }
                //删除叶子结点
                free(del);
                //设置指针为空
                del = NULL;
                return 0;//返回删除成功标记
            }
            

        }
        
    }
    
}
//在指定节点上找最小值
static STREE* findMin(STREE* node)
{
    while (node->left!= NULL)
        node = node->left;
    return node; 
}
//在指定节点上找最大值
static STREE* finMax(STREE* node)
{
    while(node->right!= NULL)
        node = node->right;
    return node;
}

//10.删除指定位置的节点--递归
void stree_delete(STREE** root,USER deldata)
{
    //判断当前根节点是否为空
    if(*root == NULL)
    {
        //递归的出口
        return  ;//*root有可能是整个树的根节点，也有可能是每个父节点
    }
    //当前根节点上的数据和要删除的数据比较
    int flag = strcmp((*root)->data.account,deldata.account);
    if(flag>0)
    {
        //当前节点上的数据比要删除的数据大
        //递归调用，去当前节点的左子树上找待删除的数据的节点
        stree_delete(&(*root)->left,deldata);
    }
    else if(flag <0)
    {
        //当前节点上的数据比要删除的数据小
        //递归调用，去当前节点右子树上找待删除数据节点
        stree_delete(&(*root)->right,deldata);
    }
    else if(flag == 0)
    {
        //当前节点上的数据和要删除的数据相等，当前节点就是要删除的节点
        //定义临时变量记录当前删除节点的地址
        STREE* nodeTpDelete = *root;
        //判断待删除的节点有没有左子树
        if((*root)->left == NULL)
        {
            //待删除的节点没有左子树
            //将右子树的地址给当前节点
            *root = (*root)->right;
            //测试打印
            //printf("del:%p ---- %d",nodeTpDelete,nodeTpDelete->data);
            //回收当前节点
            free(nodeTpDelete); //回收当前节点
            nodeTpDelete = NULL; //指针指向的内存回收，并置空
        }
        else if ((*root)->right == NULL)
        {
            //待删除的节点没有右子树
            //将左子树的地址给当前节点
            *root = (*root)->left;
            //测试打印
            //printf("del:%p ---- %d",nodeTpDelete,nodeTpDelete->data);
            //回收当前节点
            free(nodeTpDelete);
            nodeTpDelete = NULL;
        }
        else
        {
            //待删除的节点既有左子树，也有右子树
            //1.找左子树中的最大值，用来替换待删除节点上的数据，删除最大值所在的节点（叶子结点）
            //2.找右子树中的最小值，用来替换待删除的节点上的数据，删除最小值所在的节点（叶子结点）
            STREE* minNode = findMin((*root)->right);
            //左子树上的最大值，替换当前节点上的数据
            (*root)->data = minNode->data;
            //递归删除右子树上中的最小数据的节点
            stree_delete(&(*root)->right,minNode->data);

        }
    }
}

//将修改的数据更新到链表中
int stree_updatecart(STREE* root,USER data,USER newdata)
{
    //调用查询函数，找到需要修改数据的地址
    STREE* find = stree_searchdata(root,data);
    if(find == NULL)
    {
        puts("在树中没有找到要修改的数据，修改失败");
        return -1;
    }
    //修改查找到的节点的数据
    if(memcmp(&find->data,&newdata,sizeof(USER)) == 0)
    {
        puts("没有需要添加的数据");
        return  -1;
    }
    else
    {
        // newdata.integral = find->data.integral;
        // newdata.sum_money = find->data.sum_money;
        find->data = newdata;
    }
    //返回成功标记
    return 0;
}