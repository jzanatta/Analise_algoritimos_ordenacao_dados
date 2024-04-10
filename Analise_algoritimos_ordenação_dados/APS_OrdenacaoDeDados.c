#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// BUBBLE SORT ->
void bubble(int vet[], int n){
	int i, j, aux;
		for (i = 1; i < n; i++){
			for (j = 0; j < n-1; j++){
				if (vet[j]> vet[j+1]){
					aux = vet[j];
					vet[j] = vet[j+1];
					vet[j+1] = aux;
				}
			}
		}
}

// INSERTION SORT ->
void insertion(int vet[], int n){
	int i, j, aux;
		for(i = 0; i < n-1; i++){
			if(vet[i] > vet[i+1]){
				aux = vet[i+1];
				vet[i+1] = vet[i];
				vet[i] = aux;
				j = i-1;
				while(j >= 0){
					if(aux < vet[j]){
						vet[j+1] = vet[j];
						vet[j]=aux;
					}else{
						break;
					}
					j--;
				}
			}
		}
}

// MERGE SORT ->
void mergeSort(int *vet, int inicio, int meio, int fim){
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio+1;
	temp = (int *) malloc(tamanho*sizeof(int));
	if(temp!=NULL){
		for(i=0; i<tamanho; i++){
			if(!fim1 && !fim2){
				if(vet[p1] < vet[p2])
					temp[i] = vet[p1++];
				else 
					temp[i] = vet[p2++];
				if(p1>meio) fim1=1;
				if(p2>fim) fim2=1;
			}else{
				if(!fim1) 
					temp[i] = vet[p1++];
				else 
					temp[i] = vet[p2++];
			}
		}
		for(j=0, k=inicio; j<tamanho; j++, k++){
			vet[k] = temp[j];
		}
		free(temp);
	}
}
void merge(int *vet, int inicio, int fim){
	int meio;
	if(inicio < fim){
		meio = (inicio + fim)/2;
		merge(vet, inicio, meio);
		merge(vet, meio+1, fim);
		mergeSort(vet, inicio, meio, fim);
	}
}

// SELECTION SORT->
void selection(int *vet, int n){
	int i, j, menor, troca;
	for(i=0; i<n-1;i++){
		menor = i;
		for(j = i+1; j<n; j++){
			if(vet[j] < vet[menor])
				menor = j;
		}
		if(i != menor){
			troca = vet[i];
			vet[i] = vet[menor];
			vet[menor] = troca;
		}
	}
}


//Funcoes uteis
int imprimir(int vet[], int n){
	int i;
	for (i = 0; i < n; i++) {
		printf("%i ",vet[i]);
	} // Responsável por receber o vetor vet[] e imprimir no terminal os valores de todas as suas posições.
}
int qualBanco(n){
	while (n < 1 || n > 4){ // primeiro menu
	printf("\nEntre com o numero do banco de dados voce deseja ordenar?\n");
	printf("1- vetor de 20.000 posicoes\n");
	printf("2- vetor de 50.000 posicoes\n");
	printf("3- vetor de 100.000 posicoes\n");
	scanf("%d",&n);
	}
	if (n == 1){
		n = 20000;
	}
	if (n == 2){
		n = 50000;
	}
	if (n == 3){
		n = 100000;
	}
	return n; // Identifica qual banco o usuário quer ordenar e armazena o valor na variável "n".
}


int main() {

int n = 0; // Inicializa a variavel n
n = qualBanco(n); // Utiliza  a função para retornar a varavel "n" com o valor de qual banco será ordenado
	
int variavel = 0; // Variavel responsavel por controlar o menu
while (variavel != 5){ // Inicialização do loop do menu
	
	FILE *file; // Cria a variável ponteiro para o arquivo
	char arquivo[50];
	sprintf(arquivo, "Banco_de_dados%d.txt", n); // Identifica qual o valor da variavel n, portanto qual arquivo de banco de dados sera ordenado
	file = fopen(arquivo, "r"); // Abre o arquivo que foi gerado anteriormente
	int i = 0, vet[n]; 
	
	if(file == NULL){ // Verifica se o arquivo foi aberto corretamente, caso contrario encerra o programa
		printf("Arquivo nao pode ser aberto\n");
		system("pause");
		return 0;
	}
    for (i = 0; i < n; i++) { // Lê os números do arquivo e os armazena no vetor vet[]
        fscanf(file, "%d", &vet[i]);
	}

	while(variavel < 1 || variavel > 5){ // Inicialização do menu - identifica qual algoritimo ordenara o banco escolhido, ou encerra o programa
		printf("\nEntre com o numero do algoritimo com que dejesa ordenar os dados:");
		printf("\n1- BUBBLE SORT");
		printf("\n2- INSERTION SORT ");
		printf("\n3- MERGE SORT");
		printf("\n4- SELECTION SORT");
		printf("\n5- SAIR\n");
		scanf("%d", &variavel); 
	}

	
	if (variavel != 5){
		printf("Ordenando...\n");
		clock_t Ticks[2]; 
		Ticks[0] = clock(); // Começo da contagem de tempo
		
		if (variavel == 1) bubble(vet, n); // Chama a função referente ao algoritimo de ordenação de dados escolhido
		else if (variavel == 2) insertion(vet, n);
		else if (variavel == 3) merge(vet, 0, n-1);
		else selection(vet, n);
		
		Ticks[1] = clock(); // Fim da contagem de tempo
		double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC; 
			
		imprimir(vet, n); // Chamada da função de impressão
		printf("\nTempo gasto: %g ms.\n", Tempo);
	} 
	
	
	fclose(file); // Fechar o arquivo 

if (variavel != 5) variavel = 0; 
} // Fim do loop do menu
    return 0;
}
