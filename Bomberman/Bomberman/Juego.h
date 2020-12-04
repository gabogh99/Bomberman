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
		Bitmap^ bmpEnemigo = gcnew Bitmap("Imagenes\\bmpEnemigo.png");

	public:
		Juego(void)
		{


			InitializeComponent(); //Se inicializa el juego

			oControladora = new CControladora(); //Se crea el objeto Controladora

			bmpJugador->MakeTransparent(bmpJugador->GetPixel(0, 0));
			bmpBomba->MakeTransparent(bmpBomba->GetPixel(0, 0));
			bmpExplosion->MakeTransparent(bmpExplosion->GetPixel(0, 0));
			bmpEnemigo->MakeTransparent(bmpEnemigo->GetPixel(0, 0));


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
			/// Se crean los componentes gr�ficos del juego
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
			this->lbNivel->Location = System::Drawing::Point(327, 233);
			this->lbNivel->Name = L"lbNivel";
			this->lbNivel->Size = System::Drawing::Size(80, 29);
			this->lbNivel->TabIndex = 0;
			this->lbNivel->Text = L"Nivel:";
			// 
			// Progress bar de carga del juego 
			// 
			this->pbCarga->Location = System::Drawing::Point(287, 315);
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
		/// M�todo que agrega musica al juego
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
		oControladora->dibujar(buffer->Graphics, bmpSuelo, bmpDestruible, bmpSolido, bmpJugador, bmpBomba, bmpExplosion, bmpMejoras, bmpEnemigo); //Se dibujan los bmp y se vuelven visuales en la ventana
		this->Text = "" + oControladora->getoJugador()->getVidas(); //Muestra la cantidad de vidas
		buffer->Render(g);
		delete buffer, espacio, g;

	}

	/// <summary>
	/// Se carga el juego mostrando la barra de carga y el nivel actual
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e) {
		lbNivel->Text = "Nivel: " + oControladora->getNivel();
		oControladora->CambiarNivel();
	}
	private: System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) { //Validacion de los controles del teclado

		switch (e->KeyCode)
		{

		case Keys::Up:

			oControladora->getoJugador()->setDireccion(Direcciones::Arriba); //Cuando la tecla Up es tecleada realiza las funciones de la direccion arriba definida para el jugador
			break;

		case Keys::Down:

			oControladora->getoJugador()->setDireccion(Direcciones::Abajo);//Cuando la tecla Down es tecleada realiza las funciones de la direccion abajo definida para el jugador
			break;

		case Keys::Left:

			oControladora->getoJugador()->setDireccion(Direcciones::Izquierda);//Cuando la tecla Left es tecleada realiza las funciones de la direccion izquierda definida para el jugador
			break;

		case Keys::Right:

			oControladora->getoJugador()->setDireccion(Direcciones::Derecha);//Cuando la tecla Right es tecleada realiza las funciones de la direccion derecha definida para el jugador
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




		default:

			oControladora->getoJugador()->setDireccion(Direcciones::Ninguna); //Si no se presiona ninguna tecla el jugadore se detiene
			break;
		}


	}

	/// <summary>
	/// Se crea el timer de carga
	/// </summary>

	private: System::Void trCarga_Tick(System::Object^ sender, System::EventArgs^ e) {
		lbNivel->Text = "Nivel: " + oControladora->getNivel(); //Se cambia el texto en el label seg�n el nivel
		pbCarga->Increment(10); //Incrementa el progessBar de carga
		if (trCarga->Interval == 2500 && oControladora->getoArrEnemigos()->getarregloEnemigos().size() < oControladora->getNivel()) {
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