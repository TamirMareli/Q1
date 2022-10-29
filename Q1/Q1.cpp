#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 3

typedef struct Expression {
	char sign;
	char* arrNums[SIZE];
}Expression;

void createExpression(Expression & exp);
int sizeOfNum(int num);
char* toString(int num);
void calculation(Expression& exp);
int convert(char* str);
void printExpression(const Expression exp);


void main() {
	Expression exp;
	createExpression(exp);
	calculation(exp);
	printExpression(exp);
	for (int i = 0; i < SIZE; i++)
		delete[] exp.arrNums[i];
}

void createExpression(Expression& exp) {
	int num1, num2;
	cout << "Enter two nums" << endl;
	cin >> num1, cin >> num2;
	cout << "Enter math expression" << endl;
	cin >> exp.sign;
	exp.arrNums[0]=toString(num1);
	exp.arrNums[1]=toString(num2);

}
void calculation(Expression& exp) {
	int num1, num2, res;
	num1 = convert(exp.arrNums[0]);
	num2 = convert(exp.arrNums[1]);

	switch (exp.sign)
	{
	case ('+'):
		res = num1 + num2;
		break;

	case ('-'):
		if ((num1 - num2) < 0)
			res = num2 - num1;
		else
			res = num1 - num2;
		break;

	case ('*'):
		res = num1 * num2;
		break;

	case('/'):
		if (num2 == 0) {
			cout << "error" << endl;
			exit(1);
		}
		res = num1 / num2;
		break;

	case('%'):
		res = num1 % num2;
		break;
		
	default: 
		cout << "sign illegal" << endl;
		exit(1);
		break;
	}
	exp.arrNums[2] = toString(res);
}

void printExpression(const Expression exp){
	cout << exp.arrNums[0] << " " << exp.sign << " " << exp.arrNums[1] << " = " << exp.arrNums[2] << endl;
}

int sizeOfNum(int num) {
	if (num == 0)
		return 1;
	int sum = 0;
	while (num != 0) {
		num = num / 10;
		sum++;
	}
	return sum;
}

char* toString(int num) {
	int size = sizeOfNum(num);
	char* s = new char[size + 1];
	s[size] = '\0';
	for (int i = size; i >0; i--) {
		s[i-1] = '0' + (num % 10);
		num = num / 10;
	}
	return s;
}

int convert(char* str) {
	int i = 0,sum=0;
	while (str[i] != '\0') {
		sum = sum * 10 + (str[i] - '0');
		i++;
	}
	return sum;
}