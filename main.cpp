#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------
//HEAP


int heap_sort(int *vetor, int tamanho){
   
   int pai_direita, pai_esquerda, aux, contador;

   
   for(contador = tamanho-1;  contador >= 0;  contador-- ){
      
      
	  //descobrindo o a raiz de cada galho
      pai_direita  = (contador / 2) - 1;
      pai_esquerda = (contador - 2) / 2;
      
      
	  //trocando caso a raiz seja manor que o galho da direita
       if(vetor[contador] > vetor[pai_direita]){
         
         aux = vetor[contador];
         vetor[contador] = vetor[pai_direita];
         vetor[pai_direita] = aux;         
         
      }
      
      //trocando caso a raiz seja menor que o galho da esquerda
      else if (vetor[contador-1] > vetor[pai_esquerda] ){

         aux = vetor[contador-1];
         vetor[contador-1] = vetor[pai_esquerda];
         vetor[pai_esquerda] = aux;
         
      }

   }
}


//-----------------------------------------------------------
//Counting
void counting_sort(int vetor[],int maximo)
{
     int count[2000];
	 int i,j;
     
     for(i=0;i<2000;++i)
      
	 count[vetor[i]] = count[vetor[i]] + 1; //conta e salva no novo vetor
      
     
     for(i=0;i<=10;++i) //copia pro vetor original
     vetor[i] = count[i];
       
   }

void insertionsort( int vetor[], int tamanho)
{
	int i, temp, j;
	
	for (i=0; i<tamanho;i++)
	{
		temp =  vetor[i];
		j=i-1;
		while((j>=0) && (temp,vetor[j]))
		{
		vetor[j+1] = vetor[j];
		j--;
		}
		vetor[j+1] = temp;
	}
}

void selectionsort ( int vetor[], int tamanho)
{
	int min, temp, i, j;
	for (i = 0; i < tamanho; i++){
		min = i;
		for( j= i+1; j<tamanho; j++){
			if(vetor[min]>vetor[j])
			min = j;
		}
		if (i != min) {
			temp = vetor[i];
			vetor[i]= vetor[min];
			vetor[min] = temp;
		}
	}
}

void quicksort(int vetor[10], int iniciovetor, int finalvetor){
   
   int pivo, i, j, aux, meiovetor;
   
   i = iniciovetor; j = finalvetor;
   
   meiovetor = (int) ((i + j) / 2); //determina qual o indice mais próximo ao meio do vetor
   
   pivo = vetor[meiovetor]; // define o pivo como sendo o elemento central do vetor
   
   do{
      while (vetor[i] < pivo) i = i + 1; // percorre vetor enquanto elemento for menor que o pivô escolhido
      
	  while (vetor[j] > pivo) j = j - 1; // percorre vetor enquanto elemento for maior que o pivô escolhido
      
      if(i <= j){ 
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   } 
	while(j > i); //Ao final desta linha os elementos menores que o pivo estao a sua esquerda, e os maiores à direita
   
   
   // é chamada novamente a função para realizar o quicksort nos vetores resultantes
   if(iniciovetor < j) quicksort(vetor, iniciovetor, j); 
   
   if(i < finalvetor) quicksort(vetor, i, finalvetor);   

}

void merge(int vetor[],int iniciovetor1,int finalvetor1,int iniciovetor2,int finalvetor2) // Funcao merge responsavel por mesclar os vetores resultantes após o fim das divisoes do mergesort
{
	int aux[10], i, j, k;	
	
	i=iniciovetor1;	
	j=iniciovetor2;	
	k=0;
	
	while(i<=finalvetor1 && j<=finalvetor2)	
	{
		if(vetor[i]<vetor[j])
			aux[k++]=vetor[i++];
		else
			aux[k++]=vetor[j++];
	}
	
	
	while(i<=finalvetor1)	
		aux[k++]=vetor[i++];
		
	
	while(j<=finalvetor2)	
		aux[k++]=vetor[j++];
		
	
	for(i = iniciovetor1, j=0; i <= finalvetor2; i++, j++)
	
		vetor[i]=aux[j];
}

void mergesort(int vetor[],int i,int j)
{
	int meio;
		
	if(i<j)
	{
		meio=(i+j)/2; //determina metade do vetor
		
		mergesort(vetor,i,meio);	//recursao da primeira parte	
		
		mergesort(vetor,meio+1,j); //recursao da segunda parte	
		
		merge(vetor,i,meio,meio+1,j);	//merge das duas metades imediatas
	}
}

int main() {
	
	int opcao;
	int vetor[10];
	int i = 0, j = 0;
	int elemento;
	int tamanho = 10; 
	
	
	printf("Digite o vetor de 10 elementos a ser ordenado, um elemento por vez: \n ");
	
	
	while(i<tamanho){
	
	scanf("%d", &elemento);
	
	vetor[i] = elemento;
		i++;
	
	}
	
	

	
	printf("Digite a Opção: \n 1 - Insertion Sort \n 2 - Selection Sort \n 3 - QuickSort \n 4 - MergeSort \n 5 - CountingSort \n 6 - HeapSort \n" );
	
	scanf ("%d", &opcao);
	
	switch(opcao){
		
		case 1:
			
			insertionsort (vetor, tamanho);
			
			break;
			
		case 2:
			
			selectionsort (vetor, tamanho);
			
			break;
			
	
		case 3: 
			
			quicksort (vetor, 0, 9); // Pois no nosso caso, sempre temos um vetor de 10 elementos.
			
			break;
			
	
		case 4: 
			mergesort(vetor,0, 9); // Pois no nosso caso, sempre temos um vetor de 10 elementos.
			
			break;	
	
		case 5: 
			countingsort(vetor, 10); // Pois no nosso caso, sempre temos um vetor de 10 elementos.
			
			break;	
			
		case 6: 
			heapsort(vetor, 10); // Pois no nosso caso, sempre temos um vetor de 10 elementos.
			
			break;	
	
		
		default:
        	printf("Entrada invalida\n");
        	break;
			
	}
	
	printf("\n Vetor ordenado: \n");
	
	
	for(i = 0; i < tamanho; i++){	
	
		printf("%d - ", vetor[i]);
	}
	printf("\n");
	
	
	
	system("pause");
	return 0;
}