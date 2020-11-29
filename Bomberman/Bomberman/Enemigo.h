#ifndef __ENEMIGO_H__
#define __ ENEMIGO_H__
enum Estado_Enemigo{Eliminado,Normal};
#include <ctime>
#include <cstdlib>
using namespace System::Drawing;

class CEnemigo
{
public:
	CEnemigo() {
	
		srand(time(NULL));
		i = rand() % 13 + 1;
		j = rand() % 13 + 2;
		x = 715;
		y = 650;

		dx = 5;
		indiceX = 0;
		indiceY = 0;

		ancho = 96 / 6;
		alto = 16 / 6;

		ubicado = false;
		estado = Normal;

	}
	~CEnemigo() {}

	void dibujar(Graphics^ g, Bitmap^ bmpEnemigo, int** matriz) {
		Rectangle porcionAUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);

		while ((matriz[i][j - 1] != 2 || matriz[i][j] != 2 || matriz[i][j + 1] != 2) && i < 14 && ubicado == false) {

			j++;
			if (j == 15) {

				i++;
				j - 0;
			}

			if (i >= 14)break;
			x = j * 50;
			y = i * 50;
		}


		Rectangle Aumento = Rectangle(x, y, 40, 40);
		g->DrawImage(bmpEnemigo, Aumento, porcionAUsar, GraphicsUnit::Pixel);
		ubicado = true;
		x += dx;

		if ((matriz[y / 50][(x + 50) / 50] == 3 || matriz[y / 50][(x + 50) / 50] == 1) ||  (matriz[y/50][(x-10)/50]== 3 || matriz[y/50][(x-10)/50]== 1 ))

			dx *= -1;
	}

	void animar() {

		if (indiceX >= 0 && indiceX < 5) {
			indiceX++;
		}

		if (indiceX == 5) {

			while (indiceX != 0)
				indiceX--;
		}

	}


private:

	int x;
	int y;

	int i;
	int j;

	int dx;

	int indiceX;
	int indiceY;

	int ancho;
	int alto;

	bool ubicado;

	Estado_Enemigo estado;

};




#endif // !__ENEMIGO_H__

