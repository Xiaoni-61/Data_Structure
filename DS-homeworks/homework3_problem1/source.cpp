#include"stdafx.h"

using namespace std;

int main() {

	TNode* tr=NULL;					//ǰ��������ʽ��������
	
	char pp[100];					//������ַ�����
	int ii = -1;							//�����ַ��������

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


	//system("pause");				//�����뻷���Ƿ���Ҫ��
}

