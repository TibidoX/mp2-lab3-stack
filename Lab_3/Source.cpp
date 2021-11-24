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


// оформить класс калькуляиор с проверками и вычисления по постфиксной записи
void main()
{
	//выч знач, сод операции(+-*/^)скобки
	TCalculator calc("22+");
	//string s = "(()()()()())";
	//cout << Skobki(s);
}

//   1/(((2+2)*2)-3) =?
//   1/((2+5)*(4-3)) = 1 2 5 + 4 3 - * /  инфиксная, постфиксная форма записи
//   ор1 ор2 *
//   кладем операнды в стек, если операция - достаем из стека 2 операнда, результат кладем в стек
//   если извлекли одно число и пустой стек - то ок, ииначе нет
//   если операций много, то попытка извлечь из пустого стека