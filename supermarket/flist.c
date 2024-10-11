#include "flist.h"

//d定义函数---在循环链表中找尾部节点
static FLIST* flist_findtail(FLIST* head)
{
    if (head == NULL)
    {
        puts("链表为空");
        return NULL;
    }
    //定义当前指针指向头节点
    FLIST* current = head;
    while (current->next != head)
    {
        current =current->next;
    }
    //此时current指向最后一个节点
    return current;    
}


//创建链表头节点
int flist_create(GOODS data,FLIST** head)
{
    //校验头结点是否存在
    if (*head != NULL)
    {
        //头节点的地址存在，不需要创建
        puts("头节点已存在");
        return -1;
    }
    //头节点的地址为空，头节点不存在
    //申请内存
    FLIST * pNew = (FLIST*)malloc(sizeof(FLIST));
    if (!pNew)
    {
        perror("memory apply failed");
        return -1;
    }
    //给新节点的成员初始化
    pNew->data = data;
    pNew->next = NULL;
    //将新节点作为头节点
    *head = pNew;
    //头节点的后驱指针指向自己
    (*head)->next = *head;
    //返回成功标记
    return 0;
    
}

// 交换两个节点的内容  
void swap(FLIST *a, FLIST *b) {  
    GOODS temp = a->data;  
    a->data = b->data;  
    b->data = temp;  
}  
  
// 冒泡排序对链表进行排序  
void bubbleSort(FLIST *head) {  
    int swapped;  
    FLIST *current;  
    FLIST *end = NULL;  
  
    if (head == NULL)  
        return;  
  
    do {  
        swapped = 0;  
        current = head;  
  
        while (current->next != end) {  
            if (current->data.product_num > current->next->data.product_num) {  
                swap(current, current->next);  
                swapped = 1;  
            }  
            current = current->next;  
            if(current == head)
                break;
        } 
        if (swapped)
        {
            end = current; 
        }
         
         
    } while (swapped);  
} 

