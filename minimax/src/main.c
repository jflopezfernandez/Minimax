
#include "minimax.h"

#define TRUE  1
#define FALSE 0

#define IS_NULL(ptr) (ptr == NULL)
#define NOT_NULL(ptr) (!(IS_NULL(ptr)))

#define MAX(a,b) ((a > b) ? a : b)
#define MIN(a,b) ((a < b) ? a : b)

#define IS_EVEN(x) ((x % 2 == 0) ? 1 : 0)
#define IS_ODD(x)  ((x % 2 != 0) ? 1 : 0)

typedef struct node_t {
    int payoff;
    struct node_t* left;
    struct node_t* right;
}* Node;

Node createNode(int payoff);
void setLeftChild(Node parent, Node leftChild);
void setRightChild(Node parent, Node rightChild);
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
    static int n;
    
    if (IS_NULL(node)) {
        return;
    }
    
    printNode(node->left);
    printf("%4d: %4d\n", ++n, node->payoff);
    printNode(node->right);
}

Node generateTree(size_t depth) {
    int randomPayoff = rand() % 100 + 1;
    Node root = createNode(randomPayoff);
    
    if (IS_ODD(depth)) {
        root->payoff *= -1;
    }
    
    Node leftChild  = (depth > 0) ? generateTree(depth - 1) : NULL;
    Node rightChild = (depth > 0) ? generateTree(depth - 1) : NULL;
    
    setChildren(root, leftChild, rightChild);
    
    return root;
}

int nodeIsLeaf(Node node) {
    if (IS_NULL(node->left) && IS_NULL(node->right)) {
        return TRUE;
    }
    
    return FALSE;
}

int minimax(Node node, size_t lookahead, int maximizingPlayer) {
    int value = 0;
    
    if (lookahead == 0 || nodeIsLeaf(node)) {
        return node->payoff;
    }
    
    if (maximizingPlayer) {
        value = INT_MIN;
        
        value = MAX(value, minimax(node->left, lookahead - 1, FALSE));
        value = MAX(value, minimax(node->right, lookahead - 1, FALSE));
        
        return value;
    }
    
    value = INT_MAX;
    
    value = MIN(value, minimax(node->left, lookahead - 1, TRUE));
    value = MIN(value, minimax(node->right, lookahead - 1, TRUE));
    
    return value;
}


int main()
{
    srand(time(NULL));
    
    const size_t depth = 10;
    Node root = generateTree(depth);
    
    printNode(root);
    
    int decision = minimax(root, 2, TRUE);
    
    printf("decision: %d\n", decision);
    
    printf("\t - left: %d\n", root->left->payoff);
    printf("\t\t - l: %d\n", root->left->left->payoff);
    printf("\t\t - r: %d\n", root->left->right->payoff);
    
    printf("\t - right: %d\n", root->right->payoff);
    printf("\t\t - l: %d\n", root->right->left->payoff);
    printf("\t\t - r: %d\n", root->right->right->payoff);
    
    /*
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
    */

    return EXIT_SUCCESS;
}
