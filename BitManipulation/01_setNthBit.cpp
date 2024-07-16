#include<bits/stdc++.h>
using namespace std;

//If we want to set a bit at nth position in the number ‘num’, it can be done using the ‘OR’ operator( | ).  

/*First, we left shift ‘1’ to n position via (1<<n)
Then, use the ‘OR’ operator to set the bit at that position. ‘OR’ operator is used because it will set the bit 
even if the bit is unset previously in the binary representation of the number ‘num’.*/


void setNthBit(int &num,int pos)
{
    num = num | (1<<pos);
}

int main()
{
    int num = 10;
    int position = 2;
    setNthBit(num,position);
    cout<<"Number after set nth bit is "<<num<<endl;

    return 0;
    
}