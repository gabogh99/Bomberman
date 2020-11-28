#ifndef __ARRMEJORAS_H__
#define __ARRMEJORAS_H__
#include <vector>
#include "Mejora.h"
using namespace std;

class CArrMejoras
{
public:
	CArrMejoras() {}
	~CArrMejoras() {}

	void crearMejoras() {

		CMejora* nueva_mejora = new CMejora();
		vector_mejoras.push_back(nueva_mejora);
	}

	void dibujar(Graphics^g, Bitmap^bmpMejoras, int **matriz) {

		for (int i = 0; i < vector_mejoras.size(); i++)
		{
			vector_mejoras.at(i)->dibujar(g, bmpMejoras, matriz);
			vector_mejoras.at(i)->animar();
		}

	}

	vector<CMejora*>getvector_mejoras() {
		return vector_mejoras;
	}

private:
	vector<CMejora*>vector_mejoras;
};








#endif // !__ARRMEJORAS_H__

