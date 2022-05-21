//optimized approach
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<int,int>> merge(vector<pair<int,int>> &arr)
{
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<pair<int,int>> ans;
    int i=1;
    int start=arr[0].first;
    int end=arr[0].second;

    while(i<n)
    {
        if(arr[i].first <= end)
        {
            if(arr[i].second>=end)
            end=arr[i].second;
            i++;
        }
        else
        {
            ans.push_back({start,end});
            
            start=arr[i].first;
            end=arr[i].second;
            i++;
        }
    }
    ans.push_back({start,end});
    
return ans;
}
int main()
{
    vector<pair<int,int>> arr;
    arr = {{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}};
    vector<pair<int,int>> ans;
    ans=merge(arr);
    int n=ans.size();
    for(int i=0;i<n;i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}