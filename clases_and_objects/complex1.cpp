#include <iostream>
        using namespace std;
        class Complex
        {
        private:
            double real;
            double imaginary;
        public:
            Complex();
            Complex(double r, double i = 0);
            Complex operator*(const Complex & c) const;
            Complex operator*(double mult) const;
//           Complex operator*(double m, const Complex & c)
//                   { return c * m; }
    //      ostream & operator<<(ostream & os, Complex & c)
//           {os << c.real <<"," << c.imaginary; return os;}

        };
        Complex::Complex()
        {
            real = imaginary = 0;
        }

        Complex::Complex(double r, double i )
        {
            real = r;
            imaginary = i;
        }
        Complex Complex::operator*(const Complex & c) const

        {
            Complex mult;
            mult.imaginary = imaginary * c.imaginary;
            mult.real = real * c.real;
            return mult;
        }

        Complex Complex::operator*(double mult) const
        {
            Complex result;
            result.real = real * mult;
            result.imaginary = imaginary * mult;
            return result;
        }
        int main()
        {
            Complex B(5, 40);
            Complex C(6, 15);
            cout << "B, and C:\n";
//            cout << B << ": " << C << endl;
//            cout << "B * C: " << B*C << endl;
//            cout << "10 * B: " << 10*B << endl;
            return 0;
        }
