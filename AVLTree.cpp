//NOTE - this may not be valid code

/*
* Algorithm
*   Store balance of any node (sum of children balance)
*   By default, balance = -1 for left child & +1 for right child
*   Every node must have a balance of { -1, 0, 1}
*   start @ point of unbalance, LL rotation or LR rotation or RL rotation or RR rotation
*/

/*
* Performance
*   AVG O(lg n)
*/

#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1<<(n))

using namespace std;

//Node Declaration
struct avl_node
{
  int data;
  struct avl_node * left;
  struct avl_node * right;
} * root;

//AVL tree

class avlTree
{
public:
  int height(avl_node *);
  int diff(avl_node *);
  avl_node *rr_rotation(avl_node *);
  avl_node *ll_rotation(avl_node *);
  avl_node *lr_rotation(avl_node *);
  avl_node *rl_rotation(avl_node *);
  avl_node* balance(avl_node *);
  avl_node* insert(avl_node *, int );

  void display(avl_node *, int);
  void inorder(avl_node *);
  void preorder(avl_node *);
  void postorder(avl_node *);
  avlTree()
  {
      root = NULL;
  }
}

/*
 * Main Contains Menu
 */
int main()
{
    int choice, item;
    avlTree avl;
    while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"\n-----------"<<endl;
        cout<<"AVL Tree Implementation"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Display Balanced AVL Tree"<<endl;
        cout<<"3.InOrder traversal"<<endl;
        cout<<"4.PreOrder traversal"<<endl;
        cout<<"5.PostOrder traversal"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>item;
            root = avl.insert(root, item);
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            avl.display(root, 1);
            break;
        case 3:
            cout<<"Inorder Traversal:"<<endl;
            avl.inorder(root);
            cout<<endl;
            break;
        case 4:
            cout<<"Preorder Traversal:"<<endl;
            avl.preorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder Traversal:"<<endl;
            avl.postorder(root);
            cout<<endl;
            break;
        case 6:
            exit(1);
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}


/*
* Height of AVL Tree
*/
int avlTree::height(avl_node *temp)
{
   int h = 0;
   if (temp != NULL)
   {
       int l_height = height (temp->left);
       int r_height = height (temp->right);
       int max_height = max (l_height, r_height);
       h = max_height + 1;
   }
   return h;
}

/*
* Height Difference
*/
int avlTree::diff(avl_node *temp)
{
   int l_height = height (temp->left);
   int r_height = height (temp->right);
   int b_factor= l_height - r_height;
   return b_factor;
}

/*
* Right- Right Rotation (e.g. 1 rotation to the left)
*/
avl_node *avlTree::rr_rotation(avl_node *parent)
{
	/* BEGIN
		a
			b
				c
	   */

	//parent = a
   avl_node *temp;
   temp = parent->right;  //temp = b
   parent->right = temp->left; //a.right = b.left
   temp->left = parent; //b.left = a

	/* END
			b
		a		c
				
	   */
   
   return temp; //parent = temp = b
}
/*
* Left- Left Rotation (e.g. 1 rotation to the right)
*/
avl_node *avlTree::ll_rotation(avl_node *parent)
{
   avl_node *temp;
   temp = parent->left;
   parent->left = temp->right;
   temp->right = parent;
   return temp;
}

/*
* Left - Right Rotation (e.g. 1 sub-tree rotation left, then 1 rotation right)
*/
avl_node *avlTree::lr_rotation(avl_node *parent)
{
   avl_node *temp;
   temp = parent->left;
   parent->left = rr_rotation (temp);
   return ll_rotation (parent);
}

/*
* Right- Left Rotation (e.g. 1 sub-tree rotation right, then 1 rotation left)
*/
avl_node *avlTree::rl_rotation(avl_node *parent)
{
   avl_node *temp;
   temp = parent->right;
   parent->right = ll_rotation (temp);
   return rr_rotation (parent);
}

/*
* Balancing AVL Tree
*/
avl_node *avlTree::balance(avl_node *temp)
{
   int bal_factor = diff (temp);
   if (bal_factor > 1)
   {
       if (diff (temp->left) > 0)
           temp = ll_rotation (temp);
       else
           temp = lr_rotation (temp);
   }
   else if (bal_factor < -1)
   {
       if (diff (temp->right) > 0)
           temp = rl_rotation (temp);
       else
           temp = rr_rotation (temp);
   }
   return temp;
}

/*
* Insert Element into the tree
*/
avl_node *avlTree::insert(avl_node *root, int value)
{
   if (root == NULL)
   {
       root = new avl_node;
       root->data = value;
       root->left = NULL;
       root->right = NULL;
       return root;
   }
   else if (value < root->data)
   {
       root->left = insert(root->left, value);
       root = balance (root);
   }
   else if (value >= root->data)
   {
       root->right = insert(root->right, value);
       root = balance (root);
   }
   return root;
}

/*
* Display AVL Tree
*/
void avlTree::display(avl_node *ptr, int level)
{
   int i;
   if (ptr!=NULL)
   {
       display(ptr->right, level + 1);
       printf("\n");
       if (ptr == root)
       cout<<"Root -> ";
       for (i = 0; i < level && ptr != root; i++)
           cout<<"        ";
       cout<<ptr->data;
       display(ptr->left, level + 1);
   }
}

/*
* Inorder Traversal of AVL Tree
*/
void avlTree::inorder(avl_node *tree)
{
   if (tree == NULL)
       return;
   inorder (tree->left);
   cout<<tree->data<<"  ";
   inorder (tree->right);
}
/*
* Preorder Traversal of AVL Tree
*/
void avlTree::preorder(avl_node *tree)
{
   if (tree == NULL)
       return;
   cout<<tree->data<<"  ";
   preorder (tree->left);
   preorder (tree->right);

}

/*
* Postorder Traversal of AVL Tree
*/
void avlTree::postorder(avl_node *tree)
{
   if (tree == NULL)
       return;
   postorder ( tree ->left );
   postorder ( tree ->right );
   cout<<tree->data<<"  ";
}
