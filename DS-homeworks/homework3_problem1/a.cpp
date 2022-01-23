#include"stdafx.h"


using namespace std;


bool midtoend(TNode*& p,char pp[]) {
	char top1;						//得到栈顶元素
	char g[100];
	mystack <char > stk(20);
	int ii = 0;
	int jj = 0;
	while (pp[ii] != '\n') {

		stk.top(top1);

		if (stk.pri(pp[ii]) == 0) {

			g[jj] = pp[ii];
			jj++;

		}
		else if (stk.m_top == -1 && stk.pri(pp[ii]) > 0) {
			stk.push(pp[ii]);
		}
		else if (stk.pri(pp[ii]) == 4) {
			char tempop;

			while (stk.top(tempop), tempop != '(') {
				if (stk.m_top == -1) {
					cout << "Wrong!" << endl;
					system("pause");
					return 0;
				}

				char aa;
				stk.pop(aa);

				g[jj] = aa;
				jj++;

			}
			stk.pop(tempop);
		}
		else if (stk.pri(top1) < stk.pri(pp[ii]) || stk.pri(pp[ii]) == 1) {
			stk.push(pp[ii]);
		}



		else if (stk.pri(top1) >= stk.pri(pp[ii])) {
			char tempop;
			stk.pop(tempop);
			stk.push(pp[ii]);
			g[jj] = tempop;
			jj++;


		}

		ii++;

	}
	while (stk.m_top != -1) {
		char aaa;
		stk.pop(aaa);
		g[jj] = aaa;
		jj++;


	}
	/*
	printf("\n");						//调试输出
	for (int i = 0; i < jj; i++) {
		cout << g[i];
	}
	*/
	
	
	end2tree(p, g,jj);



	return true;
}

