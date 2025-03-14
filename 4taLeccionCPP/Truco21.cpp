#include "Truco21.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

namespace Truco21 {

	void iniciarDeck(Truco& t) {
		srand(time(NULL));
		char valorAgregar;
		bool yaExiste;
		for (int i = 0; i < MAX_TARJETAS; i++) {
			do {
				yaExiste = false;
				valorAgregar = rand() % (MAX_TARJETA_VALOR - MIN_TARJETA_VALOR + 1) + MIN_TARJETA_VALOR;
				for (int j = 0; j < i; j++) {
					if (t.deck[j] == valorAgregar) {
						yaExiste = true;
						break;
					}
				}
				if (!yaExiste) {
					t.deck[i] = valorAgregar;

				}

			} while (yaExiste);
		}
	}

	void mostrarGrupos(const Truco& t) {
		for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
			cout << "\t" << t.grupo1[i] << "\t" << t.grupo2[i] << "\t" << t.grupo3[i] << "\n";
		}
	}

	char revelarCarta(const Truco& t) {
		return t.deck[(MAX_TARJETAS / 2)];
	}

	void Repartir(Truco& t) {
		for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
			t.grupo1[i] = t.deck[i * MAX_GRUPOS];
			t.grupo2[i] = t.deck[i * MAX_GRUPOS + 1];
			t.grupo3[i] = t.deck[i * MAX_GRUPOS + 2];
		}
	}

	void Reagrupar(TrucoOrdenReagrupar orden, Truco& t) {
		switch (orden) {
			case GRUPO1:
				for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
					t.deck[i] = t.grupo3[i];
				}
				for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
					t.deck[i + MAX_TARJETAS_GRUPO] = t.grupo1[i];
				}
				for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
					t.deck[i + MAX_TARJETAS_GRUPO * 2] = t.grupo2[i];
				}
				break;
			case GRUPO2:
				for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
					t.deck[i] = t.grupo3[i];
				}
				for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
					t.deck[i + MAX_TARJETAS_GRUPO] = t.grupo2[i];
				}
				for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
					t.deck[i + MAX_TARJETAS_GRUPO * 2] = t.grupo1[i];
				}
				break;
			case GRUPO3:
				for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
					t.deck[i] = t.grupo2[i];
				}
				for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
					t.deck[i + MAX_TARJETAS_GRUPO] = t.grupo3[i];
				}
				for (int i = 0; i < MAX_TARJETAS_GRUPO; i++) {
					t.deck[i + MAX_TARJETAS_GRUPO * 2] = t.grupo1[i];
				}
				break;
		}
	}
}
