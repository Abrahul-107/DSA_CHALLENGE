#include<iostream>

using namespace std;

long long dividePlayers(vector<int>&skill)
{
    sort(skill.begin(),skill.end());
    int size = skill.size();
    int targetChem = skill[0] + skill[size-1];
    long long totalChem = 0;

    for(int i=0;i<size/2;++i)
    {
        if(skill[i]+skill[size-i-1] != targetChem)
            return -1;
        totalChem += (long long)skill[i]*skill[size-i-1];
    }
    return totalChem;
}

int main()
{
    vector<int>skill = {3,2,5,1,3,4};
    cout<<dividePlayers(skill);


    return 0;
}