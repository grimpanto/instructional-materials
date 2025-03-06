#include <thread>  // livelock
#include <mutex>
#include <functional>
using namespace std;
//using namespace std::literals;
void enter(mutex& me, mutex& other) {
    bool entered{};
    while (!entered) {
        me.lock();
      // simulate both reaching door simultaneously
        this_thread::sleep_for(500ms);
        if (other.try_lock()) {// should fail often
            me.unlock();   other.unlock();
            entered = true;
        } else me.unlock();  // ...the other first!
        } }

int main() {
    mutex a_enters;
    mutex b_enters;

    thread friend_a{enter,
                    ref(a_enters), ref(b_enters)};
    thread friend_b{enter,
                    ref(b_enters), ref(a_enters)};

    friend_a.join();
    friend_b.join();
}
