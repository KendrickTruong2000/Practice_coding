#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

int main(int argc, char const *argv[])
{
    ListNode *node8 = new ListNode(8);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    node8->next = node4;
    node4->next = node5;

    ListNode *list1 = new ListNode(4);
    list1->next = new ListNode(1);
    list1->next->next = node8;

    ListNode *list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(1);
    list2->next->next->next = node8;

    ListNode *result = getIntersectionNode(list1, list2);

    while (result)
    {
        cout << result->val << "->";
        result = result->next;
    }
    
    return 0;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
    {
        return nullptr;
    }
    
    ListNode *ptrA = headA;
    ListNode *ptrB = headB;

    while (ptrA != ptrB)
    {
        if (ptrA == nullptr)
        {
            ptrA = headB;
        }
        else
        {
            ptrA = ptrA->next;
        }
        
        if (ptrB == nullptr)
        {
            ptrB = headA;
        }
        else
        {
            ptrB = ptrB->next;
        }
    }
    
    return ptrA;
}