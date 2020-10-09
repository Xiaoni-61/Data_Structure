#pragma once
#include"stdafx.h"
#include"mytree.h"

//a  中序转后序
bool midtoend(TNode*& p,char pp[]);



//b 前后序加进树中
void end2tree(TNode*& p, char g[], int n);
void front2tree(TNode*& p, char g[], int n);


//c 前中后序的显示方法
void frontdisplay(TNode* tree);
void enddisplay(TNode* tree);
int pri(char s);
void middisplay(TNode* tree);