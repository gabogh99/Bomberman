#ifndef __ARRBOMBAS_H__
#define __ARRBOMBAS_H__



#include "Bomba.h"
#include <vector>
using namespace std;

/// <summary>
/// Clase que crea un arreglo de bombas
/// </summary>

class CArrBombas
{
public:

	//Se inicializa el objeto y se le permite solamente lanzar una bomba 

	CArrBombas() { totalBombas = 1; }



	~CArrBombas(){}

	/// <summary>
	/// Método para crear una bomba
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>

	void crear_una_bomba(int x, int y) {

		if (arregloBombas.size() < totalBombas) { //Valida si el array es menor a la cantida de bombas
			CBomba* nueva_bomba = new CBomba(x, y); // Se crea un objeto bomba
			arregloBombas.push_back(nueva_bomba); // Se añade la bomba al final del array de bombas
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

	void Dibujar_una_bomba(Graphics^g, Bitmap^bmpBomba, Bitmap^bmpExplosion, int xJugador, int yJugador,int **matriz ){
	
		for (int i = 0; i < arregloBombas.size(); i++) //Se recorre el array de bombas
		{
			switch (arregloBombas.at(i)->getEstado() ) // Se hace un switch para validar los estados
			{

			case Estado::normal:
				arregloBombas.at(i)->dibujarBomba(g, bmpBomba, xJugador, yJugador, matriz); //Si el estado es normal, se dibuja una bomba con el bmp de la bomba normal
				arregloBombas.at(i)->animar(); //Se realiza la animación de la posición i del array
				break;

			case Estado::explosion:
				arregloBombas.at(i)->DibujarExplosion(g, bmpExplosion, matriz); //Si el estado es de explosion se dibuja con el bmp de la explosion antes definida
				arregloBombas.at(i)->animarExplosion();//Se realiza la animación
				break;

			case Estado::desaparecer: 
				arregloBombas.erase(arregloBombas.begin() + i);//Si el estado es desaparecer se borra la bomba del array y se cambia de posición
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
	vector<CBomba*>getarregloBombas() {
		return arregloBombas;
	}

	/// <summary>
	/// Método para determinar la cantidad de bombas
	/// </summary>
	/// <param name="v"></param>
	void setBombas(int v) {
		totalBombas = v;
	}

	/// <summary>
	/// Método para retornar la cantidad de bombas
	/// </summary>
	/// <returns></returns>
	int getBombas() {
		return totalBombas;
	}

/// <summary>
/// Se definen los atributos de la clase
/// </summary>

private:
	vector<CBomba*>arregloBombas;
	int totalBombas;


};



#endif // !__ARRBOMBAS_H__

