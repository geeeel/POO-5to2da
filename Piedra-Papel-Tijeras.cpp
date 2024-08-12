#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
	//declaro variables
   int i,j, n, usu, puntos; 
   int cont_ia, cont_jug,cont;
   int cont_vic = 0, cont_per = 0;
   time_t t;
   
   //para que el numero random cambie en el programa
   srand((unsigned) time(&t));

  //bucle para las 5 rondas
for(j=0;j<5;j++){
	//blucle para cada ronda
   for(i=0;i<3;i++){
   	printf("ingrese cual elige: 1- piedra,  2- papel,  3- tijeras ");
   	scanf("%d", & usu);
   	// consigo el rango para el numero random
   	int ia = rand() % 3 +1;
   	//diferentes opciones de partida
   	if(ia== 1){
   	printf("La maquina eligio piedra\n");}
   	else if(ia==2){
   		printf("la maquina eligio papel\n");
	   }
    	else{
   		printf("la maquina eligio tijeras\n");
	   }  	
	if(usu== ia){
		printf("Empate\n");
	}
	else if(usu == 1 && ia == 2){
		printf("Punto para la Maquina\n");
		cont_ia += 1;
	}
		else if(usu == 1 && ia ==3){
		printf("Punto para vos\n");
		cont_jug +=1;
		}

	else if(usu == 2 && ia == 1){
		printf("Punto para vos\n");
		cont_ia += 1;
	}
		else if(usu == 2 && ia ==3){
		printf("Punto para la Maquina\n");
		cont_jug +=1;
		}
	else if(usu == 3 && ia == 1){
		printf("Punto para la Maquina\n");
		cont_ia += 1;
	}
		else if(usu == 3 && ia ==2){
		printf("Punto para vos\n");
		cont_jug +=1;
		}
   }
   //resultado de la ronda
   if(cont_jug > cont_ia){
	printf("El jugador gano la ronda\n");
	cont_vic += 1;
	}
	else if(cont_jug == cont_ia){
	printf("Empate nadie gano la ronda\n");
	cont_vic +=1;
	cont_per +=1;
	}
	else{
	printf("La maquina gano la ronda\n");
	cont_per += 1;
	}
	//reinicio variables para seguir jugando
	cont_jug = 0;
	cont_ia = 0;
   
}
// resultado de la partida
if(cont_vic > cont_per){
	printf("Ganaste la partida\n");
}
else if(cont_per > cont_vic){
	printf("Perdiste la partida");
}
else{
	printf("Empataste");
}
}


