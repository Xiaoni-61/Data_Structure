#include "allhead.h"

void count1(char pp[], int ylength) {
	numNode *node = new numNode[ylength];
	int i, j;
	int n = 0;			//字符数
	for (i = 0; i < ylength; i++) {
		node[i].times = 0;
	}
	for (i = 0; i < ylength; i++) {			//计数
		int k = -1;
		for (j = 0; j < ylength; j++) {
			if (pp[i] == node[j].word)
				k = j;
		}
		if (k == -1) {
			node[n].word = pp[i];
			node[n].times++;
			n++;
		}
		else {
			node[k].times++;
		}
	}

	float sum = (float)ylength;					//总字符数

	TNode* tnode = new TNode[2 * n - 1];

	for (i = 0; i < 2 * n - 1; i++) {			//初始化
		tnode[i].flag = "-1";
		tnode[i].left = NULL;
		tnode[i].right = NULL;
		tnode[i].num = '!';
		tnode[i].parent = NULL;
		tnode[i].wight = 0;
	}
	for (i = 0; i < n; i++) {
		tnode[i].num = node[i].word;
		tnode[i].wight = node[i].times;
	}
	//TNode *tnode1,*tnode2;

	
	int weightsmaller1, weightsmaller2;

	for (i = n; i < (2 * n - 1); i++) {
		int k = 0;
		while (1) {
			if (tnode[k].parent == NULL)
				break;
			k++;
		}
		weightsmaller1 = k;
		weightsmaller2 = k;
		int q = sum;
		int p = sum;
		for (j = 0; j < i; j++) {
			if (tnode[j].wight <= q && (tnode[j].parent == NULL)) {
				q = tnode[j].wight;
				weightsmaller1 = j;
			}
		}
		for (j = 0; j < i; j++) {
			if (tnode[j].wight <= p &&(weightsmaller1!=j)&& (tnode[j].parent == NULL)) {
				p = tnode[j].wight;
				weightsmaller2 = j;
			}
		}


		tnode[weightsmaller1].parent = &tnode[i];
		tnode[weightsmaller2].parent = &tnode[i];
		tnode[weightsmaller1].flag = "0";
		tnode[weightsmaller2].flag = "1";
		tnode[i].left = &tnode[weightsmaller1];
		tnode[i].right = &tnode[weightsmaller2];
		tnode[i].wight = tnode[weightsmaller1].wight + tnode[weightsmaller2].wight;

	}

	string *s=new string[n];
	TNode *tem;
	for (i = 0; i < n; i++) {
		tem = &tnode[i];
		while (1) {
			s[i] = tem->flag + s[i];
			tem = tem->parent;
			if (tem->parent == NULL)
				break;
		}
		tnode[i].code = s[i];
	}
	for (i = 0; i < n; i++) {
		float c = node[i].times / sum;
		tnode[i].flu = c;
		
	}


	for ( i = 0; i < n - 1; i++)
		for ( j = 0; j < n - i - 1; j++)
		{
			if (tnode[j].flu < tnode[j + 1].flu) // 这里是从大到小排序，如果是从小到大排序，只需将“<”换成“>”
			{
				TNode temp;
				temp = tnode[j];
				tnode[j] = tnode[j + 1];
				tnode[j + 1] = temp;
			}
		}



	for (i = 0; i < n; i++) {
		cout.setf(ios::fixed);
		cout << tnode[i].num << ":" << fixed << setprecision(2) << tnode[i].flu << ":" << tnode[i].code << endl;
	}

}