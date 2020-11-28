#ifndef __CONTROLADORA_H__
#define __CONTROLADORA_H__
#include "Escenario.h"
#include "Jugador.h"
#include "ArrBombas.h"

class CControladora {

public:

	CControladora() {

		oEscenario = new CEscenario();
		oJugador = new CJugador(50, 50);
		oArrBombas = new CArrBombas();

	}



	~CControladora() {}

	void CambiarNivel() {

		oEscenario->generarMatriz();

	}

	void agregarBomba() {
		oArrBombas->crear_una_bomba(oJugador->getX(), oJugador->getY());
	}

	void dibujar(Graphics^ g, Bitmap^ bmpBase, Bitmap^ bmpSolido, Bitmap^ bmpDestruible, Bitmap^ bmpJugador, Bitmap^bmpBomba, Bitmap^bmpExplosion ) {

		oEscenario->PintarBase(g, bmpBase);
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador->moverJugador(g, bmpJugador, oEscenario->getmatriz());
		oArrBombas->Dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador->getX(),oJugador->getY(), oEscenario->getmatriz() );
	}

	CJugador* getoJugador() {
		return oJugador;
	}

private:

	CEscenario*oEscenario;
	CJugador*oJugador;
	CArrBombas*oArrBombas;
};





#endif // !__CONTROLADORA_H__

