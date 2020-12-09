#ifndef __CONTROLADORA2_H__
#define __CONTROLADORA2_H__
#include "Escenario.h"
#include "Jugador.h"
#include "Jugador2.h"
#include "Jugador3.h"
#include "Jugador4.h"
#include "ArrBombas.h"
#include "ArrBombas2.h"
#include "ArrBombas3.h"
#include "ArrBombas4.h"
#include "ArrMejoras.h"


/// <summary>
/// Clase que controla todas las funciones del juego
/// </summary>

class CControladora2 {

public:

	CControladora2() {

		/// <summary>
		/// Se crean los objetos de todas clases incluidas
		/// </summary>

		oEscenario = new CEscenario();
		oJugador = new CJugador(50, 50);
		oJugador2 = new CJugador2(750, 20);
		oJugador3 = new CJugador3(750, 600);
		oJugador4 = new CJugador4(50, 600);


		oArrBombas = new CArrBombas();
		oArrBombas2 = new CArrBombas2();
		oArrBombas3 = new CArrBombas3();
		oArrBombas4 = new CArrBombas4();

		oArrMejoras = new CArrMejoras();


		nivel = 3; //Se inicializa el nivel
		habilidad = false; // La hailidad se inicializa en false al no iniciar con power up

	}



	~CControladora2() {}

	/// <summary>
	/// Método que genera matriz al cambiar de nivel
	/// </summary>

	void CambiarNivel() {

		oEscenario->generarMatriz();



	}


	/// <summary>
	/// Método que agrega una bomba1 
	/// </summary>
	void agregarBomba() {
		oArrBombas->crear_una_bomba(oJugador->getX(), oJugador->getY()); //Agarra una bomba del array y la coloca en las posiciones de x y y del jugador

	}

	/// <summary>
/// Método que agrega una bomba2 
/// </summary>
	void agregarBomba2() {

		if(oJugador->getX()==oJugador2->getX() || oJugador->getX() == oJugador2->getX())
			oArrBombas2->crear_una_bomba2(oJugador2->getX(), oJugador2->getY()); //Agarra una bomba del array y la coloca en las posiciones de x y y del jugador

	}

	void agregarBomba3() {
		oArrBombas3->crear_una_bomba2(oJugador3->getX(), oJugador3->getY()); //Agarra una bomba del array y la coloca en las posiciones de x y y del jugador

	}


	void agregarBomba4() {
		oArrBombas4->crear_una_bomba2(oJugador4->getX(), oJugador4->getY()); //Agarra una bomba del array y la coloca en las posiciones de x y y del jugador

	}

	/// <summary>
	/// Método para disminuir vidas por el enemigo
	/// </summary>


