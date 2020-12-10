#include "../include/MonitorBanheiro.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t banheiroCheio = PTHREAD_COND_INITIALIZER;
int qtdNoBanheiro = 0;
void corintianoQuerEntrar(){
    pthread_mutex_lock(&mutex);
    if(qtdNoBanheiro >= 3){
        pthread_cond_wait(&banheiroCheio, &mutex);
    }
    qtdNoBanheiro++;
    printf("%d\n", qtdNoBanheiro);
    pthread_mutex_unlock(&mutex);
}
void corintianoSai(){
    pthread_mutex_lock(&mutex);
    qtdNoBanheiro--;
    pthread_cond_signal(&banheiroCheio);
    pthread_mutex_unlock(&mutex);
}
void palmeirenseQuerEntrar(){
    pthread_mutex_lock(&mutex);
    if(qtdNoBanheiro >= 3){
        pthread_cond_wait(&banheiroCheio, &mutex);
    }
    qtdNoBanheiro++;
    pthread_mutex_unlock(&mutex);
}
void palmeirenseSai(){
    pthread_mutex_lock(&mutex);
    qtdNoBanheiro--;
    pthread_cond_signal(&banheiroCheio);
    pthread_mutex_unlock(&mutex);
}