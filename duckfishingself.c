#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct duck{
    char name[12];
    struct duck *nextPtr; //self
};

typedef struct duck Duck;
typedef Duck *DuckPtr;

//type of functions
void instructions();
void fish_duck(DuckPtr *, char);
char release_duck(DuckPtr *, char);
void isEmpty();
void show_ducks(DuckPtr *);

int main(){
    //initial value
    DuckPtr startPtr = NULL;
    int choice;
    char duck_name[12];

    //display the menu and input the choice 
    instructions();
    scanf("%d", &choice);

    while(choice !=4){
        switch (choice){
            //case 1: fish a duck
            case 1:
                printf("Enter the name(max 12): \n");
                scanf("%s", &duck_name);
                fish_duck(&startPtr, duck_name);
                show_ducks(startPtr);
                break;

            case 2:
                printf("Enter the name: \n");
                printf("\n");
                release_duck(&startPtr, duck_name);
                break;

            case 3:
                show_duck(startPtr);
                break;

            case 4:
                printf("End the program\n");
                break;

            default:
                printf("Invaild choice \n\n");
                instructions();
                break;

        }
        printf("Any gesture?");
        scanf("%d", &choice);
    }
}

void instructions(){
    printf("Enter your actions\n"
            "1 to fish a new duck\n"
            "2 to release the duck\n"
            "3 to check your duck\n"
            "4 to finish duckfishing\n");
}

void isEmpty(DuckPtr *sPtr){
        return sPtr == NULL;
}
void fish_duck(DuckPtr *sPtr, char d_name[12]){
    DuckPtr newPtr, previousPtr, currentPtr;

    //allocate memory
    newPtr = (struct Duck*)malloc(sizeof(Duck));

    //initial value
    previousPtr = NULL;
    currentPtr = sPtr;

    if(newPtr!=NULL){   
        //input name(string)       
        strcpy(newPtr->name, d_name);
        newPtr->nextPtr = NULL;

        previousPtr =NULL;
        currentPtr = *sPtr;

        //compare the name and find appropriate address
        while ((currentPtr !=NULL ) && (strcmp(d_name, currentPtr->name)==1)){
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

void show_duck(DuckPtr currentPtr){
    char ASCII_P1[200]=NULL;
    char ASCII_P2[200]=NULL;
    char ASCII_P3[200]=NULL;
    char ASCII_P4[200]=NULL;
    char ASCII_P5[200]=NULL;
    char ASCII_N6[200]=NULL;
    int a = strlen(currentPtr->name);
    int i;

    if (currentPtr == NULL){
        printf("Your fish line is empty");
    }

    else{
        printf("Your caught duck is\n");
        while (currentPtr !=NULL){
            strcat(ASCII_P1, "       ,~~.         ");
            strcat(ASCII_P2, "      (  6 )-_,     ");
            strcat(ASCII_P3, " (\\___ )=='-'   ->  ");
            strcat(ASCII_P4, "  \\ .   ) )         ");
            strcat(ASCII_P5, "   \\ `-' /          ");
            for (i=0 ; i < strlen(currentPtr->name)/4; i++)
            strcat(ASCII_N6, "\t%s\t\t\t\t", currentPtr->name);
            currentPtr = currentPtr->nextPtr;
        }

        printf("%s\n", ASCII_P1);
        printf("%s\n", ASCII_P2);
        printf("%s\n", ASCII_P3);
        printf("%s\n", ASCII_P4);
        printf("%s\n", ASCII_P5);
        printf("%s\n", ASCII_N6);
    }
}
