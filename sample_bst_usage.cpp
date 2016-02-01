#include "bst_imp.h"
#include <iostream>

int main() {
  std::cout << "LUL" << std::endl;
    {
        BST<int> bst({3});
        // 3
    }

    {
        BST<int> bst({3, 4});
        // 3    |
        //  \   |
        //   4  |
    }

    {
        BST<int> bst({3, 4, 1});
        //   3    |
        //  / \   |
        // 1   4  |
    }

    {
        BST<int> bst({3, 4, 1, 2});
        //    3    |
        //   / \   |
        //  1   4  |
        //   \     |
        //    2    |
    }
    {
        BST<int> bst({3,4,1,2,7});
        //    3      |
        //   / \     |
        //  1   4    |
        //   \   \   |
        //    2   7  |
        std::cout << bst << std::endl;
        std::cout << bst.height() << std::endl;
    }
/*
    BST<int> bst({3,4,1,2,7,3});
    //    3          |
    //   / \         |
    //  1   4        |
    //   \   \       |
    //    2   7      |
    //     \         |
    //      3        |
    //  
    //  */

    std::vector<int> temp;
    int sign = 1;

    for (int i = 0; i < 1000; ++i) {
      sign *= -1;
      temp.push_back(i * sign);
    }

    BST<int> bst(temp.begin(), temp.end());
    

    std::cout << bst << std::endl; // prints 1 2 3 3 4 7
    std::cout << bst.size() << std::endl; //prints 6
    std::cout << bst.min() << std::endl; // prints 1
    std::cout << bst.max() << std::endl; // prints 7
    std::cout << bst.height() << std::endl; // prints 4
    std::cout << spine(bst).height() << std::endl; // prints 6
    std::cout << spine(bst) << std::endl;
    std::cout << "FIND 4 : " << bst.find(4) << std::endl; // prints 4 7
    std::cout << "FIND 11 : " << bst.find(11) << std::endl; //prints nothing (possibly one space)
    std::cout << max_diff(bst) << std::endl; //prints 3

    return 0;
}
