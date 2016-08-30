/**
 * Course: CS 14 Summer 2016
 *
 * First Name:      Isaac
 * Last Name:       Lino
 * Username:        ilino
 * email address:   ilino001@ucr.edu
 *
 *
 * Assignment:      assn1
 * Filename :       MyList.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#include <cstdlib>

#include <iostream>
#include "MyList.h"
#include "node.h"

using namespace std;



//************* CONSTRUCTORS AND DESTRUCTORS  PART 1.1 *************//

/*------------------------------------------------------------------
 MyList()
 Default constructor
 */
MyList::MyList()
{
    cout << "\nDefault Constructor called...\n";
    head = NULL;
    
}
//------------------------------------------------------------------

/*------------------------------------------------------------------
 MyList(const MyList& str)
 Constructs a list from a passed in MyList object
*/
MyList::MyList(const MyList& str)
{
    cout << "Calling a constructor from a passed in MyList object called\n";
   
    
    head = NULL;
    Node* head_node = str.head;
    
    while(head_node!=NULL)
    {
        push_back(head_node->value);
        head_node = head_node->next;
    }
}
//------------------------------------------------------------------

/*------------------------------------------------------------------
 MyList(const string& str)
 Constructs a list from a passed in string object,
 */
MyList::MyList(const string& str)
{
    head = NULL;
    
    for(int index=1; index < str.size(); index++)
    {
        push_back(str.at(index));
    }
    
    
}
//------------------------------------------------------------------

/*------------------------------------------------------------------
 MyList(const string& str)
 Constructs a list from a passed in string literal
 */
MyList::MyList(const char* str)
{
    head = NULL;
    Node* new_node = new Node;
    while(new_node!=NULL)
    {
        for(int index=1; str[index]!='\0'; index++)
        {
            push_back(str[index]);
        }
    }
}
//------------------------------------------------------------------

/*------------------------------------------------------------------
 ~MyList()
 Destructor
 */
MyList::~MyList()
{
    
    cout << "\nList Destructor called...\n";
    
    while(head)
    {
        Node* temp_node = head;
        head = head->next;
        cout << "Deleting... "<< temp_node->value<< endl;
        delete temp_node;
    }

}
//------------------------------------------------------------------

//******************************************************************//




//*********************** MUTATORS  PART 1.2 ***********************//

/*------------------------------------------------------------------
 push_front()
 Inserts value at the front of the list
 */
void MyList::push_front(char value)
{
    // creates a new node
    Node* new_node = new Node;
    
    // sets the values parameters
    new_node->value = value;
    new_node->next = NULL;
    
    //Appends an item to an empty list
    //It checks if the list is empty
    if(!head)
    {
        cout << "\nList is empty \n" <<endl;
        head = new_node;
    }

    else
    {
        // if there is an item in list it will add
        // new node at the head
        new_node->next = head;
        head = new_node;
    }
   
    // displays the node that is been pushed
    cout << "pushing front node " << new_node->value << endl;
}
//------------------------------------------------------------------

/*------------------------------------------------------------------
 push_back()
 Inserts value at the back of the list
 */
void MyList::push_back(char value)
{
    // creates a new node
   Node* new_node = new Node;
    
//    Node* new_node->value;
     new_node->value = value;
    Node* head_node = head;
    
    // sets the values parameters
    new_node->value = value;
    new_node->next = NULL;
    
    //Appends an item to an empty list
    //It checks if the list is empty
    if(!head)
    {
        cout << "\nList is empty \n" <<endl;
        head = new_node;
    }
    
    else
    {
     // if there is an item in list it will add
     // new node right before the NULL
        while( head_node->next != NULL )
        {
            head_node = head_node->next;
        }
        head_node->next = new_node;
    }
    
    // displays the node that is been pushed
    cout << "pushing back node " << new_node->value << endl;
}
//------------------------------------------------------------------

/*------------------------------------------------------------------
 pop_front()
 Removes the front item from the lis
 */
void MyList::pop_front()
{
    if(head)
    {
        Node* head_node = head;
        head = head->next;
        cout << "Deleting... "<< head_node->value<< endl;
        delete head_node;
    }
}
//------------------------------------------------------------------

/*------------------------------------------------------------------
 pop_back()
 Removes the last item from the list
 */
void MyList::pop_back()
{
    if(head != NULL)
    {
            
        Node* last_node = head;
        Node* new_node = new Node;
        
            // scans all the list until hit NULL
            while(last_node->next != NULL)
            {
                new_node = last_node;
                last_node = last_node->next;
            }
            new_node->next=NULL;
        
            if(last_node != NULL)
            {
                cout << "Deleting... "<< last_node->value<< endl;
                delete last_node;
            }
    }
}
//------------------------------------------------------------------

/*------------------------------------------------------------------
 insert_at_pos()
 Inserts a node with value at position i in the list.
 */
