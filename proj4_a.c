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

    return 0;
}

void get_msg(char arr[], int *total)
{

    int i = 0;
    char ch;

    printf("\nEnter a message: ");

    for (i = 0, (ch = getchar()); i < MAX_MSG_LEN && ch != '\n'; ch = getchar())
    {

        if (isalpha(ch) == 0)
        {
            continue;
        }
        else
        {
            arr[i] = toupper(ch);
            i++;
            *total += 1;
        }
    }
}

bool palindrome(char arr[], int total)
{

    int i, j;

    for (i = 0, j = total - 1; i < total; i++, j--)
    {

        if (arr[i] != arr[j])
        {
            return false;
        }
    }

    return true;
}