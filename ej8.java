package e;

import javax.swing.JOptionPane;

public class ej8 {
	public static void main (String []args) {
		String texto=JOptionPane.showInputDialog("Introduce un caracter de la tabla ASCII");
		char caracter=texto.charAt(0);
		 
        int codigo=(int)caracter;
  
        System.out.println(codigo);
	}
}
