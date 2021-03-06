#ifndef __JUGADOR2_H__
#define __JUGADOR2_H__
#include "Escenario.h"
#include "Jugador.h"

#define filas 15
#define columnas 17

using namespace System::Drawing;


//Se definen direcciones para cambiar las direcciones del jugador
enum Direcciones2{ Arriba2, Abajo2, Izquierda2, Derecha2, Ninguna2 };

/// <summary>
/// Clase que crea al jugador 
/// </summary>

class CJugador2 {

public:

	CJugador2(int x, int y) {

		i = 1;
		j = 15;

		//Posici�n de jugador
		this->x = x;
		this->y = y;

		//Movimiento jugador inicializado en 0
		dx = 0;
		dy = 0;
		acelerar = rand() % 5 + 1;

		//Dimensiones de los sprites 
		ancho = 18;
		alto = 26;
		//�ndices de los sprites para cambiar y animarlo 
		indiceX = 0;
		indiceY = 0;
		/// <summary>
		/// 
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
		direccion2 = Direcciones2::Ninguna2;
		ultima2 = Direcciones2::Abajo2;
		//cantidad de vidas iniciales
		vidas = rand() % 6 + 5;
	}

	~CJugador2() {}

	/// <summary>
	/// Funcion que retorna el �rea que abarca el jugador
	/// </summary>
	/// <returns></returns>
	Rectangle retornarRectangulo() {
		return Rectangle(x + 2 * 3 + dx, y + 15 * 3, (ancho - 4) * 3, (alto - 15) * 3); //Se deine el area del jugador para las intersecciones con explosiones y powerups
	}

	/// <summary>
	/// M�todo que retorna la cantidad de vidas
	/// </summary>
	/// <returns>vidas</returns>
	int getVidas() {
		return vidas;
	}
	/// <summary>
	/// M�todo que retorna la posici�n x del jugador
	/// </summary>
	/// <returns></returns>
	int getX() { return x + 2 * 3; }

	/// <summary>
/// M�todo que retorna la posici�n x del jugador
/// </summary>
/// <returns></returns>

	int getY() { return y + 15 * 3 + dy; }

	/// <summary>
	/// M�todo que determina la cantidad de vidas del jugador
	/// </summary>
	/// <param name="v"></param>
	void setVidas(int v) {
		vidas = v;
	}

	/// <summary>
	/// M�todo que determina el movimiento en x del jugador
	/// </summary>
	/// <param name="dx"></param>
	void setDX(int dx) {
		this->dx = dx;
	}

	/// <summary>
	/// M�todo que determina el movimiento en x del jugador
	/// </summary>
	/// <param name="dx"></param>
	void setDY(int dy) {
		this->dy = dy;
	}

	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		this->y = y;
	}

	/// <summary>
	/// M�todo que retorna la direccion actual del jugador
	/// </summary>
	/// <returns></returns>
	Direcciones2 getDireccion() {
		return direccion2;
	}

	/// <summary>
	/// M�todo que define la direccion actial del jugador
	/// </summary>
	/// <param name="direccion"></param>
	void setDireccion(Direcciones2 direccion2) {
		this->direccion2 = direccion2;

	}

	/// <summary>
