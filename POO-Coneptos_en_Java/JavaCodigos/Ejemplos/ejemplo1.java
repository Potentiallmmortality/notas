package Ejemplos;


public class ejemplo1 {
    public static void main(String[] args) {

        // La forma de crear la instancia puede recordarte un poco al funcionamiento de los punteros en c o c++
        // déjame modificar el concepto un poco: *persona Ana = new persona();
        // Lo cierto es que Java maneja el tema de los punteros y la memoria de manera semiautomática

        persona Ana = new persona();

        // Dar Atributos

        Ana.nombre = "Ana";
        Ana.edad = 25;

        // Recuerda que puedes hacer esto directamente porque dichas propiedades son públicas

        Ana.saludar();
    }
}
