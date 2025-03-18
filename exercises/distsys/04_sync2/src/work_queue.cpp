// @copyright 2019 Günter Kolousek

#include "work_queue.h"

using namespace std;

void WorkQueue::push(WorkPacket packet) {
    unique_lock<mutex> lck{m};
    not_full.wait(lck, [this] { return q.size() < size; });
    q.push(packet);
    not_empty.notify_one();
}


WorkPacket WorkQueue::pop() {
    unique_lock<mutex> lck{m};
    not_empty.wait(lck, [this] { return q.size(); });
    WorkPacket p{q.front()};
    q.pop();
    not_full.notify_one();
    return p;
}
