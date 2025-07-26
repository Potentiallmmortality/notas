#include <iostream>
using namespace std;
struct nodo
{
    int dato;
    nodo *siguiente;
};
void insertarInicio(nodo *&p, int dato) // Agregar una cabeza a la lista, misma lógica que una pila
{
    nodo *auxiliar = new nodo;
    (*auxiliar).dato = dato;
    (*auxiliar).siguiente = p;
    p = auxiliar;
}
void eliminarInicio(nodo *&p) // Misma lógica que una pila, eliminar la cabeza
{
    if (p != nullptr)
    {
        nodo *auxiliar = p;
        p = (*p).siguiente;
        delete auxiliar;
    }
}
void insertarFinal(nodo *&p, int dato) // Agregar un elemento al final de la lista
{
    nodo *auxiliar = new nodo;
    (*auxiliar).dato = dato;
    (*auxiliar).siguiente = nullptr; // La cola apunta a nullptr
    if (p == nullptr) // Si la lista está vacía, el nuevo nodo es la cabeza
    {
        p = auxiliar;
    }
    else
    {
        nodo *temp = p; // temp apunta a la "pila" formada
        while ((*temp).siguiente != nullptr) // Recorre el bucle mientras el siguiente de la pila no sea nullptr, osea hasta el final
        {
            temp = (*temp).siguiente;
        }
        (*temp).siguiente = auxiliar; // Enlaza el nuevo nodo al final
    }
}
void eliminarFinal(nodo *&p) // Eliminar el último elemento de la lista
{
    if (p == nullptr) return;
    nodo *aux = p;
    if (p->siguiente == nullptr) 
    {
        delete p;
        p = nullptr;
        return;
    }
    while ((*aux).siguiente->siguiente != nullptr) // Recorre hasta el penúltimo nodo
    {
        aux = (*aux).siguiente;
    }
    delete (*aux).siguiente;
    (*aux).siguiente = nullptr;
}
void insertar_enMedio(nodo *&p, int dato, int pos) 
{
    nodo *aux = new nodo;
    (*aux).dato = dato;

    if (pos <= 1 || p == nullptr) {
        (*aux).siguiente = p;
        p = aux;
        return;
    }

    nodo *temp = p;
    for (int i = 1; i < pos - 1 && (*temp).siguiente != nullptr; i++) {
        temp = (*temp).siguiente;
    }

    (*aux).siguiente = (*temp).siguiente;
    (*temp).siguiente = aux;
}
void mostrarLista(nodo *p) // Misma lógica que una pila
{
    while (p != nullptr)
    {
        cout << (*p).dato << '\t';
        p = (*p).siguiente;       
    }
}
int main(){
    nodo *p = nullptr; // Creación de la lista 
    insertarInicio(p, 5);
    insertarFinal(p, 10);
    insertar_enMedio(p, 7, 2);
    eliminarInicio(p);
    eliminarFinal(p);
    mostrarLista(p);
    return 0;
}