#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;



void imprime_vetor(int v[], int t){
    int i;
    for(i=0;i<t;i++)
        cout << v[i] << ",";
    cout << endl;

}

void bubble(int v[], int t){
    int i,j,temp, comp = 0, troca = 0;
    for(i=0;i<t-1;i++){

        for(j=0;j<t-i-1;j++){
            comp++;
            if(v[j]>v[j+1]){
                troca++;
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;

            }
        }

    }
    imprime_vetor(v,t);
    cout << "Numero de Trocas: " << troca;
    cout << endl;
    cout << "Numero de Comparacoes: " << comp;
    cout << endl;
}
void vetorRandomBubble(int tamanho){
    clock_t comeco,comeco2,comeco3,fim,fim2,fim3;

    int vord_a[tamanho];
	int vord_d[tamanho];
	int vord_r[tamanho];


	for (int i = 0; i <tamanho; i++){

		vord_a[i]=i+1;
		vord_d[i]=tamanho-i;
		vord_r[i]= rand() % tamanho;
}
    cout << "Vetor Ascendente" << "\n";
	imprime_vetor(vord_a,tamanho);
    cout << "Vetor ascendente ordenado por Bubble: " << "\n";
    comeco = clock();
    bubble(vord_a, tamanho);
    fim = clock();
    double tempo_de_ex1 = double(fim - comeco) / double(CLOCKS_PER_SEC);
    cout << "Tempo de execucao : " << fixed
         << tempo_de_ex1 ;
    cout << " sec " << endl;
    cout << "\n";


	cout << "Vetor Descendente" << "\n";

	imprime_vetor(vord_d,tamanho);
	cout << "Vetor descendente ordenado por Bubble: " << "\n";
    comeco2 = clock();
    bubble(vord_d, tamanho);
    fim2 = clock();
    double tempo_de_ex2 = double(fim2 - comeco2) / double(CLOCKS_PER_SEC);
    cout << "Tempo de execucao : " << fixed
         << tempo_de_ex2 ;
    cout << " sec " << endl;
    cout << "\n";


    cout << "Vetor Randomico" << "\n";

	imprime_vetor(vord_r,tamanho);
	cout << "Vetor randomico ordenado por Bubble: " << "\n";
    comeco3 = clock();
    bubble(vord_r, tamanho);
    fim3 = clock();
    double tempo_de_ex3 = double(fim3 - comeco3) / double(CLOCKS_PER_SEC);
    cout << "Tempo de execucao : " << fixed
         << tempo_de_ex3 ;
    cout << " sec " << endl;
    cout << "\n";


}
void heapify(int vetor[], int tamanho, int i, int& contaCompara, int& contaTroca){
    // MAIOR RECEBE A RAIZ
    int maior = i;

    int noEsquerda = 2 * i + 1;

    int noDireita = 2 * i + 2;

    // SE NO NA ESQUERDA FOR MAIOR QUE RAIZ
    if (noEsquerda < tamanho && vetor[noEsquerda] > vetor[maior]){
        contaCompara++;
        maior = noEsquerda;
    }
    // SE O NÓ DA DIREITA FOR MAIOR QUE O MAIOR ATUAL
    if (noDireita < tamanho && vetor[noDireita] > vetor[maior]){
        contaCompara++;
        maior = noDireita;
    }
    // SE MAIOR FOR DIFERENTE DE RAIZ
    if (maior != i) {
        contaTroca++;
        swap(vetor[i], vetor[maior]);

        // APLICAR HEAPIFY RECURSIVAMENTE NA SUBÁRVORE
        heapify(vetor, tamanho, maior, contaCompara, contaTroca);
    }
}
void heapSort(int vetor[], int tamanho, int& contaCompara, int& contaTroca){

    // Transformar o vetor em Heap
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heapify(vetor, tamanho, i, contaCompara, contaTroca);

    // Remover elementos do vetor
    for (int i = tamanho - 1; i > 0; i--) {
        contaTroca++;
        // Manda a raiz atual pro fim
        swap(vetor[0], vetor[i]);

        // Heapify na heap reduzida
        heapify(vetor, i, 0, contaCompara, contaTroca);
    }
}
void vetorRandomHeap(int tamanho, int& contaCompara, int& contaTroca){
    clock_t comeco,comeco2,comeco3,fim,fim2,fim3;

    int vord_a[tamanho];
	int vord_d[tamanho];
	int vord_r[tamanho];


	for (int i = 0; i <tamanho; i++){

		vord_a[i]=i+1;
		vord_d[i]=tamanho-i;
		vord_r[i]= rand() % tamanho;
}
    cout << "Vetor Ascendente" << "\n";
	imprime_vetor(vord_a,tamanho);
    cout << "Vetor ascendente ordenado por HeapSort: " << "\n";
    comeco = clock();
    heapSort(vord_a, tamanho, contaCompara, contaTroca);
    fim = clock();
    imprime_vetor(vord_a,tamanho);
    cout << "Numero de Trocas: " << contaTroca;
    cout << endl;
    cout << "Numero de Comparacoes: " << contaCompara;
    cout << endl;
    double tempo_de_ex1 = double(fim - comeco) / double(CLOCKS_PER_SEC);
    cout << "Tempo de execucao : " << fixed
         << tempo_de_ex1 ;
    cout << " sec " << endl;
    cout << "\n";


	cout << "Vetor Descendente" << "\n";

	imprime_vetor(vord_d,tamanho);
	cout << "Vetor descendente ordenado por HeapSort: " << "\n";
    comeco2 = clock();
    heapSort(vord_d, tamanho, contaCompara, contaTroca);
    fim2 = clock();
    imprime_vetor(vord_d,tamanho);
    double tempo_de_ex2 = double(fim2 - comeco2) / double(CLOCKS_PER_SEC);
    cout << "Numero de Trocas: " << contaTroca;
    cout << endl;
    cout << "Numero de Comparacoes: " << contaCompara;
    cout << endl;
    cout << "Tempo de execucao : " << fixed
         << tempo_de_ex2 ;
    cout << " sec " << endl;
    cout << "\n";


    cout << "Vetor Randomico" << "\n";

	imprime_vetor(vord_r,tamanho);
	cout << "Vetor randomico ordenado por HeapSort: " << "\n";
    comeco3 = clock();
    heapSort(vord_r, tamanho, contaCompara, contaTroca);
    fim3 = clock();
    imprime_vetor(vord_r,tamanho);
    cout << "Numero de Trocas: " << contaTroca;
    cout << endl;
    cout << "Numero de Comparacoes: " << contaCompara;
    cout << endl;
    double tempo_de_ex3 = double(fim3 - comeco3) / double(CLOCKS_PER_SEC);
    cout << "Tempo de execucao : " << fixed
         << tempo_de_ex3 ;
    cout << " sec " << endl;
    cout << "\n";


}



int main(){

    int contaCompara = 0, contaTroca = 0;
    int tamanho,i;
    cout << "Determine o tamanho dos vetores randomicos" << "\n";
    cin >> tamanho;

    vetorRandomBubble(tamanho);

    vetorRandomHeap(tamanho, contaCompara, contaTroca);



return 0;
}
