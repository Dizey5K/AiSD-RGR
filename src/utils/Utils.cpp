#include "../include/utils/Utils.hpp"

std::string process_word(const std::string &word) {
  if (word.empty())
    return "";

  // Находим первую букву
  size_t start = 0;
  while (start < word.size() && !my_isalpha(word[start]) &&
         is_allowed_punctuation(word[start])) {
    start++;
  }

  // Если не нашли ни одной буквы - невалидное слово
  if (start >= word.size() || !my_isalpha(word[start])) {
    return "";
  }

  // Находим последнюю букву
  size_t end = word.size() - 1;
  while (end > start && !my_isalpha(word[end]) &&
         is_allowed_punctuation(word[end])) {
    end--;
  }

  // Извлекаем ядро слова (от первой до последней буквы)
  std::string core = word.substr(start, end - start + 1);

  // Проверяем, что все символы в ядре - буквы или допустимые пунктуации
  for (char c : core) {
    if (!my_isalpha(c) && !is_allowed_punctuation(c)) {
      return "";
    }
  }

  // Удаляем пунктуацию с границ
  size_t core_start = 0;
  size_t core_end = core.size() - 1;

  while (core_start < core.size() && is_allowed_punctuation(core[core_start])) {
    core_start++;
  }

  while (core_end > core_start && is_allowed_punctuation(core[core_end])) {
    core_end--;
  }

  std::string cleaned = core.substr(core_start, core_end - core_start + 1);

  // Приводим к нижнему регистру
  for (char &c : cleaned) {
    c = my_tolower(c);
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