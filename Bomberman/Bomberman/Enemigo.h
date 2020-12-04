#ifndef __ENEMIGO_H__
#define __ ENEMIGO_H__

enum Estado_Enemigo{Eliminado,Normal}; // Se definen estado para el enemigo
#include <ctime>
#include <cstdlib>
using namespace System::Drawing;

/// <summary>
/// Clase que crea los enemigos
/// </summary>

class CEnemigo
{
public:
	CEnemigo() {
	

		srand(time(NULL)); // Genera un número random para que los enemigos no aparezcan en el mismo lugar siempre

		i = rand() % 13 + 1;//Genera un valor aleatorio para una fila
		j = rand() % 13 + 2;//Genera un valor aleatorio para una columna
		x = 715; 
		y = 650;

		dx = 5; //Se inicializa el cambio en x de los enemigos en 5

		indiceX = 0; //Se crea el indice x para definir el cambio de sprites
		indiceY = 0;//Se crea el indice y para definir el cambio de sprites

		ancho = 96 / 6; //largo de sprites dividido entre la cantidad de animaciones
		alto = 20; // alto de sprite

		ubicado = false; //boolean que determina si está ya ubicado o no
		estado = Normal; //Se inicializa el estado del enemigo

	}
	~CEnemigo() {}

	/// <summary>
	/// Método que permite dibujar los enemigos usando la librería Graphics
	/// Utiliza el bmp del enemigo y la matriz para ubicarlos
	/// </summary>
	/// <param name="g"></param>
	/// <param name="bmpEnemigo"></param>
	/// <param name="matriz"></param>

	void dibujar(Graphics^ g, Bitmap^ bmpEnemigo, int** matriz) {
		Rectangle porcionAUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);// Crea los rectángulos de la zona que ocupa el enemigo en el mapa

		while ((matriz[i][j - 1] != 2 || matriz[i][j] != 2 || matriz[i][j + 1] != 2) && i < 14 && ubicado == false) { // Verifica que el enemigo tenga espacio para ser ubicado en una zona de tres bloques libres para colocarlo ahi

			j++;
			if (j == 15) { 

				i++; //Recorre la matriz fila por fila
				j = 0; 
			}

			if (i >= 14)break;
			x = j * 50; //Hace el movimiento de 50 pixeles en x
			y = i * 50;//Hace el movimiento de 50 pixeles en y
		}


		Rectangle Aumento = Rectangle(x, y, 40, 40); 
		g->DrawImage(bmpEnemigo, Aumento, porcionAUsar, GraphicsUnit::Pixel); //Se dibuja el enemigo con el bmp con la imagen
		ubicado = true;
		x += dx;

		if ((matriz[y / 50][(x + 50) / 50] == 3 || matriz[y / 50][(x + 50) / 50] == 1) ||  (matriz[y/50][(x-10)/50]== 3 || matriz[y/50][(x-10)/50]== 1 )) //Se verifica que sean bloques trasitables para realizar el cambio

			dx *= -1; //Se ahcen engativo o positivo el cambio para llevarlo de un lado al otro al chocar con un bloque 
	}

	void animar() {

		if (indiceX >= 0 && indiceX < 5) { //A medida que el indice avanza, el sprite se actualiza cambiando la imagen
			indiceX++;
		}

		if (indiceX == 5) {

			while (indiceX != 0) //Realiza el mismo proceso pero ahora devolviendo la imagen para hacerla realista
				indiceX--;
		}

	}

	/// <summary>
	/// Se crea un rectángulo que determina el área que ocupa el enemigo
	/// </summary>
	/// <returns></returns>

	Rectangle retornarRectangulo() {
		return Rectangle(x, y, 50, 50);
	}

/// <summary>
/// Se inicializan las variables del enemigo
/// </summary>

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

