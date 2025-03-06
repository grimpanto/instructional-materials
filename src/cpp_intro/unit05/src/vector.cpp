#include <iostream>  // vector.cpp
#include <vector>
using namespace std;
int main() {  vector<int> v{1, 2};
    cout << "size: " << v.size() << " cap: "
         << v.capacity() << endl;
    v.push_back(3); cout << "added 3 → size: "
      << v.size() << " cap: "<<v.capacity()<<endl;
    v.push_back(4); v.push_back(5);
    cout << "added 3, 4 → size: " << v.size()
         << " cap: " << v.capacity() << endl;
}
