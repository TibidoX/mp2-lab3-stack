#include <string>
#include <iostream>
#include "TCalculator.h"

using namespace std;
void main()
{
	//TCalculator c("(1/((2+5)*(4-3)))^2");
	TCalculator c("1+2*(3-2)-4");
	//c.SetE("2+2");
	c.ToPostfix();
	cout << c.GetP() << endl;
	cout << c.calc();
	//cout << c.calc();
}


//������� ��������!
//����� ���� ���� �������, ���� ������� � ���������� �� ���� ������� �� ������� �� ���� �������� � ������





//console app+test+graph