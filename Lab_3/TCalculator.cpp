#include "TCalculator.h"
#include  <string>

//TCalculator::TCalculator(string p)
//{
//	//postfix = p;
//	expr = p;
//	TStack<char> sc(expr.size());
//	TStack<double> sd(expr.size());
//	s_char = sc;
//	s_double = sd;
//}
//TCalculator::TCalculator(const TCalculator& c)
//{
//	postfix = c.postfix;
//	TStack<char> sc(c.s_char);
//	TStack<double> sd(c.s_double);
//	s_char = sc;
//	s_double = sd;
//}
//void TCalculator::SetE(const string& c) { expr = c; }
//void TCalculator::SetP(const string& c) {postfix = c;}
//string TCalculator::GetP() { return postfix; }
//bool TCalculator::Skobki()
//{
//	TStack<int> s;
//	for (int i = 0; i < expr.size(); i++)
//	{
//		if (expr[i] == '(')
//			s.Push(1);
//		if (expr[i] == ')')
//		{
//			if (s.Empty())
//				return false;
//			s.Pop();
//		}
//	}
//	return(s.Empty());
//}
//double TCalculator::calc()
//{
//	for (int i = 0; i < postfix.size(); i++)
//	{
//		if (postfix[i] <= '9' && postfix[i] >= '1')
//			s_double.Push(postfix[i]-'0');
//		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
//		{
//			if (s_double.Empty())
//				throw - 1;
//			double a = s_double.Pop();
//			double b = s_double.Pop();
//			switch (postfix[i])
//			{
//			case '+':
//				s_double.Push(a + b);
//				break;
//			case '-':
//				s_double.Push(b - a);
//				break;
//			case '*':
//				s_double.Push(a * b);
//				break;
//			case '/':
//				s_double.Push(b / a);
//				break;
//			case '^': {
//				double res = 1;
//				for (int i = 0; i < a; i++)
//					res *= b;
//				s_double.Push(res);
//				break; }
//			default:
//				throw 0;
//				break;
//			}
//		}
//	}
//	return s_double.Pop();
//}
//
//void TCalculator::ToPostfix()
//{
//	string infix = "(" + expr + ")";
//	s_char.Clear();
//	for (int i = 0; i < infix.size(); i++)
//	{
//		if (infix[i] <= '9' && infix[i] >= '1')
//			postfix += infix[i];
//
//		if (infix[i] == '(') s_char.Push('(');
//		if (infix[i] == ')') {
//			while (s_char.Top() != '(')
//				postfix += s_char.Pop();
//			s_char.Pop();
//		}
//
//		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
//			int prior = Priority(infix[i]);
//			while (Priority(s_char.Top() <= Priority(infix[i])))
//				postfix += s_char.Pop();
//			s_char.Push(infix[i]);
//		}
//	}
//}