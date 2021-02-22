// Fadi Elsadi
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

    
    int max = 0; 
    char f[argc];

    for(int i = 0; i < argc; i++){

        int len = strlen(argv[i]);
        
        if(len > max){
            
            max = len;
            strcpy(f, argv[i]); 

         }
         else if(len == max){

             strcat(f, " ");
             strcat(f, argv[i]);

         }
    
    }

    printf("\nThe longest command line argument(s): %s\n", f);
    printf("\n");
    
    return 0;
}

