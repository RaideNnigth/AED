#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserirValor();
void menu();

int estaRodando = 0;

void *pNumeros;
void *pBuffer;

int *bufferInteiro;
float *bufferFloat;
double *bufferDouble;
char *bufferChar;

int quantosNumeros = 0;

int main(int argc, char const *argv[])
{
    pNumeros = malloc(sizeof(0));
    pBuffer = pNumeros;
    while (estaRodando == 0)
    {
        menu();
    }
    pBuffer = pNumeros;
    bufferChar = pBuffer;
    bufferInteiro = pBuffer;
    bufferDouble = pBuffer;
    bufferFloat = pBuffer;
    for (int i = 1; i < quantosNumeros; i++)
    {
        if (bufferChar == "i")
        {
            pBuffer += sizeof(int);
            bufferInteiro = pBuffer;
            printf("%d", bufferInteiro);
        }
        else if (bufferChar == "f")
        {
            pBuffer += sizeof(float);
            bufferFloat = pBuffer;
            printf("%f", bufferFloat);
        }
        else if (bufferChar == "d")
        {
            pBuffer += sizeof(double);
            bufferDouble = pBuffer;
            printf("%lf", pBuffer);
        }
        bufferChar++;
    }

    return 0;
}

void inserirValor()
{
    pBuffer = pNumeros;
    bufferChar = pBuffer;
    bufferInteiro = pBuffer;
    bufferDouble = pBuffer;
    bufferFloat = pBuffer;
    for (int i = 1; i < quantosNumeros; i++)
    {

        if (bufferChar == "i")
        {
            pBuffer += sizeof(int);
        }
        else if (bufferChar == "f")
        {
            pBuffer += sizeof(float);
        }
        else if (bufferChar == "d")
        {
            pBuffer += sizeof(double);
        }
        bufferChar++;
    }

    printf("Escolha uma das opcoes abaixo: \n");
    printf("1) Inteiro:  \n");
    printf("2) Float: \n");
    printf("3) Double: \n");
    printf("-------------------------------\n");
    int opcao = 0;
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        printf("Digite o valor Int: \n");
        printf("-------------------------------\n");

        bufferChar = realloc(bufferChar, sizeof(char));
        char intChar[2] = "i";
        strcpy(bufferChar, intChar);

        bufferInteiro = realloc(bufferInteiro, sizeof(int));
        pBuffer += sizeof(int);
        scanf("%d", (int *)bufferInteiro);
        quantosNumeros++;
        break;
    case 2:
        printf("Digite o valor Float: \n");
        printf("-------------------------------\n");

        bufferChar = realloc(bufferChar, sizeof(char));
        char floatChar[2] = "f";
        strcpy(bufferChar, floatChar);

        bufferFloat = realloc(bufferFloat, sizeof(float));
        pBuffer += sizeof(float);
        scanf("%f", (float *)bufferFloat);
        quantosNumeros++;
        break;
    case 3:
        printf("Digite o valor Double: \n");
        printf("-------------------------------\n");

        bufferChar = realloc(bufferChar, sizeof(char));
        char doubleChar[2] = "d";
        strcpy(bufferChar, doubleChar);

        bufferDouble = realloc(bufferDouble, sizeof(double));
        pBuffer += sizeof(double);
        scanf("%lf", (double *)bufferDouble);
        quantosNumeros++;
        break;
    default:
        printf("Opcao invalidas\n");
        printf("-------------------------------\n");
        break;
    }
}

void menu()
{
    printf("Escolha uma das opcoes abaixo: \n");
    printf("1) Inserir valor:  \n");
    printf("2) Sair: \n");
    printf("-------------------------------\n");
    int opcao = 0;
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        inserirValor();
        break;
    case 2:
        estaRodando = 1;
        break;
    default:
        printf("Opção Inválida");
        break;
    }
}
