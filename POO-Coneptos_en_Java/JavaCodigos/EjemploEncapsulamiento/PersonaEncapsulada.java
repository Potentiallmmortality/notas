package EjemploEncapsulamiento;

public class PersonaEncapsulada {
    private String nombre;
    private int edad;

    // la clase principal no puede pre inicializar valores por defecto, pero conoce un método público que si (constructor)

    public PersonaEncapsulada(String nombre, int edad) {
        this.nombre = nombre;
        this.edad = edad;
    }

    // Estos son setters

    public void setEdad(int edad) {

        // Lo bueno de dejarlo a un método público, es que puedes agregar métodos de autentificación

        if  (edad > 0) {
            this.edad = edad;
        } else  System.out.println("Edad invalida, intente de nuevo");
    }
    public void setNombre(String nombre) {
        if (nombre != null) {
            this.nombre = nombre;
        } else  System.out.println("Nombre invalido, intente de nuevo");
    }

    // Estos son getters

    public String getNombre() {
        return nombre;
    }
    public int getEdad() {
        return edad;
    }
}
