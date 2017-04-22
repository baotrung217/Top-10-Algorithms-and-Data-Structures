#include <iostream>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    Node* left;
    Node* right;
};

/* Function prototypes */

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(Node* root);

/* Print nodes at a given level */
void printGivenLevel(Node* root, int level);

/* Function to print level order traversal a tree*/
void printLevelOrder(Node* root);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
Node* newNode(int data);

int main()
{
    Node* root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    std::cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}

int height(Node* root)
{
    if (root == NULL)
        return 0;
    else
    {
        /* Compute the height of each sub-tree */
        int l_height = height(root->left);
        int r_height = height(root->right);

        if (l_height > r_height)
            return (l_height + 1);
        else
            return (r_height + 1);
    }
}

void printGivenLevel(Node * root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        std::cout << root->data << " ";
    }
    else
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(Node* root)
{
    if (root == NULL)
        return;
    for (int i=1; i<=height(root); i++)
    {
        printGivenLevel(root, i);
    }
}

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}
