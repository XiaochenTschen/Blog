#include<vector>
#include<iostream>

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
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)    return head;
        ListNode* prv = new ListNode(0, head);
        ListNode* newHead = head->next;
        ListNode* current = head;
        while(current)
        {
            prv->next = current->next;
            current->next = prv->next->next;
            prv->next->next = current;
            prv = current;
            current = current->next;
        }
        return newHead;
    }
};

int main()
{
    Solution sol;
    std::vector<int> v1{1,2,3};
    ListNode* head = createList(v1);
    ListNode*ans = sol.swapPairs(head);
    printList(ans);
    
    return 0;
}