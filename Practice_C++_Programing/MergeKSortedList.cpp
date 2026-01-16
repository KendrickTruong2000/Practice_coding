#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Comparator
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

ListNode *mergeKList(vector<ListNode *> &lists);

int main(int argc, char const *argv[])
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode *> list = {list1, list2, list3};
    ListNode *result = mergeKList(list);

    while (result != nullptr)
    {
        cout << result->val;

        if (result->next != nullptr)
        {
            cout << "->";
        }
        result = result->next;
    }
    cout << endl;

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

    while (list3)
    {
        ListNode *temp = list3;
        list3 = list3->next;
        delete temp;
    }

    return 0;
}

ListNode *mergeKList(vector<ListNode *> &lists)
{
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    priority_queue<ListNode *, vector<ListNode *>, Comparator> minHeap;

    for (ListNode *list : lists)
    {
        if (list != nullptr)
        {
            minHeap.push(list);
        }
    }

    while (!minHeap.empty())
    {
        ListNode *smallest = minHeap.top();
        minHeap.pop();

        tail->next = smallest;
        tail = tail->next;

        if (smallest->next != nullptr)
        {
            minHeap.push(smallest->next);
        }
    }

    return dummy->next;
}