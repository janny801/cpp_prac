#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

int main() 
{
    
    // Enter your code here
    fstream input;
    input.open("input.txt"); 

    //output file
    ofstream output; 
    output.open("output.txt"); 

    int num; 
    while(input>>num)
    {
        
        //check the amt of divisors 
        int counter = 0; //counting the amt of divisors 
        for(int i =1; i<=num; i++)
        {
            if(num%i==0)
            {
                counter++; 
            }
            else
            {
                continue; 
            }
        }

        output<<counter<<' '; 
    }

    output.close(); //breh dont forget to close it 

    // DO NOT CHANGE THE CODE BELOW!
    ifstream file("output.txt");
    string line;
    getline(file, line);
    cout << line;
    file.close();
}