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

ListNode *removeDuplicates(ListNode *list);

int main(int argc, char const *argv[])
{
    // int result = 0;
    // vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    // result = removeDuplicates(nums);
    // cout << result << endl;
    // return 0;

    int result = 0;
    // ListNode *list = new ListNode(1);
    // list->next = new ListNode(1);
    // list->next->next = new ListNode(2);

    ListNode *list = new ListNode(1);
    list->next = new ListNode(1);
    list->next->next = new ListNode(2);
    list->next->next->next = new ListNode(3);
    list->next->next->next->next = new ListNode(3);

    ListNode *resultList = removeDuplicates(list);

    while (resultList != nullptr)
    {
        cout << resultList->val;
        if (resultList->next != nullptr)
        {
            cout << "->";
        }
        resultList = resultList->next;
    }
    cout << endl;

    while (list)
    {
        ListNode *temp = list;
        list = list->next;
        delete temp;
    }

    return 0;
}

ListNode *removeDuplicates(ListNode *list)
{
    if (!list)
    {
        return list;
    }
    
    ListNode *current = list;

    while (current && current->next)
    {
        if (current->val == current->next->val)
        {
            ListNode *tmp = current->next;
            current->next = tmp->next;
            delete tmp;
        }
        else
        {
            current = current->next;
        }
    }

    return list;
}

// int removeDuplicates(vector<int> &nums)
// {
//     vector<int> nonDuplicates;

//     for (int i = 0; i < nums.size(); i++)
//     {

//         auto isExist = find(nonDuplicates.begin(), nonDuplicates.end(), nums[i]);

//         // Found
//         if (isExist != nonDuplicates.end())
//         {
//             continue;
//         }
//         // Not found
//         else
//         {
//             nonDuplicates.push_back(nums[i]);
//             nums.push_back(nums[i]);
//         }
//     }

//     for (int j = 0; j < nonDuplicates.size(); j++)
//     {
//         nums[j] = nonDuplicates[j];
//         cout << nonDuplicates[j] << " ";
//     }
//     cout << endl;
//     return nonDuplicates.size();
// }