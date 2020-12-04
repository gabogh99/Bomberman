#ifndef __ARRENEMIGOS_H__
#define __ARRENEMIGOS_H__
#include <vector>
#include "Enemigo.h"

using namespace std;

/// <summary>
/// Clase que genera un array de enemigos 
/// </summary>

class CArrEnemigos
{
public:
	CArrEnemigos() {
	
		/// <summary>
		/// Se crea el arreglo de enemigos a partir de un vector de tamaño igual a la cantidad de enemigos
		/// </summary>
		arregloEnemigos = vector<CEnemigo*>();
	
	
	}
	~CArrEnemigos(){}

	/// <summary>
	/// Método que crea los enemigos de la clase padre 
	/// </summary>

	void crearEnemigos() {

		CEnemigo* nuevo = new CEnemigo();
		arregloEnemigos.push_back(nuevo);//Los enemgios creados son añadidos al final del arreglo de enemigos
	}

	/// <summary>
	/// Método para dibujar los enemigos con sus bmps y las posiciones en la matriz
	/// </summary>
	/// <param name="g"></param>
	/// <param name="bmpEnemigo"></param>
	/// <param name="matriz"></param>
	void dibujar(Graphics^ g, Bitmap^ bmpEnemigo, int**matriz) {

		for (int i; i < arregloEnemigos.size(); i++) { //Se recorre el array de enemigos

			arregloEnemigos.at(i)->dibujar(g, bmpEnemigo, matriz); //Conforme se recorre se dibujan y animan los enemigos
			arregloEnemigos.at(i)->animar();
		}

	}

	/// <summary>
	/// Método que retorna el arreglo de enemigos
	/// </summary>
	/// <returns></returns>
	vector<CEnemigo*>getarregloEnemigos() {
		return arregloEnemigos;
	}


/// <summary>
/// Definición del arreglo de enemigos
/// </summary>
private:

	vector<CEnemigo*>arregloEnemigos;
};



#endif // !__ARRENEMIGOS_H__
