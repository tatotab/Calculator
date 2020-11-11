///Dimitri Tabagari
///Jan 29, 2020
///Calculator Assignment

#include <iostream>

using namespace std;



void addition(double *num1, double *num2) {
    cout << *num1 + *num2 << endl;
}
void subtraction(double *num1, double *num2) {
    cout << *num1 - *num2 << endl;
}
void multiplication(double *num1, double *num2) {
    cout << (*num1) * (*num2) << endl;
}
void division(double *num1, double *num2) {
    cout << *num1 / (*num2) << endl;
}
void calculator(char *choice, double *num1, double *num2) {

    cout << "Welcome to C++ Calculator " << endl;
    while(1){

        cout << "Choose the operation for Calculation (type + - * OR /):" << endl;
        cout << "--to quit press any other character--" << endl;
        cin >> *choice;
        if (!(*choice == '+' || *choice == '-' || *choice == '*' || *choice == '/')) {
            break;
        }
        cout << "Enter Numbers, separate with space:" << endl;
        cin >> *num1;
        cin >> *num2;
        while (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "You can only enter numbers.\n";
            cout << "Enter Numbers, separate with space:\n";
            cin >> *num1;
            cin >> *num2;
        }

        
        if (*num2 == 0 && *choice == '/') {
            cout << "you cannot divide by 0, please change denominator:" << endl;
            cin >> *num2;
        }

        switch (*choice) {
        case '+':
            addition(num1, num2);
            break;
        case '-':
            subtraction(num1, num2);
            break;
        case '*':
            multiplication(num1, num2);
            break;
        case '/':
            division(num1, num2);
            break;
        default:
            cout << "GoodBye" << endl;
            break;
        }
        
        

    }
}
int main()
{
    char *choice = new char();
    double *num1 = new (nothrow) double;
    double *num2 = new (nothrow) double;
    
    if (num1 && num2 && choice) {  ///check none ptr is empty
        calculator(choice, num1, num2);
    }
    else {
        cout << "No space in Heap, try later" << endl;
    }
    delete choice;
    delete num1;
    delete num2;

}