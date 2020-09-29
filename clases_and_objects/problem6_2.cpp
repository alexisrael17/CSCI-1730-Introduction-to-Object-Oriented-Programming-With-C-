/*Error class to handle array out of bounds exception

array size exception*/

class Errors

{

public :

void ArrayIndexoutOfBounds()

{

cout<<"Array index out of bound Exception"<<endl;

}

void lessSizeArray()

{

cout<<"newArray size should be greater than old Array"<<endl;

}

};

/*DynArray class inheriting the Errors class */

class DynArray:public Errors

{

//two pointers to point to address of two dynamic arrays

int*intList;

int *newList;

//size of array

int arraySize;

public:

//constructor

DynArray()

{

intList=NULL;

}

//constructor with arraySize argument

DynArray(int arraySize)

{

//allocate memory dynamically

intList=new int[arraySize];

}

void show(int index)

{

//To handle the out of bounds array exception

if(index>arraySize)

throw ArrayIndexoutOfBounds;

else

cout<<"Element at index="<<intList[index];

}

void set(int index,int x)

{

//To set the new element into array index

for(int i=0;i<arraySize;i++)

if(index==i)

intList[index]=x;

}

void expand(int newSize)

{

//new array size always greater than old array

//or else thow exception

if(newSize<arraySize)

throw lessSizeArray;

else

{

//allocate memory for new array

newList=new int[newSize];

//copy old elements into newly created array newList

for(int i=0;i<arraySize;i++)

newList[i]=intList[i];

}

}

//Destructor

~DynArray()

{

delete[] newList;

delete[] intList;

}

};
