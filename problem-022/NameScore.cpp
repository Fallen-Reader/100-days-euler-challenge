
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<fstream>
using namespace std;

long long getNameValue(const string& name) {
    long long value = 0;
    for (char c : name) {
        if (c >= 'A' && c <= 'Z') {
            value += (c - 'A' + 1);
        }
    }
    return value;
}

string remove_quotes(string& s) {
    s.erase(remove(s.begin(), s.end(), '\"'), s.end());
    return s;
}
int main(){
    ifstream file("0022_names.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }

    string line;
    vector<string> names;
    
    while(getline(file,line)){
        string cleaned = remove_quotes(line);
        names.push_back(cleaned);
    }

    stringstream idk(names[0]);
    names.clear();

    while(getline(idk,line,',')){
        names.push_back(line);
    }

    sort(names.begin(),names.end());

    file.close();

    long long total = 0;
    for (size_t i = 0; i < names.size(); ++i) {
        int value = getNameValue(names[i]);
        long long position = i + 1; 
        total += position * value;
    }
    cout << "Total of all name scores: " << total << "\n";
    return 0;
}