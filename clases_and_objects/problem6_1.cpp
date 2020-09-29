#include <iostream>

using namespace std;

class DynArray
{
private:
int size;
int capacity;
int *arr;

public:
DynArray()
{
arr = new int[0];
capacity = 0;
size = 0;
}

DynArray(int n)
{
arr = new int[n];
capacity = n;
size = 0;
}

void show(int n)
{
if (n >= 0 && n < size)
{
cout << "Element " << n << " is "<<*(arr + n) << endl;
}
else
{
if (size == 0) cout << "Cannot show - DynArray empty" << endl;
else cout << "Invalid index in show" << endl;
}
}

void set(int n, int x)
{
if (n >= 0 && n < capacity)
{
*(arr + n) = x;
size++;
}
else
{
if (size == 0) cout << "Cannot set - DynArray empty" << endl;
else cout << "Invalid index in set" << endl;
}
}


void expand(int s)
{
int *temp = new int[capacity + s];
capacity = capacity + s;
for(int i = 0; i < size; i++)
{
*(temp + i) = *(arr + i);
}

delete arr;
arr = temp;
}

~DynArray()
{
cout << "hi from the DynArray destructor..." << endl;
delete arr;
}
};


void myFunc();
int main()
{
int size,more,i;
DynArray y;
cout << "Enter dynamic array size: ";
cin >> size;
DynArray x(size);
for(i=0;i<size;i++)
x.set(i,3*i);
for(i=0;i<size;i++)
x.show(i);
cout << "How much more dynamic array space do you want? ";
cin >> more;
x.expand(more);
for(i=0;i<(size+more);i++)
x.set(i,5*i);
for(i=0;i<(size+more);i++)
x.show(i);
x.show(size+more+5); //invalid index in show
x.set(-2,9); //invalid index in set
y.set(3,6); //empty DynArray set
y.show(3); //empty DynArray show
myFunc();
char ch; cin >> ch;
return 0;
}
void myFunc()
{
int i;
cout << "hi from myFunc...\n";
DynArray y(5);
for(i=0;i<5;i++)
y.set(i,i*i);
for(i=0;i<5;i++)
y.show(i);
cout << "bye from myFunc...\n";
}
