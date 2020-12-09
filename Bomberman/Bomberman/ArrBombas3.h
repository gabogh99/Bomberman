#ifndef __ARRBOMBAS3_H__
#define __ARRBOMBAS3_H__



#include "Bomba3.h"
#include <vector>
using namespace std;

/// <summary>
/// Clase que crea un arreglo de bombas
/// </summary>

class CArrBombas3
{
public:

	//Se inicializa el objeto y se le permite solamente lanzar una bomba 

	CArrBombas3() { totalBombas3 = rand() % 6 + 1; }



	~CArrBombas3() {}

	/// <summary>
	/// M�todo para crear una bomba
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>

	void crear_una_bomba2(int x, int y) {

		if (arregloBombas3.size() < totalBombas3) { //Valida si el array es menor a la cantida de bombas
			CBomba3* nueva_bomba = new CBomba3(x, y); // Se crea un objeto bomba
			arregloBombas3.push_back(nueva_bomba); // Se a�ade la bomba al final del array de bombas
		}
	}

	/// <summary>
	/// M�todo para dibujar una bomba
	/// </summary>
	/// <param name="g"></param>
	/// <param name="bmpBomba"></param>
	/// <param name="bmpExplosion"></param>
	/// <param name="xJugador"></param>
	/// <param name="yJugador"></param>
	/// <param name="matriz"></param>

	void Dibujar_una_bomba(Graphics^ g, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, int xJugador, int yJugador, int** matriz) {

		for (int i = 0; i < arregloBombas3.size(); i++) //Se recorre el array de bombas
		{
			switch (arregloBombas3.at(i)->getEstado()) // Se hace un switch para validar los estados
			{

			case Estado3::normal3:
				arregloBombas3.at(i)->dibujarBomba(g, bmpBomba, xJugador, yJugador, matriz); //Si el estado es normal, se dibuja una bomba con el bmp de la bomba normal
				arregloBombas3.at(i)->animar(); //Se realiza la animaci�n de la posici�n i del array
				break;

			case Estado3::explosion3:
				arregloBombas3.at(i)->DibujarExplosion(g, bmpExplosion, matriz); //Si el estado es de explosion se dibuja con el bmp de la explosion antes definida
				arregloBombas3.at(i)->animarExplosion();//Se realiza la animaci�n
				break;

			case Estado3::desaparecer3:
				arregloBombas3.erase(arregloBombas3.begin() + i);//Si el estado es desaparecer se borra la bomba del array y se cambia de posici�n
				break;

			default:
				break;
			}
		}

	}

	/// <summary>
	/// M�todo que retorna el array de bombas
	/// </summary>
	/// <returns></returns>
	vector<CBomba3*>getarregloBombas() {
		return arregloBombas3;
	}

	/// <summary>
	/// M�todo para determinar la cantidad de bombas
	/// </summary>
	/// <param name="v"></param>
	void setBombas(int v) {
		totalBombas3 = v;
	}

	/// <summary>
	/// M�todo para retornar la cantidad de bombas
	/// </summary>
	/// <returns></returns>
	int getBombas() {
		return totalBombas3;
	}

	/// <summary>
	/// Se definen los atributos de la clase
	/// </summary>

private:
	vector<CBomba3*>arregloBombas3;
	int totalBombas3;


};



#endif // !__ARRBOMBAS3_H__