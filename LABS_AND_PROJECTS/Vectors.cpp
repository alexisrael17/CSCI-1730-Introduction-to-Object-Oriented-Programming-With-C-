// This program will do mathematical operations with vectors and complex numbers

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void cactions();
void vactions();

class Pairs{

protected:
    float partA, partB;

public:
    Pairs( ) : partA(0.0), partB(0.0) {/*Body left intentionally blank*/}
    Pairs(float valueA, float valueB) : partA(valueA), partB(valueB) {/*Body left intentionally blank*/}

    const Pairs operator +(const Pairs& pair2);
    const Pairs operator -(const Pairs& pair2);
    bool operator ==(const Pairs& pair2);

};

const Pairs Pairs::operator +(const Pairs& pair2)
{
    return Pairs((partA + pair2.partA), (partB + pair2.partB));
}

const Pairs Pairs::operator -(const Pairs& pair2)
{
    return Pairs((partA - pair2.partA), (partB - pair2.partB));
}

bool Pairs::operator ==(const Pairs& pair2)
{
    if(abs(partA - pair2.partA) <= 0.000001 && abs(partB - pair2.partB) <= 0.000001)
        return true;
    else
        return false;
}

class Complex : public Pairs{

public:
    Complex( ) : Pairs( ) {/*Body left intentionally blank*/}
    Complex(float rPart, float iPart) : Pairs(rPart, iPart) {/*Body left intentionally blank*/}

    const Complex operator *(const Complex& number2);
    const Complex operator /(const Complex& number2);
    friend ostream& operator <<(ostream& outs, const Complex& number2);
	friend istream& operator >>(istream& ins, Complex& number2);
	using Pairs::operator =;

};

istream& operator >>(istream& ins, Complex& number2)
{
	char i;
	cin >> number2.partA >> number2.partB >> i;
}

ostream& operator <<(ostream& outs, const Complex& number2)
{
	cout << number2.partA;
	if (number2.partB >=0)
	{
		cout << "+" << number2.partB << "i";
	}
	else
	{
		cout << number2.partB << "i ";
	}
}

const Complex Complex::operator *(const Complex& number2)
{
    float temp = (partA * number2.partA) - (partB * number2.partB);
    float imaginary = (partA * number2.partB) + (partB * number2.partA);
    float real = temp;

    return Complex(real, imaginary);
}

const Complex Complex::operator /(const Complex& number2)
{
    float temp = ((partA * number2.partA) + (partB * number2.partB)) / (pow(number2.partA, 2.0) + pow(number2.partB, 2.0));
    float imaginary = ((partB * number2.partA) - (partA * number2.partB)) / (pow(number2.partA, 2.0) + pow(number2.partB, 2.0));
    float real = temp;

    return Complex(real, imaginary);
}

class Vect : public Pairs{

public:
    Vect( ) : Pairs( ) {/*Body intentionally left blank*/}
    Vect(float partA, float partB) : Pairs(partA, partB) {/*Body left intentionally blank*/}

    const Vect operator *(float r);
    float operator *(Vect vector2);
    friend ostream& operator <<(ostream& outs, const Vect& number2);
	friend istream& operator >>(istream& ins, Vect& number2);
	using Pairs::operator =;

};

istream& operator >>(istream& ins, Vect& number2)
{
	char i;
	cin >> i >> number2.partA >> i >> number2.partB >> i;
}

ostream& operator <<(ostream& outs, const Vect& number2)
{
	cout << "<" << number2.partA << "," << number2.partB << ">";
}

const Vect Vect::operator *(float r)
{
    return Vect((partA * r), (partB * r));
}

float Vect::operator *(Vect vector2)
{
    return ((partA * vector2.partA) + (partB * vector2.partB));
}

int main()
{
    int sel;
    do{
        cout << "Select an option  (1) perform complex number actions\n";
        cout << "                  (2) perform vector actions\n";
        cout << "                  (3) exit\n";
        cin >> sel;
        if (sel == 1)
            cactions();
        else if (sel == 2)
            vactions();
        else if (sel == 3)
            cout << "Bye...\n";
        else
            cout << "Invalid input - try again\n";
    } while (sel != 3);
    char ch; cin >> ch;
    return 0;
}


