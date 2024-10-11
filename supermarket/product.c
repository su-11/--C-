#include "product.h"

//添加商品信息
void product_insert(FLIST** product,GOODS product_data)
{
    //打印商品信息

    flist_showAll(*product);
    printf("请输入产品编号：");
    scanf("%d",&product_data.product_num);
    //清除缓冲区中的字符
    while(getchar() != '\n')
    ;
    printf("请输入产品名称：");
    scanf("%19s",product_data.product_name);
    while(getchar() != '\n')
    ;
    printf("请输入产品单价：");
    scanf("%lf",&product_data.product_price);
    while(getchar() != '\n')
    ;
    printf("请输入产品数量：");
    scanf("%d",&product_data.product_amount);
    while(getchar() != '\n')
    ;
    printf("请输入产品类别：");
    scanf("%14s",product_data.product_category);
    while(getchar() != '\n')
    ;
    printf("请输入产品积分：");
    scanf("%d",&product_data.product_integral);   
    while(getchar() != '\n')
    ;
    //添加数据到链表
    flist_insert(product,product_data);
}

//修改商品信息
void product_update(FLIST* product,GOODS product_data)
{
    //打印商品信息
    flist_showAll(product);
    GOODS posData;
    printf("请输入需要修改的商品编号：");
    scanf("%d",&product_data.product_num);
    while(getchar() != '\n')
    ;
    printf("请输入新产品编号：");
    scanf("%d",&posData.product_num);
    while(getchar() != '\n')
    ;
    printf("请输入新产品名称：");
    scanf("%19s",posData.product_name);
    while(getchar() != '\n')
    ;
    printf("请输入新产品单价：");
    scanf("%lf",&posData.product_price);
    while(getchar() != '\n')
    ;
    printf("请输入产品数量：");
    scanf("%d",&posData.product_amount);
    while(getchar() != '\n')
    ;
    printf("请输入产品类别：");
    scanf("%14s",posData.product_category);
    while(getchar() != '\n')
    ;
    printf("请输入产品积分：");
    scanf("%d",&posData.product_amount);   
    while(getchar() != '\n')
    ;
    //调用flist的修改函数
    flist_updateNode(product,product_data,posData);

}

//查询商品信息
void product_select(FLIST* product)
{
    //打印商品信息
    flist_showAll(product);
    GOODS product_data;
    printf("请输入需要查询的商品名称");
    scanf("%s",product_data.product_name);
    FLIST * find = flist_findNode(product,product_data);
    printf("———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
    char n[6][20] = {"产品编号","产品名称","产品单价","产品数量","产品类别","产品积分"};
    printf("|%-24s|%-24s|%-24s|%-24s|%-24s|%-24s| \n",n[0],n[1],n[2],n[3],n[4],n[5]);
    printf("———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
    printf("|%-20d|%-22s|%-20lf|%-20d|%-22s|%-20d| \n",find->data.product_num,find->data.product_name,find->data.product_price,find->data.product_amount,find->data.product_category,find->data.product_integral);
    printf("———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
}

//删除商品信息
void product_delete(FLIST** product)
{
    flist_showAll(*product);
    GOODS product_data;
    printf("请输入需要删除的商品名称");
    scanf("%s",product_data.product_name);
    //调用flist中删除函数通过商品编号删除商品信息
    flist_deleteNode(product,product_data);
}