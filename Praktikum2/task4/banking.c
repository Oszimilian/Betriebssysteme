#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>



#define NUM_KONTEN 3     // Anzahl an Konten
#define THREADS 5         // Anzahl an Thredas
#define TRANSFERS_PRO_THREAD 1000000 // Anzahl von Transfers zwischen Konten


volatile int konten[NUM_KONTEN];            
pthread_mutex_t mutex[NUM_KONTEN];       // eine Mutex für jeden Account


void ueberweisung(int von, int nach, int betrag) {
	// sonst bleibt das Programm stehen, weil es nachdem es gelockt hat ja wartet bis es wieder freigegeben wird
	if (von == nach){
		return;
	} else {
		printf("Von: %d Nach: %d \n", von, nach);
		pthread_mutex_lock(&mutex[von]);
		if(pthread_mutex_trylock(&mutex[nach])) {
			pthread_mutex_unlock(&mutex[von]);
			return;
		}

		if (konten[von] >= betrag) {
			konten[von] -= betrag;
			konten[nach] += betrag;
		}

		pthread_mutex_unlock(&mutex[von]);
		pthread_mutex_unlock(&mutex[nach]);
	}
}


void *thread_routine(void *unused) {
	for (int i = 0; i < TRANSFERS_PRO_THREAD; ++i) {
		// zufälle beträge zwischen zufällen Konten überweisen
		ueberweisung (rand() % NUM_KONTEN,
			      rand() % NUM_KONTEN,
			      rand() % 100);
	}

	return NULL; // keine Rückgabe
}


int main (int argc, char** argv) {
	srand(time(NULL));
	pthread_t threads[THREADS];

	int start_geld = 0;
	

	// zufälliger betrag auf alle konten
	for (int i = 0; i < NUM_KONTEN; ++i) {
		int value = rand() % 100000;
		konten[i] = value;
		start_geld += value;
	}

	// Mutexe initialisieren
	for (int i = 0; i < NUM_KONTEN; ++i)
		pthread_mutex_init(&mutex[i], NULL);
	
	int err;
	// Threads erstellen
	for (int i = 0; i < THREADS; ++i) {
		if (0 != (err = pthread_create(&threads[i], NULL, thread_routine, NULL))) {
			fprintf(stderr, "ERROR creating thread: %s\n", strerror(err));
			exit(1);
		}
	}

	// warten bis alle threads fertig sind
	for (int i = 0; i < THREADS; ++i)
		pthread_join(threads[i], NULL);

	// mutexe aufräumen
	for (int i = 0; i < NUM_KONTEN; ++i)
		pthread_mutex_destroy(&mutex[i]);

	// Inhalt aller Konten drucken. 
	int sum = 0;
	for (int i = 0; i < NUM_KONTEN; ++i) {
		printf("Konto #%03i: %7i\n", i, konten[i]);
		sum += konten[i];
	}
	// Summe sollte start_geld entsprechen
	printf ("---------------------\n"
		"Summe am Ende:  %16i\n"
		"Summe zu Begin: %16i\n", sum, start_geld);

	return 0;
}
