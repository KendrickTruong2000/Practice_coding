#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2);

int main(int argc, char const *argv[])
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *merge = mergeTwoLists(list1, list2);

    while (merge != nullptr)
    {
        cout << merge->val;
        if (merge->next != nullptr)
        {
            cout << " -> ";
        }
        merge = merge->next;
    }
    cout << endl;

    // Clean memory
    while (list1)
    {
        ListNode *temp = list1;
        list1 = list1->next;
        delete temp;
    }

    while (list2)
    {
        ListNode *temp = list2;
        list2 = list2->next;
        delete temp;
    }

    return 0;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1)
    {
        return list2;
    }

    if (!list2)
    {
        return list1;
    }

    ListNode *dummy = new ListNode();
    ListNode *current = dummy;
    ListNode *result;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1)
    {
        current->next = list1;
    }

    if (list2)
    {
        current->next = list2;
    }

    result = dummy->next;
    delete dummy;
    return result;
}
