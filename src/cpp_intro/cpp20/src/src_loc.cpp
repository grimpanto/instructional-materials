#include <iostream>
#include <experimental/source_location>

using namespace std;
using namespace std::experimental;
using src_loc = source_location;

void log(string message,
  const src_loc& loc=src_loc::current()) {
    cout << "info:" << loc.file_name() << ':'
         << loc.line() << ' ' << message
         << " ... in " << loc.function_name() << "\n";
}
 
int main() {
   cout << src_loc::current().line() << '\n';  // -> 17
   log("Hello world!");
   // -> info:src_loc.cpp:18 Hello world! ... in main
}
