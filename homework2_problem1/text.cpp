#include<iostream>
#include"mystack.h"
#include<stdlib.h>

using namespace std;

int culnum(int a, int b, char x) {
	switch (x)
	{
	case '+':return a + b; break;
	case '-':return a - b; break;
	case '*':return a * b; break;
	case '/':return a / b; break;


	default:
		break;
	}
}

int cul(char a[],int n) {

	mystack <int > stk1(20);

	for (int i = 0; i < n; i++) {
		if (a[i] >= '0'&&a[i] <= '9') {
			stk1.push(a[i]-'0');
		}
		else {
			int aa, bb;					//a为第一操作数，b为第二操作数
			stk1.pop(bb);
			stk1.pop(aa);

			stk1.push(culnum(aa, bb, a[i]));
		}

	}
	int enddd;
	stk1.pop(enddd);
	return enddd;
}



int main() {
	
	char pp;
	char top1;						//得到栈顶元素

	char g[100];					//后序表达式总字符串
	int jj=0;							//后序表达式计数

	int size1;


	
	mystack <char > stk(20);		//

	while (pp = getchar(), pp != '\n') {

		stk.top(top1);

		if (stk.pri(pp) == 0) {

			g[jj] = pp;
			jj++;
			cout << pp;
		}
		else if (stk.m_top == -1 && stk.pri(pp) > 0) {
			stk.push(pp);
		}
		else if (stk.pri(pp) == 4) {
			char tempop;

			while (stk.top(tempop), tempop != '(') {
				if (stk.m_top == -1) {
					cout << "Wrong!" << endl;
					system("pause");
					return 0;
				}

				char aa;
				stk.pop(aa);

				g[jj] =  aa;
				jj++;

				cout << aa;
			}
			stk.pop(tempop);
		}
		else if (stk.pri(top1) < stk.pri(pp)||stk.pri(pp)==1) {
			stk.push(pp);
		}
		


		else if (stk.pri(top1) >= stk.pri(pp)) {
			char tempop;
			stk.pop(tempop);
			stk.push(pp);
			g[jj] = tempop;
			jj++;

			cout << tempop ;
		}

	}
	while (stk.m_top != -1) {
		char aaa;
		stk.pop(aaa);
		g[jj] =  aaa;
		jj++;

		cout << aaa ;
	}
	/*
	printf("\n");
	for (int i = 0; i < jj; i++) {
		cout << g[i];
	}
	*/
	
	
	int num = cul(g,jj);
	
	printf("\n%d\n", num);

	//system("pause");				//看编译环境是否需要！
}


