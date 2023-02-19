#include <stdio.h>
#include <cs50.h>

float MOEDAS[4] =
{
    0.25, 0.10, 0.05, 0.01
};

int quantidadeMoeda(float n);
float convert(float n);

int main()
{
    float troco = 0.00;
    while (true)
    {
        while (troco < MOEDAS[3])
        {
            troco = get_float("Troca devida: ");
        }
        printf("%d \n", quantidadeMoeda(troco));
        break;
    }
}

int quantidadeMoeda(float n)
{
    float aux = convert(n);
    int cont;
    int i;
    i = cont = 0;
    while (true)
    {
        if (i == 4)
        {
            i = 0;
        }

        aux = aux - MOEDAS[i];

        if (convert(aux) == 0)
        {
            return ++cont;
        }

        if (aux < 0)
        {
            aux = aux + MOEDAS[i];
            i++;
        }
        else
        {
            cont++;
        }



    }
    return cont;
}
//Converter 0.090000 para 0.09
float convert(float n)
{
    int a = n * 1000;
    float b = a;
    float aux = b / 1000;
    return aux;
}