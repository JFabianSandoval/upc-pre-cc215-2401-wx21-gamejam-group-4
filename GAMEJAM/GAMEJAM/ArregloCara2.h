#pragma once
#pragma once
#include "Cara2.h"


class ArregloCara2 {


private:
	int aN;

	Cara2** avecCara2;


public:
	ArregloCara2(void);
	void Agregar(int pPosX, int pPosy);
	void mover(System::Drawing::Graphics^ pCanvas);
	void moverRebote2(System::Drawing::Graphics^ pCanvas);
	~ArregloCara2(void);
};

ArregloCara2::ArregloCara2(void) {
	aN = 0;
	avecCara2 = new Cara2 * [aN];

}

void ArregloCara2::Agregar(int pPosX, int pPosY) {
	System::Random^ r = gcnew System::Random();
	Cara2** oTemp = new Cara2 * [aN + 1];

	for (int i = 0; i < aN; i++)
		oTemp[i] = avecCara2[i];

	oTemp[aN] = new Cara2(40, 200, r->Next(5, 14), r->Next(1, 4), r->Next(7, 7), 0, aN);
	aN++;

	if (avecCara2 != nullptr)
		delete[] avecCara2;
	avecCara2 = oTemp;

}
void ArregloCara2::mover(System::Drawing::Graphics^ pCanvas) {
	for (int i = 0; i < aN; i++)
	{
		avecCara2[i]->Mover(pCanvas);
		avecCara2[i]->Dibujar(pCanvas);


	}
}
void ArregloCara2::moverRebote2(System::Drawing::Graphics^ pCanvas) {
	for (int i = 0; i < aN; i++)
	{
		avecCara2[i]->MoverRebote(pCanvas);
		avecCara2[i]->Dibujar(pCanvas);


	}
}