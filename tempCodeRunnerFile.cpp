LinkedListNode *newNode = new LinkedListNode(_data);
            LinkedListNode *pNode = findParent(_nodeData);
        LinkedListNode *node = findNode(_nodeData);
        if (head == node)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = pNode->next;
            pNode->next = newNode;
        }