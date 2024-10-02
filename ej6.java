package e;
import java.util.Scanner;
public class ej6 {
	public static void main (String [] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Introduzca un numero: ");
		int numero = sc.nextInt();
		
		if (numero %2 == 0) {
			System.out.println("El numero ingreseado es divisible por 2");
		}
		else {
			System.out.println("El numero no es divisible por 2");
		}
	}

}
