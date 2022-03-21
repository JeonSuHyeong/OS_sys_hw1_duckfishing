#include <stdio.h>
#include <stdlib.h>

struct duckNode {
    char data;
    struct duckNode *nextPtr; //self-pointer
    char ASCII_1[15];
    char ASCII_2[15];
    char ASCII_3[15];
    char ASCII_4[15];
    char ASCII_5[15];
    
};

typedef struct duckNode DuckNode;
typedef DuckNode *DuckNodePtr;

void insert(DuckNodePtr *, char);
char delete(DuckNodePtr *, char);
int isEmpty(DuckNodePtr );
void printList(DuckNodePtr);
void visualizeDuck(DuckNodePtr);
void instructions (void);
void visualizeDuck_beta(DuckNodePtr);

int main(){
    DuckNodePtr startPtr = NULL;
    int choice;
    char item;

    instructions(); //display the manu
    printf("? ");
    scanf("%d", &choice);

    while (choice !=3 ){
        switch (choice){
            case 1:
                printf("Enter a duck name: ");
                scanf( "\n%c", &item);
                insert( &startPtr, item);
                visualizeDuck( startPtr);
                break;
            case 2:
                if (!isEmpty(startPtr)) {
                    scanf("\n%c", &item);
                    
                    if (delete(&startPtr, item)){
                        printf("%c deleted.\n", item);
                        visualizeDuck (startPtr);
                    }
                    else{
                        printf("%c not found.\n\n", item);
                    }
                }
                else
                    printf("List is empty. \n\n");

                break;
            default:
                printf("Invaild choice. \n\n");
                instructions();
                break;
        }

        printf("? " );
        scanf("%d", &choice);
    }

    printf("End of run.\n");
    return 0;
}

void instructions(void){
    printf("Enter choice:\n"
            "1 to push a value on the stack\n"
            "2 to pop a value off the stack\n"
            "3 to printlist the duck art"
            "4 to end program\n");
}

// Insert a node at the stack top
void insert(DuckNodePtr *sPtr, char value){
    DuckNodePtr newPtr, previousPtr, currentPtr;

    newPtr = malloc(sizeof(DuckNode));

    if (newPtr !=NULL){ //is space available
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        
        previousPtr = NULL;
        currentPtr = *sPtr;

        while (currentPtr !=NULL && value> currentPtr->data){
            previousPtr =currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if(previousPtr == NULL){
            newPtr->nextPtr =*sPtr;
            *sPtr = newPtr;
        }
        else{
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr =currentPtr;
        }
    }
    else{
        printf("%c not inserted. No mermory available.\n",value);
    }
}

//Delete a list element
char delete(DuckNodePtr *sPtr, char value){
    DuckNodePtr previousPtr, currentPtr, tempPtr;

    if (value == (*sPtr )->data) {
        tempPtr = *sPtr;
        *sPtr = (*sPtr )->nextPtr;
        free(tempPtr);
        
        return value;
    }
    else {
        previousPtr = *sPtr;
        currentPtr = (*sPtr) -> nextPtr;

        while (currentPtr!=NULL  &&currentPtr -> data != value){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (currentPtr != NULL){
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }
    
    return '\0';
}

//Return 1 if the list is empty, 0 otherwise

int isEmpty(DuckNodePtr sPtr){
    return sPtr == NULL;
}

//print the list
void printList(DuckNodePtr currentPtr){
    if (currentPtr == NULL){
        printf("List is empty\n\n");
    }
    else{
        printf("The list is:\n");
        while (currentPtr !=NULL){
            printf("%c -->", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}

void visualizeDuck(DuckNodePtr currentPtr){
    if (currentPtr == NULL){
        printf("List is empty\n\n");
    }
    else{
        printf("The list is:\n");
        while (currentPtr !=NULL){
            printf("       ,~~.\n"
                   "      (  6 )-_,\n"
                   " (\\___ )=='-'\n"
                   "  \\ .   ) ) \n"
                   "   \\ `-' / \n");
            printf("    %c -->    ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}

void visualizeDuck_beta(DuckNodePtr currentPtr){
    if (currentPtr == NULL){
        printf("List is empty\n\n");
    }
    else{
        printf("The list is:\n");
        while (currentPtr !=NULL){
            printf("%c -->", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}