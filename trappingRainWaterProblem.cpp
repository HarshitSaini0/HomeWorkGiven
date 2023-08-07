#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the length of total block length : ";
    cin >> n;
    int arr[n];
    cout << "Enter the values : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int drops = 0, i, j;
    int tempVal = 0, index = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] >= tempVal)
        {
            for (j = index; j <= i; j++)
            {
                drops += tempVal;
                if (arr[j] != 0)
                {
                    if (arr[j] > tempVal)
                    {

                        drops -= tempVal;
                    }
                    else
                    {
                        drops -= arr[j];
                    }
                }
            }
            index = i;
            tempVal = arr[i];
        }
    }

    cout << drops << endl;
    return 0;
}
