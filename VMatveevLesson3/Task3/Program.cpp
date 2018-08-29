/*
* Выполнил: Владимир Матвеев
*
* Задача:
*
* Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. 
* Функция возвращает индекс найденного элемента или -1, если элемент не найден.
*
* Массив заполняется случайными элементами, затем сортируется путем сортировки перемешиванием. 
* Затем выполняется бинарный поиск случайного элемента. (Элемента, последнего записанного в массив (tmp)).
*/
#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

#define SIZE 10000

void Swap(int *a, int *b);
void PrintMass(int size, int *a);
int BinnarySearch(int value, int size, int *a);
void ShakerSort(int size, int *a);
int iter = 0;

int main()
{
	setlocale(LC_CTYPE, "rus");
	srand(time(NULL));

	int a[SIZE];
	int tmp;
	int result;

	for (int i = 0; i < SIZE; i++)
	{
		tmp = rand();
		a[i] = tmp;
	}

//	PrintMass(SIZE, a);
	ShakerSort(SIZE, a);
//	PrintMass(SIZE, a);
	result = BinnarySearch(tmp, SIZE, a);

	if(result == -1)
		cout << "\nЭлемент в массиве не найден" << "\n";
	else
		cout << "\nИндекс: " << result << " Значение: " << tmp << "\n";

	_getch();
	return 0;
}

void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void PrintMass(int size, int *a)
{
	int i;
	cout << "\n";
	for (i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
}

void ShakerSort(int size, int *a)
{
	int j;
	int k;
	int step = 0;
	int maxIndex = size - 1;
	int minIndex = 0;
	do
	{
		for (j = minIndex; j < maxIndex; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
		maxIndex--;

		for (k = maxIndex; k > minIndex; k--)
		{
			if (a[k] < a[k - 1])
			{
				Swap(&a[k], &a[k - 1]);
			}
		}
		minIndex++;

		step++;
	} 
	while (step < size);
}

int BinnarySearch(int value, int size, int *a)
{
	int result = -1;
	int minIndex = 0;
	int maxIndex = size - 1;
	int mid = minIndex + (maxIndex - minIndex) / 2;
	while(minIndex <= maxIndex && a[mid] != value)
	{
		if (a[mid] < value)
			minIndex = mid + 1;
		else
			maxIndex = mid - 1;

		mid = minIndex + (maxIndex - minIndex) / 2;
	}

	if (a[mid] == value)
		result = mid;

	return result;
}