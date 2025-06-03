#include "../include/utils/Utils.hpp"

std::string process_word(const std::string &word) {
  std::string cleaned;
  for (char c : word) {
    if (my_isalpha(c)) {
      cleaned += my_tolower(c);
    }
  }
  return cleaned;
}

void case_insensitive_sort(Vector<std::string> &keys) {
  for (size_t i = 0; i < keys.size(); ++i) {
    for (size_t j = i + 1; j < keys.size(); ++j) {
      std::string a = keys[i];
      std::string b = keys[j];
      for (size_t k = 0; k < a.size(); ++k)
        a[k] = my_tolower(a[k]);
      for (size_t k = 0; k < b.size(); ++k)
        b[k] = my_tolower(b[k]);
      if (a > b) {
        my_swap(keys[i], keys[j]);
      }
    }
  }
}

Vector<std::string> split_into_words(const std::string &line) {
  Vector<std::string> words;
  size_t pos = 0;

  while (pos < line.size()) {
    while (pos < line.size() && my_isspace(line[pos]))
      ++pos;
    if (pos >= line.size())
      break;

    size_t start = pos;
    while (pos < line.size() && !my_isspace(line[pos]))
      ++pos;

    words.push_back(line.substr(start, pos - start));
  }
  return words;
}