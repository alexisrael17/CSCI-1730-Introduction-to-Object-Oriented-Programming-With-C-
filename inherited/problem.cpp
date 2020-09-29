#include<iostream>
#include<string>
#include<fstream>
#define MAX 200

using namespace std;

int menu();
void read_into_array();
void count(int *no_words, int *avg_word_len,int *cnt,int *punct,string arr[]);
int longest_word(string arr[],int count );
int shortestword(string arr[],int cont);
int report_to_file(int words, int avg, int shortest, int longest, int punct, int charCount);

int main()
{
   ifstream in;
   string fname;
   string stringArr[MAX];
   int choice,no_words =0,avg_word_len = 0,shorest_words = 0,longest_words = 0,charCount = 0,punct = 0;


   //menu
   do
   {
       choice = menu();
       switch (choice)
       {
       case 1:
           count(&no_words, &avg_word_len, &charCount,&punct,stringArr);
           break;
       case 2:
           shorest_words = shortestword(stringArr, no_words);
           break;
       case 3:
           longest_words = longest_word(stringArr, no_words);
           break;
       case 4:
           report_to_file(no_words, avg_word_len, shorest_words, longest_words,punct,charCount);
           break;
       case 5:
           cout << "Quit" << endl;
           break;

       }
       if (choice == 5)
           break;
   } while (choice != 6);


}

int menu()
{
   int choice;
   cout << "1.List all shortest words\n2.List all the longest word\n3.Search for a word\n4.Word cont along with average word length\n5.output to report file\n5.Quit" << endl;
   cin >> choice;
   return choice;
}

void count(int *no_words, int *avg_word_len,int *charCount,int *punct,string strArray[])
{
   ifstream in;
   string fname;
       ifstream fileIn;
    ofstream fileOut;
   cout << "Enter the text file name: ";
//   cin >> fname;
//   in.open(fname);
getline(cin, fname);

    fileOut.open(fileOutName.c_str( ))

//    fileOut.open(fileOutName.c_str( ));
//    fileOut.open(fname.c_str( ));

   if (!in)
   {
       cout << "Not able to open input file " << fname << endl;
       return ;
   }
   int i = 0;
   while (!in.eof())
   {
       in >> strArray[i++];
   }
   *no_words = i;
   char c;
   int len,count = 0;

   for (int i = 0; i < *no_words; i++)
   {
       for (int j = 0; j < strArray[i].length(); j++)
       {
           c = strArray[i][0];
          // if (ispunct(c))
           //{
              // count++;
               //strArray[i].erase(find(strArray[i].begin(), strArray[i].end(), c));

           //}
           len = strArray[i].length();
           c = strArray[i][len];
          // if (ispunct(c))
           //{
           //    strArray[i].erase(std::find(strArray[i].begin(), strArray[i].end(), c));
            //   count++;
           //}
       }
   }
   *punct = count;
   for (int i = 0; i < *no_words; i++)
   {
       count+= strArray[i].length();
   }
   *charCount += count + *punct;
   //count avg word length
   count = 0;
   for (int i = 0; i < *no_words; i++)
   {
       count += strArray[i].length();
   }
   *avg_word_len = count;
   *avg_word_len /= *no_words;

}
int longest_word(string arr[],int count)
{
   int longest_words = 0,cnt = 0;
   longest_words = arr[0].length();
   for (int i = 0; i < count; i++)
   {
       if (longest_words < arr[i].length())
       {
           longest_words = arr[i].length();
       }
   }
   //find how many words are of length of longest_words
   for (int i = 0; i < count; i++)
   {
       if (longest_words == arr[i].length())
       cnt++;
   }
   return cnt;
}
int shortestword(string arr[],int count)
{
   int shortest_words = 0, cnt = 0;
   shortest_words = arr[0].length();
   for (int i = 0; i < count; i++)
   {
       if (shortest_words > arr[i].length())
       {
           shortest_words = arr[i].length();
       }
   }
   //find how many words are of length of longest_words
   for (int i = 0; i < count; i++)
   {
       if (shortest_words == arr[i].length())
           cnt++;
   }
   return cnt;
}
int report_to_file(int words, int avg, int shortest, int longest ,int punct,int charCount)
{
   ofstream out;
       ifstream fileIn;
    ofstream fileOut;
   string fname;
   cout << "Enter output file name: ";
   cin >> fname;
   getline(cin, fname);
//   out.open(fname);
   if (!out.is_open())
   {
       cout << "Not able to open outpt file: ";
       return -1;
   }
   out << "No of words: " << words << endl;
   out << "Avg word length: " << avg << endl;
   out << "no Shortest words: " << shortest << endl;
   out << "No of longest words: " << longest << endl;
   out << "no total chars: " << charCount << endl;
   out << "No of punct: " << punct << endl;
   return 0;
}
