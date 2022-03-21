#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct LinkedList
{
    Node *head;
    Node *tail;
};

Node *CreateNode(int number)
{
    Node *node = new Node;
    node->data = number;
    node->next = NULL;
    return node;
}

void CreatLinkedList(LinkedList &l)
{
    l.head = NULL;
    l.tail = NULL;
}
//để tạo 1 danh sách liên kết đơn ta làm
// LinkedList list;
// CreateList(list);
void AddHead(LinkedList &l, Node *node)
{

    if (l.head == NULL)
    {
        l.head = node;
        l.tail = node;
    }
    else
    {
        node->next = l.head;
        l.head = node;
    }
}
void AddTail(LinkedList &l, Node *node)
{

    if (l.head == NULL)
    {
        l.head = node;
        l.tail = node;
    }
    else
    {
        l.tail->next = node;
        l.tail = node;
    }
}
// them node p vao sau note q

void InsertAfterQ(LinkedList &l, Node *p, Node *q)
{
    if (q != NULL)
    {
        p->next = q->next;
        q->next = p;
        if (l.tail == q)
        {
            l.tail = p;
        }
    }
    else
        AddHead(l, p);
}
int DeleteHead(LinkedList &l, int &x)
{
    if (l.head == NULL)
    {
        Node *node = l.head;
        x = node->data; // tham chieu de luu lai gia tri bi xoa
        l.head = node->next;
        delete node; // Huy node do di
        if (l.head == NULL)
            l.tail = NULL;

        return 1;
    }
    return 0;
}
// xoa node bat ky after q
int RemoveAfterQ(LinkedList &l, Node *q, int &x)
{
    if (q != NULL)
    {
        Node *p = q->next;
        if (p != NULL)
        {
            if (l.tail == p)
            {
                l.tail = q;
                delete p;
                return 1;
            }
            else
            {
                q->next = p->next;
                x = p->data;
                delete p;
                return 1;
            }
        }
        return 0;
    }
    return 0;
}
// Duyet danh sach va in
void PrintList(LinkedList l)
{
    if (l.head != NULL)
    {
        Node *node = l.head;
        while (node != NULL)
        {
            cout << node->data << "  ";
            node = node->next;
        }
    }
}
// searching
Node *Search(LinkedList &l, int x)
{
    Node *node = l.head;
    while (node != NULL && node->data != x)
        node = node->next;
    if (node != NULL)
        return node;
    return NULL;
}
// GetNodeatIndex
Node *GetNode(LinkedList &l, int index)
{
    Node *node = l.head;
    int i = 0;
    while (node != NULL && i != index)
    {
        node = node->next;
        i++;
    }
    if (i == index && node != NULL)
    {
        return node;
    }
    return NULL;
}
// destroyList
void DestroyList(LinkedList &l)
{
    int x;
    Node *node = l.head;
    while (node != NULL)
    {
        DeleteHead(l, x);
    }
    l.tail = NULL;
}

int main()
{
    // Create a new linked list
    LinkedList list;
    CreatLinkedList(list);
    // Add sample data to list
    Node *node;
    for (auto i = 1; i <= 10; i++)
    {
        // Add node to head
        // List that is added node by AddHead will be reversed
        // AddHead(list, node);
        // Add node to tail
        AddTail(list, node);
    }
    // PrintList
    PrintList(list);
    cout << endl;
}
