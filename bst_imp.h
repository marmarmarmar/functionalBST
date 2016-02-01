#ifndef __BST_IMP_H__

#define __BST_IMP_H__

#include "bst.h"
#include <algorithm>
#include <functional>

template<typename T>
BST<T>::BST(T root_value, BST<T> left_child, BST<T> right_child) :
  m_root(std::make_shared<BST::Node>(root_value,
        left_child.m_root,
        right_child.m_root)) {};

template<typename T>
BST<T>::BST(std::initializer_list<T> list) :
  BST<T>(list.begin(), list.end()) {
}

template <typename T, typename Iter>
BST<T> create_from_iter(
    BST<T>&& acc,
    Iter start, 
    Iter end) {

  if (start == end) 

   return acc;

  else {

    Iter temp = start++;

    return create_from_iter(std::move(*temp + acc), start, end);
  }
} 

template <typename T>
template <typename Iter>
BST<T>::BST(Iter start, Iter end) :
BST<T>(create_from_iter(BST<T>(), start, end)) {}
  
template <typename T>
BST<T> BST<T>::left() const {

  if (empty()) {

    throw std::logic_error("Left invoked on empty tree.");

  }

  return BST<T>(m_root->m_left);
}

template <typename T>
BST<T> BST<T>::right() const {

  if (empty()) {

    throw std::logic_error("Left invoked on empty tree.");

  }

  return BST<T>(m_root->m_right);
}

template <typename T>
T const & BST<T>::value() const {

  if (empty()) {

    throw std::logic_error("Value invoked on empty tree.");

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

   throw std::logic_error("min function evaluated on empty tree.");

  } else if (m_root->m_left == nullptr) {

    return m_root->m_value;

  } else

    return BST<T>(m_root->m_left).min();
}

template <typename T>
T const & BST<T>::max() const {

  if (m_root == nullptr) {

   throw std::logic_error("max function evaluated on empty tree.");

  } else if (m_root->m_right == nullptr) {

    return m_root->m_value;

  } else

    return BST<T>(m_root->m_right).max();
}

template <typename T>
template <typename Acc, typename Functor>
Acc BST<T>::fold(Acc acc, Functor f) const { 

  return empty() ?

    acc :

    right().fold(f(left().fold(acc, f), value()), f);
}

template <typename T, typename Acc, typename Functor>
Acc reversed_fold(BST<T> tree_arg, Acc acc, Functor f) { 

  return tree_arg.empty() ?

    acc :

    reversed_fold(tree_arg.left(), f(reversed_fold(tree_arg.right(), acc, f), tree_arg.value()), f);
}

template <typename T>
BST<T> BST<T>::find(T const & arg) const {

  return empty() ? 

    BST<T>() :

    value() == arg ?

    BST<T>(*this) :

    (value() > arg) ?

    left().find(arg) :

    right().find(arg);
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

  auto lambda_functor_for_spine = 
    [] (BST<T> tree_arg, T value) {

      return tree_arg + value;

      };

  return reversed_fold(tree_arg, BST<T>(), lambda_functor_for_spine);
}

template <typename T>
BST<T> operator+(T arg, BST<T> tree_arg){ 

  return tree_arg.empty() ? 

    BST<T>(arg, BST<T>(), BST<T>()) :

    (tree_arg.value() < arg ? 

    BST<T>(tree_arg.value(), tree_arg.left(), tree_arg.right() + arg) :

    BST<T>(tree_arg.value(), tree_arg.left() + arg, tree_arg.right()));
}

template <typename T>
BST<T> operator+(BST<T> tree_arg, T arg){ 

  return arg + tree_arg;
}

template <typename T>
std::ostream & operator<<(std::ostream & os_arg, BST<T> tree_arg) {

  auto lambda_functor_for_ostream =
    [&os_arg] (int no_matter, T value) {

    os_arg << value << " ";

    return no_matter;

  };

  tree_arg.fold(0, lambda_functor_for_ostream);

  return os_arg;
} 


template <typename T>
T max_diff(BST<T> tree_arg) {

  if (tree_arg.size() < 2) 

    throw std::logic_error("max_diff invoked from empty tree_arg.");

  bool if_first = true;

  auto lambda_functor_for_max_diff = [&tree_arg, &if_first]
    (std::pair<T, T> acc, T arg) {

      if (if_first) {

        if_first = false;

        return std::pair<T, T> (arg, arg - arg);

      }

    return (arg - acc.first > acc.second) ?
      std::pair<T, T> (arg, arg - acc.first) :
      std::pair<T, T> (arg, acc.second);

  };

  return tree_arg.fold(std::pair<T, T>(
        tree_arg.value() - tree_arg.value(), 
        tree_arg.value() - tree_arg.value()), 
      lambda_functor_for_max_diff).second;
}

#endif /*__BST_IMP.H__*/
