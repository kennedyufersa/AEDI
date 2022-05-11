#include<stdio.h>
#include <list>

using namespace std;
struct aluno{
    int matricula;
    int nota;
};

void main2(){
    list<struct aluno> l;
    aluno a, b, c, d;
    a.matricula = 1;
    a.nota = 10;
    b.matricula = 2;
    b.nota = 5;
    c.matricula = 3;
    c.nota = 9;
    d.matricula = 4;
    d.nota = 3;
    l.push_front(a);
    l.push_front(b);
    l.push_front(c);
    l.push_front(d);

    /*it é um ponteiro que indica a localização dos elementos dentro da lista (container).
    As modificações no conteúdo desse ponteiro são mantidas na estrutura. Nesse caso, na lista.*/
    list<struct aluno>::iterator it;
    for(it=l.begin(); it!=l.end(); it++){
        if((*it).nota < 7){
            printf("O aluno %d tirou nota baixa (%d)\n", (*it).matricula, (*it).nota);
            printf("Ajuste de notas\n");
            (*it).nota = 8;
        }
    }

}
void main1(){
    list<int> l;
    for (int i = 0; i < 10; i++){
        l.push_front(i);
    }
    for (int i = 10; i < 20; i++){
        l.push_back(i);
    }

    list<int>::iterator it;
    for(it=l.begin(); it!=l.end(); it++){
        if(*it == 10){
            *it = 150;
        }
        //printf("%d\n", *it);
    }
}

int main(){
    main2();
}