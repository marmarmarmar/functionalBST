#include "bst_imp.h"
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <iostream>

int main() {
  std::cout << "TESTING OF BST.\n" << std::endl;
  BST<int> bst; // Empty one
  std::cout << "1. TESTING EMPTY TREE." << std::endl << std::endl;
  std::cout << "1. bst.size() == 0";
  assert(bst.size() == 0);
  std::cout << " OK.\n";
  std::cout << "1. bst.height == 0";
  assert(bst.height() == 0);
  std::cout << " OK.\n";
  std::cout << "1. spine(bst).size() == 0";
  assert(spine(bst).size() == 0);
  std::cout << " OK.\n";
  std::cout << "1. spine(bst).height() == 0";
  assert(spine(bst).size() == 0);
  std::cout << " OK.\n";
  std::cout << "1. bst.empty() == true";
  assert(bst.empty());
  std::cout << " OK.\n";
  std::cout << "1. bst.find(0).size() == 0";
  assert(bst.find(0).size() == 0);
  std::cout << " OK.\n";

  auto sum = [](int arg1, int arg2) {
    return arg1 + arg2;
  };

  std::cout << "1. bst.fold(0, sum) == 0";
  assert(bst.fold(0, sum) == 0);
  std::cout << " OK.\n";

  try {
    std::cout << "1. bst.min() will throw.";
    bst.min();
    assert(0);
  } catch (...) {
    std::cout << " OK\n";
  }

  try {
    std::cout << "1. bst.max() will throw.";
    bst.min();
    assert(0);
  } catch (...) {
    std::cout << " OK\n";
  }

  try {
    std::cout << "1. bst.left() will throw.";
    bst.left();
    assert(0);
  } catch (...) {
    std::cout << " OK\n";
  }

  try {
    std::cout << "1. bst.right() will throw.";
    bst.right();
    assert(0);
  } catch (...) {
    std::cout << " OK\n";
  }
  
  try {
    std::cout << "1. bst.value() will throw.";
    bst.value();
    assert(0);
  } catch (...) {
    std::cout << " OK\n";
  }

  std::cout << std::endl << "2. TESTING ONE ELEMENT TREE. CONSTRUCTED BY ADDING + 0" << std::endl << std::endl;

  BST<int> bst2 = bst + 0;
  
  std::cout << "2. bst2.size() == 1";
  assert(bst2.size() == 1);
  std::cout << " OK.\n";
  std::cout << "2. bst2.height == 1";
  assert(bst2.height() == 1);
  std::cout << " OK.\n";
  std::cout << "2. spine(bst2).size() == 1";
  assert(spine(bst2).size() == 1);
  std::cout << " OK.\n";
  std::cout << "2. spine(bst2).height() == 1";
  assert(spine(bst2).height() == 1);
  std::cout << " OK.\n";
  std::cout << "2. spine(bst2).value() == 0";
  assert(spine(bst2).value() == 0);
  std::cout << " OK.\n";
  std::cout << "2. bst2.empty() == false";
  assert(!bst2.empty());
  std::cout << " OK.\n";
  std::cout << "2. bst2.find(0).size() == 1";
  assert(bst2.find(0).size() == 1);
  std::cout << " OK.\n";
  std::cout << "2. bst2.find(0).height() == 1";
  assert(bst2.find(0).height() == 1);
  std::cout << " OK.\n";
  std::cout << "2. bst2.find(0).value() == 0";
  assert(bst2.find(0).value() == 0);
  std::cout << " OK.\n";
  std::cout << "2. bst2.min() == 0";
  assert(bst2.min() == 0);
  std::cout << " OK.\n";
  std::cout << "2. bst2.max() == 0";
  assert(bst2.max() == 0);
  std::cout << " OK.\n";
  std::cout << "2. bst2.left().size() == 0";
  assert(bst2.left().size() == 0);
  std::cout << " OK.\n";
  std::cout << "2. bst2.left().height() == 0";
  assert(bst2.left().height() == 0);
  std::cout << " OK.\n";
  std::cout << "2. bst2.right().size() == 0";
  assert(bst2.right().size() == 0);
  std::cout << " OK.\n";
  std::cout << "2. bst2.right().height() == 0";
  assert(bst2.right().height() == 0);
  std::cout << " OK.\n";
  std::cout << "2. bst2.right().empty() == true";
  assert(bst2.right().empty());
  std::cout << " OK.\n";
  std::cout << "2. bst2.left().empty() == true";
  assert(bst2.left().empty());
  std::cout << " OK.\n";

  std::cout << "2. bst2.fold(1, sum) == 1";
  assert(bst2.fold(1, sum) == 1);
  std::cout << " OK.\n";

  try {
    std::cout << "2. bst2.min() will not throw.";
    bst2.min();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {

    BST<int> bst2 = bst + 0;
    std::cout << "2. bst2.max() will not throw.";
    bst2.min();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {
    std::cout << "2. bst2.left() will not throw.";
    bst2.left();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {
    std::cout << "2. bst2.right() will not throw.";
    bst2.right();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }
  
  try {
    std::cout << "2. bst2.value() will not throw.";
    bst2.value();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  std::cout << std::endl << "3. TESTING ONE ELEMENT TREE. CONSTRUCTED BY {0}" << std::endl << std::endl;

  BST<int> bst3({0});
  
  std::cout << "3. bst3.size() == 1";
  assert(bst3.size() == 1);
  std::cout << " OK.\n";
  std::cout << "3. bst3.height == 1";
  assert(bst3.height() == 1);
  std::cout << " OK.\n";
  std::cout << "3. spine(bst3).size() == 1";
  assert(spine(bst3).size() == 1);
  std::cout << " OK.\n";
  std::cout << "3. spine(bst3).height() == 1";
  assert(spine(bst3).height() == 1);
  std::cout << " OK.\n";
  std::cout << "3. spine(bst3).value() == 0";
  assert(spine(bst3).value() == 0);
  std::cout << " OK.\n";
  std::cout << "3. bst3.empty() == false";
  assert(!bst3.empty());
  std::cout << " OK.\n";
  std::cout << "3. bst3.find(0).size() == 1";
  assert(bst3.find(0).size() == 1);
  std::cout << " OK.\n";
  std::cout << "3. bst3.find(0).height() == 1";
  assert(bst3.find(0).height() == 1);
  std::cout << " OK.\n";
  std::cout << "3. bst3.find(0).value() == 0";
  assert(bst3.find(0).value() == 0);
  std::cout << " OK.\n";
  std::cout << "3. bst3.min() == 0";
  assert(bst3.min() == 0);
  std::cout << " OK.\n";
  std::cout << "3. bst3.max() == 0";
  assert(bst3.max() == 0);
  std::cout << " OK.\n";
  std::cout << "3. bst3.left().size() == 0";
  assert(bst3.left().size() == 0);
  std::cout << " OK.\n";
  std::cout << "3. bst3.left().height() == 0";
  assert(bst3.left().height() == 0);
  std::cout << " OK.\n";
  std::cout << "3. bst3.right().size() == 0";
  assert(bst3.right().size() == 0);
  std::cout << " OK.\n";
  std::cout << "3. bst3.right().height() == 0";
  assert(bst3.right().height() == 0);
  std::cout << " OK.\n";
  std::cout << "3. bst3.right().empty() == true";
  assert(bst3.right().empty());
  std::cout << " OK.\n";
  std::cout << "3. bst3.left().empty() == true";
  assert(bst3.left().empty());
  std::cout << " OK.\n";

  std::cout << "3. bst3.fold(1, sum) == 1";
  assert(bst3.fold(1, sum) == 1);
  std::cout << " OK.\n";

  try {
    std::cout << "3. bst3.min() will not throw.";
    bst3.min();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {

    BST<int> bst3 = bst + 0;
    std::cout << "3. bst3.max() will not throw.";
    bst3.min();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {
    std::cout << "3. bst3.left() will not throw.";
    bst3.left();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {
    std::cout << "3. bst3.right() will not throw.";
    bst3.right();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }
  
  try {
    std::cout << "3. bst3.value() will not throw.";
    bst3.value();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  std::cout << std::endl << "4. TESTING ONE ELEMENT TREE. CONSTRUCTED BY ITER" << std::endl << std::endl;

  std::vector<int> vec = {0};
  BST<int> bst4(vec.begin(), vec.end());
  
  std::cout << "4. bst4.size() == 1";
  assert(bst4.size() == 1);
  std::cout << " OK.\n";
  std::cout << "4. bst4.height == 1";
  assert(bst4.height() == 1);
  std::cout << " OK.\n";
  std::cout << "4. spine(bst4).size() == 1";
  assert(spine(bst4).size() == 1);
  std::cout << " OK.\n";
  std::cout << "4. spine(bst4).height() == 1";
  assert(spine(bst4).height() == 1);
  std::cout << " OK.\n";
  std::cout << "4. spine(bst4).value() == 0";
  assert(spine(bst4).value() == 0);
  std::cout << " OK.\n";
  std::cout << "4. bst4.empty() == false";
  assert(!bst4.empty());
  std::cout << " OK.\n";
  std::cout << "4. bst4.find(0).size() == 1";
  assert(bst4.find(0).size() == 1);
  std::cout << " OK.\n";
  std::cout << "4. bst4.find(0).height() == 1";
  assert(bst4.find(0).height() == 1);
  std::cout << " OK.\n";
  std::cout << "4. bst4.find(0).value() == 0";
  assert(bst4.find(0).value() == 0);
  std::cout << " OK.\n";
  std::cout << "4. bst4.min() == 0";
  assert(bst4.min() == 0);
  std::cout << " OK.\n";
  std::cout << "4. bst4.max() == 0";
  assert(bst4.max() == 0);
  std::cout << " OK.\n";
  std::cout << "4. bst4.left().size() == 0";
  assert(bst4.left().size() == 0);
  std::cout << " OK.\n";
  std::cout << "4. bst4.left().height() == 0";
  assert(bst4.left().height() == 0);
  std::cout << " OK.\n";
  std::cout << "4. bst4.right().size() == 0";
  assert(bst4.right().size() == 0);
  std::cout << " OK.\n";
  std::cout << "4. bst4.right().height() == 0";
  assert(bst4.right().height() == 0);
  std::cout << " OK.\n";
  std::cout << "4. bst4.right().empty() == true";
  assert(bst4.right().empty());
  std::cout << " OK.\n";
  std::cout << "4. bst4.left().empty() == true";
  assert(bst4.left().empty());
  std::cout << " OK.\n";

  std::cout << "4. bst4.fold(1, sum) == 1";
  assert(bst4.fold(1, sum) == 1);
  std::cout << " OK.\n";

  try {
    std::cout << "4. bst4.min() will not throw.";
    bst4.min();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {

    BST<int> bst4 = bst + 0;
    std::cout << "4. bst4.max() will not throw.";
    bst4.min();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {
    std::cout << "4. bst4.left() will not throw.";
    bst4.left();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {
    std::cout << "4. bst4.right() will not throw.";
    bst4.right();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }
  
  try {
    std::cout << "4. bst4.value() will not throw.";
    bst4.value();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  std::cout << std::endl << "5. TESTING TWO ELEMENT TREE. CONSTRUCTED BY + 0 + 1" << std::endl << std::endl;

  BST<int> bst5(BST<int>() + 0 + 1);
  
  std::cout << "5. bst5.size() == 2";
  assert(bst5.size() == 2);
  std::cout << " OK.\n";
  std::cout << "5. bst5.height == 2";
  assert(bst5.height() == 2);
  std::cout << " OK.\n";
  std::cout << "5. spine(bst5).size() == 2";
  assert(spine(bst5).size() == 2);
  std::cout << " OK.\n";
  std::cout << "5. spine(bst5).height() == 2";
  assert(spine(bst5).height() == 2);
  std::cout << " OK.\n";
  std::cout << "5. spine(bst5).value() == 0";
  assert(spine(bst5).value() == 0);
  std::cout << " OK.\n";
  std::cout << "5. bst5.empty() == false";
  assert(!bst5.empty());
  std::cout << " OK.\n";
  std::cout << "5. bst5.find(0).size() == 2";
  assert(bst5.find(0).size() == 2);
  std::cout << " OK.\n";
  std::cout << "5. bst5.find(0).height() == 2";
  assert(bst5.find(0).height() == 2);
  std::cout << " OK.\n";
  std::cout << "5. bst5.find(0).value() == 0";
  assert(bst5.find(0).value() == 0);
  std::cout << " OK.\n";
  std::cout << "5. bst5.min() == 0";
  assert(bst5.min() == 0);
  std::cout << " OK.\n";
  std::cout << "5. bst5.max() == 1";
  assert(bst5.max() == 1);
  std::cout << " OK.\n";
  std::cout << "5. bst5.left().size() == 0";
  assert(bst5.left().size() == 0);
  std::cout << " OK.\n";
  std::cout << "5. bst5.left().height() == 0";
  assert(bst5.left().height() == 0);
  std::cout << " OK.\n";
  std::cout << "5. bst5.right().size() == 1";
  assert(bst5.right().size() == 1);
  std::cout << " OK.\n";
  std::cout << "5. bst5.right().height() == 1";
  assert(bst5.right().height() == 1);
  std::cout << " OK.\n";
  std::cout << "5. bst5.right().empty() == false";
  assert(!bst5.right().empty());
  std::cout << " OK.\n";
  std::cout << "5. bst5.left().empty() == true";
  assert(bst5.left().empty());
  std::cout << " OK.\n";

  std::cout << "5. bst5.fold(1, sum) == 2";
  assert(bst5.fold(1, sum) == 2);
  std::cout << " OK.\n";

  try {
    std::cout << "5. bst5.min() will not throw.";
    bst5.min();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {

    BST<int> bst5 = bst + 0;
    std::cout << "5. bst5.max() will not throw.";
    bst5.min();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {
    std::cout << "5. bst5.left() will not throw.";
    bst5.left();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {
    std::cout << "5. bst5.right() will not throw.";
    bst5.right();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }
  
  try {
    std::cout << "5. bst5.value() will not throw.";
    bst5.value();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  std::cout << std::endl << "6. TESTING TWO ELEMENT TREE. CONSTRUCTED BY {0, 1}" << std::endl << std::endl;

  BST<int> bst6({0, 1});
  
  std::cout << "6. bst6.size() == 2";
  assert(bst6.size() == 2);
  std::cout << " OK.\n";
  std::cout << "6. bst6.height == 2";
  assert(bst6.height() == 2);
  std::cout << " OK.\n";
  std::cout << "6. spine(bst6).size() == 2";
  assert(spine(bst6).size() == 2);
  std::cout << " OK.\n";
  std::cout << "6. spine(bst6).height() == 2";
  assert(spine(bst6).height() == 2);
  std::cout << " OK.\n";
  std::cout << "6. spine(bst6).value() == 0";
  assert(spine(bst6).value() == 0);
  std::cout << " OK.\n";
  std::cout << "6. bst6.empty() == false";
  assert(!bst6.empty());
  std::cout << " OK.\n";
  std::cout << "6. bst6.find(0).size() == 2";
  assert(bst6.find(0).size() == 2);
  std::cout << " OK.\n";
  std::cout << "6. bst6.find(0).height() == 2";
  assert(bst6.find(0).height() == 2);
  std::cout << " OK.\n";
  std::cout << "6. bst6.find(0).value() == 0";
  assert(bst6.find(0).value() == 0);
  std::cout << " OK.\n";
  std::cout << "6. bst6.min() == 0";
  assert(bst6.min() == 0);
  std::cout << " OK.\n";
  std::cout << "6. bst6.max() == 1";
  assert(bst6.max() == 1);
  std::cout << " OK.\n";
  std::cout << "6. bst6.left().size() == 0";
  assert(bst6.left().size() == 0);
  std::cout << " OK.\n";
  std::cout << "6. bst6.left().height() == 0";
  assert(bst6.left().height() == 0);
  std::cout << " OK.\n";
  std::cout << "6. bst6.right().size() == 1";
  assert(bst6.right().size() == 1);
  std::cout << " OK.\n";
  std::cout << "6. bst6.right().height() == 1";
  assert(bst6.right().height() == 1);
  std::cout << " OK.\n";
  std::cout << "6. bst6.right().empty() == false";
  assert(!bst6.right().empty());
  std::cout << " OK.\n";
  std::cout << "6. bst6.left().empty() == true";
  assert(bst6.left().empty());
  std::cout << " OK.\n";

  std::cout << "6. bst6.fold(1, sum) == 2";
  assert(bst6.fold(1, sum) == 2);
  std::cout << " OK.\n";

  try {
    std::cout << "6. bst6.min() will not throw.";
    bst6.min();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {

    BST<int> bst6 = bst + 0;
    std::cout << "6. bst6.max() will not throw.";
    bst6.min();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {
    std::cout << "6. bst6.left() will not throw.";
    bst6.left();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {
    std::cout << "6. bst6.right() will not throw.";
    bst6.right();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }
  
  try {
    std::cout << "6. bst6.value() will not throw.";
    bst6.value();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  std::cout << std::endl << "7. TESTING TWO ELEMENT TREE. CONSTRUCTED BY ITER" << std::endl << std::endl;

  std::vector<int> vec2 = {0, 1};
  BST<int> bst7(vec2.begin(), vec2.end());
  
  std::cout << "7. bst7.size() == 2";
  assert(bst7.size() == 2);
  std::cout << " OK.\n";
  std::cout << "7. bst7.height == 2";
  assert(bst7.height() == 2);
  std::cout << " OK.\n";
  std::cout << "7. spine(bst7).size() == 2";
  assert(spine(bst7).size() == 2);
  std::cout << " OK.\n";
  std::cout << "7. spine(bst7).height() == 2";
  assert(spine(bst7).height() == 2);
  std::cout << " OK.\n";
  std::cout << "7. spine(bst7).value() == 0";
  assert(spine(bst7).value() == 0);
  std::cout << " OK.\n";
  std::cout << "7. bst7.empty() == false";
  assert(!bst7.empty());
  std::cout << " OK.\n";
  std::cout << "7. bst7.find(0).size() == 2";
  assert(bst7.find(0).size() == 2);
  std::cout << " OK.\n";
  std::cout << "7. bst7.find(0).height() == 2";
  assert(bst7.find(0).height() == 2);
  std::cout << " OK.\n";
  std::cout << "7. bst7.find(0).value() == 0";
  assert(bst7.find(0).value() == 0);
  std::cout << " OK.\n";
  std::cout << "7. bst7.min() == 0";
  assert(bst7.min() == 0);
  std::cout << " OK.\n";
  std::cout << "7. bst7.max() == 1";
  assert(bst7.max() == 1);
  std::cout << " OK.\n";
  std::cout << "7. bst7.left().size() == 0";
  assert(bst7.left().size() == 0);
  std::cout << " OK.\n";
  std::cout << "7. bst7.left().height() == 0";
  assert(bst7.left().height() == 0);
  std::cout << " OK.\n";
  std::cout << "7. bst7.right().size() == 1";
  assert(bst7.right().size() == 1);
  std::cout << " OK.\n";
  std::cout << "7. bst7.right().height() == 1";
  assert(bst7.right().height() == 1);
  std::cout << " OK.\n";
  std::cout << "7. bst7.right().empty() == false";
  assert(!bst7.right().empty());
  std::cout << " OK.\n";
  std::cout << "7. bst7.left().empty() == true";
  assert(bst7.left().empty());
  std::cout << " OK.\n";

  std::cout << "7. bst7.fold(1, sum) == 2";
  assert(bst7.fold(1, sum) == 2);
  std::cout << " OK.\n";

  try {
    std::cout << "7. bst7.min() will not throw.";
    bst7.min();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {

    BST<int> bst7 = bst + 0;
    std::cout << "7. bst7.max() will not throw.";
    bst7.min();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {
    std::cout << "7. bst7.left() will not throw.";
    bst7.left();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {
    std::cout << "7. bst7.right() will not throw.";
    bst7.right();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }
  
  try {
    std::cout << "7. bst7.value() will not throw.";
    bst7.value();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  std::cout << std::endl << "8. TESTING THREE ELEMENT TREE. CONSTRUCTED BY + 0 + 1 + -1" << std::endl << std::endl;

  BST<int> bst8(BST<int>() + 0 + 1 + -1);
  
  std::cout << "8. bst8.size() == 3";
  assert(bst8.size() == 3);
  std::cout << " OK.\n";
  std::cout << "8. bst8.height == 2";
  assert(bst8.height() == 2);
  std::cout << " OK.\n";
  std::cout << "8. spine(bst8).size() == 3";
  assert(spine(bst8).size() == 3);
  std::cout << " OK.\n";
  std::cout << "8. spine(bst8).height() == 3";
  assert(spine(bst8).height() == 3);
  std::cout << " OK.\n";
  std::cout << "8. spine(bst8).value() == -1";
  assert(spine(bst8).value() == -1);
  std::cout << " OK.\n";
  std::cout << "8. bst8.empty() == false";
  assert(!bst8.empty());
  std::cout << " OK.\n";
  std::cout << "8. bst8.find(0).size() == 3";
  assert(bst8.find(0).size() == 3);
  std::cout << " OK.\n";
  std::cout << "8. bst8.find(0).height() == 2";
  assert(bst8.find(0).height() == 2);
  std::cout << " OK.\n";
  std::cout << "8. bst8.find(0).value() == 0";
  assert(bst8.find(0).value() == 0);
  std::cout << " OK.\n";
  std::cout << "8. bst8.min() == -1";
  assert(bst8.min() == -1);
  std::cout << " OK.\n";
  std::cout << "8. bst8.max() == 1";
  assert(bst8.max() == 1);
  std::cout << " OK.\n";
  std::cout << "8. bst8.left().size() == 1";
  assert(bst8.left().size() == 1);
  std::cout << " OK.\n";
  std::cout << "8. bst8.left().height() == 1";
  assert(bst8.left().height() == 1);
  std::cout << " OK.\n";
  std::cout << "8. bst8.right().size() == 1";
  assert(bst8.right().size() == 1);
  std::cout << " OK.\n";
  std::cout << "8. bst8.right().height() == 1";
  assert(bst8.right().height() == 1);
  std::cout << " OK.\n";
  std::cout << "8. bst8.right().empty() == false";
  assert(!bst8.right().empty());
  std::cout << " OK.\n";
  std::cout << "8. bst8.left().empty() == empty";
  assert(!bst8.left().empty());
  std::cout << " OK.\n";

  std::cout << "8. bst8.fold(1, sum) == 1";
  assert(bst8.fold(1, sum) == 1);
  std::cout << " OK.\n";

  try {
    std::cout << "8. bst8.min() will not throw.";
    bst8.min();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {

    BST<int> bst8 = bst + 0;
    std::cout << "8. bst8.max() will not throw.";
    bst8.min();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {
    std::cout << "8. bst8.left() will not throw.";
    bst8.left();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  try {
    std::cout << "8. bst8.right() will not throw.";
    bst8.right();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }
  
  try {
    std::cout << "8. bst8.value() will not throw.";
    bst8.value();
    std::cout << " OK\n";
  } catch (...) {
    assert(0);
  }

  std::cout << std::endl  << "9. TESTING MAX_DIFF." << std::endl << std::endl;

  std::cout << "9. max_diff(BST<int>({1, 1, 1, 1, 1});";
  assert(max_diff(BST<int>({1, 1, 1, 1, 1})) == 0);
  std::cout << " OK" << std::endl;
  std::cout << "9. max_diff(BST<int>({1, 2});";
  assert(max_diff(BST<int>({1, 2})) == 1);
  std::cout << " OK" << std::endl;
  std::cout << "9. max_diff(BST<int>({1, 2, 3, 4, 5, 6});";
  assert(max_diff(BST<int>({1, 2, 3, 4, 5, 6})) == 1);
  std::cout << " OK" << std::endl;
  std::cout << "9. max_diff(BST<int>({0, 2, -2, 1, -1, 3, -3});";
  assert(max_diff(BST<int>({0, 2, -2, 1, -1, 3, -3})) == 1);
  std::cout << " OK" << std::endl;

  try {
    std::cout << "9. max_diff(BST<int>() will throw";
    max_diff(BST<int>());
    assert(0);
  } catch (...) {
    std::cout << " OK.\n";
  }

  try {
    std::cout << "9. max_diff(BST<int>({1}) will throw";
    max_diff(BST<int>({1}));
    assert(0);
  } catch (...) {
    std::cout << " OK.\n";
  }

  std::cout << std::endl << "10. TESTING TREES WITH 1000 NODES." << std::endl << std::endl;

  std::vector<int> vec4;

  int sign = 1;
  for (int i = 0; i < 1000; ++i) {
    sign *= 1;
    vec4.push_back(i * sign);
  }
  
  time_t start, end;

  time(&start);

  BST<int>(vec4.begin(), vec4.end());
  
  time(&end);
  
  std::cout << "10. Building of tree with 1000 nodes took " << end - start << " seconds.\n";

  std::cout << std::endl << "11. TESTING TREES WITH 10000 NODES." << std::endl << std::endl;

  vec4 = std::vector<int>();

  for (int i = 0; i < 10000; ++i) {
    sign *= 1;
    vec4.push_back(i * sign);
  }

  time(&start);

  BST<int>(vec4.begin(), vec4.end());
  
  time(&end);
  
  std::cout << "11. Building of tree with 10000 nodes took " << end - start << " seconds.\n";

#ifdef TEST_COMPLEXITY

  std::cout << std::endl << "COMPLEXITY TEST" << std::endl << std::endl;

  srand(time(NULL));

  for (int size = 0; size <= 20; ++size) {
    
    std::vector<int> temp;

    std::cout << "Testing vector creation.";
    for (int i = 0; i < size * 250; ++i) {
      temp.push_back(rand());
    }
    std::cout << " Done. ";

    time(&start);

    BST<int>(vec4.begin(), vec4.end());

    time(&end);

    std::cout << "Building of tree with " << size * 250 << " nodes took " << end - start << " seconds.\n";
  }

#endif

    return 0;
}
