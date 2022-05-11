#include<list>
#include <queue>
#include<stdio.h>

using namespace std;

list<int> soma(list<int>, list<int>);
list<int> subtracao(list<int>, list<int>);
list<int> vezes10(list<int>*);

void printNumber(list<int> N){
    list<int>::iterator it;
    for (it = N.begin(); it != N.end(); it++)
    {
        printf("%d", *it);
    }
    printf("\n");
    
}

int main(){
    list<int> N;
    //int V[] = {1,2,1,2,1,4,5,2,3,8,6,4,5,8,9,5,3,1,3,5,7,9,1,5,4,1,0,9,0,8,7,6,7};
    int V[] = {1,9,1,1,1,5};
    for (size_t i = 0; i < 6; i++)
    {
        N.push_back(V[i]);
    }
    printNumber(N);
    list<int> C = soma(N, N);
    printNumber(C);
}

list<int> vezes10(list<int> *N){
    (*N).push_back(0);
    return (*N);
}

list<int> soma(list<int> A, list<int> B){
    list<int> C;
    list<int>::iterator itA;
    list<int>::iterator itB;
    int soma, x, y, aux=0;
    
    itA = A.end();
    itB = B.end();

    itA--;
    itB--;

    while(itA != A.begin()){
        x = *itA;
        y = *itB;
        soma = x + y + aux;
        aux = (soma > 9) ? 1 : 0;
        C.push_front(soma%10);
        itA--;
        itB--;
    }
    soma = x + y + aux;
    aux = (soma > 9) ? 1 : 0;
    C.push_front(aux);
    itA--;
    itB--;
    return C;
}
