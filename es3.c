
/*
 * Complete the 'contaStringhe' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */
int count = 0;

/*
Il caso base è quando n = 1.
T(n) = T(n-1) + O(1) , perciò avro n chiamate ricorsive di complessità costante.
Quindi T(n) = theta(n).
*/
void contaStringheAux(int n, int *a, int *e, int *i, int *o, int *u) {
	if (n > 1) {
		contaStringheAux(n-1, a, e, i, o, u);
		a[n] = e[n-1] + i[n-1] + u[n-1];
		e[n] = a[n-1] + i[n-1];
		i[n] = e[n-1] + o[n-1];
		o[n] = i[n-1];
		u[n] = i[n-1] + o[n-1];

		count++;
	}
}

/*
Ipotizzo malloc e free in tempo costante.
Viene invocata la contaStringheAux che ha complessità pari a theta(n).
Quindi T(n) = theta(n).
*/
int contaStringhe(int n) {
    int *a , *e, *i, *o, *u;
    int j, count;; 
    if (n <= 0)
        return 1;

    a = (int *) malloc(sizeof(int) * (n+1));
    e = (int *) malloc(sizeof(int) * (n+1));
    i = (int *) malloc(sizeof(int) * (n+1));
    o = (int *) malloc(sizeof(int) * (n+1));
    u = (int *) malloc(sizeof(int) * (n+1));

    a[0] = e[0] = i[0] = o[0] = u[0] = 0;
    a[1] = e[1] = i[1] = o[1] = u[1] = 1;
    for (j = 2; j < n+1; j++){
        a[j] = e[j] = i[j] = o[j] = u[j] = -1;
    }
    contaStringheAux(n, a, e, i, o, u);
    count = a[n] + e[n] + i[n] + o[n] + u[n];

    free(a);
    free(e);
    free(i);
    free(o);
    free(u);
    return count;
}

/*
Viene eseguito un ciclo for che esegue n-1 iterazini di complessità costante (il ciclo
inerno ha complessità constante perchè esegue sempre e solo 5 iterazioni di 
complessità cosntante).
Quindi T(n) = theta(n);
*/
int contaStringhe(int n){
	int len[5] = {1,1,1,1,1};
	int tmp[5];
	int i, j;

	if (n <= 0)
		return 1;

	for (i = 2; i <= n; i++) {

		for(j = 0; j < 5; j++)
			tmp[j] = len[j];

		len[0] = tmp[1] + tmp[2] + tmp[4];
		len[1] = tmp[0] + tmp[2];
		len[2] = tmp[1] + tmp[3];
		len[3] = tmp[2];
		len[4] = tmp[2] + tmp[3];
	}

	return len[0] + len[1] + len[2] + len[3] + len[4];

}

int main(){
	int res = contaStringhe(56);
	printf("Le stringe di lunghezza %d sono %d e ho eseguito %d iterazioni\n", 56, res, count);
}