#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers(3);
    for(int i = 0; i < 446; i++)
    numbers.push_back(40);
    for(int i = 0; i < 5; i++)
    numbers.pop_back();
    cout<<numbers.begin()<<endl;
    // cout<<numbers.capacity()<<endl;
    return 0;
}
