#include <iostream>
#include <vector>
#include <string>    
#include <algorithm> 

using namespace std;

int main() {
    vector<string> logs = {
        "dig1 8 1 5 1", 
        "let1 art can", 
        "dig2 3 6", 
        "let2 own kit dig", 
        "let3 art zero"
    };

    
    sort(logs.begin(), logs.end());

    for (const string& l : logs) {
        cout << l << endl;
    }

    return 0;
}
