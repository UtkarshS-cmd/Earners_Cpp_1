#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    pair<int,pair<int,int>> p = {1,{1,2}};
    cout<<p.first<<endl; //9
    cout<<p.second.first<<endl; //5
    cout<<p.second.first<<endl; //7
    
    // 1. Declaration and Initialization
    pair<int, int> p1;
    p1 = {10, 20};

    pair<int, string> p2 = {1, "Utkarsh"};

    cout << "Pair 1: " << p1.first << " " << p1.second << endl;
    cout << "Pair 2: " << p2.first << " " << p2.second << endl;


    // 2. Accessing Elements
    cout << "\nFirst Element: " << p1.first << endl;
    cout << "Second Element: " << p1.second << endl;


    // 3. Modifying Elements
    p1.first = 100;
    p1.second = 200;

    cout << "\nModified Pair: " << p1.first << " " << p1.second << endl;


    // 4. Using make_pair()
    pair<int, string> p3 = make_pair(2, "Computer");

    cout << "\nUsing make_pair: " << p3.first << " " << p3.second << endl;


    // 5. Nested Pair
    pair<int, pair<int, int>> p4 = {1, {20, 30}};

    cout << "\nNested Pair: ";
    cout << p4.first << " " << p4.second.first << " " << p4.second.second << endl;


    // 6. Comparing Pairs
    pair<int, int> a = {10, 20};
    pair<int, int> b = {10, 30};

    if (a < b)
        cout << "\nA is smaller than B" << endl;
    else
        cout << "\nA is not smaller than B" << endl;


    // 7. Swapping Pairs
    pair<int, int> x = {5, 10};
    pair<int, int> y = {15, 20};

    swap(x, y);

    cout << "\nAfter Swapping:" << endl;
    cout << "X: " << x.first << " " << x.second << endl;
    cout << "Y: " << y.first << " " << y.second << endl;


    // 8. Pair inside Vector
    vector<pair<int, int>> v;

    v.push_back({1, 100});
    v.push_back({2, 200});
    v.push_back({3, 300});

    cout << "\nVector of Pairs:" << endl;

    for (auto i : v) {
        cout << i.first << " " << i.second << endl;
    }


    // 9. Sorting Vector of Pairs
    vector<pair<int, int>> arr = {
        {3, 30},
        {1, 10},
        {2, 20},
        {1, 5}
    };

    sort(arr.begin(), arr.end());

    cout << "\nSorted Pairs:" << endl;

    for (auto i : arr) {
        cout << i.first << " " << i.second << endl;
    }


    // 10. Using tie() to Unpack Pair
    pair<int, int> p5 = {50, 60};

    int first, second;

    tie(first, second) = p5;

    cout << "\nUsing tie(): " << first << " " << second << endl;


    return 0;
}
