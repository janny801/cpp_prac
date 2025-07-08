#include <iostream> 
#include <string> 
using namespace std; 

class Solution {
public:
    bool isPalindrome(int x) {

        string as_string = to_string(x); //conv to string

        //check if palindrome

        //get reversed string
        string reversed =""; 

        for(int i =as_string.size()-1; i>=0;i--)
        {
            reversed += as_string[i]; 
        }

        cout<<"regular: "<<as_string<<endl; 
        cout<<"reversed: "<<reversed<<endl; 

        //compare regular vs reversed to see if palindrome
        int index2check =0; 

        while(index2check < as_string.size()-1)
        {

            cout<<"comparing values: " <<endl; 
            cout<<"regular: "<<as_string[index2check]<<" reversed: "<<reversed[index2check]<<endl; 

            cout<<endl; 

            if(as_string[index2check] != reversed[index2check])
            {
                return false; 
            }
            else
            {
                index2check ++; 
            }
        }

        return true; 

        
    }
};

int main()
{
    Solution sol;     // Create object of Solution class

    int x; 
    std::cin >> x;    // Read input from user

    bool result = sol.isPalindrome(x);  // Call the member function

    if (result)
        std::cout << "true\n";
    else
        std::cout << "false\n";

    return 0; 
}
