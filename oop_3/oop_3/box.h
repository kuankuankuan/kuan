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
	int lintip, lintol;//��� �����, ������� �����
	int color[2][3]; // ���� ����� � ���������
	int strtip; //��� ���������
	POINT kor[4]; //����������
public:
	void input(ifstream *f);//���� ������
	void output(ofstream *f);//����� ������
	void dvig(int k, int c);//�������� ��������
	void fon();//��������� ����
	void one();//������
	void two();//�������������� �������
	void set_kord(POINT a[4]);//��������� ���������
	void set_lin(int m[5]);//�������� �������������� �����
	void get_lin(int(*m)[5]);//������� ������������� �����
	POINT get_kord1();//������� ������� ���������� ��������� ��������
	POINT get_kord2();//������� ������ ���������� ��������� ��������
	POINT get_kord3();
	POINT get_kord4();
};
void three(box a, box a1);//������ � ������
int prov(POINT a[8]);//�������� �� �����������
int provparall(POINT a[4]);//��������: ��������������
void print_kord(POINT a[4]);//���������� ����������
void print_lin(int m[5]);//����� ������������� �����
//void print_str(int m[5]);//����� ������������� ���������
void read_kord(POINT(*a)[4]);//���� ���������
void read_lin(int(*m)[5]);//���� ������������� �����
//void read_str(int(*m)[5]);//���� ������������� ���������
void read_all(POINT(*a)[4], int(*m)[5]);//���� ����� ������
#endif
