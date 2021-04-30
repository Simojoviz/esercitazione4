#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Complete the 'shortestCommonSupersequenceTopDown' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */
/*
Ci saranno al massimo n*m chiamate ricorsive, questo perchè il corpo della funzione
verrà eseguito al massimo una sola volta per ogni combinazione i,j (i = 0...n e j = 0...m).
Quindi la complessità toltale sarà O(n*m).
*/
int SCSTopDownAux(char *s1, int m, char* s2, int n, int **aux) {
    if (aux[n][m] == -1) {
        if (n == 0) {
            aux[0][m] = m;
        }else if (m == 0) {
            aux[n][0] = n;
        }else {
            if (s1[m-1] == s2[n-1]) {
                aux[n][m] =  SCSTopDownAux(s1, m-1, s2,  n-1, aux) + 1;
            }else {
                int left =  SCSTopDownAux(s1, m-1, s2, n, aux);
                int up = SCSTopDownAux(s1, m, s2, n-1, aux);
    
                if (left < up) {
                    aux[n][m] = left + 1;
                } else {
                    aux[n][m] = up + 1;
                }
            }
        }

    }
    return aux[n][m];
}

/*
Ad ogni chiamata ricordiva ripercorro all'indietro di una posizione la LCS 
quindi verranno eseguite un tolale di n chiamate ricorsive con n la lunghezza della
SCS tra s1 e s2, che al massimo sarà len(s1) + len(s2).
Quindi la complessità totale sarà theta(n).
*/
void memSCS(char *s1, int m, char* s2, int n, int **aux, char* res) {
    if (n == 0 && m == 0)
        return;
    if (n == 0){
        res[m-1] = s1[m-1];
        memSCS(s1, m-1, s2, n, aux, res);
    }else if (m == 0) {
        res[n-1] = s2[n-1];
        memSCS(s1, m, s2, n-1, aux, res);
    }else {
        if (s1[m-1] == s2[n-1]) {
            res[aux[n][m] - 1] = s1[m-1];
            memSCS(s1, m-1, s2, n-1, aux, res);
        }else {
            if (aux[n][m-1] < aux[n-1][m]) {
                res[aux[n][m] - 1] = s1[m-1];
                memSCS(s1, m-1, s2, n, aux, res); 
            }else {
                res[aux[n][m] - 1] = s2[n-1];
                memSCS(s1, m, s2, n-1, aux, res);
            }
        }
    }
}

/*
Durante la fase di iniziallizzazione viene eseguito un ciclo for con n+1 iterazioni 
(n lunghezza di s2) di complessità costante, sucessivamente due cicli for annidati 
che eseguono (n+1)*(m+1) iterazioni di complessità costante (m lunghezza di s1). Sucessivamente 
chiama la SCSTopDownAux che ha complessità O(n*m) e la memSCS che ha complessità 
theta(len) (len lunghezza della SCS tra s1 e s2), infine viene eseguito un ciclo 
for che esegue n+1 iterazioni di complessità costante.
Visto che len < n*m la complessità totale sarà theta(n*m).
*/
char* shortestCommonSupersequenceTopDown(char* s1, char* s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int len;
    int i, j;
    int **aux;
    char *res;

    aux = (int**) malloc(sizeof(int*) * (n+1));
    for (i = 0 ; i < n+1; i++) 
        aux[i] = (int *) malloc(sizeof(int) * (m+1));
    
    for (i = 0; i < n+1; i++)
        for (j = 0; j < m+1; j++)
            aux[i][j] = -1;

    len = SCSTopDownAux(s1, m, s2, n, aux);
    
    res = (char*) malloc(sizeof(char) * (len+1));    

    memSCS(s1, m, s2, n, aux, res);
    res[len] = '\0';

    for (i = 0; i < n+1; i++)
        free(aux[i]);

    free(aux);

     return res;
}
