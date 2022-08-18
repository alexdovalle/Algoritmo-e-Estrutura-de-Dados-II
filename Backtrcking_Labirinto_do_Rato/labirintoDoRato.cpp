#include <iostream>
using namespace std;
#define TAM 4

bool solucaoLab(int lab[TAM][TAM], int x, int y, int solucao[TAM][TAM]);

//Funcao para printar a solucao do labirinto
void printaSolucao(int solucao[TAM][TAM]){
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++)
            cout<<" "<<solucao[i][j]<<" ";


        cout<<endl;
    }

}

//Função que verifica se a posição x,y existe na matriz
bool existePosicao(int lab[TAM][TAM], int x, int y){
    if(x >=0 && x < TAM && y >=0 && y < TAM && lab[x][y] == 1){
        return true;
    }
    return false;
}
// esta funçao irá percorrer o labirinto usando BackTracking,
// usando a função soluçãoLab. Se não existir um caminho para percorrer
// retorna falso. Se um caminho existir, retorna verdadeiro e printa
// o percurso usando o numero 1 para representar o caminho correto.
bool percorreLabirinto(int lab[TAM][TAM]){
    int solucao[TAM][TAM] = { { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } };
    if(solucaoLab(lab,0,0,solucao)==false){
        cout << "Nao existe solucao para este labirinto";
        return false;
    }
    printaSolucao(solucao);
    return true;
}
//usando a função de forma recursiva para resolver o problema
bool solucaoLab(int lab[TAM][TAM], int x, int y, int solucao[TAM][TAM]){
    //Se x e y estão no destino final do percurso, retorna true
    if(x == TAM-1 && y == TAM-1 && lab[x][y] == 1){
        solucao[x][y] = 1;
        return true;
    }
    //ver se a posição x,y existe no labirinto
    if (existePosicao(lab, x, y)==true){
        //verifica se o bloco atual já faz parte da solução
        if(solucao[x][y]==1){
            return false;
        }
        solucao[x][y] = 1;
        //Avança na direção x
		if (solucaoLab(lab, x + 1, y, solucao) == true){
			return true;
		}
		// Se a direção x não for o caminho, mexesse para baixo
		//na direção y
		if (solucaoLab(lab, x, y + 1, solucao) == true){
			return true;
		}
		//Se nenhum dos caminhos levar para o fim, VOLTAMOS
		//um espaço e removemos x,y atuais da solução
		solucao[x][y] = 0;
		return false;
	}
	return false;


}

int main(){
    int lab[TAM][TAM] = { { 1, 1, 0, 0 },
					{ 1, 1, 0, 1 },
					{ 0, 1, 0, 0 },
					{ 1, 1, 1, 1 } };
    percorreLabirinto(lab);


return 0;
}

