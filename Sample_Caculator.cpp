#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
string operation[] = { "+","-","*","/","sin","cos","pow","abs","sqrt"};
int operationSize = 9;
string op;
float addition(float value1, float value2) {
	return value1 + value2;
}
float subtraction(float value1, float value2) {
	return value1 - value2;
}
float multiplication(float value1, float value2) {
	return value1 * value2;
}
float division(float value1, float value2) {
	return value1 / value2;
}
float powCaculator(float value1, float value2) {
	return pow(value1, value2);
}
float absCaculator(float value1) {
	return abs(value1);
}
float sqrtCaculator(float value1) {
	if (value1 < 0) {
		cout << "Invalid";
		return -1;
	}
	else
		return sqrt(value1);
}

float GetUserInput() {
	float value;
	cout << "Input your value:		";
	cin >> value;
	return value;
}
string GetOperation() {

	cout << "Input Operator:(Enter the operation)\n";
	cout << "- Addition			(+)\n";
	cout << "- Subtraction		(-)\n";
	cout << "- Multiplication	(*)\n";
	cout << "- Division			(/)\n";
	cout << "- Sin				(sin)\n";
	cout << "- Cos				(cos)\n";
	cout << "- Pow				(pow)\n";
	cout << "- Abs				(abs)\n";
	cout << "- Sqrt				(sqrt)\n";
	cout << "Enter it:		";
	cin >> op;
	return op;	
}
int compareOperation()
{
	
	for (int i = 0; i < operationSize; i++)
	{
		if (op == operation[i]) 
			return i;
	}
	return -1;

}
void printResult(float result) {

	cout << "Result: " << result << endl;
}
void Caculator(string operation[], int operationSize){
	float value1, value2;
	float result;
	GetOperation();
	int indexOp = compareOperation();
	switch (indexOp)
	{
	case 0:
		value1 = GetUserInput();
		value2 = GetUserInput();
		result = addition(value1, value2);
		break;
	case 1:
		value1 = GetUserInput();
		value2 = GetUserInput();
		result = subtraction(value1, value2);
		break;
	case 2:
		value1 = GetUserInput();
		value2 = GetUserInput();
		result = multiplication(value1, value2);
		break;
	case 3:
		value1 = GetUserInput();
		value2 = GetUserInput();
		result = division(value1, value2);
		break;
	case 4:
		value1 = GetUserInput();
		result = sin(value1);
		break;
	case 5:
		value1 = GetUserInput();
		result = cos(value1);
		break;
	case 6:
		value1 = GetUserInput();
		value2 = GetUserInput();
		result = powCaculator(value1, value2);
		break;
	case 7:
		value1 = GetUserInput();
		result = absCaculator(value1);
		break;
	case 8:
		value1 = GetUserInput();
		result = sqrtCaculator(value1);
		break;

	default:
		cout << "This operation is not defined yet!!! Please try again." << endl;
		system("pause");
		return;
	}
	printResult(result);
}

int main()
{
	int number;
	
	cout << "-----Welcome to sample calculator-----\n";
	cout << "		Please choose your opinion:\n";
	cout << "		1. Calculator\n";
	cout << "		2. Other program\n";
	cout << "		3. Exit program\n";
	cout << "Input 1 or 2 for your purpose:		";
	cin >> number;
	switch (number) {
	case 1:
		Caculator(operation,operationSize);
		break;
	case 2:
		cout << "This extension will be update soon, stay tuned!";
		break;
	case 3: 
		cout << "Closed";
		break;
	default:
		cout << "Invalid Input! Collapse App";
		break;
	}
	return 0;
}