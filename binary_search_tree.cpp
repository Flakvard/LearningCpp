/*
    Create a binary search tree which is a tree where each node value is
    greater than any value in the node's left subtree, but 
    less than any value in the node's right subtree.

*/
#include <iostream>
#include <random>

struct Amount
{
    double amount = 0;
    int id;
};

class binary_search_tree
{
private:
    struct leafNode
    {
        Amount num;
        int duplicate;
        leafNode* nextLeft;
        leafNode* nextRight;
    };
public:
    binary_search_tree();
    void append(Amount data);
    void appendBST(leafNode* tree, leafNode* newNode);
    ~binary_search_tree();
    void printTree();
    double findAmount(double amount);
private:
    void printLeaf(leafNode* node, int level, std::string subTreeSide);
    double findAmountNode(leafNode* tree, double amount);
    typedef leafNode* treeHead;
    treeHead _root;
};

binary_search_tree::binary_search_tree(){
    _root = NULL;
}

void binary_search_tree::printLeaf(leafNode* node, int level, std::string subTreeSide){
    leafNode * nodePtr = node;
    // no tree
    if (node == NULL)
        return;
        
    //std::cout<<"ID: "<<node->data.id<<" - Name: "<<node->data.name<<" - Amount: "<<node->data.amount<<'\t';
    std::cout<<"ID: "<<node->num.id<<"\tDupl: "<<node->duplicate<<"\tAmt: "<<node->num.amount<<"\t"<<subTreeSide<<" "<<level<<"\t";


    // Start root/node
    int currentLevel = level;
    for (int i = 0; i < level; i++)
    {
        std::cout<<"  ";
    }
    std::cout<<"Lvl: "<<currentLevel<<'\n'; 
    
    // reached bottom? No == continue, Yes == stop and return
    if (node->nextLeft == NULL && node->nextRight == NULL){
        return;
    }

    // left side of tree
    printLeaf(node->nextLeft, currentLevel+1, "LEFT");
    // right side of tree
    printLeaf(node->nextRight,currentLevel+1, "RIGHT");
}
void binary_search_tree::printTree(){
    leafNode * tree = _root;
    int level = 0;
    printLeaf(tree, level,"TREE");
}

void binary_search_tree::appendBST(leafNode *Tree, leafNode *node)
{ 
    if (Tree == NULL)
        return;

    leafNode* newNode = node;
    leafNode* tree = Tree;

    // RIGHT SIDE OF THE TREE - NO NULL VALUES
    // newNode is greater than tree
    if (newNode->num.amount > tree->num.amount){

        if (tree->nextRight != NULL && newNode->num.amount < tree->nextRight->num.amount)
        {
            // if newNode is greater than tree, but less than the nextRight
            // Available left-sub-sub-tree under the right-subtree  
            if (tree->nextRight->nextLeft == NULL){
                tree->nextRight->nextLeft = newNode;
            }else{
            // Not Avaialbe, look further up the tree 
                tree = tree->nextRight;
                appendBST(tree, newNode);
                return;
            }
        }else{
            // newNode is greater than tree AND the sub-right-tree
            // Available right-sub-tree under the tree?  
            if (tree->nextRight == NULL){
                tree->nextRight = newNode;
            }
            // Not Avaialbe, look further up the tree 
            tree = tree->nextRight;
            appendBST(tree, newNode);
            return;
        }
    }

    // LEFT SIDE OF THE TREE - NO NULL VALUES
    // newNode is less than tree 
    if (newNode->num.amount < tree->num.amount){

        if (tree->nextLeft != NULL && newNode->num.amount > tree->nextLeft->num.amount)
        {
            // if newNode is less than tree, but greater than the nextLeft
            // Available right-sub-sub-tree under the left-subtree  
            if (tree->nextLeft->nextRight == NULL){
                tree->nextLeft->nextRight = newNode;
            }else{
            // Not Avaialbe, look further up the tree 
                tree = tree->nextLeft;
                appendBST(tree, newNode);
                return;
            }
        }else{
            // newNode is greater than tree AND the sub-right-tree
            // Available left-sub-tree under the tree?  
            if (tree->nextLeft == NULL){
                tree->nextLeft = newNode;
            }
            // Not Avaialbe, look further up the tree 
            tree = tree->nextLeft;
            appendBST(tree, newNode);
            return;
            
        }
    }

}

double binary_search_tree::findAmount(double amount){

    leafNode* tree = _root;
    double amountFound = 0;
    amountFound += findAmountNode(tree,amount);
    return amountFound;

}
double binary_search_tree::findAmountNode(leafNode* Tree, double amountToFind){
    if (Tree == NULL)
        return 0.0;    

    double amount = 0;
    leafNode *tree = Tree;
    if (tree->num.amount == amountToFind){
        ++tree->duplicate;
        amount = tree->num.amount;
        return amount;
    }
    if (amountToFind < tree->num.amount)
    {
        amount += findAmountNode(tree->nextLeft, amountToFind);
    }else{
        amount += findAmountNode(tree->nextRight, amountToFind);
    }
    
    return amount;
}

binary_search_tree::~binary_search_tree()
{
    // Nothing to do yet
}

void binary_search_tree::append(Amount data)
{
    double foundAmount = findAmount(data.amount);
    if (foundAmount > 0)
        return;
    
    leafNode* newNode = new leafNode;
    newNode->num = data;
    newNode->nextLeft = NULL;
    newNode->nextRight = NULL;
    newNode->duplicate = 1;

    leafNode* tree = _root;

    if (tree == NULL){
        _root = newNode;
        return;
    }else{
        appendBST(tree, newNode);
        return;
    }
}

int main(){


    binary_search_tree bst;

    Amount a;
     a.amount = 250;
     a.id = 0;
     bst.append(a);
    for (int i = 0; i < 1000; i++){
        a.amount = rand() % 500;
        a.id = i+1;
        bst.append(a);
    }
    bst.printTree();
    double amount = bst.findAmount(27);
    amount = bst.findAmount(21);
    amount = bst.findAmount(31);
    amount = bst.findAmount(59);
    amount = bst.findAmount(88);
    amount = bst.findAmount(42);
}