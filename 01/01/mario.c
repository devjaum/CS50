#include <stdio.h>
#include <cs50.h>

void mario(int n);

int main()
{
    while (true)
    {
        int n = get_int("Tamanho: ");
        if (n > 0 && n < 9)
        {
            mario(n);
            return false;
        }
    }

}

void mario(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j + i >= n - 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}