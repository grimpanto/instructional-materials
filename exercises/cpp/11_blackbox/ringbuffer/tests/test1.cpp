
#include "ringbuffer.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

TEST_CASE("size of buffer") {
    Ringbuffer<double, 5> buffer;

    CHECK(buffer.size() == 0);
    buffer.put(1.0);
    CHECK(buffer.size() == 1);
    buffer.put(2.0);
    CHECK(buffer.size() == 2);
    buffer.put(3.0);
    CHECK(buffer.size() == 3);
    buffer.put(4.0);
    CHECK(buffer.size() == 4);
    buffer.put(5.0);
    CHECK(buffer.size() == 5);
    buffer.put(6.0);
    CHECK(buffer.size() == 5);
}

TEST_CASE("write and read") {
    Ringbuffer<double, 5> buffer;

    buffer.put(1.0);
    CHECK(buffer.get() == 1.0);
    buffer.put(1.0);
    buffer.put(2.0);
    buffer.put(3.0);
    CHECK(buffer.get() == 1.0);
    CHECK(buffer.get() == 2.0);
    CHECK(buffer.get() == 3.0);
}

TEST_CASE("read from empty buffer") {
    Ringbuffer<double, 5> buffer;

    CHECK(buffer.get().has_value() == false);
    buffer.put(1.0);
    buffer.put(2.0);
    buffer.get();
    buffer.get();
    CHECK(buffer.get().has_value() == false);
}

TEST_CASE("read and write overrunning buffer size") {
    Ringbuffer<double, 5> buffer;
    
    buffer.put(1.0);
    buffer.put(2.0);
    buffer.put(3.0);
    buffer.put(4.0);
    buffer.put(5.0);
    CHECK(buffer.get() == 1);
    buffer.put(6.0);
    buffer.put(7.0);
    CHECK(buffer.get() == 3);
    CHECK(buffer.get() == 4);
    CHECK(buffer.get() == 5);
    CHECK(buffer.get() == 6);
    CHECK(buffer.get() == 7);
    CHECK(buffer.size() == 0);
}
