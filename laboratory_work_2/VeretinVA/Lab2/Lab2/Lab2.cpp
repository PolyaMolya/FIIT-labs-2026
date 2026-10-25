#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mode1()
{
    srand(time(NULL));
    int s;
    int k = 1;
    int x = rand() % 1000+1;
    printf("a number (%i) has been chosen; enter your number:\n", x);
    scanf_s("%i", &s);
    if (s == x)
    {
        printf("guessed it in %i attempt\n", k);
    }
    else
    {
        while (s != x)
        {
            if (s > x)
            {
                printf("the chosen number is smaller\n");
                k += 1;
                scanf_s("%i", &s);
            }
            else
            {
                printf("the chosen number is greater\n");
                k += 1;
                scanf_s("%i", &s);
            }
        }
        printf("guessed it in %i attempt\n", k);
    }
    return 0;
}

int mode2()
{
    int x;
    int k = 0;
    int min = 1;
    int max = 1000;
    char ans;
    while (min <= max)
    {
        x = (min + max) / 2;
        printf("is your number %i?\n", x);
        printf("enter >, <, =:\n");
        scanf_s(" %c", &ans);
        k += 1;
        if (ans == '=')
        {
            printf("guessed in %i attempts\n", k);
            break;
        }
        else if (ans == '>')
        {
            min = x + 1;
        }
        else if (ans == '<')
        {
            max = x - 1;
        }
        else
        {
            printf("invalid answer; enter >, <, =\n");
        }
    }
    return 0;
}

int main()
{
    int mode;
    printf("choose mode:\n");
    printf("1 - you guess the number\n");
    printf("2 - computer guesses your number\n");
    scanf_s("%d", &mode);
    switch (mode)
    {
    case 1:
        mode1();
        break;
    case 2:
        mode2();
        break;
    }
    return 0;
}
