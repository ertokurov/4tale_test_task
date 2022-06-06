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
	//������ ����������� ������ ���� ������������.
	if (!CheckArrayForSorting(arr))
		throw string("array is not sorted!");

	//������ ����� ������ �����, ��� ���� � �������.
	if (k > arr.size())
		throw string("k > array size!");

	vector<int> output_vec;

	int left = 0, right = arr.size(), ref_point = right;

	//���� "������� �����", �� ������� ��� ����� ������������� ���
	//������ ��������� ��������.
	//���������� �������� �����.
	//�� ����� ���� �� ����� ������ �������, ����� ������������
	//� ������� �������� �����.
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > x)
		{
			ref_point = i;
			break;
		}
	}

	//���� ������� ����� ������ � ����� �������
	if (ref_point < k)
		right = k;
	//���� ������� ����� ������ � ������ �������
	else if (ref_point > arr.size() - k)
		left = arr.size() - k;
	//���� ������� ���� ���-�� ����������
	else
	{
		left = ref_point - (k / 2);
		right = ref_point + (k / 2);
		
		//���������� ����� ����� � ����� � ������ �������
		//����� � ����� x � ����� ���������.
		if (x - arr[left - 1] > arr[right + 1] - x)
			right++;
		else
			left--;
	}

	//��������� �������� ������ ����������
	for (int i = left; i < right; i++)
		output_vec.push_back(arr[i]);

	return output_vec;
}