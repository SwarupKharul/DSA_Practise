// we have two pointers. one is a iteration pointer and the other will be behind it by requested number of elements. so for example lets say we need to get value of 3rd element from tail. we start incrementing second pointer after 3rd element alongside with iteration pointer. When iteration pointer gets to the end(tail) second pointer is going to be pointing to 3rd element from it.
int getNode(SinglyLinkedListNode *llist, int positionFromTail)
{
    int index = 0;
    SinglyLinkedListNode *current = llist;
    SinglyLinkedListNode *result = llist;
    while (current != NULL)
    {
        current = current->next;
        if (index++ > positionFromTail)
        {
            result = result->next;
        }
    }
    return result->data;
}
