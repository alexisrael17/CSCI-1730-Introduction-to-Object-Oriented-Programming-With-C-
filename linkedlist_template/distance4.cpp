#include <iostream>
#include <string>

using namespace std;

class Distance
{
  private:
   int feet;
   float inches;
  public:
   Distance() : feet(0), inches(0.0)
   { }
   Distance(int ft, float in) : feet(ft), inches(in)
   { }
   friend istream& operator >> (istream& s, Distance& d);
   friend ostream& operator << (ostream& s, Distance& d);
};

istream& operator >> (istream& s, Distance& d)
{
    cout << "\nEnter feet: "; s >> d.feet;
    cout << "Enter inches: "; s >> d.inches;
    return s;
}

ostream& operator << (ostream& s, Distance& d)
{
    s << d.feet << "-" << d.inches << endl;
    return s;
}

int main()
{
  Distance dist1, dist2; //define Distances
  Distance dist3(11, 6.25); //define, initialize dist3
  cout << "\nEnter two Distance values:";
  cin >> dist1 >> dist2; //get values from user

  cout << "\ndist1 = " << dist1 << "\ndist2 = " << dist2;
  cout << "\ndist3 = " << dist3 << endl;
  system("pause");
}
