#pragma once

#include "ArregloCara1.h"
#include "ArregloCara2.h"
#include "ArregloCara3.h"
namespace GAMEJAM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Carrera
	/// </summary>
	public ref class Carrera : public System::Windows::Forms::Form
	{
	public:
		Carrera(void)
		{
			srand(time(NULL));
			InitializeComponent();
			counter = 0;
			//
			//TODO: agregar c digo de constructor aqu 
			//
		}
	private: System::Windows::Forms::Timer^ timer2;
	public:

	protected:
		int counter;
		/// <summary>
		/// Limpiar los recursos que se est n usando.
		/// </summary>
		~Carrera()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del dise ador necesaria.
		/// </summary>
		ArregloCara1* ovecCara1;
		ArregloCara2* ovecCara2;
		ArregloCara3* ovecCara3;
		//ArregloCara1* ovecCara3;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M todo necesario para admitir el Dise ador. No se puede modificar
		/// el contenido de este m todo con el editor de c digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;

			this->timer1->Tick += gcnew System::EventHandler(this, &Carrera::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"CRON METRO";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(169, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(14, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"0";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &Carrera::timer2_Tick);			// 
			// Carrera
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(900, 542);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Carrera";
			this->Text = L"Carrera";
			this->Shown += gcnew System::EventHandler(this, &Carrera::Carrera_Shown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Carrera::Carrera_MouseClick);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ canvas = this->CreateGraphics();
		canvas->Clear(Color::SkyBlue);
		ovecCara1->mover(canvas);
		ovecCara2->mover(canvas);
		ovecCara3->mover(canvas);
		label2->Text = Convert::ToString(counter);
		counter++;

	}
	private: System::Void Carrera_Shown(System::Object^ sender, System::EventArgs^ e) {
		ovecCara1 = new ArregloCara1();
		ovecCara2 = new ArregloCara2();
		ovecCara3 = new ArregloCara3();

	}

	private: System::Void Carrera_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		ovecCara1->Agregar(e->X, e->Y);
		ovecCara2->Agregar(e->X, e->Y);
		ovecCara3->Agregar(e->X, e->Y);
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		counter++;
	}
	};

}

