#include <iostream>

using namespace std;

int main() {

    int *numbers = new int[5];
    for(int i = 0; i < 5; i++)
        numbers[i] = i + 1;
    // DON'T CHANGE THE CODE ABOVE


    // Enter your code here

    // Input 3 integers
    int addnum; 
    

    // Dynamically add them to the array "numbers"

    int length = 5;     
    int *newarray = new int[length+3]; //new array with 3 more elements
    //copy all of elements from old array into new array 
    for(int i =0; i<5; i++)
    {
        newarray[i]=numbers[i]; 
        //copy all elements from old array to new array 
    }

    for(int i =5;i<8;i++) // add to back of newarray
    {
        //add new numbers
        cin>>addnum; 
        newarray[i]=addnum; 
    }

    delete[] numbers; //deallocate old array
    numbers = newarray; //point to the newarray



    // DON'T CHANGE THE CODE BELOW
    for(int i = 0; i < 8; i++)
        cout << numbers[i] << " ";
    delete[] numbers;

    return 0;
}