void cactions()
{
    Complex numberArray[26];
    Complex temp;
    int index1, index2, index3, sel;

    do{
        cout << "Select an option - (1) Enter a complex number\n";
        cout << "                   (2) Display a complex number\n";
        cout << "                   (3) Perform arithmetic or\n";
        cout << "                       equality comparison of complex numbers\n";
        cout << "                   (4) Exit\n";
        cin >> sel;
        if (sel == 1)
        {
            cout << "Enter the location the complex number will be stored (Enter 1-26): ";
            cin >> index1;
            index1--;
            cout << "Enter the complex number in standard form (a+bi): ";
            cin >> temp;
            numberArray[index1] = temp;
        }
        else if (sel == 2)
        {
            cout << "Enter the location of the complex number (Enter 1-26): ";
            cin >> index1;
            index1--;
            cout << endl << "The complex number in location " << index1 + 1 << " is " << numberArray[index1] << endl << endl;
        }
        else if (sel == 3)
        {
            char oper;
            cout << "Which operation do you want to do (+,-,*,/,=): ";
            cin >> oper;

            switch (oper)
            {
            case '+':
                cout << "Enter the location of the first complex number (Enter 1-26): ";
                cin >> index1;
                index1--;
                cout << "Enter the location of the second complex number: ";
                cin >> index2;
                index2--;
                cout << "Enter the location to store the result: ";
                cin >> index3;
                index3--;

                numberArray[index3] = numberArray[index1] + numberArray[index2];
            break;

            case '-':
                cout << "Enter the location of the first complex number (Enter 1-26): ";
                cin >> index1;
                index1--;
                cout << "Enter the location of the second complex number: ";
                cin >> index2;
                index2--;
                cout << "Enter the location to store the result: ";
                cin >> index3;
                index3--;

                numberArray[index3] = numberArray[index1] - numberArray[index2];
            break;

            case '*':
                cout << "Enter the location of the first complex number (Enter 1-26): ";
                cin >> index1;
                index1--;
                cout << "Enter the location of the second complex number: ";
                cin >> index2;
                index2--;
                cout << "Enter the location to store the result: ";
                cin >> index3;
                index3--;

                numberArray[index3] = numberArray[index1] * numberArray[index2];
            break;

            case '/':
                cout << "Enter the location of the first complex number (Enter 1-26): ";
                cin >> index1;
                index1--;
                cout << "Enter the location of the second complex number: ";
                cin >> index2;
                index2--;
                cout << "Enter the location to store the result: ";
                cin >> index3;
                index3--;

                numberArray[index3] = numberArray[index1] / numberArray[index2];
            break;

            case '=':
                cout << "Enter the location of the first complex number (Enter 1-26): ";
                cin >> index1;
                index1--;
                cout << "Enter the location of the second complex number: ";
                cin >> index2;
                index2--;

                if (numberArray[index1] == numberArray[index2])
                    cout << "The complex numbers are equal.\n";
                else
                    cout << "The complex numbers are not equal.\n";
            break;

            default:
                cout << "Entry not recognized!";
            }
        }
        else if (sel == 4)
        {
            cout << "Bye...\n";
        }
    } while (sel != 4);
}

void vactions()
{
    Vect numberArray[26];
    Vect temp;
    int index1, index2, index3, sel;
    float scalar = 0.0;

    do{
        cout << "Select and option - (1) Enter a vector\n";
        cout << "                    (2) Display a vector\n";
        cout << "                    (3) Display a scalar\n";
        cout << "                    (4) Perform arithmetic or equality comparisons of vectors\n";
        cout << "                    (5) Exit\n";
        cin >> sel;

        if (sel == 1)
        {
            cout << "Enter the location the vector will be stored (Enter 1-26): ";
            cin >> index1;
            index1--;
            cout << "Enter the vector in vector form <a,b>: ";
            cin >> temp;
            numberArray[index1] = temp;
        }
        else if (sel == 2)
        {
            cout << "Enter the location of the vector (Enter 1-26): ";
            cin >> index1;
            index1--;
            cout << endl << "The vector in location " << index1 + 1 << " is " << numberArray[index1] << endl << endl;
        }
        else if (sel == 3)
        {
            cout << "The scalar is " << scalar << "." << endl;
        }
        else if (sel == 4)
        {
            char oper;
            cout << "Which operation do you want to do?\n";
            cout << "[+, -, =, .(for dot product), *(for vector/scalar multiplication)]: ";
            cin >> oper;

            switch (oper)
            {
            case '+':
                cout << "Enter the location of the first vector: ";
                cin >> index1;
                index1--;
                cout << "Enter the location of the second vector: ";
                cin >> index2;
                index2--;
                cout << "Enter the location to store the result: ";
                cin >> index3;
                index3--;
                numberArray[index3] = numberArray[index1] + numberArray[index2];
            break;

            case '-':
                cout << "Enter the location of the first vector: ";
                cin >> index1;
                index1--;
                cout << "Enter the location of the second vector: ";
                cin >> index2;
                index2--;
                cout << "Enter the location to store the result: ";
                cin >> index3;
                index3--;
                numberArray[index3] = numberArray[index1] - numberArray[index2];
            break;

            case '=':
                cout << "Enter the location of the first vector: ";
                cin >> index1;
                index1--;
                cout << "Enter the location of the second vector: ";
                cin >> index2;
                index2--;

                if (numberArray[index1] == numberArray[index2])
                    cout << "The vectors are equal.";
                else
                    cout << "The vectors are not equal.";
            break;

            case '.':
                cout << "Enter the location of the first vector: ";
                cin >> index1;
                index1--;
                cout << "Enter the location of the second vector: ";
                cin >> index2;
                index2--;

                scalar = numberArray[index1] * numberArray[index2];
            break;

            case '*':
                char yn;
                cout << "Enter the location of the first vector: ";
                cin >> index1;
                index1--;
                cout << "Enter the location to store the result: ";
                cin >> index3;
                index3--;
                cout << "The current value of the scalar is " << scalar << ".\n";
                cout << "Do you want to change the value? ";
                cin >> yn;
                yn = toupper(yn);
                if (yn == 'Y')
                {
                    cout << "Enter the new value for the scalar: ";
                    cin >> scalar;
                    numberArray[index3] = numberArray[index1] * scalar;
                }
                else if (yn == 'N')
                    numberArray[index3] = numberArray[index1] * scalar;
                else
                    cout << "invalid Entry\n";
            break;

            default:
                cout << "Entry not recognized!";
            }
        }
        else if (sel == 5)
        {
            cout << "Bye...\n";
        }
    } while (sel != 5);
}
