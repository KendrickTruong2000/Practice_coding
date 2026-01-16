#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head);

int main(int argc, char const *argv[])
{
    ListNode *node5 = new ListNode(5);
    ListNode *node4 = new ListNode(4, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);
    ListNode *result = reverseList(node1);

    cout << endl;
    while (result)
    {
        cout << result->val << "->";
        result = result->next;
    }

    return 0;
}

ListNode *reverseList(ListNode *head)
{
    // ListNode *current = head;
    // vector<int> dummy;

    // if (head == nullptr)
    // {
    //     return nullptr;
    // }

    // while (current)
    // {
    //     dummy.push_back(current->val);
    //     current = current->next;
    // }

    // ListNode *result = new ListNode(dummy[dummy.size() - 1]);
    // ListNode *curr = result;

    // for (int i = dummy.size() - 2; i >= 0; i--)
    // {
    //     curr->next = new ListNode(dummy[i]);
    //     curr = curr->next;
    // }

    // return result;

    ListNode *result = nullptr;
    ListNode *current = head;

    while (current)
    {
        ListNode *temp = current->next;
        current->next = result;
        result = current;
        current = temp;
    }

    return result;
}