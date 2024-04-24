#include <iostream>
using namespace std;

class LinkedListNode
{
public:
    int data;
    LinkedListNode *next;
    LinkedListNode(int _data)
    {
        this->data = _data;
        this->next = NULL;
    }
};

class LinkedListIterator
{
private:
    LinkedListNode *currentNode;
public:
    LinkedListIterator()
    {
        currentNode = NULL;
    }
    LinkedListIterator(LinkedListNode *node)
    {
        currentNode = node;
    }
    int data()
    {
        return this->currentNode->data;
    }
    LinkedListIterator next()
    {
        this->currentNode = this->currentNode->next;
        return *this;
    }
    LinkedListNode *current()
    {
        return this->currentNode;
    }
};

class LinkedList
{
public:
    LinkedListNode *head = NULL;
    LinkedListNode *tail = NULL;

    LinkedListIterator begin()
    {
        LinkedListIterator itr(this->head); // static allocation
        return itr;
    }
    void printList()
    {
        for (LinkedListIterator itr = this->begin(); itr.current() != NULL; itr.next())
        {
            cout << itr.data() << " -> ";
        }
        cout << "NULL";

        cout << endl;
    }
    void insertLast(int _data)
    {
        LinkedListNode *newNode = new LinkedListNode(_data);
        if (this->head == NULL)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }
    LinkedListNode *findNode(int _data)
    {
        for (LinkedListIterator itr = this->begin(); itr.current() != NULL; itr.next())
        {
            if (itr.data() == _data)
            {
                return itr.current();
            }
        }

        return NULL;
    }
    LinkedListNode *findParent(LinkedListNode *node)
    {
        for (LinkedListIterator itr = this->begin(); itr.current() != NULL; itr.next())
        {
            if (itr.current()->next == node)
            {
                cout << "founded" << endl;
                return itr.current();
            }
        }
        cout << "not founded" << endl;
        return NULL;
    }
    void insertAfter(int _nodeData, int _data)
    {
        // find the node that i will insert after it based on his value
        LinkedListNode *node = findNode(_nodeData);
        // create new node
        LinkedListNode *newNode = new LinkedListNode(_data);
        // chain the nodes
        newNode->next = node->next;
        node->next = newNode;

        if (this->tail == node)
        {
            this->tail = newNode;
        }
    }
    void insertBefore(int _nodeData, int _data)
    {
        LinkedListNode *newNode = new LinkedListNode(_data);
        LinkedListNode *node = this->findNode(_nodeData);
        newNode->next = node;

        LinkedListNode *parent = this->findParent(node);

        // if this parent node is the head of the linked list
        if (parent == NULL)
        {
            head = newNode;
        }
        else
        {
            parent->next = newNode;
        }
    }
    void deleteNode(int _nodeData)
    {
        LinkedListNode *node = this->findNode(_nodeData);
        cout << node->data << endl;
        if (head == tail)
        {
            this->head = NULL;
            this->tail = NULL;
        }
        else if (this->head == node)
        {
            head = head->next;
        }
        else
        {
            LinkedListNode *parent = this->findParent(node);
            if (this->tail == node)
            {
                tail = parent;
                tail->next = NULL;
            }
            else
            {
                parent->next = node->next;
            }
        }
        delete node;
    }
};

int main()
{

    LinkedList *list = new LinkedList();
    list->insertLast(1);
    list->insertLast(2);
    list->insertLast(3);
    list->insertLast(4);


    list->printList();

    return 0;
}
