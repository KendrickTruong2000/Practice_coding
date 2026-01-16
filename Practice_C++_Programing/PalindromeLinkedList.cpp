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

bool isPalindrome(ListNode *);

int main(int argc, char const *argv[])
{
    ListNode *node4 = new ListNode(1);
    ListNode *node3 = new ListNode(2, node4);
    ListNode *node2 = new ListNode(1, node3);
    ListNode *node1 = new ListNode(1, node2);
    bool result = isPalindrome(node1);

    if (result)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}

bool isPalindrome(ListNode *head)
{
    stack<int> st;
    ListNode *current = head;

    while (current)
    {
        st.push(current->val);
        current = current->next;
    }

    current = head;
    while (current)
    {
        if (current->val != st.top())
        {
            return false;
        }

        st.pop();
        current = current->next;
    }

    return true;
}