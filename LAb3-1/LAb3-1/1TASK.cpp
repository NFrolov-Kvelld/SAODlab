#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

struct vertex {
    int count;
    int data;
    vertex* left;
    vertex* right;
};

void ObhodUpToDown(vertex* p)
{
    if (p != NULL)
    {
        cout << p->data<<endl;
        ObhodUpToDown(p->left);
        ObhodUpToDown(p->right);
    }
}
void ObhodLeftToRight(vertex* p)
{
    if (p != NULL)
    {
        ObhodLeftToRight(p->left);
        cout << p->data << endl;
        ObhodLeftToRight(p->right);
    }
}
void ObhodDownToUp(vertex* p)
{
    if (p != NULL)
    {
        ObhodDownToUp(p->left);
        ObhodDownToUp(p->right);
        cout << p->data << endl;
    }
}
int size(struct vertex* p) {
    if (p == NULL) return 0;
    else { return 1 + size(p->left) + size(p->right); }
}
int Summa(vertex* p) {
    if (p == NULL) return 0;
    else {
        return p->data + Summa(p->left) + Summa(p->right);
    }
}
int Height(vertex* p) {
    if (p == NULL) return 0;
    else {
        return 1 + max(Height(p->left), Height(p->right));
    }
}
int SummaDlinPutei(vertex* p, int L)
{
    if (p == NULL) return 0;
    else {
        return L + SummaDlinPutei(p->left, L + 1) + SummaDlinPutei(p->right, L + 1);
    }
}

void main()
{
    vertex* root;
    root = (vertex*)malloc(sizeof(vertex));
    root->data = rand() % 21;
    root->count = 1;
    root->left = (vertex*)malloc(sizeof(vertex));
    root->left->data = rand() % 21;
    root->left->count = 2;
    root->right = (vertex*)malloc(sizeof(vertex));
    root->right->data = rand() % 21;
    root->right->count = 3;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->left = (vertex*)malloc(sizeof(vertex));
    root->right->left->data = rand() % 21;
    root->right->left->count = 4;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right= (vertex*)malloc(sizeof(vertex));
    root->right->right->data = rand() % 21;
    root->right->right->count = 5;
    root->right->right->left= (vertex*)malloc(sizeof(vertex));
    root->right->right->left->data = rand() % 21;
    root->right->right->left->count = 6;
    root->right->right->left->left = NULL;
    root->right->right->left ->right = NULL;
    root->right->right->right = NULL;

    ObhodUpToDown(root);
    cout << endl;
    ObhodLeftToRight(root);
    cout << endl;
    ObhodDownToUp(root);
    cout << endl;

    cout << "Size - " << size(root)<<endl;
    cout << "Control - " << Summa(root)<<endl;
    cout << "Height - " << Height(root) << endl;
    float MiddleHeigt = SummaDlinPutei(root, 1) / float(size(root));
    cout << "Medium height - " << MiddleHeigt << endl;


    /* root = (vertex*)malloc(sizeof(vertex));
    root->data = rand() % 21;
    root->count = 1;
    root->left = NULL;
    root->right = (vertex*)malloc(sizeof(vertex));
    root->right->data = rand() % 21;
    root->right->count = 2;
    root->right->right = NULL;

    root->right->left = (vertex*)malloc(sizeof(vertex));
    root->right->left->data = rand() % 21;
    root->right->left->count = 3;

    root->right->left->right = (vertex*)malloc(sizeof(vertex));
    root->right->left->right->data = rand() % 21;
    root->right->left->right->count = 5;
    root->right->left->right->right = NULL;
    root->right->left->right->left = NULL;

    root->right->left->left = (vertex*)malloc(sizeof(vertex));
    root->right->left->left->data = rand() % 21;
    root->right->left->left->count = 4;
    root->right->left->left->left = NULL;

    root->right->left->left->right = (vertex*)malloc(sizeof(vertex));
    root->right->left->left->right->data = rand() % 21;
    root->right->left->left->right->count = 6;
    root->right->left->left->right->right = NULL;
    root->right->left->left->right->left = NULL;
    */
}