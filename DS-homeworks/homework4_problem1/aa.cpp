#include"allhead.h"

void construct(int v, int e, VtoV *ss)
{
	int i, j, min, k;
	int **gragh = new int*[v];

	for (i = 0; i < v; i++) {

		gragh[i] = new int[v];

	}
	for (i = 0; i < v; i++) {			//初始化
		for (j = 0; j < v; j++) {
			if (i == j) {
				gragh[i][j] = 0;
			}
			else
			{
				gragh[i][j] = 999;
			}
		}
	}

	for (i = 0; i < e; i++) {
		gragh[ss[i].from][ss[i].to] = ss[i].weight;
	}

	int *preV = new int[v];				//记录该顶点的前一个顶点
	int *sumWeight = new int[v];		//现在的从原点到此点的最小权重

	int *final = new int[v];			//记录该点是否到达

	for (i = 0; i < v; i++) {
		final[i] = 0;
		sumWeight[i] = gragh[0][i];
		preV[i] = 0;

	}

	final[0] = 1;

	for (i = 1; i < v; i++) {
		min = 999;
		k = 0;
		for (j = 0; j < v; j++) {
			if ((final[j] == 0) && sumWeight[j] < min) {
				min = sumWeight[j];
				k = j;
			}
		}

		final[k] = 1;

		for (j = 0; j < v; j++) {
			if ((final[j] == 0) && ((min + gragh[k][j]) < sumWeight[j])) {
				sumWeight[j] = min + gragh[k][j];
				preV[j] = k;
			}
		}

	}
	string *p = new string[v];
	int ii=0;
	for (i = 1; i < v; i++) {
		j = i;
		ii = i;
		if (sumWeight[i] == 999) {
			p[i] = "-";
		}
		else {
			while (1) {
				
				p[i] =  "-" +to_string(ii)+p[i] ;
				ii = preV[ii];
				if (sumWeight[ii] == 0) {
					break;
				}
			}
			
		}
		i = j;
		if (p[i] == "-") {
			cout << "0-" << to_string(i) << " " << sumWeight[i] << " " << p[i] << endl;
		}
		else {
			cout << "0-" << to_string(i) << " " << sumWeight[i] << " 0" << p[i] << endl;
		}
		
	}


}