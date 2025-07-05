#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    
    // Enter your code here
    ifstream scores; 
    // scores.open("input.txt"); 
    string error_msg = "Student failed the course"; 

    int sum =0; //used to calculate for the avg
    int stuCounter =0; //used to find total amt of passing students



    scores.open("input.txt"); 
    string line; 

    while(!scores.eof())
    {

        try
        {
            getline(scores,line); 

            string num = ""; 
            //get the digits in each line (used for calculations)
            for(char c: line)
            {
                if(isdigit(c))
                {
                    num +=c; 
                }
            }


            // cout<<num<<endl; //testing; displays the grade for each individual student on a newline each
            //                 //but as a string 



            //convert num to integer
            int grade = stoi(num); 

            if(grade>50)
            {
                //if passing -> include their grade in passing avg
                sum+=grade; 
                stuCounter++; 
            }
            else
            {
                throw error_msg; 
            }
        }
        catch(string msg)
        {
            cout<<msg<<endl; 
        }
        


    }

        
        //cout<<line<<endl; //testing ; prints out each lines content 
    
        //calculate avg
        int avg = sum/ stuCounter; 

        cout<<avg; 


    
    return 0;
}