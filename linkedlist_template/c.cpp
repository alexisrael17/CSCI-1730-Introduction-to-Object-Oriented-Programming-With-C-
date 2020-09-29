#include<iostream>
//#include<istream>

template <typename DistanceElement>
class Distance                           //English Distance class
{
   private:
      DistanceElement feet;
      DistanceElement inches;
   public:
      Distance() : feet(0), inches(0.0)  //constructor (no args)
      {  }
                                         //constructor (two args)
      Distance(DistanceElement ft, DistanceElement in) : feet(ft), inches(in)
      {  }
      Distance( DistanceElement fltfeet )          //constructor (one arg)
      {                                  //convert float to Distance
         feet = DistanceElement(fltfeet);            //feet is integer part
         inches = 12*(fltfeet-feet);     //inches is what's left
      }
      bool operator < (Distance<DistanceElement>) const;  //compare distances
      friend istream& operator >> (istream& s, Distance<DistanceElement>& d);
      friend ostream& operator << (ostream& s, Distance<DistanceElement>& d);
       // friend istream& operator >> (istream& s, Distance<DistanceElement>& d);
      //friend ostream& operator << (ostream& s, Distance<DistanceElement>& d);
};
template<typename DistanceElement>
bool Distance<DistanceElement>::operator < (Distance<DistanceElement> d2) const
      {
   float bf1 = feet + inches/12;
   float bf2 = d2.feet + d2.inches/12;
   return (bf1 < bf2) ? true : false;
}
template<typename DistanceElement>
//--------------------------------------------------------------
istream& operator >> (istream& s, Distance<DistanceElement>& d)  //get Distance
{                                               //from user
   cout << "\nEnter feet: ";  s >> d.feet;      //using
   cout << "Enter inches: ";  s >> d.inches;    //overloaded
   return s;                                    //>> operator
}
//--------------------------------------------------------------
template<typename DistanceElement>
ostream& operator << (ostream& s, Distance<DistanceElement>& d)  //display
{                                               //Distance
   s << d.feet << "\'-" << d.inches << '\"';    //using
   return s;                                    //overloaded
}                                               //<< operator

//template<typename DistanceElement>

int main()
{
	int sel;
	bool end=false;
	int iFlag=0;
	float fFlag=0;
	char cFlag=0;
	Distance dFlag;
	cout << "TEMPLATE DEMO PROGRAM\n";
	do{
		cout << "Enter list type (1=int 2=float 3=char 4=Distance 5=exit): ";
		cin >> sel;
		switch (sel)
		{
		case 1:
			Distance(iFlag);
			break;
		case 2:
			Distance(fFlag);
			break;
		case 3:
			Distance(cFlag);
			break;
		case 4:
			Distance(dFlag);
			break;
		default:
			end=true;
			cout << "Bye...\n";
			break;
		}
	}while(!end);
	return 0;
}
