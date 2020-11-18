// Laba3_OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <iomanip> 
#include <string>
#include <ctime>

using namespace std;

class Form {
public:
	Form() {
		printf("\nАбстрактная фигура\n");
	}
	virtual void show() {

	}
	virtual ~Form() {
		printf("Фигура удалилась\n");
	}
};

class myStorage {
private:
	Form** objects;
	int Size;
public:
	myStorage(int Size) {
		this->Size = Size;
		objects = new Form * [Size];
	}
	void SetObject(int index, Form* object) {
		objects[index] = object;
	}
	Form& GetObject(int index) {
		return *objects[index]; 
	}
	void Del_Object(int index)
	{
		objects[index]->~Form();
	}
	void Add_Object(Form* object) {
		Form** object01 = new Form * [Size + 1];
		for (int i = 0; i < Size; i++)
			object01[i] = objects[i];
		object01[Size] = object;
		Size++;
		delete objects;
		objects = object01;
		printf("Добавили объект ");
		object->show();
		printf("В память с индексом  %d\n\n", Size - 1);
	}

	int getCount() {
		return Size;
	}
};

class Point : public Form {
private:
	int x, y;
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void show() {
		printf("Точка с координатами (%d;%d)\n", x, y);
	}
	~Point() {
		printf("Точка удалилась с координатами (%d;%d)\n", x, y);;
	}
};

class Line : public Form {
private:
	Point* p1;
	Point* p2;
public:
	Line() {
		p1 = new Point(rand() % 10, (rand() % 10));
		p2 = new Point(rand() % 10, (rand() % 10));
	}
	void show() {
		printf("Отрезок с точками : \n");
		//cout << endl;
		p1->show(); p2->show();
		cout << endl;
	}
	~Line() {
		printf("Отрезок с точками : \n");
		//cout << endl;
		p1->show(); p2->show();
		delete p1;
		delete p2;
	}
};

int main()
{
	Form* objNew;
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	myStorage storage(12);
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

	unsigned int start_time = clock();
	for (int i = 0; i < 100; i++) {
		int random = rand() % 4 + 1;
		switch (random) {

		case 1:
			random = rand() % 2 + 1;
			if (random == 1) {
				objNew = new Point(rand() % 10, rand() % 10);
			}
			else
				objNew = new Line();
			break;

		case 2:
			random = rand() % 2 + 1;
			if (random == 1) {
				objNew = new Point(rand() % 10, rand() % 10);
			}
			else
				objNew = new Line();
			storage.Add_Object(objNew);
			break;

		case 3:
			printf("Используем метод Show\n");
			storage.GetObject(rand() % storage.getCount()).show();
			printf("\n");
			break;

		case 4:
			storage.Del_Object(rand() % storage.getCount());
			printf("\n");
			break;
		}
	}

			


}


