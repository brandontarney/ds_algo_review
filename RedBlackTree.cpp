//NOTE - this may not be valid code

/*
* Algorithm
*   Every node has an extra bit - color (red or black)
*   The root is black
*   All leaves are black
*   If a node is red, then both its children are black
*   Every path from a given node to any of its descendant NIL nodes contains the same number of black nodes
*   Insertion/deletaion may require rotation
*/

/*
* Performance
*   AVG O(lg n)
*/

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<stdlib>

using namespace std;


// Basic type defintions:

enum color_t { BLACK, RED };

struct Node {
  Node* parent;
  Node* left;
  Node* right;
  enum color_t color;
  int key;
};

// Helper functions:

Node* GetParent(Node* n) {
  // Note that parent is set to null for the root node.
  return n->parent;
}

Node* GetGrandParent(Node* n) {
  Node* p = GetParent(n);

  // No parent means no grandparent.
  if (p == nullptr) {
    return nullptr;
  }

  // Note: Will be nullptr if parent is root.
  return GetParent(p);
}

Node* GetSibling(Node* n) {
  Node* p = GetParent(n);

  // No parent means no sibling.
  if (p == nullptr) {
    return nullptr;
  }

  if (n == p->left) {
    return p->right;
  } else {
    return p->left;
  }
}

Node* GetUncle(Node* n) {
  Node* p = GetParent(n);
  Node* g = GetGrandParent(n);

  // No grandparent means no uncle
  if (g == nullptr) {
    return nullptr;
  }

  return GetSibling(p);
}

void RotateLeft(Node* n) {
  Node* nnew = n->right;
  Node* p = GetParent(n);
  assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.
  n->right = nnew->left;
  nnew->left = n;
  n->parent = nnew;
  // Handle other child/parent pointers.
  if (n->right != nullptr) {
    n->right->parent = n;
  }

  // Initially n could be the root.
  if (p != nullptr) {
    if (n == p->left) {
      p->left = nnew;
    } else if (n == p->right) {
      p->right = nnew;
    }
  }
  nnew->parent = p;
}

void RotateRight(Node* n) {
  Node* nnew = n->left;
  Node* p = GetParent(n);
  assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.

  n->left = nnew->right;
  nnew->right = n;
  n->parent = nnew;

  // Handle other child/parent pointers.
  if (n->left != nullptr) {
    n->left->parent = n;
  }

  // Initially n could be the root.
  if (p != nullptr) {
    if (n == p->left) {
      p->left = nnew;
    } else if (n == p->right) {
      p->right = nnew;
    }
  }
  nnew->parent = p;
}
/*
Insertion begins by adding the node in a very similar manner as a standard binary search tree insertion and by coloring it red. The big difference is that in the binary search tree a new node is added as a leaf, whereas leaves contain no information in the red–black tree, so instead the new node replaces an existing leaf and then has two black leaves of its own added.
*/
Node* Insert(Node* root, Node* n) {
  // Insert new Node into the current tree.
  InsertRecurse(root, n);

  // Repair the tree in case any of the red-black properties have been violated.
  InsertRepairTree(n);

  // Find the new root to return.
  root = n;
  while (GetParent(root) != nullptr) {
    root = GetParent(root);
  }
  return root;
}

