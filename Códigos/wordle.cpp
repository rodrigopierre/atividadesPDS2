#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream file("palavras.txt", fstream::in);
    if (!file.is_open()) { return 1; }

    string line, word;
    getline(file, line);
    int tries = 0, number, n = std::stoi(line);
    cin >> number;

    for (int i = 1; i <= n; i++) {
        getline(file, word);
        if (i == number) {
            break;
        }
    }

    string letters = "", wordReturn = "*****", wordReturn2 = "*****";

    while (true){
        for (int c = 0; c < 5; c++) {
            if (wordReturn[c] != word[c]) {
                wordReturn[c] = wordReturn2[c];
            }
        }

        string wordTry;
        cin >> wordTry;

        for (int i = 0; i < 5; i++){
            int position = word.find(wordTry[i]);
            if (position != std::string::npos) {
                if (position == i) {
                    int positionLater = wordReturn.find(tolower(wordTry[i]));
                    if (positionLater != std::string::npos){
                        wordReturn[positionLater] = wordReturn2[positionLater];
                    }
                    wordReturn[i] = word[i];
                } else {
                    wordReturn[i] = tolower(wordTry[i]);
                }
            } else {
                if (letters.find(wordTry[i]) == std::string::npos){
                    letters.push_back(wordTry[i]);
                }
            }
        }
        cout << wordReturn << " (" << letters << ")" << endl;
        tries ++;

        if (wordReturn == word) {
            cout << "GANHOU!" << endl;
            break;
        }

        if (tries == 5) {
            cout << "PERDEU! " << word << endl;
            break;
        }
    }

    return 0;
}