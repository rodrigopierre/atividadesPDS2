#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

bool isAlnum(char c) {
    return isalnum(static_cast<unsigned char>(c));
}

int main() {
    string filename;
    cin >> filename;
    ifstream file(filename);
    if (!file) {return 1;}
    map<string, int> wordCount;
    string line;

    while (getline(file, line)) {
        string word;
        stringstream ss(line);

        while (ss >> word) {
            string cleanedWord;
            for (char c : word) {
                if (isAlnum(c)) {
                    cleanedWord += tolower(c);
                } else if (!cleanedWord.empty()) {
                    wordCount[cleanedWord]++;
                    cleanedWord.clear();
                }
            }
            if (!cleanedWord.empty()) 
                wordCount[cleanedWord]++;
        }
    }
    file.close();

    for (const auto& pair : wordCount) 
        cout << pair.first << " " << pair.second << endl;

    return 0;
}