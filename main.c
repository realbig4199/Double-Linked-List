/*
구현 예시
*/

#include "list.h"

int main(void)
{
    Node* head = NULL;
    Node* newNode = NULL;

    newNode = CreateNode(10);
    AppendNode(&head, newNode);
    newNode = CreateNode(20);
    AppendNode(&head, newNode);
    newNode = CreateNode(30);
    AppendNode(&head, newNode);
    PrintList(head);

    DestroyNode(RemoveNode(&head, 30));
    PrintList(head);
    DestroyNode(RemoveNode(&head, 10));
    PrintList(head);
    DestroyNode(RemoveNode(&head, 20));
    PrintList(head);

    newNode = CreateNode(30);
    AppendNode(&head, newNode);
    DestroyNode(head);
    return 0;
}