	/// <summary>
	/// Método para disminuir vida del jugador por bomba
	/// </summary>
	void disminuir_Vidas_Por_Bomba() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas->getarregloBombas().at(i)->getEstado() == Estado::explosion) { //Valida si la bomba está en explosion

				oJugador2->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador2->setDX(0);
				oJugador2->setDY(0);
			}




		}


	}


	/// <summary>
	/// Método para disminuir vida del jugador por bomba
	/// </summary>
	void disminuir_Vidas_Por_Bomba2() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas2->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas2->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas2->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas2->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas2->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas2->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas2->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas2->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas2->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas2->getarregloBombas().at(i)->getEstado() == Estado2::explosion2) { //Valida si la bomba está en explosion

				oJugador2->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador2->setDX(0);
				oJugador2->setDY(0);
			}

		}

	}

	void disminuir_Vidas_Por_Bomba3() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas3->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas3->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas3->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas3->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas3->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas3->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas3->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas3->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas3->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas3->getarregloBombas().at(i)->getEstado() == Estado3::explosion3) { //Valida si la bomba está en explosion

				oJugador2->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador2->setDX(0);
				oJugador2->setDY(0);
			}

		}

	}

	void disminuir_Vidas_Por_Bomba4() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas4->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas4->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas4->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas4->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas4->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas4->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas4->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas4->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas4->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas4->getarregloBombas().at(i)->getEstado() == Estado4::explosion4) { //Valida si la bomba está en explosion

				oJugador2->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador2->setDX(0);
				oJugador2->setDY(0);
			}

		}

	}


	void disminuir_Vidas_Por_Bomba5() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas->getarregloBombas().at(i)->getEstado() == Estado::explosion) { //Valida si la bomba está en explosion

				oJugador4->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador4->setDX(0);
				oJugador4->setDY(0);
			}

		}

	}

	void disminuir_Vidas_Por_Bomba6() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas2->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas2->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas2->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas2->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas2->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas2->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas2->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas2->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas2->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas2->getarregloBombas().at(i)->getEstado() == Estado2::explosion2) { //Valida si la bomba está en explosion

				oJugador4->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador4->setDX(0);
				oJugador4->setDY(0);
			}

		}

	}


	void disminuir_Vidas_Por_Bomba7() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas3->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas3->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas3->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas3->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas3->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas3->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas3->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas3->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas3->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas3->getarregloBombas().at(i)->getEstado() == Estado3::explosion3) { //Valida si la bomba está en explosion

				oJugador4->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador4->setDX(0);
				oJugador4->setDY(0);
			}

		}

	}


	void disminuir_Vidas_Por_Bomba8() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas4->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas4->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas4->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas4->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas4->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas4->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas4->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas4->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas4->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas4->getarregloBombas().at(i)->getEstado() == Estado4::explosion4) { //Valida si la bomba está en explosion

				oJugador4->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador4->setDX(0);
				oJugador4->setDY(0);
			}

		}

	}

	void disminuir_Vidas_Por_Bomba9() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas->getarregloBombas().at(i)->getEstado() == Estado::explosion) { //Valida si la bomba está en explosion

				oJugador->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador->setDX(0);
				oJugador->setDY(0);
			}

		}

	}

	void disminuir_Vidas_Por_Bomba10() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas2->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas2->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas2->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas2->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas2->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas2->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas2->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas2->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas2->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas2->getarregloBombas().at(i)->getEstado() == Estado2::explosion2) { //Valida si la bomba está en explosion

				oJugador->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador->setDX(0);
				oJugador->setDY(0);
			}

		}

	}

	void disminuir_Vidas_Por_Bomba11() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas3->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas3->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas3->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas3->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas3->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas3->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas3->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas3->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas3->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas3->getarregloBombas().at(i)->getEstado() == Estado3::explosion3) { //Valida si la bomba está en explosion

				oJugador->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador->setDX(0);
				oJugador->setDY(0);
			}

		}

	}


	void disminuir_Vidas_Por_Bomba12() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas4->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas4->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas4->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas4->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas4->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas4->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas4->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas4->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas4->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas4->getarregloBombas().at(i)->getEstado() == Estado4::explosion4) { //Valida si la bomba está en explosion

				oJugador->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador->setDX(0);
				oJugador->setDY(0);
			}

		}

	}

	void disminuir_Vidas_Por_Bomba13() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas->getarregloBombas().at(i)->getEstado() == Estado::explosion) { //Valida si la bomba está en explosion

				oJugador3->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador3->setDX(0);
				oJugador3->setDY(0);
			}

		}

	}


	void disminuir_Vidas_Por_Bomba14() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas2->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas2->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas2->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas2->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas2->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas2->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas2->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas2->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas2->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas2->getarregloBombas().at(i)->getEstado() == Estado2::explosion2) { //Valida si la bomba está en explosion

				oJugador3->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador3->setDX(0);
				oJugador3->setDY(0);
			}

		}

	}


	void disminuir_Vidas_Por_Bomba15() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas3->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas3->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas3->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas3->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas3->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas3->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas3->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas3->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas3->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas3->getarregloBombas().at(i)->getEstado() == Estado3::explosion3) { //Valida si la bomba está en explosion

				oJugador3->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador3->setDX(0);
				oJugador3->setDY(0);
			}

		}

	}


	void disminuir_Vidas_Por_Bomba16() {

		int PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

		for (int i = 0; i < oArrBombas4->getarregloBombas().size(); i++) // Se recorre el array de bombas
		{

			/// <summary>
			/// Se determinan los limites de daño de la explosion con las posiciones x y y de esta
			/// </summary>
			PuntaIzquierda = oArrBombas4->getarregloBombas().at(i)->getX() - 100;
			puntaDerecha = oArrBombas4->getarregloBombas().at(i)->getX() + 150;
			PuntaSuperior = oArrBombas4->getarregloBombas().at(i)->getY() - 100;
			PuntaInferior = oArrBombas4->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas4->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas4->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas4->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas4->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas4->getarregloBombas().at(i)->getEstado() == Estado4::explosion4) { //Valida si la bomba está en explosion

				oJugador3->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas
				oJugador3->setDX(0);
				oJugador3->setDY(0);
			}

		}



	}

	/// <summary>
	/// Método para adquirir power-ups
	/// </summary>

	void agarrarMejoras() {

		for (int i = 0; i < oArrMejoras->getvector_mejoras().size(); i++) //Se recorre el array de mejoras
		{
			if (oJugador->retornarRectangulo().IntersectsWith(oArrMejoras->getvector_mejoras().at(i)->devolverR())) { // Si la posicion del jugador interseca con la posicion de mejoras empieza a funcionar

				switch (oArrMejoras->getvector_mejoras().at(i)->getTipo_de_mejora()) //Se realiza un switch para validar todas las mejoras que hay
				{
				case 1: //Agregar una bomba
					oArrBombas->setBombas(oArrBombas->getBombas() + 1); //Al agarrar esta se aumenta la cantidad de bombas que se pueden tirar 
					break;
				case 2://Mover una bomba
					habilidad = true; //Permite mover una bomba ya colocada
					break;
				case 3: // Calavera
					oJugador->setVidas(oJugador->getVidas() - 1); //Al agarrarla se disminuye la vida
					break;
				case 4: //Patines
					oJugador->setAcelerar(oJugador->getAcelerar() + 3); // Se activa el método acelerar y el jugador aumenta la velocidad x3
					break;
				case 5: // Vidas
					oJugador->setVidas(oJugador->getVidas() + 1); // Se aumenta en  uno la vida
					break;
				default:
					break;
				}
				oArrMejoras->eliminarenpos(i); //Se elimina el powerup en la posicion que se encuentre en el array


			}
		}

	}

	void validaciones() {

		if (oJugador->getX() == oJugador3->getX()) {
			oJugador3->setDY(0);
			oJugador3->setDX(-0.15);
		}

	}


	/// <summary>
	/// Método para mostrar los bmps craedos en las respectivas clases
	/// Se dibujan los distintos objetos anteriormente creados
	/// </summary>
	/// <param name="g"></param>
	/// <param name="bmpBase"></param>
	/// <param name="bmpSolido"></param>
	/// <param name="bmpDestruible"></param>
	/// <param name="bmpJugador"></param>
	/// <param name="bmpBomba"></param>
	/// <param name="bmpExplosion"></param>
	/// <param name="bmpMejoras"></param>
	/// <param name="bmpEnemigo"></param>

	void dibujar(Graphics^ g, Bitmap^ bmpBase, Bitmap^ bmpSolido, Bitmap^ bmpDestruible, Bitmap^ bmpJugador, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, Bitmap^ bmpMejoras, Bitmap^ bmpJugador2, Bitmap^ bmpJugador3, Bitmap^ bmpJugador4) {

		oEscenario->PintarBase(g, bmpBase);
		oArrMejoras->dibujar(g, bmpMejoras, oEscenario->getmatriz());
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador->moverJugador(g, bmpJugador, oEscenario->getmatriz(), bmpBase);


		oJugador2->movimientoIA(g, bmpJugador2, bmpBase, oEscenario->getmatriz());
		oJugador3->movimientoIA(g, bmpJugador3, bmpBase, oEscenario->getmatriz());
		oJugador4->movimientoIA(g, bmpJugador4, bmpBase, oEscenario->getmatriz());

		oArrBombas->Dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador->getX(), oJugador->getY(), oEscenario->getmatriz());
		oArrBombas2->Dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador2->getX(), oJugador2->getY(), oEscenario->getmatriz());
		oArrBombas3->Dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador3->getX(), oJugador3->getY(), oEscenario->getmatriz());
		oArrBombas4->Dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador4->getX(), oJugador4->getY(), oEscenario->getmatriz());

		disminuir_Vidas_Por_Bomba();
		disminuir_Vidas_Por_Bomba2();
		disminuir_Vidas_Por_Bomba3();
		disminuir_Vidas_Por_Bomba4();
		disminuir_Vidas_Por_Bomba5();
		disminuir_Vidas_Por_Bomba6();
		disminuir_Vidas_Por_Bomba7();
		disminuir_Vidas_Por_Bomba8();
		disminuir_Vidas_Por_Bomba9();
		disminuir_Vidas_Por_Bomba10();
		disminuir_Vidas_Por_Bomba11();
		disminuir_Vidas_Por_Bomba12();
		disminuir_Vidas_Por_Bomba13();
		disminuir_Vidas_Por_Bomba14();
		disminuir_Vidas_Por_Bomba15();
		disminuir_Vidas_Por_Bomba16();
		agarrarMejoras();

		validaciones();

	}

	/// <summary>
	/// Método para crear los enemigos y las mejoras
	/// </summary>
	void crear_enemigos_y_mejoras() {

		oArrMejoras->crearMejoras(); //Se llaman los métodos de las clases 

	}

	/// <summary>
	/// Método para retornar el objeto jugador
	/// </summary>
	/// <returns></returns>
	CJugador* getoJugador() {
		return oJugador;
	}

	/// <summary>
/// Método para retornar el objeto jugador2
/// </summary>
/// <returns></returns>
	CJugador2* getoJugador2() {
		return oJugador2;
	}

	CJugador3* getoJugador3() {
		return oJugador3;
	}

	CJugador4* getoJugador4() {
		return oJugador4;
	}

	/// <summary>
/// Método para retornar el objeto del arreglo de mejoras
/// </summary>
/// <returns></returns>
	CArrMejoras* getoArrMejoras() {
		return oArrMejoras;
	}


	/// <summary>
/// Método para obtener el nivel del juego
/// </summary>
/// <returns></returns>
	int getNivel() {
		return nivel;
	}


	/// <summary>
	/// Se inicializan los objetos de las clases y los atributos
	/// </summary>
private:

	CEscenario* oEscenario;
	CJugador* oJugador;
	CJugador2* oJugador2;
	CJugador3* oJugador3;
	CJugador4* oJugador4;


	CArrBombas* oArrBombas;
	CArrBombas2* oArrBombas2;
	CArrBombas3* oArrBombas3;
	CArrBombas4* oArrBombas4;


	CArrMejoras* oArrMejoras;


	int nivel;
	bool habilidad;
};





#endif // !__CONTROLADORA2_H__
