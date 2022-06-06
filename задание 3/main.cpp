#include <iostream>
#include <ctime>
#include <random>
using namespace std;

struct Point
{
	int x, y;

	bool operator==(const Point& p) const
	{
		return (this->x == p.x && this->y == p.y);
	}
};

string CheckLocation(const Point&, const Point&, const Point&);

int main()
{
	srand(time(NULL));

	try
	{
		while (true)
		{
			system("cls");
			int x1, x2, x3, y1, y2, y3;

			x1 = (int)rand() % 5;
			y1 = (int)rand() % 5;
			x2 = (int)rand() % 5;
			y2 = (int)rand() % 5;
			x3 = (int)rand() % 5;
			y3 = (int)rand() % 5;

			cout << "{" << x1 << " " << y1 << "}" << endl <<
					"{" << x2 << " " << y2 << "}" << endl <<
					"{" << x3 << " " << y3 << "}" << endl;

			string result = CheckLocation({ x1,y1 }, { x2,y2 }, { x3,y3 });
			cout << result << endl;

			system("pause");
		}
		
	}
	catch (string err)
	{
		cout << err << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}

string CheckLocation(const Point& robotCoord, const Point& heroCoord, const Point& heroViewCoord)
{
	if (heroCoord == heroViewCoord)
		throw string("heroCoord = heroViewCoord!");

	//y = ax + b
	int a, b;
	
	//������ �������� ���������, �� �������� �������� ������ �� ���� �����
	if (heroCoord.x == heroViewCoord.x)
	{
		a = 0;
		b = heroCoord.x;
	}
	else
	{
		a = (heroViewCoord.y - heroCoord.y) / (heroViewCoord.x - heroCoord.x);
		b = (heroViewCoord.x * heroCoord.y - heroViewCoord.y * heroCoord.x) / (heroViewCoord.x - heroCoord.x);
	}
	
	//���� ���������� ������ ����� �� ������, �����������
	//�� ������� �������� �����, �� ������ ����� ��������� ����
	//����� ��, ���� �� ���.
	if (a * robotCoord.x + b == robotCoord.y)
	{
		if (heroViewCoord.x > heroCoord.x ||
			heroViewCoord.y > heroCoord.y)
		{
			if (heroCoord.x > robotCoord.x ||
				heroCoord.y > robotCoord.y)
				return string("Behind");
			else
				return string("InFront");
		}
		else
		{
			if (heroCoord.x > robotCoord.x ||
				heroCoord.y > robotCoord.y)
				return string("InFront");
			else
				return string("Behind");
		}
	}
	//���� �� �����, �� ���� ����� ���� ������
	else
	{
		//�������, ����������� ��������� �� ����� ������� �� ������
		//����� �����.
		int D = (robotCoord.x - heroCoord.x) * (heroViewCoord.y - heroCoord.y) - 
				(robotCoord.y - heroCoord.y) * (heroViewCoord.x - heroCoord.x);

		//���� D>0, �� ����� ����� ������
		if (D > 0)
			return string("Right");
		//���� D<0, �� ����� ����� �����
		else
			return string("Left");
	}
}