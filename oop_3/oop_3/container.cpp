#include "container.h"

//конструктор
container::container(int kolvo, int k)
{
	T = NULL; keys = k; n = kolvo; T = new table[n]; for (int i = 0; i<n; i++)T[i].first = NULL;
}
//деструктор
container::~container()
{
	if (T != NULL)
		for (int i = 0; i < n; i++)
			if (T[i].first != NULL)
				while (T[i].el->next != NULL)
				{
					delete T[i].el->el;
					T[i].el = T[i].el->next;
				}
	delete T;
}
//помещение элемента в контейнер
void container::push(box a)
{
	table *P = T; elem *c; c = new elem; c->next = NULL; c->el = new box; *(c->el) = a; int key; int position;
	switch (keys){
	case 1:{POINT b[4]; b[0] = a.get_kord1(); b[1] = a.get_kord2();  b[2] = a.get_kord3(); b[3] = a.get_kord4(); key = b[0].x + b[0].y + b[1].x + b[1].y; position = (key * 17 + 1) % n;
		if (P[position].first == NULL)
		{
			P[position].el = c; P[position].first = P[position].el;
		}
		else
		{
			while (P[position].el->next != NULL)
				P[position].el = P[position].el->next; 
			P[position].el->next = new elem; P[position].el->next = c; P[position].el = P[position].first;
		}
	}break;
	case 2:{int m[5]; a.get_lin(&m); key = m[0] + m[1] + m[2] + m[3] + m[4]; position = (key * 17 + 1) % n; if (P[position].first == NULL)
	{
		P[position].el = c; P[position].el->next = NULL; P[position].first = P[position].el;
	}
		   else
		   {
			   while (P[position].el->next != NULL)
			   {
				   P[position].el = P[position].el->next;
			   }P[position].el->next = new elem; P[position].el->next = c; P[position].el = P[position].first;
		   }}break;
	}
}
//проверка
int container::check(int m[5], int k[5], POINT a[4], POINT b[4])
{
	for (int i = 0; i<5; i++){ if (m[i] != k[i])return 0; if (i<2) if (a[i].x != b[i].x || a[i].y != b[i].y)return 0; }return 1;
}
//поиск элемента,возвращает указатель на элемент
box *container::find()
{
	int key; int position;
	switch (keys){
	case 1:{POINT b[4];
		cout << "Введите координаты" << endl; cin >> b[0].x >> b[0].y >> b[1].x >> b[1].y >> b[2].x >> b[2].y >> b[3].x >> b[3].y;
		key = b[0].x + b[0].y + b[1].x + b[1].y + +b[2].x + b[2].y + b[3].x + b[3].y;
		position = (key * 17 + 1) % n;
		if (T[position].first != NULL)
		{
			if (T[position].el->next == NULL)return T[position].el->el; else {
				cout << "Элементов с таким ключом несколько" << endl;
				cout << "Введите характеристики линии" << endl;
				int m[5]; cin >> m[0] >> m[1] >> m[2] >> m[3] >> m[4];
				int k[5]; POINT c[4];
				T[position].el->el->get_lin(&k);
				c[0] = T[position].el->el->get_kord1(); c[1] = T[position].el->el->get_kord2();
				c[2] = T[position].el->el->get_kord3(); c[3] = T[position].el->el->get_kord4();
				while (check(m, k, b, c) != 1 && T[position].el->next != NULL)
				{
					T[position].el = T[position].el->next; T[position].el->el->get_lin(&k);
					c[0] = T[position].el->el->get_kord1(); c[1] = T[position].el->el->get_kord2();
					c[2] = T[position].el->el->get_kord3(); c[3] = T[position].el->el->get_kord4();
				}
				if (check(m, k, b, c) != 1) { cout << "Такого элемента нет" << endl; return NULL; }
				else return T[position].el->el;
			}
		}
		else{ cout << "Такого элемента нет" << endl; return NULL; }}break;
	case 2:{int m[5]; cout << "Характеристики линии" << endl; cin >> m[0] >> m[1] >> m[2] >> m[3] >> m[4];
		key = m[0] + m[1] + m[2] + m[3] + m[4]; position = (key * 17 + 1) % n;
		if (T[position].first != NULL){
			if (T[position].el->next == NULL)return T[position].el->el;
			else {
				cout << "Элементов с таким ключом несколько" << endl; POINT b[4];
				cout << "Введите координаты" << endl; cin >> b[0].x >> b[0].y >> b[1].x >> b[1].y >> b[2].x >> b[2].y >> b[3].x >> b[3].y;
				int k[5];  POINT c[4]; T[position].el->el->get_lin(&k);
				c[0] = T[position].el->el->get_kord1(); c[1] = T[position].el->el->get_kord2();
				c[2] = T[position].el->el->get_kord3(); c[3] = T[position].el->el->get_kord4();
				while (check(m, k, b, c) != 1 && T[position].el->next != NULL)
				{
					T[position].el = T[position].el->next; T[position].el->el->get_lin(&k);
					c[0] = T[position].el->el->get_kord1(); c[1] = T[position].el->el->get_kord2();
					c[2] = T[position].el->el->get_kord3(); c[3] = T[position].el->el->get_kord4();
				}
				if (check(m, k, b, c) != 1) { cout << "Такого элемента нет" << endl; return NULL; }
				else return T[position].el->el;
			}
		}
		else
		{
			cout << "Такого элемента нет" << endl; return NULL;
		}}break;
	}
}
//возвращение элемента с удалением
box *container::pop()
{
	box *rez; int key; int position;
	switch (keys){
	case 1:{POINT b[4]; cout << "Введите координаты" << endl; cin >> b[0].x >> b[0].y >> b[1].x >> b[1].y >> b[2].x >> b[2].y >> b[3].x >> b[3].y;
		key = b[0].x + b[0].y + b[1].x + b[1].y + +b[2].x + b[2].y + b[3].x + b[3].y; position = (key * 17 + 1) % n;
		if (T[position].first != NULL)
		{
			if (T[position].el->next == NULL){ rez = T[position].el->el; T[position].el = NULL; return rez; }
			else {
				cout << "Элементов с таким ключом несколько" << endl;
				cout << "Введите характеристики линии" << endl;
				int m[5]; cin >> m[0] >> m[1] >> m[2] >> m[3] >> m[4]; int k[5]; POINT c[4];
				T[position].el->el->get_lin(&k);
				c[0] = T[position].el->el->get_kord1(); c[1] = T[position].el->el->get_kord2();
				c[2] = T[position].el->el->get_kord3(); c[3] = T[position].el->el->get_kord4();
				if (check(m, k, b, c) == 1)
				{
					T[position].first = T[position].el->next; rez = T[position].el->el; delete T[position].el; T[position].el = T[position].first;
					return rez;
				}
				while (check(m, k, b, c) != 1 && T[position].el->next->next != NULL)
				{
					T[position].el->next->el->get_lin(&k);
					c[0] = T[position].el->next->el->get_kord1(); c[1] = T[position].el->next->el->get_kord2();
					c[2] = T[position].el->next->el->get_kord3(); c[3] = T[position].el->next->el->get_kord4();
					if (T[position].el->next->next != NULL && check(m, k, b, c) != 1)T[position].el = T[position].el->next;
				}
				if (check(m, k, b, c) != 1)
				{
					T[position].el->next->el->get_lin(&k);
					c[0] = T[position].el->next->el->get_kord1(); c[1] = T[position].el->next->el->get_kord2();
					c[2] = T[position].el->next->el->get_kord3(); c[3] = T[position].el->next->el->get_kord4();
					if (check(m, k, b, c) != 1)
					{
						cout << "Такой фигуры нет" << endl; return NULL;
					}
					else { rez = T[position].el->next->el; T[position].el->next = NULL; return rez; }
				}
				else
					if(T[position].el->next != NULL)
				{
					rez = T[position].el->next->el; T[position].el->next = T[position].el->next->next; T[position].el = T[position].first;
					return rez;
				}
				else
				{
					rez = T[position].el->el; delete T[position].el; T[position].el = T[position].first; return rez;
				}
			}
		}
		else{ cout << "Такой фигуры нет" << endl; return NULL; }}break;
	case 2:{int m[5];
		cout << "Характеристики линии" << endl; cin >> m[0] >> m[1] >> m[2] >> m[3] >> m[4];
		key = m[0] + m[1] + m[2] + m[3] + m[4]; position = (key * 17 + 1) % n;
		if (T[position].first != NULL)
		{
			if (T[position].el->next == NULL){ rez = T[position].el->el; T[position].el = NULL; return rez; }
			else {
				cout << "Элементов с таким ключом несколько" << endl; POINT b[4];
				cout << "Введите координаты" << endl; cin >> b[0].x >> b[0].y >> b[1].x >> b[1].y >> b[2].x >> b[2].y >> b[3].x >> b[3].y;
				int k[5]; POINT c[4]; T[position].el->el->get_lin(&k);
				c[0] = T[position].el->el->get_kord1(); c[1] = T[position].el->el->get_kord2();
				c[2] = T[position].el->el->get_kord3(); c[3] = T[position].el->el->get_kord4();
				if (check(m, k, b, c) == 1)
				{
					T[position].first = T[position].el->next; rez = T[position].el->el; delete T[position].el; T[position].el = T[position].first;
					return rez;
				}
				while (check(m, k, b, c) != 1 && T[position].el->next->next != NULL)
				{
					T[position].el->next->el->get_lin(&k);
					c[0] = T[position].el->next->el->get_kord1(); c[1] = T[position].el->next->el->get_kord2();
					c[2] = T[position].el->next->el->get_kord3(); c[3] = T[position].el->next->el->get_kord4();
					if (T[position].el->next->next != NULL && check(m, k, b, c) != 1)T[position].el = T[position].el->next;
				}
				if (check(m, k, b, c) != 1)
				{
					T[position].el->next->el->get_lin(&k);
					c[0] = T[position].el->next->el->get_kord1(); c[1] = T[position].el->next->el->get_kord2();
					c[2] = T[position].el->next->el->get_kord3(); c[3] = T[position].el->next->el->get_kord4();
					if (check(m, k, b, c) != 1){ cout << "Такой фигуры нет" << endl; return NULL; }
					else { rez = T[position].el->next->el; T[position].el->next = NULL; return rez; }
				}else
					if(T[position].el->next != NULL)
				{
					rez = T[position].el->next->el; T[position].el->next = T[position].el->next->next; T[position].el = T[position].first;
					return rez;
				}
				else
				{
					rez = T[position].el->el; delete T[position].el; T[position].el = T[position].first; return rez;
				}
			}
		}
		else
		{
			cout << "Такой фигуры нет" << endl; return NULL;
		}}break;
	}
}
//вывод элементов на экран
void container::print()
{
	for (int i = 0; i<n; i++)
		if (T[i].first != NULL)
		{
			while (T[i].el != NULL)
			{
				POINT a[4]; int b[5]; a[0] = T[i].el->el->get_kord1(); a[1] = T[i].el->el->get_kord2(); a[2] = T[i].el->el->get_kord3(); a[3] = T[i].el->el->get_kord4(); T[i].el->el->get_lin(&b);
				print_kord(a); cout << endl; print_lin(b); cout << endl; cout << "\n\n";
				T[i].el = T[i].el->next;
			}T[i].el = T[i].first;
		}
}
//сохранение элементов в файл
void out(container *a)
{
	string f; cout << "Введите название файл" << endl; cin >> f; a->output(f);
}
//сохранение элементов
void container::output(string f)
{
	ofstream fout(f); for (int i = 0; i < n; i++)
		if (T[i].first != NULL)
		{
			while (T[i].el != NULL){
				POINT a[4]; int b[5]; a[0] = T[i].el->el->get_kord1(); a[1] = T[i].el->el->get_kord2(); a[2] = T[i].el->el->get_kord3(); a[3] = T[i].el->el->get_kord4(); T[i].el->el->get_lin(&b);
				print_kord(a); fout << endl; print_lin(b); fout << endl; fout << "\n\n";
				T[i].el = T[i].el->next;
			}T[i].el = T[i].first;
		}
}