#include <pthread.h>
#include <stdio.h>
#include <time.h>

int esteira1;
int esteira2;
int peso1;
int peso2;
int pesoTotal;

double time1, timedif;

void le_sensor1();
void le_sensor2();

int main() 
{
    esteira1 = 0;
    esteira2 = 0;
    peso1 = 0;
    peso2 = 0;
    pesoTotal = 0;
    
    printf("Init\n");
    
    pthread_t  t1, t2;
    
    time1 = (double) clock();
    time1 = time1 / CLOCKS_PER_SEC;
    
    pthread_create(&t2, NULL, (void *) le_sensor1, NULL);
    pthread_create(&t2, NULL, (void *) le_sensor2, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    // timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
    // printf("The elapsed time is %f seconds\n", timedif);
    // printf("Peso total %d", pesoTotal);

    return 0;
}


void le_sensor1() 
{
    for (int i = 0; i < 1000; i++)  
    {
        esteira1++;
        printf("Esteira 1: %d\n", esteira1);
        peso1 += 5;
        pesoTotal = peso1 + peso2;
    }
}

void le_sensor2() 
{
    for (int i = 0; i < 1000; i++)  
    {
        esteira2++;
        printf("Esteira 2: %d\n", esteira2);
        peso2 += 2;
        pesoTotal = peso1 + peso2;
    }
}
