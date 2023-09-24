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
    void printLeaf(leafNode* node, int level);
    double findAmountNode(leafNode* tree, double amount);
    typedef leafNode* treeHead;
    treeHead _root;
};

binary_search_tree::binary_search_tree(){
    _root = NULL;
}

void binary_search_tree::printLeaf(leafNode* node, int level){
    leafNode * nodePtr = node;
    // no tree
    if (node == NULL)
        return;
        
    //std::cout<<"ID: "<<node->data.id<<" - Name: "<<node->data.name<<" - Amount: "<<node->data.amount<<'\t';
    std::cout<<"ID: "<<node->num.id<<"\tDupl: "<<node->duplicate<<"\tAmt: "<<node->num.amount<<"\t";


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
    printLeaf(node->nextLeft, currentLevel+1);
    // right side of tree
    printLeaf(node->nextRight,currentLevel+1);
}
void binary_search_tree::printTree(){
    leafNode * tree = _root;
    int level = 0;
    printLeaf(tree, level);
}

void binary_search_tree::appendBST(leafNode *Tree, leafNode *node)
{ 
    leafNode* newNode = node;
    leafNode* tree = Tree;

    // If newNode is greater than tree and there is a node in subtree right
    if (tree->nextRight != NULL && newNode->num.amount > tree->num.amount){
        // if (tree->nextRight->num.amount == newNode->num.amount)
        // {
        //     ++tree->nextRight->duplicate;
        //     delete newNode;
        //     return;
        // }
        
        if (newNode->num.amount > tree->nextRight->num.amount)
        {
            // old node - Go down right path
            // store old node
            leafNode* newAllocation = tree->nextRight;
            // assign new node into old node path
            tree->nextRight = newNode;
            // go down left path
            tree = tree->nextRight;
            // Recursive check for the old node
            appendBST(tree, newAllocation);
            return;
        }else{
            // newnode - Go down left path
            tree = tree->nextRight;
            appendBST(tree , newNode);
            return;
        }
    }

    // If treeLeft is NOT NULL and
    // newNode is less than tree 
    if (tree->nextLeft != NULL && newNode->num.amount < tree->num.amount){
        // if (tree->nextLeft->num.amount == newNode->num.amount)
        // {
        //     ++tree->nextLeft->duplicate;
        //     delete newNode;
        //     return;
        // }
        // check if newNode is greater or less than subtree
        if (newNode->num.amount > tree->nextLeft->num.amount)
        {
            // if nextRight is NOT NULL
            // newNode is greather than nextRight
            if (tree->nextRight != NULL && newNode->num.amount > tree->nextRight->num.amount)
            {
                // old node - Go down right path
                // store old node
                leafNode* newAllocation = tree->nextRight;
                // assign new node into old node path
                tree->nextRight = newNode;
                // go down left path
                tree = tree->nextRight;
                // Recursive check for the old node
                appendBST(tree, newAllocation);
                return;
            }else if (tree->nextRight == NULL)
            {
                tree->nextRight = newNode;
                return;
            }
            // old node - Go down right path
            // store old node
            leafNode* newAllocation = tree->nextLeft;
            // assign new node into old node path
            tree->nextLeft = newNode;
            // go down left path
            tree = tree->nextLeft;
            // Recursive check for the old node
            appendBST(tree, newAllocation);
            return;
        }else{
            // newnode - Go down left path
            tree = tree->nextLeft;
            appendBST(tree, newNode);
            return;
        }
    }
    
    // If treeLeft is NULL and
    // newNode is less than tree 
    if (tree->nextLeft == NULL && newNode->num.amount < tree->num.amount){
        tree->nextLeft = newNode;
        return;
    }

    // If treeRight is NULL and
    // newNode is greater than tree 
    if (tree->nextRight == NULL && newNode->num.amount > tree->num.amount){
        tree->nextRight = newNode;
        return;
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
    }
    amount += findAmountNode(tree->nextLeft, amountToFind);
    amount += findAmountNode(tree->nextRight, amountToFind);
    return amount;
}

binary_search_tree::~binary_search_tree()
{
    // Nothing to do yet
}

void binary_search_tree::append(Amount data)
{
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

    int val[] = {40,78,32,99,8,6,10,33,55,12,3,50,60,34,92,34,21,87,52,23,44,47,29,22};
    //          {01,02,03,3,4,05,06,07,08,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
    
    int size = sizeof(val)/sizeof(val[0]);

    //for (int i = 0; i < size; i++)
    //{
        //std::cout<<val[i]<<'\n';
    //}

    Amount a;
    a.amount = 50;
    a.id = 0;
    bst.append(a);
    for (int i = 0; i < 200; i++){
        a.amount = rand() % 100;
        //a.amount = val[i];
        a.id = i+1;
        bst.append(a);
    }
    double amount = bst.findAmount(34);

}