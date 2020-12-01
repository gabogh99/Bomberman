#ifndef __MEJORA_H__
#define __MEJORA_H__
#include <ctime>
#include <stdlib.h>
using namespace System::Drawing;
class CMejora
{
public:


	CMejora() {

		srand(time(NULL));
		tipo_de_mejora = rand() % 5 + 1;

		ubicado = false;

		i = rand() % 13+1;
		j = rand() % 15 + 1;

		ancho = 128 / 8;
		alto = 96 / 6;

		indiceX = 0;
		indiceY = 0;
	
	}


	~CMejora() {}

	Rectangle devolverR() {
		return Rectangle(j * 50, i * 50, ancho * 3.125, alto * 3.125);
	}
	void dibujar(Graphics^g, Bitmap^bmpMejoras, int **matriz) {

		Rectangle porcionAUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);

		while (ubicado ==false){

			if (matriz[i][j] == 3) {
				ubicado = true;
			}

			else
			{
				if (j < 17) {
					i++;

					if (i == 14) {
					i = 0;
					j++; 
					}
				}
			}

		}


		Rectangle aumento = Rectangle(j * 50, i*50, ancho*3.125,alto*3.125);
		g->DrawImage(bmpMejoras, aumento, porcionAUsar, GraphicsUnit::Pixel);

	}

	void animar() {

		switch (tipo_de_mejora)
		{

			case 1: //Bomba adicional

				indiceX = 0;
				if (indiceY >= 0 && indiceY < 1)
					indiceY++;
				else
					indiceY = 0;
				break;

			case 2: //Mover bomba

				indiceX = 4;
				if (indiceY >= 0 && indiceY < 1)
					indiceY++;
				else
					indiceY = 0;
				break;

			case 3: //Calavera

				indiceX = 5;
				if (indiceY >= 0 && indiceY < 1)
					indiceY++;
				else
					indiceY = 0;
				break;

			case 4: //Patines

				indiceX = 8;
				if (indiceY >= 0 && indiceY < 1)
					indiceY++;
				else
					indiceY = 0;
				break;

			case 5: //Vidas

				indiceX = 9;
				if (indiceY >= 0 && indiceY < 1)
					indiceY++;
				else
					indiceY = 0;
				break;


		default:
			break;
		}

	}

	int getTipo_de_mejora() {
		return tipo_de_mejora;
	}
private:

	int i;
	int j;

	int indiceX;
	int indiceY;

	int ancho;
	int alto;

	int tipo_de_mejora;

	bool ubicado;
};



#endif // !__MEJORA_H__

