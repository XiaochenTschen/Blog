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
    ListNode* partition(ListNode* head, int x)
    {
        if(head == nullptr || head->next == nullptr)    return head;
        ListNode *current = head, *smallCur = new ListNode(), *largeCur = new ListNode();
        ListNode *ans = smallCur, *largeHead = largeCur;
        while(current)
        {
            if(current->val < x)
            {
                smallCur->next = current;
                smallCur = current;
            }
            else
            {
                largeCur->next = current;
                largeCur = current;
            }
                current = current->next;
        }
        if(largeCur->next)  largeCur->next = nullptr;
        smallCur->next = largeHead->next;
        return ans->next;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums{1,4,3,2,5,2};
    ListNode* list = createList(nums);
    ListNode* ans = sol.partition(list, 3);
    std::cout << "ans: ";
    printList(ans);

    return 0;
}
