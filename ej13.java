package asd;
import javax.swing.JOptionPane;
public class ej13 {
	public static void main(String[] args) {
		String texto=JOptionPane.showInputDialog("Introduce cantidad de ventas");
		
		int numventas=Integer.parseInt(texto);
		int sumaventas = 0;
		
		for (int i=0; i<numventas; i++) {
			texto=JOptionPane.showInputDialog("Precio de la venta"+ (i+1));
			int venta=Integer.parseInt(texto);
			
			
			sumaventas=sumaventas + venta;
		}
		System.out.println(sumaventas);
	}
}
