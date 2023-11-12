#ifndef SIMPLE_STREAM_TIMER_H
#define SIMPLE_STREAM_TIMER_H

#include <iostream>
#include <chrono>

namespace {
    using namespace std::chrono;

    struct Counter final {
        system_clock::time_point start = system_clock::now();
        bool newLine = true;

        template<typename T> requires (!std::is_same_v<T, Counter& (&)(Counter&)>)
        Counter &operator<<(const T &msg) noexcept {
            if (newLine) {
                std::cout << '[' << duration_cast<milliseconds>(system_clock::now() - start).count() << " ms] ";
                newLine = false;
            }
            std::cout << msg; return *this;
        }

        Counter &operator<<(Counter &(&modifier)(Counter &)) noexcept {
            return modifier(*this); }
    };
}

namespace Timer {
    inline Counter out;
    Counter& init() noexcept {
        Timer::out = Counter(); return out; }
    Counter& endl(Counter& counter) noexcept {
        counter.newLine = true; std::cout << std::endl; return counter; }
}

#endif //SIMPLE_STREAM_TIMER_H
