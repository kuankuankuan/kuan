#include "container.h"
void main()
{
	setlocale(LC_CTYPE, "Russian");
	container a(20, 1); //переменная для контейнера
	box *b; //переменная для характеристик параллелограмма
	b = new box;
	int key; //переменная для ключа
	int i = 0;
	do{
		system("cls");
		cout << "------------------------------------------" << endl;
		cout << "|    1-Считывание информации из файла    | " << endl;
		cout << "|    2-Вывод данных на экран             | " << endl;
		cout << "|    3-Нарисовать контур фигуры          | " << endl;
		cout << "|    4-Нарисовать закрашенную фигуру     | " << endl;
		cout << "|    5-Нарисовать фигуру в фигуре        | " << endl;
		cout << "|    6-Изменение данных                  | " << endl;
		cout << "|    7-Смещение фигур                    | " << endl;
		cout << "|    8-Сохранение данных в файл          | " << endl;
		cout << "|    9-Выход                             | " << endl;
		cout << "------------------------------------------" << endl;
		cin >> i;
		switch (i){
		case 1:{
			system("cls");
			cout << "Введите название файла" << endl;
			string t_fin;
			cin >> t_fin;
			ifstream fin(t_fin);
			int er = 0;
				while (!fin.eof())
				{
					try{ b->input(&fin); }
					catch (int error){ er++; if (error == 0)std::cout << "Error in" << er << " box" << std::endl; else (a).push(*b); }
				}
				fin.close();
				cout << "Считывание из файла было произведено" << endl;
			_getch(); }break;
		case 2:{system("cls"); (a).print(); _getch(); }break;
		case 3:{
			system("cls"); 
			if ((b = ((a).find())) != NULL)
			{
					system("cls");
					b->one();
					_getch();
					b->fon();
			}
			_getch(); 
		}break;
		case 4:{system("cls"); if ((b = ((a).find())) != NULL){ system("cls"); b->two(); _getch(); b->fon(); }_getch(); }break;
		case 5:{box *b1; b1 = new box; system("cls"); if ((b = ((a).find())) != NULL && (b1 = ((a).find())) != NULL){
			system("cls");
			three(*b, *b1);
		}_getch(); }break;
		case 6:{system("cls");
			cout << "---------------------------------" << endl;
			cout << "|   1-Добавить новую фигуру     | " << endl;
			cout << "|   2-Изменить данные           | " << endl;
			cout << "|   3-Выход                     | " << endl;
			cout << "---------------------------------" << endl;
			int number; cin >> number;
			switch (number){
			case 1:{system("cls"); POINT c[4]; int m[5]; try{ read_all(&c, &m); }
				   catch (int error){ if (error == 1){ b->set_kord(c); b->set_lin(m); (a).push(*b); cout << "Новая фигура была добавлена" << endl; } }
				   _getch(); }break;
			case 2:{system("cls"); box *d = new box;; if ((d = (a).pop()) != NULL)
			{
				system("cls");
				cout << "----------------------------------------" << endl;
				cout << "|  1-Изменение координат               | " << endl;
				cout << "|  2-Изменение характеристик линии     | " << endl;
				cout << "|  3-Выход                             | " << endl;
				cout << "----------------------------------------" << endl;
				int number1; cin >> number1; switch (number1){
				case 1:{POINT c[4]; try{ read_kord(&c); }
					   catch (int error){
						   if (error == 1){ d->set_kord(c); (a).push(*d); }
						   else std::cout << "Ошибка ввода координат" << std::endl;
					   }}break;
				case 2:{int m[5]; try{ read_lin(&m); } catch (int error){ if (error == 1){ d->set_lin(m); (a).push(*d); } else std::cout << "Ошибка ввода характеристик линии" << std::endl; }}break;
				}
			}}break;
			}}break;
		case 7:{system("cls"); box *c = new box; if ((c = (a).pop()) != NULL){
			int j, k;
			cout << "1-Смещение вверх" << endl;
			cout << "2-Смещение вправо" << endl;
			cout << "3-Смещение вниз" << endl;
			cout << "4-Смещение влево" << endl;
			cout << "Через пробел введите на сколько пикселей смещать" << endl;
			cin >> j >> k; 
			c->dvig(j, k);
			(a).push(*c);			
			cout << "Смещение было произведено" << endl;
		}
			   _getch(); system("cls"); }break;
		case 8:{
			system("cls");
			cout << "------------------------------------------" << endl;
			cout << "|   1-Сохранить данные всего контейнера  | " << endl;
			cout << "|   2-Сохранить данные отдельной фигуры  | " << endl;
			cout << "|   3-Выход                              | " << endl;
			cout << "------------------------------------------" << endl;
			int number; cin >> number;
			switch (number){
	  //  	case 1:{system("cls"); out(a); cout << "Данные успешно сохранены" << endl; _getch(); }break;
			case 2:{system("cls"); if ((b = ((a).find())) != NULL){
				cout << "Введите название файла" << endl; string c; cin >> c;
				ofstream f(c); b->output(&f); cout << "Данные успешно сохранены" << endl;
			}_getch(); }break;
			}}break;
		}
	} while (i != 9);
//	delete a;
}