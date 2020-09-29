
// This program will take input from a file and analyze the text in the file.  It will also output the results to an output file

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void wordStats(ifstream& fileIn, ofstream& fileOut, string fileName);
void shortestWords(ifstream& fileIn, ofstream& fileOut, string fileName);
void longestWords(ifstream& fileIn, ofstream& fileOut, string fileName);
void searchWord(ifstream& fileIn, ofstream& fileOut, string fileName);

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

        case 3:
                shortestWords(fileIn, fileOut, fileInName);
            break;

        case 4:
                longestWords(fileIn, fileOut, fileInName);
            break;

        case 5:
                searchWord(fileIn, fileOut, fileInName);
            break;

        case 6:
                cout << "Bye...\n";
            break;

        default:
                cout << "Invalid entry\n";
        }

    }while (selection != 6);

    fileIn.close();
    fileOut.close();
    return 0;
}

void wordStats(ifstream& fileIn, ofstream& fileOut, string fileName)
{
    cout << "Filename: " << fileName << endl;
    fileOut << "Filename: " << fileName << endl;

    string word;
    int wordTot = 0, wordChar = 0, n, punctChar = 0, shortWord = 99999, longWord = 0;
    float aveWordLen = 0.0;
    if (!fileIn.is_open())
    {
       cout << "No input file currently open.\n";
       return;
    }
    fileIn.clear();
    fileIn.seekg(0);
    while (fileIn >> word)
    {
        wordTot++;
        n = word.length();
        while (ispunct(word[n-1]))
        {
            punctChar++;
            word.erase(n-1,1);
            n--;
        }
        while (ispunct(word[0]))
        {
           punctChar++;
           word.erase(0,1);
           n--;
        }
        if(n > longWord)
           longWord = n;
        if(n < shortWord)
           shortWord = n;
        wordChar += n;
        aveWordLen = (static_cast<float>(wordChar) / static_cast<float>(wordTot));
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

void shortestWords(ifstream& fileIn, ofstream& fileOut, string fileName)
{
    cout << "Filename: " << fileName << endl;
    fileOut << "Filename: " << fileName << endl;
    cout << "The shortest words are:\n";
    fileOut << "The shortest words are:\n";

    string word;
    int shortWord = 99999, n;
    if (!fileIn.is_open())
    {
        cout << "No input file currently open.\n";
        return;
    }
    fileIn.clear();
    fileIn.seekg(0);
    while (fileIn >> word)
    {
        n = word.length();
        while (ispunct(word[n-1]))
        {
            word.erase(n-1,1);
            n--;
        }
        while (ispunct(word[0]))
        {
            word.erase(0,1);
            n--;
        }
        if(n < shortWord)
        shortWord = n;
    }
    fileIn.clear();
    fileIn.seekg(0);
    while (fileIn >> word)
    {
        n = word.length();
        while (ispunct(word[n-1]))
        {
            word.erase(n-1,1);
            n--;
        }
        while (ispunct(word[0]))
        {
            word.erase(0,1);
            n--;
        }
        if(n == shortWord)
        {
            cout << word << endl;
            fileOut << word << endl;
        }
    }
}

void longestWords(ifstream& fileIn, ofstream& fileOut, string fileName)
{
    cout << "Filename: " << fileName << endl;
    fileOut << "Filename: " << fileName << endl;
    cout << "The longest words are:\n";
    fileOut << "The longest words are:\n";

    string word;
    int longWord = 0, n;
    if (!fileIn.is_open())
    {
        cout << "No input file currently open.\n";
        return;
    }
    fileIn.clear();
    fileIn.seekg(0);
    while (fileIn >> word)
    {
        n = word.length();
        while (ispunct(word[n-1]))
        {
            word.erase(n-1,1);
            n--;
        }
        while (ispunct(word[0]))
        {
           word.erase(0,1);
           n--;
        }
        if(n > longWord)
           longWord = n;
    }
    fileIn.clear();
    fileIn.seekg(0);
    while (fileIn >> word)
    {
        n = word.length();
        while (ispunct(word[n-1]))
        {
            word.erase(n-1,1);
            n--;
        }
        while (ispunct(word[0]))
        {
            word.erase(0,1);
            n--;
        }
        if(n == longWord)
        {
            cout << word << endl;
            fileOut << word << endl;
        }
    }
}

void searchWord(ifstream& fileIn, ofstream& fileOut, string fileName)
{
    cout << "Filename: " << fileName << endl;
    fileOut << "Filename: " << fileName << endl;

    string word, searchWord;
    int wordCount = 0, n;

    if (!fileIn.is_open())
    {
        cout << "No input file currently open.\n";
        return;
    }

    cout << "Enter word to be searched: ";
    cin >> searchWord;

    fileIn.clear();
    fileIn.seekg(0);
    while (fileIn >> word)
    {
        n = word.length();
        while (ispunct(word[n-1]))
        {
            word.erase(n-1,1);
        }
        while (ispunct(word[0]))
        {
            word.erase(0,1);
        }
        if (word == searchWord)
            wordCount++;
    }

    cout << "Search word: " << searchWord << endl;
    cout << "This word appears " << wordCount << " time(s) in the file.\n";
    fileOut << "Search word: " << searchWord << endl;
    fileOut << "This word appears " << wordCount << " time(s) in the file.\n";
}
