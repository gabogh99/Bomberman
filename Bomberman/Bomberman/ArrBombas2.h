#ifndef __ARRBOMBAS2_H__
#define __ARRBOMBAS2_H__



#include "Bomba2.h"
#include <vector>
using namespace std;

/// <summary>
/// Clase que crea un arreglo de bombas
/// </summary>

class CArrBombas2
{
public:

	//Se inicializa el objeto y se le permite solamente lanzar una bomba 

	CArrBombas2() { totalBombas2 = rand() % 6 + 1; }



	~CArrBombas2() {}

	/// <summary>
	/// Método para crear una bomba
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>

	void crear_una_bomba2(int x, int y) {

		if (arregloBombas2.size() < totalBombas2) { //Valida si el array es menor a la cantida de bombas
			CBomba2* nueva_bomba = new CBomba2(x, y); // Se crea un objeto bomba
			arregloBombas2.push_back(nueva_bomba); // Se añade la bomba al final del array de bombas
		}
	}

	/// <summary>
	/// Método para dibujar una bomba
	/// </summary>
	/// <param name="g"></param>
	/// <param name="bmpBomba"></param>
	/// <param name="bmpExplosion"></param>
	/// <param name="xJugador"></param>
	/// <param name="yJugador"></param>
	/// <param name="matriz"></param>

	void Dibujar_una_bomba(Graphics^ g, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, int xJugador, int yJugador, int** matriz) {

		for (int i = 0; i < arregloBombas2.size(); i++) //Se recorre el array de bombas
		{
			switch (arregloBombas2.at(i)->getEstado()) // Se hace un switch para validar los estados
			{

			case Estado::normal:
				arregloBombas2.at(i)->dibujarBomba(g, bmpBomba, xJugador, yJugador, matriz); //Si el estado es normal, se dibuja una bomba con el bmp de la bomba normal
				arregloBombas2.at(i)->animar(); //Se realiza la animación de la posición i del array
				break;

			case Estado::explosion:
				arregloBombas2.at(i)->DibujarExplosion(g, bmpExplosion, matriz); //Si el estado es de explosion se dibuja con el bmp de la explosion antes definida
				arregloBombas2.at(i)->animarExplosion();//Se realiza la animación
				break;

			case Estado::desaparecer:
				arregloBombas2.erase(arregloBombas2.begin() + i);//Si el estado es desaparecer se borra la bomba del array y se cambia de posición
				break;

			default:
				break;
			}
		}

	}

	/// <summary>
	/// Método que retorna el array de bombas
	/// </summary>
	/// <returns></returns>
	vector<CBomba2*>getarregloBombas() {
		return arregloBombas2;
	}

	/// <summary>
	/// Método para determinar la cantidad de bombas
	/// </summary>
	/// <param name="v"></param>
	void setBombas(int v) {
		totalBombas2 = v;
	}

	/// <summary>
	/// Método para retornar la cantidad de bombas
	/// </summary>
	/// <returns></returns>
	int getBombas() {
		return totalBombas2;
	}

	/// <summary>
	/// Se definen los atributos de la clase
	/// </summary>

private:
	vector<CBomba2*>arregloBombas2;
	int totalBombas2;


};



#endif // !__ARRBOMBAS2_H__