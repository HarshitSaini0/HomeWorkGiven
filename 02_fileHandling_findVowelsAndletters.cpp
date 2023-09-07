#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isVowel(char val)
{
    val = toupper(val);
    if (val == 'A' || val == 'E' || val == 'O' || val == 'I' || val == 'U')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    char val;
    int alpbts = 0, vowels = 0;
    fstream f1;
    f1.open("story.txt", ios::in);
    while (f1 >> val)
    {
        alpbts++;
        if (isVowel(val))
        {
            vowels++;
        }
    }
    f1.close();
    cout <<"There are "<< alpbts <<" letters. "<< endl
         << "There are "<<vowels <<" vowels. "<< endl;
    return 0;
}
