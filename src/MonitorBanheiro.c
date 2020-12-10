#include "../include/MonitorBanheiro.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t banheiroCheio = PTHREAD_COND_INITIALIZER;
pthread_cond_t banheiroVazio = PTHREAD_COND_INITIALIZER;
pthread_cond_t corintianoPode = PTHREAD_COND_INITIALIZER;
pthread_cond_t palmeirensePode = PTHREAD_COND_INITIALIZER;
int qtdNoBanheiro = 0;
void corintianoQuerEntrar(){
    pthread_mutex_lock(&mutex);
    
    pthread_mutex_unlock(&mutex);
}
void corintianoSai(){
    pthread_mutex_lock(&mutex);

    pthread_mutex_unlock(&mutex);
}
void palmeirenseQuerEntrar(){
    pthread_mutex_lock(&mutex);

    pthread_mutex_unlock(&mutex);
}
void palmeirenseSai(){
    pthread_mutex_lock(&mutex);
    
    pthread_mutex_unlock(&mutex);
}