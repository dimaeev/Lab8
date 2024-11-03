#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

string readFile(const string& filename) {
    ifstream file(filename);
    string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    file.close();
    return content;
}

int main() {
    string filename = "text.txt";
    string text = readFile(filename);
    
    vector<int> letterFrequency(26, 0);

    for (char c : text) {
        if (isalpha(c)) {
            c = tolower(c);
            letterFrequency[c - 'a']++;
        }
    }
    
    map<string, int> bigramFrequency;
    
    for (size_t i = 0; i < text.size() - 1; ++i) {
        if (isalpha(text[i]) && isalpha(text[i + 1])) {
            string bigram = string(1, tolower(text[i])) + string(1, tolower(text[i + 1]));
            bigramFrequency[bigram]++;
        }
    }
    
    cout << "Частоты букв:" << endl;
    for (int i = 0; i < 26; ++i) {
        cout << static_cast<char>('a' + i) << ": " << letterFrequency[i] << endl;
    }
    
    cout << "\nЧастоты двухбуквенных сочетаний:" << endl;
    for (const auto& pair : bigramFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    return 0;
}