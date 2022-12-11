#include <stdio.h>
#define MAX_Q_SIZE 15

typedef int element;

typedef struct
{
    int front;
    int rear;
    element data[MAX_Q_SIZE]; // element 는 때에 따라 char 가 되기도하고 int 가 되기도 함
} Queue;

typedef struct
{
    char todo[101];
    int importance[101];
} list;

typedef struct
{
    list data[100];
    int number;
    int length;
} Todo;

// 큐

void error(char *message)
{
    printf("%s\n", message);
}
void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}
int isFull(Queue *q)
{
    return q->rear == MAX_Q_SIZE - 1; // 0 또는 1을 출력하는거기에 조건을 바로 써줌
}
int isEmpty(Queue *q)
{
    return q->front == q->rear; // 0 또는 1을 출력하는거기에 조건을 바로 써줌
}
void enQueue(Queue *q, element item)
{
    if (isFull(q))
        error("Queue is full"); // Full 이 꽉차있으면 에러를 발생
    q->rear++;
    q->data[q->rear] = item; // 삽입
}
element deQueue(Queue *q)
{
    if (isEmpty(q))
        error("Queue is empty");
    q->front++;
    return q->data[q->front]; // 어느 부분에 삭제했는지 알려주기
}

// Main Screen

void MainScreen(Todo *t, Queue *q)
{
    int option;
    printf("==============================\n");
    printf("\n");
    printf("[1] To Do List 추가하기\n");
    printf("\n");
    printf("[2] To Do List Log 보러가기\n");
    printf("\n");
    printf("[3] 나가기\n");
    printf("\n");
    printf("==============================\n");
    printf("입력하기 : ");
    scanf("%d", &option);
    printf("\n");
    switch (option)
    {
    case 1:
        printf("-------- Add To Do List --------\n");
        printf("\n");
        printf("할 일을 입력하세요 : ");
        scanf("%s", &t->data[t->number].todo);
        printf("중요도를 입력하세요 : ");
        scanf("%d", &t->data[t->number].importance);
        printf("===============\n");

        enQueue(q, t->number);

        t->number++;
        t->length++;
        MainScreen(t, q);
        break;
    case 2:
        printf("-------- To Do List Log --------\n\n");
        for (int i = 0; i < MAX_Q_SIZE; i++)
        {
            if (i <= q->front || i > q->rear)
            {
                printf("데 이 터 가 없 습 니 다\n");
                printf("--------------------------------\n");
            }
            else
            {
                printf("%d: %s              중요도: %d\n", i+1, t->data[i].todo, *t->data[i].importance);
                printf("--------------------------------\n");
            }
        }
        MainScreen(t, q);
        break;
    default:
        break;
    }
}

int main(void)
{
    Todo t;
    Queue q;
    t.number = 0;
    t.length = 0;
    initQueue(&q); // queue 초기 세팅

    MainScreen(&t, &q); // Main Menu Screen
    return 0;
}