package Ejemplos;

// Esta es la clase persona

public class persona {

    // Dos atributos que debería tener una persona son:

    String nombre;       // Si no hay un modificador de acceso, se sobreentiende por defecto como public
    int edad;

    public void saludar(){
        System.out.printf("Hola! Soy %s y tengo %d años de edad", nombre, edad);
    }
}
