//Tema 8
//Compliar en DevC++
//Gael Rechusky
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

//Funcion para poder usar colores
void SetColor(int ForgC) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

//Funcion para crear la matriz pidiendole a la persona que ingrese los valores
void Cmatriz(int matriz[4][3]) {
    SetColor(11);
    printf ("Ingresa 12 numeros:\n");
    SetColor(15);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf ("Posicion: (%d || %d): ", i, j);
            scanf ("%d", &matriz[i][j]);
        }
    }
}

//Funcion para graficar la matriz creada
void Dmatriz(int matriz[4][3]) {
    SetColor(14);
    printf ("Matriz:\n");
    SetColor(15);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf ("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

//Funcion para calcular las sumas pedidas
void calcularS(int matriz[4][3]) {
    int diagonalP = 0, diagonalS = 0;
    int PyUFila = 0, PyUColumna = 0;

    for (int i = 0; i < 3; i++) {
        diagonalP += matriz[i][i]; //Sumo posicion 0;0 || 1;1 || 2;2 (Empezando de la 0;0)
        diagonalS += matriz[i][2 - i]; //Sumo posicion 0;2 || 1;1 || 2;0 (Empezando de la 0;2)
    }
    for (int j = 0; j < 3; j++) {
        PyUFila += matriz[0][j] + matriz[3][j]; //Sumo posicion 0;0 || 0;1 || 0;2 || 3;0 || 3;1 || 3;2
    }
    for (int i = 0; i < 4; i++) {
        PyUColumna += matriz[i][0] + matriz[i][2]; //Sumo posicion 0;0 || 1;0 || 2;0 || 3;0 || 0;2 || 1;2 || 2;2 || 3;2
    }

    SetColor(10);
    printf ("Diagonal principal: %d\n", diagonalP);
    printf ("Diagonal secundaria: %d\n", diagonalS);
    printf ("Suma primera y ultima fila: %d\n", PyUFila);
    printf ("Suma primera y ultima columna: %d\n", PyUColumna);
    SetColor(15);
}

//Menu para seleccionar que hacer 
void matriz4x3() {
    int matriz[4][3];
    int opcion;
    while (1) {
        SetColor(13);
        printf ("1. Crear Matriz\n");
        printf ("2. Dibujar Matriz\n");
        printf ("3. Calcular Sumas\n");
        printf ("4. Ver otro ejercicio\n");
        SetColor(15);
        printf ("Seleccione que desea hacer: ");
        scanf ("%d", &opcion);
        
        switch (opcion) {
            case 1:
                Cmatriz(matriz);
                break;
            case 2:
                Dmatriz(matriz);
                break;
            case 3:
                calcularS(matriz);
                break;
            case 4:
                return;
            default:
                printf ("No existe esa opcion.\n");
        }
    }
}


void Cmatriz_20(int matriz[20][20]) {
    SetColor(11);
    printf ("Se genero una mtriz con numeros randoms\n");
	SetColor(15); // Volver al color blanco
	srand(time(0)); //Inicio funcion para generar numeros random
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            matriz[i][j] = rand() % 10; // Generar un número aleatorio entre 0 y 9
        }
    }
}

//Funcion para dibujar la matriz
void Dmatriz_20(int matriz[20][20]) {
    SetColor(14);
    printf ("Matriz:\n");
    SetColor(15);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

//Funcion para dibujar la primera columna 
void DibujarPC(int matriz [20][20]) {
	SetColor(10);
	printf ("Primer columna:\n");
	SetColor(15);
	for (int i = 0; i < 20; i++){
		printf ("%d\n", matriz[i][0]); //Recorro unicamente la primer posicion de cada fila
	}
}

//Menu para seleccionar que hacer
void matriz20() {
    int matriz[20][20];
    int opcion;
    while (1) {
        SetColor(13);
        printf("1. Crear Matriz\n");
        printf("2. Dibujar Matriz\n");
        printf("3. Imprimir Primera Columna\n");
        printf("4. Ver otro ejercicio\n");
        SetColor(15);
        printf("Que desea hacer: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                Cmatriz_20(matriz);
                break;
            case 2:
                Dmatriz_20(matriz);
                break;
            case 3:
                DibujarPC(matriz);
                break;
            case 4:
                return;
            default:
                printf("Opcion no existente\n");
        }
    }
}

//Funcion para ingresar las ventas de cada dia cambiando la semana al completarla  
void Cmatriz (int matriz[4][7]){
	SetColor(11);
	printf ("Ingresa las ventas de cada dia:\n");
	SetColor(15);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 7; j++){
			printf ("Venta del dia %d semana %d: ", j + 1, i + 1);
			scanf ("%d", &matriz[i][j]);
		}
	}
}
 
//Funcion para dibujar la matriz recorriendo primero el dia y luego la semana
void Dmatriz(int matriz[4][7]) {
    SetColor(14);
    printf("Ventas:\n");
    SetColor(15);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

//Funcion para calcular las ventas totales de cada semana (No me salio el promedio :( )
void CalcularVS(int matriz[4][7]) {
    int totalV[4] = {0, 0, 0, 0};
    int SemanaMV = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            totalV[i] += matriz[i][j];
        }
        if (totalV[i] > totalV[SemanaMV]) {
            SemanaMV = i;
        }
    }

    SetColor(10);
    for (int i = 0; i < 4; i++) {
        printf("Total de ventas de la semana %d: %d\n", i + 1, totalV[i]);
    }
    printf("La semana con mayor venta es la %d\n", SemanaMV + 1);
    SetColor(15);
}


//Menu del ejercicio para seleccionar que hacer
void matriz4x7() {
    int matriz[4][7];
    int opcion;
    while (1) {
        SetColor(13);
        printf("1. Crear Matriz\n");
        printf("2. Dibujar Matriz\n");
        printf("3. Calcular Ventas Semanales\n");
        printf("4. Ver otro ejercicio\n");
        SetColor(15);
        printf("Seleccione que desea hacer: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                Cmatriz(matriz);
                break;
            case 2:
                Dmatriz(matriz);
                break;
            case 3:
                CalcularVS(matriz);
                break;
            case 4:
                return;
            default:
                printf("Opcion no existente\n");
        }
    }
}

//Menu principal para elegir que ejercicio ver
void menu_principal() {
    int opcion;
    while (1) {
        SetColor(13);
        printf("\nMenu de ejercicios:\n");
        printf("1. Matriz 4x3\n");
        printf("2. Matriz 20x20\n");
        printf("3. Ventas\n");
        printf("4. Salir\n");
        SetColor(15);
        printf("Seleccione un ejercicio: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                matriz4x3();
                break;
            case 2:
                matriz20();
                break;
            case 3:
                matriz4x7();
                break;
            case 4:
                exit(0);
            default:
                printf("La opcion no existe\n");
        }
    }
}

int main() {
    menu_principal();
    return 0;
}
