<<<<<<< HEAD


#include <iostream>
using namespace std;

int main()
{
    // Initialize the piles array with sample banana piles.
    // (In a real scenario, this would likely be user input or function parameter.)
    int piles[1000] = {3, 6, 11, 7};

    int h; // Number of hours Koko has to eat all bananas.

    // Prompt the user to enter the number of hours.
    cout << "Enter the hours : ";
    cin >> h;

    int start = 0, end = 0, mid, ans, n = 3; // n = number of piles (should be 4 based on the array)
    long long sum = 0; // To store the total number of bananas.

    // Find the total bananas and the largest pile.
    for (int i = 0; i < n; i++)
    {
        sum += piles[i];          // Add up bananas in all piles.
        end = max(end, piles[i]); // Find the pile with the maximum bananas.
    }

    // Set the minimum possible eating speed.
    // If Koko eats sum/h bananas per hour, she would just finish in time if perfectly divisible.
    start = sum / h;
    if (!start)
        start = 1; // Ensure the minimum speed is at least 1.

    // Binary search for the minimum eating speed that allows Koko to finish in 'h' hours.
    while (start <= end)
    {
        mid = start + (end - start) / 2; // Test the middle speed.

        int time = 0; // Calculate the total time needed at current speed.

        for (int i = 0; i < n; i++)
        {
            time += piles[i] / mid; // Whole hours needed for this pile.
            if (piles[i] % mid)
                time++; // If there are leftovers, need an extra hour.
        }

        // If total time exceeds allowed hours, speed is too slow, increase it.
        if (time > h)
        {
            start = mid + 1;
        }
        // If within allowed hours, try a slower speed to minimize.
        else
        {
            ans = mid;       // Record the current feasible answer.
            end = mid - 1;   // Try to find a smaller speed.
        }
    }

    // Output the result: minimum bananas Koko must eat per hour.
    cout << "KOKO have to eat " << ans << " bananas in 1 hour";

    return 0;
}
=======
// Koko Eating Bananas
#include <iostream>
using namespace std;
int main()
{
    int piles[1000] = {3, 6, 11, 7};
    int h;
    cout << "Enter the hours : ";
    cin >> h;

    int start = 0, end = 0, mid, ans, n = 3;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {

        sum += piles[i];
        end = max(end, piles[i]);
    }
    start = sum / h;
    if (!start)
        start = 1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        int time = 0;

        for (int i = 0; i < n; i++)
        {
            time += piles[i] / mid;
            if (piles[i] % mid)
                time++;
        }

        if (time > h)
        {
            start = mid + 1;
        }

        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    cout<<"KOKO have to eat "<<ans<<" bananas in 1 hour";

    return 0;
}
>>>>>>> 549b0d8 (file update)
