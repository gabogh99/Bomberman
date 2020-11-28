#pragma once
#include "Controladora.h"
namespace Bomberman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Juego
	/// </summary>
	public ref class Juego : public System::Windows::Forms::Form
	{
	public:

		CControladora* oControladora = new CControladora();

		Bitmap^ bmpSuelo = gcnew Bitmap("Imagenes\\bmpSuelo.png");
		Bitmap^ bmpSolido = gcnew Bitmap("Imagenes\\bmpSolido.png");
		Bitmap^ bmpDestruible = gcnew Bitmap("Imagenes\\bmpDestruible.png");
		Bitmap^ bmpJugador = gcnew Bitmap("Imagenes\\Jugador.png");
		Bitmap^ bmpBomba = gcnew Bitmap("Imagenes\\bomba.png");
		Bitmap^ bmpExplosion = gcnew Bitmap("Imagenes\\explosion.png");


		Juego(void)
		{
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(0, 0));
			InitializeComponent();
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
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Juego::timer1_Tick);
			// 
			// Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(849, 750);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Juego";
			this->Text = L"Juego";
			this->Load += gcnew System::EventHandler(this, &Juego::Juego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::UltimaTeclaPresionada);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);

		oControladora->dibujar(buffer->Graphics, bmpSuelo, bmpDestruible, bmpSolido, bmpJugador, bmpBomba,bmpExplosion );
		buffer->Render(g);
		delete buffer, espacio, g;

	}


	private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e) {

		oControladora->CambiarNivel();
	}
	private: System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		switch (e->KeyCode)
		{

		case Keys::Up:

			oControladora->getoJugador()->setDireccion(Direcciones::Arriba);
			break;

		case Keys::Down:

			oControladora->getoJugador()->setDireccion(Direcciones::Abajo);
			break;

		case Keys::Left:

			oControladora->getoJugador()->setDireccion(Direcciones::Izquierda);
			break;

		case Keys::Right:

			oControladora->getoJugador()->setDireccion(Direcciones::Derecha);
			break;

		default:
			break;
		}

	}
	private: System::Void UltimaTeclaPresionada(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		switch (e->KeyCode)
		{

		case Keys::Space:
				oControladora->agregarBomba();
				
				break;




		default:

			oControladora->getoJugador()->setDireccion(Direcciones::Ninguna);
			break;
		}


	}
};
}
