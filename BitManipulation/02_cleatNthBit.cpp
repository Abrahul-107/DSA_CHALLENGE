#include<bits/stdc++.h>
using namespace std;

/*
Suppose we want to unset a bit at nth position in number ‘num’ then we have to do this with the help of ‘AND’ (&) operator.

First, we left shift ‘1’ to n position via (1<<n) then we use bitwise NOT operator ‘~’ to unset this shifted ‘1’.
Now after clearing this left shifted ‘1’ i.e making it to ‘0’ we will ‘AND'(&) with the number ‘num’ that will unset bit at nth position.*/

void clearNthBit(int &num,int pos)
{
    // cout<<(~(1<<pos));  first it convert 1<<pos that means it will convert 1010 to 1000 then ~ of 1000 is 0111
    num = num &(~(1<<pos));

}
int main()
{
    int num = 10;
    int position = 3;
    clearNthBit(num,position);

    cout<<"After clear nth bit number is "<<num<<endl;


    return 0;

}