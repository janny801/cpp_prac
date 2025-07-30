#include <iostream>
#include <fstream>
#include <string> 

using namespace std;


bool isPalindrome(string x)
{

    //get the reversed string (to compare to original)
    string reverse = ""; 
    for(int i =x.length()-1; i>=0; i--)
    {
        //
        reverse+=x[i]; 
    }


    // cout<<"regular: "<<x<<endl; 
    // cout<<"reversed: "<<reverse<<endl; 

    //compare char by char the regular and reverse 
    for(int i = 0; i<x.length(); i++)
    {
        if(x[i]!=reverse[i])
        {
            return false; 
        }
    }
    return true; 


}

 
int main()
{
    
    // Enter your code here
    fstream input; 
    input.open("input.txt"); 

    //go thru each iteration and pass each line to the isPalindrome func
    string line; 
    while(getline(input,line))
    {


        //remove carriage return (edge cases) 
        if(!line.empty() && line.back() == '\r')
        {
            line.pop_back(); 
        }

        //pass to isPalindrome func
        if(isPalindrome(line))
        {
            //isPalindrome is true
            cout<<"Palindrome"<<endl; 
        }
        else
        {
            //isPalindrome is false
            cout<<"Not a palindrome"<<endl; 
        }
    }

    return 0;
}