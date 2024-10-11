#include "user.h"

//用户注册
static void root_registered(STREE** root)
{
    USER user_data;
    printf("请输入您的账号：");
    scanf("%14s",user_data.account);

    printf("请输入您的密码：");
    scanf("%14s",user_data.password);
    //设置默认权限为1
    user_data.permissions = 1;

    printf("请输入您的姓名：");
    scanf("%19s",user_data.name);

    printf("请输入您的性别：");
    scanf("%s",user_data.sex);

    printf("请输入个性签名：");
    scanf("%39s",user_data.signature);
    user_data.integral = 0;
    user_data.sum_money = 0.00;
    //添加数据到链表
    stree_add(root,user_data);
}

//修改用户
static void update_user(STREE* root)
{
    USER updateuser;
    USER data;
    printf("请输入需要修改的用户账户：");
    scanf("%s",updateuser.account);
    printf("请输入更新后您的账号：");
    scanf("%14s",data.account);

    printf("请输入更新后您的密码：");
    scanf("%14s",data.password);

    printf("请输入您需要设置的权限：");
    scanf("%d",&data.permissions);

    printf("请输入更新后您的姓名：");
    scanf("%19s",data.name);

    printf("请输入更新后您的性别：");
    scanf("%s",data.sex);

    printf("请输入更新后的个性签名：");
    scanf("%39s",data.signature);
    data.integral = 0;
    data.sum_money = 0.00;
    stree_updatecart(root,updateuser,data);
}

