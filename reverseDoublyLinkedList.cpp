DoublyLinkedListNode *reverse(DoublyLinkedListNode *llist)
{
    DoublyLinkedListNode *current = llist;
    DoublyLinkedListNode *prev = nullptr;
    DoublyLinkedListNode *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    llist = prev;
    return llist;
}