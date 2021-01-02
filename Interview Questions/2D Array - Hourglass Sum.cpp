/* Arrays Interview Problem:
Calculate the hourglass sum for every hourglass in arr, then print the maximum hourglass sum. The array will always be 6x6.
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int count = -64;
    int row = 0;
    int col = 0;
    int temp;
    while (row < 4)
    {
        temp = arr[row][col] + arr[row][col + 1] + arr[row][col + 2] + arr[row + 1][col + 1] + arr[row + 2][col] + arr[row + 2][col + 1] + arr[row + 2][col + 2];

        if (temp > count)
        {
            count = temp;
        }

        col += 1;

        if (col == 4)
        {
            col = 0;
            row += 1;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
