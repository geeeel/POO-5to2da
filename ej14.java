package asd;
import javax.swing.JOptionPane;
public class ej14 {
	public static void main(String[]args) {
		String textoA=JOptionPane.showInputDialog("Valor de a");
		int a=Integer.parseInt(textoA);
		String textoB=JOptionPane.showInputDialog("Valor de b");
		int b=Integer.parseInt(textoB);
		String textoC=JOptionPane.showInputDialog("Valor de c");
		int c=Integer.parseInt(textoC);
 
		double discriminante=Math.pow(b, 2)-(4*a*c);
 
		//Mensaje de traza
		System.out.println(">>"+discriminante);
 
		if (discriminante>0){
			double x1=((b*(-1))+Math.sqrt(discriminante))/(2*a);
			double x2=((b*(-1))-Math.sqrt(discriminante))/(2*a);
 
			System.out.println("El valor de x1 es "+x1+" y el valor de x2 es "+x2);
		}else{
			System.out.println("El discriminante es negativo");
		}
	}
}
