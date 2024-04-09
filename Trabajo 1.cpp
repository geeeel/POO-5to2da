#include <stdio.h>
int main (){
int num,
	menu, 
	i,
	num1,
	num2,
	num3;
	
	
do{



printf (" 1: Positivo o negativo\n 2:Par o Impar\n 3:Multiplo 2/3\n 4:Cual es mayor\n 0:finalizar\n");
printf ("cual opcion usas? ");
scanf ("%d", &menu);
switch (menu){
	
case 1:
	printf ("Escribi un numero: ");
	scanf ("%d",&num);
	if (num >= 0){
		printf ("El numero es positivo\n");
	}
	else{
		printf ("El numero es negativo\n");
	}
	break;		
	
case 2:
	printf ("Escribi un numero: ");
	scanf ("%d",&num);
	if (num%2==0){
		printf ("el numero es par\n");
		}
		
	else {
		printf ("el numero es impar\n");
	}
	break;
case 3:
	printf ("Escribi un num: ");
	scanf ("%d", &num);
	if (num%2==0){
		printf ("El numero es multiplo de 2\n");
		if (num%3==0){
			printf ("El numero tambien es multiplo de 3\n");
		}
	}
	else if (num%3==0){
		printf ("El numero es multiplo de 3\n");
	}
	break;
case 4: 
		printf ("ponga los 3 numeros: ");
		scanf ("%d %d %d", &num1, &num2, &num3);
		if (num1 > num2 && num1 > num3){
			printf ("El primer numero es el mayor\n");
		}
		else if (num2 > num1 && num2 > num3){
			printf ("El segundo numero es el mayor\n");
		}
		else if (num3 > num1 && num3 > num1){
			printf ("El tercer numero es el mayor\n");
		}
		else if (num1 == num2 && num1 == num3){
			printf ("Los tres numeros son iguales\n");
		}
		else if (num1 > num2 && num1 == num3){
			printf ("El primer y tercer numero son los mayores\n");
		}
		else if (num2 > num1 && num2 == num3){
			printf ("El segundo y tercer numero son los mayores\n");
		}
		else if (num1 > num3 && num1 == num2){
			printf ("El primer y segundo numeros son los mayores\n");
		}
		break;
	}
	}while (menu != 0);
	

}

