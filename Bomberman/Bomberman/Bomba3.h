#ifndef __BOMBA3_H__
#define __BOMBA3_H__
using namespace System::Drawing;

/// <summary>
/// Clase que crea y dibuja las bombas
/// </summary>

enum Estado3 { normal3, explosion3, desaparecer3 }; // Se crean estado para la animacion de la bomba

class CBomba3
{
public:
	/// <summary>
	/// Se inicializa la bomba
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>


	CBomba3(int x, int y) {

		this->x = x;
		this->y = y;
		estado3 = Estado3::normal3; //Se inicializa el estado en normal, como está al colocarla

		ancho = 66 / 3; //Ancho de sprites entre cantidad de animaciones
		alto = 24; //Alto de sprites

		indiceX = 0;
		tiempo_antes_de_explotar = 0; //Tiempo de explosion incializado en 0



	//Datos Iniciales para la explosion de la bomba

		indiceEX = 0;
		indiceEY = 0;

		altoExplosion = 160 / 8; //Ancho de sprites entre cantidad de animaciones
		anchoExplosion = 80 / 4; //Alto de sprites


	}
	~CBomba3() {}

	/// <summary>
	/// Método que define el áera que ocupa la bomba
	/// </summary>
	/// <returns></returns>
	Rectangle getRectangulo() {
		return Rectangle(x, y, 40, 40);
	}
	/// <summary>
	/// Función para validar si el lugar donde se desea poner una bomba es apto
	/// </summary>
	/// <param name="xJugador"></param>
	/// <param name="yJugador"></param>
	/// <param name="matriz"></param>
	/// <returns></returns>
	bool validarLugar(int xJugador3, int yJugador3, int** matriz) {

		if (matriz[yJugador3 / 50][xJugador3 / 50] == 0 || matriz[yJugador3 / 50][xJugador3 / 50] == 2) //Valida con los valores dados de la matriz si se puede colocar la bomba
			return true;
		else
			return false; //Para los casos donde haya bloques fijos no se pueden colocar

	}
	/// <summary>
	/// Método para dibujar la bomba antes de explotar
	/// </summary>
	/// <param name="g"></param>
	/// <param name="bmpBomba"></param>
	/// <param name="xJugador"></param>
	/// <param name="yJugador"></param>
	/// <param name="matriz"></param>
	void dibujarBomba(Graphics^ g, Bitmap^ bmpBomba2, int xJugador3, int yJugador3, int** matriz) {

		if (validarLugar(xJugador3, yJugador3, matriz) == true) { //Determina si la validación anterior es verdadera

			Rectangle porcionAUsar = Rectangle(indiceX * ancho, 0, ancho, alto); ///Se define el espacio a utilizar de los sprites
			Rectangle aumento = Rectangle(x, y, 40, 40);
			g->DrawImage(bmpBomba2, aumento, porcionAUsar, GraphicsUnit::Pixel); //Se dibuja la bomba normal con su bmp
		}



		if (tiempo_antes_de_explotar == 6) { estado3 = Estado3::explosion3; }//Cuando el tiempo de explosion llega a 6, el estado cambia a explosion
	}

	/// <summary>
	/// Método para realizar la animación de la bomba
	/// </summary>
	void animar() {

		if (indiceX >= 0 && indiceX < 2) //Se recorre los sprites y se cambian para animarlo
			indiceX++;
		else {
			tiempo_antes_de_explotar++;//A medida que se actualizan los sprites, el tiempo de explosion aumenta
			indiceX = 0;
		}
	}

