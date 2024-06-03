#pragma once
#include <iostream>
class Cara1 {
private:
	int x, y;
	int dx, dy;
	int color, indice;
	int R;

public:
	Cara1(int px, int py, int pdx, int pdy, int pR, int pColor, int pIndice);
	~Cara1();
	void Mover(System::Drawing::Graphics^ pCanvas);//un puntero que tendra el parametro canvas
	void Dibujar(System::Drawing::Graphics^ pCanvas);
	void MoverRebote(System::Drawing::Graphics^ pCanvas);
	

};

Cara1::Cara1(int pPosX, int pPosY, int pDesX, int pDesY, int pR, int pColor, int pIndice) {
	x = pPosX;
	y = pPosY;
	dx = pDesX;
	dy = pDesY;
	R = pR;
	color = pColor;
	indice = pIndice;


}

void Cara1::Mover(System::Drawing::Graphics^ pCanvas) {
	if ((x - R) + dx < 0 || (x + R) + dx > pCanvas->VisibleClipBounds.Width - 50)
		dx = 0;
	
	x += dx;

}

void Cara1::MoverRebote(System::Drawing::Graphics^ pCanvas) {
	if ((x - R) + dx < 0 || (x + R) + dx > pCanvas->VisibleClipBounds.Width - 50)
		dx *= -1;
	if ((y - R) + dy < 0 || (y + R) + dy > pCanvas->VisibleClipBounds.Height - 50)
		dy *= -1;
	x += dx;
	y += dy;
}


void Cara1::Dibujar(System::Drawing::Graphics^ pCanvas)
{

	pCanvas->FillEllipse(System::Drawing::Brushes::Red, x + 10, y - R, R * 8, R * 8);

	pCanvas->FillEllipse(System::Drawing::Brushes::Gray, x + 20, y, R * 2, R * 2);
	pCanvas->FillEllipse(System::Drawing::Brushes::Gray, x + 42, y, R * 2, R * 2);
	pCanvas->FillEllipse(System::Drawing::Brushes::Coral, x + 24, y+30, R * 4, R * 2);

}



Cara1::~Cara1(void) {

}