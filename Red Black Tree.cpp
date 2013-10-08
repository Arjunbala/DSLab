#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<iomanip>
#include<deque>
#include<sstream>
#include<math.h>
using namespace std;

enum color
{
     black = 0,
     red = 1
};

struct node
{
       int data;
       node *left;
       node *right;
       node *parent;
       enum color clr;
};

node *root = NULL;


struct node *right_rotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *left_rotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    // Return new root
    return y;
}

void rb_insert_fixup(node *temp, node *ins)
{
     while((ins->parent)->clr == red)
     {
        if(ins->parent == ((ins->parent)->parent)->left)
        {
            node *y = ((ins->parent)->parent)->right;
            if(y->clr == red)
            {
                      (ins->parent)->clr = black;
                      y->clr = black;
                      ((ins->parent)->parent)->clr = red;
                      ins = (ins->parent)->parent;
                      return;
            }
            else if(ins == (ins->parent)->right)
            {
               ins = ins->parent;
               temp = left_rotate(temp);    
               return;
            }
            (ins->parent)->clr = black;
            ((ins->parent)->parent)->clr = red;
            temp = right_rotate(temp);
            return;
        }
        if(ins->parent == ((ins->parent)->parent)->right)
        {
            node *y = ((ins->parent)->parent)->left;
            if(y->clr == red)
            {
                      (ins->parent)->clr = black;
                      y->clr = black;
                      ((ins->parent)->parent)->clr = red;
                      ins = (ins->parent)->parent;
                      return;
            }
            else if(ins == (ins->parent)->left)
            {
               ins = ins->parent;
               temp = left_rotate(temp);    
               return;
            }
            (ins->parent)->clr = black;
            ((ins->parent)->parent)->clr = red;
            temp = right_rotate(temp);
            return;
        }
     }
}

void insert_rb(node *temp, node *ins)
{
     node *y = NULL;
     node *x = temp;
     while(x != NULL)
     {
             y = x;
             if(ins->data < x->data)
               x = x->left;
             else
              x = x->right;
     }
     ins->parent = y;
     if(y == NULL)
     {
          temp = ins;
     }
     else if(ins->data < y->data)
     {
          y->left = ins;
     }
     else
      y->right = ins;
     ins->left = NULL;
     ins->right = NULL;
     ins->clr = red;
     rb_insert_fixup(temp,ins);
}

int maxHeight(node *p) {
  if (!p) return 0;
  int leftHeight = maxHeight(p->left);
  int rightHeight = maxHeight(p->right);
  return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
}

string intToString(int val) {
  ostringstream ss;
  int st = val;
  ss << st;
  return ss.str();
}

void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<node*>& nodesQueue) {
  deque<node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {  
    cout << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
    cout << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
  }
  cout <<"\n";
}

void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<node*>& nodesQueue) {
  deque<node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    cout << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
    cout << setw(branchLen+2) << ((*iter) ? intToString((*iter)->data) : "");
    cout << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  cout << "\n";
}

void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<node*>& nodesQueue) {
  deque<node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    cout << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->data) : "");
  }
  cout << "\n";
}

void display(node *root) {
  int h = maxHeight(root);
  int nodesInThisLevel = 1;
  int level = 1;
  int indentSpace = 0;
  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)
    
  deque<node*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue);

    for (int i = 0; i < nodesInThisLevel; i++) {
      node *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
	      nodesQueue.push_back(currNode->left);
	      nodesQueue.push_back(currNode->right);
      } else {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue);
}

int main()
{
     int ch=1,data;
     node *ins = new node;
     while(ch != 3)
     {
              cout<<"\nMAIN MENU\n";
              cout<<"1.Insert\n";
              cout<<"2.Display\n";
              cout<<"3.Exit\n";
              cout<<"Enter your choice\n";
              cin>>ch;
              switch(ch)
              {
                case 1:
                     cout<<"Enter the number to be inserted\n";
                     cin>>data;
                      ins->data = data;
                      ins->left = NULL;
                      ins->right = NULL;
                      ins->clr = red;
                     insert_rb(root,ins);
                     break;
                case 2:
                     display(root);
                     break;
                case 3:
                     break;
                default: 
                         cout<<"Enter a correct choice\n";
                         break;
                
              }
     }
     getch();
     return 0;
}