void InsertRecurse(Node* root, Node* n) {
  // Recursively descend the tree until a leaf is found.
  if (root != nullptr && n->key < root->key) {
    if (root->left != nullptr) {
      InsertRecurse(root->left, n);
      return;
    } else {
      root->left = n;
    }
  } else if (root != nullptr) {
    if (root->right != nullptr) {
      InsertRecurse(root->right, n);
      return;
    } else {
      root->right = n;
    }
  }

  // Insert new Node n.
  n->parent = root;
  n->left = nullptr;
  n->right = nullptr;
  n->color = RED;
}
/*
What happens next depends on the color of other nearby nodes. There are several cases of red–black tree insertion to handle:

N is the root node, i.e., first node of red–black tree
N's parent (P) is black
P is red (so it can't be the root of the tree) and N's uncle (U) is red
P is red and U is black'
*/
void InsertRepairTree(Node* n) {
  if (GetParent(n) == nullptr) {
    InsertCase1(n);
  } else if (GetParent(n)->color == BLACK) {
    InsertCase2(n);
  } else if (GetUncle(n) != nullptr && GetUncle(n)->color == RED) {
    InsertCase3(n);
  } else {
    InsertCase4(n);
  }
}
/*
Property 1 (every node is either red or black) and Property 3 (all leaves are black) always holds.
Property 2 (the root is black) is checked and corrected with case 1.
Property 4 (red nodes have only black children) is threatened only by adding a red node, repainting a node from black to red, or a rotation.
Property 5 (all paths from any given node to its leaves have the same number of black nodes) is threatened only by adding a black node, repainting a node, or a rotation.
Case 1: The current node N is at the root of the tree. In this case, it is repainted black to satisfy property 2 (the root is black). Since this adds one black node to every path at once, property 5 (all paths from any given node to its leaf nodes contain the same number of black nodes) is not violated.
*/
void InsertCase1(Node* n) {
  if (GetParent(n) == nullptr) {
    n->color = BLACK;
  }
}
/*
Case 2: The current node's parent P is black, so property 4 (both children of every red node are black) is not invalidated. In this case, the tree is still valid. Property 5 (all paths from any given node to its leaf nodes contain the same number of black nodes) is not threatened, because the current node N has two black leaf children, but because N is red, the paths through each of its children have the same number of black nodes as the path through the leaf it replaced, which was black, and so this property remains satisfied.
*/
void InsertCase2(Node* n) {
  // Do nothing since tree is still valid.
  return;
}
/*
Note: In the following cases it can be assumed that N has a grandparent node G, because its parent P is red, and if it were the root, it would be black. Thus, N also has an uncle node U, although it may be a leaf in case 4.
Note: In the remaining cases, it is shown in the diagram that the parent node P is the left child of its parent even though it is possible for P to be on either side. The code samples already cover both possibilities.
Diagram of case 3
Case 3: If both the parent P and the uncle U are red, then both of them can be repainted black and the grandparent G becomes red to maintain property 5 (all paths from any given node to its leaf nodes contain the same number of black nodes). Since any path through the parent or uncle must pass through the grandparent, the number of black nodes on these paths has not changed. However, the grandparent G may now violate Property 2 (The root is black) if it is the root or Property 4 (Both children of every red node are black) if it has a red parent. To fix this, the tree's red-black repair procedure is rerun on G.

Note that this is a tail-recursive call, so it could be rewritten as a loop. Since this is the only loop, and any rotations occur after this loop, this proves that a constant number of rotations occur.
*/
void InsertCase3(Node* n) {
  GetParent(n)->color = BLACK;
  GetUncle(n)->color = BLACK;
  GetGrandParent(n)->color = RED;
  InsertRepairTree(GetGrandParent(n));
}
/*
Diagram of case 4
Case 4, step 1: The parent P is red but the uncle U is black. The ultimate goal will be to rotate the current node into the grandparent position, but this will not work if the current node is on the "inside" of the subtree under G (i.e., if N is the left child of the right child of the grandparent or the right child of the left child of the grandparent). In this case, a left rotation on P that switches the roles of the current node N and its parent P can be performed. The rotation causes some paths (those in the sub-tree labelled "1") to pass through the node N where they did not before. It also causes some paths (those in the sub-tree labelled "3") not to pass through the node P where they did before. However, both of these nodes are red, so property 5 (all paths from any given node to its leaf nodes contain the same number of black nodes) is not violated by the rotation. After this step has been completed, property 4 (both children of every red node are black) is still violated, but now we can resolve this by continuing to step 2.
*/
void InsertCase4(Node* n) {
  Node* p = GetParent(n);
  Node* g = GetGrandParent(n);

  if (n == p->right && p == g->left) {
    RotateLeft(p);
    n = n->left;
  } else if (n == p->left && p == g->right) {
    RotateRight(p);
    n = n->right;
  }

  InsertCase4Step2(n);
}
/*
Diagram of case 5
Case 4, step 2: The current node N is now certain to be on the "outside" of the subtree under G (left of left child or right of right child). In this case, a right rotation on G is performed; the result is a tree where the former parent P is now the parent of both the current node N and the former grandparent G. G is known to be black, since its former child P could not have been red without violating property 4. Once the colors of P and G are switched, the resulting tree satisfies property 4 (both children of every red node are black). Property 5 (all paths from any given node to its leaf nodes contain the same number of black nodes) also remains satisfied, since all paths that went through any of these three nodes went through G before, and now they all go through P.
*/
void InsertCase4Step2(Node* n) {
  Node* p = GetParent(n);
  Node* g = GetGrandParent(n);

  if (n == p->left) {
    RotateRight(g);
  } else {
    RotateLeft(g);
  }
  p->color = BLACK;
  g->color = RED;
}
