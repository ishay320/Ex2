#include <stdio.h>


int bankCMD();
int accountInput(double bankAccount[50][2]);
int Initial(double bankAccount[50][2]);
int checkAccount(double bankAccount[50][2]);
int deposit(double bankAccount[50][2]);
int withdraw(double bankAccount[50][2]);
int close(double bankAccount[50][2]);
int interest(double bankAccount[50][2]);
int accountInput(double bankAccount[50][2]);
int print(double bankAccount[50][2]);
int exitE(double bankAccount[50][2]);

enum bool
{
    false,
    true
};

int bankCMD(){
    double bankAccount[50][2];
    for (int i = 0; i < 50; i++) //zero the bank setting
    {
        bankAccount[i][0] = false;
        bankAccount[i][1] = 0;
    }

    int keepRunning = true;
    while (keepRunning)
    {

        printf("\nPlease choose a transaction type:\n O-Open Account \n B-Balance Inquiry \n D-Deposit \n W-Withdrawal \n C-Close Account \n I-Interest \n P-Print \n E-Exit \n");
        char c;
        scanf(" %c", &c);
        switch (c)
        {
        case 'O':
            Initial(bankAccount);
            break;
        case 'B':
            checkAccount(bankAccount);

            break;
        case 'D':
            deposit(bankAccount);
            break;
        case 'W':
            withdraw(bankAccount);
            break;
        case 'C':
            close(bankAccount);
            break;
        case 'I':
            interest(bankAccount);
            break;
        case 'P':
            print(bankAccount);
            break;
        case 'E':
            exitE(bankAccount);
            keepRunning = 0;
            break;
        default:
            printf("Invalid transaction type\n");
            break;
        }
    }
    return 0;
}

int ScreenRead()
{
    return 0;
}

int Initial(double bankAccount[50][2])
{
    int FreeSpace = -1;
    for (int i = 0; i < 50; i++) //find free space
    {
        if (bankAccount[i][0] == false)
        {
            FreeSpace = i;
            break;
        }
    }
    if (FreeSpace == -1)
    {
        printf("Sorry, there is no free accont\n");
        return 0;
    }

    printf("Please enter amount for deposit: ");
    double amount = 0;
    int read = scanf(" %lf", &amount);
    if (amount<0)
    {
        printf("Invalid Amount\n");
        return 0;
    }
    
    if (read == 0) //check the input
    {
        printf("Failed to read the amount\n");
        return 0;
    }
    bankAccount[FreeSpace][0] = true;
    bankAccount[FreeSpace][1] = amount;
    FreeSpace += 901;
    printf("New account number is: %d\n", FreeSpace);
    return 0;
}

int checkAccount(double bankAccount[50][2])
{
    int number = accountInput(bankAccount);
    if (number == -1)
    {
        return 0;
    }

    printf("The balance of account number %d is: %.2f\n",number+901 , bankAccount[number][1]);
    return 0;
}

int deposit(double bankAccount[50][2])
{
    int number = accountInput(bankAccount);
    if (number == -1)
    {
        return 0;
    }

    printf("Please enter the amount to deposit: ");
    double amount = 0;
    int read = scanf(" %lf", &amount);
    if (read == 0) //check the input
    {
        printf("Failed to read the amount\n");
        return 0;
    }
    if (amount <0)
    {
        printf("Cannot deposit a negative amount\n");
        return -1;
    }
    
    bankAccount[number][1] += amount;
    printf("The new balance is: %.2f \n", bankAccount[number][1]);
    return 0;
}

int withdraw(double bankAccount[50][2])
{
    int number = accountInput(bankAccount);
    if (number == -1)
    {
        return 0;
    }

    printf("Please enter the amount to withdraw: ");
    double amount = 0;
    int read = scanf(" %lf", &amount);
    if (read == 0) //check the input
    {
        printf("Input failed\n");
        return 0;
    }
    
    if (bankAccount[number][1] - amount < 0)
    {
        printf("You cannot withdraw that much money you dont have enough \n");
        return 0;
    }

    bankAccount[number][1] -= amount;
    printf("The new balance is: %.2f \n", bankAccount[number][1]);
    return 0;
}

int close(double bankAccount[50][2])
{
 printf("Please enter account number: ");
    int number = -1;
    int read = scanf(" %d", &number);
    if (read == 0) //check the input
    {
        printf("Failed to read the account number\n");
        return -1;
    }
    number -= 901;
    if (number<0 | number> 50) //input check
    {
        printf("Invalid account number\n");
        return -1;
    }
    if (bankAccount[number][0] == false)
    {
        printf("This account is already closed\n");
        return -1;
    }

    bankAccount[number][0] = false;
    bankAccount[number][1] = 0;
    printf("Closed account number %d\n", number + 901);
    return 0;
}

int interest(double bankAccount[50][2])
{
    printf("Please enter interest rate: ");
    int amount = 0;
    int read = scanf(" %d", &amount);
    if (read == 0) //check the input
    {
        printf("Failed to read the interest rate\n");
        return 0;
    }
    if (amount < 0)
    {
        printf("Invalid interest rate\n");
        return -1;
    }
    for (int i = 0; i < 50; i++)
    {
        if (bankAccount[i][0] == true)
        {
            bankAccount[i][1] += bankAccount[i][1] * ((double)amount/100);
        }
    }
    return 0;
}

int accountInput(double bankAccount[50][2])
{
    printf("Please enter account number: ");
    int number = -1;
    int read = scanf(" %d", &number);
    if (read == 0) //check the input
    {
        printf("Failed to read the account number\n");
        return -1;
    }
    number -= 901;
    if (number<0 | number> 50) //input check
    {
        printf("Invalid account number\n");
        return -1;
    }
    if (bankAccount[number][0] == false)
    {
        printf("This account is closed\n");
        return -1;
    }
    
    return number;
}

int print(double bankAccount[50][2])
{
    for (int i = 0; i < 50; i++)
    {
        if (bankAccount[i][0] == true)
        {
            printf("The balance of account number %d is: %.2f\n", i + 901, bankAccount[i][1]);
        }
    }
    return 0;
}

int exitE(double bankAccount[50][2])
{
    for (int i = 0; i < 50; i++)
    {
        if (bankAccount[i][0] == true)
        {
            bankAccount[i][1] = 0;
            bankAccount[i][0] = false;
        }
    }
    return 0;
}
