#include <iostream>
#include <stdlib.h>
#include <string>
#include "TStack.h"
#include "TCalculator.h"
using namespace std;

//bool Skobki(const string& c)
//{
//	TStack<int> s;
//	for (int i = 0; i < c.size(); i++)
//	{
//		if (c[i] == '(')
//			s.Push(1);
//		if (c[i] == ')')
//		{
//			if (s.Empty())
//				return false;
//			s.Pop();
//		}
//	}
//	return(s.Empty());
//}


// �������� ����� ����������� � ���������� � ���������� �� ����������� ������
void main()
{
	//��� ����, ��� ��������(+-*/^)������
	TCalculator calc("22+");
	//string s = "(()()()()())";
	//cout << Skobki(s);
}

//   1/(((2+2)*2)-3) =?
//   1/((2+5)*(4-3)) = 1 2 5 + 4 3 - * /  ���������, ����������� ����� ������
//   ��1 ��2 *
//   ������ �������� � ����, ���� �������� - ������� �� ����� 2 ��������, ��������� ������ � ����
//   ���� �������� ���� ����� � ������ ���� - �� ��, ������ ���
//   ���� �������� �����, �� ������� ������� �� ������� �����