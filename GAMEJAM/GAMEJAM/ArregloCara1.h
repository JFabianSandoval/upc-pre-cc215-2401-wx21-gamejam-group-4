#pragma once
#include "Cara1.h"


class ArregloCara1 {


private :
	int aN;

	Cara1** avecCara1;
	

public :
	ArregloCara1(void);
	void Agregar(int pPosX, int pPosy);
	void mover(System::Drawing::Graphics^ pCanvas);
	void moverRebote1(System::Drawing::Graphics^ pCanvas);
	~ArregloCara1(void);
};

ArregloCara1::ArregloCara1(void) {
	aN = 0;
	avecCara1 = new Cara1 * [aN];
	
}

void ArregloCara1::Agregar(int pPosX, int pPosY) {
	System::Random^ r = gcnew System::Random();
	Cara1** oTemp = new Cara1 * [aN + 1];
	
	for (int i = 0; i < aN; i++)
		oTemp[i] = avecCara1[i];
	    
	oTemp[aN] = new Cara1(40, 100, r->Next(5, 13), r->Next(1, 4), r->Next(7, 7), 0, aN);
	aN++;
	
	if (avecCara1 != nullptr)
		delete[] avecCara1;
	avecCara1 = oTemp;
	
}
void ArregloCara1::mover(System::Drawing::Graphics^ pCanvas) {
	for (int i = 0; i < aN; i++)
	{
		avecCara1[i]->Mover(pCanvas);
		avecCara1[i]->Dibujar(pCanvas);
		
		
	}
}
void ArregloCara1::moverRebote1(System::Drawing::Graphics^ pCanvas) {
	for (int i = 0; i < aN; i++)
	{
		avecCara1[i]->MoverRebote(pCanvas);
		avecCara1[i]->Dibujar(pCanvas);


	}
}