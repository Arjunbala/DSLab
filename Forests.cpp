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

struct node
{
       char data;
       node *left;
       node *right;
};

int maxHeight(node *p) {
  if (!p) return 0;
  int leftHeight = maxHeight(p->left);
  int rightHeight = maxHeight(p->right);
  return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
}

string intToString(int val) {
  ostringstream ss;
  char st = val;
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

void preorder(node *temp)
{
     cout<<temp->data<<" ";
     if(temp->left != NULL)
     preorder(temp->left);
     if(temp->right != NULL)
     preorder(temp->right);
}

void postorder(node *temp)
{
     if(temp->left != NULL)
     postorder(temp->left);
     if(temp->right != NULL)
     postorder(temp->right);
     cout<<temp->data<<" ";
}


int levels[100];
node *address[100];
int top = -1;

int main()
{
    int ch = 1,level;
    int pred_level;
    node *pred_loc;
    char data;
    node *head = new node;
    head->left = NULL;
    head->right = head;
    top = top + 1;
    levels[top]=0;
    address[top] = head;
    while(ch != 2)
    {
             cout<<"Enter your choice\n";
             cout<<"1->Insert more data , 2->Exit\n\n";
             cin>>ch;
             if(ch == 1)
             {
                   cout<<"Enter information in the format: level data\n";
                   cin>>level>>data;
                   node *temp = new node;
                   temp->data = data;
                   temp->left = NULL;
                   temp->right = NULL;
                   pred_level = levels[top];
                   pred_loc = address[top];
                   if(level > pred_level)
                   {
                            pred_loc->left = temp;
                   }
                   else
                   {
                       while(pred_level > level)
                       {
                           top = top - 1;
                           pred_level = levels[top];
                           pred_loc = address[top];
                       }
                       if(pred_level < level)
                       {
                           cout<<"Mixed Level Numbers\n\n";
                           exit(1);
                       }
                       pred_loc->right = temp;
                       top = top - 1;
                   }
                       top = top + 1;
                       levels[top] = level;
                       address[top] = temp;
                   
             }
             else if(ch == 2)
             {
                   cout<<"Going to results... \n";
                   break;
             }
             else
             {
                 cout<<"Enter a valid choice\n\n";
             }
    }
    cout<<"Displaying...\n\n\n";
    display(head->left);
    cout<<"\n\n\n";
    cout<<"Preorder: ";
    preorder(head->left);
    cout<<"\n\n";
    cout<<"Postorder: ";
    postorder(head->left);
    getch();
    return 0;
}
