#include <iostream>
#include <conio.h>
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
int insertNode(float num);
int appendNode(float num);
void deleteNode(float num);
void destroyList();
void display(LinkedList obj);
LinkedList(void)
{
   head = NULL;
}
LinkedList( const LinkedList &obj)
{
   head=head;
}
~LinkedList(void) {destroyList();}
};

void LinkedList::display(LinkedList obj)
{
   ListNode *list = head;
   while(list!=NULL) {
       cout << list->value << " ";
       list = list->next;
   }
   cout << endl;
   cout << endl;
}


int LinkedList::appendNode(float num)
{
ListNode *newNode, *nodePtr = head;
newNode = new ListNode;
if(newNode == NULL) {
   cout << "\nError allocating memory for new list member!\n";
   return 1;
}
newNode->value = num;
newNode->next = NULL;
if(head == NULL) {
   cout << "\nList was empty - " << newNode->value;
   cout << "\n is part of list's first node.\n";
   head = newNode;
}
else
{
   while(nodePtr->next != NULL)
   nodePtr = nodePtr->next;
   nodePtr->next = newNode;
}
return 0;
}
int LinkedList::insertNode(float num)
{
struct ListNode *newNode, *nodePtr = head, *prevNodePtr = NULL;
newNode = new ListNode;
if(newNode == NULL)
{
   cout << "Error allocating memory for new list member!\n";
   return 1;
}
newNode->value = num;
newNode->next = NULL;
if(head==NULL)
{
   cout << "List was empty - " << newNode->value;
   cout << " is part of list's first node.\n";
   head = newNode;
}
else
{
   while((nodePtr != NULL) && (nodePtr->value < num))
   {
   prevNodePtr = nodePtr;
   nodePtr = nodePtr->next;
   }
   if(prevNodePtr==NULL)
   newNode->next = head;
   else
   newNode->next = nodePtr; prevNodePtr->next = newNode;
}
return 0;
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
   if(nodePtr==NULL)
   cout << "The value " << num << " is not in this list!\n";
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
int main()
{
//clrscr();
float num;
char answer;
int choice;
LinkedList temp;
LinkedList temp2=temp;
do
{
   cout<<"\n1. Create New Link List ";
   cout<<"\n2. Append in Link List ";
   cout<<"\n3. Delet Node from Link List ";
   cout<<"\n4. Delete Link List ";
   cout<<"\n5. Display Link list";
   cout<<"\n-> Enter Choice : ";
   cin>>choice;
   if(choice==1)
   {
   cout << "\nEnter a value for the New list : ";
   cin >> num;
   temp.insertNode(num);
   }
   else if(choice==2)
   {
   cout << "\nEnter a value for the list : ";
   cin >> num;
   temp.appendNode(num);
   }
   else if(choice==3)
   {
   cout << "\nEnter a value delete from the list : ";
   cin >> num;
   temp.deleteNode(num);
   cout<<"\nNode Deleted from List!!!";
   }
   else if(choice==4)
   {
   temp.destroyList();
   cout<<"\nLink List destroyed!!!";
   }
   else if(choice==5)
   {
       cout<<"\n Actual list\n";
       temp.display(temp);
       cout<<"\n Copy list\n";
       temp2.display(temp2);
   }
   else
   {
   cout<<"\nIncorrect Choice!!!";
   }
   cout << "\nDo you want to continue(y/n) : ";
   cin >> answer;
}while(answer=='y');
return 0;
}
