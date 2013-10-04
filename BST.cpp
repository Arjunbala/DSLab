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
       int data;
       node *left;
       node *right;
       node *parent;
};
node *root = NULL;

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

void insert(node *traverse,int data)
{
     node *temp = new node;
     temp->data = data;
     temp->left = NULL;
     temp->right = NULL;
     temp->parent = NULL;
     if(traverse == NULL)
     {
      traverse = temp;
      root = traverse;
      return;           
     }
     if(data < traverse->data)
     {
             if(traverse->left == NULL)
             {             
                  traverse->left = temp;
                  temp->parent = traverse;
                  return;
             }
             else
             insert(traverse->left,data);
     }
     else
     {
         if(traverse->right == NULL)
         {
              traverse->right = temp;
              temp->parent = traverse;
              return;
         }
         else
         insert(traverse->right,data);
     }
}

void del(node *temp,int data)
{
     if(temp == NULL)
     {
             cout<<"The tree is empty\n";
             return;
     }
     else if(root->data == data)
     {
          if((root->right == NULL)&&(root->left == NULL))
          {
              delete(root);
              root = NULL; 
              return;
          }
          else if((root->right == NULL)&&(root->left != NULL))
          {
               node *suc = root->left;
               //(suc->left)->parent = suc;
               root = suc;
               return;
          }
          else if((root->right != NULL)&&(root->left == NULL))
          {
               node *suc = root->right;
               //(suc->right)->parent = suc;
               root = suc;
               return;
          }
          else
          {
              node *suc = root->right;
              suc->left = root->left;
              //(suc->left)->parent = suc;
              //(suc->right)->parent = suc;
              root = suc;
              return;
          }
     }
     else
     {
         if(temp->data == data)
         {
             if((temp->left == NULL)&&(temp->right == NULL))
             {
                 if((temp->parent)->left == temp)
                 {
                    (temp->parent)->left = NULL;
                    delete temp;
                    return;
                 }
                  else if((temp->parent)->right == temp)
                 {
                    (temp->parent)->right = NULL;
                    delete temp;
                    return;
                 }
             }
             else if((temp->left == NULL)&&(temp->right != NULL))
             {
                  node *suc = temp->right;
                  temp->right = NULL;
                  if((temp->parent)->left == temp)
                  {
                   (temp->parent)->left = suc;
                   delete temp;
                   return;
                  }
                  else if((temp->parent)->right == temp)
                  {
                   (temp->parent)->right = suc;
                   delete temp;
                   return;
                  }
             }
             else if((temp->right == NULL)&&(temp->left != NULL))
             {
                  node *suc = temp->left;
                  temp->left = NULL;
                  if((temp->parent)->left == temp)
                  {
                   (temp->parent)->left = suc;
                   delete temp;
                   return;
                  }
                  else if((temp->parent)->right == temp)
                  {
                   (temp->parent)->right = suc;
                   delete temp;
                   return;
                  }
             }
             else if((temp->left != NULL)&&(temp->right != NULL))
             {
                  node *suc = temp->right;
                  if(suc->left == NULL)
                  {
                   suc->left = temp->left;
                  }
                  else
                  {
                  while(suc->left != NULL)
                  {
                    suc = suc->left;
                  }
                  suc->left = temp->left;
                  suc->right = temp->right;
                  }
                  if((temp->parent)->left == temp)
                  {
                     (temp->parent)->left = suc;
                  }
                  else if((temp->parent)->right == temp)
                  {
                     (temp->parent)->right = suc;
                  }
                  if((suc->parent)->left == suc)
                  {
                     (suc->parent)->left = NULL;
                  }
                  else if((suc->parent)->right == suc)
                  {
                     (suc->parent)->right = NULL;
                  }
                  delete temp;
                  return;
             }
         }
         if((data < temp->data)&&(temp->left != NULL))
         {
                  del(temp->left,data);
         }
         if((data < temp->data)&&(temp->left == NULL))
         {
                  cout<<"Item not found\n";
                  return;
         }
         if((data > temp->data)&&(temp->right != NULL))
         {
                  del(temp->right,data);
         }
         if((data > temp->data)&&(temp->right == NULL))
         {
                   cout<<"Item not found\n";
                  return;
         }
     }
}

int main()
{
    int ch =1,data;
    while(ch != 4)
    {
             cout<<"\n";
             cout<<"MAIN MENU\n";
             cout<<"1.Insert\n";
             cout<<"2.Delete\n";
             cout<<"3.Display\n";
             cout<<"4.Exit\n";
             cout<<"\nEnter your choice\n";
             cin>>ch;
             switch(ch)
             {
                       case 1:
                            cout<<"\nEnter the data to be inserted\n";
                            cin>>data;
                            insert(root,data);
                            break;
                       case 2:
                            cout<<"\nEnter the data to be deleted\n";
                            cin>>data;
                            del(root,data);
                            break;
                       case 3:
                            cout<<"\n\nDisplaying..\n\n";
                            display(root);
                            break;
                       case 4:
                            break;
                       default:
                               cout<<"\nPlease enter a valid choice\n";
             } 
    }
    getch();
    return 0;
}
