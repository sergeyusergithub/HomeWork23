#include <iostream>
#include <cstdlib>
#include <ctime>



void tree_max(int& a, int& b, int& c);

template <typename T>
void print_arr(T arr[], const int length);

void fill_arr(int arr[], const int length, int begin, int last);

int& neg_elem(int arr[], const int length);

void zero_arr(int arr1[], const int length1, int arr2[], const int length2);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	srand(time(NULL));

	// Задача 1. Максимум из трех чисел
	std::cout << "Задача 1.\nВведите три числа -> ";
	int a, b, c;
	std::cin >> a >> b >> c;

	tree_max(a, b, c);
	std::cout << a << ' ' << b << ' ' << c << "\n\n";

	// Задача 2. Возврат ссылки на отрицательный или первый элемент массива
	std::cout << "Задача 2.\nИсходный массив:\n";
	const int size = 10;
	int arr[size]{ 0 };

	fill_arr(arr, size, -10, 10);
	print_arr(arr, size);

	std::cout << "Ссылка на отрицательный элемент: " << neg_elem(arr, size) << "\n\n";

	// Задача 3. Обнуление одинаковых элементов

	std::cout << "Задача 3.\nМассив 1: ";
	const int size1 = 10;
	int arr1[size1]{};
	fill_arr(arr1, size1,0,100);
	print_arr(arr1, size1);

	const int size2 = 8;
	int arr2[size2]{};
	std::cout << "Массив 2: ";
	fill_arr(arr2, size2,0,100);
	print_arr(arr2, size2);

	std::cout << "Массив 2 после вызова функции: ";
	zero_arr(arr1, size1, arr2, size2);
	print_arr(arr2, size2);


	return 0;
}

void tree_max(int& a, int& b, int& c){
	if (a > b && a > c)
		c = b = a;
	else
		if (b > a && b > c)
			c = a = b;
		else
			a = b = c;
}

void fill_arr(int arr[], const int length, int begin, int last){
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (last - begin) + begin;
}

int& neg_elem(int arr[], const int length){
	// TODO: insert return statement here
	for (int i = 0; i < length; i++)
		if (arr[i] < 0)
			return arr[i];
	return arr[0];
}

void zero_arr(int arr1[], const int length1, int arr2[], const int length2){
	for (int i = 0; i < length1; i++)
		for (int j = 0; j < length2; j++)
			if (arr2[j] == arr1[i])
				arr2[j] = 0;
}

template<typename T>
void print_arr(T arr[], const int length){
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}
