#include "include/MonitorBanheiro.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
void *thread_corintiano(void *id)
{
    int ID = (int)id;
    while (true)
    {
        corintianoQuerEntrar();
        printf("Eu sou corintiano-%d: ... UFA! Entrei no banheiro!\n", ID);
        sleep(3);
        corintianoSai();
        printf("Eu sou corintiano-%d: ... Estou aliviado! Vou trabalhar!\n", ID);
        sleep(5);
    }
}

void *thread_palmeirense(void *id)
{
    int ID = (int)id;
    while (true)
    {
        palmeirenseQuerEntrar();
        printf("Eu sou palmeirense-%d: ... UFA! Entrei no banheiro!\n", ID);
        sleep(3);
        palmeirenseSai();
        printf("Eu sou palmeirense-%d: ... Estou aliviado! Vou trabalhar!\n", ID);
        sleep(5);
    }
}

int main()
{
    pthread_t funcionarios[20];
    for (int i = 0; i < 10; i++)
    {
        pthread_create(&funcionarios[i], NULL, thread_corintiano, i);
    }
    for (int i = 10; i < 20; i++)
    {
        pthread_create(&funcionarios[i], NULL, thread_palmeirense, (i - 10));
    }
    for(int i = 0; i < 20; i++){
        pthread_join(funcionarios[i], NULL);
    }
}