/// M�todo que crea rect�ngulos transparentes para definir el �rea del jugador.
/// Con estos se valida si es posible avanzar o si hay un bloque
/// </summary>
/// <param name="matriz"></param>

	void ValidarMovimiento(int** matriz) {
		int X, Y = 0;

		for (int i = 0; i < filas; i++)//Se recorren las filas del mpara
		{
			X = 0;
			for (int j = 0; j < columnas; j++)//Se recorren las columnas del mapra

			{
				Rectangle c1 = Rectangle(X, Y, 50, 50);//Se crea el rect�ngulo del �rea

				if (matriz[i][j] == 1 || matriz[i][j] == 3) {

					if (CDI.IntersectsWith(c1))dx = 0;//Si adelante del rect�ngulo hay un bloque fijo o un destruible, se detiene el movimiento
					if (CAA.IntersectsWith(c1))dy = 0;

				}

				X += 50;//Se aumenta el movimiento x
			}
			Y += 50;//Se aumenta el movimiento en y
		}
	}

	/// <summary>
	/// M�todo que disminuye las vidas del jugador
	/// </summary>

	void disminuirVidas() {
		x = 50;
		y = 650;//Cuando el jugador pierde una vida, se devuelve al inicio del mapa
		vidas--;

	}
	/// <summary>
	/// M�todo que disminuye vidas por interseccion con bomba
	/// </summary>
	/// <param name="PuntaIzquierda"></param>
	/// <param name="puntaDerecha"></param>
	/// <param name="CentroInicioY"></param>
	/// <param name="CentroFinalY"></param>
	/// <param name="PuntaSuperior"></param>
	/// <param name="PuntaInferior"></param>
	/// <param name="CentroInicioX"></param>
	/// <param name="CentroFinalX"></param>


	void disminuirVidas(int PuntaIzquierda, int puntaDerecha, int CentroInicioY, int CentroFinalY,
		int PuntaSuperior, int PuntaInferior, int CentroInicioX, int CentroFinalX) {

		if (getX() >= PuntaIzquierda && getX() <= puntaDerecha && getY() >= CentroInicioY && getY() <= CentroFinalY) {

			x = 750;
			y = 20;
			vidas--;

		}

		if (getY() >= PuntaSuperior && getY() <= PuntaInferior && getX() >= CentroInicioX && getX() <= CentroFinalX)
		{
			x = 750;
			y = 20;
			vidas--;
		}

	}


	/// <summary>
	/// M�todo que dibuja al jugador
	/// </summary>
	/// <param name="g"></param>
	/// <param name="bmpJugador"></param>
	/// <param name="matriz"></param>
	/// 
	void dibujarJugador(Graphics^ g, Bitmap^ bmpJugador2, Bitmap^bmpBase, int** matriz) {

		CDI = Rectangle(x + 2 * 3 + dx, y + 15 * 3, (ancho - 4) * 3, (alto - 15) * 3); //Se dibuja el rect�ngulo del �rea del jugador con el movimiento x
		g->DrawRectangle(Pens::Transparent, CDI);// Se hace transparente para que no se vea

		CAA = Rectangle(x + 2 * 3, y + 15 * 3 + dy, (ancho - 4) * 3, (alto - 15) * 3);//Se dibuja el rect�ngulo del �rea del jugador con el movimiento y
		g->DrawRectangle(Pens::Transparent, CAA);// Se hace transparente para que no se vea


		ValidarMovimiento(matriz);; //Se valida el movimiento seg�n los bloques del mapa

		Rectangle PorcionAlusar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);//Se define la porcion a usar de los sprites
		Rectangle Aumento = Rectangle(x, y, ancho * 3, alto * 3);///Se aumenta el sprite para adecuarlo al mapa
		g->DrawImage(bmpJugador2, Aumento, PorcionAlusar, GraphicsUnit::Pixel);//Se dibuja el jugador
		x += dx;//Se cambia la posicion x de acuerdo al movimiento
		y += dy; //Se cambia la posicion y de acuerdo al movimiento

		if (vidas < 1) {//Se valida si las vidas son menores a 1, cuando el jugador muere


			ancho = 10;//Se define alto y ancho para dibujar la base
			alto = 10;
			g->DrawImage(bmpBase, Aumento, PorcionAlusar, GraphicsUnit::Pixel);//Se cambia el jugador por la base
			vidas = 0;//Se hacen 0 para que no haya negativos


		}

		else {
			ancho = 18;//Se confirma el ancho y alto para cambiarlo al reiniciar el juego
			alto = 26;
		}

	}

	/// <summary>
