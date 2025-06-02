#include "../include/Utils.hpp"

std::string process_word(const std::string &word) {
  std::string cleaned;
  for (char c : word) {
    if (isAlpha(c)) {
      cleaned += toLower(c);
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
        a[k] = toLower(a[k]);
      for (size_t k = 0; k < b.size(); ++k)
        b[k] = toLower(b[k]);
      if (a > b) {
        Swap(keys[i], keys[j]);
      }
    }
  }
}

Vector<std::string> split_into_words(const std::string &line) {
  Vector<std::string> words;
  size_t pos = 0;
  while (pos < line.size()) {
    // Пропуск пробельных символов
    while (pos < line.size() && isSpace(line[pos])) {
      ++pos;
    }
    if (pos >= line.size())
      break;

    // Извлечение слова
    size_t start = pos;
    while (pos < line.size() && !isSpace(line[pos])) {
      ++pos;
    }
    words.push_back(line.substr(start, pos - start));
  }
  return words;
}

std::string clean_line(const std::string &line) {
  std::string cleaned;
  bool in_escape = false;

  for (char c : line) {
    unsigned char uc = static_cast<unsigned char>(c);

    if (uc == 27) {
      in_escape = true;
      continue;
    }

    if (in_escape) {
      if (uc == 'm') {
        in_escape = false;
      }
      continue;
    }

    if (isAlpha(c) || uc == ' ') {
      cleaned += c;
    }
  }
  return cleaned;
}