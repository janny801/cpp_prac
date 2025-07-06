#include <iostream>
#include <fstream>
#include <string> 
#include <algorithm> 

using namespace std;

int main() 
{
    
    // Enter your code here
    fstream books; 

    books.open("input.txt"); 
    string line; 

    string error_message = "Book overdue"; //if borrowed for more than 14 days 

    //use these vals to calc the avg
    int sum = 0; 
    int counter = 0; 
    //use these vals to calc the avg

    while(!books.eof())
    {

        
        try
        {

        
            getline(books,line); 
            string num = ""; //conver to int later using stoi() 

            //read 'line' backwards til you get to quotation marks
            for(int i = line.length()-1; i>=0; i--)
            {
                //
                char c= line [i]; 
                //read until quotation marks

                if(c!= '"')
                {
                    num+=c; 
                }
                else
                {
                    break; 
                }
                //reverse the string so that the number is proper

            } 

            reverse(num.begin(), num.end()); // now num is in corrct order

            //cout<<num<<endl; //test to print out days_borrowed as string

            //convert num to string 
            int days_borrowed = stoi(num); 
             sum += days_borrowed; 
             counter++; 
            

            //cout<<days_borrowed<<endl; 


            //check if borrowed days longer than 14 (if so throw error)
            if(days_borrowed>14)
            {
                throw error_message; 
            }
            

        }
        catch(string msg)
        {
            cout<<msg<<endl; 
        }


        
    }

     //print avg 
        double avg= sum / (double)counter; 

        cout<<avg; 

    
    return 0;
}