#include <iostream>
using namespace std;

struct nodo
{
    int dato;
    nodo *siguiente;
};
struct cola
{
    nodo *delante;
    nodo *atras;
};
void encolar(cola &q, int valor)
{
    nodo *aux = new nodo;
    (*aux).dato = valor;
    (*aux).siguiente = nullptr;
    if (q.delante == nullptr)
        q.delante = aux;
    else
        (*q.atras).siguiente = aux;
    q.atras = aux;
}
void mostrarCola(cola &q)
{
    nodo *aux = q.delante;
    while (aux != nullptr)
    {
        cout << (*aux).dato << '\t'; // Imprime el dato del nodo actual
        aux = (*aux).siguiente;      // Mueve al siguiente nodo
    }
}
void desencolar(cola &q)
{
    nodo *aux = q.delante;
    int dato = (*aux).dato; // Guarda el dato del nodo que se va a eliminar
    q.delante = (*q.delante).siguiente; // Mueve la cabeza de la cola al siguiente nodo
    cout << "Desencolado: " << dato << endl;
    delete aux; // Libera la memoria al que este apuntando aux,
}
int main(){ 
    cola q;
    q.delante = nullptr;
    q.atras = nullptr;
    encolar(q,1);
    encolar(q,2);
    encolar(q,3);
    mostrarCola(q);
    desencolar(q);

    return 0;
}