#ifndef __CONTROLADORA_H__
#define __CONTROLADORA_H__
#include "Escenario.h"
#include "Jugador.h"
#include "ArrBombas.h"
#include "ArrMejoras.h"
#include "ArrEnemigos.h"


class CControladora {

public:

	CControladora() {

		oEscenario = new CEscenario();
		oJugador = new CJugador(50, 50);
		oArrBombas = new CArrBombas();
		oArrMejoras = new CArrMejoras();
		oArrEnemigos = new CArrEnemigos();
		
		nivel = 3;

	}



	~CControladora() {}

	void CambiarNivel() {

		oEscenario->generarMatriz();

	}



	void agregarBomba() {
		oArrBombas->crear_una_bomba(oJugador->getX(), oJugador->getY());
	}

	void disminuir_Vidas_Por_Enemigo() {

		for (int i = 0; i < oArrEnemigos->getarregloEnemigos().size(); i++)
		{
			if (oJugador->retornarRectangulo().IntersectsWith(oArrEnemigos->getarregloEnemigos().at(i)->retornarRectangulo())){

				oJugador->disminuirVidas();
			
			}
				
		}

	}

	void disminuir_Vidas_Por_Bomba() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas->getarregloBombas().size(); i++)
		{

			PuntaIzquierda = oArrBombas->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas->getarregloBombas().at(i)->getY() -100;
			PuntaInferior = oArrBombas->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas->getarregloBombas().at(i)->getEstado() == Estado::explosion) {

				oJugador->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX);

			}

		}

	}

	void dibujar(Graphics^ g, Bitmap^ bmpBase, Bitmap^ bmpSolido, Bitmap^ bmpDestruible, Bitmap^ bmpJugador, Bitmap^bmpBomba, Bitmap^bmpExplosion, Bitmap^bmpMejoras, Bitmap^bmpEnemigo ) {

		oEscenario->PintarBase(g, bmpBase);
		oArrMejoras->dibujar(g, bmpMejoras, oEscenario->getmatriz());
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador->moverJugador(g, bmpJugador, oEscenario->getmatriz());
		oArrBombas->Dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador->getX(),oJugador->getY(), oEscenario->getmatriz() );
		oArrEnemigos->dibujar(g, bmpEnemigo, oEscenario->getmatriz());

		disminuir_Vidas_Por_Bomba();
		disminuir_Vidas_Por_Enemigo();
	}

	void crear_enemigos_y_mejoras() {

		oArrEnemigos->crearEnemigos();
		oArrMejoras->crearMejoras();

	}

	CJugador*getoJugador() {
		return oJugador;
	}

	CArrMejoras* getoArrMejoras() {
		return oArrMejoras;
	}

	CArrEnemigos* getoArrEnemigos() {
		return oArrEnemigos;
	}

	int getNivel() {
		return nivel;
	}

private:

	CEscenario*oEscenario;
	CJugador*oJugador;
	CArrBombas*oArrBombas;
	CArrMejoras* oArrMejoras;
	CArrEnemigos* oArrEnemigos;

	int nivel;
};





#endif // !__CONTROLADORA_H__

