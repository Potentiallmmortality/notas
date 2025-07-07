#include <iostream>
#include <string>

using namespace std;
int contadorDesc(int n){
    if (n == 1) return n; //condición para parar
    
    cout << n << " ";
    return contadorDesc(n-1); //volver ejecutar el método con el número dado -1
}
int producto(int a, int b){
    if (a == 1) return b;
    return b + producto(a-1,b); 
}
char showStr(string &nombre, int i){ //presentar string en orden inverso
    if(i == 0) return nombre[i];
    cout << nombre[i] << " ";
    return showStr(nombre, i-1); //parametro de cambio
}
char showStr2(string &nombre, int i){ //presentar string en orden normal
    if(i== nombre.length()) return nombre[i];
    cout << nombre[i] << " ";  
    return showStr2(nombre, i+1); //parametro de cambio
}
int main(){
    cout << "contador descendente: " <<  contadorDesc(5) << endl;
    cout << "Producto de :" << 5 << " y " << 3 << " es: " << producto(5,3) << endl;
    
    string nombre = "sebastian";
    cout << "string: " << showStr(nombre,nombre.length());
    cout << "string2: " << showStr2(nombre,0);
    return 0;
}
