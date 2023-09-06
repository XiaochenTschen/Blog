链表这个数据结构在平时工作中很少见到，更不用说用到了。之前刷题的时候会做一些链表相关的题目，做题的时候会复习一下链表相关的内容，但是时间一长就容易遗忘，每次遇到链表都觉得像是全新的知识点一样，现在借助阅读FreeRTOS源码的机会，把我认为重要的知识点总结一下。
首先，通俗一点来说，链表就是一个个节点通过某种方式连接起来，形成像链条一样的东西。在这个通俗的表示中已经提出了两个重要的点：节点和节点的连接方式。

```c
struct xLIST_ITEM
{
    listFIRST_LIST_ITEM_INTEGRITY_CHECK_VALUE           
    configLIST_VOLATILE TickType_t xItemValue;          
    struct xLIST_ITEM * configLIST_VOLATILE pxNext;     
    struct xLIST_ITEM * configLIST_VOLATILE pxPrevious; 
    void * pvOwner;                                     
    struct xLIST * configLIST_VOLATILE pxContainer;     
    listSECOND_LIST_ITEM_INTEGRITY_CHECK_VALUE
};
typedef struct xLIST_ITEM ListItem_t; 
```
上面这个例子就是FreeRTOS里面对链表节点的定义，这里面最重要的就是那两个指向链表节点的指针，一个表示下一个节点next，一个表示之前的节点previous，正是这两个指针让不同的节点连接起来成为了可能。节点里面其他的成员表示节点的信息，这些要根据项目需求而定，比如在这里pvOwner指针指向拥有该节点的对象，pxContainer指向该节点所属的链表，这些都在任务调度的时候非常有用。

```c
typedef struct xLIST
{
    listFIRST_LIST_INTEGRITY_CHECK_VALUE      
    volatile UBaseType_t uxNumberOfItems;
    ListItem_t * configLIST_VOLATILE pxIndex; 
    MiniListItem_t xListEnd;                  
    listSECOND_LIST_INTEGRITY_CHECK_VALUE     
} List_t;
```
上面这段代码定义了一个链表结构，里面最重要的是定义了一个指向链表项的指针pxIndex，还有指向链表终端节点的xListEnd（处于节省内存的考虑这里用了一个简化版的节点）。
其实要创建一个链表，比如做题过程中，是不需要单独定义一个链表结构体的，只要知道链表的开始节点，就可以通过给节点指针赋值让不同的节点串起来，在这里使用链表结构体是为了更方便地管理链表。

有了这些基本的知识后就要使用链表，使用地过程离不开几个最重要的点：初始化，增，删，查，改。

先说初始化，对于节点地初始化其实很简单，在这里直接设置该节点不属于任何链表即可。
```c
void vListInitialiseItem( ListItem_t * const pxItem )
{
    pxItem->pxContainer = NULL;

    listSET_FIRST_LIST_ITEM_INTEGRITY_CHECK_VALUE( pxItem );
    listSET_SECOND_LIST_ITEM_INTEGRITY_CHECK_VALUE( pxItem );
}
```
对于链表地初始化，需要设置地值稍微多一些。
```c
void vListInitialise( List_t * const pxList )
{

    pxList->pxIndex = ( ListItem_t * ) &( pxList->xListEnd ); 

    pxList->xListEnd.xItemValue = portMAX_DELAY;

    pxList->xListEnd.pxNext = ( ListItem_t * ) &( pxList->xListEnd );     
    pxList->xListEnd.pxPrevious = ( ListItem_t * ) &( pxList->xListEnd ); 

    pxList->uxNumberOfItems = ( UBaseType_t ) 0U;

    listSET_LIST_INTEGRITY_CHECK_1_VALUE( pxList );
    listSET_LIST_INTEGRITY_CHECK_2_VALUE( pxList );
}
```
代码首先把链表遍历用地指针pxIndex指向链表地尾节点，把跟后续节点插入需要用到的值xItemValue设置为最大，然后让尾节点地前后指针都指向自己用以表示链表为空，然后将链表中节点地数量设置为0.

在链表里面进行增删查改其实逻辑大部分是相通地，通过某种遍历方式找到节点的位置，然后对前后指针做适当的操作就可以达到想要的目的，具体的操作可以去到代码中理解。
```c
/*直接在链表最后插入，在这里的意思是插入到遍历指针的后面*/
void vListInsertEnd( List_t * const pxList, ListItem_t * const pxNewListItem )
{
    /*先获得该链表的遍历指针*/
    ListItem_t * const pxIndex = pxList->pxIndex;

    listTEST_LIST_INTEGRITY( pxList );
    listTEST_LIST_ITEM_INTEGRITY( pxNewListItem );
    /*调整指针指向的对象*/
    pxNewListItem->pxNext = pxIndex;
    pxNewListItem->pxPrevious = pxIndex->pxPrevious;

    mtCOVERAGE_TEST_DELAY();
    /*调整指针对象*/
    pxIndex->pxPrevious->pxNext = pxNewListItem;
    pxIndex->pxPrevious = pxNewListItem;
    /*记录节点属于哪个链表*/
    pxNewListItem->pxContainer = pxList;
    /*链表节点数加一*/
    ( pxList->uxNumberOfItems )++;
}

/*根据节点的xItemValue来确定在什么位置插入节点，增加了一个寻找位置的过程*/
void vListInsert( List_t * const pxList, ListItem_t * const pxNewListItem )
{
    ListItem_t * pxIterator;
    const TickType_t xValueOfInsertion = pxNewListItem->xItemValue;

    listTEST_LIST_INTEGRITY( pxList );
    listTEST_LIST_ITEM_INTEGRITY( pxNewListItem );

    if( xValueOfInsertion == portMAX_DELAY )
    {
        pxIterator = pxList->xListEnd.pxPrevious;
    }
    else
    {

        for( pxIterator = ( ListItem_t * ) &( pxList->xListEnd ); pxIterator->pxNext->xItemValue <= xValueOfInsertion; pxIterator = pxIterator->pxNext ) 
        {
        }
    }

    pxNewListItem->pxNext = pxIterator->pxNext;
    pxNewListItem->pxNext->pxPrevious = pxNewListItem;
    pxNewListItem->pxPrevious = pxIterator;
    pxIterator->pxNext = pxNewListItem;

    pxNewListItem->pxContainer = pxList;

    ( pxList->uxNumberOfItems )++;
}

/*删除节点的话，可以通过节点本身找到节点所属的链表，操作指针让节点从链表中移除*/
/*移除的时候需要注意，如果链表的遍历指针刚好指向待移除的节点，需要先更新遍历指针*/
UBaseType_t uxListRemove( ListItem_t * const pxItemToRemove )
{
    List_t * const pxList = pxItemToRemove->pxContainer;

    pxItemToRemove->pxNext->pxPrevious = pxItemToRemove->pxPrevious;
    pxItemToRemove->pxPrevious->pxNext = pxItemToRemove->pxNext;

    mtCOVERAGE_TEST_DELAY();

    /* Make sure the index is left pointing to a valid item. */
    if( pxList->pxIndex == pxItemToRemove )
    {
        pxList->pxIndex = pxItemToRemove->pxPrevious;
    }
    else
    {
        mtCOVERAGE_TEST_MARKER();
    }

    pxItemToRemove->pxContainer = NULL;
    ( pxList->uxNumberOfItems )--;

    return pxList->uxNumberOfItems;
}
```