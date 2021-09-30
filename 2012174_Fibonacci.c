#include <stdio.h>
void add(char n1[], char n2[], char result[])
{
    int carry = 0;
    for (int j = 4999; j >= 0; j--)
    {
        int value = (n1[j] - '0') + (n2[j] - '0') + carry;
        result[j] = (value % 10) + '0';
        carry = value / 10;
    }
}
void paste2on1(char n1[], char n2[])
{
    for (int i = 4999; i >= 0; i--)
        n1[i] = n2[i];
}
char fib1[5000];
char fib2[5000];
char result[5000];
int main()
{
    for (int i = 0; i < 5000; i++)
    {
        fib1[i] = fib2[i] = result[i] = '0';
    }
    fib2[4999] = '1';
    int num;
    printf("Which term of the fibonacci series you want to know?\n");
    scanf("%d", &num);
    if (num == 0 || num == 1)
    {
        printf("%c", num + '0');
    }
    else
    {
        for (int i = 2; i < num; i++)
        {
            add(fib1, fib2, result);
            paste2on1(fib1, fib2);
            paste2on1(fib2, result);
        }
        int check = 0;
        printf("The %dth term of the fibonacci series is\n", num);
        for (int i = 0; i < 5000; i++)
        {
            if (check == 0 && result[i] == '0')
                continue;
            if (check == 0 && result[i] != '0')
                check = 1;
            printf("%c", result[i]);
        }
        printf("\n");
    }
    return 0;
}