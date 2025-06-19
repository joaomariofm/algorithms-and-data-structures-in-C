/**
 * Observação:
 *  A Busca Binária assume que o array já está
 *  organizado quando inicia sua execução
*/

int buscaBinaria(int *V, int N, int elem) {
    int i, inicio, meio, final;
    inicio = 0;
    final = N-1;
    while(inicio <= final) {
        meio = (inicio + final)/2;
        if(elem < V[meio])
            final = meio-1;//busca na metade da esquerda
        else   
            if(elem > V[meio])
                inicio = meio+1;//busca na metade da direita
            else    
                return meio;
    }
    return -1;//elemento não encontrado
}
