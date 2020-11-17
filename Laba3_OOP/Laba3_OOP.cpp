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

	}
	virtual void show() {

	}
	virtual ~Form() {
		cout << "Фигура была удалена" << endl;
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
		return; //дописать
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
		cout << "";
		object->show();
		cout << "" << Size - 1 << endl;
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
		cout << "";
	}
	~Point() {
		cout << "";
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
		cout << "";
		cout << endl;
		p1->show(); p2->show();
		cout << endl;
	}
	~Line() {
		cout << "";
		cout << endl;
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
		if (choice == 2)
			storage.SetObject(i, new Point(rand() % 10, rand() % 10));
		else
			storage.SetObject(i, new Line());
	}
	for (int i = 0; i < storage.getCount(); i++) {
		storage.GetObject(i).show();
	}

}


