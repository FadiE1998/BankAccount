#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void get_msg(char arr[], int *total);
bool palindrome(char arr[], int total);

#define MAX_MSG_LEN 80

int main()
{
    char arr[MAX_MSG_LEN];
    int total = 0;
    bool result = false;

    get_msg(arr, &total);

    result = palindrome(arr, total);

    if (result)
    {
        printf("Is a palindrome\n");
    }
    else
    {
        printf("Not a palindrome\n");
    }

    //  printf("%s\n%d\n", arr, total);

    return 0;
}

void get_msg(char arr[], int *total)
{
    char ch, *p = arr;

    printf("\nEnter a message: ");

    for ((ch = getchar()); ch != '\n'; ch = getchar())
    {

        if (isalpha(ch) == 0)
        {
            continue;
        }
        else
        {
            *p = toupper(ch);
            p++;
            *p = '\0';
            *total += 1;
        }
    }
}

bool palindrome(char arr[], int total)
{
    char *p = arr;
    char *j = arr + total - 1;

    for (; *p != '\0'; p++, j--)
    {

        if (*p != *j)
        {
            return false;
        }
    }

    return true;
}