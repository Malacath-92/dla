#pragma once

#include <string>
#include <ostream>

namespace dla {
    template<class T>
    std::string to_string(const T& val);

    template<class CharT, class Traits, class T>
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& stream, const T& val);
}

#include "to_string.inl"
