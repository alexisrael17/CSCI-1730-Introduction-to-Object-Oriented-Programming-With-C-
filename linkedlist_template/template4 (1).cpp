#include<iostream>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include <cstdlib>
using namespace std;

template <class t>
class List
{
       private:
            t a[5];

       public:
            List (){a[0]={0};a[1]={0};a[2]={0};a[3]={0};a[4]={0};}
            void get();
            void sort();
            void display();
};

template <class t>
void List  <t>::get()
{
        int i;
        for(i=0; i<5;i++)
        {
            cout<<"Enter element "<<i+1<<": ";
            cin>>a[i];
        }
}

template <class t>
void List  <t>::display()
{
        int i,j=0;
        for(i=0;i<5;i++)
        cout <<" " <<  a[i];
}

template <class t>
void List  <t>::sort()
{
        int i,j;
        t temp;
        for(i=0;i<5;i++)
        {
            for(j=i+1;j<5;j++)
                {
                    if(a[j]<a[i])
                        {
                            temp=a[i];
                            a[i]=a[j];
                            a[j]=temp;
                        }
                }
        }

        cout<<"\nList created -> ";display();
        cout<<"\nSort the first list\nSorted list --> ";display();
        cout<<"\n";
}


class Distance                           //English Distance class
{
   private:
      int feet;
      float inches;
   public:
      Distance() : feet(0), inches(0.0)  //constructor (no args)
      {  }
                                         //constructor (two args)
      Distance(int ft, float in) : feet(ft), inches(in)
      {  }
      Distance( float fltfeet )          //constructor (one arg)
      {                                  //convert float to Distance
         feet = int(fltfeet);            //feet is integer part
         inches = 12*(fltfeet-feet);     //inches is what's left
      }
      bool operator < (Distance) const;  //compare distances
      friend istream& operator >> (istream& s, Distance& d);
      friend ostream& operator << (ostream& s, Distance& d);
};
bool Distance::operator < (Distance d2) const
      {
   float bf1 = feet + inches/12;
   float bf2 = d2.feet + d2.inches/12;
   return (bf1 < bf2) ? true : false;
}

//--------------------------------------------------------------
istream& operator >> (istream& s, Distance& d)  //get Distance
{                                               //from user
   cout << "\nEnter feet: ";  s >> d.feet;      //using
   cout << "Enter inches: ";  s >> d.inches;    //overloaded
   return s;                                    //>> operator
}
//--------------------------------------------------------------
ostream& operator << (ostream& s, Distance& d)  //display
{                                               //Distance
   s << d.feet << "\'-" << d.inches << '\"';    //using
   return s;                                    //overloaded
}                                               //<< operator


template<typename t>
void demo(t flag)
{

     List <t> myList;
    cout<<"List values -> ";myList.display();
    cout<<endl;
     myList.get();
     cout<<"List entered -> ";myList.display();
     cout<<"\nCreate a second list initialized to the first";
    myList.sort();
     cout<<endl;
}

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
           demo(iFlag);
            break;
        case 2:
            demo(fFlag);
            break;
        case 3:
            demo(cFlag);
            break;
        case 4:
        demo(dFlag);
        break;
        default:
            end=true;
            cout << "Bye...\n";
            break;
        }
    }while(!end);
    return 0;
}


