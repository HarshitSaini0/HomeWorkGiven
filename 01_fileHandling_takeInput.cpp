#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream f1;
    f1.open("story.txt", ios::out);
    char line[100];
    for (int i = 1; i <= 5; i++)
    {
        cout << "Enter " << i<< "th line : ";
        cin.getline(line, 100);
        f1 << line << endl;
    }
    f1.close();

    return 0;
}
