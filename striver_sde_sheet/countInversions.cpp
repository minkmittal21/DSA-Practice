#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//using merge sort method
int countInversions(int arr[],int s,int mid,int e)
{
    int temp[e-s+1];
    int k=0;
    int count=0;
    int i=s;
    int j=mid+1;
    while((i<=mid) && (j<=e))
    {
        if(arr[i]<=arr[j])
        temp[k++]=arr[i++];

        else
        {
            temp[k++]=arr[j++];
            count=count+mid-i+1;
        }
    }

    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=e)
    {
        temp[k++]=arr[j++];
    }
    k=0;
    for(int i=s;i<=e;i++)
    {
        arr[i]=temp[k++];
    }

 return count;
}
int merge_Sort(int arr[],int s,int e)
{
    int count=0;
    int mid;
    if(s<e)
    {
        mid=s+(e-s)/2;
        count+=merge_Sort(arr,s,mid);

        count+=merge_Sort(arr,mid+1,e);
        count+=countInversions(arr,s,mid,e);
    }
    return count;
}
int main()
{
    int arr[]={5,3,2,1,4};
    int n=5;
    int ans = merge_Sort(arr,0,n-1);
    cout<<"The total inversions are "<<ans<<endl; 
}