#pragma once

#include "Cara3.h"


class ArregloCara3 {


private:
	int aN;

	Cara3** avecCara3;


public:
	ArregloCara3(void);
	void Agregar(int pPosX, int pPosy);
	void mover(System::Drawing::Graphics^ pCanvas);
	void moverRebote3(System::Drawing::Graphics^ pCanvas);
	~ArregloCara3(void);
};

ArregloCara3::ArregloCara3(void) {
	aN = 0;
	avecCara3 = new Cara3 * [aN];

}

void ArregloCara3::Agregar(int pPosX, int pPosY) {
	System::Random^ r = gcnew System::Random();
	Cara3** oTemp = new Cara3 *  [aN + 1];

	for (int i = 0; i < aN; i++)
		oTemp[i] = avecCara3[i];

	oTemp[aN] = new Cara3 (40, 300, r->Next(5, 15), r->Next(1, 4), r->Next(7, 7), 0, aN);
	aN++;

	if (avecCara3 != nullptr)
		delete[] avecCara3;
	avecCara3 = oTemp;

}
void ArregloCara3::mover(System::Drawing::Graphics^ pCanvas) {
	for (int i = 0; i < aN; i++)
	{
		avecCara3[i]->Mover(pCanvas);
		avecCara3[i]->Dibujar(pCanvas);


	}
}
void ArregloCara3::moverRebote3(System::Drawing::Graphics^ pCanvas) {
	for (int i = 0; i < aN; i++)
	{
		avecCara3[i]->MoverRebote(pCanvas);
		avecCara3[i]->Dibujar(pCanvas);


	}
}