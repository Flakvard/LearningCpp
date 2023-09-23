#include <iostream>
struct treeData
{
    int id;
    double amount;
};

class BinaryTree
{
private:
    struct binaryNode
    {
        treeData data;
        binaryNode* nextLeft;
        binaryNode* nextRight;
    };
    
public:
    BinaryTree();
    void appendTree(treeData node);
    ~BinaryTree(){};
private:
    typedef binaryNode* treeNodes;
    treeNodes _root;
};

BinaryTree::BinaryTree(/* args */){
    _root = NULL;
}

void BinaryTree::appendTree(treeData leafData){
    binaryNode* tree = _root;
    
    binaryNode* newNode = new binaryNode;
    newNode->data = leafData;
    newNode->nextLeft = NULL;
    newNode->nextRight = NULL;

    // First round
    if (tree == NULL){
        _root = newNode;
        return;
    }

    while (tree != NULL){
        // Second Round
        if (tree != NULL){
            if (tree->nextLeft == NULL){
                tree->nextLeft = newNode;
                return;
            }
            if (tree->nextRight == NULL && tree->nextLeft != NULL){
                tree->nextRight = newNode;
                return;
            }
        }

            if (tree->nextLeft == NULL){
                tree->nextLeft = newNode;
                break;
            }
            if (tree->nextRight == NULL && tree->nextLeft == NULL){
                tree->nextRight = newNode;
                break;
            }
            tree = tree->nextLeft;
    }
}

int main(){

    BinaryTree bt;
    treeData jippy;    jippy.id = 1;    jippy.amount = 150.20;
    bt.appendTree(jippy);

    treeData tommy;    tommy.id = 2;    tommy.amount = 252.60;
    bt.appendTree(tommy);

    treeData booby;    booby.id = 3;    booby.amount = -55.22;
    bt.appendTree(booby);

    treeData wompy;    wompy.id = 4;    wompy.amount = 159.98;
    bt.appendTree(wompy);

    treeData marko;    marko.id = 5;    marko.amount = 73.32;
    bt.appendTree(marko);

    treeData jumper;    jumper.id = 6;    jumper.amount = -42.47;
    bt.appendTree(jumper);



}
