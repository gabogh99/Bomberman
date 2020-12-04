#ifndef __MEJORA_H__
#define __MEJORA_H__
#include <ctime>
#include <stdlib.h>
using namespace System::Drawing;

/// <summary>
/// Clase que crea las mejoras 
/// </summary>

class CMejora
{
public:


	CMejora() {

		srand(time(NULL)); // Genera un numero aleatorio para que aparezcan siempre en lugares diferentes
		tipo_de_mejora = rand() % 5 + 1; //Se randomiza el tipo de mejora

		ubicado = false; //Inicializado en false porque no ha sido ubicado 

		i = rand() % 13+1; 
		j = rand() % 15 + 1;

		ancho = 128 / 8; //Ancho del sprite entre la cantidad total
		alto = 96 / 6; //Alto del sprite entre la cantidad total

		indiceX = 0; //Inidice X inicializado en 0
		indiceY = 0; // Indice Y inicializado en 0
	
	}


	~CMejora() {}

	/// <summary>
	/// Método que genera rectángulos de donde se coloca el power-up
	/// </summary>
	/// <returns></returns>
	Rectangle devolverR() {
		return Rectangle(j * 50, i * 50, ancho * 3.125, alto * 3.125); //Se retorna el rectangulo con tamaño de 50x50 y el alto y ancho del sprite
	}

	/// <summary>
	/// Método que dibuja los powerups en el mapa
	/// </summary>
	/// <param name="g"></param>
	/// <param name="bmpMejoras"></param>
	/// <param name="matriz"></param>
	void dibujar(Graphics^g, Bitmap^bmpMejoras, int **matriz) {

		Rectangle porcionAUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto); //Se define y cambia la porción a usar de los sprites

		while (ubicado ==false){ //verifica que no haya sido ubicado el powerUp

			if (matriz[i][j] == 3) {
				ubicado = true; //Si la posición es un bloque destruible cambia ubicado a true
			}

			else //En otro caso, se sigue recorriendo la matriz hasta econtrar un bloque destruible y colocarlo
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

		/// <summary>
		/// Método que retorna el área que ocupará el power-up
		/// </summary>
		/// <param name="g"></param>
		/// <param name="bmpMejoras"></param>
		/// <param name="matriz"></param>
		/// 
		Rectangle aumento = Rectangle(j * 50, i*50, ancho*3.125,alto*3.125);
		g->DrawImage(bmpMejoras, aumento, porcionAUsar, GraphicsUnit::Pixel);//Se dibuja la mejora segun la porciona usar y lodeterminado antes

	}

	/// <summary>
	/// Método para animar las mejoras
	/// </summary>

	void animar() {

		switch (tipo_de_mejora)
		{

			case 1: //Bomba adicional

				indiceX = 0; //Hace el índice 0 por ser las imagenes necesarias
				if (indiceY >= 0 && indiceY < 1)
					indiceY++; //Recorre la imagen de sprites y pasa por las que le corresponden
				else
					indiceY = 0;
				break;

			case 2: //Mover bomba

				indiceX = 4;//Hace el índice 4 por ser las imagenes necesarias
				if (indiceY >= 0 && indiceY < 1)
					indiceY++;//Recorre la imagen de sprites y pasa por las que le corresponden
				else
					indiceY = 0;
				break;

			case 3: //Calavera

				indiceX = 5;//Hace el índice 5 por ser las imagenes necesarias
				if (indiceY >= 0 && indiceY < 1)
					indiceY++;//Recorre la imagen de sprites y pasa por las que le corresponden
				else
					indiceY = 0;
				break;

			case 4: //Patines

				indiceX = 8;//Hace el índice 8 por ser las imagenes necesarias
				if (indiceY >= 0 && indiceY < 1)
					indiceY++;//Recorre la imagen de sprites y pasa por las que le corresponden
				else
					indiceY = 0;
				break;

			case 5: //Vidas

				indiceX = 9;//Hace el índice 9 por ser las imagenes necesarias
				if (indiceY >= 0 && indiceY < 1)
					indiceY++;//Recorre la imagen de sprites y pasa por las que le corresponden
				else
					indiceY = 0;
				break;


		default:
			break;
		}

	}
	/// <summary>
	/// Método que retorna el tipo de mejora a colocar
	/// </summary>
	/// <returns></returns>
	int getTipo_de_mejora() {
		return tipo_de_mejora;
	}

/// <summary>
/// Se definen las variables de la clase
/// </summary>
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

