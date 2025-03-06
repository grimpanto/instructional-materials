#ifndef PERSON_H
#define PERSON_H

struct Person {  // inline_variables.h
  public:
    int id{};
    // cancels ODR (one definition rule)
    static inline int next_id{};
    // without inline -> explicit definition
    //                   in person.cpp necessary!
    Person() : id{next_id++} {}
};

inline Person root;
#endif
