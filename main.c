#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void game(int, int);
int choosemin();
int choosemax(int);

int main(){
    printf("Number guessing game\n");
    printf("********************\n");
 
    int min = choosemin();
    int max = choosemax(min);

    game(min, max);

    return 0;
}

void game(int min, int max){
    int guess = 0;
    int tries = 0;
    srand(time(0));
    int number = rand() % (max - min + 1) + min;
    int c;
    int boundary_max = 1000;
    bool pass = false;
    char term;

    do
    {
        printf("Choose a number between %d-%d: \n", min, max);

        if(scanf("%d%c", &guess, &term) != 2 || guess > boundary_max || guess < 0 || term != '\n')
            {
                printf("Invalid input\n");
                while ((c = getchar()) != '\n' && c != EOF) { }
            }

        else if(guess != number)
        {
            tries += 1;
            if(number > guess)
            {
                printf("Incorrect guess: Too low\n");
            }
            else
            {
                printf("Incorrect guess: Too high!\n");
            }
        }

        else
        {
            tries += 1;
            printf("Correct guess: %d tries\n", tries);
            pass = true;
        }

    }while (pass == false);
}
int choosemin(){
    int min = 0;
    int boundary_min = 500;
    bool pass = false;
    int c;
    char term;

    do
    {
        printf("Choose a minimum number to guess (max 500): \n");

        if(scanf("%d%c", &min, &term) != 2 || min > boundary_min || term != '\n' || min < 0)
        {
            printf("Invalid input\n");
            while ((c = getchar()) != '\n' && c != EOF) { }
        }

        else
        {
            pass = true;
        }

    }while(pass == false);
    
    return min;
}

int choosemax(int min){
    int max = 0;
    int boundary_max = 1000;
    bool pass = false;
    int c;
    char term;
    
    do
    {
       printf("Choose a maximum number to guess (max 1000): \n");
       
       if(scanf("%d%c", &max, &term) != 2 || max > boundary_max || min > max || term != '\n' || max < 0)
       {
          printf("Invalid input\n");
          while ((c = getchar()) != '\n' && c != EOF) { }
       }

       else
       {
          pass = true;
       }

    } while (pass == false);
    
    return max;
}