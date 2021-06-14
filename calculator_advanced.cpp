/*
Author : elderny (elderny1 from telegram)
Usage: Advance Calculator with 2 options simple, and scientific
date: 13/06/2021
purpose: practice
*/

#include <iostream>
#include <cmath>
using namespace std;

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

// SCIENTIFIC CALCULATOR CLASS
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
        case 8:
            cout << "The tan of "<<a<<" is "<< tan(a) << endl;
            cout << "The tan of "<<b<<" is "<< tan(b) << endl;
            break;
        case 9:
            cout << "The cos of "<<a<<" is "<<cos(a) << endl;
            cout << "The cos of "<<b<<" is "<<cos(b) << endl;
            break;

        default:
            break;
        }
    }
};

// This will display those two calculator classes
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
    //this will put any calculator in use depending upon users input
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
//This will just give a bit of information about usage
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

    //asking which calculator to use
    cin >> ask;

    //applying that input here
    elderny.slct_type(ask);

    //asking for numbers
    cout << "\nType your first number:\nNo: ";
    cin >> num1;

    cout << "\nType your second number:\nNo: ";
    cin >> num2;

    //displaying the options in calculators
    type_checking(ask);
    cin >> sign;
    cout << endl;

    //collecting the user inputs together
    elderny.input_value(num1, num2, sign);

    //putting everything together and showing the results
    cout << "\n\n<---- RESULTS ---->\n\n";
    elderny.start_calc();
    return 0;
}
