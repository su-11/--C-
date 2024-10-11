# include "doulist.h"

//创建新节点
static NODE* initNewNode(DATA data)
{
    //申请内存空间
    NODE* pNew = (NODE*)malloc(sizeof(NODE));
    //非空校验
    if(!pNew)
    {
        perror("内存申请失败");
        return NULL;
    }
    //新节点成员初始化
    pNew->data = data;
    pNew->prev = NULL;
    pNew->next = NULL;
    //返回新节点地址
    return pNew;
}

//创建链表的头节点--以返回值的形式返回头节点地址

int doulist_create(DATA data,NODE **head)
{
    //创建新节点
    NODE* pNew = (NODE*)malloc(sizeof(NODE));
    //非空校验
    if (!pNew)
    {
        perror("内存创建失败");
        return -1;//返回失败标记
    }
    //初始化节点中的成员
    pNew->data = data;
    pNew->prev = NULL;
    pNew->next = NULL;
    //通过形式参数返回新节点的地址
    *head = pNew;
    return 0;//返回成功标记0；   
}

//插入数据--头插法
int doulist_addHead(NODE **head,DATA data)
{
    //申请内存空间
    NODE* pNew = (NODE*)malloc(sizeof(NODE));
    //非空校验
    if (!pNew)
    {
        perror("内存申请失败");
        return -1;//返回插入失败的标记-1；
    }
    //给新节点的成员初始化
    pNew->data =data;
    pNew->prev = NULL;
    pNew->next = NULL;
    /*
    //校验头节点是否存在，如果不存在就有两种处理方式：将新节点作为头节点，回收新节点地址，并返回失败标记
    if (*head == NULL)
    {
        //头节点不存在，将新节点作为头节点
        *head = pNew;
        return 0;
    }
    //头结点存在
    //新节点后驱指向原来的头节点
    pNew->next = *head;
    //原来的头节点的前驱指针指向新节点
    (*head)->prev = pNew;
    //新节点作为新的头节点
    *head = pNew;
    //返回成功标记
    return 0;
    */
    /*
        //校验头节点是否存在，如果不存在就有两种处理方式：将新节点作为头节点，回收新节点地址，并返回失败标记
    if (*head == NULL)
    {
        //头节点不存在，将新节点作为头节点
        *head = pNew;
        return 0;
    }
    //头结点存在
    //新节点后驱指向原来的头节点
    pNew->next = *head;
    //原来的头节点的前驱指针指向新节点
    (*head)->prev = pNew;
    //新节点作为新的头节点
    *head = pNew;
    //返回成功标记
    return 0;
    */
    if (*head != NULL)
    {
        //头结点存在
        //新节点后驱指向原来的头节点
        pNew->next = *head;
        //原来的头节点的前驱指针指向新节点
        (*head)->prev = pNew;
    }
    //新节点作为新的头节点
    *head = pNew;
    //返回成功标记
    return 0;

}

//插入数据--尾插法
int doulist_addTail(NODE **head,DATA data)
{
    //申请内存空间
    NODE* pNew = (NODE*)malloc(sizeof(NODE));
    //非空校验
    if(!pNew)
    {
        perror("内存申请失败");
         return -1;
    }
    //新节点成员初始化
    pNew->data = data;
    pNew->prev = NULL;
    pNew->next = NULL;

    //定义当前指针指向头节点
    NODE* current = *head;
    //判断头节点是否存在
    if(current ==NULL)
    {
        //头指针为空：头节点不存在，链表为空
        //1.头节点不存在，新节点作为头节点
        //2.头节点不存在，提示用户，回收新节点，返回失败标记
        // puts("头节点不存在，链表为空");
        // //回收
        // free(pNew);
        // pNew =NULL;
        // //返回失败标记
        // return -1;
        //头节点不存在，将新节点作为头节点
        *head = pNew;
        return 0;
    }
    //头结点存在
    while (current->next != NULL)
    {
        //当前指针就移动到它的下一个节点处
        current = current->next;
    }
    //当前指针就执行了尾节点
    //当前指针指向的节点的后驱指针存储新节点的地址
    current->next = pNew;
    //新节点的前驱指针指向了当前节点
    pNew->prev = current;
    //返回成功标记
    return 0;
}

//插入数据--中间插入（在指定数据的位置插入）
int doulist_addMiddle(NODE **head,DATA data, DATA posData)
{
    NODE* pNew = initNewNode(data);
    if (!pNew)
        return -1;
    //校验头节点是否存在
    if(*head == NULL)
    {
        //头节点不存在，链表为空
        puts("头节点不存在，链表为空");
        //返回插入失败的标记
        return -1;
    }
    //头结点存在
    //初始化当前指针和尾随指针
    NODE * current = *head;
    NODE* follow = NULL;
    //遍历链表中的节点
    while (current!= NULL)
    {
        //当前节点上的数据和指定的数据是否相同
        if (memcmp(&(current->data),&data,sizeof(DATA))==0)
        {
            //链表中找到了要插入节点的位置
            //判断当前指针是否指向了头节点
            if(follow == NULL)
            {
                //当前指针指向了头节点
                //新节点的后驱指针指向原来的头节点
                //pNew->next = *head;     //pNew->next = current;
                //原来的头节点的前驱指针指向新节点
                //(*head)->prev = pNew;   //等效    //current->prev = pNew;
                //新节点作为新的头节点
                *head = pNew;
                
            }else
            {
                //新节点的后驱指针指向当前节点
                //pNew->next = current;
                //新节点的前驱指针指向当前节点的前一个节点
                pNew->prev = follow;
                //当前节点的前一个节点的后驱指针指向新节点
                follow->next = pNew;
                //当前节点的前驱指针指向新节点
                //current->prev = pNew;
            }
            //新节点的后驱指针指向当前节点
            pNew->next = current;
            //当前节点的前驱指针指向新节点
            current->prev = pNew;
            //插入成功，返回成功标记0；
            return 0;
        }
        //指针尾随
        //尾随指针移动到当前指针的位置
        follow = current;
        //当前指针移动到下一个节点处
        current = current->next;
        
    }
    //此时current指向空，follow指向链表的尾节点
    //链表中没有找到posData，两种处理方案：新节点插入到链表的末尾； 回收新节点，返回失败标记
    //新节点插入到链表的末尾
    // follow->next = pNew;//尾节点的后驱指针指向新节点
    // pNew->prev = follow;//新节点的后驱指针指向尾节点
    // return 0;
    // 回收新节点，返回失败标记
    puts("没有找见posData");
    free(pNew);
    pNew = NULL;
    //返回失败标记
    return -1;
}

