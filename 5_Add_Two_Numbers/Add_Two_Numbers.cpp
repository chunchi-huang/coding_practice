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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    ListNode *dummy = new ListNode();
    ListNode *p = l1, *q = l2, *curr = dummy;
    int carry = 0;

    while (p != NULL || q != NULL)
    {

        int x = (p == NULL) ? 0 : p->val;
        int y = (q == NULL) ? 0 : q->val;

        int sum = x + y + carry;
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);

        curr = curr->next;

        if (p != NULL)
            p = p->next;
        if (q != NULL)
            q = q->next;
    }

    if (carry)
        curr->next = new ListNode(1);

    return dummy->next;
}

void printListNode(ListNode *list) {
    while (list)
    {
        cout << list->val;
        if (list->next) cout << "->";
        list = list->next;
    }

    cout << endl; 
}

int main()
{
    vector<int> list1{9,9,9,9,9,9,9}, list2{9, 9, 9};

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

    ListNode *res = addTwoNumbers(curr1, curr2);

    printListNode(curr1);
    printListNode(curr2);
    printListNode(res);
}