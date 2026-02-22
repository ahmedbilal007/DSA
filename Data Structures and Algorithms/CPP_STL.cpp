#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;
int main(){
    vector<int> vec = {1,2,3,4};
    vector<int>::iterator it;               // Vector iterators --> same like simple loop iterators
    // for (it=vec.begin(); it!=vec.end(); it++)
        // cout << *(it) << " ";
    // cout << endl;

    // for (auto it = vec.rbegin(); it!=vec.rend(); it++)
        // cout << *(it) << " ";
    // cout << endl;

    list<int> l;
    l.push_back(1);              // adds item at the end
    l.push_front(2);              // adds item at the start
    l.push_back(3);              
    l.push_front(4);
    for (int v : l)
        cout << v << " ";
    cout << endl;

    l.pop_back();                // removes item from the end
    l.pop_front();               // removes item from the start
    for (int v : l)
        cout << v << " ";
    cout << endl;


    return 0;
}