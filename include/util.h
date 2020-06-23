#ifndef VERBOSE
    #define LOG(x) ;
#else
    #include <chrono>
    #include <iostream>
    #define LOG(x) cout << (uint64_t) std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << ": " << x << endl
#endif