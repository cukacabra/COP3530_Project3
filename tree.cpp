#include <iomanip>
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
#include "tree.h"
#include <sstream>
using namespace std;

// If not found : Returns node pointer with empty airport name string
// If found     : Returns node pointer to aiport node 
node* tree::getNode(node* rootNode, string airport)
{
	if(rootNode == nullptr){
        return new node();
    } else if(airport == rootNode->nodeAirport){
        return rootNode;
    }  else if(airport < rootNode->nodeAirport){
        return getNode(rootNode->leftChild, airport);
    } else{
        return getNode(rootNode->rightChild, airport);
    }
}

bool tree::insertNode(node* rootNode, node* inserted)
{
    if(rootNode == nullptr){ //Airport inserted
        //rootNode = inserted;
        this->root = inserted;
        return true;
    }
    else if(inserted->nodeAirport == rootNode->nodeAirport){ // Airport in tree
        return false;
    } else if(inserted->nodeAirport < rootNode->nodeAirport && rootNode->leftChild == NULL){
        rootNode->leftChild = inserted;
        return true;
    } else if (inserted->nodeAirport < rootNode->nodeAirport) {
        return insertNode(rootNode->leftChild, inserted);
    } 
    else if (inserted->nodeAirport > rootNode->nodeAirport && rootNode->rightChild == NULL) {
        rootNode->rightChild = inserted;
        return true;
    }
    else if (inserted->nodeAirport > rootNode->nodeAirport) {
        return insertNode(rootNode->rightChild, inserted);
    }
}




// create and populate table based on root OR could be lowest item in PQ
void tree::populateTree(vector<node*> nodes)
{
    //check access of myTree
    //myTree tree;
    //tree.root = nullptr;
    for (auto thisNode : nodes)
    {
        this->insertNode(this->root,thisNode);
    }
};