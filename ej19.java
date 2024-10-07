package asd;
import javax.swing.JOptionPane;
public class ej19 {
	public static void main(String[]args) {
		int numero=0;
		do{
			String texto=JOptionPane.showInputDialog("Introduce un numero");
			numero=Integer.parseInt(texto);
		}while(numero<0); int contador=0; for (int i=numero;i>0;i/=10){
			contador++;
		}
 
		if (contador==1){
			System.out.println("El numero "+numero+ " tiene "+contador+" cifra");
		}else{
			System.out.println("El numero "+numero+ " tiene "+contador+" cifras");
		}
	}
}
