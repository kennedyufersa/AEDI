#include<list>
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
    int V[] = {1,2,1,2,1,4,5,2,3,8,6,4,5,8,9,5,3,1,3,5,7,9,1,5,4,1,0,9,0,8,7,6,7};
    for (size_t i = 0; i < 33; i++)
    {
        N.push_back(V[i]);
    }
    printNumber(N);
    vezes10(&N);
    printNumber(N);
}

list<int> vezes10(list<int> *N){
    (*N).push_back(0);
    return (*N);
}