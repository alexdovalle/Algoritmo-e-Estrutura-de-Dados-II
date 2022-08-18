#include <bits/stdc++.h>
using namespace std;

int comparacao = 0, movimentacao = 0;

void imprimeVetor(int vetor[], int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        cout << vetor[i] << ",";
    }
    cout << endl;
}

void merge(int vetor[], int inicio, int meio, int fim){
    int i,j,k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int vetorEsquerda[n1], vetorDireita[n2];
    for(i=0;i<n1;i++){
        vetorEsquerda[i] = vetor[inicio + i];
    }
     for(j=0;j<n2;j++){
        vetorDireita[j] = vetor[meio + j +1];
     }

    i = 0;
    j = 0;
    k = inicio;
    while(i < n1 && j < n2){
            if(vetorEsquerda[i] <= vetorDireita[j]){
                vetor[k] = vetorEsquerda[i];
                i++;
                comparacao++;
                movimentacao++;
            }
            else{
                vetor[k] = vetorDireita[j];
                j++;
                movimentacao++;
                comparacao++;
            }
            k++;
        }
    while(i < n1){

            vetor[k] = vetorEsquerda[i];
            movimentacao++;
            i++;
            k++;

        }
    while(j < n2){

            vetor[k] = vetorDireita[j];
            movimentacao++;
            j++;
            k++;

        }



}

void mergeSort(int vetor[], int inicio, int fim){
    if(inicio<fim){
        int meio = inicio + (fim - inicio)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }


}

int particao(int vetor[], int inicio, int fim){
    int temporario, j;
    int pivot = vetor[fim];
    int i = (inicio - 1);

    for(j = inicio;j <= fim - 1;j++){

        if(vetor[j] < pivot){
            comparacao++;
            i++;
            temporario = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temporario;
            movimentacao++;
        }
    }
    temporario = vetor[i+1];
    vetor[i+1] = vetor[fim];
    vetor[fim] = temporario;
    movimentacao++;
    return (i+1);
}

int particaoMediana(int vetor[], int inicio, int fim){
    int temporario, j, x = vetor[inicio], y=vetor[(fim-inicio)/2+(inicio)] , z=vetor[fim-1];

}

void quickSort(int vetor[], int inicio, int fim){

    if(inicio < fim){
        int meio = particao(vetor,inicio,fim);

        quickSort(vetor,inicio,meio-1);
        quickSort(vetor,meio+1,fim);
    }
}

int main(){
    clock_t start, end;
    int v[] = {89, 79, 32, 38, 46, 26, 43, 38, 32, 79};

    int tam = sizeof(v)/sizeof(v[0]);

    imprimeVetor(v,tam);
    //start = clock();
    //mergeSort(v,0,tam - 1);
    quickSort(v,0,tam - 1);
    //end = clock();
    imprimeVetor(v,tam);
    cout << "O numero de comparacoes eh: " << comparacao << "\n";
    cout << "O numero de movimentacoes eh: " << movimentacao << "\n";
    /*double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Tempo de execucao do sort eh : " << fixed
         << time_taken << setprecision(5);
    cout << " segundos " << endl;*/



return 0;
}
