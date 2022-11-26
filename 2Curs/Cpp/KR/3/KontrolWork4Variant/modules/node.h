typedef struct Node {
    int index;
    Node * next; 
};
void push(Node **head, int data);
int pop(Node **head);
Node* getNextElement(Node* head, int n);
Node* getLast(Node *head);
void pushBack(Node *head, int value);
Node* getLastButOne(Node* head);
void popBack(Node **head);
void insert(Node *head, unsigned n, int val);
int length(Node *head);
int* toArray(Node *head);
void printLinkedList(const Node *head);
int deleteElement(Node **head, int n);
void deleteElementByValue(Node **head, int n);