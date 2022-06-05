#include "BST.h"
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

Node* BST::FindNode(int k)
{
    Node *cur = Root;
    while (cur != nullptr) {
        if (cur->val == k) return cur;
        if (k < cur->val) cur = cur->Leftchild;
        else cur = cur->Rightchild;
    }

    return nullptr;
}

void BST::AddNode(int k)
{
    if (Root == nullptr) Root = new Node({k, 0, nullptr, nullptr, nullptr});
    else {
        Node *cur = Root;
        while (1) {
            if (k == cur->val) return;
            if (k < cur->val) {
                if (cur->Leftchild == nullptr) {
                    cur->Leftchild = new Node({k, 1, cur, nullptr, nullptr});
                    return;
                }

                cur = cur->Leftchild;
            }

            if (k > cur->val) {
                if (cur->Rightchild == nullptr) {
                    cur->Rightchild = new Node({k, 0, cur, nullptr, nullptr});
                    return;
                }

                cur = cur->Rightchild;
            }
        }
    }
}

void BST::DeleteNode(int k)
{
    Node *cur = Root;
    while (cur != nullptr) {
        if (cur->val == k) {
            if (cur->Leftchild == nullptr && cur->Rightchild == nullptr) {
                if (cur->isleft && cur->Parent)
                    cur->Parent->Leftchild = nullptr;
                if (!cur->isleft && cur->Parent)
                    cur->Parent->Rightchild = nullptr;

                if (cur == Root) Root = nullptr;
                delete cur;

                return;
            }

            if (cur->Leftchild == nullptr) {
                if (cur->isleft && cur->Parent) cur->Parent->Leftchild = cur->Rightchild, cur->Rightchild->isleft = 1;
                if (!cur->isleft && cur->Parent) cur->Parent->Rightchild = cur->Rightchild;
                cur->Rightchild->Parent = cur->Parent;
                delete cur;
                return;
            }

            if (cur->Rightchild == nullptr) {
                if (cur->isleft && cur->Parent) cur->Parent->Leftchild = cur->Leftchild;
                if (!cur->isleft && cur->Parent) cur->Parent->Rightchild = cur->Leftchild, cur->Leftchild->isleft = 0;
                cur->Leftchild->Parent = cur->Parent;
                delete cur;
                return;
            }

            Node *RightMost = cur->Leftchild;
            while (RightMost->Rightchild) RightMost = RightMost->Rightchild;

            if (RightMost != cur->Leftchild) {

                RightMost->Parent->Rightchild = RightMost->Leftchild;

                if (RightMost->Leftchild) {
                    RightMost->Leftchild->Parent = RightMost->Parent;
                    RightMost->Leftchild->isleft = 0;
                }

                RightMost->Leftchild = cur->Leftchild;
                RightMost->Leftchild->Parent = RightMost;
            }

            RightMost->Rightchild = cur->Rightchild;
            RightMost->Rightchild->Parent = RightMost;

            if (cur->Parent) {
                if (cur->isleft) cur->Parent->Leftchild = RightMost;
                else cur->Parent->Rightchild = RightMost;
            }

            RightMost->isleft = cur->isleft;
            RightMost->Parent = cur->Parent;

            delete cur;
            return;
        }
        if (k < cur->val) cur = cur->Leftchild;
        else cur = cur->Rightchild;
    }
}

void BST::Output(Node *cur) {
    if (cur == nullptr) return;
    Output(cur->Leftchild);
    cout << cur->val << " ";
    Output(cur->Rightchild);
}

void BST::Traverse() {
    Output(Root);
}

Node* BST::FindClosest(int x) {
    return _FindClosest(Root, x);
}

Node* BST::_FindClosest(Node *cur, int x) {
    if (cur == nullptr) return nullptr;

    Node *res = nullptr;
    if (cur->val > x)
        res = _FindClosest(cur->Leftchild, x);
    else res = _FindClosest(cur->Rightchild, x);

    if (res == nullptr) return cur;

    return (abs(cur->val - x) < abs(res->val - x)) ? cur : res;
}

