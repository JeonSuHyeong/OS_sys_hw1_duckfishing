#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct duck{
    char d_name[8];
    struct duck *nextDuck;
};

typedef struct duck Duck;
typedef Duck *DuckPtr;

//functions
void instructions();
void caution();
void fish_duck(DuckPtr *);
void release_duck(DuckPtr *);
int isEmpty(DuckPtr);
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
                system("clear");
                if (d_cnt<10){
                    fish_duck(&startPtr);
                    animated_ducks(startPtr);
                    d_cnt++;
                }
                else{
                    printf("Too many ducks!\n");
                    printf("You can't fish more duck\n");
                    printf("Try another action\n\n");
                }
                break;
            //release the duck
            case 2:
                system("clear");
                if (!isEmpty(startPtr)){
                    release_duck(&startPtr);
                    animated_ducks(startPtr);
                    d_cnt--;
                    break;
                }
                else{
                    caution();
                    break;
                }
            //show your ducks
            case 3:
                system("clear");
                if(!isEmpty(startPtr)){
                    animated_ducks(startPtr);
                    break;
                }
                else{
                    caution();
                    break;
                }
            default:
                printf("Invaild choice.\n\n ");
                break;
        }
        instructions();
        scanf("%d", &choice);
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
    int check_pos;

    printf("You fish a new duck!\n");
    printf("Name the duck(max 8) :\n");
    scanf("%s", name);
    
    //allocate the new memory
    newDuck = (struct DuckPtr*)malloc(sizeof(Duck));

    //check the memory
    if(newDuck!=NULL){//1. space is available
        //initial value
        strcpy(newDuck->d_name, name);
        newDuck->nextDuck = NULL;

        previousDuck = NULL;
        currentDuck = *sPtr;
        
        //initial check point
        if(currentDuck==NULL){
            check_pos = 1;
        }
        else{
            check_pos=strcmp(name, currentDuck->d_name);
        }

        //compare the string and find the location
        while (currentDuck !=NULL && check_pos>0){
            printf("%d  %s\n", check_pos, currentDuck->d_name);
            previousDuck = currentDuck;
            currentDuck = currentDuck->nextDuck;
            if(currentDuck!=NULL){
                check_pos=strcmp(name, currentDuck->d_name);
            }
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


void release_duck(DuckPtr *sPtr){
    DuckPtr tempDuck, previousDuck, currentDuck;
    char name[8];

    printf("Enter the name to release :\n");
    scanf("%s", name);
    //if the entered name is first member of list
    if (strcmp(name, (*sPtr)->d_name)==0){
        tempDuck = *sPtr; 
        *sPtr = (*sPtr)->nextDuck; 
        free(tempDuck); 
    }

    else{

        previousDuck = *sPtr;
        currentDuck = (*sPtr) -> nextDuck;


        while(currentDuck!= NULL && strcmp(currentDuck->d_name,name) != 0){
            previousDuck = currentDuck;
            currentDuck = currentDuck->nextDuck;
        }

        if(currentDuck!=NULL){
            tempDuck = currentDuck;
            previousDuck->nextDuck = currentDuck->nextDuck;
            free(tempDuck);
        }
        
    }
}

void animated_ducks(DuckPtr sptr){
    char ASCII_P1[220]="";
    char ASCII_P2[220]="";
    char ASCII_P3[220]="";
    char ASCII_P4[220]="";
    char ASCII_P5[220]="";
    char ASCII_N6[220]="";
    char ASCII_N6_temp[25] = "                    ";
    int i,len;

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

            len =strlen(sptr->d_name);
            for (i=0;i<len;i++){
                ASCII_N6_temp[3+i] = sptr->d_name[i];
            }

            strcat(ASCII_N6, ASCII_N6_temp);
            
            
            sptr = sptr->nextDuck;
            

            len = 0;
            strcpy(ASCII_N6_temp,"                    ");
        }

        printf("%s\n", ASCII_P1);
        printf("%s\n", ASCII_P2);
        printf("%s\n", ASCII_P3);
        printf("%s\n", ASCII_P4);
        printf("%s\n", ASCII_P5);
        printf("%s\n\n", ASCII_N6);
    }    
}

int isEmpty(DuckPtr sPtr){
    return sPtr==NULL;
}

void caution(){
    printf("You don't have any ducks\n\n");
    printf("Try another action\n\n");
}