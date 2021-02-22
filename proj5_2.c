// Fadi Elsadi
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int read_line(char str[], int n);
void encrypt(char *msg, int shift);

#define LENGTH 80 + 1

int main(){

    char msg[LENGTH]; 
    int shift;

    printf("\nEnter the message to be encrypted: ");
    read_line(msg, 80);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    encrypt(msg, shift);
    puts(msg);
    printf("\n");

    return 0;
}     

void encrypt(char *msg, int shift){

    char *p; 
    //p = msg;

    printf("Encrypted message: ");

     for(p = msg; *p; p++){
        
        if (*msg >= 'A' && *msg <= 'Z')
            *msg = ((*msg - 'A') + shift) % 26 + 'A';
        else if (*msg >= 'a' && *msg <= 'z')
            *msg = ((*msg - 'a') + shift) % 26 + 'a';
        msg++;

     }

}

int read_line(char str[], int n){

    int ch, i = 0;

    while((ch = getchar()) != '\n'){
        
        if(i < n){
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;

}