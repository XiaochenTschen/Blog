#include<iostream>
#include<vector>

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

    ListNode* ans = dummyHead->next;
    delete dummyHead;
    return ans;
}

void printList(ListNode* listHead)
{
    while(listHead)
    {
        std::cout << listHead->val << ", ";
        listHead = listHead->next;
    }
    std::cout << '\n';
}

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode *slow = dummyHead, *fast = dummyHead;
        while(n >= 0)
        {
            fast = fast->next;
            --n;
        }
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        ListNode* ans = dummyHead->next;
        delete nodeToDelete;
        delete dummyHead;
        return ans;
    }
};

int main()
{
    std::vector<int> nums{1,2,3,4,5};
    int n = 2;
    Solution sol;
    ListNode* head = createList(nums);
    ListNode* ans = sol.removeNthFromEnd(head, n);

    std::cout << "ans: ";
    printList(ans);

    return 0;
}