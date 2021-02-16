#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void printNextNode(Node *list)
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

void printRandomNode(Node *list)
{
    while (list)
    {
        if (list->random == nullptr)
            cout << "-1";
        else
            cout << list->random->val;

        if (list->next)
            cout << " -> ";
        list = list->next;
    }

    cout << endl;
}

Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return nullptr;

    unordered_map<Node *, Node *> map;

    Node *curr = head;

    while (curr)
    {
        map[curr] = new Node(curr->val);
        curr = curr->next;
    }

    curr = head;

    while (curr)
    {
        map[curr]->next = map[curr->next];
        map[curr]->random = map[curr->random];
        curr = curr->next;
    }

    return map[head];
}

int main()
{
    //example Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    // 7->13->11->10->1->nullptr
    vector<int> linkList{7, 13, 11, 10, 1};
    Node *dummy = new Node(0), *head = dummy;
    unordered_map<int, Node*> map;
    int count = 0;

    for (auto &c : linkList) {
        head->next = new Node(c);
        map[count++] = head->next;
        head = head->next;
    }

    head = dummy->next;
    vector<int> randomList{-1, 0, 4, 2, 0};

    for (int i = 0; i < randomList.size(); ++i) {
        
        if (randomList[i] == -1)
            head->random = nullptr;
        else 
            head->random = map[randomList[i]];
            
        head = head->next;
    }

    head = dummy->next;
    printNextNode(head);
    head = dummy->next;
    printRandomNode(head);

    head = dummy->next;
    Node *res = copyRandomList(head);

    cout << "After deep copy" << endl;
    head = dummy->next;
    printNextNode(head);
    head = dummy->next;
    printRandomNode(head);

}
