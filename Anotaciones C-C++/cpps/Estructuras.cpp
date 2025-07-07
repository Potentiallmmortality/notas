
#include <iostream>
#include <string>
using namespace std;
struct Mascota
{
    int edad;
    string nombre;
    char tipo[20];
};

struct estudiante
{
    int id;                  
    int edad;    
    char nombre[20];    
    Mascota mascotita;   //anidar una estructura dentro de otra
};
int main(){
    int a;
    a = 0;
    estudiante a1 = {1, 10, "Juan", {5, "Firulais"}}; //manera de llenar la estructura estudiante, se queman valores 
    //se llena en orden de acuerdo a los aspectos definidos de la estructura
    
    estudiante a0; //Manera alternativa de llenar la estructura
    a0.id      = 0 ;
    a0.edad    = 21 ; 
    a0.nombre[0]  = 'Ana';    //arreglo[0] = 'caracteres_que_contenga'
    a0.mascotita.edad = 1;
    a0.mascotita.nombre = "Firulais";

    estudiante a2 = {2,20,"Pablo"}; //Pablo esta vez no tiene mascota :(

    estudiante a3 = {3,30,"Dross",{5, "Muzolini", "Pez"}}; //Dross?

    estudiante Lst[]= { //Puedo crear un arreglo con las estructuras que creamos
    a0,
    a1,
    {2,20,"Pablo"},
    a3,
    };

    cout << Lst[3].id      ;                                       
    cout << Lst[3].edad     ;                  
    cout << Lst[3].nombre[0];                     
    cout << Lst[3].mascotita.edad;             
    cout << Lst[3].mascotita.nombre;    

}