// Authors: Kent Johnson, Alex Lema
//4/26/2017
/*Write a class LinkList, which implements a sorted linked list of floats.
The class should have member functions that handle the following tasks:*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode
{
   float value;
   ListNode *next;
};

ListNode *head;

class LinkedList
{
   public:
   void insertNode(float num);
   void deleteNode(float num);
   void destroyList();
   void displayList();
   void searchNode(float num);
   void displayNth(int n);
   void displayMedian(int n);
   void deleteNth(int n);
   void displayStatistics();
   // LinkedList() {head = NULL;}
   //~LinkedList() {destroyList();}
   /*private:
    ListNode *listNode;*/
};

void LinkedList::insertNode(float num)
{
   struct ListNode *newNode, *nodePtr = head, *prevNodePtr = NULL;

   newNode = new ListNode;
   newNode->value = num;
   newNode->next = NULL;

   if(head==NULL)
    {
        head = newNode;
    }

   else if (nodePtr->value >= num)
    {
        newNode->next = head;
        head = newNode;
    }

   else
    {
       while((nodePtr != NULL) && (nodePtr->value < num))
        {
           prevNodePtr = nodePtr;
           nodePtr = nodePtr->next;
        }

       if(prevNodePtr==NULL) newNode->next = head;

       else newNode->next = nodePtr; prevNodePtr->next = newNode;
   }
}

void LinkedList::deleteNode(float num)
{
   struct ListNode *nodePtr = head, *prevNodePtr = NULL;

   if(head==NULL)
    {
       cout << "The list was empty!\n";
       return;
    }
   if(head->value == num)
    {
       head = nodePtr->next;
       delete [] nodePtr;
    }
   else
    {
       while((nodePtr!= NULL)&&(nodePtr->value != num))
        {
           prevNodePtr = nodePtr;
           nodePtr = nodePtr->next;
        }

       if(nodePtr==NULL) cout << "The value " << num << " is not in this list!\n";

       else
        {
           prevNodePtr->next = nodePtr->next;
           delete [] nodePtr;
        }
   }
}

void LinkedList::destroyList()
{
   struct ListNode *nodePtr = head, *nextNode = nodePtr;

   if(head==NULL)
    {
       cout << "The list is empty!\n";
       return;
    }

   while (nodePtr != NULL)
    {
       nextNode = nodePtr->next;
       delete [] nodePtr;
       nodePtr = nextNode;
    }
}

void LinkedList::displayList()
{
   struct ListNode *nodePtr = head;

   if (nodePtr == NULL) cout << "The list is empty!\n";
   else
    {
       cout << "List: ";
            while (nodePtr != NULL)
            {
                cout <<"\t"<< nodePtr->value << "\n";
                nodePtr = nodePtr->next;
            }
       cout << "\n";
   }
}

void LinkedList::searchNode(float num)
{
   struct ListNode *nodePtr = head;

   if(head==NULL)
    {
       cout << "The list is empty!\n";
       return;
    }
   if(head->value == num)
    {
       head = nodePtr->next;
       cout <<num<<" is in position: 1\n";;
    }
   else
    {
       int count = 1;
            while((nodePtr!= NULL)&&(nodePtr->value != num))
                {
                    nodePtr = nodePtr->next;
                    count++;
                }
       if(nodePtr==NULL) cout << "The value " << num << " is not in this list.\n";
       else
            {
           cout <<num<<" is in position: " << count <<"\n";
            }
    }
}

void LinkedList::displayNth(int n)
{
   if(!head) cout << "\nList is empty!";
   ListNode* temp = head;
   int location = 1;

   while(location != n && temp)
    {
       temp = temp->next;
       location++;
    }
   if(temp) cout << "\nValue of position " << n << " is " << temp->value<<"\n";
   else cout << "\nNo position "<<n<<" link in the list\n";

}

