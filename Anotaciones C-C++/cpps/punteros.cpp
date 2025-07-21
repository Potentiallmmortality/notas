#include <iostream>

using namespace std;
int funcion(int valor) //parametro por "valor"
{
    valor += 5; // en valor: |__valor__| <--- valor + 5
    return valor;
}
void funcion_ref(int *valor) //parametro por "referencia"
{
    *valor += 5; //en num: |__valor__| <--- valor + 5

    // En este caso, valor le asigno la "Etiqueta" de num", si modifico a valor, modifico a num
    // sin necesidad de crear una copia
}
int main(){
    int num = 10; // num: |__10__|
    cout << "Valor de num despues de la funcion por valor: " << num << endl;
    funcion(num); // num se pasa por valor, se crea una copia de num en "valor"
    // Notese que num no se modifica, solo retorna el valor modificado
    cout << "Valor de num despues de la funcion por valor: " << num << endl;
    num = funcion(num);
    cout << "Valor de num despues de asignarle el resultado de la funcion por valor: " << num << endl;

    num = 10;
    cout << "Valor de num antes de la funcion por referencia: " << num << endl;
    funcion_ref(&num); // num se pasa por referencia, se pasa la direccion de memoria de num
    // Notese que num se modifica directamente
    cout << "Valor de num despues de la funcion por referencia: " << num << endl;
    return 0;
}

// si a=b ambas comparten el mismo contenido
// si *a=&b ambas comparten la misma direccion de memoria
// Para que una valor se dobleimplique con el otro: o 