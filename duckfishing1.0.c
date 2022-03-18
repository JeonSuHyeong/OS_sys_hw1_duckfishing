#include <stdio.h>
#include <stdlib.h>

struct listNode {
    char data;
    struct listNode *nextPtr; //self-pointer
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *, char);
char delete(ListNodePtr *, char);
int isEmpty(ListNodePtr );
void printList( ListNodePtr);
void instructions (void);

int main(){
    ListNodePtr startPtr = NULL;
    int choice;
    char item;

    instructions(); //display the manu
    printf("? ");
    scanf("%d", &choice);

    while (choice !=3 ){
        switch (choice){
            case 1:
                printf("Enter a character: ");
                scanf( "\n%c", &item);
                insert( &startPtr, item);
                printList( startPtr);
                break;
            case 2:
                if (!isEmpty(startPtr)) {
                    scanf("\n%c, &item");
                    
                    if (delete(&startPtr, item)){
                        printf("%c deleted.\n", item);
                        printList (startPtr);
                    }
                    else{
                        printf("%c not fountd.\n\n", item);
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
            "3 to end protgram\n");
}

// Insert a node at the stack top
void insert(ListNodePtr *sPtr, char value){
    ListNodePtr newPtr, previousPtr, currentPtr;

    newPtr = malloc(sizeof(ListNode));

    if (newPtr !=NULL){ //is space available
        newPtr->data = value;
        newPtr->nextPtr = value;
        
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
char delete(ListNodePtr *sPtr, char value){
    ListNodePtr previousPtr, currentPtr, tempPtr;

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

int isEmpty(ListNodePtr sPtr){
    return sPtr == NULL;
}

//print the list
void printList(ListNodePtr currentPtr){
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