// @copyright 2019 Günter Kolousek

#pragma once

//#ifndef WORK_PACKET_H
//#define WORK_PACKET_H

class WorkPacket {
    const int id{};
  public:
    WorkPacket(int id_) : id{id_} {}
    int get_id() const { return id; }
};
// #endif
