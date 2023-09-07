#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    char line[100];
    fstream f1;
    f1.open("story.txt", ios::in);
    while (f1.getline(line, 100))
    {
        for (int i = 0; line[i] != '\0'; i++)
        {
            line[i] = toupper(line[i]);
        }
        cout << line << endl;
    }
    f1.close();

    return 0;
}
