#ifndef __CONTROLADORA_H__
#define __CONTROLADORA_H__
#include "Escenario.h"
#include "Jugador.h"
#include "ArrBombas.h"
#include "ArrMejoras.h"


class CControladora {

public:

	CControladora() {

		oEscenario = new CEscenario();
		oJugador = new CJugador(50, 50);
		oArrBombas = new CArrBombas();
		oArrMejoras = new CArrMejoras();
		nivel = 5;

	}



	~CControladora() {}

	void CambiarNivel() {

		oEscenario->generarMatriz();

	}



	void agregarBomba() {
		oArrBombas->crear_una_bomba(oJugador->getX(), oJugador->getY());
	}

	void dibujar(Graphics^ g, Bitmap^ bmpBase, Bitmap^ bmpSolido, Bitmap^ bmpDestruible, Bitmap^ bmpJugador, Bitmap^bmpBomba, Bitmap^bmpExplosion, Bitmap^bmpMejoras ) {

		oEscenario->PintarBase(g, bmpBase);
		oArrMejoras->dibujar(g, bmpMejoras, oEscenario->getmatriz());
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador->moverJugador(g, bmpJugador, oEscenario->getmatriz());
		oArrBombas->Dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador->getX(),oJugador->getY(), oEscenario->getmatriz() );

	}

	void crear_enemigos_y_mejoras() {

		oArrMejoras->crearMejoras();

	}

	CJugador*getoJugador() {
		return oJugador;
	}

	CArrMejoras* getoArrMejoras() {
		return oArrMejoras;
	}

	int getNivel() {
		return nivel;
	}

private:

	CEscenario*oEscenario;
	CJugador*oJugador;
	CArrBombas*oArrBombas;
	CArrMejoras* oArrMejoras;

	int nivel;
};





#endif // !__CONTROLADORA_H__

