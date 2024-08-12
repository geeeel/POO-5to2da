/* Fuentes, Griggio, Rechusky, Rojas 5ª2 */

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Declaramos las matrices, los vectores y las variables.
char matriz[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
int movimiento[3][3], jugada[9], tateti[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int i, j, a = -1, b = 0, c, r = 0, q = 0;
int jug;


// Funcion para tener en cuenta las posiciones y sea mas facil para el usuario.
void tablero()
{
	printf("TABLERO: \n");
    printf("1   2   3\n\n4   5   6\n\n7   8   9\n\n\n");
	printf("JUEGO: \n");
}


// Para iniciar el juego
void iniciarJuego()
{
	tablero();
	
	// Iniciamos y mostramos el tablero vacio
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%c   ", matriz[i][j]);
            a += 1;
            movimiento[i][j] = a + 1; // Al ser "a" un contador, esta matriz tendra las posiciones "1, 2, 3, etc." segun lo mencionado.
        }
        printf("\n\n");
    }
    printf("\n");
}


// Determina el ganador del juego
void ganadorJuego()
{
	// El for es para repasar las filas y columnas sin necesidad de tener que hacer muchos "if"
	for (i = 0; i < 3; i++)
    {   
    	// Repasa todas las columnas
		if (tateti[i][0] == tateti[i][1] && tateti[i][0] == tateti[i][2] && tateti[i][0] != 0)
   		{
            q = tateti[i][0]; // Se le asignara el valor "1" o "2"
            break;
        }
        
        // Repasa las filas
        if (tateti[0][i] == tateti[1][i] && tateti[0][i] == tateti[2][i] && tateti[0][i] != 0)
        {
            q = tateti[0][i]; // Se le asignara el valor "1" o "2"
            break;
        }
    }
    
	// Repasa las diagonales    
    if (tateti[0][0] == tateti[1][1] && tateti[0][0] == tateti[2][2] && tateti[0][0] != 0)
    {
        q = tateti[0][0]; // Se le asignara el valor "1" o "2"
    }
    
    if (tateti[0][2] == tateti[1][1] && tateti[0][2] == tateti[2][0] && tateti[0][2] != 0)
    {
        q = tateti[0][2]; // Se le asignara el valor "1" o "2"
    }
}


// Para empezar a jugar el juego
void jugarJuego()
{
	// Ciclo para que se haga solo las 9 veces (3x3) necesarias para jugar
    do
    {
        r = 0;
        b += 1; // Contador para determinar el final de bucle (sino termina antes)
		
		// Ciclo para que cada jugador elija su movimiento
        do
        {
			printf("Movimiento jugador %d: ", (b % 2) == 0 ? 2 : 1); // Determina si el movimiento es del jugador 1 o 2
            scanf("%d", &jug);

			system("cls");
            
            // Ciclo para determinar en el vector si el numero ya fue usado
            for (c = 0; c < 9; c++)
            {
            	// Si ya esta presente el numero, entonces esa posicion esta ocupada
                if (jugada[c] == jug)
                {
                    r = 1; // Para repetir el ciclo
                    printf("Lugar ya ocupado.\n");
                    b -= 1; // El contador resa 1 para que despues lo vuelva a sumar y no ocupe una posicion
                    break;
                }
            }
			
			// Si "r" es 0 entonces se le asigna el valor al vector
            if (r == 0)
            {
                jugada[b - 1] = jug;
            }
        } 
		while (r == 1); // Si "r" es 1 vuelve a iterar

        system("cls");
        
		tablero();   
		
		// Tablero para mostrar los movimientos
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
            	// Cuando el numero ingresado por el jugador coincida con el asignado a la matriz se imprimira una "X" u "O"
				if (movimiento[i][j] == jug)
                {
                	// Si el contador va por un numero par, significa que es el jugador 2, entonces se imprime "O"
                    if ((b % 2) == 0)
                    {
                        printf("O   ");
                        matriz[i][j] = 'O'; // Impresion
                        tateti[i][j] = 2; // Recibira el valor 2
                    }
                    else // Si esta por uno impar, significa que es el jugador 1, se imprime "X"
                    {
                        printf("X   ");
                        matriz[i][j] = 'X'; // Impresion
                        tateti[i][j] = 1; // Recibira el valor 1
                    }
                }
                else
                {
                    printf("%c   ", matriz[i][j]); // Si no coincide nada, se imprime el "-"
                }
            }
            printf("\n\n");
        }
        
        ganadorJuego(); // Utilizamos la funcion ya explicada antes para determinar el ganador
        
        // Si el valor "q" es uno (esta en la funcion ganadorJuego), significa que el ganador es el jugador 1.
    	if (q == 1)
    	{
        	printf("TA TE TI - JUGADOR 1 GANADOR!\n");
        	break;
    	}
    	else if (q == 2) // Si es 2 entonces lo es el jugador 2
    	{
        	printf("TA TE TI - JUGADOR 2 GANADOR!\n");
        	break;
    	}
//    	 El 'break' finaliza el bucle para que no se tenga que jugar 9 veces si o si
    } 
	while (b < 9); // Si lleva "b" a 9 entonces es porque termino en empate
    
    // Aparte de que "q" se mantenga en cero
	if (b == 9 && q == 0)
    {
        printf("Empate!\n");
    }
}


// Principal
int main()
{
	// Para mostrar al principio
    printf("TA - TE - TE\n");
    printf("Empezamos a jugar:\n");
    printf("Cargando...");
	
	// Espera y limpia la pantalla
	sleep(3);
	system("cls");
	
	// Inicial las funciones explicadas anteriormente
	iniciarJuego();	
	jugarJuego();
	
	// Fin
	return 0;
}

