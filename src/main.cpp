#include <iostream>
#include <string>

#include "../include/Utils.hpp"
#include "../include/hashtable/HashTable.hpp"

int main() {
  HashTable cross_ref;
  Vector<std::string> input_lines;
  Vector<std::string> cleaned_lines;
  std::string line;
  int line_num = 0;

  while (std::getline(std::cin, line)) {
    ++line_num;
    input_lines.push_back(line);
    cleaned_lines.push_back(clean_line(line));

    Vector<std::string> words = split_into_words(line);
    for (const std::string &word : words) {
      std::string processed = process_word(word);
      if (!processed.empty()) {
        cross_ref.insert(processed, line_num);
      }
    }
  }

  for (size_t i = 0; i < cleaned_lines.size(); ++i) {
    std::cout << (i + 1) << ": " << cleaned_lines[i] << "\n";
  }

  Vector<std::string> keys;
  cross_ref.get_keys(keys);
  case_insensitive_sort(keys);

  std::cout << "\nCross references:\n";
  for (size_t i = 0; i < keys.size(); ++i) {
    std::cout << keys[i] << ": ";
    Vector<int> lines = cross_ref.search(keys[i]);
    for (size_t j = 0; j < lines.size(); ++j) {
      if (j > 0)
        std::cout << ", ";
      std::cout << lines[j];
    }
    std::cout << "\n";
  }

  return 0;
}