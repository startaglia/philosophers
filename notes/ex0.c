
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

int cont = 0; // variabile globale
pthread_mutex_t lock; //dichiarazione della var mutex

void  *routine() // funzione che aumenta una variabile globale fino ad un milione
{
  int i;

  i = -1;
  while (++i < 1000000)
  {
	pthread_mutex_lock(&lock); // Il primo thread che arriva acquisisce la lock sulla mutex, impedendo ad altri thread di accedere alla variabile "cont". Si noti che tutto quello che segue la funct pthread_mutex_lock é un blocco di codice, come fosse una condizione, ci accede solo chi acquisice la lock.
    	cont++; 
    pthread_mutex_unlock(&lock); // Rilascia la lock sulla mutex, permettendo ad altri thread di acquisirla e accedere alla variabile "cont".
  }
  return (NULL);
}

int main()
{
  pthread_t tid1, tid2; //* dichiarazione di due variabili di tipo trhead.
	
	//* Funzione che inizializza l'oggetto di tipo mutex lock
	//* Il primo parametro é il puntatore alla var mutex da utilizzare.
	//* Il secondo parametro é un puntatore ad una istanza della struttura pthread_mutexattr_t che specifica gli attributi della mutex; se NULL la mutex verrá inizializzata con attributi predefiniti.
  		pthread_mutex_init(&lock, NULL);
  	
	//* Funzione che crea un nuovo thread ed assegna la funzione routine come entry point, l'ID del thread viene memorizzato nella var tid1.
	//* Il primo parametro é il puntatore alla var di tipo thread.
	//* Il secondo parametro specifica gli attributi del thread come la prioritá e altri.
	//* Il terzo parametro é la funzione che deve essere eseguita dal thread (deve essere void *).
	//* L'ultimo parametro si usa per passare eventuali argomenti alla funzione routine.
		pthread_create(&tid1, NULL, &routine, NULL);
		pthread_create(&tid2, NULL, &routine, NULL);
	
	//* Funzione che viene usata per attendere la terminazione di un thread specifico. Di base aspetta che il thread abbia terminato l'esecuzione e restituisce il valore di ritorno se presente.
	//* Il primo valore é il descrittore del thread che si vuole attendere.
	//* Il secondo valore é il puntatore all'area di memoria dove si vuole salvare il dato di ritorno.
		pthread_join(tid1, NULL);
		pthread_join(tid2, NULL);
		pthread_mutex_destroy(&lock); //* funzione che distrugge il mutex.
		printf("cont: %d\n", cont);
}