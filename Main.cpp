#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
		while (true)
		{
			Fraction f1;
			Fraction f2;
			Fraction result;
			char operation;

			while (true)
			{
				try
				{
					cout << "Enter the first fraction: " << endl;
					cin >> f1;
					break;
				}

				catch (...)
				{
					cout << "The denominator cannot be zero, try again" << endl;
				}
			}

			cout << "\nSelect operation (+ - * /): " << endl;
			cin >> operation;
			
			while (true)
			{
				try
				{
					cout << "\nEnter the second fraction: " << endl;
					cin >> f2;
					break;
				}

				catch (...)
				{
					cout << "The denominator cannot be zero, try again" << endl;
				}
			}

			switch (operation)
			{
				case '+':
					result = f1 + f2;
					break;

				case '-':
					result = f1 - f2;
					break;

				case '*':
					result = f1 * f2;
					break;

				case '/':
					try
					{
						result = f1 / f2;
						break;
					}

					catch (...)
					{
						cout << "Division by zero" << endl;
						break;
					}

				default:
					cout << "Entered incorrectly, try again\n" << endl;
					break;
			}

			cout << "\nResult: " << result << endl;
			char choice;
			cout << "Want to calculate again ? (Y / N)" << endl;
			cin >> choice;
			if ((choice != 'y' && choice != 'Y')) { break; }
		}
		return 0;
}
	
	
