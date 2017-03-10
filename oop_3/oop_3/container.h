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
	table *T;						//указатель на таблицу
	int n;							//размер таблицы
	int keys;						//что является ключом
public:
	container(int kolvo, int k);					//конструктор
	~container();					//деструктор
	box *find();					//поиск элемента,возвращает указатель на элемент
	box *pop();						//возвращение элемента с удалением
	void push(box a);				//помещение элемента в контейнер
	void output(string f);			//вывод содержимого контейнера в файл f
	void print();					//вывод содержимого контейнера на экран
	int check(int m[5],
		int k[5],   //проверка
		POINT a[2], POINT b[2]
		);
};
void out(container *a);				//вывод элементов в файл
#endif
