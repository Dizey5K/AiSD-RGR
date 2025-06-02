#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <string>

#include "containers/Vector.hpp"

class HashTable {
  struct Node {
    std::string key;
    Vector<int> lines;
    Node* next;

    Node(const std::string& k, int line);
  };

  Vector<Node*> table;
  size_t item_count = 0;

  size_t hash(const std::string& key) const;
  void rehash();

 public:
  HashTable();
  void insert(const std::string& key, int line);
  Vector<int> search(const std::string& key) const;
  void remove(const std::string& key);
  void get_keys(Vector<std::string>& keys) const;
};

#endif