/// M�todo que realiza el movimiento autom�tico de los enemigos
/// </summary>
/// <param name="g"></param>
/// <param name="bmpJugador2"></param>
/// <param name="bmpBase"></param>
/// <param name="matriz"></param>

	void movimientoIA(Graphics^ g, Bitmap^ bmpJugador2, Bitmap^ bmpBase, int** matriz) {


			CDI = Rectangle(x + 2 * 3 + dx, y + 15 * 3, (ancho - 4) * 3, (alto - 15) * 3); //Se dibuja el rect�ngulo del �rea del jugador con el movimiento x
			g->DrawRectangle(Pens::Transparent, CDI);// Se hace transparente para que no se vea

			CAA = Rectangle(x + 2 * 3, y + 15 * 3 + dy, (ancho - 4) * 3, (alto - 15) * 3);//Se dibuja el rect�ngulo del �rea del jugador con el movimiento y
			g->DrawRectangle(Pens::Transparent, CAA);// Se hace transparente para que no se vea


			ValidarMovimiento(matriz);; //Se valida el movimiento seg�n los bloques del mapa

			Rectangle PorcionAlusar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);//Se define la porcion a usar de los sprites
			Rectangle Aumento = Rectangle(x, y, ancho * 3, alto * 3);///Se aumenta el sprite para adecuarlo al mapa
			g->DrawImage(bmpJugador2, Aumento, PorcionAlusar, GraphicsUnit::Pixel);//Se dibuja el jugador

			x += dx;//Se cambia la posicion x de acuerdo al movimiento
			y += dy; //Se cambia la posicion y de acuerdo al movimiento

			
			indiceY = 3;//Se define el indice del sprite

				ancho = 18;
				alto = 26;
			

			if (vidas < 1) {


				ancho = 10;//Se define alto y ancho para dibujar la base
				alto = 10;
				g->DrawImage(bmpBase, Aumento, PorcionAlusar, GraphicsUnit::Pixel);//Se cambia el jugador por la base
				vidas = 0;//Se hacen 0 para que no haya negativos
				x = 750;
				y = 50;
				dx = 0;//Se detiene el movimiento


			}

			else {

				ancho = 18; //Se redefine el ancho y alto para cambiarlo al reiniciar el juego
				alto = 26;
				dx -= 0.3;// Se cambia el movimiento

			}

		

	}

	/// <summary>
	/// M�todo que mueve al jugador
	/// </summary>
	/// <param name="g"></param>
	/// <param name="bmpJugador"></param>
	/// <param name="matriz"></param>
	void moverJugador(Graphics^ g, Bitmap^ bmpJugador2, Bitmap^ bmpBase ,int** matriz) {

		direccion2 == Arriba2 ? ancho = 17 : ancho = 18;

		switch (direccion2)//Se hace un switch para los posibles casos de movimiento
		{
		case Arriba2:

			indiceY = 0;
			if (indiceX >= 1 && indiceX < 3) //Si se va hacia arriba, se cambian los �ndices de los sprites para moverlo
				indiceX++;

			else
				indiceX = 1;
			dx = 0;
			dy = -10 - acelerar; //Se redefine el movimiento y se resta en y para subir
			ultima2 = Arriba2; //Se define la ultima posici�n para lograr detenerse

			break;

		case Abajo2:

			indiceX = 0;
			if (indiceY >= 1 && indiceY < 3) //Si se mueve hacia abajo se validan los indices de los sprites y se cambian
				indiceY++;

			else
				indiceY = 1;
			dx = 0;
			dy = 10 + acelerar; //Se redefine el movimiento y se suma en y para subir
			ultima2 = Abajo2; //Se define la ultima posici�n para lograr detenerse

			break;


		case Izquierda2:
			indiceY = 3;

			if (indiceX >= 1 && indiceX < 3)//Si se mueve hacia la izquierda se validan los indices de los sprites y se cambian
				indiceX++;

			else
				indiceX = 1;
			dx = -10 - acelerar;//Se redefine el movimiento y se resta en x para subir
			dy = 0;
			ultima2 = Izquierda2; //Se define la ultima posici�n para lograr detenerse

			break;

		case Derecha2:
			indiceY = 1;
			if (indiceX >= 1 && indiceX < 3)//Si se mueve hacia la derecha se validan los indices de los sprites y se cambian
				indiceX++;

			else
				indiceX = 1;
			dx = 10 + acelerar;//Se redefine el movimiento y se suma en x para subir
			dy = 0;
			ultima2 = Derecha2; //Se define la ultima posici�n para lograr detenerse

			break;

		case Ninguna2: //Se crea para parar el movimiento

			dx = dy = 0; //Se hace 0 el cambio cuando est� quieto

			if (ultima2 == Direcciones2::Abajo2) {

				indiceX = 0;
				indiceY = 2; //Si la ultima direccion es abajo, se define el sprite a utilizar
			}

			if (ultima2 == Direcciones2::Arriba2) {

				indiceX = 0;
				indiceY = 0;//Si la ultima direccion es arriba, se define el sprite a utilizar
			}

			if (ultima2 == Direcciones2::Derecha2) {

				indiceX = 1;
				indiceY = 1; //Si la ultima direccion es derecha, se define el sprite a utilizar
			}

			if (ultima2 == Direcciones2::Izquierda2) {

				indiceX = 1;
				indiceY = 3; //Si la ultima direccion es izquierda, se define el sprite a utilizar
			}

			break;

		default:
			break;
		}

		dibujarJugador(g, bmpJugador2,bmpBase, matriz); //Se dibuja el jugador y actualiza conforma va moviendose, por eso al final del m�todo, luego de las validaciones de movimiento


	}

	/// <summary>
	/// M�todo que obtiene el numero de aceleracion uitilizado para el power up patinar
	/// </summary>
	/// <returns></returns>
	int getAcelerar() {
		return acelerar;
	}

	/// <summary>
	/// M�todo con el que se establece la aceleracion del jugador
	/// </summary>
	/// <param name="v"></param>
	void setAcelerar(int v) {
		acelerar = v;
	}

	/// <summary>
	/// Definici�n de los atributos del jugador
	/// </summary>

private:

	int i;
	int j;
	int x;
	int y;
	float dx;
	float dy;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	int acelerar;

	Direcciones2 direccion2;
	Direcciones2 ultima2;

	Rectangle CDI;
	Rectangle CAA;

	int vidas;

};



#endif // !__JUGADOR2_H__
