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

ListNode *removeElements(ListNode *head, int val);

int main(int argc, char const *argv[])
{
    ListNode *node7 = new ListNode(6);
    ListNode *node6 = new ListNode(5, node7);
    ListNode *node5 = new ListNode(4, node6);
    ListNode *node4 = new ListNode(3, node5);
    ListNode *node3 = new ListNode(6, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);
    int val = 6;
    ListNode *result = removeElements(node1, val);
    cout << endl;
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}

ListNode *removeElements(ListNode *head, int val)
{
    ListNode dummy(0);
    dummy.next = head;

    ListNode *current = &dummy;

    while (current->next)
    {
        if (current->next->val == val)
        {
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }
    
    return dummy.next;
}