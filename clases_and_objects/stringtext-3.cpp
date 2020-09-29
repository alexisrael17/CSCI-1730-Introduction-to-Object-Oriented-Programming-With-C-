#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{

   string string_variable;
   char array_variable[9999],space = ' ',tab='\n';
   int i = 0, special_C = 0, lowercase = 0, total=0,uppercase = 0, numbers = 0, w_spaces=0;
   int size_variable;

     cout << "Enter a string: " << endl;
     getline ( cin, string_variable,'@');
     size_variable=string_variable.length();

     cout<<endl<<string_variable<<endl<<endl;

    for (i=0;i<=size_variable;i++)
        {
            array_variable[i]=string_variable[i];
        }

    i=0;

    while (i<size_variable)

    {
         if(array_variable[i] >= 'a' && array_variable[i] <= 'z')
         lowercase++;

         else if (array_variable[i] >= 'A' && array_variable[i] <= 'Z')
         uppercase++;

         else if (array_variable[i] >= '0' && array_variable[i] <= '9')
         numbers++;

         else if (array_variable[i] == space)
         w_spaces++;

         else if (array_variable[i]==tab)
         w_spaces++;

         else
         special_C++;

         i++;
    }

    total = lowercase + uppercase + numbers+w_spaces+special_C;


    cout<<"There were "<<total<<" total characters."<<endl;
    cout<<"There were "<<uppercase<<" upper case letters."<<endl;
    cout<<"There were "<<lowercase<<" lower case letters."<<endl;
    cout<<"There were "<<numbers<<" digits."<<endl;
    cout<<"There were "<<w_spaces<<" white space characters."<<endl;
    cout<<"There were "<<special_C<<" other characters."<<endl;

    return 0;
}
