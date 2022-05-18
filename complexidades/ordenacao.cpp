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

/*
    O algoritmo apresentado no main está ordenando elementos com a quantidade expressa no vetor v(vSize), com valores incrementados em vIncrement.
*/
int main()
{
    int vSize = 100;
    int vIncrement = 100;   
    int *v = (int*)malloc(vSize*sizeof(int));
    for(int i=0; i<vSize; i++){
        v[i] = vIncrement*(i+1);
    }
    for(int j=0; j<vSize; j++){
        gerarNumerosAleatorios(v[j]);
        int *x = (int*)malloc(v[j]*sizeof(int));
        for(int i=0; i<2; i++){
            //BubbleSort
            x = lerDados(v[j]);
            clock_t dB = clock();
            bubbleSort(x, v[j]);
            dB = clock() - dB;
            FILE *f = fopen("tempoBubble.txt", "a");
            fprintf(f, "%d\t%f\n", v[j], (float) 1000*dB/CLOCKS_PER_SEC);
            fclose(f);

            //QuickSort
            x = lerDados(v[j]);
            clock_t dQ = clock();
            quicksort(x, 0, v[j]);
            dQ = clock() - dQ;
            FILE *fQ = fopen("tempoQuick.txt", "a");
            fprintf(fQ, "%d\t%f\n", v[j], (float) 1000*dQ/CLOCKS_PER_SEC);
            fclose(fQ);

            //MergeSort
            x = lerDados(v[j]);
            clock_t dM = clock();
            mergeSort(x, 0, v[j], v[j]);
            dM = clock() - dM;
            FILE *fM = fopen("tempoMerge.txt", "a");
            fprintf(fM, "%d\t%f\n", v[j], (float) 1000*dM/CLOCKS_PER_SEC);
            fclose(fM);
        }
    }
    //quicksort(x, 0, N);
    //mergeSort(x, 0, N);
    //mostrarValores(x, v[0]);
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
