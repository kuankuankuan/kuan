#define _CRT_SECURE_NO_WARNINGS
#include "box.h"
//считывание из файла
void box::input(ifstream *f)
{
	RECT rt; POINT a[4]; int m[5], m1[3];
	HWND hwnd = GetConsoleWindow();
	GetClientRect(hwnd, &rt);
	char buf[100];
	(*f) >> a[0].x;
	(*f) >> a[0].y;
	(*f) >> a[1].x;
	(*f) >> a[1].y;
	(*f) >> a[2].x;
	(*f) >> a[2].y;
	(*f) >> a[3].x;
	(*f) >> a[3].y;
	(*f) >> m[0];
	(*f) >> m[1];
	(*f) >> m[2];
	(*f) >> m[3];
	(*f) >> m[4];
	(*f) >> m1[0];
	(*f) >> m1[1];
	(*f) >> m1[2];
	kor[0].x = a[0].x;
	kor[0].y = a[0].y;
	kor[1].x = a[1].x;
	kor[1].y = a[1].y;
	kor[2].x = a[2].x;
	kor[2].y = a[2].y;
	kor[3].x = a[3].x;
	kor[3].y = a[3].y;
	lintip = m[0];
	lintol = m[1];
	color[0][0] = m[2];
	color[0][1] = m[3];
	color[0][2] = m[4];
	color[1][0] = m1[0];
	color[1][1] = m1[1];
	color[1][2] = m1[2];
	if (provparall(kor))
		throw 0;
	else
		throw 1;
}
//отрисовка фона
void box::fon()
{
	RECT rt; HWND hwnd = GetConsoleWindow();
	GetClientRect(hwnd, &rt);
	HDC hdc = GetDC(hwnd);
	SetBkColor(hdc, RGB(0, 0, 0));
	HBRUSH Brush0 = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH hOldBrush = SelectBrush(hdc, Brush0);
	Rectangle(hdc, 0, 0, rt.right, rt.bottom);
	SelectBrush(hdc, Brush0);
	DeleteBrush(Brush0);
	system("cls");
}
//отрисовка контура
void box::one()
{
	POINT parall[4] = { { kor[0].x, kor[0].y }, { kor[1].x, kor[1].y }, { kor[2].x, kor[2].y }, { kor[3].x, kor[3].y } };
	HBRUSH Brush1;
	RECT rt;
	HWND hwnd = GetConsoleWindow();
	GetClientRect(hwnd, &rt);
	HDC hdc = GetDC(hwnd);
	HPEN hRedPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	HPEN hOldPen = SelectPen(hdc, hRedPen);
	POINT pt; //положение пера
	HBRUSH BlackBrush = GetStockBrush(BLACK_BRUSH);
	HBRUSH hBlackBrush = SelectBrush(hdc, BlackBrush);
	if (!provparall(parall))
		Polygon(hdc, parall, 4);
	else
		cout << "Фигура не является параллелограммом или выходит за пределами окон" << endl;
	ReleaseDC(hwnd, hdc);
}
//отрисовка закрашенной фигуры
void box::two()
{
	POINT parall[4] = { { kor[0].x, kor[0].y }, { kor[1].x, kor[1].y }, { kor[2].x, kor[2].y }, { kor[3].x, kor[3].y } };
	HBRUSH Brush1;
	RECT rt;
	HWND hwnd = GetConsoleWindow();
	GetClientRect(hwnd, &rt);
	HDC hdc = GetDC(hwnd);
	SetBkColor(hdc, RGB(0, 0, 255));
	Brush1 = CreateSolidBrush(RGB(0, 0, 255));
	HPEN hRedPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	HPEN hOldPen = SelectPen(hdc, hRedPen);
	HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hOldBrush = SelectBrush(hdc, hGreenBrush);
	POINT pt; //положение пера
	if (!provparall(parall))
		Polygon(hdc, parall, 4);
	else
		cout << "Фигура не является параллелограммом или выходит за пределами окон" << endl;
	ReleaseDC(hwnd, hdc);
	ReleaseDC(hwnd, hdc);
	SelectPen(hdc, hOldBrush);
	DeletePen(Brush1);
	ReleaseDC(hwnd, hdc);
}
//вывод в файл
void box::output(ofstream *f)
{
	(*f) << "x1 = " << kor[0].x << " y1 = " << kor[0].y << endl;
	(*f) << "\nx2 = " << kor[1].x << " y2 = " << kor[1].y << endl;
	(*f) << "\nx3 = " << kor[2].x << " y3 = " << kor[2].y << endl;
	(*f) << "\nx4 = " << kor[3].x << " y4 = " << kor[3].y << endl;
	(*f) << "\nТип линии = " << lintip << endl;
	(*f) << "\nТолщина линии = " << lintol << endl;
	(*f) << "\nЦвет RGB = " << color[0][0] << " " << color[0][1] << " " << color[0][2] << endl;
	(*f) << color[1][0] << " " << color[1][1] << " " << color[1][2] << endl;
}
//сдвиг фигуры
void box::dvig(int k, int c)
{
	switch (k)
	{
	case 1:{kor[0].y -= c; kor[1].y -= c; kor[2].y -= c; kor[3].y -= c; }break;
	case 2:{kor[0].x += c; kor[1].x += c; kor[2].x += c; kor[3].x += c;	}break;
	case 3:{kor[0].y += c; kor[1].y += c; kor[2].y += c; kor[3].y += c; }break;
	case 4:{kor[0].x -= c; kor[1].x -= c; kor[2].x -= c; kor[3].x -= c; }break;
	}
}
//возврат значений 1-ой координаты
POINT box::get_kord1()
{
	return kor[0];
}
//возврат значений 2-ой координаты
POINT box::get_kord2()
{
	return kor[1];
}
//возврат значений 3-ой координаты
POINT box::get_kord3()
{
	return kor[2];
}
//возврат значений 4-ой координаты
POINT box::get_kord4()
{
	return kor[3];
}
//возврат значений линии
void box::get_lin(int(*m)[5])
{
	(*m)[0] = lintip;
	(*m)[1] = lintol;
	(*m)[2] = color[0][0];
	(*m)[3] = color[0][1];
	(*m)[4] = color[0][2];
}
//изменение координат
void box::set_kord(POINT a[4])
{
	kor[0].x = a[0].x;
	kor[0].y = a[0].y;
	kor[1].x = a[1].x;
	kor[1].y = a[1].y;
	kor[2].x = a[2].x;
	kor[2].y = a[2].y;
	kor[3].x = a[3].x;
	kor[3].y = a[3].y;
}
//изменение характеристик линии
void box::set_lin(int m[5])
{
	lintip = m[0];
	lintol = m[1];
	color[0][0] = m[2];
	color[0][1] = m[3];
	color[0][2] = m[4];
}
//проверка параллельности
int provparall(POINT b[4])
{
	RECT rt;
	HWND hwnd = GetConsoleWindow();
	GetClientRect(hwnd, &rt);
	char buf[100];
	sprintf(buf, "Размер окна %d на %d пикселей", rt.right, rt.bottom);
	int ax, cy, ay, cx, bx, dy, dx, by;
	ax = abs(b[1].x - b[0].x);
	ay = abs(b[1].y - b[0].y);
	bx = abs(b[2].x - b[1].x);
	by = abs(b[2].y - b[1].y);
	cx = abs(b[3].x - b[2].x);
	cy = abs(b[3].y - b[2].y);
	dx = abs(b[0].x - b[3].x);
	dy = abs(b[0].y - b[3].y);
	if ((ax*cy - ay*cx == 0) && (bx*dy - dx*by == 0))
	{
		if (b[0].x > rt.right || b[0].x < 0 || b[0].y > rt.bottom || b[0].y < 0 || b[1].x > rt.right || b[1].x < 0 || b[1].y > rt.bottom || b[1].y < 0 || b[2].x > rt.right || b[2].x < 0 || b[2].y > rt.bottom || b[2].y < 0 || b[3].x > rt.right || b[3].x < 0 || b[3].y > rt.bottom || b[3].y < 0) //Если фигура больше размеров окна 
			return 1;
		else
			return 0;
	}
	else
		return 1;
}
//рисует фигуру в фигуре
void three(box a, box a1)
{
	POINT b[4];
	b[0] = a.get_kord1();
	b[1] = a.get_kord2();
	b[2] = a.get_kord3();
	b[3] = a.get_kord4();
	if (!provparall(b))
	{
		b[0] = a1.get_kord1();
		b[1] = a1.get_kord2();
		b[2] = a1.get_kord3();
		b[3] = a1.get_kord4();
		if (!provparall(b))
		{
			b[0] = a.get_kord1();
			b[1] = a.get_kord2();
			b[2] = a.get_kord3();
			b[3] = a.get_kord4();
			b[4] = a1.get_kord1();
			b[5] = a1.get_kord2();
			b[6] = a1.get_kord3();
			b[7] = a1.get_kord4();
			if (prov(b))
			{
				a1.two();
				a.one();
				_getch();
			}
			else
				printf("Меньший параллелограмм не прошел проверку на вложенность в большой параллелограмм");
		}
		else
			printf("Внутреняя фигура не является параллелограммом");
	}
	else
		printf("Фигура не является параллелограммом");
	_getch();
	a.fon();
}
//вывод на экран координат
void print_kord(POINT a[4])
{
	cout << "x1= " << a[0].x;
	cout << "   y1= " << a[0].y;
	cout << "\nx2= " << a[1].x;
	cout << "   y2= " << a[1].y;
	cout << "\nx3= " << a[2].x;
	cout << "   y3= " << a[2].y;
	cout << "\nx4= " << a[3].x;
	cout << "   y4= " << a[3].y;
}
//вывод на экран характеристик линии
void print_lin(int m[5])
{
	cout << "Тип линии " << m[0];
	cout << "\nТолщина линии " << m[1];
	cout << "\nЦвет RGB " << m[2] << " " << m[3] << " " << m[4];
}
//проверка на вложенность
int prov(POINT b[8])
{
	int ax, cy, ay, cx, bx, dy, dx, by;
	ax = abs(b[1].x - b[0].x);
	ay = abs(b[1].y - b[0].y);
	bx = abs(b[2].x - b[1].x);
	by = abs(b[2].y - b[1].y);
	cx = abs(b[3].x - b[2].x);
	cy = abs(b[3].y - b[2].y);
	dx = abs(b[0].x - b[3].x);
	dy = abs(b[0].y - b[3].y);
	int length_ab, length_bc, length_cd, length_da, x1 = 1, y1 = 0;
	length_ab = ((b[4].x - b[0].x)*(b[1].y - b[0].y) - (b[4].y - b[0].y)*(b[1].x - b[0].x));
	length_bc = ((b[4].x - b[1].x)*(b[2].y - b[1].y) - (b[4].y - b[1].y)*(b[2].x - b[1].x));
	length_cd = ((b[4].x - b[2].x)*(b[3].y - b[2].y) - (b[4].y - b[2].y)*(b[3].x - b[2].x));
	length_da = ((b[4].x - b[3].x)*(b[0].y - b[3].y) - (b[4].y - b[3].y)*(b[0].x - b[3].x));
	if (length_ab > 0 && length_bc > 0 && length_cd > 0 && length_da > 0)
		return 0;
	else
		return 1;
}
//чтение координат
void read_kord(POINT(*a)[4])
{
	cout << "\nВведите координаты верхней левой точки\n" << endl;
	cin >> (*a)[0].x >> (*a)[0].y;
	cout << "\nВведите координаты верхней правой точки\n" << endl;
	cin >> (*a)[1].x >> (*a)[1].y;
	cout << "\nВведите координаты нижней правой точки\n" << endl;
	cin >> (*a)[2].x >> (*a)[2].y;
	cout << "\nВведите координаты нижней левой точки\n" << endl;
	cin >> (*a)[3].x >> (*a)[3].y;
	RECT rt;
	HWND hwnd = GetConsoleWindow();
	GetClientRect(hwnd, &rt); char buf[100];
	sprintf(buf, "Размер окна %d на %d пикселей", rt.right, rt.bottom);
	if (abs((*a)[0].x - (*a)[1].x) == abs((*a)[0].y - (*a)[1].y) && (*a)[1].x <= rt.right && (*a)[1].y <= rt.bottom)
		throw 0;
	else
		throw 1;
}
//чтение характеристик линии
void read_lin(int(*m)[5])
{
	cout << "Введите тип линии" << endl; cin >> (*m)[0];
	cout << "Введите толщину линии" << endl; cin >> (*m)[1];
	cout << "Введите цвет RGB" << endl; cin >> (*m)[2] >> (*m)[3] >> (*m)[4];
	if ((*m)[0]>7 && (*m)[0]<1 && (*m)[1]<1 && (*m)[2]>255 && (*m)[2]<0 && (*m)[3]>255 && (*m)[3]<0 && (*m)[4]>255 && (*m)[4]<0)throw 0; else throw 1;
}
//ввод новой фигуры
void read_all(POINT(*a)[4], int(*m)[5])
{
	try
	{
		std::cout << "Введите координаты" << std::endl;
		read_kord(a);
	}
	catch (int error)
	{
		if (error == 1)
			try
		{
			std::cout << "Введите характеристики линии" << std::endl;
			read_lin(m);
		}
		catch (int error)
		{
			if (error == 1)
				throw 1;
			if (error == 0)
			{
				std::cout << "Ошибка в характеристиках линии" << std::endl;
				throw 0;
			}
		}
		else std::cout << "Ошибка в координатах" << std::endl;
	}
}

