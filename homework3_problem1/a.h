#pragma once
#include"stdafx.h"
#include"mytree.h"

//a  ����ת����
bool midtoend(TNode*& p,char pp[]);



//b ǰ����ӽ�����
void end2tree(TNode*& p, char g[], int n);
void front2tree(TNode*& p, char g[], int n);


//c ǰ�к������ʾ����
void frontdisplay(TNode* tree);
void enddisplay(TNode* tree);
int pri(char s);
void middisplay(TNode* tree);