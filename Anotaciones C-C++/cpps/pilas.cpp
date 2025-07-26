#include <iostream>
using namespace std;

struct nodo // No voy a necesitar de una cabeza y de un fondo, solo un "elemento del nodo"
{
    int dato;
    nodo *siguiente;
};
void push(nodo *&p, int dato)
{
    nodo *auxiliar = new nodo;
    (*auxiliar).dato = dato;
    (*auxiliar).siguiente = p;
    p = auxiliar;
}
void mostrarPila(nodo *p) // No recibir parametro con un &
{
    while (p != nullptr)
    {
        cout << (*p).dato << '\t'; // Imprime el dato del nodo actual
        p = (*p).siguiente;       // Mueve al siguiente nodo
    }
}
void pop(nodo *&p)
{
    nodo *aux = p;
    int dato = (*aux).dato;
    p = (*p).siguiente;
    cout << "Desapilado: " << dato << endl;
    delete aux;
}
int main(){
    nodo *p = nullptr;
    push(p, 5);
    push(p, 10);
    push(p, 15);
    mostrarPila(p);
    pop(p);
    mostrarPila(p);
    return 0;
}
