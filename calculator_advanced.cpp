#include <iostream>
#include <cmath>
using namespace std;
/*
Create 2 classes:
    1. SimpleCalculator - Takes input of 2 numbers using a utility function and perfoms +, -, *, / and displays the results using another function.
    2. ScientificCalculator - Takes input of 2 numbers using a utility function and perfoms any four scientific operation of your chioice and displays the results using another function.

    Create another class HybridCalculator and inherit it using these 2 classes:
    Q1. What type of Inheritance are you using?
    Q2. Which mode of Inheritance are you using?
    Q3. Create an object of HybridCalculator and display results of simple and scientific calculator.
    Q4. How is code reusability implemented?
*/

class SimpleCalculator
{
protected:
    int a, b, s;

public:
    void ask_num(int num1, int num2, int sign)
    {
        a = num1;
        b = num2;
        s = sign;
    }
    void calc(void)
    {
        switch (s)
        {
        case 1:
            cout << "The result of adding " << a << " with " << b << " is " << a + b << endl;
            break;
        case 2:
            cout << "The result of subtracting " << a << " from " << b << " is " << a - b << endl;
            break;
        case 3:
            cout << "The result of Multiplying " << a << " with " << b << " is " << a * b << endl;
            break;
        case 4:
            cout << "The result of dividing " << a << " with " << b << " is " << a / b << endl;
            break;

        default:
            break;
        }
    }
};

class ScientificCalculator : virtual public SimpleCalculator
{
public:
    void calc_advance(void)
    {
        switch (s)
        {
        case 1:
            cout << "The result of adding " << a << " with " << b << " is " << a + b << endl;
            break;
        case 2:
            cout << "The result of subtracting " << a << " from " << b << " is " << a - b << endl;
            break;
        case 3:
            cout << "The result of Multiplying " << a << " with " << b << " is " << a * b << endl;
            break;
        case 4:
            cout << "The result of dividing " << a << " with " << b << " is " << a / b << endl;
            break;
        case 5:
            cout << "The Root of Number " << a << " is " << sqrt(a) << endl;
            cout << "The Root of Number " << b << " is " << sqrt(b) << endl;
            break;
        case 6:
            cout << "The Square of Number " << a << " is " << pow(a, 2) << endl;
            cout << "The Square of Number " << b << " is " << pow(b, 2) << endl;
            break;
        case 7:
            cout << "The Cube of Number " << a << " is " << pow(a, 3) << endl;
            cout << "The Cube of Number " << b << " is " << pow(b, 3) << endl;
            break;

        default:
            break;
        }
    }
};

class hybridCalculator : virtual public SimpleCalculator, public ScientificCalculator
{
protected:
    int display;
    int x, y, z;

public:
    void slct_type(int show)
    {
        display = show;
    }
    void input_value(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
    void start_calc()
    {
        if (display == 1)
        {
            SimpleCalculator::ask_num(x, y, z);
            calc();
        }
        else if (display == 2)
        {
            ScientificCalculator::ask_num(x, y, z);
            calc_advance();
        }
    }
};

void type_checking(int ask_value)
{
    if (ask_value == 1)
    {
        cout << "\n------You are using Simple Calculator------\n"
             << endl;
        cout << "Type '1' to add, '2' to subtract, '3' to multiply, '4' to divide your numbers\nType here: ";
    }
    else if (ask_value == 2)
    {
        cout << "\n------You are using Scientific Calculator------\n"
             << endl;
        cout << "Type '1' to add, '2' to subtract, '3' to multiply, '4' to divide, '5' to root, '6' to square, '7' to cube your numbers\nType here: ";
    }
}
int main()
{
    int ask, num1, num2, sign;
    hybridCalculator elderny;
    cout << "\nWelcome to the calculator made by Elderny\n"
         << endl;
    cout << "Type '1' to use Simple Calculator or Type '2' to use Scientific calculator\nType Here: ";
    cin >> ask;
    elderny.slct_type(ask);
    cout << "\nType your first number:\nNo: ";
    cin >> num1;
    cout << "\nType your second number:\nNo: ";
    cin >> num2;
    type_checking(ask);
    cin >> sign;
    cout << endl;
    elderny.input_value(num1, num2, sign);
    cout << "\n\n<---- RESULTS ---->\n\n";
    elderny.start_calc();
    return 0;
}