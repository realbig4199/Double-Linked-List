typedef struct Node
{
    int data;
    struct Node *prev_node;
    struct Node *next_node;
} Node;

Node *CreateNode(int key);

void AppendNode(Node **head, Node *new_node);

Node *SearchNode(Node *current, int data);

Node *RemoveNode(Node **head, int data);

void DestroyNode(Node *target);

// 5. 리스트 출력
void PrintList(Node *current);

// 6. 리스트 삭제
void DestroyList(Node *current);