//遍历链表中节点中的数据
void flist_showAll(FLIST* head)
{
    //定义当前指针指向指向头节点
    FLIST * current =head;
    if(current ==NULL)
    {
        puts("flist is empty");
        return ;
    }
    bubbleSort(current);

    printf("———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
    char n[6][20] = {"产品编号","产品名称","产品单价","产品数量","产品类别","产品积分"};
    printf("|%-24s|%-24s|%-24s|%-24s|%-24s|%-24s| \n",n[0],n[1],n[2],n[3],n[4],n[5]);
    printf("———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");

    while (current != NULL)
    {
        
        printf("|%-20d|%-22s|%-20lf|%-20d|%-22s|%-20d \n",current->data.product_num,current->data.product_name,current->data.product_price,current->data.product_amount,current->data.product_category,current->data.product_integral);
        printf("———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
        //移动当前指针到下一个节点
        current = current->next;
        //校验当前指针是否头节点
        if(current == head)
            break;
    }
    printf("\n");
    return ;
}

//插入数据
int flist_insert(FLIST **head,GOODS data)
{
    //申请内存
    FLIST* pNew = (FLIST*)malloc(sizeof(FLIST));
    //非空校验
    if (!pNew)
    {
        perror("内存申请失败");
        return -1;
    }
    //初始化新节点中的成员
    pNew->data = data;
    pNew->next = NULL;
    //判断头节点是否存在    
    if (*head == NULL)
    {
        //头节点不存在      1.新节点作为头节点  2.回收新节点，提示并返回
        /*
        //2.回收新节点，提示并返回
        puts("链表为空");
        free(pNew);
        pNew= NULL;
        return -1;
        */
        //1.新节点作为头节点
        *head = pNew;
        //自己的next指向自己
        (*head)->next = *head;
        //返回成功标记
        return 0;
    }
    //找到尾部节点,调用函数
    FLIST* tailNode = flist_findtail(*head);
    //尾节点的后驱指针指向新节点
    tailNode->next = pNew;
    //新节点的后驱指针指向原头节点
    pNew->next = *head;
    //新节点作为头节点
    *head = pNew;
    //返回成功标记
    return 0;
}


//插入数据--中间插入（在指定数据的位置插入）
int flist_addMiddle(FLIST **head,GOODS data, GOODS posData)
{
    //判断头节点是否存在
    if (*head ==NULL)
    {
        //头节点不存在，链表为空
        puts("flist is empty");
        return -1;  //返回失败标记
    }
    //创建新节点
    FLIST* pNew = (FLIST*)malloc(sizeof(FLIST));
    //非空校验
    if(!pNew)
    {
        perror("memory apply failed");
        return -1;
    }
    //初始化新节点中的成员
    pNew->data =data;
    pNew->next = NULL;
    //初始化当前指针和尾随指针
    FLIST* current = *head;
    FLIST* follow = flist_findtail(*head);
    while (current->next!=*head)
    {
        if (memcmp(&(current->next),&posData,sizeof(GOODS))==0)
        {
            //找到了要插入节点的位置
            pNew->next = current;
            follow->next = pNew;
            //插入成功
            return 0;
        }
        
        //指针尾随
        follow = current;
        current = current->next;
    }
    //current指向尾部节点
    if (memcmp(&(current->next),&posData,sizeof(GOODS))==0)
    {
        //要插入的位置在尾节点的前方
        pNew->next = current;
        follow->next =pNew;
        return 0;
    }
    //在链表中没有找到要插入的位置，    1.添加到链表末尾    2.回收内存，返回失败标记
    puts("posData不存在");
    free(pNew);
    pNew = NULL;
    return -1;
}

//查询链表--根据指定数据查询该数据在链表中的节点，并返回该节点的地址
FLIST * flist_findNode(FLIST* head,GOODS posData)
{
    if(head == NULL)
    {
        //头节点为空,链表中没有节点
        puts("链表中没有节点");
        return NULL;
    }
    //初始化当前指针指向头节点
    FLIST* current  = head;
    do
    {
        if (strcmp(current->data.product_name,posData.product_name)==0)
        {
            //在链表中找到查询的数据
            return current;
        }
        //移动当前指针指向它的下一节点处
        current=current->next;
    } while (current!=head);
    //链表中没有找到要查询的数据
    //提示并返回
    puts("链表中没有找到要查询的数据");
    return NULL;
}

//查询链表--根据指定数据查询该数据在链表中的节点，并返回该节点的地址---根据商品编号比较信息
// 逻辑错误：在当前的实现中，如果第一个节点的数据不匹配 posData，函数就立即返回 NULL，而不会继续检查后续节点。这会导致无法正确遍历整个链表。
// 返回错误：即使第一个节点的数据不匹配，也不应立即返回 NULL。应当继续遍历链表直到回到头节点。
// 循环逻辑：do-while 循环的使用是正确的，因为这是一个环形链表，需要确保至少检查一次头节点。
// FLIST * flist_findNodenum(FLIST* head,GOODS posData)
// {
//     if(head == NULL)
//     {
//         //头节点为空,链表中没有节点
//         puts("链表中没有节点");
//         return NULL;
//     }
//     //初始化当前指针指向头节点
//     FLIST* current  = head;
//     do
//     {
//         if (current->data.product_num==posData.product_num)
//         {
//             //在链表中找到查询的数据
//             return current;
//         }
//         else
//         {
//             return NULL;
//         }
//         //移动当前指针指向它的下一节点处
//         current=current->next;
//     } while (current!=head);
//     //链表中没有找到要查询的数据
//     //提示并返回
//     puts("链表中没有找到要查询的数据");
//     return NULL;
// }
FLIST* flist_findNodenum(FLIST* head, GOODS posData)
{
    if(head == NULL)
    {
        // 头节点为空,链表中没有节点
        puts("链表中没有节点");
        return NULL;
    }
    // 初始化当前指针指向头节点
    FLIST* current = head;
    do
    {
        if (current->data.product_num == posData.product_num)
        {
            // 在链表中找到查询的数据
            return current;
        }
        // 移动当前指针指向它的下一节点处
        current = current->next;
    } while (current != head);
    // 链表中没有找到要查询的数据
    // 提示并返回
    puts("链表中没有找到要查询的数据");
    return NULL;
}


//修改操作--根据指定的数据查找在链表中的节点，并用新的数据修改该节点上的数据
int flist_updateNode(FLIST* head, GOODS posData,GOODS newData)
{
    //调用查询函数，获取被修改数据所在节点的地址
    FLIST* updatedata = flist_findNode(head,posData);
    //判断返回结果是否为空
    if(updatedata == NULL)
    {
        return -1;
    }
    else    //在链表中查找到被修改节点所在的位置
    {
        //用新的数据覆盖节点上的数据
        updatedata->data = newData;
        //返回成功标记
        return 0;
    }
    
}

//换货操作
//修改操作--根据指定的数据查找在链表中的节点，并用新的数据修改该节点上的数据
int flist_updateCart(FLIST* head, GOODS posData,GOODS newData)
{
    //调用查询函数，获取被修改数据所在节点的地址
    FLIST* updatedata = flist_findNodenum(head,posData);
    //判断返回结果是否为空
    if(updatedata == NULL)
    {
        return -1;
    }
    else    //在链表中查找到被修改节点所在的位置
    {
        //用新的数据覆盖节点上的数据
        updatedata->data.product_num         = newData.product_num;
        strcmp(updatedata->data.product_name,newData.product_name);
        updatedata->data.product_price       = newData.product_price;
        strcmp(updatedata->data.product_category,newData.product_category);
        updatedata->data.product_integral    = newData.product_integral;
        //返回成功标记
        return 0;
    }
    
}

//添加数据到购物车 head是原始商品信息头节点，shopcart是购物车信息头节点，posdata是需要查询的原始商品信息；
int flist_insertshopCart(FLIST* head, FLIST** shopcart ,GOODS posData,int porduct_number)
{

    //调用查询函数，获取被插入数据所在节点的地址
    FLIST* insert_shop = flist_findNodenum(head,posData);
    //判断返回结果是否为空
    if(insert_shop == NULL)
    {
        return -1;
    }
    else    //在链表中查找到被修改节点所在的位置
    {
        //用新的数据覆盖节点上的数据
        // updatedata->data = newData;
        insert_shop->data.product_amount = porduct_number;
        flist_insert(shopcart,insert_shop->data);
        //返回成功标记
        return 0;
    }
    
}

//清空链表--清空链表中的所有节点
void flist_clear(FLIST **head)
{
    if(*head == NULL)
    {
        //头节点不存在，链表为空
        puts("flist is empty");
        return ;
    }
    //定义当前指针
    FLIST* current = *head;
    //定义临时变量，记录要删除节点的下一个节点地址
    FLIST* currentNext = NULL;
    while (current!= NULL&&current->next != *head)
    {
        //当前链表中最少有两个节点
        currentNext = current->next;
        //测试代码
        //printf("----data:%d\n",current->data);
        //回收当前指针指向的节点
        free(current);
        //current = NULL;   //可以省略
        current = currentNext;
    }
    //测试代码
    //printf("data:%d\n",current->data);
    //回收唯一的头节点
    free(current);
    current = NULL;
    *head = NULL;
}

//删除操作
int flist_deleteNode(FLIST **head,GOODS posData)
{
    if(*head == NULL)
    {
        //头节点不存在，链表为空
        puts("flist is empty");
        return -1;
    }
    //调用函数获取尾部节点
    FLIST* tailNode = flist_findtail(*head);
    //初始化当前指针和尾随指针
    FLIST* current = *head;
    FLIST* follow = NULL;
    //循环遍历链表
    while (current!=NULL)
    {
        if (strcmp(current->data.product_name,posData.product_name)==0)
        {
            //在链表中找到了需要删除的节点
            if (current == *head&&current->next ==*head)
            {
                //free(current);
                //current = NULL;
                //要删除的接电视唯一的头节点
                *head = NULL;
                //return 0;
            }
            else if(follow == NULL)
            {
                //要删除的是头节点，但头节点不是链表中的唯一节点
                *head = current->next; //当前节点的下一个节点作为新的头节点
                tailNode->next = *head; //尾部节点的后驱指针指向新的头节点
                //free(current);
                //current = NULL;
                //return 0;
            }
            else
            {
                //链表中至少有两个节点，并且删除的不是头节点
                //尾随指针的后驱指针指向当前节点的下一个节点处
                follow->next = current->next;
                //free(current);
                //current = NULL;
                //return 0;
            }
            free(current);
            current = NULL;
            return 0;
        }
        //指针尾随
        follow = current;
        current = current->next;  
        //当前指针再次移动到头节点处，证明循环结束，break跳出循环 
        if (current == *head)
            break;
    }
    //在链表中没有找到要删除的数据的节点，提示并返回失败标记
    puts("posData is not exist");
    return -1;
}

//计算总价
double flist_priceSum(STREE* root,FLIST* shopcart,USER* user_data)
{
    //需要通过sum累加购物车中的物品价格，判断用户积分是否达条件，获取当前用户信息，将用户信息赋值 
    //定义price_sum(double),integral_sum(int)
    double price_sum = 0;//商品价格
    int integral_sum = user_data->integral;//积分求和
    double value_sum = user_data->sum_money;
    //遍历链表中的数据，对商品进行计价，求和积分
    //定义当前指针指向指向头节点
    FLIST * current = shopcart;
    if(current ==NULL)
    {
        puts("flist is empty");
        return 0;
    }
    do
    {
        price_sum = price_sum+ current->data.product_price*(double)current->data.product_amount;
        integral_sum =  integral_sum +current->data.product_amount*current->data.product_integral;
        value_sum = price_sum+value_sum;
        //移动当前指针到下一个节点
        current = current->next;
    } while (current != shopcart);//判断当前指针不是头节点，就执行循环体语句
    user_data->integral = integral_sum;
    user_data->sum_money = value_sum;
    return price_sum;
}