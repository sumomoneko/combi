// cmdline
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#include "cmdline.h"
#pragma GCC diagnostic pop

#include <iostream>

int main(int argc, char** argv) {
    /*
      引数パース処理
      (´･_･`) https://github.com/tanakh/cmdline
    */
    cmdline::parser a;

    // Run parser.
    a.parse_check(argc, argv);

    if (a.rest().size() != 1) {
        std::cerr << a.usage();
        exit(0);
    }

    const auto P = stoi(a.rest()[0]);

    if (P  >= 144) {
        std::cout << "all max." << std::endl;
        exit(1);
    }

    const int vv[] = {36, 28, 21, 15, 10, 6, 3, 1, 0};
    const int lv[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    for (auto i = 0; i < 9; ++i) {
        for (auto j = i; j < 9; ++j) {
            for (auto k = j; k < 9; ++k) {
                for (auto l = k; l < 9; ++l) {
                    const auto sum = vv[i] + vv[j] + vv[k] + vv[l];
                    if (sum <= P && P - sum < 9) {
                        std::cout << lv[i] << " " << lv[j] << " " << lv[k]
                                  << " " << lv[l] << " rem: " << P - sum
                                  << std::endl;
                    }
                }
            }
        }
    }
}
