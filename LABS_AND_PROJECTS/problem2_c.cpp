
using namespace std;

struct ListNode {
   float value;
   ListNode *next;
};

ListNode *head;

class LinkedList {
   public:
   void insertNode(float num);
   void deleteNode(float num);
   void destroyList();
   void displayList();

   void searchNode(float num);
   void displayNth(int n);
   void deleteNth(int n);
   void displayStatistics();

   LinkedList(void) {head = NULL;}
   ~LinkedList(void) {destroyList();}
};

void LinkedList::insertNode(float num)
{
   struct ListNode *newNode, *nodePtr = head, *prevNodePtr = NULL;
   newNode = new ListNode;
   if(newNode == NULL) {
       cout << "Error allocating memory for new list member!\n";
       return;
   }
   newNode->value = num;
   newNode->next = NULL;
   if(head==NULL) {
       cout << "List was empty - " << newNode->value;
       cout << " is part of list's first node.\n";
       head = newNode;
   }
   else if (nodePtr->value > num)
   {
       newNode->next = head;
       head = newNode;
   }
   else {
       while((nodePtr != NULL) && (nodePtr->value < num)) {
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
   if(head==NULL) {
       cout << "The list was empty!\n";
       return;
   }
   if(head->value == num) {
       head = nodePtr->next;
       delete [] nodePtr;
   }
   else {
       while((nodePtr!= NULL)&&(nodePtr->value != num)) {
           prevNodePtr = nodePtr;
           nodePtr = nodePtr->next;
       }
       if(nodePtr==NULL) cout << "The value " << num << " is not in this list!\n";
       else {
           prevNodePtr->next = nodePtr->next;
           delete [] nodePtr;
       }
   }
}

void LinkedList::destroyList()
{
   struct ListNode *nodePtr = head, *nextNode = nodePtr;
   if(head==NULL) {
       cout << "The list is empty!\n";
       return;
   }
   while (nodePtr != NULL) {
       nextNode = nodePtr->next;
       delete [] nodePtr;
       nodePtr = nextNode;
   }
}

void LinkedList::displayList()
{
   struct ListNode *nodePtr = head;
   if (nodePtr == NULL) cout << "The list is empty!\n";
   else {
       cout << "List: ";
       while (nodePtr != NULL) {
           cout << nodePtr->value << " -> ";
           nodePtr = nodePtr->next;
       }
       cout << "NULL\n";
   }
}

void LinkedList::searchNode(float num){
   struct ListNode *nodePtr = head;
   if(head==NULL) {
       cout << "The list is empty!\n";
       return;
   }
   if(head->value == num) {
       head = nodePtr->next;
       cout << "At position: 1\n";
   }
   else {
       int count = 1;
       while((nodePtr!= NULL)&&(nodePtr->value != num)) {
           nodePtr = nodePtr->next;
           count++;
       }
       if(nodePtr==NULL) cout << "The value " << num << " is not in this list!\n";
       else {
           cout << "At position: " << count << '\n';
       }
   }
}

void LinkedList::displayNth(int n){
   if(!head) cout << "\nList is empty!";
   ListNode* temp = head;
   int location = 1;
   while(location != n && temp){
       temp = temp->next;
       location++;
   }
   if(temp) cout << "\nValue at " << n << " = " << temp->value;
   else cout << "\nInvalid location!\n";
}

void LinkedList::deleteNth(int n){
   struct ListNode *nodePtr = head, *prevNodePtr = NULL;
   int location = 1;
   if(head==NULL) {
       cout << "The list is empty!\n";
       return;
   }
   if(location == n) {
       head = nodePtr->next;
       delete [] nodePtr;
       return;
   }
   else {
       while((nodePtr!= NULL)&&(location!=n)) {
           prevNodePtr = nodePtr;
           nodePtr = nodePtr->next;
           location++;
       }
       if(nodePtr==NULL) cout << "\nInvalid location!\n";
       else {
           prevNodePtr->next = nodePtr->next;
           delete [] nodePtr;
       }
   }
}

void LinkedList::displayStatistics(){
   int count = 1;
   float sum = 0;
   ListNode* temp = head;
   while(temp){
       sum += temp->value;
       temp=temp->next;
       count++;
   }

   cout << "\n\tCount: " << count
       << "\n\tMean: " << sum/count
       << "\n\tMedian(s): ";
   displayNth(int(count/2 + 0.5));
   cout << "\n";
}
void menu()
{   cout<<"Make a selection:"
         <<"\n1 - Add a value(a decimal number)"
         <<"\n2 - Search for a value"
         <<"\n3 - Find the nth value"
         <<"\n4 - Delete the nth value"
         <<"\n5 - Display list statistics (count,mean, median)"
         <<"\n6 - Display the list"
         <<"\n7 -  Exit the program\n"
         <<"=> ";
}

int main()
{
   float num;
   unsigned int choice, location;
   LinkedList temp;

   cout<<endl<<"LINKED LIST MANAGER"<<endl<<endl;
   menu();
   while(1){
       cin >> choice;
       switch(choice){
           case 1:
               cout <<"\nEnter value: ";
               cin >> num;
               temp.insertNode(num);
               break;
           case 2:
               cout <<"\nEnter value: ";
               cin >> num;
               temp.searchNode(num);
               break;
           case 3:
               cout <<"\nEnter the location: ";
               cin >> location;
               temp.displayNth(location);
               break;
           case 4:
               cout <<"\nEnter the location: ";
               cin >> location;
               temp.deleteNth(location);
               break;
           case 5:
               cout <<"\nStatistics: ";
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
               cout << "\nPlease choose proper option:\n\n";
       }
       menu();
   }

}
