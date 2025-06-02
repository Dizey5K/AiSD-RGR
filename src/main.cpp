#include <cctype>
#include <iostream>
#include <sstream>

#include "../include/hashtable/HashTable.hpp"

static std::string process_word(const std::string &word) {
  std::string cleaned;
  for (char c : word) {
    if (std::isalpha(static_cast<unsigned char>(c))) {
      cleaned += static_cast<char>(std::tolower(c));
    }
  }
  return cleaned;
}

static void case_insensitive_sort(Vector<std::string> &keys) {
  for (size_t i = 0; i < keys.size(); ++i) {
    for (size_t j = i + 1; j < keys.size(); ++j) {
      std::string a = keys[i];
      std::string b = keys[j];
      for (auto &ch : a)
        ch = std::tolower(ch);
      for (auto &ch : b)
        ch = std::tolower(ch);
      if (a > b) {
        std::swap(keys[i], keys[j]);
      }
    }
  }
}

int main() {
  HashTable cross_ref;
  Vector<std::string> input_lines;
  std::string line;
  int line_num = 0;

  while (std::getline(std::cin, line)) {
    ++line_num;
    input_lines.push_back(line);

    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
      std::string processed = process_word(word);
      if (!processed.empty()) {
        cross_ref.insert(processed, line_num);
      }
    }
  }

  for (size_t i = 0; i < input_lines.size(); ++i) {
    std::cout << (i + 1) << ": " << input_lines[i] << "\n";
  }

  Vector<std::string> keys;
  cross_ref.get_keys(keys);
  case_insensitive_sort(keys);

  std::cout << "\nCross references:\n";
  for (size_t i = 0; i < keys.size(); ++i) {
    std::cout << keys[i] << ": ";
    const Vector<int> &lines = cross_ref.search(keys[i]);
    for (size_t j = 0; j < lines.size(); ++j) {
      if (j > 0)
        std::cout << ", ";
      std::cout << lines[j];
    }
    std::cout << "\n";
  }
  return 0;
}