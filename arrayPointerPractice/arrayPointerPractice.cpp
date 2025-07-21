#include <iostream>

using namespace std;

int main() {
    
    int numbers[] = {10, 20, 30, 40, 50, 60, 70, 80};
    
    // Enter code for ptr1
    int *ptr1 = numbers;  
    
    // Enter code for ptr2
    int *ptr2 = ptr1; 
    //increment ptr2 to move to the fourth element 
    ptr2 +=3; 
    
    // Enter code for ptr3
    int *ptr3= ptr2; 
    //decrement ptr3 by 2 
    ptr3-=2; 

    
    // Print out the wanted message    
    int *first = numbers; 
    
    //get length of the array 
    int length = sizeof(numbers)/sizeof(numbers[0]); 
    int *last = numbers + (length-1); 

    int difference = last- first; 
    cout<<"There are "<<difference<<" elemenents between "<<*first<<" and "<<*last <<endl; 
    
    
    // DO NOT CHANGE ANYTHING BELOW THIS
    // ---------------------------------

    cout << "*ptr1 -> " << *ptr1 << endl;
    cout << "*ptr2 -> " << *ptr2 << endl;
    cout << "*ptr3 -> " << *ptr3 << endl;
    
    return 0;
}