	void DibujarExplosion(Graphics^ g, Bitmap^ bmpExplosionCentro, int** matriz) {

		Rectangle porcionUsarCentro = Rectangle(indiceEX * anchoExplosion, indiceEY * altoExplosion, anchoExplosion, altoExplosion); // indiceY=0
		Rectangle centro = Rectangle(x, y, 50, 50);
		g->DrawImage(bmpExplosionCentro, centro, porcionUsarCentro, GraphicsUnit::Pixel);
		if (matriz[y / 50][(x - 50) / 50] != 1) {
			Rectangle porcionUsarIzquierda = Rectangle(indiceEX * anchoExplosion, indiceEY + 2 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 2
			Rectangle izquierda = Rectangle(x - 50, y, 50, 50);
			g->DrawImage(bmpExplosionCentro, izquierda, porcionUsarIzquierda, GraphicsUnit::Pixel);

			if (matriz[y / 50][(x - 50) / 50] == 3) { matriz[y / 50][(x - 50) / 50] = 2; }
		}


		if (matriz[y / 50][(x + 50) / 50] != 1) {
			Rectangle porcionUsarDerecha = Rectangle(indiceEX * anchoExplosion, indiceEY + 4 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 4
			Rectangle derecha = Rectangle(x + 50, y, 50, 50);
			g->DrawImage(bmpExplosionCentro, derecha, porcionUsarDerecha, GraphicsUnit::Pixel);

			if (matriz[y / 50][(x + 50) / 50] == 3) { matriz[y / 50][(x + 50) / 50] = 2; }

		}
		if (matriz[y / 50][(x + 50) / 50] != 1) {
			Rectangle porcionUsarPuntaDerecha = Rectangle(indiceEX * anchoExplosion, indiceEY + 3 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 3
			Rectangle Puntaderecha = Rectangle(x + 100, y, 50, 50);
			g->DrawImage(bmpExplosionCentro, Puntaderecha, porcionUsarPuntaDerecha, GraphicsUnit::Pixel);

			if (matriz[y / 50][(x + 100) / 50] == 3 && matriz[y / 50][(x + 50) / 50] != 1)
			{

				matriz[y / 50][(x + 100) / 50] = 2;
			}
		}

		if (matriz[y / 50][(x - 50) / 50] != 1) {
			Rectangle porcionUsarPuntaIzquierda = Rectangle(indiceEX * anchoExplosion, indiceEY + 1 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 1
			Rectangle Puntaizquierda = Rectangle(x - 100, y, 50, 50);
			g->DrawImage(bmpExplosionCentro, Puntaizquierda, porcionUsarPuntaIzquierda, GraphicsUnit::Pixel);

			if (matriz[y / 50][(x - 100) / 50] == 3 && matriz[y / 50][(x - 50) / 50] != 1)
			{
				matriz[y / 50][(x - 100) / 50] = 2;
			}
		}

		Rectangle porcionUsarVerticales = Rectangle(indiceEX * anchoExplosion, indiceEY + 6 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 1
		Rectangle VerticalSuperior = Rectangle(x, y - 50, 50, 50);
		Rectangle VerticalInferior = Rectangle(x, y + 50, 50, 50);

		if (matriz[(y - 50) / 50][x / 50] != 1) { g->DrawImage(bmpExplosionCentro, VerticalSuperior, porcionUsarVerticales, GraphicsUnit::Pixel); }
		if (matriz[(y - 50) / 50][x / 50] == 3) { matriz[(y - 50) / 50][x / 50] = 2; }
		if (matriz[(y + 50) / 50][x / 50] != 1) { g->DrawImage(bmpExplosionCentro, VerticalInferior, porcionUsarVerticales, GraphicsUnit::Pixel); }
		if (matriz[(y + 50) / 50][x / 50] == 3) { matriz[(y + 50) / 50][x / 50] = 2; }


		if (matriz[(y - 50) / 50][x / 50] != 1) {
			Rectangle porcionUsarPuntaSuperior = Rectangle(indiceEX * anchoExplosion, indiceEY + 5 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 5
			Rectangle PuntaSuperior = Rectangle(x, y - 100, 50, 50);
			g->DrawImage(bmpExplosionCentro, PuntaSuperior, porcionUsarPuntaSuperior, GraphicsUnit::Pixel);

			if (matriz[(y - 100) / 50][x / 50] == 3 && matriz[(y - 50) / 50][x / 50] != 1) { matriz[(y - 100) / 50][x / 50] = 2; }
		}


		if (matriz[(y + 50) / 50][x / 50] != 1) {
			Rectangle porcionUsarPuntaInferior = Rectangle(indiceEX * anchoExplosion, indiceEY + 7 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 7
			Rectangle PuntaInferior = Rectangle(x, y + 100, 50, 50);
			g->DrawImage(bmpExplosionCentro, PuntaInferior, porcionUsarPuntaInferior, GraphicsUnit::Pixel);
			if (matriz[(y + 100) / 50][x / 50] == 3 && matriz[(y + 50) / 50][x / 50] != 1) {
				matriz[(y + 100) / 50][x / 50] = 2;
			}
		}
	}

	void animarExplosion() {

		if (indiceEX >= 0 && indiceEX < 3)//Se recorre los sprites y se cambian para animarlo
			indiceEX++;
		else
		{
			estado3 = Estado3::desaparecer3;//Luego de la explosion se pasa al estado desaparecer
		}
	}

	/// <summary>
	/// Método get para obtener el estado
	/// </summary>
	/// <returns></returns>

	Estado3 getEstado() {
		return estado3;
	}

	/// <summary>
	/// Método get para obtener el x
	/// </summary>
	/// <returns>x</returns>
	int getX() {
		return x;
	}

	/// <summary>
/// Método get para obtener el y
/// </summary>
/// <returns>y</returns>

	int getY() {
		return y;
	}
	/// <summary>
	/// Método para definir el x 
	/// </summary>
	/// <param name="v"></param>
	void setx(int v) {
		x = v;
	}
	/// <summary>
	/// Método para definir el y 
	/// </summary>
	/// <param name="v"></param>
	void sety(int v) {
		y = v;
	}
	/// <summary>
	/// Método para definir el tiempo antes de explotar
	/// </summary>
	/// <param name="v"></param>
	void settiempo(int v) {
		tiempo_antes_de_explotar = v;
	}

private: //Datos definidos de la explosion

	int indiceEX;
	int indiceEY;

	int altoExplosion;
	int anchoExplosion;



private:  //Datos definidos de la bomba

	int x;
	int y;
	int ancho;
	int alto;
	int indiceX;

	int tiempo_antes_de_explotar;

	Estado3 estado3;

};

#endif // !__BOMBA3_H__