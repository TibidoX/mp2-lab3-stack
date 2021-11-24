#pragma once
#include "TStack.h"

class TCalculator
{
	string expr;
	string postfix;
	TStack<char> s_char;
	TStack<double> s_double;
	
	int Priority(char op)
	{
		if (op == '(') return 0;
		else if (op == '+' || op == '-') return 1;
		else if (op == '*' || op == '/') return 2;
		else if (op == '^') return 3;
		else return 100; 
	}
	

public:
	TCalculator(string p=" ")
	{
		//postfix = p;
		expr = p;
		TStack<char> sc(expr.size());
		TStack<double> sd(expr.size());
		s_char = sc;
		s_double = sd;
	}
	TCalculator(const TCalculator& c)
	{
		expr = c.expr;
		postfix = c.postfix;
		TStack<char> sc(c.s_char);
		TStack<double> sd(c.s_double);
		s_char = sc;
		s_double = sd;
	}

	bool operator==(const TCalculator& c) const { return (expr == c.expr); }

	void SetE(const string& c) { expr = c; }
	//void SetP(const string& c) { postfix = c; }
	string GetE() { return expr; };
	string GetP() { return postfix; }
	double calc()
	{
		for (int i = 0; i < postfix.size(); i++)
		{
			if (postfix[i] <= '9' && postfix[i] >= '1')
				s_double.Push(postfix[i] - '0');
			if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
			{
				if (s_double.Empty())
					throw - 1;
				double a = s_double.Pop();
				double b = s_double.Pop();
				switch (postfix[i])
				{
				case '+':
					s_double.Push(a + b);
					break;
				case '-':
					s_double.Push(b - a);
					break;
				case '*':
					s_double.Push(a * b);
					break;
				case '/':
					s_double.Push(b / a);
					break;
				case '^': {
					double res = 1;
					for (int i = 0; i < a; i++)
						res *= b;
					s_double.Push(res);
					break; }
				default:
					throw 0;
					break;
				}
			}
		}
		return s_double.Pop();
	}
	void ToPostfix()
	{
		string infix = "(" + expr + ")";
		s_char.Clear();
		//postfix = "";
		//s_char.Push(' ');
		for (int i = 0; i < infix.size(); i++)
		{
			if (infix[i] <= '9' && infix[i] >= '1')
				postfix += infix[i];

			if (infix[i] == '(') s_char.Push('(');
			if (infix[i] == ')') {
				while (s_char.Top() != '(')
					postfix += s_char.Pop();
				s_char.Pop();
			}

			if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
				int prior = Priority(infix[i]);
				while (Priority(s_char.Top()) >= Priority(infix[i]))
					postfix += s_char.Pop();
				s_char.Push(infix[i]);
			}
		}
	}

	double calcInfix()
	{
		string infix = "(" + expr + ")";
		for (int i = 0; i < infix.size(); i++)
		{
			if (infix[i] >= '0' && infix[i] <= '9')
				s_double.Push(infix[i] - '0');
			if (infix[i] == '(')
				s_char.Push('(');
			if (infix[i] == ')') 
			{
				while (s_char.Top() != '(') 
				{
					double a = s_double.Pop();
					double b = s_double.Pop();
					switch (s_char.Pop()) 
					{
						{
					case '+':
						s_double.Push(a + b);
						break;
					case '-':
						s_double.Push(b - a);
						break;
					case '*':
						s_double.Push(a * b);
						break;
					case '/':
						s_double.Push(b / a);
						break;
					case '^': {
						double res = 1;
						for (int i = 0; i < a; i++)
							res *= b;
						s_double.Push(res);
						break; }
					default:
						throw 0;
						break;
						}
					}
				}
				s_char.Pop();
			}
			if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') 
			{
				while (Priority(s_char.Top()) >= Priority(infix[i]))
				{
					double a = s_double.Pop();
					double b = s_double.Pop();
					switch (s_char.Pop()) 
					{
						{
					case '+':
						s_double.Push(a + b);
						break;
					case '-':
						s_double.Push(b - a);
						break;
					case '*':
						s_double.Push(a * b);
						break;
					case '/':
						s_double.Push(b / a);
						break;
					case '^': {
						double res = 1;
						for (int i = 0; i < a; i++)
							res *= b;
						s_double.Push(res);
						break; }
					default:
						throw 0;
						break;
						}
					}
				}
				s_char.Push(infix[i]);
			}
		}
		return s_double.Pop();
	}
};