//对用户进行增删改查
static void user_operation(STREE* root)
{
    USER data;
    int flag = 0;
    while(1)  //无限循环，当用户输入0停止
    {
        printf("请输入需要进行的操作：");
        scanf("%d",&flag);
        if(flag == 0)
        {
            break;  //输入0，退出循环
        }
        else
        {
            switch(flag)
            {
                //删除用户
                case 1:
                    printf("请输入需要删除的用户账户：");
                    scanf("%s",data.account);
                    stree_deleteNode(&root,data);
                    break;
                //修改用户
                case 2:
                    update_user(root);
                    break;
                //查询用户
                case 3:
                    printf("请输入需要查询的用户账户：");
                    scanf("%s",data.account);
                    STREE* find =  stree_searchdata(root,data);
                    //打印根节点上的数据
                    printf("————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
                    printf("|%-15s|%-15s|%-15d|%-20s|%-15s|%-15d|%-15.2f|%-40s| \n",find->data.account,find->data.password,find->data.permissions,find->data.name,find->data.sex,find->data.integral,find->data.sum_money,find->data.signature);
                    printf("————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
                    break;
                //添加用户
                case 4:
                    root_registered(&root);
                    break;
            }
        }
    }    
}
//用户信息打印功能
static void user_manage(STREE* root)
{
    printf("\n");
    printf("————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
    char n[8][20] = {"用户账号","用户密码","用户权限","用户姓名","用户性别","用户积分","金额总计","个性签名"};
    printf("|%-19s|%-19s|%-19s|%-22s|%-18s|%-19s|%-19s|%-40s| \n",n[0],n[1],n[2],n[3],n[4],n[5],n[6],n[7]);
    printf("————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
    stree_startShow(root);
    printf("                \n");
    printf("————————————1:删除用户——————————————————————2:修改用户———————————————————————3:查询用户——————————————————————4.增加用户—————————————0:退出——————————————\n");
    printf("\n");
    user_operation(root);
}

//root用户菜单
static void root_menu(NODE* root_head)
{
    doulist_showAll(root_head);
    printf("——————————————————————1.尾部添加菜单—————————————————————————2.中间添加菜单——————————————————————————————0.退出——————————————————————————————\n");
    printf("\n");   
    DATA posData,root_data;
    int n = 0;
    while(1)
    {
        
        // doulist_showAll(root_head);
        // printf("——————————————————————1.尾部添加菜单—————————————————————————2.中间添加菜单——————————————————————————————0.退出——————————————————————————————\n");
        
        printf("请输入您需要进行的操作：");
        scanf("%d",&n);
        if(n == 0)
        {
            break ;
        }
        switch(n)
        {
            case 1:
                //添加root功能菜单
                //printf("请输入需要在菜单之前需要插入新菜单的原始菜单：");
                //scanf("%s",root_data.name);
                printf("请输入需要插入的新菜单：");
                scanf("%s",posData.name);
                //doulist_addMiddle(&root_head,root_data,posData);
                doulist_addTail(&root_head,posData);
                break;
            case 2:
                //添加root功能菜单
                printf("请输入需要在菜单之前需要插入新菜单的原始菜单：");
                scanf("%s",root_data.name);
                printf("请输入需要插入的新菜单：");
                scanf("%s",posData.name);
                doulist_addMiddle(&root_head,root_data,posData);
                //doulist_addTail(&root_head,posData);
                break;
            default:
                break;
        }

    }
    
}
//user用户菜单
static void user_menu(NODE* user_head)
{
    doulist_showAll(user_head);
    printf("——————————————————————1.尾部添加菜单—————————————————————————2.中间添加菜单——————————————————————————————0.退出——————————————————————————————\n");
    printf("\n");   
    DATA posData,root_data;
    int n = 0;
    while(1)
    {
        
        // doulist_showAll(root_head);
        // printf("——————————————————————1.尾部添加菜单—————————————————————————2.中间添加菜单——————————————————————————————0.退出——————————————————————————————\n");
        
        printf("请输入您需要进行的操作：");
        scanf("%d",&n);
        if(n == 0)
        {
            break ;
        }
        switch(n)
        {
            case 1:
                //添加user功能菜单
                //printf("请输入需要在菜单之前需要插入新菜单的原始菜单：");
                //scanf("%s",root_data.name);
                printf("请输入需要插入的新菜单：");
                scanf("%s",posData.name);
                //doulist_addMiddle(&root_head,root_data,posData);
                doulist_addTail(&user_head,posData);
                break;
            case 2:
                //添加user功能菜单
                printf("请输入需要在菜单之前需要插入新菜单的原始菜单：");
                scanf("%s",root_data.name);
                printf("请输入需要插入的新菜单：");
                scanf("%s",posData.name);
                doulist_addMiddle(&user_head,root_data,posData);
                //doulist_addTail(&root_head,posData);
                break;
            default:
                break;
        }

    }
    
}

//更换商品功能
static void shopcartData(FLIST* product,FLIST* shopcart)
{
    int num;
    GOODS shopcart_data,product_datanum;
    printf("请输入你需要更换的商品名称：");
    scanf("%19s",shopcart_data.product_name); 
    printf("请输入您需要商品的商品编号："); 
    scanf("%d",&product_datanum.product_num);  
    //查询链表--根据指定数据查询该数据在链表中的节点，并返回该节点的地址
    //查找购物车中的数据
    FLIST *findcart =  flist_findNode(shopcart,shopcart_data);
    //查找商品信息
    FLIST *findproduct =  flist_findNodenum(product,product_datanum);
    //修改购物车数据
    flist_updateNode(shopcart, findcart->data,findproduct->data);
}

//结算商品
static double shopcartSum(FLIST* shopcart,STREE* root,USER *currentdata)
{
    //需要通过sum累加购物车中的物品价格，判断用户积分是否达条件，获取当前用户信息，将用户信息赋值 
    //定义price_sum(double),integral_sum(int,用不到了，直接在flist_priceSum函数中解决，直接调用用户数据)
    double price_sum = 0;//商品价格
    //遍历链表中的数据，对商品进行计价，求和积分
    price_sum = flist_priceSum(root,shopcart,currentdata);
    if (currentdata->integral>20000)
    {
        return 0.7*price_sum;
    }
    else if(currentdata->integral>5000)
    {
        return 0.8*price_sum;
    }
    else if(currentdata->integral>1000)
    {
        return 0.9*price_sum;
    }
    else if(currentdata->integral>100)
    {
        return 0.95*price_sum;
    }
    else
        return price_sum;

}

//商品操作
static void order(FLIST* product,FLIST** shopcart)
{
    int num;
    GOODS  shoppingcart; //接收添加到购物车的商品信息
    printf("请输入您需要加入购物车的商品编号：");
    scanf("%d",&shoppingcart.product_num);
    printf("请输入您需要购买的数量：");
    scanf("%d",&num);
    //添加到购物车功能，即将查询商品信息链表，复制数据
    flist_insertshopCart(product, shopcart ,shoppingcart,num);
}

//购买功能
static void payshop(FLIST* product,FLIST** shopcart)
{
    int flag;
    flist_showAll(product);
    printf("————————————1:添加到购物车——————————————————————————2:查看购物车————————————————————————————0:退出—————————————————————————————\n");

     while(1)  //无限循环，当用户输入0停止
    {
        printf("请输入需要进行的操作：");
        scanf("%d",&flag);
        if(flag == 0)
        {
            break;  //输入0，退出循环
        }
        else
        {
            switch(flag)
            {
                //添加到购物车
                case 1:
                    order(product,shopcart);
                    break;
                //查看购物车
                case 2:
                    flist_showAll(*shopcart);
                    break;
                default :
                    break;
            }
        }
    }    
}

//购物车功能实现；
static void shop_cart(FLIST* shopcart,FLIST* product,STREE* root,NODE* user_head,USER user_data)
{
    //定义以个新的商品信息链表，随用户输入商品编号，将商品信息赋值到新的购物车链表，并让用户输入购买数量，让此数量代替商品货架数量
    //添加到购物车即上一注释
    //查看即查询链表（可以对商品信息添加类别，属性）
    //退货，即删除节点
    //换货即修改节点
    //结算，使用购买数量*单价   //将总价赋值个用户数据，树结构中的金额总计，并使其求和
    //给商品设置积分属性，结算金额时，积分复制到用户积分中，超100，打九五折，超1000，打九折，超5000 打八折，超20000，，打七折；
    //用户确认退出，清空链表

    GOODS deletecart; //接收需要删除的商品属性
    int user_n= 0;
    while(1)
    {
        doulist_showAll(user_head);
        printf("请输入需要进行的操作");
        scanf("%d",&user_n);
        
        if(user_n > 0)
        {
            switch(user_n)
            {
                case 1:
                    
                    payshop(product,&shopcart);
                    system("clear");
                    break;
                case 2:
                    
                    order(product,&shopcart);
                    printf("请按回车继续");
                    while(getchar()=='\n')
                    {
                        getchar()!='\n';
                        break;
                    }
                    system("clear");
                    break;
                case 3:
                    
                    //查看购物车
                    flist_showAll(shopcart);
                    printf("请按回车继续");
                    while(getchar()=='\n')
                    {
                        getchar()!='\n';
                        break;
                    }
                    system("clear");
                    break;
                case 4:
                    
                    //更换商品
                    //更换商品功能
                    shopcartData(product,shopcart);
                    system("clear");
                    break;
                case 5:
                    
                    //退还商品
                    printf("请输入需要删除的商品名称：");
                    scanf("%s",deletecart.product_name);
                    //删除操作
                    flist_deleteNode(&shopcart, deletecart);
                    system("clear");
                    break;
                case 6:
                    
                    //结算商品
                    printf("本次总消费：%.2f元\n",shopcartSum(shopcart,root,&user_data));
                    printf("请按回车继续");
                    while(getchar()=='\n')
                    {
                        getchar()!='\n';
                        break;
                    }
                    system("clear");
                    break;
                case 7:
                    
                    //个人中心
                    printf("|%-15s|%-15s|%-15d|%-20s|%-15s|%-15d|%-15.2f|%-30s| \n",user_data.account,user_data.password,user_data.permissions,user_data.name,user_data.sex,user_data.integral,user_data.sum_money,user_data.signature);
                            //将修改的数据更新到链表中
                    USER data;
                    strcpy(data.account,user_data.account);
                    stree_updatecart(root,data,user_data);
                    printf("————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
                    while(getchar()=='\n')
                    {
                        getchar()!='\n';
                        break;
                    }
                    system("clear");
                    break;
                default :
                    puts("输入错误，请重新输入");
                    break;
            }
        }
        else if (user_n == 0)
        {
            //清空链表退出
            flist_clear(&shopcart);
            break ;
        }
        else
        {
            puts("输入错误");
            return ;
        }
    }

}

//用户登录功能实现；
void function_rootmenu(STREE* root,FLIST* product,FLIST* shopcart,NODE* user_head,NODE* root_head)
{
    USER user_data;
    GOODS product_data;
    DATA posData,root_data;
    //初始化信息
    //DATA data12 = {"添加功能"};
    //doulist_addTail(&root_head,data12);
    // DATA user_start = {"查看商品信息"};
    // doulist_create(user_start,&user_head);
    // DATA root_data1 =  {"删除用户菜单"};
    // doulist_deleteNode(&root_head,root_data1);
    // DATA user_data1 =  {"消费总计"};
    // doulist_deleteNode(&user_head,user_data1);
    int n = 0;
    printf("请输入您需要进行的操作：");
    scanf("%d",&n);
    if(n == 1)
    {   
        //登录校验
        //USER data1;
        printf("请输入您的账号：");
        scanf("%s",user_data.account);
        printf("请输入您的密码：");
        scanf("%s",user_data.password);
        while(getchar()!='\n');
        //比较账号密码信息
        STREE* flag= stree_searchdata(root,user_data);
        int acc = strcmp(flag->data.account,user_data.account);
        int pass = strcmp(flag->data.password,user_data.password);
        if(acc == 0 && pass == 0)
        {
            user_data = flag->data;
            system("clear");
            //账号密码正确，权限验证
            if(user_data.permissions == 0)
            {
                while(1)
                {
                    //打印root用户菜单
                    //printf_Supermenu(root_head);
                    doulist_showAll(root_head);
                    //root功能菜单
                    int n = 0;
                    printf("请输入需要进行的操作");

                    scanf("%d",&n);
                    if(n == 0)
                    {
                        break ;
                    }
                    switch(n)
                    {
                        case 1:
                            //用户管理                      
                            user_manage(root);
                            system("clear");
                            break;
                        case 2:
                            //添加商品信息
                            product_insert(&product,product_data);
                            system("clear");
                            break;
                        case 3:
                            //修改商品信息
                            product_update(product,product_data);
                            system("clear");
                            break;
                        case 4:
                            //查询商品信息
                            product_select(product);
                            printf("请按回车继续");
                            while(getchar()=='\n')
                            {
                                getchar()!='\n';
                                break;
                            }   
                            system("clear");
                            break;
                        case 5:
                            //删除商品信息                           
                            //flist_deleteNode(FLIST **head,GOODS posData);
                            product_delete(&product);
                            system("clear");
                            break;
                        case 6:       
                            //root用户功能菜单添加                     
                            root_menu(root_head);
                            system("clear");
                            break;
                        case 7:       
                            //普通用户功能菜单添加                   
                            user_menu(user_head);
                            system("clear");
                            break;
                        default :
                            puts("输入错误，请重新输入");
                            break; 
                    }
                }
            } 
            else if(user_data.permissions == 1)
            {  //打印普通用户菜单
                doulist_showAll(user_head);
                system("clear");
                shop_cart(shopcart,product,root,user_head,user_data);
            }
        }
        else
        {
            if(acc!=0)
            {
                puts("账号错误");
                return ;
            }
                
            else if(pass!= 0)
            {
                puts("密码错误");
                return ;
            }
        }
    }
    else if(n == 2)
    {
        root_registered(&root);
    }
    else   
    {
        puts("输入错误，请重新输入");
    } 
}