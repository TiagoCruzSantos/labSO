#include "../include/MonitorBanheiro.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t banheiroCheio = PTHREAD_COND_INITIALIZER;
pthread_cond_t corintianoNaFila = PTHREAD_COND_INITIALIZER;
pthread_cond_t palmeirenseNoBanheiro = PTHREAD_COND_INITIALIZER;
pthread_cond_t corintianoNoBanheiro = PTHREAD_COND_INITIALIZER;
int qtdNoBanheiro = 0;
int palcor = -1;//0 = palmeirense no banheiro, 1 = corintiano no banheiro, -1 ninguem no banheiro
void corintianoQuerEntrar(){
    pthread_mutex_lock(&mutex);
    if(palcor == 0){
        pthread_cond_wait(&palmeirenseNoBanheiro, &mutex);
    }
    if(qtdNoBanheiro >= 3){
        pthread_cond_wait(&banheiroCheio, &mutex);
    }
    qtdNoBanheiro++;
    palcor = 1;
    printf("%d corintianos\n", qtdNoBanheiro);
    pthread_mutex_unlock(&mutex);
}
void corintianoSai(){
    pthread_mutex_lock(&mutex);
    qtdNoBanheiro--;
    if(qtdNoBanheiro <= 0){
        palcor = -1;
        pthread_cond_signal(&corintianoNoBanheiro);
    }
    pthread_cond_signal(&banheiroCheio);
    printf("%d corintianos\n", qtdNoBanheiro);
    pthread_mutex_unlock(&mutex);
}
void palmeirenseQuerEntrar(){
    pthread_mutex_lock(&mutex);
    if(palcor == 1){
        pthread_cond_wait(&corintianoNoBanheiro, &mutex);
    }
    if(qtdNoBanheiro >= 3){
        pthread_cond_wait(&banheiroCheio, &mutex);
    }
    palcor = 0;
    qtdNoBanheiro++;
    printf("%d palmeirense\n", qtdNoBanheiro);
    pthread_mutex_unlock(&mutex);
}
void palmeirenseSai(){
    pthread_mutex_lock(&mutex);
    qtdNoBanheiro--;
    if(qtdNoBanheiro <= 0){
        palcor = -1;
        pthread_cond_signal(&palmeirenseNoBanheiro);
    }
    pthread_cond_signal(&banheiroCheio);
    printf("%d palmeirense\n", qtdNoBanheiro);
    pthread_mutex_unlock(&mutex);
}