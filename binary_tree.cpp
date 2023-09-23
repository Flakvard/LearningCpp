#include <iostream>
struct treeData
{
    int id;
    double amount;
    std::string name;
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
    void printLeaf(binaryNode* node, int level);
    double sumLeaf(binaryNode *node);
    int countLeaf(binaryNode *node);
    
public:
    BinaryTree();
    void appendTree(treeData node);
    void appendLeaf(treeData node, binaryNode* root);
    void printTree();
    double sumTree();
    int countTree();
    ~BinaryTree(){};
private:
    typedef binaryNode* treeNodes;
    treeNodes _root;
};

BinaryTree::BinaryTree(/* args */){
    _root = NULL;
}

void BinaryTree::appendLeaf(treeData leafData, binaryNode* node)
{ 
    binaryNode* tree = node;
    // int currentLevel = level;
    
    binaryNode* newNode = new binaryNode;
    newNode->data = leafData;
    newNode->nextLeft = NULL;
    newNode->nextRight = NULL;

    // First round
    if (tree == NULL){
        _root = newNode;
        return;
    }


    int nodesBelowleft = countLeaf(tree->nextLeft);
    int nodesBelowRight = countLeaf(tree->nextRight);
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
        // Third Round
        if (tree->nextLeft == NULL){
            tree->nextLeft = newNode;
            break;
        }
        if (tree->nextRight == NULL && tree->nextLeft == NULL){
            tree->nextRight = newNode;
            break;
        }
        // Go down one level 
        tree = (nodesBelowRight >= nodesBelowleft) 
            ? tree->nextLeft : tree->nextRight;

        // tree = tree->nextLeft;
    }

}

void BinaryTree::appendTree(treeData leafData){
    binaryNode* tree = _root;
    appendLeaf(leafData, tree);

}

void BinaryTree::printLeaf(binaryNode *node, int level){
    binaryNode * nodePtr = node;
    // no tree
    if (node == NULL)
        return;
        
    std::cout<<"ID: "<<node->data.id<<" - Name: "<<node->data.name<<" - Amount: "<<node->data.amount<<'\t';

    // Start root/node
    int currentLevel = level;
    for (int i = 0; i < level; i++)
    {
        std::cout<<"    ";
    }
    std::cout<<"Level: "<<currentLevel<<'\n'; 
    
    // reached bottom? No == continue, Yes == stop and return
    if (node->nextLeft == NULL && node->nextRight == NULL){
        return;
    }

    // left side of tree
    printLeaf(node->nextLeft, currentLevel+1);
    // right side of tree
    printLeaf(node->nextRight,currentLevel+1);
}
void BinaryTree::printTree(){
    binaryNode * tree = _root;
    int level = 0;
    printLeaf(tree, level);
}
double BinaryTree::sumLeaf(binaryNode *node){
    if (node == NULL)
        return 0;
    double sum = 0;
    if (node != NULL)
        sum += node->data.amount;
    
    if (node->nextLeft == NULL && node->nextRight == NULL){
       return sum;
    }

    sum += sumLeaf(node->nextLeft);
    sum += sumLeaf(node->nextRight);

    return sum;

}
int BinaryTree::countLeaf(binaryNode *node)
{
    int count = 0;
    if (node == NULL)
        return count;

    ++count;

    // Reach bottom
    if (node->nextLeft == NULL && node->nextRight == NULL){
        return count;
    }

    count += countLeaf(node->nextLeft);
    count += countLeaf(node->nextRight);
    
    return count;
    
}
double BinaryTree::sumTree()
{
    binaryNode * tree = _root;
    return sumLeaf(tree);
}

int BinaryTree::countTree()
{
    binaryNode * tree = _root;
    return countLeaf(tree);
}

int main(){

    BinaryTree bt;
    treeData jippy;    jippy.id = 1;    jippy.amount  = 150.20;   jippy.name  = "Jippy";    bt.appendTree(jippy); // HEAD 
    treeData tommy;    tommy.id = 2;    tommy.amount  = 252.60;   tommy.name  = "Tommy";    bt.appendTree(tommy); // Left 
    treeData booby;    booby.id = 3;    booby.amount  = -55.22;   booby.name  = "Booby";    bt.appendTree(booby); // Right
    treeData wompy;    wompy.id = 4;    wompy.amount  = 159.98;   wompy.name  = "Wompy";    bt.appendTree(wompy); // Left 
    treeData marko;    marko.id = 5;    marko.amount  =  73.32;   marko.name  = "Marko";    bt.appendTree(marko); // Right
    treeData jumper;   jumper.id = 6;   jumper.amount = -42.47;   jumper.name = "Jumper";   bt.appendTree(jumper);// Left 
    treeData dillan;   dillan.id = 7;   dillan.amount = 112.63;   dillan.name = "Dillan";   bt.appendTree(dillan);// Right
    treeData noob;     noob.id = 9;     noob.amount   =  22.22;   noob.name   = "Noob" ;    bt.appendTree(noob);  // Left 
    treeData slupp;    slupp.id = 10;   slupp.amount  = -12.78;   slupp.name  = "Slupp";    bt.appendTree(slupp); // Right
    treeData jolp;     jolp.id = 11;    jolp.amount   =  73.32;   jolp.name   = "Jolp" ;    bt.appendTree(jolp);  // Left 
    treeData prump;    prump.id = 12;   prump.amount  = -42.47;   prump.name  = "Prump";    bt.appendTree(prump); // Right
    bt.printTree();
    double sum = bt.sumTree();
    std::cout<<"Sum of total tree = "<<sum<<'\n';

    int size = bt.countTree();
    std::cout<<"Total size of tree = "<<size<<'\n';
}
