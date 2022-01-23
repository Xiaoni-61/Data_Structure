#include"stdafx.h"

using namespace std;

int main() {

	TNode* tr=NULL;					//前、后序表达式构建的数
	
	char pp[100];					//输入的字符数组
	int ii = -1;							//输入字符数组计数

	int flag;
	cin >> flag;					//

	getchar();

	while (pp[ii] != '\n') {
		ii++;
		pp[ii] = getchar();
		
	}


	if (flag == 2) {
		midtoend(tr,pp);
	}
	else if (flag == 3) {
		end2tree(tr, pp, ii);
	}
	else if (flag == 1) {
		front2tree(tr, pp, ii);
	}


	frontdisplay(tr);
	cout <<  endl;

	middisplay(tr);

	cout <<  endl;
	enddisplay(tr);


	//system("pause");				//看编译环境是否需要！
}

