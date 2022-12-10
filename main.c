#include<stdio.h>

typedef struct
{
    char todo[101];
    int importance[101];
} list;

typedef struct
{
    list data[100];
    int number;
} Todo;


void MainScreen(Todo* t) {
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
        printf("==============================\n");
        printf("%d\n", *t->data[t->number].importance);
        printf("%s\n", t->data[t->number].todo);
        break;
    
    default:
        break;
    }
}

int main(void)
{
    Todo t;
    t.number = 0;
    MainScreen(&t); // Main Menu Screen
    return 0;
}