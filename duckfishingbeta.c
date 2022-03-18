#include <stdio.h>
#include <stdlib.h>

struct duck_chara{
    char data[10]; //duck's name (max 10)
    struct duck_chara *nextduckPtr;
};

typedef struct duck_chara Duck;
typedef Duck *DuckNodePtr;

//functions
void instructions(void); //display the menu
int isEmpty(DuckNodePtr );
void insert(DuckNodePtr *,char);
void printlist(DuckNodePtr);


int main(){
    DuckNodePtr startPtr = NULL;
    int choice;
    char item;

    instructions(); //display the menu
    printf("? ");
    scanf("%d", choice);

    while(choice !=3){
        switch (choice){
            case 1:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insert(&startPtr, item);
                printlist(startPtr);
                break;

        }
    }
}

void instructions(void){
    printf("Select the actions"
            "1. Insert the duck"
            "2. pop the duck from list"
            "3. animating ducks"
            "4. End the process");
}

int isEmpty(DuckNodePtr sPtr){ //check the list. 1 to empty, 0 otherwise
    return sPtr == NULL;
}

void insert(DuckNodePtr *sPtr, char value){
    DuckNodePtr newPtr, previousPtr, currentPtr, tempPtr;

    newPtr = malloc (sizeof(Duck));

    if (newPtr !=NULL){ //space is available
        newPtr->data[10] = value;
        newPtr->nextduckPtr = value;

        previousPtr = NULL;
        currentPtr =*sPtr;

        while (currentPtr !=NULL && value>currentPtr->data){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextduckPtr;
        }

        if(currentPtr !=NULL){
            tempPtr = currentPtr;
            previousPtr->nextduckPtr = currentPtr -> nextduckPtr;
        }
    }
}