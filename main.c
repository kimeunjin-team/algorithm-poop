#include<stdio.h>

void MainScreen() {
    int option;
    printf("==============================\n");
    printf("------------ Menu ------------\n");
    printf("\n");
    printf("[1] To Do List 추가하기\n");
    printf("\n");
    printf("[2] To Do List Log 보러가기\n");
    printf("\n");
    printf("[3] 나가기\n");
    printf("\n");
    printf("==============================\n");
    scanf("입력하기 : %d", &option);
    switch (option)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    default:
        printf("그딴거는 없다 게이야..");
        break;
    }
}

int main(void)
{
    MainScreen(); // Main Menu Screen
    return 0;
}