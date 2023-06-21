#include <iostream>
// base building block - node
// first node - root - does not have a parent
// last nodes - leaf nodes - does not have children nodes
// regular tree - any number of children
// binary tree - two children max
// bsd - niary search tree - data organized in a specific way - left lower than parent, right higher than parent
// tree traversal - only way to acces the date stored in nodes
// bfs and dfs algos
// depth first search - branch by branch in a way
// - 1. preorder (data, left, right)
// - 2. inorder (left, data, right)
// - 3. postorder (left, right, data)
struct node
{
    int data;
    node *left;
    node *right;
};

void printTree(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    std::cout << root->data << std::endl;
    printTree(root->left);
    printTree(root->right);
}

void printLeaves(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    else if (root->left == nullptr && root->right == nullptr)
    {
        std::cout << "leaf " << root->data << std::endl;
    }

    printLeaves(root->left);
    printLeaves(root->right);
}

void leavesCount(node* root, int& count)
{   
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
    {
        count+=1;
    }
    leavesCount(root->left, count);
    leavesCount(root->right, count);
}

void leavesSum(node* root, int& sum)
{   
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
    {
        sum+=root->data;
    }
    leavesSum(root->left, sum);
    leavesSum(root->right, sum);
}

int treeSum(node* root)
{   
    int sum = 0;
    if (root == nullptr) return 0;

    sum = root->data + treeSum(root->right) + treeSum(root->left);
    return sum;

}

int countNodes(node* root)
{
    int count = 0;
    if (root == nullptr) return 0;

    count = 1 + countNodes(root->left) + countNodes(root->right);
    return count;
}

node *createNode(int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    std::cout << "CREATED: " << newNode->data << std::endl;
    return newNode;
}

int main()
{
    std::cout << "Tree" << std::endl;
    // Level 1
    node *root = createNode(1);
    // Level 2
    root->left = createNode(2);
    root->right = createNode(3);
    // Level 3
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    // Level 4
    root->left->right->left = createNode(9);
    root->right->right->left = createNode(15);

    printTree(root);
    printLeaves(root);
    int count = 0;
    int sum = 0;
    leavesCount(root, count);
    leavesSum(root, sum);
    std::cout<<"Number of leaves: "<<count<<std::endl;
    std::cout<<"Sum of leaves: "<<sum<<std::endl;

    std::cout<<"Sum of nodes: "<<treeSum(root)<<std::endl;
    std::cout<<"Number of nodes: "<<countNodes(root)<<std::endl;

    return 0;
}