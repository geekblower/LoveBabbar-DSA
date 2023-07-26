#include <bits/stdc++.h>
using namespace std;    

int main() {
    // Creation
    map<string, int> M;

    // Insertion

    // 1
    pair<string, int> pair1 = make_pair("white", 2);
    M.insert(pair1);

    // 2
    pair<string, int> pair2("black", 3);
    M.insert(pair2);

    // 3
    M["red"] = 4;

    // Printing
    cout << "Before updation : white = " << M["white"] << endl;

    // Updation
    M["white"] = 10;    
    cout << "After updation : white = " << M.at("white") << endl;

    // cout << M.at("orange") << endl;
    cout << M["orange"] << endl;

    // Size
    cout << "Size : " << M.size() << endl;

    // Check presence
    cout << M.count("yellow") << endl;
    cout << M.count("white") << endl;

    // Removal
    M.erase("white");
    cout << "Size : " << M.size() << endl;

    // Traversal
    for(auto i : M) {
        cout << i.first << " & " << i.second << endl;
    }

    // Iterator
    /*
    unordered_map<string, int> :: iterator it = M.begin();
    while(it != M.end()) {
        cout << it.first << " , " << it.second << endl;
        it++;
    }
    */
    
    return 0;
}
