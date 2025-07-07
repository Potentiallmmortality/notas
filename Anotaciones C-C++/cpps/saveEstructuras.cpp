//Para la casa: modificar codigo para guardar una estructura en un csv directamete
//encontrar código para extraer estrcuturas de un csv
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "lib/readUtil.h"

using namespace std;

struct Mascota
{
    int edad;
    string nombre;
    string tipo;
};
struct estudiante
{
    int id;                  
    int edad;    
    string nombre;    
    Mascota mascotita;
};
estudiante a1 = {1,20,"Pepe",{1,"Bartolito","pez"}}, // [1] [Pepe]  [1] [Bartolito] [pez]
           a2 = {2,15,"Luis"},                          // [2] [Luis]  [ ] [ ] [ ] [ ] [ ]
           a3 = {3,18,"Juan",{1,"Pirulo","perro"}};
vector<estudiante> Lista = {a1,a2,a3};
void saveStruc(const string & filename) {
    ofstream archivo(filename); 
    if (!archivo) 
    { 
        cout << "No se pudo abrir el archivo para escritura." << endl;
        return;
    }
    for (auto && A: Lista)
    {
        archivo << "[" << A.id << "] " << "[" << A.edad << "] " << "[" << A.nombre << "] " << "[" << A.mascotita.edad << "] " << "[" << A.mascotita.nombre << "] " << "[" << A.mascotita.tipo << "] " << endl;
        cout << "[" << A.id << "] " << "[" << A.edad << "] " << "[" << A.nombre << "] " << "[" << A.mascotita.edad << "] " << "[" << A.mascotita.nombre << "] " << "[" << A.mascotita.tipo << "] " << endl;    
    }
    archivo.close();
}
vector<estudiante> loadStruc(){
    vector<vector<string>> datos;
    estudiante b1;
    vector<estudiante> Lista_2;
    datos = extractLines("../estructuras.csv");
    for (auto && fila: datos)
    {
        int i=0;
        for (auto && str : fila)
        {
        switch (i)
        {
        case 0:
            b1.id = stoi(str);
            break;
        case 1:
            b1.edad = stoi(str);
            break;
        case 2:
            b1.nombre = str;
            break;
        case 3:
            b1.mascotita.edad = stoi(str);
            break;
        case 4:
            b1.mascotita.nombre = str;
            break;
        case 5:
            b1.mascotita.tipo = str;
            break;
        default:
            cout << "error de algun tipo XD" << endl; 
            break;
        }
            i++;
        }
        Lista_2.push_back(b1); //push_back() significa: ve guardando lo que esta en parentesis en el vector
    }
    return Lista_2;
}
void leer(){
    vector<estudiante> Lista_2 = loadStruc();
    for (auto && estr : Lista_2 )
    {
        cout << estr.id << " " << estr.edad << " " << estr.nombre << " " << estr.mascotita.edad << " " << estr.mascotita.nombre << " " << estr.mascotita.tipo << " " << endl;
    }
}
int main(){
    saveStruc("../estructuras.csv");

    return 0;
}