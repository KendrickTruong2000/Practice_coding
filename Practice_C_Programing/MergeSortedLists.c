#include <stdio.h>
#include <stdlib.h>

struct ListNode* mergeTwoLists(struct ListNode*, struct ListNode*);

struct ListNode {
    int val;
    struct ListNode *next;
};

int main(int argc, char const *argv[])
{
    struct ListNode *list1 = malloc(sizeof(struct ListNode));
    list1->val = 1;
    list1->next = malloc(sizeof(struct ListNode));
    list1->next->val = 2;
    list1->next->next = malloc(sizeof(struct ListNode));
    list1->next->next->val = 4;
    list1->next->next->next = NULL;

    struct ListNode *list2 = malloc(sizeof(struct ListNode));
    list2->val = 1;
    list2->next = malloc(sizeof(struct ListNode));
    list2->next->val = 3;
    list2->next->next = malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    struct ListNode *mergedList = mergeTwoLists(list1, list2);

    while(mergedList != NULL){
        printf("%d ", mergedList->val);
        mergedList = mergedList->next;
    }

    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL) {
        return list2;
    }

    if(list2 == NULL) {
        return list1;
    }

    struct ListNode* mergedList = NULL;

    if (list1->val < list2->val){
        mergedList = list1;
        mergedList->next = mergeTwoLists(list1->next, list2);
    }
    else
    {
        mergedList = list2;
        mergedList->next = mergeTwoLists(list1, list2->next);
    }

    return mergedList;
}
