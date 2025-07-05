
#include <iostream>
#include <vector> 


using namespace std;


int main()
{
    // Enter your code here
    int arrlen;
    cin>>arrlen;


    vector<int> arr(arrlen);


    //get input to put into array
    for(int i =0; i<arrlen; i++)
    {
        cin>>arr[i];
    }
   


    // //output current array for test
    // for(int i =0; i<arrlen; i++)
    // {
    //     cout<<arr[i]<<endl;
    // }


    //find largest and smallest numbers
    int largest = -100000000;
    int smallest= 100000000;


    //loop thru to find the largest and smallest nums
    for(int i =0; i<arrlen; i++)
    {
        if(arr[i]>largest)
        {
            //if it is larger
            largest = arr[i];
        }
         if(arr[i]<smallest)
        {
            smallest = arr[i];
        }
    }






    //output smallest and largest vals
    cout<<smallest<<' '<<largest;




    return 0;
}
