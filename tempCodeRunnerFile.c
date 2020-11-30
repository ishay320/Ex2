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