#include<iostream>
#include<vector>
#include<iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummyHead = new ListNode();
        ListNode* current = dummyHead;
        int flag = 0;
        while(l1 != nullptr || l2 != nullptr)
        {
            int a = 0, b = 0;
            if(l1 != nullptr)  a = l1->val;
            if(l2 != nullptr)  b = l2->val;

            int val = (a+b+flag)%10;
            current->next = new ListNode(val);
            current = current->next;

            flag = (a+b+flag)/10;
            if(l1 != nullptr)   l1 = l1->next;
            if(l2 != nullptr)   l2 = l2->next;
        }
        if(flag != 0)
        {
            current->next = new ListNode(flag);
        }

        ListNode* ans = dummyHead->next;
        delete dummyHead;
        return ans;
    }
};

ListNode* createList(std::vector<int>& nums)
{
    ListNode* dummyHead = new ListNode();
    ListNode* current = dummyHead;
    for(int num:nums)
    {
        ListNode* nextNode = new ListNode(num);
        current->next = nextNode;
        current = nextNode;
    }
    ListNode* list = dummyHead->next;
    delete dummyHead;
    return list;
}

void printList(ListNode* node)
{
    while(node != nullptr)
    {
        std::cout << node->val << ", ";
        node = node->next;
    }
    std::cout << '\n';
}


int main()
{
    Solution sol;
    std::vector<int> nums1{9,9,9,9,9,9,9};
    std::vector<int> nums2{9,9,9,9};
    ListNode* l1 = createList(nums1);
    ListNode* l2 = createList(nums2);
    ListNode* ans = sol.addTwoNumbers(l1, l2);

    std::cout << "ans: ";
    printList(ans);

    return 0;
}
