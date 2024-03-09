#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> buildArray(vector<int> &target, int n)
{
    int currentNumber = 1; // Initialize the stream
    vector<string> result; // Vector to store the operations

    int i = 0; // Index for the target array

    // Loop until we process all elements of the target array or reach the end of the stream
    while (i < target.size() && currentNumber <= n)
    {
        result.push_back("Push"); // Push the current number

        // If the current number matches the target number, move to the next target number
        if (currentNumber == target[i])
        {
            i++;
        }
        else
        {
            result.push_back("Pop"); // If the current number doesn't match, pop
        }
        currentNumber++; // Move to the next number in the stream
    }

    return result;
}

int main()
{
    // Test case
    vector<int> target = {1, 3}; // Target array
    int n = 3;                   // Maximum value in the stream

    // Generate the sequence of operations
    vector<string> result = buildArray(target, n);

    // Display the sequence of operations
    for (const string &operation : result)
    {
        cout << operation << " ";
    }
    cout << endl;

    return 0;
}
