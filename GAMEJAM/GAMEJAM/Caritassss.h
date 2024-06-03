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
	/// Resumen de Caritasss
	/// </summary>
	public ref class Caritasss : public System::Windows::Forms::Form
	{
	public:
		Caritasss(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Caritasss()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		ArregloCara1* oVecCara1;
		ArregloCara2* oVecCara2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Timer^ timer1;
		   ArregloCara3* oVecCara3;
	



#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			  

			   this->SuspendLayout();
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(25, 13);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(75, 23);
			   this->button1->TabIndex = 0;
			   this->button1->Text = L"Cara1";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Caritasss::button1_MouseClick);
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(148, 13);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(75, 23);
			   this->button2->TabIndex = 1;
			   this->button2->Text = L"Cara2";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Caritasss::button2_MouseClick);
			   // 
			   // button3
			   // 
			   this->button3->Location = System::Drawing::Point(276, 13);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(75, 23);
			   this->button3->TabIndex = 2;
			   this->button3->Text = L"Cara3";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Caritasss::button3_MouseClick);
			   // 
			   // button4
			   // 
			   this->button4->Location = System::Drawing::Point(630, 13);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(130, 23);
			   this->button4->TabIndex = 3;
			   this->button4->Text = L"Recuperar caras";
			   this->button4->UseVisualStyleBackColor = true;
			   this->button4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Caritasss::button4_MouseClick);
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Interval = 1;
			   this->timer1->Tick += gcnew System::EventHandler(this, &Caritasss::timer1_Tick);
			  
			   // 
			   // Caritasss
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(807, 540);
			   this->Controls->Add(this->button4);
			   this->Controls->Add(this->button3);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->button1);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"Caritasss";
			   this->Text = L"Caritasss";
			   this->Load += gcnew System::EventHandler(this, &Caritasss::Caritasss_Load);
			   this->ResumeLayout(false);

		   }
#pragma endregion
		   private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			   Graphics^ canvas2 = this->CreateGraphics();
			   canvas2->Clear(Color::Purple);
			   oVecCara1->moverRebote1(canvas2);
			   oVecCara2->moverRebote2(canvas2);
			   oVecCara3->moverRebote3(canvas2);
		   }
	private: System::Void Caritasss_Load(System::Object^ sender, System::EventArgs^ e) {
		oVecCara1 = new ArregloCara1();
		oVecCara2 = new ArregloCara2();
		oVecCara3 = new ArregloCara3();
	}
	private: System::Void button1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		oVecCara1->Agregar(e->X, e->Y);
		button1->Hide();
	}
	private: System::Void button2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		oVecCara2->Agregar(e->X, e->Y);
		button2->Hide();
	}
	private: System::Void button3_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		oVecCara3->Agregar(e->X, e->Y);
		button3->Hide();
	}
	private: System::Void button4_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		button1->Show();
		button2->Show();
		button3->Show();
	}
	
	};
}
