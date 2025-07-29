#include <iostream>
#include <windows.h>

using namespace std;

struct nodo
{
    int num;
    nodo *izquierda, *derecha;
};
void insertar(nodo *&arbol, int num)
{
    if ( arbol == nullptr ) 
    {
        arbol = new nodo;
        (*arbol).num = num;
        (*arbol).izquierda = nullptr;
        (*arbol).derecha = nullptr;
    }
    else if ( num < (*arbol).num )
        insertar((*arbol).izquierda, num);
    else if ( num > (*arbol).num )
        insertar((*arbol).derecha, num);
}
// void insertar(nodo *&arbol, int num)
// {
//     while (arbol != nullptr)
//     {
//         if (num < arbol->num)
//             arbol = arbol->izquierda;
//         else if (num > arbol->num)
//             arbol = arbol->derecha;
//     }
//     arbol = new nodo;
//     arbol->num = num;
//     arbol->izquierda = nullptr;
//     arbol->derecha = nullptr;
// }
void preOrden(nodo *arbol)
{
    if ( arbol != nullptr )
    {
        cout << (*arbol).num << " ";
        preOrden((*arbol).izquierda);
        preOrden((*arbol).derecha);
    }
}
void enOrden(nodo *arbol)
{
    if (arbol != nullptr)
    {
        enOrden((*arbol).izquierda);
        cout << (*arbol).num << " ";
        enOrden((*arbol).derecha);
    }
}
void posOrden(nodo *arbol)
{
    if (arbol != nullptr)
    {
        posOrden((*arbol).izquierda);
        posOrden((*arbol).derecha);
        cout << (*arbol).num << " ";
    }
}
void verArbol(nodo *arbol, int nivel)
{
    if (arbol == nullptr)
        return;
    verArbol((*arbol).derecha, nivel + 1);
    for (int i = 0; i < nivel; i++)
        cout << "   ";
    cout << (*arbol).num << endl;
    verArbol((*arbol).izquierda, nivel + 1);
}
int main(){
    nodo *arbol = nullptr;
    insertar(arbol, 5);
    insertar(arbol, 3);
    insertar(arbol, 1);
    preOrden(arbol); cout << endl;
    enOrden(arbol); cout << endl;
    posOrden(arbol); cout << endl;

    verArbol(arbol, 3);
    return 0;
}
