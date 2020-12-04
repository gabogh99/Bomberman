#ifndef __CONTROLADORA_H__
#define __CONTROLADORA_H__
#include "Escenario.h"
#include "Jugador.h"
#include "ArrBombas.h"
#include "ArrMejoras.h"
#include "ArrEnemigos.h"

/// <summary>
/// Clase que controla todas las funciones del juego
/// </summary>

class CControladora {

public:

	CControladora() {

		/// <summary>
		/// Se crean los objetos de todas clases incluidas
		/// </summary>

		oEscenario = new CEscenario();
		oJugador = new CJugador(50, 50);
		oArrBombas = new CArrBombas();
		oArrMejoras = new CArrMejoras();
		oArrEnemigos = new CArrEnemigos();
		
		nivel = 3; //Se inicializa el nivel
		habilidad = false; // La hailidad se inicializa en false al no iniciar con power up

	}



	~CControladora() {}

	/// <summary>
	/// Método que genera matriz al cambiar de nivel
	/// </summary>

	void CambiarNivel() {

		oEscenario->generarMatriz();

	}


	/// <summary>
	/// Método que agrega una bomba 
	/// </summary>
	void agregarBomba() {
		oArrBombas->crear_una_bomba(oJugador->getX(), oJugador->getY()); //Agarra una bomba del array y la coloca en las posiciones de x y y del jugador
	}

	/// <summary>
	/// Método para disminuir vidas por el enemigo
	/// </summary>
	
	void disminuir_Vidas_Por_Enemigo() {

		for (int i = 0; i < oArrEnemigos->getarregloEnemigos().size(); i++) //Se recorre el array de enemigos
		{
			if (oJugador->retornarRectangulo().IntersectsWith(oArrEnemigos->getarregloEnemigos().at(i)->retornarRectangulo())){ //Valida si el rectángulo del área ocupada interseca con el enemigo

				oJugador->disminuirVidas(); //Si el if es cierto disminuye la vida activando el método en la clase Jugador
			
			}
				
		}

	}

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
			PuntaSuperior = oArrBombas->getarregloBombas().at(i)->getY() -100;
			PuntaInferior = oArrBombas->getarregloBombas().at(i)->getY() + 150;
			CentroInicioY = oArrBombas->getarregloBombas().at(i)->getY();
			CentroInicioX = oArrBombas->getarregloBombas().at(i)->getY();
			CentroFinalX = oArrBombas->getarregloBombas().at(i)->getY() + 50;
			CentroFinalY = oArrBombas->getarregloBombas().at(i)->getY() + 50;

			if (oArrBombas->getarregloBombas().at(i)->getEstado() == Estado::explosion) { //Valida si la bomba está en explosion

				oJugador->disminuirVidas(PuntaIzquierda, puntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX); //Si el if es cieto, se disminuye la vida si la posicion del jugador es alguna de las definidas

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

	void dibujar(Graphics^ g, Bitmap^ bmpBase, Bitmap^ bmpSolido, Bitmap^ bmpDestruible, Bitmap^ bmpJugador, Bitmap^bmpBomba, Bitmap^bmpExplosion, Bitmap^bmpMejoras, Bitmap^bmpEnemigo ) {

		oEscenario->PintarBase(g, bmpBase);
		oArrMejoras->dibujar(g, bmpMejoras, oEscenario->getmatriz());
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador->moverJugador(g, bmpJugador, oEscenario->getmatriz());
		oArrBombas->Dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador->getX(),oJugador->getY(), oEscenario->getmatriz() );
		oArrEnemigos->dibujar(g, bmpEnemigo, oEscenario->getmatriz());

		disminuir_Vidas_Por_Bomba();
		disminuir_Vidas_Por_Enemigo();
		agarrarMejoras();

	}

	/// <summary>
	/// Método para crear los enemigos y las mejoras
	/// </summary>
	void crear_enemigos_y_mejoras() {

		oArrEnemigos->crearEnemigos();
		oArrMejoras->crearMejoras(); //Se llaman los métodos de las clases 

	}

	/// <summary>
	/// Método para retornar el objeto jugador
	/// </summary>
	/// <returns></returns>
	CJugador*getoJugador() {
		return oJugador;
	}

	/// <summary>
/// Método para retornar el objeto del arreglo de mejoras
/// </summary>
/// <returns></returns>
	CArrMejoras* getoArrMejoras() {
		return oArrMejoras;
	}

	/// <summary>
/// Método para retornar el objeto arreglo de enemigos
/// </summary>
/// <returns></returns>
	CArrEnemigos* getoArrEnemigos() {
		return oArrEnemigos;
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

	CEscenario*oEscenario;
	CJugador*oJugador;
	CArrBombas*oArrBombas;
	CArrMejoras* oArrMejoras;
	CArrEnemigos* oArrEnemigos;

	int nivel;
	bool habilidad;
};





#endif // !__CONTROLADORA_H__

