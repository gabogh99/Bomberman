#pragma once
#include "Controladora.h"

namespace Bomberman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Summary for Juego
	/// </summary>
	public ref class Juego : public System::Windows::Forms::Form
	{


	private:
		SoundPlayer^ MusicaN;

		CControladora* oControladora; //Se crea el objeto Controladora

		/// <summary>
		/// Se crean los bmps con las imagenes
		/// </summary>

		Bitmap^ bmpSuelo = gcnew Bitmap("Imagenes\\bmpSuelo.png");
		Bitmap^ bmpSolido = gcnew Bitmap("Imagenes\\bmpSolido.png");
		Bitmap^ bmpDestruible = gcnew Bitmap("Imagenes\\bmpDestruible.png");
		Bitmap^ bmpJugador = gcnew Bitmap("Imagenes\\Jugador.png");
		Bitmap^ bmpBomba = gcnew Bitmap("Imagenes\\bomba.png");
		Bitmap^ bmpExplosion = gcnew Bitmap("Imagenes\\explosion.png");
		Bitmap^ bmpMejoras = gcnew Bitmap("Imagenes\\mejoras.png");
		Bitmap^ bmpJugador2 = gcnew Bitmap("Imagenes\\Jugador2.png");
		Bitmap^ bmpJugador3 = gcnew Bitmap("Imagenes\\Jugador3.png");
		Bitmap^ bmpJugador4 = gcnew Bitmap("Imagenes\\Jugador4.png");


	public:
		Juego(void)
		{
			

				InitializeComponent(); //Se inicializa el juego

				oControladora = new CControladora(); //Se crea el objeto Controladora

				bmpJugador->MakeTransparent(bmpJugador->GetPixel(0, 0));
				bmpJugador2->MakeTransparent(bmpJugador2->GetPixel(0, 0));
				bmpJugador3->MakeTransparent(bmpJugador3->GetPixel(0, 0));
				bmpJugador4->MakeTransparent(bmpJugador4->GetPixel(0, 0));


				bmpBomba->MakeTransparent(bmpBomba->GetPixel(0, 0));
				bmpExplosion->MakeTransparent(bmpExplosion->GetPixel(0, 0));
				


				//
				//TODO: Add the constructor code here
				//
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Juego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lbNivel;
	private: System::Windows::Forms::ProgressBar^ pbCarga;
	private: System::Windows::Forms::Timer^ trCarga;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{

			/// <summary>
			/// Se crean los componentes gráficos del juego
			/// </summary>
			/// <param name=""></param>
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbNivel = (gcnew System::Windows::Forms::Label());
			this->pbCarga = (gcnew System::Windows::Forms::ProgressBar());
			this->trCarga = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1 para recargar los frames del juego
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Juego::timer1_Tick);
			// 
			// label para mostrar el nivel actual
			// 
			this->lbNivel->AutoSize = true;
			this->lbNivel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbNivel->ForeColor = System::Drawing::Color::White;
			this->lbNivel->Location = System::Drawing::Point(315, 231);
			this->lbNivel->Name = L"lbNivel";
			this->lbNivel->Size = System::Drawing::Size(80, 29);
			this->lbNivel->TabIndex = 0;
			this->lbNivel->Text = L"Multijugador";
			// 
			// Progress bar de carga del juego 
			// 
			this->pbCarga->Location = System::Drawing::Point(327, 315);
			this->pbCarga->Name = L"pbCarga";
			this->pbCarga->Size = System::Drawing::Size(161, 23);
			this->pbCarga->TabIndex = 1;
			// 
			// Timer para cargar el juego
			// 
			this->trCarga->Enabled = true;
			this->trCarga->Interval = 2500;
			this->trCarga->Tick += gcnew System::EventHandler(this, &Juego::trCarga_Tick);
			// 
			// Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(849, 750);
			this->Controls->Add(this->pbCarga);
			this->Controls->Add(this->lbNivel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Juego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Juego";
			this->Load += gcnew System::EventHandler(this, &Juego::Juego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::UltimaTeclaPresionada);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/// <summary>
		/// Método que agrega musica al juego
		/// </summary>

		//void MusicaNivel() {
			//MusicaN = gcnew SoundPlayer("Sonido\\ModoSolitario.wav");
		//MusicaN->PlayLooping();
		//}

	///Timer para refrescar los frames cada cierto tiempo	

private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		oControladora->dibujar(buffer->Graphics, bmpSuelo, bmpDestruible, bmpSolido, bmpJugador, bmpBomba, bmpExplosion, bmpMejoras, bmpJugador2, bmpJugador3, bmpJugador4); //Se dibujan los bmp y se vuelven visuales en la ventana

		if (oControladora->getoJugador()->getVidas() == 0 && oControladora->getoJugador2()->getVidas() == 0 && oControladora->getoJugador3()->getVidas() == 0 && oControladora->getoJugador4()->getVidas() != 0) {
			this->Text = "																													Game Over:  Winner Player 4";
			_sleep(3000);
			oControladora->getoJugador()->setVidas(rand()%6+5 );
			oControladora->getoJugador2()->setVidas(rand() % 6 + 5);
			oControladora->getoJugador3()->setVidas(rand() % 6 + 5);
			oControladora->getoJugador4()->setX(50);
			oControladora->getoJugador4()->setY(600);


			reiniciar();	
		}
		if (oControladora->getoJugador()->getVidas() == 0 && oControladora->getoJugador2()->getVidas() == 0 && oControladora->getoJugador4()->getVidas() == 0 && oControladora->getoJugador3()->getVidas() != 0) {
			this->Text = "																													Game Over:  Winner Player 3";
			_sleep(3000); //Sleep para mostrar ganador
			oControladora->getoJugador4()->setVidas(rand() % 5 + 5); //Genera otro numero random de vidas 
			oControladora->getoJugador2()->setVidas(rand() % 5 + 5);//Genera otro numero random de vidas 
			oControladora->getoJugador3()->setVidas(rand() % 5 + 5);//Genera otro numero random de vidas 
			oControladora->getoJugador()->setVidas(rand() % 5 + 5);//Genera otro numero random de vidas 

			oControladora->getoJugador3()->setX(50);
			oControladora->getoJugador3()->setY(600);
			reiniciar();//Se reinicia el juego	
		
		}

		if (oControladora->getoJugador()->getVidas() == 0 && oControladora->getoJugador4()->getVidas() == 0 && oControladora->getoJugador3()->getVidas() == 0 && oControladora->getoJugador2()->getVidas() != 0) {
			this->Text = "																													Game Over:  Winner Player 2";
			_sleep(3000); //Sleep para mostrar ganador
			oControladora->getoJugador4()->setVidas(rand() % 5 + 5); //Genera otro numero random de vidas 
			oControladora->getoJugador2()->setVidas(rand() % 5 + 5);//Genera otro numero random de vidas 
			oControladora->getoJugador3()->setVidas(rand() % 5 + 5);//Genera otro numero random de vidas 
			oControladora->getoJugador()->setVidas(rand() % 5 + 5);//Genera otro numero random de vidas 

			oControladora->getoJugador2()->setX(50);
			oControladora->getoJugador2()->setY(600);
			reiniciar();//Se reinicia el juego		

		}

		if (oControladora->getoJugador2()->getVidas() == 0 && oControladora->getoJugador4()->getVidas() == 0 && oControladora->getoJugador3()->getVidas() == 0 && oControladora->getoJugador()->getVidas() != 0) {
			this->Text = "																													Game Over:  Winner Player 1";
			_sleep(3000);
			_sleep(3000); //Sleep para mostrar ganador
			oControladora->getoJugador4()->setVidas(rand() % 5 + 5); //Genera otro numero random de vidas 
			oControladora->getoJugador2()->setVidas(rand() % 5 + 5);//Genera otro numero random de vidas 
			oControladora->getoJugador3()->setVidas(rand() % 5 + 5);//Genera otro numero random de vidas 
			oControladora->getoJugador()->setVidas(rand() % 5 + 5);//Genera otro numero random de vidas 

			oControladora->getoJugador()->setX(50);
			oControladora->getoJugador()->setY(600);

			reiniciar();//Se reinicia el juego		
		}
		else
		{
			this->Text = "              Vidas Jugador 1: " + oControladora->getoJugador()->getVidas() + "                        Vidas Jugador 2: " + oControladora->getoJugador2()->getVidas() + "                        Vidas Jugador 3: " + oControladora->getoJugador3()->getVidas() + "                    Vidas Jugador 4: " + oControladora->getoJugador4()->getVidas(); //Muestra la cantidad de vidas

		}
		
		buffer->Render(g);
		delete buffer, espacio, g;

	}
	   /// <summary>
		/// Método para reiniciar la partida una vez finalizada
		/// </summary>
	   void reiniciar() {

		   oControladora->CambiarNivel();
		   Graphics^ g = this->CreateGraphics();
		   BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		   BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		   oControladora->dibujar(buffer->Graphics, bmpSuelo, bmpDestruible, bmpSolido, bmpJugador, bmpBomba, bmpExplosion, bmpMejoras, bmpJugador2, bmpJugador3, bmpJugador4); //Se dibujan los bmp y se vuelven visuales en la ventana



	   }

	/// <summary>
	/// Se carga el juego mostrando la barra de carga y el nivel actual
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	public: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e) {
		lbNivel->Text = "MULTIJUGADOR " ;
		oControladora->CambiarNivel();
	}
	private: System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) { //Validacion de los controles del teclado

		switch (e->KeyCode)
		{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case Keys::Up:

			oControladora->getoJugador()->setDireccion(Direcciones::Arriba); //Cuando la tecla Up es tecleada realiza las funciones de la direccion arriba definida para el jugador
			break;

		case Keys::W:

			oControladora->getoJugador2()->setDireccion(Direcciones2::Arriba2); //Cuando la tecla Up es tecleada realiza las funciones de la direccion arriba definida para el jugador
			break;

		case Keys::I:

			oControladora->getoJugador3()->setDireccion(Direcciones3::Arriba3); //Cuando la tecla Up es tecleada realiza las funciones de la direccion arriba definida para el jugador
			break;

		case Keys:: X:

			oControladora->getoJugador4()->setDireccion(Direcciones4::Arriba4); //Cuando la tecla Up es tecleada realiza las funciones de la direccion arriba definida para el jugador
			break;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		case Keys::Down:

			oControladora->getoJugador()->setDireccion(Direcciones::Abajo);//Cuando la tecla Down es tecleada realiza las funciones de la direccion abajo definida para el jugador
			break;

		case Keys::S:

			oControladora->getoJugador2()->setDireccion(Direcciones2::Abajo2);//Cuando la tecla s es tecleada realiza las funciones de la direccion abajo definida para el jugador
			break;

		case Keys::K:

			oControladora->getoJugador3()->setDireccion(Direcciones3::Abajo3);//Cuando la tecla k es tecleada realiza las funciones de la direccion abajo definida para el jugador
			break;

		case Keys::C:

			oControladora->getoJugador4()->setDireccion(Direcciones4::Abajo4);//Cuando la tecla c es tecleada realiza las funciones de la direccion abajo definida para el jugador
			break;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		case Keys::Left:

			oControladora->getoJugador()->setDireccion(Direcciones::Izquierda);//Cuando la tecla Left es tecleada realiza las funciones de la direccion izquierda definida para el jugador
			break;

		case Keys::A:

			oControladora->getoJugador2()->setDireccion(Direcciones2::Izquierda2);//Cuando la a Left es tecleada realiza las funciones de la direccion izquierda definida para el jugador
			break;

		case Keys::J:

			oControladora->getoJugador3()->setDireccion(Direcciones3::Izquierda3);//Cuando la tecla j es tecleada realiza las funciones de la direccion izquierda definida para el jugador
			break;

		case Keys::Z:

			oControladora->getoJugador4()->setDireccion(Direcciones4::Izquierda4);//Cuando la tecla z es tecleada realiza las funciones de la direccion izquierda definida para el jugador
			break;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		case Keys::Right:

			oControladora->getoJugador()->setDireccion(Direcciones::Derecha);//Cuando la tecla Right es tecleada realiza las funciones de la direccion derecha definida para el jugador
			break;

		case Keys::D:

			oControladora->getoJugador2()->setDireccion(Direcciones2::Derecha2);//Cuando la tecla d es tecleada realiza las funciones de la direccion derecha definida para el jugador
			break;

		case Keys::L:

			oControladora->getoJugador3()->setDireccion(Direcciones3::Derecha3);//Cuando la tecla l es tecleada realiza las funciones de la direccion derecha definida para el jugador
			break;

		case Keys::V:

			oControladora->getoJugador4()->setDireccion(Direcciones4::Derecha4);//Cuando la tecla v es tecleada realiza las funciones de la direccion derecha definida para el jugador
			break;

		default:
			break;
		}

	}
	private: System::Void UltimaTeclaPresionada(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		switch (e->KeyCode)
		{

		case Keys::Space:
			oControladora->agregarBomba(); // Cuando la tecla presionada es Space llama al metodo agregar bomba

			break;

		case Keys::Q:
			oControladora->agregarBomba2(); // Cuando la tecla presionada es Q llama al metodo agregar bomba

			break;

		case Keys::U:
			oControladora->agregarBomba3(); // Cuando la tecla presionada es U llama al metodo agregar bomba

			break;

		case Keys::ShiftKey:
			oControladora->agregarBomba4(); // Cuando la tecla presionada es Shift llama al metodo agregar bomba

			break;


		default:

			oControladora->getoJugador()->setDireccion(Direcciones::Ninguna); //Si no se presiona ninguna tecla el jugadore se detiene
			oControladora->getoJugador2()->setDireccion(Direcciones2::Ninguna2);
			oControladora->getoJugador3()->setDireccion(Direcciones3::Ninguna3);
			oControladora->getoJugador4()->setDireccion(Direcciones4::Ninguna4);

			break;
		}


	}


	

	/// <summary>
	/// Se crea el timer de carga
	/// </summary>

	private: System::Void trCarga_Tick(System::Object^ sender, System::EventArgs^ e) {
		lbNivel->Text = "MULTIJUGADOR " ; //Se cambia el texto en el label según el nivel
		pbCarga->Increment(10); //Incrementa el progessBar de carga
		if (trCarga->Interval == 2500 && oControladora->getoArrMejoras()->getvector_mejoras().size() < oControladora->getNivel())
		{
			oControladora->crear_enemigos_y_mejoras(); //Se crean los enemigos y mejoras
		}
		

		else { //Al hacerse falso el timer de carga, se hace verdadero el timer 1 del juego y los labels y progressBar se deshabilitan.
			trCarga->Enabled = false;
			timer1->Enabled = true;
			//MusicaNivel();
			lbNivel->Visible = false;
			lbNivel->Enabled = false;
			pbCarga->Visible = false;
			pbCarga->Enabled = false;


		}


	}
	};
}