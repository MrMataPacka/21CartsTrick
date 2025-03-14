/* 
	int numbers[5];

	int promedio, suma;

	for (int i = 0; i <= 4; i++) {
		cout << "N"<< i+1<<": "; cin >> numbers[i];
	}

	suma = 0;

	for (int i = 0; i <= 4; i++) {
		suma += numbers[i];
	}

	promedio = suma / 5;

	cout << "SUMA= " << suma << " PROMEDIO= " << promedio;
	


	srand(time(NULL));
	const int LARGE = 10;
	const int MAX_VALUE = 20;

	int numeros[LARGE];
	int num;
	bool yaExiste;

	for (int i = 0; i < LARGE; i++) {
		do {
			yaExiste = false;
			num = rand() % MAX_VALUE +1;
			for (int j = 0; j < i; j++) {
				if (numeros[j] == num) {
					yaExiste = true;
					break;
				}
			}
			if (!yaExiste) {
				numeros[i] = num;

			}

		} while (yaExiste);
		cout << numeros[i] << " ";
	}
	*/


/*
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MAX_SECUENCIAS = 3;
const int MAX_TARJETAS_GRUPO = 7;
const int MAX_GRUPOS = 3;
const int MAX_TARJETAS = MAX_TARJETAS_GRUPO * MAX_GRUPOS;
const char MIN_TARJETA_VALOR = 'A';
const char MAX_TARJETA_VALOR = MAX_TARJETAS + MIN_TARJETA_VALOR - 1;

void iniciarDeck(char deck[MAX_TARJETAS]) {
	srand(time(NULL));
	char valorAgregar;
	bool yaExiste;
	for (int i = 0; i < MAX_TARJETAS; i++) {
		do {
			yaExiste = false;
			valorAgregar = rand() % (MAX_TARJETA_VALOR - MIN_TARJETA_VALOR + 1) + MIN_TARJETA_VALOR;
			for (int j = 0; j < i; j++) {
				if (deck[j] == valorAgregar) {
					yaExiste = true;
					break;
				}
			}
			if (!yaExiste) {
				deck[i] = valorAgregar;

			}

		} while (yaExiste);
	}
}

void mostrarGrupos(char grupo1[MAX_TARJETAS_GRUPO], char grupo2[MAX_TARJETAS_GRUPO], char grupo3[MAX_TARJETAS_GRUPO]) {
	for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
		cout << "\t" << grupo1[i] << "\t" << grupo2[i] << "\t" << grupo3[i] << "\n";
	}
}

bool inputInvalido(char inputUsuario) {
	return (inputUsuario != '1' && inputUsuario != '2' && inputUsuario != '3');
}

char pedirInputUsuario() {
	char inputUsuario;
	do {
		cout << "En que grupo esta tu tarjeta [1,2,3]:";
		cin >> inputUsuario;

		if (inputInvalido(inputUsuario)) {
			cout << "VALOR DE ENTRADA INCORRECTO\n";
		}
	} while (inputInvalido(inputUsuario));

	return inputUsuario;
}

char revelarCarta(char deck[MAX_TARJETAS] ) {
	return deck[(MAX_TARJETAS / 2)];
}

void Repartir(char deck[MAX_TARJETAS], char grupo1[MAX_TARJETAS_GRUPO], char grupo2[MAX_TARJETAS_GRUPO], char grupo3[MAX_TARJETAS_GRUPO]) {
	for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
		grupo1[i] = deck[i * MAX_GRUPOS];
		grupo2[i] = deck[i * MAX_GRUPOS + 1];
		grupo3[i] = deck[i * MAX_GRUPOS + 2];
	}
}

void Reagrupar(char deck[MAX_TARJETAS], char arriba[MAX_TARJETAS_GRUPO], char medio[MAX_TARJETAS_GRUPO], char ultimo[MAX_TARJETAS_GRUPO]) {
	for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
		deck[i] = arriba[i];
	}
	for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
		deck[i + MAX_TARJETAS_GRUPO] = medio[i];
	}
	for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
		deck[i + MAX_TARJETAS_GRUPO * 2] = ultimo[i];
	}
}

int main() {


	char grupo1[MAX_TARJETAS_GRUPO], grupo2[MAX_TARJETAS_GRUPO], grupo3[MAX_TARJETAS_GRUPO];
	char deck[MAX_TARJETAS];


	char inputUsuario;

	iniciarDeck(deck);

	Repartir(deck, grupo1, grupo2, grupo3);

	cout << "Haremos 3 secuencias. Empecemos...\n";
	for (int j = 0; j < MAX_SECUENCIAS; j++) {

		cout << "Secuencia " << j+1 << ":\n\n";

		mostrarGrupos(grupo1, grupo2, grupo3);

		inputUsuario = pedirInputUsuario();

		if (inputUsuario == '1') {
			Reagrupar(deck, grupo2, grupo1, grupo3);
		}

		if (inputUsuario == '2') {
			Reagrupar(deck, grupo3, grupo2, grupo1);
		}

		if (inputUsuario == '3') {
			Reagrupar(deck, grupo2, grupo3, grupo1);
		}

		Repartir(deck, grupo1, grupo2, grupo3);

	}

	cout << "Obviamente elegiste la " << revelarCarta(deck);


}


*/