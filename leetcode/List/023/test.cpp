#include<vector>
#include<iostream>
#include<queue>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createList(std::vector<int>& nums)
{
    ListNode* dummyHead = new ListNode();
    ListNode* current = dummyHead;

    for(int num:nums)
    {
        current->next = new ListNode(num);
        current = current->next;
    }

    ListNode* head = dummyHead->next;
    delete dummyHead;
    return head;
}

void printList(ListNode* head)
{
    ListNode* current = head;
    while(current)
    {
        std::cout << current->val << " ,";
        current = current->next;
    }
    std::cout << '\n';
}

class Solution
{
public:
    ListNode*  mergeKLists(std::vector<ListNode*>& lists) 
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for(auto list:lists)
        {
            while(list)
            {
                pq.push(list->val);
                list = list->next;
            }
        }
        ListNode* dummyHead = new ListNode();
        ListNode* nodeToDelete = dummyHead;
        while(!pq.empty())
        {
            dummyHead->next = new ListNode(pq.top());
            dummyHead = dummyHead->next;
            pq.pop();
        }
        ListNode* ans = nodeToDelete->next;
        delete nodeToDelete;
        return ans;
    }
};

int main()
{
    return 0;
}