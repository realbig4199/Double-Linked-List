/*
구현 순서에 따른 슈도 코드

0. 노드 구조체 정의
typedef struct Node
{
    정수형 data;
    앞 노드를 가리키는 포인터 생성(prev_node)
    뒷 노드를 가리키는 포인터 생성(next_node)
} Node;

1. 노드 생성
Node *CreateNode(int data)
{
    노드 동적 할당(힙에 노드를 넣고 주소만 따온다.)
    생성 노드의 데이터에 입력 데이터 할당
    생성 노드의 앞 노드 포인터에 NULL 할당
    생성 노드의 뒷 노드 포인터에 NULL 할당

    생성 노드 반환(동적 할당에 따라 주소를 반환)
}

2. 노드 추가
void AppendNode(Node **head, Node *new_node)
{
    만약 head가 가리키는 노드가 NULL이면
        head에 생성 노드 삽입
    그렇지 않으면(head가 어떤 노드를 가리키고 있다면)
        노드 포인터 current를 head가 가리키는 노드로 설정
        반복 (current의 뒷 노드 포인터가 NULL이 아닐 때까지)
            current를 current가 가리키는 뒷 노드 포인터로 이동
        <양방향 연결>
        current가 가리키는 노드의 뒷 노드 포인터를 new_node로 설정
        new_node의 앞 노드 포인터를 current로 설정
}

3. 노드 검색
Node *SearchNode(Node *current, int data)
{
    만약 current가 NULL이라면 (비어 있는 케이스 대비)
        NULL 반환
    반복 (current가 NULL이 아닐 때까지)
        만약 노드 current의 data가 입력된 data와 일치한다면
            노드 current 반환
        그렇지 않다면(data가 일치하지 않는다면)
            current를 다음 노드로 이동
    찾지 못했을 경우
        NULL 반환
}

4. 노드 삭제
Node *RemoveNode(Node **head, int data)
{
    노드 포인터 타겟 = SearchNode로 찾은 값
    만약 타겟이 NULL이 아니라면
        만약 head가 타겟을 가리키고 있다면
            head를 타겟의 다음 노드로 업데이트
            만약 head가 NULL이 아니면
                head가 가리키는 노드의 앞 노드 포인터를 NULL로 설정
        그렇지 않으면 (head 이외의 노드가 타겟이라면)
            타겟의 다음 노드가 NULL이 아니라면
                타겟 뒷 노드의 앞 노드 포인터를 타겟의 앞 노드 포인터로 업데이트
            그렇지 않으면 (타겟의 다음 노드가 NULL이라면)
                타겟 앞 노드의 뒷 노드 포인터를 타겟의 뒷 노드 포인터로 설정
        타겟의 앞 노드 포인터를 NULL로 설정
        타겟의 뒷 노드 포인터를 NULL로 설정
    타겟 반환
}

5. 리스트 출력
void PrintList(Node *current)
{
    만약 current가 NULL이면
        "빈 리스트" 출력
    그렇지 않으면 (current가 가리키는 게 있으면)
        반복 (current가 NULL이 아닐 때까지)
            출력 (current 포인터, current 앞 노드 포인터, current 데이터, current 뒷 노드 포인터)
            current를 뒷 노드 포인터로 이동
}

6. 리스트 삭제
void DestroyList(Node *current)
{
    제거할 노드 포인터에 current 삽입
    반복 (제거할 노드가 NULL이 아닐 때까지)
        현재 노드를 현재 노드의 다음 노드로 업데이트
        동적 할당 해제
        제거할 노드를 업데이트
}
*/

#include <stdio.h>
#include <stdlib.h>

// 0. 노드 구조체 정의
typedef struct Node
{
    int data;
    struct Node *prev_node;
    struct Node *next_node;
} Node;

// 1. 노드 생성
Node *CreateNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev_node = NULL;
    new_node->next_node = NULL;

    return new_node;
}

// 2. 노드 추가
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

// 3. 노드 검색
Node *SearchNode(Node *current, int data)
{
    if(current == NULL) return NULL;
    while(current != NULL) {
        if(current->data == data) return current;
        current = current->next_node;
    }
    return NULL;
}

// 4. 노드 삭제
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

// 5. 리스트 출력
void PrintList(Node *current) {
    if(current == NULL) printf("빈 리스트\n");
    else {
        while(current != NULL) {
            printf("[%p] %p %d %p\n", current, current->prev_node, current->data, current->next_node);
            current = current->next_node;
        }
    }
}

// 6. 리스트 삭제
void DestroyList(Node *current) {
    Node* remove = current;
    while(remove != NULL) {
        current = current->next_node;
        free(remove);
        remove = current;
    }
}
