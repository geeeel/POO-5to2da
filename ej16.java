package asd;
import javax.swing.JOptionPane;
public class ej16 {
	public static void main (String[] args) {
		String contrase�a="eureka";
		  
        final int INTENTOS = 3;
        
        boolean acierto=false;
 
        String password;
        for (int i=0;i<3 && !acierto;i++){
            password=JOptionPane.showInputDialog("Introduce una contrase�a");
 
            if (password.equals(contrase�a)){
                System.out.println("Enhorabuena, acertaste");
                acierto=true;
            }
        }
	}
}
