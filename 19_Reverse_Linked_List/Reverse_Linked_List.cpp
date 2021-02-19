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

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr, *curr = head;

    while (curr)
    {
        ListNode *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
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

int main() {

    vector<int> list {1,2,3,4,5};
    ListNode *l = new ListNode(), *curr = l;

    for (auto &n : list)
    {
        curr->next = new ListNode(n);
        curr = curr->next;
    }

    curr = l->next;
    printListNode(curr);
    curr = l->next;
    ListNode *res = reverseList(curr);
    printListNode(res);
}
