#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    //reading the first line
    int amt_of_arrays, amt_of_queries; 
    cin>>amt_of_arrays>> amt_of_queries; 
    
    vector<vector<int>> arrays(amt_of_arrays); 
    
    //reading from the arrays 
    for(int i = 0; i<amt_of_arrays; i++)
    {
        //get the size from the first number in the line 
        int size = 0; 
        cin>>size; 
        
        //put values in based on the size
        for(int j = 0; j<size; j++)
        {
            int val; 
            cin>>val; 
            arrays[i].push_back(val); 
        }
    }
    // //print out arrays for testing
    // for(int i =0; i<amt_of_arrays; i++)
    // {
    //     cout<<"printing the "<<i+1<< " array"<<endl; 
    //     for(int j =0; j<arrays[i].size(); j++)
    //     {
    //         cout<<arrays[i][j]<<" "; 
    //     }
    //     cout<<endl; //newline for each array
        
    // }
    
    
    //queries 
    int counter = 0; 
    while(counter < amt_of_queries)
    {
        int x, y; 
        cin>>x >>y; 
        
        cout<<arrays[x][y]<<endl; 
        counter ++; 
    }
    
    
    
    
    return 0;
}