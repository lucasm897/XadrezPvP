#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//vERIFICAR UM JOGO


char At[3][3]= {
	{' ',' ',' '},
	{' ',' ',' '},
	{' ',' ',' '}
};//,"A,"A","A","A","A","A"};
//{" "," "," "," "," "," "," "," "," ",};
int condi = 0;

int validador(int i) {
// 	printf("%d", i);
	int valor;
	i = i - 1;
	if(i>=0 && i<=2) {
		return i;
	} else {
		printf("Digite o valor correto, 1, 2 ou 3: ");
		scanf("%d", &i);
		valor = i;
		validador(valor);
	}
}



int jogador1() {
	int x,y;
	int jogador = 1;
	printf("Jogador 1 informe a linha e coluna da jogada.\n");
	printf("Linha: ");
	scanf(" %d", &x);
	x = validador(x);
	printf("Coluna:");
	scanf(" %d", &y);
	y = validador(y);
	if(At[x][y]=='X' || At[x][y]=='O') {
		printf("Nao foi possivel sobrepor as pecas.\n");
		jogador1();
	} else {
		At[x][y]='O';
	}
	return 0;
}

int jogador2() {
	int x,y;
	int jogador = 2;
	printf("Jogador 2 informe a linha e coluna da jogada.\n");
	printf("Linha: ");
	scanf(" %d", &x);
	x = validador(x);
	printf("Coluna:");
	scanf(" %d", &y);
	y = validador(y);
	if(At[x][y]=='X' || At[x][y]=='O') {
		printf("Nao foi possivel sobrepor as pecas.\n");
		jogador2();
	} else {
		At[x][y]='X';
	}

	return 0;
}



int mostrar() {
	printf("\n");
	int i,j;
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf(" %c ", At[i][j]);
			if(j!=2) {
				printf("|");
			}
		}
		printf("\n");
	}
	printf("\n");


}


int vitoria(int jogador) {
	condi=0;
	if(At[0][0]==At[0][1] && At[0][1]==At[0][2] && (At[0][0] == 'O' || At[0][0] == 'X')) {
		condi = 1;
		printf("Jogador %d Ganhou !!!", jogador);
		exit(0);
	}
	if(At[1][0]==At[1][1] && At[1][1]==At[1][2] && (At[1][0] == 'O' || At[1][0] == 'X')) {
		condi = 1;
		printf("Jogador %d Ganhou !!!", jogador);
		exit(0);
	}
	if(At[2][0]==At[2][1] && At[2][1]==At[2][2] && (At[2][0] == 'O' || At[2][0] == 'X')) {
		condi = 1;
		printf("Jogador %d Ganhou !!!", jogador);
		exit(0);
	}
	if(At[0][0]==At[1][0] && At[1][0]==At[2][0] && (At[0][0] == 'O' || At[0][0] == 'X')) {
		condi = 1;
		printf("Jogador %d Ganhou !!!", jogador);
		exit(0);
	}
	if(At[0][1]==At[1][1] && At[1][1]==At[2][1] && (At[0][1] == 'O' || At[0][1] == 'X')) {
		condi = 1;
		printf("Jogador %d Ganhou !!!", jogador);
		exit(0);
	}
	if(At[0][2]==At[1][2] && At[1][2]==At[2][2] && (At[0][2] == 'O' || At[0][2] == 'X')) {
		condi = 1;
		printf("Jogador %d Ganhou !!!", jogador);
		exit(0);
	}
	if(At[0][0]==At[1][1] && At[1][1]==At[2][2] && (At[0][0] == 'O' || At[0][0] == 'X')) {
		condi = 1;
		printf("Jogador %d Ganhou !!!", jogador);
		exit(0);
	}
	if(At[0][2]==At[1][1] && At[1][1]==At[2][0] && (At[0][2] == 'O' || At[0][2] == 'X')) {
		condi = 1;
		printf("Jogador %d Ganhou !!!", jogador);
		exit(0);
	}
	return 0;
}

int jogada(int numero, char simbolo){
    int x,y;
	int jogador = 2;
	printf("Olá, Jogador %d informe a linha e coluna da jogada.\n", numero);
	printf("Linha: ");
	scanf(" %d", &x);
	x = validador(x);
	printf("Coluna:");
	scanf(" %d", &y);
	y = validador(y);
	if(At[x][y]=='X' || At[x][y]=='O') {
		printf("Nao foi possivel sobrepor as pecas.\n");
		jogador2();
	} else {
		At[x][y]='X';
	}

	return 0;
}

int main() {

	char var;

	printf("Bem vindo ao Jogo do Velho!\n\n");
	mostrar();
	// printf("%C|%C|%C\n", At[0][0],At[0][1],At[0][2]);
	// printf("%C|%C|%C\n", At[1][0],At[1][1],At[1][2]);
	// printf("%C|%C|%C\n", At[2][0],At[2][1],At[2][2]);

	printf("Bom jogo aos dois!!!");

	do {
		system("clear");
		mostrar();
		jogada(1, 'X');
// 		jogador1();
		vitoria(1);
		system("clear");
		mostrar();
		jogador2();
		vitoria(2);
	} while(condi==0);

	return 0;
}