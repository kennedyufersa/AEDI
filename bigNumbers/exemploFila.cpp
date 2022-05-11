#include <stdio.h>
#include <queue>

using namespace std;
struct aluno
{
    int matricula;
    int nota;
};

void main2(){
    queue<struct aluno> f;
    aluno a, b;
    a.matricula = 1;
    a.nota = 10;
    b.matricula = 2;
    b.nota = 9;
    f.push(a);
    f.push(b);
    f.pop();
}

void main1(){
    queue<int> f;
    for(int i=0; i<10; i++){
        printf("Elemento %d inserido\n", i);
        f.push(i);
    }
    while(!f.empty()){
        int r = f.front();
        f.pop();
        printf("Elemento %d removido\n", r);
    }
}

int main(){
    main2();
}