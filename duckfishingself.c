#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct duck{
    char name[10];
    struct duck *nextPtr; //self
};

typedef struct duck Duck;
typedef Duck *DuckPtr;

//type of functions
void instructions();
void fish_duck();
void release_duck();
void isEmpty();
void show_ducks();

int main(){
    //initial value
    DuckPtr startPtr = NULL;
    int choice;
    char duck_name[10];

    //display the menu and input the choice 
    instructions();
    printf("? ");
    scanf("%d", &choice);

    while(choice !=3){
        switch (choice){
            //case 1: fish a duck
            case 1:
                printf("Enter the name(max 10): \n");
                scanf("%s", &duck_name);
                fish_duck(&startPtr, duck_name);
                show_ducks(startPtr);
        }
    }
}

void instructions(){
    printf("Enter your actions\n"
            "1 to fish a new duck\n"
            "2 to release the duck\n"
            "3 to check your duck\n"
            "4 to finish duckfishing\n");
}

void fish_duck(DuckPtr *sPtr, char d_name[10]){
    DuckPtr newPtr, previousPtr, currentPtr;

    //allocate memory
    newPtr = malloc(sizeof(Duck));

    //initial value
    previousPtr = NULL;
    currentPtr = sPtr;

    if(newPtr!=NULL){          
        strcpy(newPtr->name, d_name);

        newPtr->nextPtr = NULL;

        previousPtr =NULL;
        currentPtr = *sPtr;
    //compare the name and find appropriate address
        while ((currentPtr !=NULL )&& (strcmp(d_name, currentPtr->name)==1)){
            previousPtr = currentPtr;
            currentPtr = currentPtr ->nextPtr;
        }
        //if the position is first
        if(previousPtr==NULL){
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }

        else{
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else{
        printf("%s not fished. No fishing line available.\n", d_name);
    }


}