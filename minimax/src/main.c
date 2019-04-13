
#include "minimax.h"

#define IS_NULL(ptr) (ptr == NULL)
#define NOT_NULL(ptr) (!(IS_NULL(ptr)))

typedef struct node_t {
    int payoff;
    struct node_t* left;
    struct node_t* right;
}* Node;

Node createNode(int payoff);
void setChildren(Node parent, Node left, Node right);
void printNode(Node node);

Node createNode(int payoff) {
    Node newNode = calloc(sizeof(struct node_t), 1);
    
    if (IS_NULL(newNode)) {
        exit(EXIT_FAILURE);
    }
    
    newNode->payoff = payoff;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void setLeftChild(Node parent, Node leftChild) {
    parent->left = leftChild;
}

void setRightChild(Node parent, Node rightChild) {
    parent->right = rightChild;
}

void setChildren(Node parent, Node left, Node right) {
    if (IS_NULL(parent)) {
        return;
    }
    
    setLeftChild(parent, left);
    setRightChild(parent, right);
}

void printNode(Node node) {
    if (IS_NULL(node)) {
        return;
    }
    
    printNode(node->left);
    printf("%d\n", node->payoff);
    printNode(node->right);
}


int main()
{
    Node n1 = createNode(1);
    Node n2 = createNode(2);
    Node n3 = createNode(3);
    Node n4 = createNode(4);
    Node n5 = createNode(5);
    Node n6 = createNode(6);
    
    setChildren(n1, n2, n3);
    setChildren(n2, n4, n5);
    setChildren(n3, NULL, n6);
    
    printNode(n1);

    return EXIT_SUCCESS;
}
