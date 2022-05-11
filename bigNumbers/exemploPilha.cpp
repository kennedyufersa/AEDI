#include<stdio.h>
#include<stack>

using namespace std;

struct aluno
{
    int matricula;
    int nota;
};


void main1(){
    stack<struct aluno> p;
    aluno a, b;
    a.matricula = 1;
    a.nota = 10;
    b.matricula = 2;
    b.nota = 9;
    p.push(a);
    p.push(b);
}
void main2(){
    stack<int> p;
    for (int i = 0; i < 10; i++)
    {
        printf("Elemento %d inserido\n", i);
        p.push(i);
    }

    while(!p.empty()){
        int r = p.top();
        p.pop();
        printf("Elemento %d removido\n", r);
    }
    
}

int main(){
    main1();
    main2();
}