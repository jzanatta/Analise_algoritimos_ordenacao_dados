#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	FILE *file; // cria variável ponteiro para o arquivo
	int x = 1;
	while (x < 4){
		int n;
		if (x == 1) n = 20000;
		if (x == 2) n = 50000;
		if (x == 3) n = 100000;
	
    int i = 0, j, teste, vet[n];

	char arquivo[50];
	sprintf(arquivo, "Banco_de_dados%d.txt", n);
 	file = fopen(arquivo, "w"); // r ler | a escrever | w sobreescrever
  
  	//testando se o arquivo foi realmente criado
  	if(file == NULL){
  	printf("Erro na abertura do arquivo!");
  	return 1;
  	}

    srand(time(NULL));
    
	printf(" Gerando banco de dados de %d numeros...\n", n);
    for (i = 0; i < n; i++) { 	// Preenche o vetor com números de 1 a N
        vet[i] = i + 1;
    }
	for (i = n - 1; i > 0; i--){    // Embaralha os números
		int j = rand() % (i + 1);
        int temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
	}
    
    printf(" ");
    for(i = 0; i < n; i++){
        //printf("%d ", vet[i]); 
		// Se desejar ver os numero impressos na tela, basta descomentar a linha acima
        
  		fprintf(file, "%d ", vet[i]);	//usando fprintf para armazenar cada valor do array no arquivo
    }

  	fclose(file); 	//usando fclose para fechar o arquivo
  	printf(" Arquivo gerado com sucesso!\n\n");
  	
  	
	x++;
  }
    return 0;
}
