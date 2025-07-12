#include <string>
#include <iostream> 

using namespace std;
string sippingCocoa(string dipper, int sips) {
        // Write code here

        int sipcounter = 0; 
        int iterator= 0; 


        while(sips>=0)
        {
                //base case? 
                //if dipper is empty but sips still greater than 1 
                if(dipper.empty()&& sips>0)
                {
                        return ""; 
                }

                if(sipcounter ==2 && (!dipper.empty())) // if sips =2 and there is still stuff left in cup 
                {
                        sipcounter=0; //reset sipcounter to 0
                        //every two sips add 'm' to end of string 
                        dipper += "M"; 
                }

                if(!dipper.empty() && sips!=1)
                {
                        //cout<<"dipper before erasing: "<<dipper<<endl; 
                        dipper.erase(iterator,1); 
                }
                
                sipcounter ++; 
                sips--; 
        }


        //cout<<"final value of dipper: "; 
        cout<<dipper<<endl; 

        return ""; 
        
}


//return final contents of the dipper based on the number of sips taken 
