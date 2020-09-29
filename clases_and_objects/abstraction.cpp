#include <iostream>
using namespace std;

class sample {
public:
    int gl, g2;

public:
    void val()
    {
        cout << "Enter Two values : "; cin >> gl >> g2;
    }
    void display()
    {
        cout << gl << " " << g2;
        cout << endl;
    }
};
int main()
{
    sample S;
    S.val();
    S.display();
}
