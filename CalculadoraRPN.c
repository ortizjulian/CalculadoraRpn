#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

double stack[8];

void printstack()
{
    for (int i = 0; i < 8; i++)
    {
        printf("%d.  %f", 8 - i, stack[i]);
        printf("\n");
    }
    printf("\n");
}

void moveStackUp()
{

    for (int i = 1; i < 8; i++)
    {
        stack[i - 1] = stack[i];
    }
}

void moveStackDown()
{
    for (int i = 7; i > 0; i--)
    {
        stack[i] = stack[i - 1];
    }
    stack[0] = 0;
}

void cleanStack()
{
    for (int i = 0; i < 8; i++)
    {
        stack[i] = 0.0;
    }
}

int main()
{
    int opc;
    char operacion;
    float num, resultado;
    cleanStack();

    printf("//////// Calculadora RPN ////////\n");

    do
    {

        printstack();
        printf("Eliga un opción\n\n");
        printf("1. Ingresar un número 2. Seleccionar operación 3. Limpiar último\n4. Limpiar todo 5. Salir \n");
        scanf("%i", &opc);

        if (opc == 1)
        {
            printf("\033[2J");
            printstack();
            printf("Ingrese un número: ");
            scanf("%f", &num);
            printf("\033[2J");
            moveStackUp();
            stack[7] = num;
        }
        else if (opc == 2)
        {
            printf("\033[2J");
            printstack();
            printf("Seleccione la operación\n");
            printf("+, -, * , /, r(raiz cuadrada), s(seno), c(coseno), t(tangente), p(potencia): ");
            scanf(" %c", &operacion);
            printf("\033[2J");
            switch (operacion)
            {
            case '+':
                /* Suma */
                resultado = stack[6] + stack[7];
                moveStackDown();
                stack[7] = resultado;
                break;
            case '-':
                /* Resta */
                resultado = stack[6] - stack[7];
                moveStackDown();
                stack[7] = resultado;
                break;
            case '*':
                /* Multiplicación */
                resultado = stack[6] * stack[7];
                moveStackDown();
                stack[7] = resultado;
                break;
            case '/':
                /* División */
                if (stack[7] == 0)
                {
                    printf("Math error\n");
                }
                else
                {
                    resultado = stack[6] / stack[7];
                    moveStackDown();
                    stack[7] = resultado;
                }
                break;
            case 'r':
                /* Raiz cuadrada */
                if (stack[7] < 0)
                {
                    printf("Math error\n");
                }
                else
                {
                    resultado = sqrt(stack[7]);
                    stack[7] = resultado;
                }
                break;
            case 's':
                /* Seno */
                resultado = sin((stack[7] * PI) / 180);
                stack[7] = resultado;
                break;
            case 'c':
                /* Coseno */
                resultado = cos((stack[7] * PI) / 180);
                stack[7] = resultado;
                break;
            case 't':
                /* Tangente */
                /*cos((stack[7] * PI) / 180) == 0*/
                if (stack[7] == 90 || stack[7] == 270)
                {
                    printf("Math error\n");
                }
                else
                {
                    resultado = tan((stack[7] * PI) / 180);
                    stack[7] = resultado;
                }
                break;
            case 'p':
                /* Potencia */
                resultado = pow(stack[6], stack[7]);
                moveStackDown();
                stack[7] = resultado;
                break;
            default:
                break;
            }
        }
        else if (opc == 3)
        {
            printf("\033[2J");
            stack[7] = 0;
            moveStackDown();
        }
        else if (opc == 4)
        {
            printf("\033[2J");
            for (int i = 0; i < 8; i++)
            {
                stack[i] = 0.0;
            }
        }
        else
        {
            printf("\033[2J");
        }

    } while (opc != 5);
}
