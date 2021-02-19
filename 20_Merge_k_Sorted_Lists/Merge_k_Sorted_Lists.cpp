#include <iostream>
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

void printListNode(ListNode *list) {
    while (list)
    {
        cout << list->val;
        if (list->next) cout << "->";
        list = list->next;
    }

    cout << endl; 
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *dummy = new ListNode(), *curr = dummy;
    priority_queue<pair<int, ListNode *>> pq;

    for (auto &l : lists)
        if (l)
            pq.push({-l->val, l});

    while (pq.empty() == false)
    {
        ListNode *node = pq.top().second;
        pq.pop();
        curr->next = node;
        curr = curr->next;
        node = node->next;

        if (node)
            pq.push({-node->val, node});
    }
    return dummy->next;
}
int main()
{
    vector<int> list1 {1,4,5}, list2 {1,3,4}, list3 {2,6};
    ListNode *l1 = new ListNode(), *curr1 = l1;
    ListNode *l2 = new ListNode(), *curr2 = l2;
    ListNode *l3 = new ListNode(), *curr3 = l3;

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

        for (auto &n : list3)
    {
        curr3->next = new ListNode(n);
        curr3 = curr3->next;
    }

    curr1 = l1->next;
    curr2 = l2->next;
    curr3 = l3->next;

    printListNode(curr1);
    printListNode(curr2);
    printListNode(curr3);

    curr1 = l1->next;
    curr2 = l2->next;
    curr3 = l3->next;

    vector<ListNode *> lists {curr1, curr2, curr3};
    ListNode *res = mergeKLists(lists);
    printListNode(res);
}