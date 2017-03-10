#pragma once
#ifndef Box
#define Box
#include <windows.h>
#include <windowsx.h>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <iostream>
using namespace std;
class box
{
private:
	int lintip, lintol;//тип линии, толщина линии
	int color[2][3]; // цвет линии и штриховки
	int strtip; //тип штриховки
	POINT kor[4]; //координаты
public:
	void input(ifstream *f);//ввод данных
	void output(ofstream *f);//вывод данных
	void dvig(int k, int c);//смещение квадрата
	void fon();//отрисовка фона
	void one();//контур
	void two();//заштрихованный квадрат
	void set_kord(POINT a[4]);//изменение координат
	void set_lin(int m[5]);//изменяет характеристики линии
	void get_lin(int(*m)[5]);//возврат характеристик линии
	POINT get_kord1();//возврат верхней координаты диагонали квадрата
	POINT get_kord2();//возврат нижней координаты диагонали квадрата
	POINT get_kord3();
	POINT get_kord4();
};
void three(box a, box a1);//фигура в фигуре
int prov(POINT a[8]);//проверка на вложенность
int provparall(POINT a[4]);//проверка: параллельности
void print_kord(POINT a[4]);//показывает координаты
void print_lin(int m[5]);//вывод характеристик линии
//void print_str(int m[5]);//вывод характеристик штриховки
void read_kord(POINT(*a)[4]);//ввод координат
void read_lin(int(*m)[5]);//ввод характеристик линии
//void read_str(int(*m)[5]);//ввод характеристик штриховки
void read_all(POINT(*a)[4], int(*m)[5]);//ввод новой фигуры
#endif
