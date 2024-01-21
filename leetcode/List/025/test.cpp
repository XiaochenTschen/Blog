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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        int len = count(head);
        if(len < k)    return head;
        int reverseCount = len/k;

        ListNode* prv = new ListNode(0, head);
        ListNode* newHead = prv;
        for(int i = 0; i < reverseCount; ++i)
        {
            ListNode* start = prv->next;
            ListNode* startPrv = prv;
            ListNode* cur = start;
            for(int j = 0; j < k; ++j)
            {
                ListNode* tmp = cur->next;
                cur->next = prv;
                prv = cur;
                cur = tmp;
            }
            start->next = cur;
            startPrv->next = prv;
            prv = start;
        }

        return newHead->next;
    }

private:
    int count(ListNode* head)
    {
        ListNode* cur = head;
        int ans = 0;
        while(cur)
        {
            ++ans;
            cur = cur->next;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums{1,2,3,4,5};
    ListNode* head = createList(nums);
    ListNode* ans = sol.reverseKGroup(head, 2);
    std::cout<< "ans: ";
    printList(ans);
    
    return 0;
}