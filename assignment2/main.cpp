#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
static int numKeys = 0; // global variable for number of keys
class Node{
public:
  int key;
  Node *left;
  Node *right;
  int height;
};
int getHeight(Node* node){
  if (node != NULL){
    return node->height;
  } else{
    return 0;
  }
}
int getBalance(Node* node){
  if (node == NULL){
    return 0;
  } else{
    return getHeight(node->left)-getHeight(node->right); // difference in heights of left and right
  }
}
Node* getLeftMost(Node* node){ // smallest node in tree (most left)
  Node* temp = node;
  while (temp->left != NULL){
    temp = temp->left;
  }
  return temp;
}
Node* getRightMost(Node* node){ // largest node in tree (most right)
  Node* temp = node;
  while (temp->right != NULL){
    temp = temp->right;
  }
  return temp;
}
// right rotate
Node *rightRotate(Node *node){
  Node *nodeL = node->left; // pivot (left of pivot stays the same)
  Node *nodeLR = nodeL->right;

  nodeL->right = node;
  node->left = nodeLR;

  node->height = max(getHeight(node->left),getHeight(node->right)) + 1;
  nodeL->height = max(getHeight(nodeL->left),getHeight(nodeL->right)) + 1;

  return nodeL;
}
// left rotate
Node *leftRotate(Node *node){
  Node *nodeR = node->right; // pivot (right of pivot stays the same)
  Node *nodeRL = nodeR->left;

  nodeR->left = node;
  node->right = nodeRL;

  node->height = max(getHeight(node->left),getHeight(node->right)) + 1;
  nodeR->height = max(getHeight(nodeR->left),getHeight(nodeR->right)) + 1;

  return nodeR;
}
// insertion of node
Node* insertNode(Node* node, int key){
  if (node == NULL){ // if target node is empty
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    numKeys++;
    return(node);
  }

  if (key == node->key){ // don't insert (value already exists)
    return node;
  } else if (key < node->key){ // insert to the left (recursive)
    node->left = insertNode(node->left, key);
  } else if (key > node->key){ // insert to the right (recursive)
    node->right = insertNode(node->right, key);
  }

  node->height = max(getHeight(node->left),getHeight(node->right))+1; // get side with more height and add 1 (root) to it

  int balance = getBalance(node); // check if node is still balanced

  if (balance > 1 && key < node->left->key){ // l-l case
    return rightRotate(node);
  }
  if (balance < -1 && key > node->right->key){ // r-r case
    return leftRotate(node);
  }
  if (balance > 1 && key > node->left->key){ // l-r case
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  if (balance < -1 && key < node->right->key){ // r-l case
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node; // return root node(for that level)
}
// delete node
Node* deleteNode(Node* node, int key){
  if (node == NULL){ // if key to delete is not found
    return node;
  }
  
  if (key < node->key){ // delete from left (recursive)
    node->left = deleteNode(node->left, key);
  } else if (key > node->key){ // delete from right (recursive)
    node->right = deleteNode(node->right, key);
  } else{ // delete this
    if ((node->left == NULL) && (node->right == NULL)){ // no children
      Node *temp = node;
      node = NULL;
      free(temp);
      numKeys--;
    } else if (node->left == NULL){ // right child
      Node *temp = node->right;
      *node = *temp;
      free(temp);
      numKeys--;
    } else if (node->right == NULL){ // left child
      Node *temp = node->left;
      *node = *temp;
      free(temp);
      numKeys--;
    } else{ // both children
      Node* temp = getRightMost(node->left);

      node->key = temp->key;

      node->left = deleteNode(node->left,temp->key);
    }
  }

  if (node == NULL){ // return node after deleting
    return node;
  }

  node->height = max(getHeight(node->left),getHeight(node->right))+1;

  int balance = getBalance(node);

  if (balance > 1 && getBalance(node->left) >= 0){ // l-l case
    return rightRotate(node);
  }
  if (balance > 1 && getBalance(node->left) < 0){ // l-r case
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  if (balance < -1 && getBalance(node->right) <= 0){ // r-r case
    return leftRotate(node);
  }
  if (balance < -1 && getBalance(node->right) > 0){ // r-l case
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}
// print operations (pre, post, in)
void preOrder(Node *node){
  if(node == NULL){
    return;
  }
  cout << node->key << " ";
  preOrder(node->left);
  preOrder(node->right);
}
void postOrder(Node *node){
  if (node == NULL){
    return;
  }
  postOrder(node->left);
  postOrder(node->right);
  cout << node->key << " ";
}
void inOrder(Node *node){
  if (node != NULL){
    inOrder(node->left);
    cout << node->key << " ";
    inOrder(node->right);
  }
}


int main(void){
  string input;
  getline(cin,input);
  vector<string> inputs; // inputs for all add/delete operations
  string delimiter = " ";
  size_t pos = 0;
  while ((pos = input.find(delimiter)) != string::npos){
    inputs.push_back(input.substr(0, pos));
    input.erase(0, pos + delimiter.length()); // input will be left with the finishing move
  }

  Node *root = NULL; // root node
  for (unsigned int i = 0; i < inputs.size(); i++){
    switch (inputs.at(i).at(0)){ // add/delete
      case 'A':
        root = insertNode(root,stoi(inputs.at(i).substr(1)));
        break;
      case 'D':
        root = deleteNode(root,stoi(inputs.at(i).substr(1)));
        break;
      default:
        cout << "Add/Delete Error" << endl;
        break;
    }
  }

  switch (input.at(1)){
    case 'R': // preorder
      preOrder(root);
      if (numKeys == 0){
        cout << "EMPTY";
      }
      break;
    case 'O': // postorder
      postOrder(root);
      if (numKeys == 0){
        cout << "EMPTY";
      }
      break;
    case 'N': // inorder
      inOrder(root);
      if (numKeys == 0){
        cout << "EMPTY";
      }
      break;
    default:
      cout << "No finisher found" << endl;
      break;
  }
}
