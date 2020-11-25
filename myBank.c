#include <stdio.h>

void bankCMD(){
    int stop = 1;
   while (stop)
   {
    char c;
    printf("Transaction type?:\n");
    scanf("%c",&c);
    
    switch (c)
    {
    case 'O':
        printf("Initial deposit?:\n");
        break;
        case 'B':
        printf("Account number?:\n");
        break;
        case 'D':
        printf("Account number?:\n");
        break;
        case 'W':
        printf("Account number?:\n");
        break;
        case 'C':
        printf("Account number?:\n");
        break;
        case 'I':
        printf("Interest rate?:\n");
        break;
        case 'P':
        break;
        case 'E':
        stop = 0;
        break;
    default:
        break;
    }
   }
}

int open(double* bankAcounts[]){
    int accountNumber = 0;
        scanf("%o",&accountNumber);
        if (bankAcounts[accountNumber]!=NULL)
        {
            
        }
        
}