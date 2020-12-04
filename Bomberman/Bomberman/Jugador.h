#ifndef __JUGADOR_H__
#define __JUGADOR_H__
using namespace System::Drawing;

//Se definen direcciones para cambiar las direcciones del jugador
enum Direcciones{Arriba, Abajo, Izquierda, Derecha, Ninguna};

/// <summary>
/// Clase que crea al jugador 
/// </summary>

class CJugador {

public:

	CJugador(int x, int y) {

		//Posición de jugador
		this->x = x;
		this->y = y;
	
		//Movimiento jugador inicializado en 0
		dx = 0;
		dy = 0;
		acelerar = 0;
		//Dimensiones de los sprites 
		ancho = 18;
		alto = 26;
		//índices de los sprites para cambiar y animarlo 
		indiceX = 0;
		indiceY = 0;
		/// <summary>
		/// 
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
		direccion = Direcciones::Ninguna;
		ultima = Direcciones::Abajo;
		//cantidad de vidas iniciales
		vidas = 5;
	}

	~CJugador() {}

	/// <summary>
	/// Funcion que retorna el área que abarca el jugador
	/// </summary>
	/// <returns></returns>
	Rectangle retornarRectangulo() {
		return Rectangle(x + 2 * 3 + dx, y + 15 * 3, (ancho - 4) * 3, (alto - 15) * 3); //Se deine el area del jugador para las intersecciones con explosiones y powerups
	}

	/// <summary>
	/// Método que retorna la cantidad de vidas
	/// </summary>
	/// <returns>vidas</returns>
	int getVidas() {
		return vidas;
	}
	/// <summary>
	/// Método que retorna la posición x del jugador
	/// </summary>
	/// <returns></returns>
	int getX() { return x + 2 * 3; }

	/// <summary>
/// Método que retorna la posición x del jugador
/// </summary>
/// <returns></returns>

	int getY() { return y + 15 * 3 + dy; }

	/// <summary>
	/// Método que determina la cantidad de vidas del jugador
	/// </summary>
	/// <param name="v"></param>
	void setVidas(int v) {
		vidas = v;
	}

	/// <summary>
	/// Método que determina el movimiento en x del jugador
	/// </summary>
	/// <param name="dx"></param>
	void setDX(int dx) {
		this->dx = dx;
	}

/// <summary>
/// Método que determina el movimiento en x del jugador
/// </summary>
/// <param name="dx"></param>
	void setDY(int dy) {
		this->dy = dy;
	}

	/// <summary>
	/// Método que retorna la direccion actual del jugador
	/// </summary>
	/// <returns></returns>
	Direcciones getDireccion() {
		return direccion;
	}

	/// <summary>
	/// Método que define la direccion actial del jugador
	/// </summary>
	/// <param name="direccion"></param>
	void setDireccion(Direcciones direccion) {
		this->direccion = direccion;

	}


	void ValidarMovimiento(int** matriz) {
		int X, Y = 0;

		for (int i = 0; i < filas; i++)
		{
			X = 0;
			for (int j = 0; j < columnas; j++)

			{
				Rectangle c1 = Rectangle(X, Y, 50, 50);

				if (matriz[i][j] == 1 || matriz[i][j] == 3) {

					if (CDI.IntersectsWith(c1))dx = 0;
					if (CAA.IntersectsWith(c1))dy = 0;

				}

				X += 50;
			}
			Y += 50;
		}
	}

	/// <summary>
	/// Método que disminuye las vidas del jugador
	/// </summary>

	void disminuirVidas() {
		x = 50;
		y = 50;//Cuando el jugador pierde una vida, se devuelve al inicio del mapa
		vidas--;

	}
	/// <summary>
	/// Método que disminuye vidas por interseccion con bomba
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

