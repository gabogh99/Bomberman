#ifndef __CONTROLADORA_H__
#define __CONTROLADORA_H__
#include "Escenario.h"

class CControladora {

public:

	CControladora() {

		oEscenario = new CEscenario();

	}

	~CControladora() {}

	void CambiarNivel() {

		oEscenario->generarMatriz();

	}

	void dibujar(Graphics^ g, Bitmap^ bmpBase, Bitmap^ bmpSolido, Bitmap^ bmpDestruible) {

		oEscenario->PintarBase(g, bmpBase);
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);

	}

private:

	CEscenario* oEscenario;

};





#endif // !__CONTROLADORA_H__

