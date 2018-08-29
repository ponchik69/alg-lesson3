/*
* Выполнил: Владимир Матвеев
*
* Программа, совмещающая в себе сортировку пузырьком, улучшенную сортировку пузырьком и шейкерную сортировку.
* Выводит результаты работы на экран.
*/
#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

#define SIZE 10000

void swap(int *a, int *b);
int BubbleSort(int size, int *a);
int BubbleMegaSort(int size, int *b);
int ShakerSort(int size, int *c);
void printMass(int size, int *a);
int iter = 0;

int main()
{
	setlocale(LC_CTYPE, "rus");
	srand(time(NULL));

	int a[SIZE];
	int b[SIZE];
	int c[SIZE];
	int count = 0;
	int tmp;

	for (int i = 0; i < SIZE; i++)
	{
		tmp = rand();
		a[i] = tmp;
		b[i] = tmp;
		c[i] = tmp;
	}

	//	printMass(SIZE, a);
	count = BubbleSort(SIZE, a);
	cout << "\nОпераций перемещения в пузырьковой сортировке: " << count << " Проходов по массиву: " << iter << "\n";
	//	printMass(SIZE, a);
	count = 0;
	iter = 0;
	//	printMass(SIZE, b);
	count = BubbleMegaSort(SIZE, b);
	cout << "\nОпераций перемещения в оптимизированной пузырьковой сортировке: " << count << " Проходов по массиву: " << iter << "\n";
	//	printMass(SIZE, b);
	count = 0;
	iter = 0;
	//	printMass(SIZE, с);
	count = ShakerSort(SIZE, c);
	cout << "\nОпераций перемещения в сортировке перемещением: " << count << " Проходов по массиву: " << iter << "\n";
	//	printMass(SIZE, c);

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

int BubbleSort(int size, int *a)
{
	int count = 0;
	int i;
	for (i = 0; i < size; i++)
	{
		int j;
		for (j = 0; j < size - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				count++;
			}
			iter++;
		}
	}
	return count;
}

int BubbleMegaSort(int size, int *b)
{
	int count = 0;
	int tmp;
	int i;
	for (i = 0; i < size; i++)
	{
		tmp = 0;
		int j;
		for (j = 0; j < size - 1; j++)
		{
			if (b[j] > b[j + 1])
			{
				swap(&b[j], &b[j + 1]);
				count++;
			}
			else
			{
				tmp++;
			}
			iter++;
		}
		if (tmp == size - 1)
			break;
	}
	return count;
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
	} while (step < size);

	return count;
}