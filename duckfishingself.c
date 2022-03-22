#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


struct duck{
    char d_name[8];
    struct duck *nextDuck;
};

typedef struct duck Duck;
typedef Duck *DuckPtr;

//functions
void instructions();
void fish_duck(DuckPtr *);
char release_duck(DuckPtr *);
int isEmpty(DuckPtr);
void show_ducks(DuckPtr);
void animated_ducks(DuckPtr);


int main(){
    //initial value
    char name[8]; //string
    DuckPtr startPtr = NULL;
    int choice;
    int d_cnt = 0;

    //instructions
    instructions();
    scanf("%d", &choice);

    while(choice!=4){
        switch (choice){
            //fishing a new duck
            case 1:
               fish_duck(&startPtr);
               system("cls");
               d_cnt++;
               break;
            //release the duck
            case 2:
                release_duck(&startPtr);
                system("cls");
                d_cnt--;
                break;
            //show your ducks
            case 3:
                show_ducks(startPtr);
                animated_ducks(startPtr);
                break;
            default:
                printf("Invaild choice.\n\n ");
                break;
        }
        instructions();
        scanf("%d", &choice);
        system("cls");
    }
    //end fishing
    printf("Quit the program!\n");
}   
    

void instructions(){
    printf("Enter your actions\n"
            "1 to fish a new duck\n"
            "2 to release the duck\n"
            "3 to show your duck\n"
            "4 to finish duckfishing\n");
}

void fish_duck(DuckPtr *sPtr){
    DuckPtr newDuck, previousDuck, currentDuck;
    char name[8];

    //initial value
    previousDuck = NULL;
    currentDuck = *sPtr;

    printf("Enter the name(max 8) :\n");
    scanf("%s", name);
    

    //allocate memory
    newDuck = malloc(sizeof(Duck));

    //check the memory
    if(newDuck!=NULL){//1. space is available
        //initial value
        strcpy(newDuck->d_name, name);
        newDuck->nextDuck = NULL;
        previousDuck =NULL;
        currentDuck = *sPtr;

        //compare the string and find the location
        while (currentDuck !=NULL && strcmp(name, currentDuck->d_name)==1){
            previousDuck = currentDuck;
            currentDuck = currentDuck->nextDuck;

        }

        //if the location is first
        if(previousDuck == NULL){
            newDuck->nextDuck = *sPtr; //first link the pointer
            *sPtr = newDuck; // change the head pointer
        }

        //else
        else{
            previousDuck->nextDuck =newDuck; //first link the prev pointer to new duck
            newDuck->nextDuck =currentDuck; //second link the new duck's pointer to currentDuck
        }
    }

    else{
        printf("%s not fished. No fishing line available\n",name);
    }

}


char release_duck(DuckPtr *sPtr){
    DuckPtr tempDuck, previousDuck, currentDuck;
    char name[8];

    printf("Enter the unwanted duck :\n");
    scanf("%s", name);
    //if the entered name is first member of list
    if (strcmp(name, (*sPtr)->d_name)==0){
        tempDuck = *sPtr; //헤더 Ptr을 임시로 저장합니다.
        *sPtr = (*sPtr)->nextDuck; //해더 ptr의 주소를 두번째 멤버의 주소로 정의합니다.
        free(tempDuck); //free로 메모리할당을 해제합니다.
    }

    else{
        //초기 설정
        previousDuck = *sPtr;
        currentDuck = (*sPtr) -> nextDuck;

        //입력한 이름과 같은 곳을 찾을 때까지 while문을 돌립니다.
        while(currentDuck!= NULL && strcmp(currentDuck->d_name,name) != 0){
            previousDuck = currentDuck;
            currentDuck = currentDuck->nextDuck;
        }
        //free를 합니다.
        if(currentDuck!=NULL){
            tempDuck = currentDuck;
            previousDuck->nextDuck = currentDuck->nextDuck;
            free(tempDuck);
        }
        
    }
}

void show_ducks(DuckPtr sptr){
    if(sptr == NULL){
        printf("You don't have any ducks");
    }
    else{
        while(sptr !=NULL){
            printf("%s-->", sptr->d_name);
            sptr = sptr->nextDuck;
            if(sptr == NULL){
                break;
            }
        }
        printf("NULL\n\n");
    }

}

void animated_ducks(DuckPtr sptr){
    char ASCII_P1[220]="";
    char ASCII_P2[220]="";
    char ASCII_P3[220]="";
    char ASCII_P4[220]="";
    char ASCII_P5[220]="";
    char ASCII_N6[220]="";
    int a = 0;

    if (sptr == NULL){
        printf("Your fish line is empty");
    }

    else{
        printf("Your caught duck is\n");
        while (sptr !=NULL){
            strcat(ASCII_P1, "       ,~~.         ");
            strcat(ASCII_P2, "      (  6 )-_,     ");
            strcat(ASCII_P3, " (\\___ )=='-'   ->  ");
            strcat(ASCII_P4, "  \\ .   ) )         ");
            strcat(ASCII_P5, "   \\ `-' /          ");
            strcat(ASCII_N6, "   11111111         ");
            
            sptr = sptr->nextDuck;
        }

        printf("%s\n", ASCII_P1);
        printf("%s\n", ASCII_P2);
        printf("%s\n", ASCII_P3);
        printf("%s\n", ASCII_P4);
        printf("%s\n", ASCII_P5);
        printf("%s\n", ASCII_N6);
    }    
}

int isEmpty(DuckPtr sPtr){
    return sPtr==NULL;
}
