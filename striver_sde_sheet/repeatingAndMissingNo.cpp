#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//XOR method
void repeatAndMissingNumber(int arr[],int n)
{
    int XOR=0;
    int x=0;
    int y=0;
    for(int i=0;i<n;i++)
    {
        XOR^=arr[i]^i+1;
    }
    int setBit=XOR & ~(XOR-1);
    for(int i=0;i<n;i++)
    {
        if(arr[i]&setBit)
        {
            x=x^arr[i];
        }
        else
        {
            y=y^arr[i];
        }

        if((i+1)&setBit)
        {
            x^=i+1;

        }
        else
        {
            y^=i+1;
        }
    }


    //To check out of x ans y which one is repeating no and which is missing no.
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            break;

        }
        if(arr[i]==y)
        {
            swap(x,y);
            break;
        }
    }
    cout<<x<<" "<<y;
}


//sign trick method

// void repeatAndMissingNumber(int arr[],int n)
// {
//     int a;
//     int b;
//     for(int i=0;i<n;i++)
//     {
//         if(arr[abs(arr[i])-1]>0)
//         arr[abs(arr[i])-1]=-arr[arr[i]-1];

//         else     //repeating number
//         a=arr[i];
//     }
//     for(int i=0;i<n;i++){

//         if(arr[i]>0)    //missing number
//         {
//             b=i+1;
//         }
//     }
//     cout<<a<<" "<<b;
// }
int main()
{
    int arr[]={5,1,2,5,3,4,6};
    repeatAndMissingNumber(arr,7);
    return 0;
}