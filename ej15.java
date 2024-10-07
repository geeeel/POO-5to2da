package asd;
import javax.swing.JOptionPane;
public class ej15 {
	public static void main(String[] args) {
		int codigo;
		do{
			String texto=JOptionPane.showInputDialog("Introduce un numero mayor que 0");
			codigo=Integer.parseInt(texto);
		}while(codigo<=0);
 
		System.out.println(codigo);
	}
}
