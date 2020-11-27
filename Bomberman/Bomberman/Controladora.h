#ifndef __CONTROLADORA_H__
#define __CONTROLADORA_H__
#include "Escenario.h"
#include "Jugador.h"

class CControladora {

public:

	CControladora() {

		oEscenario = new CEscenario();
		oJugador = new CJugador(50, 50);

	}



	~CControladora() {}

	void CambiarNivel() {

		oEscenario->generarMatriz();

	}

	void dibujar(Graphics^ g, Bitmap^ bmpBase, Bitmap^ bmpSolido, Bitmap^ bmpDestruible, Bitmap^ bmpJugador) {

		oEscenario->PintarBase(g, bmpBase);
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador->moverJugador(g, bmpJugador, oEscenario->getmatriz());
	}

	CJugador* getoJugador() {
		return oJugador;
	}

private:

	CEscenario* oEscenario;
	CJugador* oJugador;

};





#endif // !__CONTROLADORA_H__

