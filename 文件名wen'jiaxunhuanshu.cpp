open 1.13.6


#include<iostream>
#include<string>
using namespace std;
string num, judge, s;
int ch[70] = { 0 }, arr[70] = { 0 };
int t = 0;
int f = 0;
int main()
{
	cin >> num;
	judge = num + num;
	int len = num.size();
	int ch[70] = { 0 }, arr[70] = { 0 };
	int t = 0;
	int f = 0;
	for (int i = 0;i < len;i++)
	{
		ch[i] = num[i] - '0';
	}
	for (int i = 1;i <= len;i++)
	{
		for (int j = 0;j < len;j++)
		{
			arr[j] = ch[j];
		}
		for (int j = len - 1;j >= 0;j--)
		{
			arr[j] = arr[j] * i + t;
			t = arr[j] / 10;
			arr[j] = arr[j] % 10;
		}
		s = "";
		for (int q = 0;q < len;q++)
		{
			s = s+(char)(arr[q] + '0');
		}
		f = judge.find(s, 0);
		if (f == -1)
		{
			cout << '0';
			return 0;
		}
	}
	cout << '1';
	return 0;
}
