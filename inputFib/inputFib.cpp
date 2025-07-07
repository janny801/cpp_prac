#include <iostream>
#include <fstream>

using namespace std;

//func to find fib
void findfib(int num)
{
    int a=1; int b=1; 
    while(a<=num)
    {
        cout<<a<<" "; 
        int next= a+b; 
        a=b; 
        b= next; 
    }
}


int main()
{
    
    // Enter your code here
    ifstream input; 
    input.open("input.txt"); 
    int num; 
    while(!input.eof()) {
        input >> num; 

        //now find fib sequence for each num 
        findfib(num); 
        cout<<endl; 
    }

 
    return 0;
}