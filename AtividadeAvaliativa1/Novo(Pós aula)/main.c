#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserirValor();
void menu();
void getPFinalBuffer();

int estaRodando = 0;

void *pNumeros;
void *pBuffer;

int *bufferInteiro;
float *bufferFloat;
double *bufferDouble;

char *bufferChar;
char *bufferTipo;

int quantosNumeros = 0;
int quantosInt = 0;
int quantosFloat = 0;
int quantosDouble = 0;

int main(int argc, char const *argv[])
{
    pNumeros = malloc(sizeof(int));
    pBuffer = pNumeros;
    bufferInteiro = (int *)pBuffer;
    bufferFloat = (float *)pBuffer;
    bufferDouble = (double *)pBuffer;
    bufferTipo = (char *)malloc(sizeof(char) * 2);
    bufferChar = bufferTipo;

    while (estaRodando == 0)
    {
        menu();
    }
    pBuffer = pNumeros;
    printf("-------------------------------\n");
    printf("Numeros na ordem inserida: \n");
    for (int i = 0; i < quantosNumeros; i++)
    {

        if (bufferTipo[i] == 105)
        {
            printf("Inteiro = %d\n", *(int *)pBuffer);
            pBuffer += sizeof(int);
        }
        else if (bufferTipo[i] == 102)
        {
            printf("Float = %f\n", *(float *)pBuffer);
            pBuffer += sizeof(float);
        }
        else if (bufferTipo[i] == 100)
        {
            printf("Double = %lf\n", *(double *)pBuffer);
            pBuffer += sizeof(double);
        }
    }
    pBuffer = pNumeros;
    printf("-------------------------------\n");
    printf("Numeros inteiros: \n");
    for (int i = 0; i < quantosNumeros; i++)
    {
        if (bufferTipo[i] == 105)
        {
            printf("Inteiro = %d\n", *(int *)pBuffer);
            pBuffer += sizeof(int);
        }
        else if (bufferTipo[i] == 102)
            pBuffer += sizeof(float);
        else if (bufferTipo[i] == 100)
            pBuffer += sizeof(double);
    }
    pBuffer = pNumeros;
    printf("-------------------------------\n");
    printf("Numeros float: \n");
    for (int i = 0; i < quantosNumeros; i++)
    {
        if (bufferTipo[i] == 105)
            pBuffer += sizeof(int);
        else if (bufferTipo[i] == 102)
        {
            printf("Float = %f\n", *(float *)pBuffer);
            pBuffer += sizeof(float);
        }
        else if (bufferTipo[i] == 100)
            pBuffer += sizeof(double);
    }
    pBuffer = pNumeros;
    printf("-------------------------------\n");
    printf("Numeros double: \n");
    for (int i = 0; i < quantosNumeros; i++)
    {
        if (bufferTipo[i] == 105)
            pBuffer += sizeof(int);
        else if (bufferTipo[i] == 102)
            pBuffer += sizeof(float);
        else if (bufferTipo[i] == 100)
        {
            printf("Double = %lf\n", *(double *)pBuffer);
            pBuffer += sizeof(double);
        }
    }

    free(pNumeros);
    free(bufferTipo);
    return 0;
}

void inserirValor()
{
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
        quantosInt++;
        pNumeros = realloc(pNumeros, (quantosInt * sizeof(int)) + (quantosFloat * sizeof(float)) + (quantosDouble * sizeof(double)));
        pBuffer = pNumeros;
        getPFinalBuffer();
        bufferInteiro = (int *)pBuffer;
        scanf("%d", (int *)bufferInteiro);
        quantosNumeros++;
        bufferTipo = realloc(bufferTipo, quantosNumeros * (sizeof(char) * 2));
        bufferChar = bufferTipo;
        bufferChar += quantosNumeros - 1;
        strcpy(bufferChar, "i");
        break;
    case 2:
        printf("Digite o valor Float: \n");
        printf("-------------------------------\n");
        quantosFloat++;
        pNumeros = realloc(pNumeros, (quantosInt * sizeof(int)) + (quantosFloat * sizeof(float)) + (quantosDouble * sizeof(double)));
        pBuffer = pNumeros;
        getPFinalBuffer();
        bufferFloat = (float *)pBuffer;
        scanf("%f", (float *)bufferFloat);
        quantosNumeros++;
        bufferTipo = realloc(bufferTipo, quantosNumeros * (sizeof(char) * 2));
        bufferChar = bufferTipo;
        bufferChar += quantosNumeros - 1;
        strcpy(bufferChar, "f");
        break;
    case 3:
        printf("Digite o valor Double: \n");
        printf("-------------------------------\n");
        quantosDouble++;
        pNumeros = realloc(pNumeros, (quantosInt * sizeof(int)) + (quantosFloat * sizeof(float)) + (quantosDouble * sizeof(double)));
        pBuffer = pNumeros;
        getPFinalBuffer();
        bufferDouble = (double *)pBuffer;
        scanf("%lf", (double *)bufferDouble);
        quantosNumeros++;
        bufferTipo = realloc(bufferTipo, quantosNumeros * (sizeof(char) * 2));
        bufferChar = bufferTipo;
        bufferChar += quantosNumeros - 1;
        strcpy(bufferChar, "d");
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
        printf("Opção Invalida\n");
        break;
    }
}

void getPFinalBuffer()
{
    for (int i = 0; i < quantosNumeros; i++)
        if (bufferTipo[i] == 105)
            pBuffer += sizeof(int);
        else if (bufferTipo[i] == 102)
            pBuffer += sizeof(float);
        else if (bufferTipo[i] == 100)
            pBuffer += sizeof(double);
}
