#ifndef __ARRBOMBAS4_H__
#define __ARRBOMBAS4_H__



#include "Bomba4.h"
#include <vector>
using namespace std;

/// <summary>
/// Clase que crea un arreglo de bombas
/// </summary>

class CArrBombas4
{
public:

	//Se inicializa el objeto y se le permite solamente lanzar una bomba 

	CArrBombas4() { totalBombas4 = rand() % 6 + 1; }



	~CArrBombas4() {}

	/// <summary>
	/// Método para crear una bomba
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>

	void crear_una_bomba2(int x, int y) {

		if (arregloBombas4.size() < totalBombas4) { //Valida si el array es menor a la cantida de bombas
			CBomba4* nueva_bomba = new CBomba4(x, y); // Se crea un objeto bomba
			arregloBombas4.push_back(nueva_bomba); // Se añade la bomba al final del array de bombas
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

		for (int i = 0; i < arregloBombas4.size(); i++) //Se recorre el array de bombas
		{
			switch (arregloBombas4.at(i)->getEstado()) // Se hace un switch para validar los estados
			{

			case Estado4::normal4:
				arregloBombas4.at(i)->dibujarBomba(g, bmpBomba, xJugador, yJugador, matriz); //Si el estado es normal, se dibuja una bomba con el bmp de la bomba normal
				arregloBombas4.at(i)->animar(); //Se realiza la animación de la posición i del array
				break;

			case Estado4::explosion4:
				arregloBombas4.at(i)->DibujarExplosion(g, bmpExplosion, matriz); //Si el estado es de explosion se dibuja con el bmp de la explosion antes definida
				arregloBombas4.at(i)->animarExplosion();//Se realiza la animación
				break;

			case Estado4::desaparecer4:
				arregloBombas4.erase(arregloBombas4.begin() + i);//Si el estado es desaparecer se borra la bomba del array y se cambia de posición
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
	vector<CBomba4*>getarregloBombas() {
		return arregloBombas4;
	}

	/// <summary>
	/// Método para determinar la cantidad de bombas
	/// </summary>
	/// <param name="v"></param>
	void setBombas(int v) {
		totalBombas4 = v;
	}

	/// <summary>
	/// Método para retornar la cantidad de bombas
	/// </summary>
	/// <returns></returns>
	int getBombas() {
		return totalBombas4;
	}

	/// <summary>
	/// Se definen los atributos de la clase
	/// </summary>

private:
	vector<CBomba4*>arregloBombas4;
	int totalBombas4;


};



#endif // !__ARRBOMBAS4_H__