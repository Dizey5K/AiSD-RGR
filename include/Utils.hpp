#ifndef UTILS
#define UTILS

#include "containers/Vector.hpp"
#include <string>

inline bool isAlpha(char c) {
  unsigned char uc = static_cast<unsigned char>(c);
  return (uc >= 'A' && uc <= 'Z') || (uc >= 'a' && uc <= 'z');
}

inline bool isSpace(char c) {
  unsigned char uc = static_cast<unsigned char>(c);
  return uc == ' ' || uc == '\t' || uc == '\r' || uc == '\n' || uc == '\0';
}

inline char toLower(char c) {
  unsigned char uc = static_cast<unsigned char>(c);
  if (uc >= 'A' && uc <= 'Z') {
    return static_cast<char>(uc + ('a' - 'A'));
  }
  return c;
}

template <typename T> inline void Swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

std::string process_word(const std::string &word);

void case_insensitive_sort(Vector<std::string> &keys);

Vector<std::string> split_into_words(const std::string &line);

std::string clean_line(const std::string &line);

#endif