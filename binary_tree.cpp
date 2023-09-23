#include <iostream>
#include <cstring>
struct treeData
{
    int id;
    double amount;
    char name[45] = {0};
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


    while (tree != NULL){
    int nodesBelowleft = countLeaf(tree->nextLeft);
    int nodesBelowRight = countLeaf(tree->nextRight);

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
        
    //std::cout<<"ID: "<<node->data.id<<" - Name: "<<node->data.name<<" - Amount: "<<node->data.amount<<'\t';
    std::cout<<"ID: "<<node->data.id<<" ";

    // Start root/node
    int currentLevel = level;
    for (int i = 0; i < level; i++)
    {
        std::cout<<"  ";
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
     char Jippy[45] = {'J','i','p','p','y'} ;
     char Tommy[45] = {'T','o','m','m','y'} ;
     char Booby[45] = {'B','o','o','b','y'} ;
     char Wompy[45] = {'W','o','m','p','y'} ;
     char Marko[45] = {'M','a','r','k','o'} ;
     char Jumper[45]= {'J','u','m','p','e','r'};
     char Dillan[45]= {'D','i','l','l','a','n'};
     char Noob[45]  = {'N','o','o','b'} ;
     char Slupp[45] = {'S','l','u','p','p'} ;
     char Jolp[45]  = {'J','o','l','p'} ;
     char Prump[45] = {'P','r','u','m','p'} ;

    BinaryTree bt;
    treeData jippy;    jippy.id = 1;    jippy.amount  = 150.20;   std::strcpy(jippy.name  , Jippy);    bt.appendTree(jippy); // HEAD 
    treeData tommy;    tommy.id = 2;    tommy.amount  = 252.60;   std::strcpy(tommy.name  , Tommy);    bt.appendTree(tommy); // Left 
    treeData booby;    booby.id = 3;    booby.amount  = -55.22;   std::strcpy(booby.name  , Booby);    bt.appendTree(booby); // Right
    treeData wompy;    wompy.id = 4;    wompy.amount  = 159.98;   std::strcpy(wompy.name  , Wompy);    bt.appendTree(wompy); // Left 
    treeData marko;    marko.id = 5;    marko.amount  =  73.32;   std::strcpy(marko.name  , Marko);    bt.appendTree(marko); // Right
    treeData jumper;   jumper.id = 6;   jumper.amount = -42.47;   std::strcpy(jumper.name , Jumper);   bt.appendTree(jumper);// Left 
    treeData dillan;   dillan.id = 7;   dillan.amount = 112.63;   std::strcpy(dillan.name , Dillan);   bt.appendTree(dillan);// Right
    treeData noob;     noob.id = 9;     noob.amount   =  22.22;   std::strcpy(noob.name   , Noob);     bt.appendTree(noob);  // Left 
    treeData slupp;    slupp.id = 10;   slupp.amount  = -12.78;   std::strcpy(slupp.name  , Slupp);    bt.appendTree(slupp); // Right
    treeData jolp;     jolp.id = 11;    jolp.amount   =  73.32;   std::strcpy(jolp.name   , Jolp);     bt.appendTree(jolp);  // Left 
    treeData prump;    prump.id = 12;   prump.amount  = -42.47;   std::strcpy(prump.name  , Prump);    bt.appendTree(prump); // Right
    for (int i = 0; i < 100000; i++){
        prump.id = i;
        bt.appendTree(prump);
    }

    // levels 06  ==    100 nodes
    // levels 09  ==   1000 nodes
    // levels 13  ==  10000 nodes
    // levels 15  ==  50000 nodes
    // levels 16  ==  75000 nodes
    // levels 16  == 100000 nodes

    // real 5m49.819s
    // user 5m21.773s
    // sys  0m00.536s
    
    bt.printTree();
    // double sum = bt.sumTree();
    // std::cout<<"Sum of total tree = "<<sum<<'\n';

    // int size = bt.countTree();
    // std::cout<<"Total size of tree = "<<size<<'\n';
}
// id 755 level 9 vinstra