#include <iostream>
#include <string>
#include <exception>
using namespace std;

int FindSubstring(string s, string t);

int main()
{

	try 
	{
		cout << FindSubstring("a", "aa") << endl;
		cout << FindSubstring("ab", "aab") << endl;
		cout << FindSubstring("b", "aa") << endl;
	}
	catch (string err)
	{
		cout << err << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}


//int FindSubstring(string s, string t)
//{
//	if (s == "")
//		throw string("s is empty!");
//
//
//	for (int i = 0; i <= (int)(t.length() - s.length()); i++)
//	{
//		string v = t.substr(i, s.length()); //создаем новую подстроку v
//
//		if (v == s)
//			return 1;
//	}
//
//	return -1;
//}

int FindSubstring(string s, string t)
{
	if (s == "")
		throw string("s is empty!");

	int i = 0;

	do 
	{
		int j = 0;
		while (t[i + j] == s[j++])
		{
			if (j == s.length())
				return 1;
		}

		i += j;

	} while (i < t.length());

	return -1;
}