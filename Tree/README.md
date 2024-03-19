## Binary Tree 

- **Traversal techniques**

  A Tree Data Structure can be traversed in the following ways:

  - **Depth First Search or DFS**
    - Inorder Traversal
    - Preorder Traversal
    - Postorder Traversal

  - **Breadth First Search or BFS**
    - Level Order Traversal

  - **Other Traversals**
    - Boundary Traversal
    - Diagonal Traversal


**Preorder Traversal**
- Traverse the root node 
- Traverse the left subtree , i:e (left->subtree)
- Traverse the right subtree, i:e (right->subtree)

**Inorder Traversal**
- Traverse the left subtree, i.e., call Inorder(left->subtree)
- Visit the root.
- Traverse the right subtree, i.e., call Inorder(right->subtree)

**Postorder Traversal**
- Traverse the left subtree, i.e., call Postorder(left->subtree)
- Traverse the right subtree, i.e., call Postorder(right->subtree)
- Visit the root

| --:Binary Tree PROBLEMS:--  |
|------------------------------|
- 1. [Representation of tree in C++ ](https://github.com/Abrahul-107/DSA_CHALLENGE/blob/main/Tree/01_representation.cpp)
- 2. [Preorder traversal in tree ](https://github.com/Abrahul-107/DSA_CHALLENGE/blob/main/Tree/02_preorder_traversal.cpp) 
- 3. [inorder traversal in tree ](https://github.com/Abrahul-107/DSA_CHALLENGE/blob/main/Tree/03_inorder_traversal.cpp) 
- 4. [inorder traversal in tree ](https://github.com/Abrahul-107/DSA_CHALLENGE/blob/main/Tree/04_postorder_traversal.cpp) 
- 5. [Level order traversal in tree(BFS) ](https://github.com/Abrahul-107/DSA_CHALLENGE/blob/main/Tree/05_levelorder_traversal.cpp) 
- 6. [Maximum depth/height of tree(Using both BFS and DFS) ](https://github.com/Abrahul-107/DSA_CHALLENGE/blob/main/Tree/06_maximum_depth.cpp) 