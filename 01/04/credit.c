#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool validarCartao (int n);
int somarConjuntos (long int n, int tam);
void identificarCartao (int n);

int main ()
{
    long int numeroCartao = get_long("numeros: ");
    char numeros[17];
    sprintf(numeros, "%ld", numeroCartao);
    int tam = strlen(numeros);
    int n;
    if(numeros[0] != '4')
    {
        n = ((numeros[0]-'0')*10)+(numeros[1]-'0');
    }
    else
    {
        n = (numeros[0]-'0');
    }

    if (tam < 13) {
        return 0;
    }
    else
    {
        if(validarCartao(somarConjuntos(numeroCartao, tam)))
            {
                identificarCartao(n);
            }
        else
        {
            identificarCartao(n);
        }
    }
}

bool validarCartao (int n)
{
    if (n % 10 == 0)
    {
        return true;
    }
    return false;
}
int somarConjuntos (long int n, int tam)
{
    char numeros[tam];
    sprintf(numeros, "%ld", n);
    int soma1[tam/2 + 1];
    int soma2[tam/2];

    for(int i = 0; i < tam/2;i++){
        soma2[i] = ' ';
        soma1[i] = ' ';
        if(tam/2 == i+1)
        {
            soma1[i + 1] = ' ';
        }
    }
    int j = 0;
    int k = 0;
    for (int i = tam - 1; i >= 0; i--)
    {
        int p = i % 2;
        if (p == 0)
        {
            soma1[j] = numeros[i] - '0';
            soma1[j] = soma1[j] * 2;
            j++;
        }
        else if (p == 1)
        {
            soma2[k] = numeros[i] - '0';
            k++;
        }
    }
    int total = 0;
    for (int i = j - 1; i >= 0; i--)
    {
        if(i == j - 1)
        {
            if( soma1[i] > 9)
            {
                total = total + soma1[i] - 10 + 1;
            }
            else
            {
                total = total + soma1[i];
            }
        }
        else
        {
            if (soma1[i] > 9)
            {
                total = total + soma1[i] - 10 + 1 + soma2[i];
            }
            else
            {
                total = total + soma1[i] + soma2[i];
            }
        }

    }
    return total;
}
void identificarCartao(int n)
{
    if(n == 34 || n == 37)
    {
        printf("AMEX\n");
    }
    else if (n == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("MASTERCARD\n");
    }
}