void LinkedList::deleteNth(int n)
{
   struct ListNode *nodePtr = head, *prevNodePtr = NULL;
   int location = 1;

   if(head==NULL)
    {
       cout << "The list is empty!\n";
       return;
    }

   if(location == n)
    {
       head = nodePtr->next;
       delete [] nodePtr;
       return;
    }

   else
    {
       while((nodePtr!= NULL)&&(location!=n))
        {
           prevNodePtr = nodePtr;
           nodePtr = nodePtr->next;
           location++;
        }
       if(nodePtr==NULL) cout << "\nThere are less than 4 terms in the list - no delete made!\n";
       else
        {
           prevNodePtr->next = nodePtr->next;
           delete [] nodePtr;
        }
   }
}

void LinkedList::displayStatistics()
{
   int count = 0;
   float sum = 0;
   ListNode* temp = head;

   ListNode* temp2 = head;

   while(temp)
    {
       sum += temp->value;
       temp=temp->next;
       count++;
    }

    cout << "\n\tNumber of items in list = " << count
        << "\n\tMean (average) = " << sum/count
        << "\n\tMedian = ";

      int middle;
    //double average, median;
    middle = count / 2.0;
     int location = 1;
    float reserve;
     while(location<=middle){
       temp2 = temp2->next;
       location++;
    }
    if (!(middle % 2))
    {

       cout<< temp2->value<<"\n";
        //median = (array[middle] + array[middle + 1]) / 2.0;
        //cout << "The median is: " << average << endl;
    }
    else
    {
    reserve=temp2->value;
     temp2= temp2->next;
     reserve=(temp2->value+reserve);
     cout<<reserve/2<<"\n";
        //median = array[middle + 0] / 1.0;
       // cout << "The median is: " << median << endl;
    }
   // return median;


  /*if(middle%2==1)
    cout<< temp->value<<"\n";

    else
    {
     reserve=temp->value;
     temp = temp->next;
     reserve=(temp->value+reserve);
     cout<<reserve/2<<"\n";
    }
*/
    //count++;
    //displayMedian(int(count/2 + 0.5));
}

void LinkedList::displayMedian(int n)
{
    ListNode* temp = head;
    int location = 1;
    float reserve;

    while(location != n && temp)
    {
       temp = temp->next;
       location++;
    }

    if(n%2==1)
    cout<< temp->value<<"\n";

    else
    {
     reserve=temp->value;
     temp = temp->next;
     reserve=(temp->value+reserve);
     cout<<reserve/2<<"\n";
    }

}

void menu()
{
     cout<<"\nMake a selection:"
         <<"\n1 - Add a value(a decimal number)"
         <<"\n2 - Search for a value"
         <<"\n3 - Find the nth value"
         <<"\n4 - Delete the nth value"
         <<"\n5 - Display list statistics (count, mean, median)"
         <<"\n6 - Display the list"
         <<"\n7 - Exit the program\n"
         <<"=> ";
}

int main()
{
   float num;
   unsigned int choice, location;
   LinkedList temp;

   cout<<"\nLINKED LIST MANAGER\n";

   menu();

   while(1){
       cin >> choice;
       switch(choice){
           case 1:
               cout <<"\nEnter data value to add: ";
               cin >> num;
               temp.insertNode(num);
               break;
           case 2:
               cout <<"\nEnter data value to search for: ";
               cin >> num;
               temp.searchNode(num);
               break;
           case 3:
               cout <<"\nEnter position number to find: ";
               cin >> location;
               temp.displayNth(location);
               break;
           case 4:
               cout <<"\nEnter item position number to delete: ";
               cin >> location;
               temp.deleteNth(location);
               break;
           case 5:
               cout <<"\nLIST STATISTICS: ";
               temp.displayStatistics();
               break;
           case 6:
               cout <<'\n';
               temp.displayList();
               break;
           case 7:
               exit(0);
               break;
           default:
               cout << "\nInvalid selection - try again.\n\n";
       }
       menu();
   }

}
