#pragma once


#ifndef SFINAE_TEST
#define SFINAE_TEST


#include <type_traits>
#include <vector>
#include <string>


/*
    SFINAE - substitution failture is not an error 
    (Сбой подстановки не является ошибкой)
*/


int difference (const int& a, const int& b) {
    return a - b;
}

template <class T> typename T::difference_type difference (const T& a, const T& b)
{
    return a - b;
}


// metafunction
template <typename T> struct has_foo {
    static const bool value = true;
};


// SFINAE
void f(int, std::vector<int>) {}
void f(int, int) {}
void f(double, double) {}
void f(int, int, char, std::string, std::vector<int>) {}
void f(std::string) {}
void f(...) {}

template <class T> void f(T, T) {}
template <class T> void f(T, typename T::iterator) {}   // Конкретный пример 


//  std::enable_if - применяется для разрешения перегрузки SFINAE
#endif  // "SFINAE_TEST"