void MyList::insert_at_pos(int i, char value)
{
    // Node to inserted declared and initialized
    // create an integer to count items
    int counter = 1;
    
    Node* head_node = head;
    Node* new_node = new Node;
    
    // set value to a new node
    new_node->value = value;
    new_node->next = NULL;
    
    cout << "inserting value " << value << " at position "<< i << " ... " << endl;
    
    /* Checks if list is empty */
    if(!head)
    {
        cout << "empty\n";
        head = new_node;
    }
    
    // out of range less or equal than 0
    else if(i <= 0)
    {
        
        // If position is 0 or negative numbers, value will be attach at head
        cout << "position " << i << " (out boundary too small). Value " << value << " inserted at head " << endl;
        
        //setting new node at head
        new_node -> next = head;
        head = new_node;
    }
    /*
    // out of range larger than list
    else if (i > counter)
    {
        cout << "position " << i << " (out boundary too big). Value " << value << " inserted at tail " << endl;
        while( head_node->next != NULL )
        {
            head_node = head_node->next;
        }
        head_node->next = new_node;
    }
    */
    // inserting at given i position
    else {
        
        // scan all the nodes
        while(head_node != NULL)
        {
            // look for the given i postion
            // if found insert
            if(counter == i)
            {
                new_node -> next = head_node -> next;
                head_node -> next = new_node;
            }
            head_node = head_node -> next;
            
            // update the counter
            counter++;
        }
    }
}
//------------------------------------------------------------------

/*------------------------------------------------------------------
 reverse()
 Reverses the items in the list
 */
void MyList::reverse()
{
    cout << "Reversing...\n";
 
    //creating nodes and setting
    Node* head_node = head;
    Node* temp;
    Node* previous_node = NULL;
    
    //scans all the nodes
    while(head_node!=NULL)
    {
        
        temp = head_node->next;
        head_node->next = previous_node;
        
        previous_node = head_node;
        head_node = temp;
        
    }
    head = previous_node;
}
//------------------------------------------------------------------

//******************************************************************//



//********************* ACCESSORS  PART 1.3 ************************//

/*------------------------------------------------------------------
 size()
 Returns the number of nodes in the list
 */
int MyList::size()const
{
    // initialize the counter
    int counter = 0;
    
    // declare pointer and set it to head
    Node* new_node;
    new_node = head;
    
    
    /* Checks if list is empty */
    if(!head)
    {
        cout << "empty\n";
        return 0;
    }
    
    //scans all the nodes
    while(new_node != NULL)
    {
        
        
        // scans all the nodes
        new_node = new_node->next;
        
        //increment counter for every node
        counter++;
    }
    
    cout << "\nSize of Mylist: " << counter <<endl;
    return counter;
}
//------------------------------------------------------------------

/*------------------------------------------------------------------
 print()
 Prints the contents of the list.
 */
void MyList::print()const
{
    cout << "Printing MyList: ";
    
    Node* nodes;
    nodes = head;
    
    /* list is empty */
    if(!head)
    {
        cout << "empty\n";
        return;
    }
    
    //scans all the nodes
    while(nodes != NULL)
    {
        cout << nodes->value << ", ";
        nodes = nodes->next;
    }
    cout << endl;
}
//------------------------------------------------------------------//

/*------------------------------------------------------------------
 int find(char value)const;
 Finds the position of the first occurrence of a character value 
 in the list and returns that position. 
 If the character is not in the list, the function returns -1.
 */
int MyList::find(char value)const
{
    cout << "Looking for value " << value << "... "<< endl;
    // Node to inserted declared and initialized
    // create an integer to count items
    int counter = 0;
    
    Node* head_node = head;
    
    // declare pointer and set it to head
    Node* new_node;
    new_node = head;
    
    
    /* Checks if list is empty */
    if(!head)
    {
        cout << "empty\n";
        return 0;
    }
    
        // scan all the nodes
        while(head_node != NULL)
        {
            
            // looking for the given value on list
            if(head_node->value == value)
            {
                new_node -> next = head_node -> next;
                head_node -> next = new_node;
                
                //if found display the value and the posiont
                cout << "found value "<< value << " at position " << counter <<endl;
                
                //return the counter of the position found
                return counter;
            }
            
            head_node = head_node -> next;
   
           // update the counter
            counter++;
        }
    
        // if value not found display and return -1
         cout << "value " << value << " NOT FOUND at any position! "<< endl;

    return -1;
}
//------------------------------------------------------------------//

//******************************************************************//




//***************** OPERATORS OVERLOADERS  PART 1.4 ****************//

/*------------------------------------------------------------------
 char& operator[](const int i)
 Returns a character a position i
 */
char& MyList::operator[](const int i)
{
    cout << "calling operator[]...\n";
    Node* head_node = head;
    
    static char null = '\0';
  
        while(head_node!=NULL)
        {
            if(head_node->value==i)
            {
                return head_node->value;
            }
            head_node=head_node->next;
        }

    return null;
}

//******************************************************************//


