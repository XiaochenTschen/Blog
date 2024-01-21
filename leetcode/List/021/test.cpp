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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* dummyHead = new ListNode();
        ListNode *current = dummyHead, *current1 = list1, *current2 = list2;

        while(current1 || current2)
        {
            int a = current1?current1->val:101;
            int b = current2?current2->val:101;
            if(a < b)
            {
                current->next = new ListNode(a);
                if(current1)    current1 = current1->next;
            }
            else
            {
                current->next = new ListNode(b);
                if(current2)    current2 = current2->next;
            }
            current = current->next;
        }

        ListNode* ans = dummyHead->next;
        delete dummyHead;
        return ans;
    }
};

int main()
{
    Solution sol;
    std::vector<int> v1{1,2,4}, v2{1,3,4};
    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);
    ListNode* ans = sol.mergeTwoLists(l1, l2);
    std::cout << "ans: ";
    printList(ans);
    
    return 0;
}