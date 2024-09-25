package tp2;

import java.util.Scanner;
public class ej4 {
	public static void main (String[] args) {
		try (Scanner sc = new Scanner (System.in)) {
			System.out.println ("Ingrese su nombre: ");
			String nombre=sc.nextLine();
			System.out.println ("Bienvenido/a " + nombre);
		}
	}
}
