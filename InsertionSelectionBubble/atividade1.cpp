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
int binaria(int v[],int chave, int baixo, int alto){
    while (baixo <= alto) {
        int meio = baixo + (alto - baixo) / 2;
        if (chave == v[meio])
            return meio + 1;
        else if (chave > v[meio])
            baixo = meio + 1;
        else
            alto = meio - 1;
    }

    return baixo;


}
void insertionBinario(int v[], int t){
    int i, j, temp, loc;
    for(i=1;i<t;i++){
        temp = v[i];
        j = i-1;
        loc = binaria(v,temp,0,j);
        while(j>=loc){
            v[j+1] = v[j];
            j--  ;

        }
        v[j+1] = temp;
        //imprime_vetor(v,t);
    }
    imprime_vetor(v,t);

}
void insertion(int v[], int t){
    int i, j, temp, comp = 0, troca = 0;
    for(i=1;i<t;i++){
        comp++;
        temp = v[i];
        j = i-1;
        while(j>=0&&v[j] > temp){
            v[j+1] = v[j];
            j--  ;
            troca++;
            comp++;
        }
        v[j+1] = temp;
        //imprime_vetor(v,t);
    }
    imprime_vetor(v,t);
    cout << "Numero de Trocas: " << troca;
    cout << endl;
    cout << "Numero de Comparacoes: " << comp;
    cout << endl;
}
void insertionDescendente(int v[], int t){
    int i, j, temp, comp = 0, troca = 0;
    for(i=1;i<t;i++){
        comp++;
        temp = v[i];
        j = i-1;
        while(j>=0&&v[j] < temp){
            v[j+1] = v[j];
            j--  ;
            troca++;
            comp++;
        }
        v[j+1] = temp;
        imprime_vetor(v,t);
    }
    cout << "Troca: " << troca;
    cout << endl;
    cout << "Comparacao: " << comp;
    cout << endl;

}
void selection(int v[], int t){
    int i, j, ind, temp, comp = 0, troca = 0;
    bool trocou = false;
    for(i=0;i<t-1;i++){
    ind = i;
    trocou = false;
        for(j=i+1;j<t;j++){
            comp++;
            if(v[j]<v[ind]){
                trocou = true;
                ind = j;
            }
        }
    if(trocou == true){
        troca++;
    }
    temp = v[ind];
    v[ind] = v[i];
    v[i] = temp;


}
    imprime_vetor(v,t);
    cout << "Numero de Trocas: " << troca;
    cout << endl;
    cout << "Numero de Comparacoes: " << comp;
    cout << endl;
}
void selectionDescendente(int v[], int t){
    int i, j, ind, temp, comp = 0, troca = 0;
    bool trocou = false;
    for(i=0;i<t-1;i++){
    ind = i;
    trocou = false;
        for(j=i+1;j<t;j++){
            comp++;
            if(v[j]>v[ind]){
                trocou = true;
                ind = j;
            }
        }
    if(trocou == true){
        troca++;
    }
    temp = v[ind];
    v[ind] = v[i];
    v[i] = temp;

    imprime_vetor(v,t);
}
    cout << "Troca: " << troca;
    cout << endl;
    cout << "Comparacao: " << comp;
    cout << endl;

}
void bubble(int v[], int t){
    int i,j,temp,comp = 0,troca = 0;
    for(i=0;i<t-1;i++){

        for(j=0;j<t-i-1;j++){
            comp++;
            if(v[j]>v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                troca++;
            }
        }

    }
    imprime_vetor(v,t);
    cout << "Numero de Trocas: " << troca;
    cout << endl;
    cout << "Numero de Comparacoes: " << comp;
    cout << endl;
}
void bubbleDescendente(int v[], int t){
   int i,j,temp, comp = 0, troca = 0;
    for(i=0;i<t-1;i++){
        for(j=0;j<t-i-1;j++){
            comp++;
            if(v[j]<v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                troca++;
            }
        }
    imprime_vetor(v, t);
    }
    cout << "Troca: " << troca;
    cout << endl;
    cout << "Comparacao: " << comp;
    cout << endl;
}
void vetorRandomInsertion(int tamanho){
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
    cout << "Vetor ascendente ordenado por Insertion: " << "\n";
    comeco = clock();
    insertion(vord_a, tamanho);
    fim = clock();
    double tempo_de_ex1 = double(fim - comeco) / double(CLOCKS_PER_SEC);
    cout << "Tempo de execucao : " << fixed
         << tempo_de_ex1 ;
    cout << " sec " << endl;
    cout << "\n";


	cout << "Vetor Descendente" << "\n";

	imprime_vetor(vord_d,tamanho);
	cout << "Vetor descendente ordenado por Insertion: " << "\n";
    comeco2 = clock();
    insertion(vord_d, tamanho);
    fim2 = clock();
    double tempo_de_ex2 = double(fim2 - comeco2) / double(CLOCKS_PER_SEC);
    cout << "Tempo de execucao : " << fixed
         << tempo_de_ex2 ;
    cout << " sec " << endl;
    cout << "\n";


    cout << "Vetor Randomico" << "\n";

	imprime_vetor(vord_r,tamanho);
	cout << "Vetor randomico ordenado por Insertion: " << "\n";
    comeco3 = clock();
    insertion(vord_r, tamanho);
    fim3 = clock();
    double tempo_de_ex3 = double(fim3 - comeco3) / double(CLOCKS_PER_SEC);
    cout << "Tempo de execucao : " << fixed
         << tempo_de_ex3 ;
    cout << " sec " << endl;
    cout << "\n";


}
void vetorRandomSelection(int tamanho){
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
    cout << "Vetor ascendente ordenado por Selection: " << "\n";
    comeco = clock();
    selection(vord_a, tamanho);
    fim = clock();
    double tempo_de_ex1 = double(fim - comeco) / double(CLOCKS_PER_SEC);
    cout << "Tempo de execucao : " << fixed
         << tempo_de_ex1 ;
    cout << " sec " << endl;
    cout << "\n";


	cout << "Vetor Descendente" << "\n";

	imprime_vetor(vord_d,tamanho);
	cout << "Vetor descendente ordenado por Selection: " << "\n";
    comeco2 = clock();
    selection(vord_d, tamanho);
    fim2 = clock();
    double tempo_de_ex2 = double(fim2 - comeco2) / double(CLOCKS_PER_SEC);
    cout << "Tempo de execucao : " << fixed
         << tempo_de_ex2 ;
    cout << " sec " << endl;
    cout << "\n";


    cout << "Vetor Randomico" << "\n";

	imprime_vetor(vord_r,tamanho);
	cout << "Vetor randomico ordenado por Selection: " << "\n";
    comeco3 = clock();
    selection(vord_r, tamanho);
    fim3 = clock();
    double tempo_de_ex3 = double(fim3 - comeco3) / double(CLOCKS_PER_SEC);
    cout << "Tempo de execucao : " << fixed
         << tempo_de_ex3 ;
    cout << " sec " << endl;
    cout << "\n";


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

int main(){
    //TODAS AS FUNÇÕES ESTÃO PRONTAS PARA SEREM EXECUTADAS, BASTA REMOVER OS COMENTÁRIOS
    int tam, vet[] = {10,9,8,7,6,5,4,3,2,1};
    int T = sizeof(vet)/sizeof(vet[0]);
    imprime_vetor(vet,T);
    //AQUI ESTÃO OS DIFERENTES METODOS DE SORT,ASCENDENTES E DESCENDENTES PARA O VETOR VET[]
    //insertionBinario(vet,T);
    //insertion(vet,T);
    //insertionDescendente(vet,T);
    //selection(vet,T);
    //selectionDescendente(vet,T);
    bubble(vet,T);
    //bubbleDescendente(vet,T);


    //AQUI ESTÃO AS FUNCÕES PARA ORDENAR OS VETORES ALEATÓRIOS
    //USE O CIN PARA DETERMINAR O TAMANHO DO VETOR GERADO ALEATORIAMENTE
    /*
    cout << "Determine o tamanho dos vetores randomicos" << "\n";
    cin >> tam;
    vetorRandomInsertion(tam);
    vetorRandomSelection(tam);
    vetorRandomBubble(tam);
    */


return 0;

}
