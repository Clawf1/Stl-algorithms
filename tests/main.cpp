#include <algorithms/algorithms.h>

int main () {
    auto a = xrange(1, 13, 1);
    for (auto i: a) {
        std::cout << i << ' ';
    }
}