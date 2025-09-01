#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <mutex>
#include <initializer_list>
#include <utility>
#include <memory>

namespace nanoka {
    std::pair<int, int> min(int a, int b);
    std::pair<int, int> max(int a, int b);
}

#endif