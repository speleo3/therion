#pragma once

namespace therion {

/**
 * An immutable forward linked list which doesn't have ownership of its tail.
 *
 * - Prepend in O(1)
 * - No heap memory allocations
 *
 * Inspired by scala.collection.immutable.List
 */
template <typename T>
class borrowing_list {
  borrowing_list const * m_tail = nullptr;
  T m_value = {};

  borrowing_list(borrowing_list const * tail, T const & value) //
      : m_tail(tail), m_value(value) {};

public:
  borrowing_list() = default;

  /**
   * Tests whether this list contains a given value as an element.
   */
  [[nodiscard]] bool contains(T const & value) const {
    for (auto item = this; item->m_tail; item = item->m_tail) {
      if (item->m_value == value)
        return true;
    }
    return false;
  }

  /**
   * A copy of the list with an element prepended.
   */
  [[nodiscard]] borrowing_list prepended(T const & value) const {
    return borrowing_list(this, value);
  }
};

} // namespace therion
