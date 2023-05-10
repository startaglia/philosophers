# The Dining Philosopher’s Problem
Il problema dei 5 filosofi a cena é un esempio utile per capire la gestione delle risorse condivise in un programma.
Ci sono 5 filosofi seduti ad un tavolo circolare, con 5 piatti di pasta e 5 forchette, tutti quanti devono poter mangiare e per mangiare hanno bisogno di due forchette. Le forchette sono rispettivamente ai lati di ogni piatto quindi non ci sono forchette a sufficienza per far mangiare tutti i filosofi contemporaneamente. Quello che si deve evitare sono le situazioni di deadlock e starvation. Per risolvere il problema ci sono degli algoritmi appositi(si consideri che il problema é stato formulato per analizzare il problema di gestione di risorse condivise, quindi soluzioni semplici come ad esempio far mangiare i filosofi in ordine di ingresso nella stanza risolvono il problema ma non centrano il focus).
* Deadlock
Il Deadlock("impasse" o "punto morto") é la situazione in cui nessun filosofo puó accedere ad entrambe le forchette, quindi nessuno puó mangiare. Nello specifico si verifica quando due o piú processi o thread sono bloccati perché stanno ciacuno di essi sta aspettando il rilascio di una risorsa da parte di un altro processo o thread a sua volta bloccato; tutti stanno aspettando qualcosa che non verrá mai rilasciato.
* Starvation
La Starvation é una situazione in cui uno o piú filosofi hanno una prioritá molto bassa di prendere una forchettta rispetto agli altri, quindi potrebbero non avere mai la possibilitá di mangiare. Stesso discorso se si considerano processi o thread. Potrebbero esserci casi in cui un processo o thread non abbiano mai accesso alle risorse per un discorso di prioritá.
La differenza con la situazione di Deadlock é che nella Starvation alcuni processi continuano ad accedere alle risorse, nel Deadlock sono tutti bloccati.
La consegna del progetto chiede di implementare una soluzione al problema evitando appunto situazioni di Deadlock o di Starvation.
* Processo
Un processo si puó pensare come se fosse un programma in esecuzione. Tecnicamente un programma diventa un processo quando il suo file eseguibile viene caricato in memoria. Quindi un processo é un'entitá indipendente che ha una sua area di memoria.
* Thread
Un thread é una parte del processo che viene eseguita in maniera concorrente ed indipendente interamente dallo stato del processo stesso. Si pensi ad una corda composta da fibre; la corda stessa é il processo, ogni singola fibra é un thread. Un thread condivide l'area di memoria con il processo di cui fanno parte.
Un esempio di processo e thread é un browser web. Quando si apre il browser si crea un processo che contiene tutte le info sul browser; quindi quando si aprono piú finestre browser sono piú processi separati ed indipendenti tra di loro. L'apertura di una scheda aggiuntiva all'interno di una finestra é un esempio di thread.
* Sezione critica
Una sezione critca é una porzione di codice che accede ad una risorsa condivisa(una variabile, una struttura dati o un file) e che deve essere eseguita in modo esclusivo da un solo processo o thread alla volta. In altre parole una sezione critica é un punto del programma in cui é necessario garantire l'accesso esclusivo ad una risorsa condivisa per evitare problemi di concorrenza tra piú processi o thread. Nel progetto in questione la sezione critica é l'azione di prendere le forchette.
* Race condition
Una race condition si verifica quando due o piú processi possono accedere ad una risorsa condivisa in modo concorrente e non sincronizzato, generando cosi risultati imprevedibili.
Ad esempio se due thread possono accedere alla stessa variabile condivisa il risultato sará  imprevedibile. Se uno dei thread legge la variabile prima che l'altro abbia finito di scriverci sopra, il valore restituito sará diverso da quello che ci aspettavamo. Per evitare questo comportamento si usano le mutex.
* Mutex
Le mutex sono un meccanismo di sincronizzazione che prevengono le race condition garantendo l'acesso esclusivo alle risorse condivise da piú processi o thread.
Il primo processo o thread che accede alla risorsa riceve dalla mutex una lock, e da quel momento in poi nessun altro thread o processo potrá accedere a quella risorsa se prima non viene liberata dalla mutex.


Per figuare il problema seguendo la consegna dobbiamo sequenzialmente capire il processo.
- 1.0
Entra il filosofo P0 e puó mangiare perché é solo nella stanza ed ha le forchette a disposizione.
- 1.1
Entra il filosofo P1 e non puó mangiare perché la forchetta alla sua destra(quindi la forchetta sinistra filosofo P0) é occupata.
- 1.2
Entra il filosofo P2 e puó iniziare a mangiare perché ha tutte e due le forchette disponibili.
- 1.3
Entra il filosofo P3 e non puó mangiare perché ha lo stesso problema del filosofo P1(la forchetta alla sua destra é presa dal filosofo P2).
- 1.4
Il filosofo P4 anche non puó mangiare finche il filosofo P0 non finisce (la forchetta destra del filosofo P0 é la forchetta sinistra del filosofo P4).
- 1.5
Il filosofo P0 che é stato il primo ad iniziare a mangiare ora ha finito ed ha liberato le sue due forchette. Questo significa che il filosofo P4 puó iniziare a mangiare.
- 1.6
Il filosofo P2 ha che é stato il secondo ad iniziare a mangiare ha finito quindi ha liberato le forchette per far iniziare a mangiare il filosofo P1.
- 1.7
Il filosofo P4 ha finito di mangiare quindi puó infine mangiare il filosofo P3.

Quindi con 5 filosofi l'ordine in cui mangiano é P0/P2/P0 finisce - inizia P4/P2 finisce inizia P1/P4 finisce inizia P3.

Seguendo la consegna i filosofi, in questo ordine, possono mangiare, pensare e dormire.
Gli input sono i seguenti:
* numbers_of_philosophers:
Il numero di filosofi.
* time_to_die(in milliseconds):
Il tempo che ci mette un filosofo a morire dalla fine della sua ultima azione prima di mangiare. Supponiamo che time_to_die sia 800ms. Se il filosofo finisce di pensare e passano piu di 800 ms prima che possa iniziare a mangiare allora il filosofo muore.
* time_to_eat(in milliseconds):
Il tempo impiegato da un filosofo per mangiare.
* time_to_sleep(in milliseconds):
Il tempo che un filosofo ci mette per dormire.
* numbers_of_times_each_philosopher_must_eat:
Il numero massimo di volte tutti i filosofi possono mangiare. Se tutti i filosofi hanno mangiato almeno questo numero di volte la simulazione si interrompe. Se il parametro non viene passato il programma si interrompe quando un filosofo muore.

TO_DO:
- PROSEGUIRE CON I COMMENTI DEL PROGRAMMA. CAPIRE BENE PERCHÉ NON E' POSSIBILE CHE QUALCHE PHILO NON PASSI SOTTO SUPERVISOR.(PROBABILMENTE PERCHE'STO ESAMINANDO LA CONDIZIONE CON UN PHILO)