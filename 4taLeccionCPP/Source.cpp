#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Truco21.h"

using namespace std;
using namespace Truco21;



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

int main() {

	Truco truco;

	char inputUsuario;

	iniciarDeck(truco);

	Repartir(truco);

	cout << "Haremos 3 secuencias. Empecemos...\n";
	for (int j = 0; j < MAX_SECUENCIAS; j++) {
		
		cout << "Secuencia " << j+1 << ":\n\n";

		mostrarGrupos(truco);

		inputUsuario = pedirInputUsuario();

		if (inputUsuario == '1') {
			Reagrupar(GRUPO1,truco);
		}

		else if (inputUsuario == '2') {
			Reagrupar(GRUPO2, truco);
		}

		else if (inputUsuario == '3') {
			Reagrupar(GRUPO3, truco);
		}

		Repartir(truco);

	}

	cout << "Obviamente elegiste la " << revelarCarta(truco);

	
}