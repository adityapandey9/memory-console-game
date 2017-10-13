#include <stdio.h>
#include <time.h>
#include <conio.h>
#define E 6
#define M 8
#define H 12
#define E_MIN 65
#define E_MAX 90
#define H_MIN 48
#define E_TIME 3500
#define M_TIME 3000
#define H_TIME 2500
#define w 30

void random_string(char *,unsigned ,int ,int );
void delay(int );
void randomness(char *,int ,int ,int ,int ,int );

int main()
{
    int i,x,y=5,a,cs=1;
  char s[30];
  do
  {   top:
      system("cls");
      system("color 79");
      printf("1: Start the game\n");
      printf("0: Exit\n");
      printf("Please enter your choice\n");
      scanf("%d",&i);

      switch(i)
      {

      case 1:   getop:
                system("cls");
                printf("1: Easy\n");
                printf("2: Medium\n");
                printf("3: Hard\n");
                printf("0: Back\n");
                printf("Please enter your choice\n");
                scanf("%d",&x);

                switch(x)
                {
                  easy: case 1: system("cls");
                                randomness(s,E,E_MIN,E_MAX,E_TIME,1);
                                printf("\nDo you want to play more?(1 for YES and 0 for NO)\n");
                                scanf("%d",&a);
                                if(a)
                                    goto easy;
                                break;
                   medi:  case 2: system("cls");
                                  randomness(s,M,H_MIN,E_MAX,M_TIME,2);
                                  printf("\nDo you want to play more?(1 for YES and 0 for NO)\n");
                                  scanf("%d",&a);
                                  if(a)
                                    goto medi;
                                  break;
                  hard: case 3: system("cls");
                                randomness(s,H,H_MIN,E_MAX,H_TIME,3);
                                printf("\nDo you want to play more?(1 for YES and 0 for NO)\n");
                                scanf("%d",&a);
                                if(a)
                                    goto hard;
                                break;
                        case 0: goto top;
                                break;
                        default: printf("\nInvalid input\n");
                                 delay(1000);
                                 goto getop;
                                 break;
                }
                break;

        case 0: printf("\nExit\n");
                break;
        default: printf("\nInvalid input is given\n");
                 delay(1000);
                 goto top;
                 break;
      }
      system("cls");
      printf("\nDo you really want to Exit from the game?(1 for YES and 0 for NO)\n");
      scanf("%d",&cs);
  }while(cs==0);
    return 0;
}


void randomness(char * s,int as,int mins,int maxs,int tims,int d)
{

    int y=5;
    system("cls");
    if(d==1)
    printf("\nEasy\n");
    else if(d==2)
        printf("\nMedium\n");
    else if(d==3)
        printf("\nHard\n");
    printf("\nPlease remember character and their sequence to win\n");
    delay(1500);

    char b[30];
    int i,re=0;
    random_string(s, as,mins,maxs);
    printf("\nHere is your choice\n");
    for(i=0;i<as;i++)
    {
        printf("%c ",toupper(s[i]));
    }
    delay(tims);
    system("cls");
        printf("\nHere is your choice\n\n");
    for(i=0;i<as;i++)
	{
		printf("* ");
	}

    printf("\nPlease enter Character what your remember\n\n");
    fflush(stdin);
    for(i=0;i<as;i++)
    {
        scanf("%c",&b[i]);
    }
    for(i=0;i<as;i++)
    {
        if(toupper(s[i])==b[i])
            re++;
    }
     if(re==as-1)
    {
        printf("\nYou won CHARACTER MATCHES: %d\nYou entered: %s\nWhat was that: %s\n",re,b,s);
    }

    else
    {
        printf("\nSorry you lose CHARACTER MATCHES: %d\nWhat was that: %s\nWhat you have entered: %s\n",re,s,b);
    }


}

void random_string(char * string, unsigned length,int min,int max)
{
  srand((unsigned int) time(0) + getpid());
  /* ASCII characters min to max */
  unsigned int num_chars = length-1;
  unsigned int i;
  unsigned int s;
  for (i = 0; i < num_chars; i++)
    {
            s=rand() % (max - min + 1) + min;
            if(s>=58&&s<=64)
            {
             string[i]=65+i;
            }
            else
            {
                 string[i] = s;
            }
    }

  string[num_chars] = '\0';
}

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause ){
        now = clock();
	}
}


