#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(int *arr, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int currentAsteroid = arr[i]; // Store the current asteroid's value

        while (!st.empty() && currentAsteroid < 0 && st.top() > 0)
        {
            int sum = st.top() + currentAsteroid;
            if (sum < 0)
            {
                st.pop(); // Destroy the asteroid moving right
            }
            else if (sum > 0)
            {
                currentAsteroid = 0; // Destroy the current asteroid
                break;               // Exit the while loop
            }
            else
            {
                st.pop();            // Destroy both asteroids
                currentAsteroid = 0; // Destroy the current asteroid
                break;               // Exit the while loop
            }
        }
        if (currentAsteroid != 0)
            st.push(currentAsteroid); // If the current asteroid survives, push it onto the stack
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top()); // Store remaining asteroids
        st.pop();
    }
    reverse(ans.begin(), ans.end()); // Reverse the order to print in the correct sequence
    return ans;
}

int main()
{
    int arr[] = {5, 10, -5}; // Added one more asteroid for testing
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> ans = asteroidCollision(arr, size); // Corrected function call

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}
