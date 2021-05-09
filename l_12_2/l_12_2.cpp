#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int Info; // створення псевдоніму типу

struct Elem
{
	Elem* link;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
Info check(Elem* first);
Info dequeue(Elem*& first, Elem*& last);

int main()
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	Elem* first = NULL,
		* last = NULL;
	Info num;
	for (int i = 1; i <= 10; i++) { // створення черги
		num = 1 + rand() % 10;
		enqueue(first, last, num);
	}


	Info result = check(first); 
	cout << "В списку є " << result << " непарних елементів";
	cout << endl << endl;
	cout << "Список: ";
	while (last != NULL) {
		cout << dequeue(first, last) << " "; // Вивід та видалення черги
	}
	cout << endl;

	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
}

Info dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->link;
	Info value = first->info;
	delete first;
	first = tmp;
	if (first == NULL)
		last = NULL;
	return value;
}


Info check(Elem* first)
{
	Info k = 0;
	cout << "Непарні елементи: ";
	while (first != NULL) {
		if (first->info % 2 != 0) {
			cout << first->info << " ";
			k++;
		}
		first = first->link;
	}
	cout << endl << endl;
	return k;
}