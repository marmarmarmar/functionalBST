#ifndef __BST_IMP_H__

#define __BST_IMP_H__

#include "bst.h"
#include <algorithm>
#include <functional>
#include <iostream>

template<typename T>
BST<T>::BST(T value, BST<T> left, BST<T> right) :
  m_root(std::make_shared<BST::Node>(value,
        left.m_root,
        right.m_root)) {};

template<typename T>
BST<T>::BST(std::initializer_list<T> list) :
  BST<T>(list.begin(), list.end()) {
}

template <typename T, typename Iter>
BST<T> accumulate_bst(BST<T>&& acc, Iter start, 
    Iter end) {
  if (start == end) 
   return acc;
  else {
    Iter temp = start++;
    return accumulate_bst(std::move(*temp + acc), start, end);
  }
} 

template <typename T>
template <typename Iter>
BST<T>::BST(Iter start, Iter end) :
BST<T>(accumulate_bst(BST<T>(), start, end)) {}
  
template <typename T>
BST<T> BST<T>::left() const {
  if (empty()) {
    std::logic_error log_err("Left invoked on empty tree.");
    throw log_err;
  }
  return BST<T>(m_root->m_left);
}

template <typename T>
BST<T> BST<T>::right() const {
  if (empty()) {
    std::logic_error log_err("Left invoked on empty tree.");
    throw log_err;
  }
  return BST<T>(m_root->m_right);
}

template <typename T>
T const & BST<T>::value() const {
  if (empty()) {
    std::logic_error log_err("Value invoked on empty tree.");
    throw log_err;
  }
  return m_root->m_value;
}

template <typename T>
bool BST<T>::empty() const {
  return m_root == nullptr;
}

template <typename T>
T const & BST<T>::min() const {
  if (m_root == nullptr) {
   std::logic_error log_err("min function evaluated on empty tree.");
   throw log_err; 
  } else if (m_root->m_left == nullptr) {
    return m_root->m_value;
  } else
    return BST<T>(m_root->m_left).min();
}

template <typename T>
T const & BST<T>::max() const {
  if (m_root == nullptr) {
   std::logic_error log_err("max function evaluated on empty tree.");
   throw log_err; 
  } else if (m_root->m_right == nullptr) {
    return m_root->m_value;
  } else
    return BST<T>(m_root->m_right).max();
}

template <typename T>
template <typename Acc, typename Functor>
Acc BST<T>::fold(Acc a, Functor f) const { 
  return empty() ?
    a :
    right().fold(f(left().fold(a, f), value()), f);
}

template <typename T>
BST<T> BST<T>::find(T const & t) const {
  return empty() ? 
    BST<T>() :
    value() == t ?
    BST<T>(*this) :
    (value() > t) ?
    left().find(t) :
    right().find(t);
}

template <typename T>
std::size_t BST<T>::size() const { 
  
  auto lambda_for_size = [] (int acc, T value) {

    return acc + 1;
  };

  return fold(0, lambda_for_size);
}

template <typename T>
std::size_t BST<T>::height() const { 

  return empty() ?
    0 :
    std::max(left().height(), right().height()) + 1;

}

template <typename T>
BST<T> spine(BST<T> tree_arg){
  
  return tree_arg.fold(BST<T>(), [] (BST<T> tree_arg, T value) {
      return tree_arg + value;
      });

}

template <typename T>
BST<T> operator+(T arg, BST<T> tree){ 

  return tree.empty() ? 
    BST<T>(arg, BST<T>(), BST<T>()) :
    (tree.value() < arg ? 
    BST<T>(tree.value(), tree.left(), tree.right() + arg) :
    BST<T>(tree.value(), tree.left() + arg, tree.right()));

}

template <typename T>
BST<T> operator+(BST<T> tree, T arg){ 

  return arg + tree;

}

template <typename T>
std::ostream & operator<<(std::ostream & os, BST<T> tree) {

  auto lambda_functor_for_ostream = [&os] (int no_matter, T value) {
    os << value << " ";
    return no_matter;
  };

  tree.fold(0, lambda_functor_for_ostream);

  return os;
} 


template <typename T>
T max_diff(BST<T> tree) {

  if (tree.size() < 2) 
    throw std::logic_error("max_diff invoked from empty tree.");

  bool if_first = true;

  auto lambda_functor_for_max_diff = [&tree, &if_first]
    (std::pair<T, T> acc, T arg) {
      if (if_first) {
        if_first = false;
        return std::pair<T, T> (arg, arg - arg);
      }
    return (arg - acc.first > acc.second) ?
      std::pair<T, T> (arg, arg - acc.first) :
      std::pair<T, T> (arg, acc.second);
  };

  return tree.fold(std::pair<T, T>(tree.value() - tree.value(), tree.value() - tree.value()), lambda_functor_for_max_diff).second;
}

#endif /*__BST_IMP.H__*/
