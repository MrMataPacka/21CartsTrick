#pragma once
#ifndef Truco21.h

const int MAX_SECUENCIAS = 3;
const int MAX_TARJETAS_GRUPO = 7;
const int MAX_GRUPOS = 3;
const int MAX_TARJETAS = MAX_TARJETAS_GRUPO * MAX_GRUPOS;
const char MIN_TARJETA_VALOR = 'A';
const char MAX_TARJETA_VALOR = MAX_TARJETAS + MIN_TARJETA_VALOR - 1;

namespace Truco21 {
	enum TrucoOrdenReagrupar {GRUPO1, GRUPO2, GRUPO3};

	struct Truco {
		char grupo1[MAX_TARJETAS_GRUPO], grupo2[MAX_TARJETAS_GRUPO], grupo3[MAX_TARJETAS_GRUPO];
		char deck[MAX_TARJETAS];
	};

	void iniciarDeck(Truco&t);

	void mostrarGrupos(const Truco&t);

	char revelarCarta(const Truco&t);

	void Repartir(Truco& t);

	void Reagrupar(TrucoOrdenReagrupar orden, Truco& t);
}



#endif // !Truco21.h

