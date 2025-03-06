#include <iostream>
#include <string>
#include <asio.hpp>

using asio::ip::tcp;
using namespace std;

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            cerr << "Usage: daytime_client <host>" << endl;
            return 1;
        }

        tcp::iostream s(argv[1], "10013");  // also: "daytime" -> 13
        if (!s) {
            cout << "Unable to connect: " << s.error().message() << endl;
            return 1;
        }

        string line;
        getline(s, line);
        cout << line << endl;
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}
