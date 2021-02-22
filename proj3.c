// Project 3. Fadi Elsadi. I had to erase some lines to meet 250 line requirement. My format before was nicer. 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int menu();
void new_accounts(int *acc1, float *bal1, int *acc2, float *bal2);
void summary(int acc1, float bal1, int acc2, float bal2);
void withdraw(int acc, float *balance, float input);
void deposit(int acc, float *balance, float input);
void transfer(int acc1, float *bal1, int acc2, float *bal2, float bal);
void exchange(int a1, float *bal1, int a2, float *bal2);
int *high_balance(int *a1, float bal1, int *a2, float bal2, float *difference);
void reset(float *bal1, float *bal2);
void change(int *a1, int a2);

int main(){
    int input = 0, a1, a2, acc_chosen, acc_picked, t_a1, t_a2, reassign, chosen, new_a1, new_a2;
    float b1, b2, amount, a_transferd, t_amount, t_b1, t_b2, diff;
    char letter_2;
    do{
        menu();
        scanf("%d", &input);
       
        if (input == 0){
           
            printf("\n> > > > GOOD BYE!\n");
        }
        else if (input == 1){
           
            new_accounts(&a1, &b1, &a2, &b2);
        }
        else if (input == 2){
            
            summary(a1, b1, a2, b2);
        }
         else if(input == 3){
                
                printf("\n\nEnter account to withdraw (%d or %d):  ", a1, a2);
                scanf("%d", &acc_chosen);
                
                if(acc_chosen != a1 && acc_chosen != a2){
                   
                    printf("\n\nAccount %d doesn't exist!\n\n", acc_chosen);
                    continue;
                }

                printf("Enter amount to withdraw:  ");
                scanf("%f", &amount);
                
                if(acc_chosen == a1){
                    withdraw(acc_chosen, &b1, amount);
                }
                else if(acc_chosen == a2){
                    withdraw(acc_chosen, &b2, amount);
                }       
                
        }else if(input == 4){

                printf("\n\nEnter acount to deposit (%d or %d):  ", a1, a2);
                scanf("%d", &acc_chosen);
                
                if(acc_chosen != a1 && acc_chosen != a2){
                   
                    printf("\n\nAccount %d doesn't exist!\n\n", acc_chosen);
                    continue;
                }

                printf("Enter amount to deposit:  ");
                scanf("%f", &amount);
                
                if(acc_chosen == a1){
                    deposit(acc_chosen, &b1, amount);
                }
                else if(acc_chosen == a2){
                    deposit(acc_chosen, &b2, amount);
                }       
        }else if(input == 5){

            printf("\n\nEnter 'FROM' account and 'TO' account separated by a space:  ");
            scanf("%d %d", &t_a1, &t_a2);
            
            if(t_a1 != a1 && t_a1 != a2 && t_a2 != a2 && t_a2 != a1){
            
            printf("\n> > > > Account %d and %d don't exist!\n\n", t_a1, t_a2);
            continue;
            }
            
            if(t_a2 != a2 && t_a2 != a1){
                
                printf("\n> > > > Account %d doesn't exist!\n\n", t_a2);
                continue;

            }
            if(t_a1 != a1 && t_a1 != a2){
            
            printf("\n> > > > Account %d doesn't exist!\n\n", t_a1);
            continue;
            }
            if(t_a1 == t_a2){
                printf("\n> > > > Cannot transfer from and to the same account!\n\n");
                continue;
            }

            printf("Enter amount to transfer: $");
            scanf(" %f", &a_transferd);

            printf("\n");
            transfer(a1, &b1, a2, &b2, a_transferd);
      
        }else if(input == 6){
            
            char letter;

            printf("\nAre you sure to exchange balance of account %d and %d (y/n)? ", a1, a2);
            scanf(" %c", &letter);

            if(letter == 'y' || letter == 'Y'){

                exchange(a1, &b1, a2, &b2);
            }
            if(letter == 'n' || letter == 'N'){
                
                 continue;
            }
        }else if(input == 7){
            high_balance(&a1, b1, &a2, b2, &diff);
        }else if(input == 8){

            printf("\nAre you sure to reset balance of both accounts (y/n)? ");
            scanf(" %c", &letter_2);
            
            if(letter_2 == 'y' || letter_2 == 'Y'){

                 reset(&b1, &b2);

            }
            if(letter_2 == 'n' || letter_2 == 'N'){

                 continue;

            }
        }else if(input == 9){

            printf("\nWhich account number to change, %d or %d? ", a1, a2);
            scanf("%d", &chosen);

            if(chosen != a1 && chosen != a2){
                   
                printf("\n\nAccount %d doesn't exist!\n\n", chosen);
                continue;
            }
            if(chosen == a1){
 
                do{
                new_a1 = rand() % (59 - 55 + 1) + 55;
                  }while(new_a1 == a1 || new_a1 == a2);
                 
                  printf("\n> > > > Account %d is now changed to %d\n\n", chosen, new_a1);
                  change(&a1, new_a1);
            }else if(chosen == a2){
             do{ 
                 new_a2 = rand() % (59 - 55 + 1) + 55;
                 }while(new_a2 == a1 || new_a2 == a2);
                     printf("\n> > > > Account %d is now changed to %d\n\n", chosen, new_a2);
                     change(&a2, new_a2);
            }  
        }  
    }while (input != 0);
    return 0;
}
int menu(){
    printf(": ----------------------------------\n"); printf(": Main Menu\n:\n"); printf(": 1. New Accounts\n"); printf(": 2. All Accounts\n"); printf(": 3. Withdraw\n"); printf(": 4. Deposit\n");  printf(": 5. Transfer Fund\n"); printf(": 6. Exchange Balance\n"); printf(": 7. High Balance\n"); printf(": 8. Reset All Balance\n"); printf(": 9. Change Account Number\n"); printf(": 0. Exit\n"); printf(": ----------------------------------\n "); printf("--> Choose your transaction(1, 2..... 9. or 0 to exit): ");
    return 0;
}
void new_accounts(int *acc1, float *bal1, int *acc2, float *bal2){
    int min1 = 55, max1 = 59;
    int min2 = -10000, max2 = 99999;
    srand(time(NULL));

    do{
    *acc1 = rand() % (max1 - min1 + 1) + min1;
    *acc2 = rand() % (max1 - min1 + 1) + min1;
    }while(*acc1 == *acc2);

    *bal1 = (rand() % (max2 - min2 + 1) + min2) / 100.0;
    *bal2 = (rand() % (max2 - min2 + 1) + min2) / 100.0;

    printf("\n\n> > > > Two accounts created!\n\n\n");
}
void summary(int acc1, float bal1, int acc2, float bal2){
    printf("\n\n> > > >  %d:  $%.2f \n> > > >  %d:  $%.2f \n\n", acc1, bal1, acc2, bal2);
}
void withdraw(int acc, float *balance, float input){
    float old_balance = *balance;
    *balance = *balance - input;
    printf("\n> > > >  Account %d balance changed from $%.2f to $%.2f\n\n", acc, old_balance, *balance);
}
void deposit(int acc, float *balance, float input){
    float old_balance = *balance;
    *balance = *balance + input;
    printf("\n> > > >  Account %d balance changed from $%.2f to $%.2f\n\n", acc, old_balance, *balance);
}
void transfer(int acc1, float *bal1, int acc2, float *bal2, float transfer){
        float old_bal1 = *bal1;
        float old_bal2 = *bal2;
        *bal1 -= transfer;
        *bal2 += transfer;
        printf("> > > > Account %d balance changed from $%.2f to $%.2f", acc1, old_bal1, *bal1);
        printf("\n> > > > Account %d balance changed from $%.2f to $%.2f\n\n", acc2, old_bal2, *bal2);
}
void exchange(int a1, float *bal1, int a2, float *bal2){
    int temp = a1;
    a1 = a2;
    a2 = temp;
    float temp2 = *bal1;
    *bal1 = *bal2;
    *bal2 = temp2;
    
    printf("\n> > > > Account %d balance changed from $%.2f to $%.2f\n", a2, *bal1, *bal2);
    printf("> > > > Account %d balance changed from $%.2f to $%.2f\n\n", a1, *bal2, *bal1);
}
int *high_balance(int *a1, float bal1, int *a2, float bal2, float *difference){
         *difference = bal1 - bal2;
         float difference_2 = bal2 - bal1;
           
        if(*difference >= 200){    
            
            printf("\n> > > > Account %d ($%.2f) has a balance of $%.2f more than account %d ($%.2f) \n\n", *a1, bal1, *difference, *a2, bal2);
             return a1;
        }else if(difference_2 >= 200){
             
             printf("\n> > > > Account %d ($%.2f) has a balance of $%.2f more than account %d ($%.2f) \n\n", *a2, bal2, difference_2, *a1, bal1);
             return a2;
        }else{
            printf("\n > > > > No any account's balance is $200 or higher than the other's\n\n");
            return NULL;
        }
}
void reset(float *bal1, float *bal2){
    *bal1 = 0.00;
    *bal2 = 0.00;

    printf("\n> > > > Balance of both accounts are reset to $0.00\n\n");
}
void change(int *a1, int a2){
    int temp = *a1;
    *a1 = a2;
}