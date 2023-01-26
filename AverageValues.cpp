#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    string filename;

    cout << "Enter the input file name: ";
    cin >> filename;
    cout << endl;

    ifstream inputFile;
    inputFile.open(filename);

    ofstream outputFile;
    outputFile.open ("badvalues.txt");

    double number;
    int invalid = 0;
    int valid = 0;
    int total = 0;
    double sum = 0;

    if (!(inputFile))
        cout << "The file \"" << filename << "\" could not be opened." << endl;

    else if (inputFile)
    {
        while (inputFile >> number)
        {
            total++;

            if (total == 0)
            {
                cout << "The file did not contain any valid values." << endl;
            }

            if (number < 1 || number > 150)
            {
                outputFile << setprecision (3) << fixed << number << endl;
                invalid ++;
            }

            else if (number >= 1 || number <= 150)
            {
                valid++;
                sum += number;
            }
        }

        cout << "Total number of values read: " << total << endl;
        cout << "Valid values read: " << valid << endl;
        cout << "Invalid values read: " << invalid << endl;

        double avg = sum / valid;

        if (!(valid == 0))
            cout << "The average of the valid numbers read = " << setprecision(2) << fixed << avg << endl;
        else if (valid == 0)
            cout << "The file did not contain any valid values." << endl;
    }

    inputFile.close();

    outputFile.close();
}
