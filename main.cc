/**
 * First Name:      Isaac
 * Last Name:       Lino
 *
 * Filename :       main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 */

#include <iostream>
#include "node.h"
#include "MyList.h"

using namespace std;

int main()
{
 
    // Test Constructors and Destructors Part 1.1 /
    cout << "\n********** Testing Constructors and Destructors Part 1.1 **********" << endl;
    
    MyList MyList1;
    MyList MyList2;
    
    // Test Mutators Part 1.2 /
    cout << "\n\n******************** Testing Mutators Part 1.2 ********************" << endl;
    
    cout << "\n\nPush front (prePend) List: ";// <<endl;
    MyList1.push_front('0');
    MyList1.push_front('2');
    MyList1.push_front('5');
    MyList1.push_front('9');
    MyList1.push_front('7');
    MyList1.push_front('1');
    MyList1.print();
    
    cout << "\n\nPush back (Append) list";// <<endl;
    MyList2.push_back('3');
    MyList2.push_back('0');
    MyList2.push_back('1');
    MyList2.push_back('9');
    MyList2.push_back('7');
    MyList2.push_back('9');
    MyList2.push_back('6');
    MyList2.push_back('2');
    MyList2.push_back('4');
    MyList2.print();
    
    cout<<"\n\npop_front() called to remove front item from list"<<endl;
    MyList2.pop_front();
    MyList2.print();
    
    cout<<"\n\npop_back() called to remove last item from list"<<endl;
    MyList2.pop_back();
    MyList2.print();
    
    cout << "\n\ninsert_at_pos() called to inset a node with value at i position" << endl;
    MyList2.print();
    MyList2.insert_at_pos(2,'5');
    MyList2.print();
    
    cout<<"\n\nreverse() called to reverse list"<<endl;
    MyList2.print();
    MyList2.reverse();
    MyList2.print();
   
    // Test for accessors Part 1.3 //
    cout << "\n\n********************** Testing Accessors 1.3 **********************" << endl;
    MyList2.print();
    MyList2.size();
    
    cout<<"\n\nfind() called to find a value and return position"<<endl;
    MyList2.print();
    MyList2.find('0');
    
    // Test for operator overloaders Part 1.4 //
    cout << "\n\n**************** Testing Operator Overloaders 1.4 *****************" << endl;
    
    return 0;
    
}
