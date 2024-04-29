#include <stdio.h>
main(){
	int menu;
	
	do {
		
		printf ("1: Ej1\n2: Ej2\n3: Ej3\n4: Ej4\n5: Ej5\n0: Salir\nQue ejercicio desea ver?: ");
		scanf ("%d", &menu);
		
		switch (menu){
			case 1:
				int he, hs, paga, ent;
				float ht;
				printf ("Ingrese la hora de entrada (En formato militar): ");
				scanf ("%d", &he);
				printf ("Ingrese la hora de salida (En formato militar)");
				scanf ("%d", &hs);
				
				ht = (hs - he) / 100;
				ht == ent;
				paga = paga + 500;
				paga = paga + (250 * (ht - 1)); 
				
				if (ht != ent){
					paga = paga + 250;
				}
				printf ("El total a pagar es %d\n", paga); 
				break;
				
			case 2:
				float n1, n2;
				int ent1, ent2, i, acum;
				printf ("Ingrese un numero entero y positivo: ");
				scanf ("%f", &n1);
				ent1 = n1;
				if (ent1 != n1){
					printf ("El numero ingresado no es valido ya que no es entero");
					break;
				}
				if (n1 <= 0){
					printf ("El numero ingresado no es valido ya que es negativo");
					break;
				}
				printf ("Ingrese un segundo numero positivo y entero: ");
				scanf ("%f", &n2);
				ent2 = n2;
				if (ent2 != n2){
					printf ("El numero ingresado no es valido ya que no es entero\n");
					break;
				}
				if (n2 <= 0){
					printf ("El numero ingresado no es valido ya que no es positivo\n");
					break;
				}
				for (i = 0; i < ent2; i++){
					acum += ent1; 
				}
				printf ("El resultado es %d\n", acum);
				break;
				
			case 5: 
				int per, total;
				printf ("Ingrese cuantas personas asisten: ");
				scanf ("%d", &per);
				if (per < 200){
					total = 6500 * per;
				}
				else if (per > 200 && per <= 300){
					total = 5500 * per;
				}
				else if (per > 300){
					total = 4500 * per;
				}
				printf ("El total a pagar es de %d pesos\n", total);
				break;
				
			case 4:
				int entr, cant, tot, desc;
				printf ("Ingrese el precio por entrada: ");
				scanf ("%d", &entr);
				printf ("Ingrese cuantas entradas desea comprar (Puede hasta 4 entradas): ");
				scanf ("%d", &cant);
				if (cant > 4){
					printf ("No puede comprar mas de 4 entradas\n");
					break;
				}
				if (cant == 2){
					tot = entr * 2;
					desc = tot * 0.1;
					tot = tot - desc;
					printf ("El total a pagar es de %d pesos\n", tot);
				}
				else if (cant == 3){
					tot = entr * 3;
					desc = tot * 0.15;
					tot = tot - desc;
					printf ("El total a pagar es %d pesos\n", tot);
				}
				else if (cant == 4){
					tot = entr * 4;
					desc = tot * 0.2;
					tot = tot - desc;
					printf ("El total a pagar es de %d pesos\n", tot);
				} 
				else if (cant == 1){
					tot = entr * 1;
					printf ("El total a pagar es de %d pesos\n", tot);
				}
				break;
			case 3: 
				printf ("No lo hice :)");
				break;
		}
	} while (menu != 0);
}
