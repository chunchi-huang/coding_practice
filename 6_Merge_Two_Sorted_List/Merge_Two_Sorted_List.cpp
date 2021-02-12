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

void printListNode(ListNode *list)
{
    while (list) {
        cout << list->val;
        if (list->next)
            cout << "->";
        list = list->next;
    }

    cout << endl;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(), *res = dummy;

    while (l1 && l2)
    {
        if (l1->val <= l2->val) {
            res->next = l1;
            l1 = l1->next;
        }
        else {
            res->next = l2;
            l2 = l2->next;
        }

        res = res->next;
    }

    res->next = l1 == nullptr ? l2 : l1;
    return dummy->next;
}

int main()
{
    vector<int> list1{1, 2, 4}, list2{1, 3, 4};

    ListNode *l1 = new ListNode(), *l2 = new ListNode();
    ListNode *curr1 = l1, *curr2 = l2;

    for (auto &n : list1)
    {
        curr1->next = new ListNode(n);
        curr1 = curr1->next;
    }

    for (auto &n : list2)
    {
        curr2->next = new ListNode(n);
        curr2 = curr2->next;
    }

    curr1 = l1->next;
    curr2 = l2->next;

    printListNode(curr1);
    printListNode(curr2);

    ListNode *res = mergeTwoLists(curr1, curr2);

    printListNode(res);
}