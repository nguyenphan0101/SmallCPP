#include<iostream>
#include<iomanip>
using namespace std;
const char ID[30] = "nguyenphan0101";
const char password[20] = "maiphuongbeovcl";
char x[30];
char y[20];
int dem = 0;

int main() {

	do {
		dem++;
		if (dem > 1) { cout << "Invalid Account! Please check your account!!!!" << endl; }
		if (dem == 5) { 
			cout << "You cant logging right now! Sorry!"; 
			break; 
		}
		cout << "Please enter your account: " << endl << "ID: ";
		cin >> x;
		cout << "Password: ";
		cin >> y;
	} while (strcmp(ID, x) != 0 || strcmp(password, y) != 0 );
	if (strcmp(ID, x) == 0 && strcmp(password, y) == 0)
	{
		cout << "Login successfully!. Wellcome back " << x;
	}
	else return 0;
	
	return 0;
} 