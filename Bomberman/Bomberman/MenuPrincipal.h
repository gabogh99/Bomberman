#pragma once
#include"Juego.h"
#include"Jugar.h"
#include "Cooperativo.h"

namespace Bomberman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Summary for MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{

		//Se crea el soundPlayer para la musica
	private:
	//	SoundPlayer^ Music;

	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}

		//Se inicializan los componentes del  menu principal
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:

	private: System::Windows::Forms::Button^ btnInstrucionesAparecer;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnJugar;
	private: System::Windows::Forms::Button^ btnCoop;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnInstrucionesAparecer = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->btnCoop = (gcnew System::Windows::Forms::Button());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 22);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(340, 208);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// btnInstrucionesAparecer
			// 
			this->btnInstrucionesAparecer->Location = System::Drawing::Point(145, 305);
			this->btnInstrucionesAparecer->Name = L"btnInstrucionesAparecer";
			this->btnInstrucionesAparecer->Size = System::Drawing::Size(91, 23);
			this->btnInstrucionesAparecer->TabIndex = 2;
			this->btnInstrucionesAparecer->Text = L"Jugar";
			this->btnInstrucionesAparecer->UseVisualStyleBackColor = true;
			this->btnInstrucionesAparecer->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnInstrucionesAparecer_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(539, 22);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(250, 250);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(548, 296);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(232, 127);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox3->TabIndex = 4;
			this->pictureBox3->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(631, 268);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 25);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Arriba";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(497, 320);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 25);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Izquierda";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(727, 320);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 25);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Derecha";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(631, 426);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 25);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Abajo";
			// 
			// btnJugar
			// 
			this->btnJugar->Location = System::Drawing::Point(145, 353);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(91, 23);
			this->btnJugar->TabIndex = 9;
			this->btnJugar->Text = L"Multijugador";
			this->btnJugar->UseVisualStyleBackColor = true;
			this->btnJugar->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnJugar_Click);
			//
			//btnCoop
			//
			this->btnCoop->Location = System::Drawing::Point(145, 400);
			this->btnCoop->Name = L"btnCoop";
			this->btnCoop->Size = System::Drawing::Size(91, 23);
			this->btnCoop->TabIndex = 10;
			this->btnCoop->Text = L"Cooperativo";
			this->btnCoop->UseVisualStyleBackColor = true;
			this->btnCoop->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnCoop_Click);
			
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(416, 472);
			this->Controls->Add(this->btnJugar);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnInstrucionesAparecer);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnCoop);
			this->Name = L"MenuPrincipal";
			this->Text = L"MenuPrincipal";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/// <summary>
		/// Método para reproducir musica del inicio en loop
		/// </summary>
		void Musica() {
			//Music = gcnew SoundPlayer("Sonido\\MusicaIntro.wav");
			//Music->PlayLooping();
		}

	/// <summary>
	/// Funcion del boton desaparecer instrucciones que hace la ventana pequeña
	/// </summary>
	private: System::Void btnInstruccionesDesaparecer_Click(System::Object^ sender, System::EventArgs^ e) {
	
		this->Width = 500;
	//	btnInstruccionesDesaparecer->Visible = false;
		btnInstrucionesAparecer->Visible = true;
	}


		   /// <summary>
		   /// Funcion del boton instrucciones que hace la ventana grande para ver las instrucciones
		   /// </summary>
private: System::Void btnInstrucionesAparecer_Click(System::Object^ sender, System::EventArgs^ e) {

	Jugar^ frame = gcnew Jugar();// Se crea el juego
	this->Visible = false;
	frame->Show();;
}

private: System::Void btnCoop_Click(System::Object^ sender, System::EventArgs^ e) {

	Cooperativo^ frame2 = gcnew Cooperativo();// Se crea el juego
	this->Visible = false;
	frame2->Show();;
}

/// <summary>
/// Boton jugar que inicia el juego
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>

private: System::Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e) {

	Juego^ frm = gcnew Juego();// Se crea el juego
	this->Visible = false;
	frm->Show();
	//Music->Stop(); //Se detiene la musica del menu

}

//Se carga el menú principal y la música que este tiene
private: System::Void MenuPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {

	Musica();

}
};
}
