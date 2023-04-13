#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <array>
#include<functional>
using namespace std;

class MyClass {
	int x;
public:
	MyClass() :x(10) { cout << x << endl; }
	void doSomthing() // метод класса выполняющий лямбда функцию
	{
		auto lambda = [this](int val) {
			cout << x * val << endl;
		};
		lambda(5);
	}
};

// Задание №2
// Напишите класс работник(поля: имя и зарплата, метод : инициализация).Создайте список работников.
// Реализуйте механизм лямбд при сортировке списка по убыванию, а также при выводе.
// При выводе использовать перегруженный оператор << .

class Worker
{
private:
	string name;
	int salary;
public:
	Worker(string name, int salary) : name(name), salary(salary) {}
	void setName(string name) { this->name = name; }
	void setSalary(int salary) { this->salary = salary; }
	string getName() { return name; }
	int getSalary() { return salary; }
	friend ostream& operator<<(ostream& os, const Worker& worker)
	{
		os << "name: " << worker.name << " salary: " << worker.salary << endl;
		return os;
	}
	void print()
	{
		cout << "name: " << name << " salary: " << salary << endl;
	}
	void init()
	{
		cout << "name: ";
		cin >> name;
		cout << "salary: ";
		cin >> salary;
	}
	void doSomthing() // метод класса выполняющий лямбда функцию
	{
		auto lambda = [this](int val) {
			cout << salary * val << endl;
		};
		lambda(5);
	}
};


int main()
{
	int menu;

	do
	{
		cout << "Choice menu: " << endl;
		cin >> menu;

		switch (menu)
		{
		case 1:
		{
			vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			// 1. поиск минимального значения
			auto min = min_element(vec.begin(), vec.end());
			cout << "min = " << *min << endl;
			// 2. поиск максимального значения
			auto max = max_element(vec.begin(), vec.end());
			cout << "max = " << *max << endl;
			// 3. сортировка данных по убыванию
			sort(vec.begin(), vec.end(), greater<int>());
			for (auto i : vec)
				cout << i << " ";
			cout << endl;
			// 4. сортировка данных по возрастанию
			sort(vec.begin(), vec.end());
			for (auto i : vec)
				cout << i << " ";
			cout << endl;
			// 5. увеличение значений в контейнере на заданную константу
			int val = 5;
			for_each(vec.begin(), vec.end(), [val](int& i) {i += val; });
			for (auto i : vec)
				cout << i << " ";
			cout << endl;
			// 6. уменьшение значений в контейнере на заданную константу
			for_each(vec.begin(), vec.end(), [val](int& i) {i -= val; });
			for (auto i : vec)
				cout << i << " ";
			cout << endl;
			// 7. удаление элементов из контейнера равных искомому значению
			int val2 = 5;
			vec.erase(remove(vec.begin(), vec.end(), val2), vec.end());
			for (auto i : vec)
				cout << i << " ";
			cout << endl;
			break;
		}
		case 2:
		{
			// Задание №2

			Worker worker1("Ivan", 1000);
			Worker worker2("Petr", 2000);
			Worker worker3("Sidor", 3000);

			vector<Worker> workers;
			workers.push_back(worker1);
			workers.push_back(worker2);
			workers.push_back(worker3);

			// 1. сортировка данных по убыванию
			sort(workers.begin(), workers.end(), [](Worker& a, Worker& b) {return a.getSalary() > b.getSalary(); });
			for (auto i : workers)
				cout << i;
			cout << endl;
		}
		case 0:
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	} while (menu!=0);
}