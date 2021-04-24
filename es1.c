#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Complete the 'shortestCommonSupersequence' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */
/*
a) 

			{ i         se j = 0
SCS[i,j] =  { j         se i = 0
		    { SCS[i-1, j-1] + 1		se i>0 AND j>0 AND s1[i] == s2[j]
	    	{ min(SCS[i-1, j], SCS[i, j-1]) + 1     altrimenti

c)
Entrambi i rami dell' if then else hanno ala stessa complessità. La fase di 
inizializzazione avrà complessita theta(min(n,m)) con n lunghezza di s1 e m 
lunghezza di s2, essendo un ciclo for che esegua min(n.m) iterazioni di 
complessità costante. Sucessivamente avrò due cicli for innestti cche eseguiranno
rispettivamente che in totale eseguiranno n*m iterazione di compleessità costante
quindi theta(n*m). La complessità totale sarà quindi theta(n*m).
*/
int shortestCommonSupersequence(char* s1, char* s2) {
	int m = strlen(s1);
	int n = strlen(s2);
	char * aux;
	int i, j, tmp, d;
	if (m < n) {
		aux = (char *) malloc(sizeof(char) * (m+1));
		for (i = 0; i < m+1; i++)
			aux[i] = i;

		for (i = 1; i < n+1; i++) {
			d = i-1;
			aux[0] = i;
			for (j = 1; j < m+1; j++) {
				tmp = aux[j];
				if (s1[j-1] == s2[i-1]) 
					aux[j] = d+1;
				else 
					aux[j] = tmp < aux[j-1] ? tmp + 1 : aux[j-1] + 1;

				printf("%d ", aux[j]);
				d = tmp;
			}
			printf("\n");
		}
		tmp = aux[m];
	} else {
		aux = (char *) malloc(sizeof(char) * (n+1));
		for (i = 0; i < n+1; i++)
			aux[i] = i;

		for (i = 1; i < m+1; i++) {
			d = i-1;
			aux[0] = i;
			for (j = 1; j < n+1; j++) {
				tmp = aux[j];
				if (s2[j-1] == s1[i-1]) 
					aux[j] = d+1;
				else 
					aux[j] = tmp < aux[j-1] ? tmp + 1 : aux[j-1] + 1;

				printf("%d ", aux[j]);
				d = tmp;
			}
			printf("\n");
		}
		tmp = aux[n];
	}	
	free(aux);
	return tmp;
}

int main(int argc, char const *argv[]) {
	int r = shortestCommonSupersequence("3121", "4123");
	printf("%d\n", r);
	return 0;
}