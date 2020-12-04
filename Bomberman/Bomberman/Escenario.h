#ifndef __ESCENARIO_H__
#define __ESCENARIO_H__
#include <ctime>
#include <stdlib.h>

/*

Se define la cantidad de filas y columnas para el escenario de juego

*/

#define filas 15
#define columnas 17

using namespace System::Drawing;

/// <summary>
/// Clase que crea la matriz que se utilizará como escenario del juego
/// </summary>

class CEscenario {


/// <summary>
/// Se inicializan los objetos del escenario
/// </summary>

public:
	CEscenario() {
		matriz = new int*[filas];
	}

	~CEscenario() {}

	/// <summary>
	/// Método que genera la matriz mediante un recorrido de listas de filas y columnas
	/// </summary>
	void generarMatriz() {


		srand(time(NULL())); /// Genera un número random para que el mapa no siempre sea el mismo

		/// <summary>
		/// función for que recorre las filas y al llegar al final crea las columnas
		/// </summary>
		for (int i = 0; i < filas; i++) {

			matriz[i] = new int[columnas];

		} 

		/// <summary>
		/// Función for que recorre filas y columnas y define los limites laterales del mapa
		/// Le asigna un valor de 1 a los bordes 
		/// Verifica todos los valores de la matriz que tienen 0 en fila y columna, así como los anteriores al final de las mismas
		/// </summary>

		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1) // Bordes matriz

					matriz[i][j] = 1; // Asigna el valor de 1 a las posiciones del if

				else
				{
					if (i % 2 == 0 && j % 2 == 0) // Define bloques fijos no destruibles cada vez que las posiciones de la matriz son pares
						matriz[i][j] = 1;
					else
					{
						if ((i == 1 && (j == 1 || j == 2)) || (j == 1 && i == 2) || (i == filas - 2 && (j == columnas - 3 || j == columnas - 2)) || (i == filas - 3 && j == columnas - 2)) // Genera zonas libres donde el jugador aparece al iniciar el jeugo.
							matriz[i][j] = 0; //Le da un valor de 0 a los bloques en los que se puede transitar

						else  
						{
							matriz[i][j] = rand() % 2 + 2; //Genera bloques destruibles aleatorios para que el mapa sea diferente, y a estos les da un valor de 2, los demás quedan como 0
						}

					}

				}

			}

		}

	}

	/// <summary>
	/// Método para pintar los bloques transitables, se utiliza la librería graphics y los bmps definidos que contienen las imagenes 
	/// </summary>
	/// <param name="g"></param>
	/// <param name="bmpBase"></param>

	void PintarBase(Graphics^g, Bitmap^bmpBase) {

		int X, Y = 0; // Se definen las posiciones finales de los bloques y se inicializan en 0

		for (int i = 0; i < filas; i++) 
		{
			X = 0;
			for (int j = 0; j < columnas; j++) //Se recorren las filas y columnas de la matriz
			{

				
				if (matriz[i][j] == 0 || matriz[i][j] == 2) //Verifica la posición de matri tiene un valor de 0 o 2, para dibujar los espacios transitables

					g->DrawImage(bmpBase, X, Y, 50, 50);// Dibuja el bmp que contiene el bloque de zona transitable

				X += 50; //Se aumenta en 50, que es el tamaño de los bloques
			}

			Y += 50; //Se aumenta en 50, que es el tamaño de los bloques
		}

	}

	/// <summary>
	///  Método para pintar los bloques fijos y destruibles, se utiliza la librería graphics y los bmps definidos que contienen las imagenes 
	/// Se utilizan los bmps con las imágenes
	/// </summary>
	/// <param name="g"></param>
	/// <param name="bmpSolido"></param>
	/// <param name="bmpDestruible"></param>

	void PintarMatriz(Graphics^g, Bitmap^bmpSolido, Bitmap^bmpDestruible) {

		int X, Y = 0; // Se inicializan las posiciones en 0

		for (int i = 0; i < filas; i++)
		{

			X = 0;
			for (int j = 0; j < columnas; j++) //Se recorren filas y columnas de la matriz
			{
				if (matriz[i][j] == 1) //Verifica que la posición tenga el valor de 1, que son los bloques fijos

					g->DrawImage(bmpSolido, X, Y, 50, 50); // Dibuja el bmp que contiene el bloque fijo

				else
				{
					if (matriz[i][j] == 3)//Verifica que la posición tenga el valor de 3, que son los bloques destriubles

						g->DrawImage(bmpDestruible, X, Y, 50, 50);// Dibuja el bmp que contiene el bloque destruible

				}

				X += 50;//Se aumenta en 50, que es el tamaño de los bloques
			}

			Y += 50;//Se aumenta en 50, que es el tamaño de los bloques
		}

	}

	/// <summary>
	/// Método get que retorna la matriz creada
	/// </summary>
	/// <returns></returns>

	int** getmatriz() {

		return matriz;
	}


private:

	int **matriz; /// Se define la matriz

};




#endif // !__ESCENARIO_H__

