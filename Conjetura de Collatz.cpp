#include <stdio.h>
main(){
	int num;
	printf ("ingrese un numero: ");
	scanf ("%d", & num);
	do{
		if (num %2 == 0){
			num = num / 2;
			printf ("%d ", num);
		}
		else{
			num = (num * 3) + 1;
			printf ("%d ", num);
		}
	} while (num != 1); 
}
