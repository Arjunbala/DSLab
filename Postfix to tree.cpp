#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<iomanip.h>
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

node *stack[100];
node *root = NULL;
int top = -1;

void push(node *temp)
{
     top = top + 1;
     stack[top] = temp;
}

node* pop()
{
     if(top == -1)
     {
            return NULL;
     }
     else
     {
         top = top - 1;
         return stack[top+1];
     }
}

/*void display(node *t,int indent = 5)
{
     if(t == NULL)
     {
          cout<<"Tree is empty\n";
          exit(1);
     }
    else
     {
         node *temp = t;
         if (indent) {
            cout <<setw(indent) <<" ";
        }
         cout<<temp->data<<" ";
         if(temp->left != NULL)
         {
          cout<<"\n";
          display(temp->left,indent-2);
         }
         if(temp->right != NULL)
         {
          display(temp->right,indent-2);
         }
         if (indent) {
            cout <<setw(indent) <<" ";
        }
         
     }
      
}*/

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

int main()
{
    char exp[100];
    cout<<"Enter the postfix expression\n";
    gets(exp);
    for(int i=0;i<strlen(exp);i++)
    {
            if((exp[i] == '+')|| (exp[i] == '-')|| (exp[i] == '*')|| (exp[i] == '/')|| (exp[i] == '^')|| (exp[i] == '%'))
            {
                 node *temp = new node;
                 temp->data = exp[i];
                 temp->right = pop();
                 temp->left = pop();
                 if((temp->right == NULL)||(temp->right == NULL))
                 {
                      cout<<"The expression is invalid\n";
                      exit(1);
                 }      
                 else
                 {
                     push(temp);
                 }
            }      
            else if(isalnum(exp[i]))
            {
                 node *temp = new node;
                 temp->data = exp[i];
                 temp->left = NULL;
                 temp->right = NULL;
                 push(temp);
            }
            else
            {
                cout<<"Invalid expression\n";
                exit(1);
            }
    }
    node *root = pop();
   if(top != -1)
    {
           cout<<"Expression is invalid\n";
           exit(1);
    }
    else
    {
        display(root);
    }
    getch();
}
