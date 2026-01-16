#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head);

int main(int argc, char const *argv[])
{
    ListNode *node4 = new ListNode(4);
    ListNode *node3 = new ListNode(0);
    ListNode *node2 = new ListNode(2);
    ListNode *node1 = new ListNode(3);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    bool result = hasCycle(node1);

    if (result == 1)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}