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
    int length;
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
        printf("===============\n");
        t->number++;
        t->length++;
        MainScreen(t);
        break;
    case 2:
        printf("-------- To Do List Log --------\n\n");
        for(int i=0;i<t->length;i++) {
            printf("%d: %s         중요도: %d\n", i+1, t->data[i].todo, *t->data[i].importance);
            printf("--------------------------------\n");
        }
        MainScreen(t);
        break;
    default:
        break;
    }
}

int main(void)
{
    Todo t;
    t.number = 0;
    t.length = 0;
    MainScreen(&t); // Main Menu Screen
    return 0;
}