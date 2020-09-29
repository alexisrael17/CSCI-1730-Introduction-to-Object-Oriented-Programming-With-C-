#include <iostream>

using namespace std;
class Distance
{
   private:
      int feet ;
      float inches ;
   public:
      Distance () : feet(0), inches(0.0) { }
      Distance (int ft, float in) :
         feet(ft), inches(in) { }
friend istream & operator >> ( istream & s,
                             Distance & d ) ;
friend ostream & operator << ( ostream & s,
                       const Distance & d ) ;
} ;

istream & operator >> ( istream & s,
                               Distance & d )
{
   cout << "Enter feet: " ; s >> d.feet ;
   cout << "Enter inches: " ; s >> d.inches ;
   return s ;
}

ostream & operator << ( ostream & s,    12.33
                         const Distance & d )
{
   s << d.feet << "\'-" << d.inches << "\"" ;
   return s ;
}

int main ()
{
   Distance dist1, dist2, dist3(11, 6.25) ;

   cout << "Enter two Distances:\n" ;
   cin >> dist1 >> dist2 ;
   cout << "dist1: " << dist1 << "\ndist2: "
   << dist2 << "\ndist3: " << dist3 << endl;
}
