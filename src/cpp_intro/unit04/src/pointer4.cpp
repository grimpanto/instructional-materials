int main() { // pointer4.cpp
    char mini[]{"x"}; char* p{mini};
    char s[]{"Maxi"};

    const char* pc{s};  // pointer to const char
    // pc[0] = 'm';  // error
    pc = p;  // ok

    char* const cp{s};  // constant pointer
    cp[0] = 'm';
    // cp = p;  // error

    const char* const cpc{s};
    // cpc[0] = 'm';  // error
    // cpc = p;  // error
}