			x = 50;
			y = 50;
			vidas--;

		}

		//if (getY() >= PuntaSuperior && getY() <= PuntaInferior && getX() >= CentroInicioX && getX() <= CentroFinalX  )
		//{
			//x = 50;
			//y = 50;
			//vidas--;
		//}

	}


	/// <summary>
	/// Método que dibuja al jugador
	/// </summary>
	/// <param name="g"></param>
	/// <param name="bmpJugador"></param>
	/// <param name="matriz"></param>
	void dibujarJugador(Graphics^g, Bitmap^bmpJugador, int **matriz){

		CDI = Rectangle(x + 2 * 3 + dx, y + 15 * 3, (ancho - 4) * 3, (alto - 15) * 3); //Se dibuja el rectángulo del área del jugador con el movimiento x
		g->DrawRectangle(Pens::Transparent, CDI);// Se hace transparente para que no se vea

		CAA = Rectangle(x + 2 * 3, y + 15 * 3 + dy, (ancho - 4) * 3, (alto - 15) * 3);//Se dibuja el rectángulo del área del jugador con el movimiento y
		g->DrawRectangle(Pens::Transparent, CAA);// Se hace transparente para que no se vea


		ValidarMovimiento(matriz);; //Se valida el movimiento según los bloques del mapa

		Rectangle PorcionAlusar = Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);//Se define la porcion a usar de los sprites
		Rectangle Aumento = Rectangle(x, y, ancho*3, alto*3);///Se aumenta el sprite para adecuarlo al mapa
		g->DrawImage(bmpJugador, Aumento, PorcionAlusar, GraphicsUnit::Pixel );//Se dibuja el jugador
		x += dx;//Se cambia la posicion x de acuerdo al movimiento
		y += dy; //Se cambia la posicion y de acuerdo al movimiento

	}

	/// <summary>
	/// Método que mueve al jugador
	/// </summary>
	/// <param name="g"></param>
	/// <param name="bmpJugador"></param>
	/// <param name="matriz"></param>
	void moverJugador(Graphics^ g, Bitmap^ bmpJugador, int** matriz){

		direccion == Arriba ? ancho = 17 : ancho = 18;

		switch (direccion)//Se hace un switch para los posibles casos de movimiento
		{
		case Arriba:

			indiceY = 0;
			if (indiceX >= 1 && indiceX < 3) //Si se va hacia arriba, se cambian los índices de los sprites para moverlo
				indiceX++;

			else
				indiceX = 1;
			dx = 0;
			dy = -10-acelerar; //Se redefine el movimiento y se resta en y para subir
			ultima = Arriba; //Se define la ultima posición para lograr detenerse

			break;

		case Abajo:

			indiceX = 0;
			if (indiceY >= 1 && indiceY < 3) //Si se mueve hacia abajo se validan los indices de los sprites y se cambian
				indiceY++;

			else
				indiceY = 1;
			dx = 0;
			dy = 10+acelerar; //Se redefine el movimiento y se suma en y para subir
			ultima = Abajo; //Se define la ultima posición para lograr detenerse

			break;


		case Izquierda:
			indiceY = 3;

			if (indiceX >= 1 && indiceX < 3)//Si se mueve hacia la izquierda se validan los indices de los sprites y se cambian
				indiceX++;

			else
				indiceX = 1;
			dx = -10-acelerar;//Se redefine el movimiento y se resta en x para subir
			dy = 0;
			ultima = Izquierda; //Se define la ultima posición para lograr detenerse

			break;

		case Derecha:
			indiceY = 1;
			if (indiceX >= 1 && indiceX < 3)//Si se mueve hacia la derecha se validan los indices de los sprites y se cambian
				indiceX++;

			else
				indiceX = 1;
			dx = 10+acelerar;//Se redefine el movimiento y se suma en x para subir
			dy = 0;
			ultima = Derecha; //Se define la ultima posición para lograr detenerse

			break;

		case Ninguna: //Se crea para parar el movimiento

			dx = dy = 0; //Se hace 0 el cambio cuando está quieto

			if (ultima == Direcciones::Abajo) { 

				indiceX = 0;
				indiceY = 2; //Si la ultima direccion es abajo, se define el sprite a utilizar
			}

			if (ultima == Direcciones::Arriba) {

				indiceX = 0;
				indiceY = 0;//Si la ultima direccion es arriba, se define el sprite a utilizar
			}

			if (ultima == Direcciones::Derecha) {

				indiceX = 1;
				indiceY = 1; //Si la ultima direccion es derecha, se define el sprite a utilizar
			}

			if (ultima == Direcciones::Izquierda) {

				indiceX = 1;
				indiceY = 3; //Si la ultima direccion es izquierda, se define el sprite a utilizar
			}

			break;

		default:
			break;
		}
		
		dibujarJugador(g, bmpJugador, matriz); //Se dibuja el jugador y actualiza conforma va moviendose, por eso al final del método, luego de las validaciones de movimiento


	}

	/// <summary>
	/// Método que obtiene el numero de aceleracion uitilizado para el power up patinar
	/// </summary>
	/// <returns></returns>
	int getAcelerar() {
		return acelerar;
	}

	/// <summary>
	/// Método con el que se establece la aceleracion del jugador
	/// </summary>
	/// <param name="v"></param>
	void setAcelerar(int v) {
		acelerar = v;
	}

/// <summary>
/// Definición de los atributos del jugador
/// </summary>

private:

	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	int acelerar;

	Direcciones direccion;
	Direcciones ultima;

	Rectangle CDI;
	Rectangle CAA; 

	int vidas;

};



#endif // !__JUGADOR_H__
