#include <iostream>
#include <windows.h> // dung cho ham gotoxy
#include <cstdlib>
#include <conio.h>
using namespace std;
void gotoxy(int column, int line);

struct Point
{
	int x, y; // toa do
};

class CONRAN
{
private:
	Point A[100];
	int DoDai;
public:
	CONRAN() {
		DoDai = 3;
		A[0].x = 10; A[0].y = 10;
		A[1].x = 11; A[1].y = 10;
		A[2].x = 12; A[2].y = 10;
	}
	~CONRAN(){}
	void VeConRan()
	{
		for (int i = 0; i < DoDai; i++) 
		{
			gotoxy(A[i].x, A[i].y);
			cout << "X";
		}
	}
	void DiChuyen(int Huong)
	{
		for (int i = DoDai - 1; i > 0; i--)
			A[i] = A[i - 1];
		if (Huong == 0) A[0].x = A[0].x + 1;
		if (Huong == 1) A[0].y = A[0].y + 1;
		if (Huong == 2) A[0].x = A[0].x - 1;
		if (Huong == 3) A[0].y = A[0].y - 1;
	}
};

void gotoxy(int column, int line)
{
	COORD Position; // COORD trong thu vien windows.h giong struct point
	Position.X = column;
	Position.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position); // lenh di chuyen den toa do 
}

int main()
{
	CONRAN Snake;
	char t;
	int huong = 0;
	while (1)
	{
		if (_kbhit())
		{
			t = _getch();
			if (t == 'a') huong = 2;
			if (t == 'w') huong = 3;
			if (t == 'd') huong = 0;
			if (t == 's') huong = 1;
		}
		system("cls");
		Snake.VeConRan();
		Snake.DiChuyen(huong);
		Sleep(300);
	}
	return 0;
}