#ifndef __JUGADOR_H__
#define __JUGADOR_H__
using namespace System::Drawing;

enum Direcciones{Arriba, Abajo, Izquierda, Derecha, Ninguna};

class CJugador {

public:

	CJugador(int x, int y) {

		//Posición
		this->x = x;
		this->y = y;
	
		//Movimiento jugador
		dx = 0;
		dy = 0;
		//Dimensiones Sprites
		ancho = 18;
		alto = 26;
		indiceX = 0;
		indiceY = 0;

		direccion = Direcciones::Ninguna;
		ultima = Direcciones::Abajo;


	}

	~CJugador() {}

	void setDireccion(Direcciones direccion) {
		this->direccion = direccion;

	}

	void dibujarJugador(Graphics^g, Bitmap^bmpJugador) {

		Rectangle PorcionAlusar = Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
		Rectangle Aumento = Rectangle(x, y, ancho*3, alto*3);
		g->DrawImage(bmpJugador, Aumento, PorcionAlusar, GraphicsUnit::Pixel );
		x += dx;
		y += dy;

	}

	void moverJugador(Graphics^ g, Bitmap^ bmpJugador) {

		direccion == Arriba ? ancho = 17 : ancho = 18;

		switch (direccion)
		{
		case Arriba:

			indiceY = 0;
			if (indiceX >= 1 && indiceX < 3)
				indiceX++;

			else
				indiceX = 1;
			dx = 0;
			dy = -10;
			ultima = Arriba;

			break;

		case Abajo:

			indiceX = 0;
			if (indiceY >= 1 && indiceY < 3)
				indiceY++;

			else
				indiceY = 1;
			dx = 0;
			dy = 10;
			ultima = Abajo;

			break;


		case Izquierda:
			indiceY = 3;

			if (indiceX >= 1 && indiceX < 3)
				indiceX++;

			else
				indiceX = 1;
			dx = -10;
			dy = 0;
			ultima = Izquierda;

			break;

		case Derecha:
			indiceY = 1;
			if (indiceX >= 1 && indiceX < 3)
				indiceX++;

			else
				indiceX = 1;
			dx = 10;
			dy = 0;
			ultima = Derecha;

			break;

		case Ninguna:

			dx = dy = 0;

			if (ultima == Direcciones::Abajo) {

				indiceX = 0;
				indiceY = 2;
			}

			if (ultima == Direcciones::Arriba) {

				indiceX = 0;
				indiceY = 0;
			}

			if (ultima == Direcciones::Derecha) {

				indiceX = 1;
				indiceY = 1;
			}

			if (ultima == Direcciones::Izquierda) {

				indiceX = 1;
				indiceY = 3;
			}

			break;

		default:
			break;
		}
		
		dibujarJugador(g, bmpJugador);


	}

private:

	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	Direcciones direccion;
	Direcciones ultima;

};



#endif // !__JUGADOR_H__
