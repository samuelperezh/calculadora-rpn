// Samuel Pérez Hurtado
// ID 000459067
#include "stdio.h"
#include "math.h"

float pi = 3.14159265;
float stack[8];

void printstack(void)
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        printf("%d", 8 - i);
        printf(". ");
        printf("%f", stack[i]);
        printf("\n");
    }
}

void movestackup(void)
{
    int i = 0;
    for (i = 1; i < 8; i++)
    {
        stack[i - 1] = stack[i];
    }
}

void movestackdown(void)
{
    int i = 0;
    for (i = 5; i >= 0; i--)
    {
        stack[i + 1] = stack[i];
    }
}

void printoptions(void)
{
    printf("\033[32m¿Qué deseas hacer?\n");
    printf("1. Ingresar número 2. Seleccionar operación 3. Limpiar último ");
    printf("\n4. Limpiar todo  5. Salir\n\033[37m");
}

void operation(char n)
{
    double radianes;
    switch (n)
    {
    case '+':
        stack[7] += stack[6];
        movestackdown();
        printf("\033[2J");
        break;
    case '-':
        stack[7] = stack[6] - stack[7];
        movestackdown();
        printf("\033[2J");
        break;
    case '*':
        stack[7] *= stack[6];
        movestackdown();
        printf("\033[2J");
        break;
    case '/':
        if (stack[7] == 0)
        {
            printf("\033[2J");
            printf("\033[31mMath Error\n\n\033[37m");
        }
        else
        {
            stack[7] = stack[6] / stack[7];
            movestackdown();
            printf("\033[2J");
        }
        break;
    case 'r':
        if (stack[7] >= 0)
        {
            stack[7] = sqrt(stack[7]);
            printf("\033[2J");
        }
        else
        {
            printf("\033[2J");
            printf("\033[31mMath Error\n\n\033[37m");
        }
        break;
    case 's':
        radianes = stack[7] * (pi / 180);
        stack[7] = sin(radianes);
        printf("\033[2J");
        break;
    case 'c':
        radianes = stack[7] * (pi / 180);
        stack[7] = cos(radianes);
        printf("\033[2J");
        break;
    case 't':
        radianes = stack[7] * (pi / 180);
        if (fabs(fmod(radianes, pi) - pi / 2) > 1e-10)
        {
            stack[7] = tan(radianes);
            printf("\033[2J");
        }
        else
        {
            printf("\033[2J");
            printf("\033[31mMath Error\n\n\033[37m");
        }
        break;
    case 'p':
        stack[7] = pow(stack[6], stack[7]);
        movestackdown();
        printf("\033[2J");
        break;
    default:
        break;
    }
}

void deleteall()
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        stack[i] = 0.0;
    }
}

void deletelast()
{
    int i = 0;
    for (i = 6; i >= 0; i--)
    {
        stack[i + 1] = stack[i];
    }
}

int main()
{
    int opt = 0, num;
    char ascci;
    while (opt != 5)
    {
        printstack();
        printoptions();
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\033[2J");
            printstack();
            printf("Ingrese el numero: ");
            scanf("%d", &num);
            movestackup();
            stack[7] = num;
            printf("\033[2J");
            break;
        case 2:
            printf("\033[2J");
            printstack();
            printf("+, -, *, /, r(raiz cuadrada), s(seno), c(coseno), t(tangante), p(potencia)\n");
            scanf("%s", &ascci);
            operation(ascci);
            break;
        case 3:
            printf("\033[2J");
            printstack();
            deletelast();
            printf("\033[2J");
            break;
        case 4:
            printf("\033[2J");
            printstack();
            deleteall();
            printf("\033[2J");
            break;
        case 5:
            printf("\033[2J");
            printf("\033[36m¡Gracias por utilizar la calculadora!\n\033[37m");
            break;
        default:
            printf("\033[2J");
            printf("\033[31mOpción no válida\n\n\033[37m");
            break;
        }
    }
    return 0;
}
