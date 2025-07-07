#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
// Utilizar ruta relativa del archivo respecto al .cpp o .c, usalmente debes salir de la carpeta output también
vector<string> getLines(const string & filename) {
    vector<string> Arr;
    string line;
    ifstream file(filename); //trata de leer la ruta proporcionada y devuelve un valor de "true" o "false"
    if (!file)  //si da "false" procede a mostrar un mensaje de error
    {
        cout << "error" << endl;
        return {};
    }
    while (getline(file,line)) //El bucle se justa con el número de líneas del archivo, getline guarda las lineas del archivo en "line"
    {
        Arr.push_back(line); //cada linea leida se guarda en un string y el string se va agregando al vector Arr [vector columna]
        cout << line << endl;
    }
    return Arr; //Nota, devuelve un vector que contiene cada linea del archivo como "string", no es un vector<vector<string>>
}
vector<vector<string>> extractLines(const string & filename){
    vector<vector<string>> Arr;
    string line;
    ifstream file(filename);
    if (!file) 
    {
        cout << "error" << endl;
        return {};
    }
    while (getline(file,line)) //Cada fila se guarda en line
    {
        vector<string> Vec;
        size_t posBusqueda = 0; 

        while (true) {  //repite indefinidamente
            size_t inicio = line.find('[', posBusqueda); // Busca el primer '[' desde la posición marcada
            if (inicio == string::npos) break; // Si no encuentra un '[', sale del bucle

            size_t fin = line.find(']', inicio); // Busca el primer ']' a partir de donde se encontró ']'
            if (fin == string::npos) break; // Si no encuentra sale del bucle

            string contenido = line.substr(inicio + 1, fin - inicio - 1); //De line extrae un string de entre las posiciones de []
            cout << contenido << '\t';
            Vec.push_back(contenido);  //guarda el string extraido en Vec
            posBusqueda = fin + 1; // La próxima ves que busque lo hace pasando de donde encontró ']'
        }
        cout << '\n';
        if (!Vec.empty()) { // Si Vec no está vacío, este se agrega a Arr
            Arr.push_back(Vec);
        }
    }
    return Arr; // Nota, devuelve vector de vectores de strings
}
void saveTable(const vector<vector<string>> & tabla, const string & filename) { //variable de la tablas, ruta del archivo
    ofstream archivo(filename); //abre el archivo en modo escritura o sino lo crea
    if (!archivo) { //si la acción no es exitosa, manda un error
        cout << "No se pudo abrir el archivo para escritura." << endl;
        return;
    }
    for (auto && fila : tabla) { //de la tabla extaer filas, de la filas strings,
        for (auto && dato : fila) {
            archivo << "[" << dato << "]\t"; //en el arhivo imprimir [ el string ] y depues hacer un espacio
            cout << "[" << dato << "]"; //que se imprima en la consola
        } 
        archivo << endl;
    } cout << '\n'; // \n en la consola depues de imprimir las filas de la tabla
    archivo.close();
}
vector<vector<string>> extractWords(const string & filename){
    vector<vector<string>> Arr;
    string line;
    ifstream file(filename);
    if (!file) 
    {
        cout << "error" << endl;
        return {};
    }
    while (getline(file,line)) //Cada fila se guarda en line
    {
        vector<string> Vec;
        size_t posBusqueda = 0; 

        while (true) {  //repite indefinidamente
            size_t inicio = line.find(' ', posBusqueda); // Busca el primer ' ' desde la posición marcada
            if (inicio == string::npos) break; // Si no encuentra un ' ', sale del bucle

            size_t fin = line.find(' ', inicio); // Busca el primer ' ' a partir de donde se encontró ']'
            if (fin == string::npos) break; // Si no encuentra sale del bucle

            string contenido = line.substr(inicio + 1, fin - inicio - 1); //De line extrae un string de entre las posiciones de []
            cout << contenido << '\t';
            Vec.push_back(contenido);  //guarda el string extraido en Vec
            posBusqueda = fin + 1; // La próxima ves que busque lo hace pasando de donde encontró ']'
        }
        cout << '\n';
        if (!Vec.empty()) { // Si Vec no está vacío, este se agrega a Arr
            Arr.push_back(Vec);
        }
    }
    return Arr; // Nota, devuelve vector de vectores de strings
}
// void escrbirAlgo(const string & filename) {
//     ofstream archivo(filename); 
//     if (!archivo) 
//     { 
//         cout << "No se pudo abrir el archivo para escritura." << endl;
//         return;
//     }
//         archivo << << endl;    
//     archivo.close();
    
// }