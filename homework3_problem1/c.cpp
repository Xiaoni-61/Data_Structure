#include"stdafx.h"
using namespace std;


void frontdisplay(TNode* tree) {
	if (tree != NULL) {
		cout << tree->num;
		frontdisplay(tree->left);
		frontdisplay(tree->right);
	}
}


void enddisplay(TNode* tree) {
	if (tree != NULL) {
		enddisplay(tree->left);
		enddisplay(tree->right);
		cout << tree->num;
	}
}

void middisplay(TNode* tree) {
	if (tree != NULL) {
		if ((tree->num == ')' || tree->num == '+' || tree->num == '-' || tree->num == '*' || tree->num == '/' || tree->num == '(')&&pri(tree->left->num) < pri(tree->num)) {
			
			if (tree->left->num >= '0'&&tree->left->num <= '9') {
				middisplay(tree->left);
			}
			else {
				cout << "(";
				middisplay(tree->left);
				cout << ")";
			}
		
		}
		else {
			middisplay(tree->left);
		}

		cout << tree->num;

		if ((tree->num == ')' || tree->num == '+' || tree->num == '-' || tree->num == '*' || tree->num == '/' || tree->num == '(')&&pri(tree->right->num) < pri(tree->num)) {
			if (tree->right->num >= '0'&&tree->right->num <= '9') {
				middisplay(tree->right);
			}
			else {
				cout << "(";
				middisplay(tree->right);
				cout << ")";
			}
			
		}
		else {
			middisplay(tree->right);
		}


	}
}



int pri(char s) {
	int a;
	switch (s)
	{
	case '(':a = 1; break;
	case '+':a = 2; break;
	case '-':a = 2; break;
	case '*':a = 3; break;
	case '/':a = 3; break;
	case ')':a = 4; break;
	default:
		a = 0;
		break;
	}
	return a;
}