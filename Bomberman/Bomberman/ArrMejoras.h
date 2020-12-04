#ifndef __ARRMEJORAS_H__
#define __ARRMEJORAS_H__
#include <vector>
#include "Mejora.h"
using namespace std;

/// <summary>
/// Clase que genera un array de Mejoras
/// </summary>
class CArrMejoras
{
public:
	CArrMejoras() {}
	~CArrMejoras() {}


	/// <summary>
	/// Método que crea las mejoras
	/// </summary>
	void crearMejoras() {

		CMejora* nueva_mejora = new CMejora(); //Se crea la mejora
		vector_mejoras.push_back(nueva_mejora); //Se agrega la mejora creada al array de mejoras
	}
	/// <summary>
	/// Método para dibujar los power-ups
	/// Utiliza los bmp y las posiciones en la matriz
	/// </summary>
	/// <param name="g"></param>
	/// <param name="bmpMejoras"></param>
	/// <param name="matriz"></param>
	void dibujar(Graphics^g, Bitmap^bmpMejoras, int **matriz) {

		for (int i = 0; i < vector_mejoras.size(); i++) //Se recorre el array de mejoras
		{
			vector_mejoras.at(i)->dibujar(g, bmpMejoras, matriz); // Se dibuja el powerup
			vector_mejoras.at(i)->animar();
		}

	}

	/// <summary>
	/// Método que retorna el vector de mejoras
	/// </summary>
	/// <returns>vector_mejoras</returns>
	vector<CMejora*>getvector_mejoras() {
		return vector_mejoras;
	}

	/// <summary>
	/// Método para elminiar la mejora
	/// </summary>
	/// <param name="pos"></param>
	void eliminarenpos(int pos) {
		vector_mejoras.erase(vector_mejoras.begin() + pos); //Se elimina la mejora al ser igual a la posición del jugador
	}


//Se define el array de las mejoras
private:
	vector<CMejora*>vector_mejoras;
};








#endif // !__ARRMEJORAS_H__

