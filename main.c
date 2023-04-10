#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

struct shared_memory 
{
    int esteira1;
    int esteira2;
    int peso_total;
};

int main()
{
    int i, shmid, a;
    struct shared_memory *shared;
    key_t key = 1234; //Chave para memória
    
    //Criando a memória
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) 
    {
        perror("shmget");
        exit(1);
    }
    
    //Anexando a memória
    if ((shared = shmat(shmid, NULL, 0)) == (struct shared_memory *) -1) 
    {
        perror("shmat");
        exit(1);
    }
    
    shared->esteira1 = 0;
    shared->esteira2 = 0;
    shared->peso_total = 0;
    
    //Simulação
    while(1)
    {
        i++;
        
        
        //1
        if (1) 
        {
            shared->esteira1++;
            shared->peso_total += 5;
            printf("Esteira 1: %d\n", shared->esteira1);
            a++;
        }
        
        
        if (a % 500 == 0) 
        {
            printf("Peso total que passou pelas esteiras: %d\n", shared->peso_total);
        }
    
        
        
        //2
        if (1) 
        {
            shared->esteira2++;
            shared->peso_total += 2;
            a++;

        }
        
        if (a % 500 == 0) 
        {
            printf("Peso total que passou pelas esteiras: %d\n", shared->peso_total);
        }
        
        //2
        if (1) 
        {
            shared->esteira2++;
            shared->peso_total += 2;
            printf("Esteira 2: %d\n", shared->esteira2);
            a++;

        }
        
        sleep(2);
    }
    
   
    shmdt(shared);
    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}
