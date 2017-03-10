#pragma once
#ifndef Container
#define Container
#include "box.h"
#include <string>
struct elem{ box *el; elem *next; };
struct table{ elem *el; elem *first; };
class container
{
private:
	table *T;						//��������� �� �������
	int n;							//������ �������
	int keys;						//��� �������� ������
public:
	container(int kolvo, int k);					//�����������
	~container();					//����������
	box *find();					//����� ��������,���������� ��������� �� �������
	box *pop();						//����������� �������� � ���������
	void push(box a);				//��������� �������� � ���������
	void output(string f);			//����� ����������� ���������� � ���� f
	void print();					//����� ����������� ���������� �� �����
	int check(int m[5],
		int k[5],   //��������
		POINT a[2], POINT b[2]
		);
};
void out(container *a);				//����� ��������� � ����
#endif
