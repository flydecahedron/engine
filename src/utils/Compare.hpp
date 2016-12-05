/*
 * Compare.hpp
 *
 *  Created on: Dec 5, 2016
 *      Author: eroc
 */

#ifndef UTILS_COMPARE_HPP_
#define UTILS_COMPARE_HPP_


/**
 * CompareFirst
 * unary predicate returns true if pair.first equals the passed in value.
 *
 * Meant to be used with find_if and a vector of pairs, for more info see:
 * http://stackoverflow.com/questions/12008059/find-if-and-stdpair-but-just-one-element
 */
template <typename K, typename T>
struct CompareFirst
{
  CompareFirst(K key) : m_key(key) {}
  bool operator()(const std::pair<K,T>& element) const {
    return m_key == element.first;
  }
  private:
    K m_key;
};

/**
 * CompareSecond
 * unary predicate returns true if pair.second equals the passed in value.
 *
 * Meant to be used with find_if and a vector of pairs, for more info see:
 * http://stackoverflow.com/questions/12008059/find-if-and-stdpair-but-just-one-element
 */
template <typename K, typename T>
struct CompareSecond
{
  CompareSecond(T t) : m_t(t) {}
  bool operator()(const std::pair<K,T>& element) const {
    return m_t == element.second;
  }
  private:
    T m_t;
};


#endif /* UTILS_COMPARE_HPP_ */
