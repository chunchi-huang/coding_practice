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
    while (list)
    {
        cout << list->val;
        if (list->next)
            cout << "->";
        list = list->next;
    }

    cout << endl;
}

ListNode *reverseKGroup(ListNode *head, int k)
{

    ListNode *dummy = new ListNode(), *pre = dummy, *calList = head;

    int len = 0;
    while (calList)
    {
        len++;
        calList = calList->next;
    }

    dummy->next = head;

    for (int i = 0; i < (int)len / k; ++i)
    {
        for (int j = 1; j < k; ++j)
        {
            ListNode *tmp = pre->next;
            pre->next = head->next;
            head->next = head->next->next;
            pre->next->next = tmp;
        }
        pre = head;
        head = head->next;
    }

    return dummy->next;
}

int main()
{
    vector<int> linkList{1, 2, 3, 4, 5};
    ListNode *head = new ListNode(), *dummy = head;

    for (auto &c : linkList) {
        head->next = new ListNode(c);
        head = head->next;
    }

    head = dummy->next;
    printListNode(head);

    int k = 2;
    ListNode *res = reverseKGroup(head, k);
    printListNode(res);
}