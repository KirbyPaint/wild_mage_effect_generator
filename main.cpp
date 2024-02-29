#include <iostream>
#include <fstream>

#include <string>

using namespace std;

int numEffect = 101;

int main()
{
    string *effect_string = new string[numEffect];
    int i;
    i = 0;
    string effect = " ";

    int *effect_int = new int[numEffect];
    for (int h = 0; h < numEffect; h++)
    {
        effect_int[h] = h;
    }

    ifstream effect_file ("effects.txt");
    if (effect_file.is_open())
    {
        while ( getline (effect_file,effect) )
        {
            effect_string[i] = effect;
            i++;
        }
        effect_file.close();
    }

    else cout << "Unable to open file";

    startprog:

    cout << "Enter percentile rolled:" << endl;
    int effectInput = 1;
    cin >> effectInput;
    cout << "   " << effect_string[(effectInput - 1)] << " ";

    cout << endl;
    cout << "Would you like another? 1 for yes, 0 for no." << endl;
    int answer = 0;
    cin >> answer;

    if (answer == 1)
    {goto startprog;}

    else if (answer == 100)
    {
        for (int y = 0; y < 100; y++)
        {
            cout << y+1 << ") " << effect_string[y];
            cout << endl;
        }
    }

    delete [] effect_string;
    delete [] effect_int;

    return 0;
}
