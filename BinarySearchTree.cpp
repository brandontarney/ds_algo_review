//NOTE - this may not be valid C++ code!

/*
*Binary search tree is NOT a binary sort tree...a Binary search tree is formed from sorted data where the middle value is used as the root of each "partition" 
*/


// C program to demonstrate insert operation in binary search tree 
#include<stdio.h> 
#include<stdlib.h> 
   
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
   
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 

struct node * createBST( int bstVals[] )
{
	printf("Creating BST");
	//Find the middle value
	const int lengthOfArray = sizeof(bstVals)/sizeof(*bstVals);
	const int middleIndex = lengthOfArray/2;
	//Choose middle value & make it the root
	struct node * rootNode = newNode(bstVals[middleIndex]);
	
	//Create partition arrays
	int leftPartition[middleIndex];
	int rightPartition[middleIndex];
	std::copy(bstVals, bstVals+middleIndex, leftPartition);
	std::copy(bstVals+middleIndex, bstVals+lenthOfArray, rightPartition);
	
	//Recursively create the tree
	rootNode->left = createBST(leftPartition);
	rootNode->right = createBST(rightPartition);	
}
   
// Driver Program to test above functions 
int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    
    /*
    *Default way to create tree
    
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
   */

    int bstVals[7] = {20,30,40,50,60,70,80};
    
    struct node * root = createBST(bstVals);
    
    // print inoder traversal of the BST 
	inorder(root);
	
	//search tree
	return 0;

}