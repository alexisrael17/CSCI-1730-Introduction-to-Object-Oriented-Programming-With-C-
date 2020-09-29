#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

int numWords=0, wordsBeginWithT=0, wordsWithNoVowels=0, averageLength=0, minLength=0, maxLength=0, wordsWithAllVowels=0, wordsBeginWithSh=0 ;
int totalLength=0;
string word, shortestWord="Z", longestWord="Z" ;
ifstream wordfile;
wordfile.open( "story2.txt" );   // this file name must match file in same folder
if (wordfile.fail())
{
cout << "Error opening file";
return 0;
} // if problem then exit

while (!wordfile.eof())     // main loop - keep reading data until eof (end of file); one line at a time
{
    wordfile >> word;     // get next word from file (do not use cin); store in variable �word�
    numWords++;         // count number of words
    totalLength = totalLength + word.size();
    if (shortestWord=="Z" && longestWord=="Z")
    {
      shortestWord = word;
      longestWord = word;
      maxLength = word.size();
      minLength = word.size();
    }
    else
    {
      if (word.size() > longestWord.size())
          {
            longestWord = word;
            maxLength = word.size();
          }
      if (word.size() < shortestWord.size() )
          {
            shortestWord = word;
            minLength = word.size();
          }
    }

    if (word.at(0) == 'T' || word.at(0) == 't')
      wordsBeginWithT++;
    if(word.size()>1)
      if ((word.at(0) == 'S'|| word.at(0) == 's') && word.at(1) == 'h')
        wordsBeginWithSh++;

    int numvowels = 0;
    for(int i=0; i<word.size(); i++)
    {
      char alpha = word.at(i);
      if(alpha == 'a' || alpha == 'e' || alpha == 'i' || alpha == 'o' || alpha == 'u'
        || alpha == 'A' || alpha == 'E' || alpha == 'I' || alpha == 'O' || alpha == 'U'
        || alpha == 'Y' || alpha == 'y')
        numvowels =1;
    }
    if (numvowels ==0 )
      wordsWithNoVowels++;

    int countA=0, countE=0, countI=0, countO=0, countU=0;

    for(int i=0; i<word.size(); i++)
    {
       char chasc = word.at(i);
        switch(chasc){
          case'a' :
          case'A' :
            countA++;
            break;
          case'e' :
          case'E' :
            countE++;
            break;
          case'i' :
          case'I' :
            countI++;
            break;
          case'o' :
          case'O' :
            countO++;
            break;
          case'u' :
          case'U' :
            countU++;
            break;
          default:
            continue;
     }
    }

    if(countA >0 && countE>0 && countI>0 && countO>0 && countU>0 )
      wordsWithAllVowels++;

}
   averageLength = totalLength/numWords;
   wordfile.close();


   cout <<"\n\nThe number of words in file = " << numWords << endl;
   cout<<"The number of words that begin with T = "<<wordsBeginWithT<<endl;
   cout<<"The number of words without any vowels and y = "<<wordsWithNoVowels<<endl;
   cout<<"The average length of word is = "<< averageLength<<endl;
   cout<<"The minimum word length is = "<<minLength<<endl;
   cout<<"The shortest Word is = "<<shortestWord<<endl;
   cout<<"The maximum word length is = "<<maxLength<<endl;
   cout<<"The longest Word is = "<< longestWord<<endl;
   cout<<"The number of words with all the vowels (a,e,i,o,u) = "<<wordsWithAllVowels<<endl;
   cout<<"The number of words that begin with Sh = "<<wordsBeginWithSh<<endl<<endl;
return 0;

}
