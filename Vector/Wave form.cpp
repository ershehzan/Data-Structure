#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    cout << "wave form" << endl;

    for (int j = 0; j < 4; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                cout << matrix[i][j] << " ";
            }
          
        }
            else
            {
                for(int i=2;i>=0;i--){
                    cout<<matrix[i][j]<<" ";
                }
        }
        
}
return 0;
}
