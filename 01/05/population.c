#include <stdio.h>
#include <cs50.h>

int natalidade(int n, int x);

int main()
{
    int n = 0;
    int x = 0;
    while(n < 9)
    {
        n = get_int("Start size: \n");
    }
    while(x < n)
    {
        x = get_int("End size: \n");
    }
    printf("Years: %d\n", natalidade(n,x));
}

int natalidade(int n, int x)
{
    int i = 0;
    while (n < x)
    {
        //Nascem
        int nasce = n/3;
        //Morrem
        int morre = n/4;
        //Calcula a populacao
        n = n + nasce - morre;
        //Adiciona +1 ao ano
        i++;
    }
    return i;
}