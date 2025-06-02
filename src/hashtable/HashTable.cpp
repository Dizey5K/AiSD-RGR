#include "../include/hashtable/HashTable.hpp"

HashTable::Node::Node(const std::string &k, int line) : key(k), next(nullptr) {
  lines.push_back(line);
}

HashTable::HashTable() : table(101, nullptr) {}

size_t HashTable::hash(const std::string &key) const {
  size_t hash = 5381;
  for (char c : key)
    hash = (hash << 5) + hash + static_cast<unsigned char>(c);
  return hash % table.size();
}

void HashTable::rehash() {
  size_t new_size = table.size() * 2;
  Vector<Node *> new_table(new_size, nullptr);

  for (size_t i = 0; i < table.size(); ++i) {
    Node *current = table[i];
    while (current) {
      Node *next_node = current->next;
      size_t new_idx = hash(current->key) % new_size;
      current->next = new_table[new_idx];
      new_table[new_idx] = current;
      current = next_node;
    }
  }

  table = new_table;
}

void HashTable::insert(const std::string &key, int line) {
  if (item_count > table.size() * 0.75)
    rehash();

  size_t idx = hash(key);
  Node *current = table[idx];

  while (current) {
    if (current->key == key) {
      if (current->lines.empty() || current->lines.back() != line)
        current->lines.push_back(line);
      return;
    }
    current = current->next;
  }

  Node *new_node = new Node(key, line);
  new_node->next = table[idx];
  table[idx] = new_node;
  ++item_count;
}

void HashTable::remove(const std::string &key) {
  if (key.empty())
    throw std::invalid_argument("Key cannot be empty");

  size_t idx = hash(key);
  Node *current = table[idx];
  Node *prev = nullptr;

  while (current) {
    if (current->key == key) {
      if (prev) {
        prev->next = current->next;
      } else {
        table[idx] = current->next;
      }
      delete current;
      item_count--;
      return;
    }
    prev = current;
    current = current->next;
  }
  throw std::runtime_error("Key not found");
}

Vector<int> HashTable::search(const std::string &key) const {
  size_t idx = hash(key);
  Node *current = table[idx];

  while (current) {
    if (current->key == key)
      return current->lines;
    current = current->next;
  }
  return Vector<int>();
}

void HashTable::get_keys(Vector<std::string> &keys) const {
  keys.clear();
  for (size_t i = 0; i < table.size(); ++i) {
    Node *current = table[i];
    while (current) {
      keys.push_back(current->key);
      current = current->next;
    }
  }
}