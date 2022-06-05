#pragma once

using namespace std;

const int oo = 1e9;

struct Node
{
    int val;
    bool isleft = 0;
    Node *Parent = nullptr;
    Node *Leftchild = nullptr;
    Node *Rightchild = nullptr;
};

struct BST
{
    Node *Root = nullptr;

    Node *FindNode(int k);
    void AddNode(int k);
    void DeleteNode(int k);
    void Output(Node *cur);
    void Traverse();
    Node *FindClosest(int x);
    Node *_FindClosest(Node *cur, int x);
};
