#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

double convertPriceToUAH(double priceInDollars, double exchangeRate) {
    return priceInDollars * exchangeRate;
}

void processFile(const string& inputFileName, const string& outputFileName, double exchangeRate) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file!" << endl;
        return;
    }
    if (!outputFile.is_open()) {
        cerr << "Unable to open output file!" << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string companyName, productName;
        double priceInDollars;

        ss >> companyName >> productName >> priceInDollars;

        double priceInUAH = convertPriceToUAH(priceInDollars, exchangeRate);
        outputFile << fixed << setprecision(2);
        outputFile << companyName << " " << productName << " " << priceInDollars << " " << priceInUAH << endl;
    }
}

string getInputFileName() {
    string fileName;
    cout << "Enter the input file name: ";
    cin >> fileName;
    return fileName;
}

string getOutputFileName() {
    string fileName;
    cout << "Enter the output file name: ";
    cin >> fileName;
    return fileName;
}

double getExchangeRate() {
    double exchangeRate;
    cout << "Enter the exchange rate from USD to UAH: ";
    while (!(cin >> exchangeRate) || exchangeRate <= 0) {
        cout << "Please enter a valid exchange rate: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return exchangeRate;
}

int main() {
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Convert prices from USD to UAH" << endl;
        cout << "2. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string inputFileName = getInputFileName();
            string outputFileName = getOutputFileName();
            double exchangeRate = getExchangeRate();

            processFile(inputFileName, outputFileName, exchangeRate);
        }
        else if (choice == 2) {
            cout << "Exiting program." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}