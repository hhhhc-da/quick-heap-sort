#include <base.hpp>

using namespace std;

namespace nanoka{
    pair<int, int> min(int a, int b){
        return {((a < b) ? 0 : 1), ((a < b) ? a : b)};
    }

    pair<int, int> max(int a, int b){
        return {((a > b) ? 0 : 1), ((a > b) ? a : b)};
    }
}