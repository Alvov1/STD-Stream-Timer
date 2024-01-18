# STD::Stream Timer
A simple header-only C++ library for counting time elapsed since the beginning of the program while writing information in std::cout

#### Usage example:
```cpp
Timer::init() << "Hello, World!" << Timer::endl;
std::this_thread::sleep_for(std::chrono::milliseconds(2500));
Timer::out << "We were here in 2.5 seconds." << Timer::endl;
std::this_thread::sleep_for(std::chrono::milliseconds(750));
Timer::out << "And then another 0.75 seconds passed." << Timer::endl;
```

#### Output:
> [0 ms] Hello, World!
> 
> [2502 ms] Were here after 2,5 seconds.
>
> [3257 ms] And here we are after 0,75 seconds more.


#### Usage with CMake:
```cmake
include(FetchContent)
FetchContent_Declare(STDStreamTimer
        GIT_REPOSITORY https://github.com/Alvov1/STD-Stream-Timer.git
        GIT_TAG main
)
FetchContent_MakeAvailable(STDStreamTimer)

target_include_directories(Target PRIVATE ${STDStreamTimer_SOURCE_DIR})
```

