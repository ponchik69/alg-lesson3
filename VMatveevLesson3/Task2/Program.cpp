/*
* Выполнил: Владимир Матвеев
*
* Задача:
*
* Реализовать шейкерную сортировку.
*
*
* Оценка сложностей алгоритма:
* Сортировка перемешиванием:
* Всего число проходов по массиву : (n-1)+(n-2)+(n-3)...+1= n*(n-1)/2. Сложность составляет O(n*n)
*
** Улучшения сортировка пузырьком:
* Всего число проходов по массиву : N*(N-1). Сложность составляет O(n*n).
* На практике, число проховов по циклу меньше на 5%-8%.
*/
#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

#define SIZE 100

void swap(int *a, int *b);
int ShakerSort(int size, int *a);
void printMass(int size, int *a);
int iter = 0;

int main()
{
	setlocale(LC_CTYPE, "rus");
	srand(time(NULL));

	int a[SIZE];
	int count = 0;
	int tmp;

	for (int i = 0; i < SIZE; i++)
	{
		tmp = rand();
		a[i] = tmp;
	}

//	printMass(SIZE, a);
	count = ShakerSort(SIZE,a);
	cout << "\nОпераций в шейкерной сортировке: " << count << " Проходов по массиву: "<< iter << "\n";
//	printMass(SIZE, a);

	_getch();
	return 0;
}

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void printMass(int size, int *a)
{
	int i;
	cout << "\n";
	for (i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
}

int ShakerSort(int size, int *a)
{
	int j;
	int k;
	int step = 0;
	int maxIndex = size - 1;
	int minIndex = 0;
	int count = 0;
	do
	{
		for (j = minIndex; j < maxIndex; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				count++;
			}
			iter++;
		}
		maxIndex--;

		for (k = maxIndex; k > minIndex; k--)
		{
			if (a[k] < a[k - 1])
			{
				swap(&a[k], &a[k - 1]);
				count++;
			}
			iter++;
		}
		minIndex++;

		step++;
	} 
	while (step < size);

	return count;
}