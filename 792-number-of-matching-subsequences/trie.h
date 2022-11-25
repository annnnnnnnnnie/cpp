#ifndef __TRIE_H__
#define __TRIE_H__

#include <array>
#include <string>
class Trie;

class Trie {
  /**
   * Trie with a marker
   */
private:
  static constexpr std::size_t N_ALPHA{26};
  std::array<Trie, N_ALPHA> next;

public:
  Trie() {}
  ~Trie() {}

  /**
   * Insert into the trie.
   * Return false when it can already be concluded that the assertion would
   * fail.
   */
  bool insert_and_assert_ok(std::string_view s);

  /**
   * Mark that assertion on s would fail. This method is used when
   * insert_and_assert_ok returns true and the actual assertion is found out to
   * fail.
   */
  void mark_failed(std::string_view s);
};

#endif //__TRIE_H__