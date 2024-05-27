### List数据结构
List是由一些列node串联在一起的数据结构，对于最简单的单向链表来说，每一个node可以看作是一个结构体，该结构体包含两部分，数据部分和指向下一个node的指针部分。结构体的头元素是第一个有效元素，尾元素的next指针为空指针，意味着没有下一个元素。下面是一个简单的链表节点示例：
```c++
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
```

### List最常见的操作

对链表进行操作的时候，常用到的一些辅助手段包括：
1. 定义一个dummyHead，让该头节点指向链表的头节点。(这样更容易实现previous和current节点的概念)
2. 遍历链表节点信息的时候，可以利用previous和current节点来记录遍历的信息

#### reverseList
```c++
ListNode* reverseList(ListNode* list)
{
    if(list == nullptr || list->next == nullptr)
        return list;

    ListNode *prv = nullptr, *cur = list, *tmp = nullptr;
    while(cur)
    {
        tmp = cur->next;
        cur->next = prv;
        prv = cur;
        cur = tmp;
    }
    return prv;
}
```

#### delete node
```c++
/* for example, delete Nth node from end */
ListNode* deleteNttNodeFromEnd(ListNode* list, int N)
{
    ListNode *fast = list, *prv = new ListNode(0, list);
    ListNode *tmp = prv;
    for(; N > 0 && fast != nullptr; --N)
    {
        fast = fast->next;
    }
    while(fast)
    {
        fast = fast->next;
        prv = prv->next;
    }
    ListNode* nodeToDelete = prv->next;
    prv->next = nodeToDelete->next;
    delete nodeToDelete;
    return tmp->next;
}
```

#### merge two list
```c++
/* for example, merge two sorted list */
ListNode* mergeSortedList(ListNode* l1, ListNode* l2)
{
    ListNode* dummyHead = new ListNode();
    ListNode* tmp = dummyHead;
    while(l1 && l2)
    {
        if(l1->val > l2->val)
        {
            dummyHead->next = l2;
            l2 = l2->next;
        }   
        else
        {
            dummyHead->next = l1;
            l1 = l1->next;
        }
        dummyHead = dummyHead->next;    
    }

    if(l1) dummyHead->next = l1;
    if(l2) dummyHead->next = l2;

    ListNode* ans = tmp->next;
    delete tmp;
    return ans;
}
```

