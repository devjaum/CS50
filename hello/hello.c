#include <stdio.h>
#include <cs50.h>

int main(){
    string nome = get_string("Qual é seu nome? \n");
    printf("Olá, %s\n", nome);
}   