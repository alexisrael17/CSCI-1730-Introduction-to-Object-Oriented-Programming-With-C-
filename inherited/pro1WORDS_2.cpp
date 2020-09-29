// Authors: Alex Lema, Yiqiang Pei and Kent Johnson
// Date: 4/5/17
// This program will take input from a file and analyze the text in the file.  It will also output the results to an output file

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void wordStats(ifstream& fileIn, ofstream& fileOut, string fileName);

int main()
{
    string fileInName, fileOutName;
    ifstream fileIn;
    ofstream fileOut;

    cout << "Enter output file name (Must include \".txt\" at the end):\n";
    getline(cin, fileOutName);
    fileOut.open(fileOutName.c_str( ));
    if (fileOut.fail( ))
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    int selection;

    do
    {
        cout << endl << "Select and option:\n" << '\t' << "1 - Enter input file name\n";
        cout << '\t' << "2 - Determine word statistics\n" << '\t';
        cout << "3 - List shortest words\n" << '\t' << "4 - List longest words\n" << '\t' << "5 - Search for a word\n";
        cout << '\t' << "6 - Exit\n";

        cin >> selection;
        cin.ignore(80,'\n');

        switch (selection)
        {
        case 1:
                cout << "Enter input file name (story.txt or story2.txt):\n";
                getline(cin, fileInName);
                fileIn.open(fileInName.c_str( ));
                if (fileIn.fail( ))
                {
                    cout << "Input file opening failed.\n";
                    exit(1);
                }
                cout << "Filename entered: " << fileInName;
                cout << endl << endl;
            break;

        case 2:
                wordStats(fileIn, fileOut, fileInName);
            break;
        }

    }while (selection != 6);

    return 0;
}

void wordStats(ifstream& fileIn, ofstream& fileOut, string fileName)
{



    int wordTot = 0, wordChar = 0, punctChar = 0, shortWord = 99999, longWord = 0;
    float aveWordLen = 0.0;

    cout << "Filename: " << fileName << endl;
    fileOut << "Filename: " << fileName << endl;

    char next;

    fileIn.get(next);
    while (! fileIn.eof( ))
    {
        if (isalnum(next))
            wordChar++;
        else if (isspace(next))
            wordTot++;
        else if(ispunct(next))
            punctChar++;
        fileIn.get(next);
    }

    cout << "Total number of words = " << wordTot << endl;
    cout << "Average word length = " << aveWordLen << " characters." << endl;
    cout << "Total number of word characters = " << wordChar << endl;
    cout << "Total number of punctuation characters = " << punctChar << endl;
    cout << "Shortest word length = " << shortWord << endl;
    cout << "Longest word length = " << longWord << endl;

    fileOut << "Total number of words = " << wordTot << endl;
    fileOut << "Average word length = " << aveWordLen << " characters." << endl;
    fileOut << "Total number of word characters = " << wordChar << endl;
    fileOut << "Total number of punctuation characters = " << punctChar << endl;
    fileOut << "Shortest word length = " << shortWord << endl;
    fileOut << "Longest word length = " << longWord << endl;
}
