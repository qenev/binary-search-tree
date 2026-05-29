#include <iostream>
#include "BST.h"

int main() {
    BST<int> tree;
    for (int v : {5, 3, 7, 1, 4, 6, 8, 2}) tree.insert(v);

    std::cout << "In-order:   "; tree.inorder  ([](const int& v){ std::cout << v << " "; }); std::cout << "\n";
    std::cout << "Pre-order:  "; tree.preorder ([](const int& v){ std::cout << v << " "; }); std::cout << "\n";
    std::cout << "Post-order: "; tree.postorder([](const int& v){ std::cout << v << " "; }); std::cout << "\n";
    std::cout << "Height: " << tree.height() << "  Count: " << tree.count() << "\n";
    std::cout << "Contains 4: " << (tree.contains(4) ? "yes" : "no") << "\n";

    tree.remove(3);
    std::cout << "After remove(3) in-order: ";
    tree.inorder([](const int& v){ std::cout << v << " "; });
    std::cout << "\n";
    return 0;
}
