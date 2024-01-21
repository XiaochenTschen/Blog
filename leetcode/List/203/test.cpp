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

class  Solution
{
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)   return head;
        while(head->val == val)
        {
            ListNode* tmp = head;
            head = head->next;
            if(!head)   return head;
            delete tmp;
        }
        ListNode* current = head;
        while(current&&current->next)
        {
            if(current->next->val == val)
            {
                ListNode* tmp = current->next;
                current->next = tmp->next;
                delete tmp;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums{7,7,7,7};
    ListNode* list = createList(nums);
    ListNode* ans = sol.removeElements(list, 7);
    std::cout << "ans: ";
    printList(ans);

    return 0;
}
