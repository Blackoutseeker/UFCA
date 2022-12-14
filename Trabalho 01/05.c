// Autor: Gabriel Augusto Alcântara Bezerra

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

float MEDIA (int v[], int size);
float MAIOR (float v[], int size);
int MENOR (int v[], int size);

int main () {

    FILE *arq;

    remove("log.txt");

    arq = fopen("log.txt", "a");

    if (arq == NULL){
        printf ("Nao foi possivel abrir o arquivo");
        scanf ("%d");
        exit(0);
    }

    int i = 1, size = 0, t = 0;
    int *filhos, *idade, *mediaEX;
    float *salario;
    char *sexo;


        struct tm* ptr;
        time_t timestamp;
        timestamp = time(NULL);
        ptr = localtime(&timestamp);
        fprintf(arq, "%s\n\n", asctime(ptr));


    salario = (int*)malloc(1*sizeof(int));
    sexo = (char*)malloc(1*sizeof(char));
    filhos = (float*)malloc(1*sizeof(float));
    idade = (int*)malloc(1*sizeof(int));
    mediaEX = (int*)malloc(1*sizeof(int));

    while (1){
        salario = (float*)realloc(salario, i*sizeof(float));
        sexo = (char*)realloc(sexo, i*sizeof(char));
        filhos = (int*)realloc(filhos, i*sizeof(int));
        idade = (int*)realloc(idade, i*sizeof(int));

        printf ("\nDados da pessoa %d\n\n", i);


        printf ("Digite sua idade: ");
        scanf ("%d", &idade[i-1]);

            while (idade[i-1] < 0){
                printf ("Idade invalido\nDigite uma idade valida: ");
                scanf ("%d", &idade[i-1]);
                    fprintf (arq, "idade[%d](invalido) = %d\n", (i-1), idade[i-1]);
            } 
            
                if (idade[i-1] == 0){

                    fprintf (arq, "size = %d\n", size);
                    
                    for (i = 0; i < size; i++){
                            if (sexo[i] == 'f' || sexo[i] == 'F'){
                                if (salario[i] < 300){
                                    t++;
                                    mediaEX = (int*)realloc(mediaEX, t*sizeof(int));
                                    mediaEX[t-1] = idade[i];
                                    fprintf (arq, "mediaEX[%d] = %d\n", t-1, mediaEX[t-1]);
                                }
                            }
                    }
                    float m1, m2, m3, big, small;

                    m1 = MEDIA (mediaEX, t);
                    m2 = MEDIA (idade, size);
                    m3 = MEDIA (filhos, size);
                    big = MAIOR (salario, size);
                    small = MENOR (idade, size);

                    fprintf (arq, "\nm1 recebe a media do vetor mediaEX\n");
                    fprintf (arq, "m2 recebe a media do vetor idade\n");
                    fprintf (arq, "m3 recebe a media do vetor filhos\n");
                    fprintf (arq, "big recebe o maior elemento do vetor salario\n");
                    fprintf (arq, "small recebe o menor elemento do vetor idade\n\n");

                    printf ("\nA media da idade das mulheres com menos de 300 reais de salario e de: %.f Anos\n", m1);
                    printf ("A media das idades e de: %.f Anos\n", m2);
                    printf ("A media da quantidade de filhos e de: %.1f Filhos\n", m3);
                    printf ("O maior salario e de: %.2f Reais\n", big);
                    printf ("A menor idade e de: %.f Anos\n", small);

                    fprintf (arq, "\nm1 = %.f\n", m1);
                    fprintf (arq, "m2 = %.f\n", m2);
                    fprintf (arq, "m3 = %.1f\n", m3);
                    fprintf (arq, "big = %.2f\n", big);
                    fprintf (arq, "small = %.f\n\n\n", small);

                    fclose (arq);
                return 0;
                }

            fprintf (arq, "idade[%d] = %d\n", (i-1), idade[i-1]);

        printf ("Digite seu salario: ");
        scanf ("%f", &salario[i-1]);
                fprintf (arq, "salario[%d] = %.2f\n", (i-1), salario[i-1]);

            while (salario[i-1] < 0){
                printf ("Salario invalido\nDigite um valor valido: ");
                scanf ("%f", &salario[i-1]);
                    fprintf (arq, "salario[%d](invalido) = %.2f\n", (i-1), salario[i-1]);
            }
        
        printf ("Digite seu sexo (M ou F): ");
        scanf ("%s", &sexo[i-1]);
                fprintf (arq, "sexo[%d] = %c\n", (i-1), sexo[i-1]);

            while (sexo[i-1] != 'F' && sexo[i-1] != 'f' && sexo[i-1] != 'M' && sexo[i-1] != 'm'){
                printf ("Sexo invalido\nDigite um sexo valido: ");
                scanf ("%c", &sexo[i-1]);
                    fprintf (arq, "sexo[%d](invalido) = %c\n", (i-1), sexo[i-1]);
            }

        printf ("Digite a quantidade de filhos que tem: ");
        scanf ("%d", &filhos[i-1]);
                fprintf (arq, "filhos[%d] = %d\n\n", (i-1), filhos[i-1]);

            while (filhos[i-1] < 0){
                printf ("Quantidade de filhos invalida\nDigite uma quantidade de filhos valida: ");
                scanf ("%d", &filhos[i-1]);
                    fprintf (arq, "filhos[%d](invalido) = %d\n\n", (i-1), filhos[i-1]);
            }

        i++;
        size++;
    }

    return 0;
}

float MEDIA (int v[], int size){
    int i, med = 0;
    for (i = 0; i < size; i++){
        med += v[i];
    }
    return med / size;
}

float MAIOR (float v[], int size){
    float maior;
    int i;

        for (i = 0; i < size; i++){
            if (i == 0)
                maior = v[0];

            else{
                if (v[i] > maior)
                maior = v[i];
            }
    }
        return maior;
}

int MENOR (int v[], int size){
    int menor, i;

        for (i = 0; i < size - 1; i++){
            if (i == 0)
                menor = v[0];

            else{
                if (v[i] < menor)
                menor = v[i];
            }
    }
        return menor;
}