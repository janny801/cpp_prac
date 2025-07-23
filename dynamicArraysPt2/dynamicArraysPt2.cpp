#include <iostream>

using namespace std;

int main() {
    // Write code here
    int len; 
    cin>>len; 

    int nums; 

    //allocating for 'len' integers
    int *numbers = new int[len];

    //filling up the array 
    for(int i = 0; i<len; i++)
    {
        cin>>nums; 
        numbers[i] = nums; 

        if(i%2==0)
        {
            //print out all elements on even posititions 
            cout<<numbers[i]<<" "; 
        }
    }


    //deallocate the memory 
    delete[] numbers; 

    return 0;
};