#include<iostream>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include <cstdlib>
using namespace std;

template <class t>

class Demo
{
       private:
            t a[5];
       public:
            Demo()
            {a[0]={0};a[1]={0};a[2]={0};a[3]={0};a[4]={0};}
            void get();
            void sort();
            void display();
};

template <class t>
void Demo <t>::get()
{
        int i;
        for(i=0; i<5;i++)
        {
            cout<<"Enter element "<<i+1<<": ";
            cin>>a[i];
        }
}

template <class t>
void Demo <t>::display()
{
        int i;
        for(i=0;i<5;i++)
        cout<<a[i]<<setw(10);
}

template <class t>
void Demo <t>::sort()
{
        int i,j;
        t temp;
        for(i=0;i<5;i++)
        {
            for(j=i+1;j<5;j++)
                {
                    if(a[i]>a[j])
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

int main()
{
    int sel;
	bool end=false;
    Demo<int> iFlag;
    Demo<float> fFlag;
    Demo<char> cFlag;

    cout << "TEMPLATE DEMO PROGRAM\n";

    do{
		cout << "Enter list type (1=int 2=float 3=char 4=Distance 5=exit): ";
        cin>>sel;
        cout<<"New blank list created"<<endl;
        switch(sel)
        {
         case 1:
                cout<<"List values -> ";iFlag.display();
                cout<<endl;
                iFlag.get();
                cout<<"List entered -> ";iFlag.display();
                cout<<"\nCreate a second list initialized to the first";
                iFlag.sort();
                break;

         case 2:
                cout<<"List values -> ";fFlag.display();
                cout<<endl;
                fFlag.get();
                cout<<"List entered -> ";fFlag.display();
                cout<<"\nCreate a second list initialized to the first";
                fFlag.sort();
                break;

        case 3: cout<<"List values -> ";
                cout<<endl;
                cFlag.get();
                cout<<"List entered -> ";cFlag.display();
                cout<<"\nCreate a second list initialized to the first";
                cFlag.sort();
                break;

        case 4:
                cout<<"<Program terminating>";
                exit(0);

        default:
                cout<<"Invalid Choice try again!\n";
                return 0;

        }
        cout<<endl;
    }while(!end);
getch();
}
