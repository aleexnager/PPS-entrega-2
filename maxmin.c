#include <stdio.h>

int main(int argc, char * argv[])
{   
    FILE * fp = fopen(argv[1], "r");
    float max = 0;
    float min = 110;
    float aux;
    char c = fgetc(fp);

    /*comprobamos que hay archivo para leer*/
    if (argc < 2)
    {   
        return -1;
    }

    /*probamos a abrir el archivo*/
    if (fp == NULL)
    {
        return -1;
    }

    /*miramos si está vacio archivo vacio*/
    if (c == EOF)
    {
        printf("%10.2f %10.2f", max, min);
        return 1;
    }

    rewind(fp);
    /*leer de un fichero y coger el numero maximo y minimo*/
    while (fscanf(fp, "%f", &aux) != EOF)
    {   
        if (max < aux)
        {
            max = aux;
        }
        if (aux < min)
        {
            min = aux;
        }
    }

    printf("%10.2f %10.2f", max, min);
    fclose(fp);

    return 0;
}