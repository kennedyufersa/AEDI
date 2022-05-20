#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "numerosAleatorios.cpp"


int* lerDados(int);
void gerarNumerosAleatorios(int);
void mostrarValores(int*,int);

void bubbleSort(int*, int);
void quicksort(int*, int, int);
void mergeSort(int *, int, int,int);

void merge(int *,int, int , int,int );
void swap(int *a, int *b);

float tempo(clock_t tempo);

/*
    O algoritmo apresentado no main está ordenando elementos com a quantidade expressa no vetor v(vSize), com valores incrementados em vIncrement.
*/
int main()
{
    int vSize = 100;
    int vIncrement = 1000; 
    int tentativa = 5; 
    clock_t dB[tentativa], dQ[tentativa], dM[tentativa];
    int *v = (int*)malloc(vSize*sizeof(int));
    for(int i=0; i<vSize; i++){
        v[i] = vIncrement*(i+1);
    }
    for(int j=0; j<vSize; j++){
        gerarNumerosAleatorios(v[j]);
        int *x = (int*)malloc(v[j]*sizeof(int));
        for(int i=0; i<tentativa; i++){
            //BubbleSort
            x = lerDados(v[j]);
            dB[i] = clock();
            bubbleSort(x, v[j]);
            dB[i] = clock() - dB[i];
    
            //QuickSort
            x = lerDados(v[j]);
            dQ[i] = clock();
            quicksort(x, 0, v[j]);
            dQ[i] = clock() - dQ[i];

            //MergeSort
            x = lerDados(v[j]);
            dM[i] = clock();
            mergeSort(x, 0, v[j], v[j]);
            dM[i] = clock() - dM[i];
        }
        clock_t sB=dB[0]/tentativa;
        clock_t sQ=dQ[0]/tentativa;
        clock_t sM=dM[0]/tentativa;
        for (int i = 1; i < tentativa; i++){
            sB += dB[i]/tentativa;
            sQ += dQ[i]/tentativa;
            sM += dM[i]/tentativa;
        }
        FILE *f = fopen("tempos.txt", "a");
        fprintf(f, "%d\t%f\t%f\t%f\n", v[j], tempo(sB), tempo(sQ), tempo(sM));
        fclose(f);
    }
}

int* lerDados(int t){
    FILE *f = fopen("numerosAleatorios.txt", "r");
    int* res = (int*)malloc(t*sizeof(int));
    int aux = 0;
    while(!feof(f)){
        fscanf(f, "%d", &res[aux++]);
    }
    return res;
}

void gerarNumerosAleatorios(int t){
    int dispersao = 100;
    srand(100);
    int* res = numerosAleatorios(t, dispersao);
    escreverEmArquivo(res, t);
}

void mostrarValores(int *x, int t){
    for (int i = 0; i < t; i++)
    {
        printf("x[%d] = %d\n", i, x[i]);
    }   
}

void bubbleSort(int *x, int n){ 
    if (n < 1)return; 
    for (int i=0; i<n; i++){
        if (x[i] > x[i+1]){
            swap(&x[i], &x[i+1]);  
        }
    }
    bubbleSort(x, n-1); 
}

void quicksort(int *x, int ini, int fim){
	int i, j, pivo, aux;
	i = ini;
	j = fim-1;
	pivo = x[(ini + fim) / 2];
	while(i <= j){
		while(x[i] < pivo && i < fim){
			i++;
		}
		while(x[j] > pivo && j > ini){
			j--;
		}
		if(i <= j){
			aux = x[i];
			x[i] = x[j];
			x[j] = aux;
			i++;
			j--;
		}
	}
	if(j > ini)
		quicksort(x, ini, j+1);
	if(i < fim)
		quicksort(x, i, fim);
}

void mergeSort(int *x, int inf, int sup, int t)
{
    int meio;
    if (inf < sup){
        meio=(inf+sup)/2;
        mergeSort(x,inf,meio,t);
        mergeSort(x,meio+1,sup,t);
        merge(x,inf,sup,meio, t);
    }
}

void merge(int *x, int inf, int sup, int mid, int t)
{
    int i, j, k, c[t];
    i = inf;
    k = inf;
    j = mid + 1;
    while (i <= mid && j <= sup) {
        if (x[i] < x[j]) {
            c[k] = x[i];
            k++;
            i++;
        }
        else  {
            c[k] = x[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = x[i];
        k++;
        i++;
    }
    while (j <= sup) {
        c[k] = x[j];
        k++;
        j++;
    }
    for (i = inf; i < k; i++)  {
        x[i] = c[i];
    }
}

void swap(int *a, int *b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

float tempo(clock_t tempo){
    return ((float) tempo)/CLOCKS_PER_SEC;
}