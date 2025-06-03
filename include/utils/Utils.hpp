#ifndef UTILS
#define UTILS

#include "containers/Vector.hpp"
#include <string>

inline bool my_isalpha(char c) {
  unsigned char uc = static_cast<unsigned char>(c);
  return (uc >= 'A' && uc <= 'Z') || (uc >= 'a' && uc <= 'z');
}

inline bool my_isspace(char c) {
  unsigned char uc = static_cast<unsigned char>(c);
  return uc == ' ' || uc == '\t' || uc == '\r' || uc == '\n' || uc == '\0' ||
         uc == '\x01';
}

inline char my_tolower(char c) {
  unsigned char uc = static_cast<unsigned char>(c);
  if (uc >= 'A' && uc <= 'Z') {
    return static_cast<char>(uc + ('a' - 'A'));
  }
  return c;
}

template <typename T> inline void my_swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

std::string process_word(const std::string &word);
void case_insensitive_sort(Vector<std::string> &keys);
Vector<std::string> split_into_words(const std::string &line);

#endif