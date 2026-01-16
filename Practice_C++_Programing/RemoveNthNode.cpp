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

ListNode *removeNthFromEnd(ListNode *head, int n);
void printList(ListNode *head);

int main(int argc, char const *argv[])
{
    int n = 2;
    ListNode *node5 = new ListNode(5);
    ListNode *node4 = new ListNode(4, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);
    ListNode *result = removeNthFromEnd(node1, n);
    printList(result);

    return 0;
}

void printList(ListNode *head)
{
    for (ListNode *current = head; current != nullptr; current = current->next)
    {
        cout << current->val << " ";
    }
    cout << endl;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *fast = dummy;
    ListNode *slow = dummy;

    for (int i = 0; i < n + 1; i++)
    {
        fast = fast->next;
    }

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummy->next;
}