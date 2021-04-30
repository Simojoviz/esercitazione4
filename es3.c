
/*
 * Complete the 'contaStringhe' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */
/*
Viene eseguito un ciclo for che esegue n-1 iterazioni di complessità costante (il ciclo
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
