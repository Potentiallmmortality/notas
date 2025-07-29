#include <iostream>
using namespace std;
enum {DIV_0 = 0,NEG};
int main(){
    int a,b;
    cout << "wenas" << endl
         << "Ingresa dos numeros para dividirlos: " << endl
         << "Numero 1: ";
    try
    {
        cin >> a;
       
        cout << "Numero 2: ";
        cin >> b;
        if (b == 0) 
            throw (int)DIV_0;
        else if (a < 0 && b > 0) 
            throw (int)NEG;
    }
    catch(int e)
    {
        switch (e)
        {
        case DIV_0:
            cout << "Error: No se puede dividir por cero" << endl;
            break;
        case NEG:
            cout << "Error: El numero 1 es negativo y el número 2 es positivo" << endl;
            break;
        }
    }
    return 0;
}

