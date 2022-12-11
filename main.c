#include <stdio.h>
#define MAX_Q_SIZE 10

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
    int check;
} list;

typedef struct
{
    list data[100];
    int number;
    int length;
} Todo;

// 정렬

void sort(Queue *q, Todo *t)
{
    int i, j, k, temp, key;
    for(i=0; i<-1; i++)
    {
        k=i;
        for(j=i+1; j<t->length; j++)
        {
            if(t->data[j].importance<t->data[k].importance)
            {
                k=j;
            }
        }
        temp=q->data[i];
        q->data[i]=q->data[k];
        q->data[k]=temp;
    }
}

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
element deQueue(Queue *q, Todo *t)
{
    if (isEmpty(q))
        error("Queue is empty");
    q->front++;
    t->data[q->front].check = 1;
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
    printf("[3] To Do List Check\n");
    printf("\n");
    printf("[4] 중요도 순 정렬\n");
    printf("\n");
    printf("[5] 나가기\n");
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
        printf("--------------------------------\n");
        enQueue(q, t->number);

        t->number++;
        t->length++;
        MainScreen(t, q);
        break;
    case 2:
        printf("-------- To Do List Log --------\n\n");
        for (int i = 0; i < MAX_Q_SIZE; i++)
        {
            if (t->data[i].check == 1)
            {
                printf("[⎷]  %s              중요도: %d\n", t->data[i].todo, *t->data[i].importance);
                printf("--------------------------------\n");
            }
            else if (i <= q->front || i > q->rear)
            {
                continue;
            }
            else
            {
                printf("[ ]  %s              중요도: %d\n", t->data[i].todo, *t->data[i].importance);
                printf("--------------------------------\n");
            }
        }
        MainScreen(t, q);
        break;
    case 3:
        deQueue(q, t);
        MainScreen(t, q);
        break;
    case 4:
        sort(q, t);
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

    for (int i = 0; i < 15; i++)
    {
        t.data[i].check = 0; // 초기 세팅
    }

    initQueue(&q); // queue 초기 세팅

    MainScreen(&t, &q); // Main Menu Screen
    return 0;
}