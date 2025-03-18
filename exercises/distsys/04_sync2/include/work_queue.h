// @copyright 2019 Günter Kolousek

#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

#include "work_packet.h"

class WorkQueue {
    std::queue<WorkPacket> q;
    std::mutex m;
    std::condition_variable not_empty;
    std::condition_variable not_full;
    size_t size;
  public:
    WorkQueue(size_t size_) : size{size_} {}
    void push(WorkPacket);
    WorkPacket pop();
};
