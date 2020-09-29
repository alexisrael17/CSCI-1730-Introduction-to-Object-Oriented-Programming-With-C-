#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

class Distance {
    private:
        int feet;
        int inches;
    public:
        Distance() {
            feet = 0;
            inches = 0;
        }
        Distance(int f, int i) {
            feet = f;
            inches = i;
        }
        friend ostream &operator<<( ostream &output, const Distance &D ) {
            output << D.feet << "\'" << D.inches << "\"" << endl;
            return output;
        }
        friend istream &operator>>( istream &input, const Distance &D ) {
            input >> D.feet >> D.inches;
            return input;
        }
};

int main() {
    Distance D1(11,10), D2(5,11), D3;
    cin >> D3;
    cout << "First Distance : " << D1 << endl;
    cout << "Second Distance : " << D2 << endl;
    cout << "Third Distance : " << D3 << endl;
    return 0;
}
