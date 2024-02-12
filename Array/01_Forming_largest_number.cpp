#include<bits/stdc++.h>
using namespace std;



/*For the string elements*/
int compare(string first,string second)
{
    string firstsecond = first+second;
    string secondfirst = second+first;

    return firstsecond.compare(secondfirst)>0?1:0;
}
void formingLargestFromArray(vector<string>&arr)
{
    sort(arr.begin(),arr.end(),compare);
    for(int i=0;i<arr.size();i++)
        cout<<arr[i];

}


/*For the integer element*/
static bool integercompare(int firstInt, int secondInt)
{
 
    int firstNum = firstInt, secondNum = secondInt;
 
    // Count length of firstInt and secondInt
    int countx = 0, county = 0;
 
    // Count length of X
    while (firstInt > 0) {
        countx++;
        firstInt /= 10;
    }
 
    // Count length of Y
    while (secondInt > 0) {
        county++;
        secondInt /= 10;
    }
 
    firstInt = firstNum;
    secondInt = secondNum;
 
    while (countx--)
        secondNum *= 10;
 
    while (county--)
        firstNum *= 10;
 
    // Append firstInt to secondInt
    secondNum += firstInt;
 
    // Append secondInt to firstInt
    firstNum += secondInt;
 
    return firstNum > secondNum;
}

/*Will write the efficient one very soon */

void formingLargestFromArrayInteger(vector<int>&arrint)
{
    sort(arrint.begin(),arrint.end(),integercompare);
    for(int i=0;i<arrint.size();i++)
        cout<<arrint[i];

    
}
int main()
{
    vector<string> arr;

    arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");
    // formingLargestFromArray(arr);

    vector<int>intarray;
    intarray.push_back(54);
    intarray.push_back(546);
    intarray.push_back(548);
    intarray.push_back(60);
    formingLargestFromArrayInteger(intarray);
    

    return 0;
    
}