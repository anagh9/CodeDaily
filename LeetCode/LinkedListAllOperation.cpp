/* Print the Elements of a Linked list */

void PrintLL(Node *list)
{
    while (list != NULL)
    {
        cout << list->data << " ";
        list = list->next;
    }
}

/* Insert Node at the Tail of a Linked List */
SinglyLinkedListNode *insertNodeAtTail(SinglyLinkedListNode *head, int data)
{
    SinglyLinkedListNode *curr = new SinglyLinkedListNode(data);
    //  curr->data = data;
    curr->next = NULL;
    SinglyLinkedListNode *temp;

    if (head == NULL)
    {
        return (curr);
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = curr;
    return (head);
}

/* Reverse Print the Linked list */
void reversePrint(SinglyLinkedListNode *head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        reversePrint(head->next);
        cout << head->data << endl;
    }
}

/* Compare two Linked Lists */
bool compare_lists(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    while (head1->next != NULL && head2->next != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1->next != NULL || head2->next != NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/* Merge two sorted linked lists */

SinglyLinkedListNode *mergeLists(SinglyLinkedListNode *headA, SinglyLinkedListNode *headB)
{

    SinglyLinkedListNode *head = NULL;

    SinglyLinkedListNode *p = headA;
    SinglyLinkedListNode *q = headB;

    if (p == NULL && q == NULL)
    {
        return NULL;
    }

    if (p == NULL && q != NULL)
    {
        head = q;
        q = q->next;
    }

    if (p != NULL && q == NULL)
    {
        head = p;
        p = p->next;
    }

    if (p && q && p->data <= q->data)
    {
        head = p;
        p = p->next;
    }
    else if (p && q && q->data <= q->data)
    {
        head = q;
        q = q->next;
    }

    SinglyLinkedListNode *r = head;

    while (p && q)
    {
        if (p->data <= q->data)
        {
            r->next = p;
            p = p->next;
        }
        else
        {
            r->next = q;
            q = q->next;
        }
        r = r->next;
    }

    while (p)
    {
        r->next = p;
        p = p->next;
        r = r->next;
    }

    while (q)
    {
        r->next = q;
        q = q->next;
        r = r->next;
    }

    r->next = NULL;
    return head;
}

/* Get Node Value */
int getNode(SinglyLinkedListNode *head, int positionFromTail)
{
    int i = 0;
    SinglyLinkedListNode *current = head;
    SinglyLinkedListNode *result = head;
    while (current != NULL)
    {
        current = current->next;
        if (i++ > positionFromTail)
        {
            result = result->next;
        }
    }
    return result->data;
}

/* Delete duplicate-value nodes from a sorted Linked List */

SinglyLinkedListNode *removeDuplicates(SinglyLinkedListNode *head)
{
    SinglyLinkedListNode *cur = head;
    while (cur->next != NULL)
    {
        if (cur->data == cur->next->data)
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }
    return head;
}

/* Find Merge Point of Two Lists */

int findMergeNode(SinglyLinkedListNode *headA, SinglyLinkedListNode *headB)
{

    SinglyLinkedListNode *tempB;

    while (headA != NULL)
    {
        tempB = headB;
        while (tempB != NULL)
        {
            if (tempB == headA)
            {
                return tempB->data;
            }
            tempB = tempB->next;
        }
        headA = headA->next;
    }
    return headA->data;
}

/* Reversing a Doubly Linked List */
DoublyLinkedListNode *reverse(DoublyLinkedListNode *llist)
{
    DoublyLinkedListNode *temp = NULL;
    DoublyLinkedListNode *curr = llist;
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL)
        llist = temp->prev;
    return llist;
}
