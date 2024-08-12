#include<vector>
#include<conio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<windows.h>

using namespace std;
enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
    BrightBlue = 9,
    BrightGreen = 10,
    BrightCyan = 11,
    BrightRed = 12,
    BrightMagenta = 13,
    BrightYellow = 14,
    BrightWhite = 15
};

void SetConsoleColor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>(color));
}
	
void dibujar_tablero(int matriz[10][10], int jugador[2]){
	 system("cls");

    for(int j = 0; j < 10; j++){
        for(int i = 0; i < 10; i++){
            if(i == jugador[0] && j == jugador[1]){
			SetConsoleColor(Red);
                cout << "7  ";
            SetConsoleColor(White);
            }
            else if(i == 9 && j == 9){
			SetConsoleColor(Yellow);
                cout << "8  ";
            SetConsoleColor(White);    
            }
            else{
            	SetConsoleColor(Green);
                cout << matriz[i][j] << "  ";
                SetConsoleColor(White);
        }
    }
        cout << endl;
    }
}

  int check(int matriz[10][10], int jugador[2], int& vidas){
    if(matriz[jugador[0]][jugador[1]] == 0 && vidas==1){
		jugador[1] = 0;
        jugador[0] = 0;
        dibujar_tablero(matriz, jugador);
        vidas--;
        return 3;
    }
    else if((matriz[jugador[0]][jugador[1]] == 0)){
    	 jugador[1] = 0;
        jugador[0] = 0;
        dibujar_tablero(matriz, jugador);
        vidas--;
        return 4;
	}
    else if(matriz[jugador[0]][jugador[1]] == 8){
        return 2;
    } 
    else {
    	return 1;
	}
}

juego(int matriz[10][10], int jugador[2]){
    int mov;
    int a = jugador[0];
	 int b = jugador[1];
	
    int vidas = 3;
    dibujar_tablero(matriz, jugador);

    while(vidas > 0){
		 cout << "Vidas restantes: " << vidas << endl;
        cout << "Ingrese 1 para moverse para la derecha, 2 para la izquierda, 3 para arriba y 4 para abajo: ";
        cin >> mov;
       

        switch(mov){
            case 1: a += 1; break;
            case 2: a -= 1; break;
            case 3: b -= 1; break;
            case 4: b += 1; break;
            default: 
                cout << "No se ingreso una direccion valida vuelva a intentarlo" << endl;
                continue;
        }

        if(a < 0 || a >= 10 || b < 0 || b >= 10){
            cout << "Movimiento fuera de los límites del tablero." << endl;
            continue;
        }

        jugador[0] = a;
        jugador[1] = b;
         
        if (check(matriz, jugador, vidas) == 4) {
        	a = 0;
			b=0;
		}
		else if(check(matriz, jugador, vidas) == 2){
			cout<<"ganaste pa"<<endl;
			break;
		}
		else if((check(matriz, jugador, vidas) == 3)){
			cout<<"the moriset"<<endl;
			break;
		}
		 dibujar_tablero(matriz, jugador);

    }

   
}

void inicio(){
    int matriz[10][10];
    int agujeros, dificultad;
    int jugador[2] = {0, 0};

    cout << "Elija la dificultad: 1 facil,2 normal , 3 dificil ";
    cin >> dificultad;

    switch(dificultad){
        case 1: agujeros = 10; break;
        case 2: agujeros = 20; break;
        case 3: agujeros = 30; break;
        default: 
            cout << "La dificultad no existe" << endl;
            return;
    }

    srand (time(NULL));

    for(int j = 0; j < 10; j++){
        for(int i = 0; i < 10; i++){
            matriz[i][j] = 1;
        }
    }

    for(int i = 0; i < agujeros; i++){
        int a = rand() % 10;
        int b = rand() % 10;
        matriz[a][b] = 0;
    }
    matriz[9][9] = 8;
    juego(matriz, jugador);
}

int main(){
    inicio();
    return 0;
}


