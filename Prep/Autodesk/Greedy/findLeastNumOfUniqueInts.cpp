#include<iostream>
#include<vector>

using namespace std;


//removing all occurrences of a low-frequency number reduces the unique count with the fewest removals
int findLeastUnique(vector<int>&arr,int k)
{
    unordered_map<int,int>mp;
    for(auto it:arr)
        mp[it]++;
    int size = arr.size();
    vector<int>bucket(size+1,0);

    //counting sort on frequencies, which avoids sorting the frequency list
    for(auto it:mp)
        bucket[it.second]++;
    /*
    bucket[1] = 1   // One numbers appear once (4)
    bucket[2] = 2  //  One number appears twice (5)
    */
    int uniqueCount = mp.size();

    for(int i=1;i<=size;++i)
    {
        while(bucket[i] >0 && k>=i)
        {
            k -= i;
            bucket[i] --;
            uniqueCount--;

        }
        if(i>k)
            break;
    }
    return uniqueCount;
}

int main()
{
    vector<int>arr = {5,5,4};
    int k = 1;
    cout<<findLeastUnique(arr,k);



    return 0;
}