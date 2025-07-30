#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string getOutput(const string& queryLine, const vector<string>& hrml)
{
    /* notes 
    
    const; function wont modify the input values 
        - ensure we dont modify the actual values of queryLine and hrml 
    &; not copying entire string or vector
        - queryLine and hrml are used directly (not duplicated memory) 
        - faster -> especially for vector<string> (could be large) 
        
    .find(char to find, start position) 
    
    .substr(start index, how many characters to include)

    
    */ 
    
    //function to find the string to output 
    
    //step 1; split the queryLine into path and attribute
    int tilde = queryLine.find('~'); 
    string path = queryLine.substr(0,tilde); //whole path from the query 
    string attribute= queryLine.substr(tilde+1);
    
    /*testing -- print out path and attribute to find 
    cout<<"Query Path: "<<path<<endl; 
    cout<<"Query Attribute to find: "<<attribute<<endl;
    */ 
    
    
    //variables to track current tag path while parsing hrml 
    string currentPath = ""; //compare current tag path with the given query path  
                            //ensures the output comes from the correct nested tag structure 
    vector<string> pathStack; //acts as a stack 
                            //but allows for us to access individual elements in the path 
    
    
    //step 2 ; loop thru each line of the hrml input 
    for(int i =0; i<hrml.size(); i++)
    {
        string line = hrml[i]; 
        
        if(line.substr(0,2) == "</")
        {
            //handle closing tag
            // pop last tag from the path stack 
            if(!pathStack.empty())
            {
                pathStack.pop_back(); 
            }
        }
        else
        {
            //handle opening tag 
            int spacePosition = line.find(' '); //used to separate tag name and attribute (name, value) 
            if(spacePosition == -1)
            {
                spacePosition = line.find('>'); 
            }
            string tagName = line.substr(1, spacePosition-1); //extract tag name (remove '<')
            
            pathStack.push_back(tagName); //add path name to the pathStack vector (keeps track of nested tags)
                                        //used to compare to the string path from the queryLine
            
             //build the full tag path using dot notation 
             //only build/update the full path when a new tag is opened 
             currentPath = pathStack[0]; //start with outermost tag (first element in the stack)
                                        //resets the path each time (so that we get the current path we are traversing)
                                        //ensures no duplication from previous path values 
             
             //append nested tags (if any) -- separated by '.' 
             //ex "tag1.tag2.tag3"
             for(int j =1; j< pathStack.size(); j++)
             {
                currentPath += "." + pathStack[j]; 
             }
             
             //step 3; if current path matches query path (from input) -> search for the attribute 
             // only start to look for attribute if in the correct (fully matched) tag
             if(currentPath ==path) 
             {
                string attributePattern = " " + attribute + " = \""; //string pattern we are trying to find in the line 
                                                            //that matches how the attributes are written 
                
                int attributePosition = line.find(attributePattern); 
                if(attributePosition!=-1)
                {

                    //step 4a; attribute found -> locate value inside the quotes 
                    int quoteStart = line.find('"', attributePosition); //find opening quotation mark 
                                                                        //starting from attribute position 
                    int quoteEnd = line.find('"', quoteStart+1); //find closing quotation mark 
                                                                //starting one index after opening quotation mark
                                                                
                    //step 5; get substring between the quotes -- this is attribute value 
                    return line.substr(quoteStart+1, quoteEnd- quoteStart -1); 
                    // '+1' and '-1' exclude the starting and ending quotation marks -> only return attribute value
                }
                else
                {
                    //attributePosition = -1 (ie not found) 
                    //step 4b; attribute not found -> return "Not Found"
                    return "Not Found!"; 
                }
             }
             
                   
        }
    }
    
    
    
    //incase; reached end of hrml without finding matching tag and attribute
    return "Not Found!"; 
    
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int hmrlLines; 
    int amtOfQueries; 
    
    cin>>hmrlLines>>amtOfQueries; 
    
    cin.ignore(); //clear leftover newline
    
    vector<string> hrml; 
    vector<string> queries; 
    
    

    
    //read hmrl lines and put into vector 
    for(int i =0; i<hmrlLines; i++)
    {
        string line; 
        getline(cin,line); 
        hrml.push_back(line); 
    }
    
    //read queries lines and put into vector 
    for(int i =0; i<amtOfQueries; i++)
    {
        string line; 
        getline(cin, line); 
        queries.push_back(line); 
    }
    
    
    for(int i = 0; i<queries.size(); i++)
    {
        //find string to output 
        string result = getOutput(queries[i], hrml); 
        cout<<result<<endl; //output from the helper function 
        
    }
    
    
    
    
    
    
    
    
    /*testing
    cout<<"HMRL Lines: "<<hmrlLines<<endl; 
    
    cout<<"Amount of queries: "<<amtOfQueries<<endl; 

    cout<<endl; 
    
    //testing; print out hmrl lines one by one
    for(int i =0; i<hrml.size(); i++)
    {
        cout<<"Line #"<<i<<": "<<hrml[i]<<endl; 
    }
    
    cout<<endl; 
    
    //testing print out each query 
    for(int i = 0; i<queries.size(); i++)
    {
        cout<<"Query #"<<i <<": "<<queries[i]<<endl; 
    }
    testing*/

  
    
    return 0;
}
