#include "include/MonitorBanheiro.h"
#include <stdbool.h>
void thread_corintiano(int *id)  // cada corintiano e palmeirense terá um identificador de 1 a 10
{ 
 while (true){
       corintianoQuerEntrar();
       printf ("Eu sou corintiano-%d: ... UFA! Entrei no banheiro!\n",*id);
       sleep(3);
       corintianoSai();
       printf ("Eu sou corintiano-%d: ... Estou aliviado! Vou trabalhar!\n",*id);
       sleep(5);
   }
}

void thread_palmeirense(int *id)  // cada palmeirense e palmeirense terá um identificador de 1 a 10
{ 
 while (true){
       palmeirenseQuerEntrar();
       printf ("Eu sou palmeirense-%d: ... UFA! Entrei no banheiro!\n",*id);
       sleep(3);
       palmeirenseSai();
       printf ("Eu sou palmeirense-%d: ... Estou aliviado! Vou trabalhar!\n",*id);
       sleep(5);
   }
}


int main(){

}