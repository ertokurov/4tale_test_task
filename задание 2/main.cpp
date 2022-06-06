#include <iostream>
#include <vector>
using namespace std;

bool CheckArrayForSorting(const vector<int>& arr);
vector<int> FindClosestNumbersInArray(const vector<int>& arr, int k, int x);

int main()
{

	try
	{
		vector<int> arr = FindClosestNumbersInArray({ 4,12,54,100,121,344,540 }, 6, -100);

		for (const auto& item : arr)
			cout << item << endl;
	}
	catch (string err)
	{
		cout << err << endl;
	}
	


	system("pause");
	return EXIT_SUCCESS;
}

bool CheckArrayForSorting(const vector<int>& arr)
{
	for (int i = 1; i < arr.size(); i++)
		if (arr[i - 1] > arr[i])
			return false;

	return true;
}

vector<int> FindClosestNumbersInArray(const vector<int>& arr, int k, int x)
{
	//Массив обязательно должен быть отсортирован.
	if (!CheckArrayForSorting(arr))
		throw string("array is not sorted!");

	//Нельзя найти больше чисел, чем есть в массиве.
	if (k > arr.size())
		throw string("k > array size!");

	vector<int> output_vec;

	int left = 0, right = arr.size(), ref_point = right;

	//Ищем "опорную точку", от которой уже будем отталкиваться при
	//поиске ближайших значений.
	//Используем линейный поиск.
	//На самом деле не самое лучшее решение, лучше использовать
	//к примеру бинарный поиск.
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > x)
		{
			ref_point = i;
			break;
		}
	}

	//Если опорная точка близка к левой границе
	if (ref_point < k)
		right = k;
	//Если опорная точка близка к правой границе
	else if (ref_point > arr.size() - k)
		left = arr.size() - k;
	//Если опорная тока где-то посередине
	else
	{
		left = ref_point - (k / 2);
		right = ref_point + (k / 2);
		
		//Сравниваем какое число с левой и правой границы
		//ближе к числу x и берем ближайшее.
		if (x - arr[left - 1] > arr[right + 1] - x)
			right++;
		else
			left--;
	}

	//Заполняем выходной массив значениями
	for (int i = left; i < right; i++)
		output_vec.push_back(arr[i]);

	return output_vec;
}