//删除操作
int doulist_deleteNode(NODE **head,DATA posData)
{
    //判断头节点是否为空
    if (*head == NULL)
    {
        //头节点不存在，链表为空
        puts("头节点不存在，链表为空");
        return -1;
    }
    //初始化当前指针指向头节点
    NODE* current = *head;
    //循环遍历链表中的节点
    while (current != NULL)
    {
        //判断当前节点上的数据和要删除的数据是否相同
        if(strcmp(current->data.name,posData.name)== 0)
        {
            
            if (current->prev == NULL)
            {
                //当前指针指向的节点的前驱指针为空，证明该节点是头节点（要删除的是头节点）
                if (current->next == NULL)
                {
                    //当前要删除的节点是链表中的唯一节点
                    *head = NULL;
                }
                else    //当前要删除的节点不是头节点
                {
                    *head = current->next;
                    current->next->prev = NULL;
                }
            }
            else    //要删除的是中间节点或者尾部节点
            {
                if (current->next == NULL)
                {
                    //要删除的是尾部节点
                    current->prev->next = NULL;
                }
                else    //要删除的是中间节点
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                
            }
            //公共代码
            free(current);
            current =NULL;
            //返回成功标记
            return 0;
            
        }
        //指针移动
        current = current->next;
    }
    //在链表中没有找到要删除的数据
    puts("posData在链表中不存在");
    //返回失败标记
    return -1;
    
}

//查询链表--根据指定数据查询该数据在链表中的节点，并返回该节点的地址
int doulist_findNode(NODE* head,DATA posData,NODE** findNode)
{
    //头结点是否存在
    if (head == NULL)
    {
        //头节点不存在，链表为空
        puts("链表为空");
        //通过形式参数返回NULL给调用者
        *findNode= NULL;
        //返回失败标记
        return -1;
    }
    //头结点存在，定义当前指针指向头节点
    NODE* current = head;
    while (current != NULL)
    {
        //判断当前节点上的数据和要查询数据是否相同
        if (memcmp(&(current->data),&posData,sizeof(DATA))==0)  
        {
            //找到需要查询的数据的节点
            *findNode = current; //以形式参数返回需要查找的地址
            return 0;//返回成功标记
        }
        //移动当前指针到下一个节点处
        current = current->next;
        
    }
    //如果需要查找的数据没找到，返回失败标记
    puts("需要查询的数据不存在");
    *findNode = NULL;
    return -1;
}

//修改操作--根据指定的数据查找在链表中的节点，并用新的数据修改该节点上的数据
int doulist_updateNode(NODE* head, DATA posData,DATA newData)
{
    //调用查找函数int doulist_findNode(NODE* head,DATA posData,NODE** findNode)
    NODE* findNode = NULL;
    doulist_findNode(head,posData,&findNode);
    if (findNode == NULL)
    {
        //findNode为空，未找到修改数据
        return -1;// 修改失败
    }
    //findNode不为空，修改该节点上的数据
    findNode->data = newData;
    //返回成功标记
    return 0;
    
}

//清空链表--清空链表中的所有节点
void doulist_clear(NODE **head)
{
    //初始化当前指针和尾随指针
    NODE* current = *head;
    NODE* follow = NULL;
    //判断当前指针是否为空
    while(current != NULL)
    {
        //当前指针指向的节点存在
        //尾随指针移动当前指针指向的节点处
        follow = current;
        //当前指针移动到下一节点处
        current = current->next;
        //回收尾随指针所在节点
        free(follow);
        follow = NULL;
    }
    //头节点也为空
    *head = NULL;
}

//遍历链表中节点中的数据
void doulist_showAll(NODE* head)
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
    int n =0;
    printf("\n\n\n\n\n");
    printf("                    \033[1;34;47m                                                        \033[m\n");
    printf("                    \033[1;34;47m ✿ --------------------------------------------------✿  \033[m\n");
    printf("                    \033[1;34;47m |--------------------^_^主菜单^_^--------------------| \033[m\n");
    printf("                    \033[1;34;47m |----------------------------------------------------| \033[m\n");
    while (current!=NULL)
    {
        //当节点不为空，取当前节点数据
    printf("                    \033[1;34;47m |------------------%2d:%-16s-------------------| \033[m\n",n+1 , current->data.name);

        current = current->next;
        ++n;
    }
    printf("                    \033[1;34;47m |----------------------------------------------------| \033[m\n");
    printf("                    \033[1;34;47m |-----------------输入操作： (0)退出-----------------| \033[m\n");
    printf("                    \033[1;34;47m ✿ --------------------------------------------------✿  \033[m\n");
    printf("                    \033[1;34;47m                                                        \033[m\n");
    printf("\n");
}
