/*
* ��������: �������� �������
*
* ������:
* �������������� ����������� ����������.
* �������� ���������� �������� ��������� ���������������� � �� ���������������� ���������.
* �������� ������� ����������, ������� ���������� ���������� ��������.
*
* BubbleSort - ������� ���������� ���������.
* BubbleMegaSort - ��������� ������� ���������� ���������. ��������� ����������� � ���, ��� ����� ���� ��� ������ ������������, ���������� ������������.
* 
* ������ ���������� ����������:
* ���������� ���������:
* ����� ����� �������� �� ������� : N*(N-1). ��������� ���������� O(n*n)
* 
** ��������� ���������� ���������:
* ����� ����� �������� �� ������� : N*(N-1). ��������� ���������� O(n*n).
* �� ��������, ����� �������� �� ����� ������ �� 5%-8%.
*/
#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

#define SIZE 10000

void swap(int *a, int *b);
int BubbleSort(int size, int *a);
int BubbleMegaSort(int size, int *b);
void printMass(int size, int *a);
int iter = 0;

int main()
{
	setlocale(LC_CTYPE, "rus");
	srand(time(NULL));

	int a[SIZE];
	int b[SIZE];
	int count = 0;
	int tmp;

	for (int i = 0; i < SIZE; i++)
	{
		tmp = rand();
		a[i] = tmp;
		b[i] = tmp;
	}

//	printMass(SIZE, a);
	count = BubbleSort(SIZE,a);
	cout << "\n�������� ����������� � ����������� ����������: " << count << " �������� �� �������: "<< iter << "\n";
//	printMass(SIZE, a);
	count = 0;
	iter = 0;
//	printMass(SIZE, b);
	count = BubbleMegaSort(SIZE, b);
	cout << "\n�������� ����������� � ���������������� ����������� ����������: " << count << " �������� �� �������: " << iter << "\n";
//	printMass(SIZE, b);

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
