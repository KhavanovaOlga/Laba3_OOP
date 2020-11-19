// Laba3_OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>

using namespace std;

//Cоздание базового класса-предка
class Form {
public:
	//Конструктор по умолчанию
	Form() {
		
	}
	virtual void show() {
		printf("\nАбстрактная фигура\n");
	}
	//Деструктор
	virtual ~Form() {
		printf("Фигура удалилась\n");
	}
};

//Cоздание класса-хранилища объектов
class myStorage {
//Закрытые данные класса, к к-ым не можем обращаться напрямую
private:
	Form** objects;
	int Size;
public:

	//Конструктор с параметрами
	myStorage(int Size) {
		this->Size = Size;
		objects = new Form * [Size];
	}

	//Помещение конкретного объекта в хранилище
	void SetObject(int index, Form* object) {
		objects[index] = object;
	}

	//Получение конкретного объекта из хранилища
	Form& GetObject(int index) {
		return *objects[index];
	}

	//Функция удаления объекта из хранилища
	void Del_Object(int index)
	{
		objects[index]->~Form();
	}

	//Функция добавления объекта в хранилище
	void Add_Object(Form* object) {
		Form** object01 = new Form * [Size + 1];
		for (int i = 0; i < Size; i++)
			object01[i] = objects[i];
		object01[Size] = object;
		Size++;
		delete objects;
		objects = object01;
		printf("\nДобавили объект (в память с индексом  %d):\n", Size - 1);
		object->show();
		//printf("в память с индексом  %d\n", Size - 1);
	}

	//Функция возвращения значения размера хранилища
	int getCount() {
		return Size;
	}
};

//Создание класса-потомка, наследуемый от предка (класса Form)
class Point : public Form {
//Закрытые данные класса, к к-ым не можем обращаться напрямую
private:
	int x, y;
public:

	//Конструктор по умолчанию
	Point() {
		x = 0;
		y = 0;
	}

	//Конструктор с параметрами
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void show() {
		printf("Точка с координатами (%d;%d)\n", x, y);
	}

	//Деструктор
	~Point() {
		printf("Точка удалилась с координатами (%d;%d)\n", x, y);
	}
};

//Создание класса-потомка, наследуемый от предка (класса Form)
class Line : public Form {
private:
	//указатели на начальную и конечную точку отрезка
	Point* p1;
	Point* p2;
public:
	//Конструктор по умолчанию
	Line() {
		p1 = new Point(rand() % 10, (rand() % 10));
		p2 = new Point(rand() % 10, (rand() % 10));
	}
	void show() {
		printf("\nОтрезок с точками:\n");
		//cout << endl;
		p1->show(); 
		p2->show();
		cout << endl;
	}
	//Деструктор
	~Line() {
		printf("Отрезок с точками:\n");
		//cout << endl;
		p1->show(); 
		p2->show();
		delete p1;
		delete p2;
	}
};

int main()
{
	Form* objNew;
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");

	printf("========================================\n");
	printf("   Хранилище из 12 случайных объектов \n");
	printf("========================================\n");
	
	myStorage storage(12);

	//Случайным образом помещаем в хранилище объекты: Point и Line
	for (int i = 0; i < storage.getCount(); i++) {
		int choice = rand() % 2 + 1;
		if (choice == 2) {
			storage.SetObject(i, new Point(rand() % 10, rand() % 10));
		}
		else
			storage.SetObject(i, new Line());
	}
	for (int i = 0; i < storage.getCount(); i++) {
		storage.GetObject(i).show(); 
	}

	printf("\n%d - Размер хранилища\n\n", storage.getCount());

	printf("===========================================\n");
	printf("      Цикл из 100 случайных действий \n");
	printf("===========================================\n");
	//Подсчет времени работы цикла
    unsigned int start_time = clock();
	for (int i = 0; i < 100; i++) {
		int random = rand() % 4 + 1;
		switch (random) {

		//Cоздание объектов
		case 1:
			random = rand() % 2 + 1;
			if (random == 1) {
				objNew = new Point(rand() % 10, rand() % 10);
			}
			else
				objNew = new Line();
			break;

		//Добавление объектов в хранилище
		case 2:
			random = rand() % 2 + 1;
			if (random == 1) {
				objNew = new Point(rand() % 10, rand() % 10);
			}
			else
				objNew = new Line();
			storage.Add_Object(objNew);
			printf("\n");
			break;

		//Использование методов объектов
		case 3:
			printf("Используем метод Show()\n");
			storage.GetObject(rand() % storage.getCount()).show();
			//printf("\n");
			break;
        
		//Удаление объектов из хранилища
		case 4:
			printf("\nУдаляем объект:\n");
			storage.Del_Object(rand() % storage.getCount());
			printf("\n");
			break;
		}
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	printf("Время работы программы (мс) = %d\n", search_time);
	system("pause");
	system("cls");

	printf("==============================================\n");
	printf("        Цикл из 1000 случайных действий \n");
	printf("==============================================\n");
	//Подсчет времени работы цикла
	start_time = clock();
	for (int i = 0; i < 1000; i++) {
		int random = rand() % 4 + 1;
		switch (random) {

		//Cоздание объектов
		case 1:
			random = rand() % 2 + 1;
			if (random == 1) {
				objNew = new Point(rand() % 10, rand() % 10);
			}
			else
				objNew = new Line();
			break;

		//Добавление объектов в хранилище
		case 2:
			random = rand() % 2 + 1;
			if (random == 1) {
				objNew = new Point(rand() % 10, rand() % 10);
			}
			else
				objNew = new Line();
			storage.Add_Object(objNew);
			printf("\n");
			break;

		//Использование методов объектов
		case 3:
			printf("Используем метод Show()\n");
			storage.GetObject(rand() % storage.getCount()).show();
			//printf("\n");
			break;

		//Удаление объектов из хранилища
		case 4:
			printf("\nУдаляем объект:\n");
			storage.Del_Object(rand() % storage.getCount());
			printf("\n");
			break;
		}
	}
	end_time = clock();
	search_time = end_time - start_time;
	printf("Время работы программы (мс) = %d\n", search_time);
	system("pause");
	system("cls");

	printf("=============================================\n");
	printf("        Цикл из 10000 случайных действий \n");
	printf("=============================================\n");
	//Подсчет времени работы цикла
	start_time = clock();
	for (int i = 0; i < 10000; i++) {
		int random = rand() % 4 + 1;
		switch (random) {

		//Cоздание объектов
		case 1:
			random = rand() % 2 + 1;
			if (random == 1) {
				objNew = new Point(rand() % 10, rand() % 10);
			}
			else
				objNew = new Line();
			break;

		//Добавление объектов в хранилище
		case 2:
			random = rand() % 2 + 1;
			if (random == 1) {
				objNew = new Point(rand() % 10, rand() % 10);
			}
			else
				objNew = new Line();
			storage.Add_Object(objNew);
			printf("\n");
			break;

		//Использование методов объектов
		case 3:
			printf("Используем метод Show()\n");
			storage.GetObject(rand() % storage.getCount()).show();
			//printf("\n");
			break;

		//Удаление объектов из хранилища
		case 4:
			printf("\nУдаляем объект:\n");
			storage.Del_Object(rand() % storage.getCount());
			printf("\n");
			break;
		}
	}
	end_time = clock();
	search_time = end_time - start_time;
	printf("Время работы программы (мс) = %d\n", search_time);
	system("pause");
	//system("cls");
}


