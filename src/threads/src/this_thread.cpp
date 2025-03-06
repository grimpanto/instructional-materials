#include <iostream>  // join2.cpp
#include <thread>
#include <vector>
using namespace std;

int main() {  // join2.cpp
  vector<thread> threads;

  for(int i = 0; i < 5; ++i){
    threads.push_back(std::thread([](){
      cout << "Hello from thread "
           << this_thread::get_id() << endl;
    }));
  }

  for(auto& thread : threads){
    thread.join();
  }
}
