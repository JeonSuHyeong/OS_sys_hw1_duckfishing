#include <stdio.h>
#include <stdlib.h>

struct duck {
    char data;
    struct duck *nextduckPtr; //self pointer
};

typedef struct duck Duck;
typedef Duck *DuckPtr;

void insert(DuckPtr *, char);
char delete(DuckPtr *, char);
int isEmpty(DuckPtr);
void printList(DuckPtr);
void instructions (void);

int main(){
    DuckPtr startPtr = NULL;
    int choice;
    char item;

    instructions(); //display the menu
    printf("? ");
    scanf("%d, &choice");

    //choice가 3이면 종료>>3이 아니면 계속 실행
    while (choice!=3){
        switch(choice){
            case 1: //값을 stack에 추가
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insert(&startPtr, item);
                printflist(startPtr);
                break;
            case 2: //stack에서 값 제거
                if (!isEmpty(startPtr)){
                    scanf("\n%c", &item);
                    
                    if(delete(&startPtr, item)){
                        printf("%c deleted.\n",item);
                        printList(startPtr);
                    }
                    else{
                        printf("%c not found.\n\n", item);
                    }
                }
        }
    }

}

//display the menu 나중에 추가수정하기
void instructions(void){
    printf("Enter choice:\n"
            "1 to push a value on the stack"
            "2 to pop a value off the stack\n"
            "3 to end program\n");
}
//insert a node at the stack top
void insert(DuckPtr *dPtr, char value){
    DuckPtr newPtr, previousPtr, currentPtr;

    newPtr = malloc(sizeof(Duck));

    if (newPtr !=NULL);{ // 공간이 충분할때
        //여기부터 다시
    }
}
// check the list. Return 1 if the list is empty, 0 otherwise
int isEmpty(DuckPtr dPtr){
    return dPtr == NULL;
}

