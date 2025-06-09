<<<<<<< HEAD
#include <iostream>
using namespace std;

int main()
{

    int arr[6] = {1, 2, 3, 4, 5, 6};

    int start = 0, end = 5;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    };
    for (int i = 0; i < 6; i++)
        cout << arr[i]<<" ";

    return 0;
}
=======
#include <iostream>
using namespace std;

int main()
{

    int arr[6] = {1, 2, 3, 4, 5, 6};

    int start = 0, end = 5;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    };
    for (int i = 0; i < 6; i++)
        cout << arr[i]<<" ";

    return 0;
}
>>>>>>> 549b0d8 (file update)
