#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void print1();
void print2();
void print3();
void print4();

int main()
{
    string emailAddress;
    bool isValid = true;
    bool hasAtSymbol = false;
    int ats=0,size_string;
    string play_again = "y";

    while (play_again =="y")
    {
        ats=0;
        cout<<"Enter the address: ";
        getline( cin, emailAddress);
        cout<<"You entered: "<<emailAddress<<endl;
        int size_string =emailAddress.length();

        for(int i = 0; i < size_string; i++)
        {
            if(emailAddress[i] ==32)//spaces
                    {
                        print1();
                        isValid = false;
                        break;
                    }

            if(emailAddress[0]=='@')
                    {
                        print3();
                        isValid = false;
                        break;
                    }
            if((emailAddress[0]=='.'))
                    {
                        print4();
                        isValid = false;
                        break;
                    }


             if(emailAddress[i]=='@')
                        ats++;
             if(ats>1)
                    {
                        isValid = false;
                        print2();
                        break;
                    }

             if(emailAddress[i] == '@' && hasAtSymbol == false)
                    {
                        hasAtSymbol = true;
                        if(i == emailAddress.length() - 1 || i == 0)
                            {
                                print2();
                                isValid = false;
                                break;
                            }
                    }
            else if(emailAddress[i] == '@')
                    {
                        isValid = false;
                        print2();
                        break;
                    }

            if(emailAddress[i] == '.')
                    {
                        if(i == 0 || i == emailAddress.length() - 1)
                            {
                                isValid = false;
                                break;
                            }
                        else if(emailAddress[i - 1] == '@' || emailAddress[i - 1] == '.' || emailAddress[i + 1] == '.' ||emailAddress[i + 1] == '@')
                            {
                                isValid = false;
                                print4();
                                break;
                            }
                    }
             if(emailAddress[size_string-1]=='.')
                    {
                        print1();
                        isValid = false;
                        break;
                    }
        }

        ats=0;

for(int i = 0; i < size_string; i++)
    {
        if(emailAddress[i]=='@')
        ats++;
    }
if(ats==0)
    {
        isValid = false;
        print2();
    }

if(isValid)
cout<<endl<<"The email address is valid.\n\n";


hasAtSymbol = false;
isValid = true;
cout<<"Enter another (y or n)? ";
getline (cin, play_again);

}

return 0;
}


    void print1()
        {
            cout<<"Not valid - contains a blank"<<endl;
        }

    void print2()
        {
            cout<<"Not valid - not exactly one '@'"<<endl;
        }


    void print3()
        {
            cout<<"Not valid - '@' is first character"<<endl;
        }

    void print4()
        {
            cout<<"Not valid - a dot is first or last, or preceded or followed by @ or ."<<endl;
        }
