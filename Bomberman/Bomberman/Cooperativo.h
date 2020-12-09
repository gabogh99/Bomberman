#include "Controladora3.h"
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
	public ref class Cooperativo : public System::Windows::Forms::Form
	{


	private:
		SoundPlayer^ MusicaN;

		CControladora3* oControladora3; //Se crea el objeto Controladora

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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
		   Bitmap^ bmpJugador4 = gcnew Bitmap("Imagenes\\Jugador4.png");


	public:
		Cooperativo(void)
		{


			InitializeComponent(); //Se inicializa el juego

			oControladora3 = new CControladora3(); //Se crea el objeto Controladora

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
		~Cooperativo()
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
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbNivel = (gcnew System::Windows::Forms::Label());
			this->pbCarga = (gcnew System::Windows::Forms::ProgressBar());
			this->trCarga = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Cooperativo::timer1_Tick);
			// 
			// lbNivel
			// 
			this->lbNivel->AutoSize = true;
			this->lbNivel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbNivel->ForeColor = System::Drawing::Color::White;
			this->lbNivel->Location = System::Drawing::Point(333, 232);
			this->lbNivel->Name = L"lbNivel";
			this->lbNivel->Size = System::Drawing::Size(155, 29);
			this->lbNivel->TabIndex = 0;
			this->lbNivel->Text = L"Cooperativo";
			// 
			// pbCarga
			// 
			this->pbCarga->Location = System::Drawing::Point(327, 316);
			this->pbCarga->Name = L"pbCarga";
			this->pbCarga->Size = System::Drawing::Size(161, 23);
			this->pbCarga->TabIndex = 1;
			// 
			// trCarga
			// 
			this->trCarga->Enabled = true;
			this->trCarga->Interval = 2500;
			this->trCarga->Tick += gcnew System::EventHandler(this, &Cooperativo::trCarga_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DarkOrange;
			this->label1->Location = System::Drawing::Point(206, 410);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(389, 29);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Equipo 1: Jugador 1 y Jugador 3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->label2->Location = System::Drawing::Point(206, 527);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(389, 29);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Equipo 2: Jugador 2 y Jugador 4";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(382, 472);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 29);
			this->label3->TabIndex = 4;
			this->label3->Text = L"VS";
			// 
			// Cooperativo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(849, 750);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pbCarga);
			this->Controls->Add(this->lbNivel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Cooperativo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Juego";
			this->Load += gcnew System::EventHandler(this, &Cooperativo::Juego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Cooperativo::Juego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Cooperativo::UltimaTeclaPresionada);
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
		oControladora3->dibujar(buffer->Graphics, bmpSuelo, bmpDestruible, bmpSolido, bmpJugador, bmpBomba, bmpExplosion, bmpMejoras, bmpJugador2, bmpJugador3, bmpJugador4); //Se dibujan los bmp y se vuelven visuales en la ventana
		this->Text = "              Vidas equipo 1: " + oControladora3->getoJugador()->getVidas() + oControladora3->getoJugador3()->getVidas() + "                        Vidas equipo 2: " + oControladora3->getoJugador2()->getVidas() +  oControladora3->getoJugador4()->getVidas(); //Muestra la cantidad de vidas
		if ((oControladora3->getoJugador2()->getVidas() + oControladora3->getoJugador4()->getVidas()) == 0) {
			this->Text = "																											Game Over:		Winners Equipo 1";
			_sleep(3000);
			oControladora3->getoJugador4()->setVidas(rand() % 6 + 5);
			oControladora3->getoJugador2()->setVidas(rand() % 6 + 5);
			oControladora3->getoJugador3()->setVidas(rand() % 6 + 5);
			oControladora3->getoJugador()->setVidas(rand() % 6 + 5);

			oControladora3->getoJugador()->setX(50);
			oControladora3->getoJugador()->setY(50);

			reiniciar();
		}

		if ((oControladora3->getoJugador()->getVidas() + oControladora3->getoJugador3()->getVidas()) == 0) {
			this->Text = "																										Game Over:			Winners Equipo 2                             ";
			_sleep(3000);
			oControladora3->getoJugador4()->setVidas(rand() % 6 + 5);
			oControladora3->getoJugador2()->setVidas(rand() % 6 + 5);
			oControladora3->getoJugador3()->setVidas(rand() % 6 + 5);
			oControladora3->getoJugador()->setVidas(rand() % 6 + 5);
			oControladora3->getoJugador()->setX(50);
			oControladora3->getoJugador()->setY(50);
			reiniciar();
		}



		buffer->Render(g);
		delete buffer, espacio, g;

	}


		   void reiniciar() {

			   oControladora3->CambiarNivel();
			   Graphics^ g = this->CreateGraphics();
			   BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
			   BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
			   oControladora3->dibujar(buffer->Graphics, bmpSuelo, bmpDestruible, bmpSolido, bmpJugador, bmpBomba, bmpExplosion, bmpMejoras, bmpJugador2, bmpJugador3, bmpJugador4); //Se dibujan los bmp y se vuelven visuales en la ventana

			   oControladora3->getoJugador2()->setX(750);
			   oControladora3->getoJugador2()->setY(20);
			   oControladora3->getoJugador3()->setX(750);
			   oControladora3->getoJugador3()->setY(620);
			   oControladora3->getoJugador4()->setX(50);
			   oControladora3->getoJugador4()->setY(600);

		   }

		   /// <summary>
		   /// Se carga el juego mostrando la barra de carga y el nivel actual
		   /// </summary>
		   /// <param name="sender"></param>
		   /// <param name="e"></param>
		   /// <returns></returns>
	private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e) {
		lbNivel->Text = "Cooperativo";
		oControladora3->CambiarNivel();
	}
	private: System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) { //Validacion de los controles del teclado

		switch (e->KeyCode)
		{

			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case Keys::Up:

			oControladora3->getoJugador()->setDireccion(Direcciones::Arriba); //Cuando la tecla Up es tecleada realiza las funciones de la direccion arriba definida para el jugador
			break;

		case Keys::W:

			oControladora3->getoJugador3()->setDireccion(Direcciones3::Arriba3); //Cuando la tecla Up es tecleada realiza las funciones de la direccion arriba definida para el jugador
			break;

			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		case Keys::Down:

			oControladora3->getoJugador()->setDireccion(Direcciones::Abajo);//Cuando la tecla Down es tecleada realiza las funciones de la direccion abajo definida para el jugador

			break;

		case Keys::S:

			oControladora3->getoJugador3()->setDireccion(Direcciones3::Abajo3);//Cuando la tecla Down es tecleada realiza las funciones de la direccion abajo definida para el jugador

			break;


			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		case Keys::Left:

			oControladora3->getoJugador()->setDireccion(Direcciones::Izquierda);//Cuando la tecla Left es tecleada realiza las funciones de la direccion izquierda definida para el jugador
			break;

		case Keys::A:

			oControladora3->getoJugador3()->setDireccion(Direcciones3::Izquierda3);//Cuando la tecla Left es tecleada realiza las funciones de la direccion izquierda definida para el jugador
			break;

			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		case Keys::Right:

			oControladora3->getoJugador()->setDireccion(Direcciones::Derecha);//Cuando la tecla Right es tecleada realiza las funciones de la direccion derecha definida para el jugador
			break;

		case Keys::D:

			oControladora3->getoJugador3()->setDireccion(Direcciones3::Derecha3);//Cuando la tecla Left es tecleada realiza las funciones de la direccion izquierda definida para el jugador
			break;


		default:
			break;
		}

	}
	private: System::Void UltimaTeclaPresionada(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		switch (e->KeyCode)
		{
		case Keys::Space:
			oControladora3->agregarBomba(); // Cuando la tecla presionada es Space llama al metodo agregar bomba

			break;

		case Keys::Q:
			oControladora3->agregarBomba3();

		default:
			oControladora3->getoJugador()->setDireccion(Direcciones::Ninguna); //Si no se presiona ninguna tecla el jugadore se detiene
			oControladora3->getoJugador3()->setDireccion(Direcciones3::Ninguna3); //Si no se presiona ninguna tecla el jugadore se detiene
			break;
		}



	}




		   /// <summary>
		   /// Se crea el timer de carga
		   /// </summary>

	private: System::Void trCarga_Tick(System::Object^ sender, System::EventArgs^ e) {
		lbNivel->Text = "Cooperativo"; //Se cambia el texto en el label según el nivel
		pbCarga->Increment(10); //Incrementa el progessBar de carga
		if (trCarga->Interval == 2500 && oControladora3->getoArrMejoras()->getvector_mejoras().size() < oControladora3->getNivel())
		{
			oControladora3->crear_enemigos_y_mejoras(); //Se crean los enemigos y mejoras
		}


		else { //Al hacerse falso el timer de carga, se hace verdadero el timer 1 del juego y los labels y progressBar se deshabilitan.
			trCarga->Enabled = false;
			timer1->Enabled = true;
			//MusicaNivel();
			lbNivel->Visible = false;
			lbNivel->Enabled = false;
			pbCarga->Visible = false;
			pbCarga->Enabled = false;
			label1->Visible = false;
			label2->Visible = false;
			label3->Visible = false;



		}


	}


};
}