#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



struct NODE  
{
   
   struct NODE* next;
   int data;
};


struct NODE* Head = NULL; // Head는 초기 Null


struct NODE* NewNode(int data) // 특정 데이터를 받아 새로운 NODE에 집어넣는다
{
   struct NODE* pointer;     // NODE를 가리킬 수 있는 pointer하나 생성 
   struct NODE* n3 = (struct NODE*)malloc(sizeof(struct NODE));  // n3 pointer가 NODE구조체 하나를 가리키도록 한다. 
   pointer = n3;             // pointer -> n3 
   pointer->data = data;     // pointer -> n3 -> data에 입력 받은 값을 집어넣음 
   pointer->next = NULL;     // pointer -> n3 -> next는 가리키는게 없으니 NULL  
   return pointer;          

};

void insert(struct NODE* newNode)  // 데이터 삽입 
{
   if (Head == NULL)              // HEAD가 비어있으면 (가장 앞이 비어있으면)
   {
      Head = newNode;            // HEAD에 넣음 
   }

   else
   {
      struct NODE* list = Head;  // list 포인터 생성 -> Head 
      while (list->next != NULL) // list -> Head -> next가 Null이 아니면 (값이 있으면) 계속 뒤로 간다
         list = list->next;
      list->next = newNode;      // 리스트 끝에 오면 newNode 집어넣는다

   }

};


void delete_node(int num)   // 입력받은 데이터와 일치하는 값을 삭제
{
   struct NODE* list = Head;  // list 포인터 생성 -> Head 
   if (Head == NULL)          // Head 가 Null이면 (list 생성전이면) 삭제할 것이 없으니 종료 
      return;

   else if (Head->data == num) // Head에 들어있는 data가 입력받은 값과 일치한다면 
   {
      Head = Head->next;      // 그 값을 가리키는 pointer를 없애서 누락시킴 ! (제거)
      return;
   }
   else // 앞부분은 Head가 Null일 경우 고려한것 이후는 list 중간 부분 탐색 
   {
      while (list->next != NULL) // list -> next가 Null이 아날때까지 반복 
      {
         if (list->next->data == num) // list -> next의 데이터가 입력받은 값과 일치하면
         {
            list->next = list->next->next; // 그 값을 가리키는 pointer를 없애서 누락시킴 ! (제거)
            return;
         }
         list = list->next; // list -> next의 데이터가 입력받은 값과 일치하지않으면 계속 진행 
      }
   }
};




void print(struct NODE* head) // 현 낚시 상태를 출력하는 함수 
{
   

   for (struct NODE* list = head; list != NULL; list = list->next) // list -> next가 Null이 아닐때까지 계속 반복 
      printf("%d -->", list->data);


};




int main()
{
   int i = 1;
   int decision;
   int decision1;
   int deletion;



   // 난수생성 
   // 원래 Linked list에서는 원하는 데이터를 리스트에 삽입해야하지만, 오리낚시를 하는 상황에서는
   // 어떤 오리가 잡힐 지 알 수가 없기 때문에, 데이터 삽입 시 1~10사이의 랜덤의 수가 삽입되도록 하고 싶었습니다 


   srand((unsigned)time(NULL));
   int nResult[10] = { 0, };
   int count = 0;
   int num = 0;
   int exist = 0; // 중복되지않는 난수를 만들어내야하기 때문에 그를 체크하기 위한 변수 

   while (count < 10)
   {
      exist = 0;
      num = rand() % 10 + 1; // 난수를 10으로 나누고 남은 나머지에 + 1 =>>> 1~10까지의 수를 생성하겠다

      for (int i = 0; i < 10; i++)  // 10개 다 검사
      {
         if (num == nResult[i]) // 같은 놈이 있다면 
            exist = 1;      // exist변수를 true로 ! 
      }

      if (!exist)             // exist가 false일 경우에만 (이미 뽑힌 것들 중에 중복된게 없을 경우에만)
      {
         nResult[count++] = num; // nResult값에 집어 넣는다.  
      }

      // nResult[0] , nResult[1] ,  ㅡ ㅡ ㅡ , nResult[9] => 겹치지 않는 1~10까지 정수

   }




   printf("현재 호수에는 1번부터 10번까지 총 10마리의 오리가 있습니다!\n");
   printf("낚시를 시작하려면 1번을, 낚시를 마치려면 0번을 눌러주세요\n");
   scanf("%d", &decision);
   system("cls");

   fflush(stdin); //하다보니 scanf가 무시되는 경우가 있어서 버퍼를 비워줌. 아마 %d앞에 공백을 썼었기 때문이 아닌가 싶은데
               // %d앞에 공백을 없애니 괜찮아졌지만, 혹시모르니 남겨뒀습니다 


   if (decision == 0) exit(0); // 0번을 누르면 낚시를 종료 exit(0) <- 프로그램 정상종료 
   else // 그 외의 경우 낚시를 시작한다 
   {
      struct NODE* n0 = (struct NODE*)malloc(sizeof(struct NODE)); // 동적할당을 위한 malloc, 
                                    // malloc은 기본적으로 void를 반환하므로 앞에 NODE*로 형변환을 해줘야함 
      n0 = NewNode(nResult[0]);
      insert(n0);

      
      print(Head);

      while (getchar() == '\n')break;
   }




   while (1)
   {

      printf("\n\n그만두시려면 0번\n낚시를 계속 하시려면 1번\n잡은 오리를 놓아주려면 2번을 눌러주세요\n\n\n");
      scanf("%d", &decision1);
      printf("\n\n");
      fflush(stdin);

      if (decision1 == 0) // 그만두려면 0번 
      {
         printf("낚시를 종료합니다.\n");
         exit(1);
      }


      else if (decision1 == 1) // 낚시를 계속하려면 1번 
      {
         if (i == 10) // 모든 오리를 다 잡으면 ! 
         {
            printf("모든 오리가 한번씩 잡혔습니다.\n\n\n");
            print(Head);
            exit(0);
         }
         else // 오리잡기 
         {

            struct NODE* n1 = (struct NODE*)malloc(sizeof(struct NODE));
            n1 = NewNode(nResult[i]);

            insert(n1);
            print(Head);
            i++;

         }
      }
      else if (decision1 == 2) // 오리를 제거하려면 2번 
      {
         printf("삭제할 오리의 번호를 입력하세요:  ");
         scanf("%d", &deletion);
         printf("\n\n");

         fflush(stdin);

         delete_node(deletion);
         print(Head);

      }


      else
      {
         printf("잘못된 입력입니다\n\n");
         break;
      }

   }

}