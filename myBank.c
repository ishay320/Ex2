#include <stdio.h>

enum bool
{
    false,
    true
};

int bankCMD()
{
    double bankAccount[50][2];
    for (int i = 0; i < 50; i++) //zero the bank setting
    {
        bankAccount[i][0] = false;
        bankAccount[i][1] = 0;
    }

    int keepRunning = true;
    while (keepRunning)
    {

        printf("Please choose a transaction type:\n O-Open Account \n B-Balance Inquiry \n D-Deposit \n W-Withdrawal \n C-Close Account \n I-Interest \n P-Print \n E-Exit \n");
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
            exit(bankAccount);
            keepRunning = 0;
            break;
        default:
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

    printf("Initial deposit?:\n");
    double amount = 0;
    int read = scanf(" %lf", &amount);
    if (read == 0|amount<0) //check the input
    {
        printf("Input failed\n");
        return 0;
    }
    bankAccount[FreeSpace][0] = true;
    bankAccount[FreeSpace][1] = amount;
    FreeSpace += 901;
    printf("The number of the new account is: %d\n", FreeSpace);
    return 0;
}

int checkAccount(double bankAccount[50][2])
{
    int number = accountInput(bankAccount);
    if (number == -1)
    {
        return 0;
    }

    printf(" %.2f \n", bankAccount[number][1]);
    return 0;
}

int deposit(double bankAccount[50][2])
{
    int number = accountInput(bankAccount);
    if (number == -1)
    {
        return 0;
    }

    printf("How much to deposit?:\n");
    double amount = 0;
    int read = scanf(" %lf", &amount);
    if (read == 0) //check the input
    {
        printf("Input failed\n");
        return 0;
    }
    bankAccount[number][1] += amount;
    printf("After your deposit you have: %.2f \n", bankAccount[number][1]);
    return 0;
}

int withdraw(double bankAccount[50][2])
{
    int number = accountInput(bankAccount);
    if (number == -1)
    {
        return 0;
    }

    printf("How much to withdraw?:\n");
    double amount = 0;
    int read = scanf(" %lf", &amount);
    if (read == 0) //check the input
    {
        printf("Input failed\n");
        return 0;
    }
    if (amount<0)
    {
        printf("You cannot withdraw minus amount of money \n");
        return 0;
    }
    
    if (bankAccount[number][1] - amount < 0)
    {
        printf("You cannot withdraw that much money you dont have enough \n");
        return 0;
    }

    bankAccount[number][1] -= amount;
    printf("After your withdraw you have: %.2f \n", bankAccount[number][1]);
    return 0;
}

int close(double bankAccount[50][2])
{
    int number = accountInput(bankAccount);
    if (number == -1)
    {
        return 0;
    }

    bankAccount[number][0] = false;
    bankAccount[number][1] = 0;
    printf("The account number %d closed\n", number + 901);
    return 0;
}

int interest(double bankAccount[50][2])
{
    printf("How much interest?:\n");
    double amount = 0;
    int read = scanf(" %lf", &amount);
    if (read == 0) //check the input
    {
        printf("Input failed\n");
        return 0;
    }
    for (int i = 0; i < 50; i++)
    {
        if (bankAccount[i][0] == true)
        {
            bankAccount[i][1] += bankAccount[i][1] * (amount/100);
        }
    }
    return 0;
}

int accountInput(double bankAccount[50][2])
{
    printf("Account number?:\n");
    int number = -1;
    int read = scanf(" %d", &number);
    if (read == 0) //check the input
    {
        printf("Input failed\n");
        return -1;
    }
    number -= 901;
    if (number<0 | number> 50) //input check
    {
        printf("Input failed\n");
        return -1;
    }
    if (bankAccount[number][0] == false)
    {
        printf("This account is closed \n");
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
            printf("Account number %d have %.2f money\n", i + 901, bankAccount[i][1]);
        }
    }
    return 0;
}

int exit(double bankAccount[50][2])
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
