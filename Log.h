#pragma once
#include <iostream>
#include <sstream>

#define LOG() \
    ([&]() { \
        std::ostringstream oss; \
        oss << __FILE__ << ":" << __LINE__ << " (" << __func__ << "): "; \
        return oss.str(); \
    }())
