#include"stdafx.h"


using namespace std;
void end2tree(TNode*& p, char g[], int n) {

	mystack <TNode* > stk1(20);
	for (int i = 0; i < n; i++) {

		if (g[i] >= '0'&&g[i] <= '9') {
			p = new TNode(g[i]);
			stk1.push(p);
		}
		else {
			p = new TNode(g[i]);

			TNode* p1 = new TNode();
			TNode* p2 = new TNode();

			stk1.pop(p1);
			p->right = p1;

			stk1.pop(p2);
			p->left = p2;

			stk1.push(p);


		}
	}

}

void front2tree(TNode*& p, char g[], int n) {

	mystack <TNode* > stk1(20);

	for (int i = (n-1); i >= 0; i--) {

		if (g[i] >= '0'&&g[i] <= '9') {
			p = new TNode(g[i]);
			stk1.push(p);
		}
		else {
			p = new TNode(g[i]);

			TNode* p1 = new TNode();
			TNode* p2 = new TNode();

			stk1.pop(p1);
			p->right = p1;

			stk1.pop(p2);
			p->left = p2;

			stk1.push(p);


		}
	}


}
