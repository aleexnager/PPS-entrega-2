#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /*Variables*/
    int m, p, i, j;
    long int **matriz;
    (void)argc;

    m = atol(argv[1]); /*num filas*/
    p = atol(argv[2]); /*num columnas*/

    /*Memoria dinamica*/
    matriz = (long int **)calloc(m, sizeof(int *));
    if (matriz == NULL)
        exit(71);
    for (i = 0; i < m; ++i)
    {
        matriz[i] = (long int *)calloc(p, sizeof(int *));
        if (matriz == NULL)
            exit(71);
    }

    /*Asignacion valores*/
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < p; ++j)
        {
            if (i == 0 || j == 0)
                matriz[i][j] = 1;
            else
                matriz[i][j] = matriz[i - 1][j] + matriz[i][j - 1];
        }
    }

    /*prints*/
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < p; ++j) 
        {
            if (j == p-1)
            {
                printf("%li\n", matriz[i][j]); /*para ultimo elem*/
            } else {
                printf("%li\t", matriz[i][j]);
            }
        }
    }

    /*Liberacion menoria dinamica*/
    for (i = 0; i < m; ++i)
        free(matriz[i]);
    free(matriz);

    exit(0);
}