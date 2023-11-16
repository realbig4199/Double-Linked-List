/*
���� ������ ���� ���� �ڵ�

0. ��� ����ü ����
typedef struct Node
{
    ������ data;
    �� ��带 ����Ű�� ������ ����(prev_node)
    �� ��带 ����Ű�� ������ ����(next_node)
} Node;

1. ��� ����
Node *CreateNode(int data)
{
    ��� ���� �Ҵ�(���� ��带 �ְ� �ּҸ� ���´�.)
    ���� ����� �����Ϳ� �Է� ������ �Ҵ�
    ���� ����� �� ��� �����Ϳ� NULL �Ҵ�
    ���� ����� �� ��� �����Ϳ� NULL �Ҵ�

    ���� ��� ��ȯ(���� �Ҵ翡 ���� �ּҸ� ��ȯ)
}

2. ��� �߰�
void AppendNode(Node **head, Node *new_node)
{
    ���� head�� ����Ű�� ��尡 NULL�̸�
        head�� ���� ��� ����
    �׷��� ������(head�� � ��带 ����Ű�� �ִٸ�)
        ��� ������ current�� head�� ����Ű�� ���� ����
        �ݺ� (current�� �� ��� �����Ͱ� NULL�� �ƴ� ������)
            current�� current�� ����Ű�� �� ��� �����ͷ� �̵�
        <����� ����>
        current�� ����Ű�� ����� �� ��� �����͸� new_node�� ����
        new_node�� �� ��� �����͸� current�� ����
}

3. ��� �˻�
Node *SearchNode(Node *current, int data)
{
    ���� current�� NULL�̶�� (��� �ִ� ���̽� ���)
        NULL ��ȯ
    �ݺ� (current�� NULL�� �ƴ� ������)
        ���� ��� current�� data�� �Էµ� data�� ��ġ�Ѵٸ�
            ��� current ��ȯ
        �׷��� �ʴٸ�(data�� ��ġ���� �ʴ´ٸ�)
            current�� ���� ���� �̵�
    ã�� ������ ���
        NULL ��ȯ
}

4. ��� ����
Node *RemoveNode(Node **head, int data)
{
    ��� ������ Ÿ�� = SearchNode�� ã�� ��
    ���� Ÿ���� NULL�� �ƴ϶��
        ���� head�� Ÿ���� ����Ű�� �ִٸ�
            head�� Ÿ���� ���� ���� ������Ʈ
            ���� head�� NULL�� �ƴϸ�
                head�� ����Ű�� ����� �� ��� �����͸� NULL�� ����
        �׷��� ������ (head �̿��� ��尡 Ÿ���̶��)
            Ÿ���� ���� ��尡 NULL�� �ƴ϶��
                Ÿ�� �� ����� �� ��� �����͸� Ÿ���� �� ��� �����ͷ� ������Ʈ
            �׷��� ������ (Ÿ���� ���� ��尡 NULL�̶��)
                Ÿ�� �� ����� �� ��� �����͸� Ÿ���� �� ��� �����ͷ� ����
        Ÿ���� �� ��� �����͸� NULL�� ����
        Ÿ���� �� ��� �����͸� NULL�� ����
    Ÿ�� ��ȯ
}

5. ����Ʈ ���
void PrintList(Node *current)
{
    ���� current�� NULL�̸�
        "�� ����Ʈ" ���
    �׷��� ������ (current�� ����Ű�� �� ������)
        �ݺ� (current�� NULL�� �ƴ� ������)
            ��� (current ������, current �� ��� ������, current ������, current �� ��� ������)
            current�� �� ��� �����ͷ� �̵�
}

6. ����Ʈ ����
void DestroyList(Node *current)
{
    ������ ��� �����Ϳ� current ����
    �ݺ� (������ ��尡 NULL�� �ƴ� ������)
        ���� ��带 ���� ����� ���� ���� ������Ʈ
        ���� �Ҵ� ����
        ������ ��带 ������Ʈ
}
*/

#include <stdio.h>
#include <stdlib.h>

// 0. ��� ����ü ����
typedef struct Node
{
    int data;
    struct Node *prev_node;
    struct Node *next_node;
} Node;

// 1. ��� ����
Node *CreateNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev_node = NULL;
    new_node->next_node = NULL;

    return new_node;
}

// 2. ��� �߰�
void AppendNode(Node **head, Node *new_node)
{
    if (*head == NULL) *head = new_node;
    else
    {
        Node *current = *head;
        while(current->next_node != NULL) current = current->next_node;
        current->next_node = new_node;
        new_node->prev_node = current;
    }
}

// 3. ��� �˻�
Node *SearchNode(Node *current, int data)
{
    if(current == NULL) return NULL;
    while(current != NULL) {
        if(current->data == data) return current;
        current = current->next_node;
    }
    return NULL;
}

// 4. ��� ����
Node *RemoveNode(Node **head, int data)
{
    Node *target = SearchNode(*head, data);
    if (target != NULL)
    {
        if (*head == target)
        {
            *head = target->next_node;
            if (*head != NULL)
                (*head)->prev_node = NULL;
        }
        else
        {
            if (target->next_node != NULL) 
                target->next_node->prev_node = target->prev_node;
            target->prev_node->next_node = target->next_node;
        }
        target->prev_node = NULL;
        target->next_node = NULL;
    }
    return target;
}

void DestroyNode(Node *target)
{
    free(target);
}

// 5. ����Ʈ ���
void PrintList(Node *current) {
    if(current == NULL) printf("�� ����Ʈ\n");
    else {
        while(current != NULL) {
            printf("[%p] %p %d %p\n", current, current->prev_node, current->data, current->next_node);
            current = current->next_node;
        }
    }
}

// 6. ����Ʈ ����
void DestroyList(Node *current) {
    Node* remove = current;
    while(remove != NULL) {
        current = current->next_node;
        free(remove);
        remove = current;
    }
}
