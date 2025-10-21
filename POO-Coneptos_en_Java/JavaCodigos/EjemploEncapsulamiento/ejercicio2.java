package EjemploEncapsulamiento;

public class ejercicio2 {
    public static void main(String[] args) {

        PersonaEncapsulada persona1 = new PersonaEncapsulada("Sebas", 35);

        // para referirse al nombre o la edad de la persona hemos de utilizar los getters

        System.out.println("Hola, soy: " + persona1.getNombre() + " y tengo: " + persona1.getEdad() + " años de edad \n");

        // cambiemos los atributos de persona1 mediante los setters

        persona1.setEdad(25);
        persona1.setNombre("Alejandro");

        System.out.println("Hola, soy: " + persona1.getNombre() + " y tengo: " + persona1.getEdad() + " años de edad" );

        // cambiemos de nuevo (malintencionadamente)

        persona1.setEdad(-6);
        persona1.setNombre("");
    }
}
