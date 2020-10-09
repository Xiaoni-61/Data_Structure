#include"allhead.h"

void construct(int v,int e,VtoV *ss) 
{
	int i, j;
	int **gragh=new int*[v];
	
	for (i = 0; i < v; i++) {

		gragh[i] = new int[v];

	}
	for (i = 0; i < v; i++) {			//��ʼ��
		for (j = 0; j < v; j++) {
			if (i == j) {
				gragh[i][j] = 0;
			}
			else
			{
				gragh[i][j] = 9999;
			}
		}
	}

	for (i = 0; i < e; i++) {
		gragh[(int)(ss[i].from - 'A')][(int)(ss[i].to - 'A')] = ss[i].weight;
		gragh[(int)(ss[i].to - 'A')][(int)(ss[i].from - 'A')] = ss[i].weight;
	}
	
	/*
	for (i = 0; i < v; i++) {
		for (j = 0; j < v; j++) {
			printf("%5d", gragh[i][j]);
		}
		printf("\n");
	}
	*/
	
	
	
	VtoV *end = new VtoV[v];		//�����ս��

	int min, ii, jj, kk;
	int *underline=new int[v];		//��ض����±�
	int *lowcost = new int[v];		//��ʱ�ܴﵽ������Ȩ��

	lowcost[0] = 0;
	underline[0] = 0;

	for (ii = 1; ii < v; ii++) {		//��ʼ��
		lowcost[ii] = gragh[0][ii];
		underline[ii] = 0;
	}

	for (ii = 1; ii < v; ii++) {
		min = 9999;
		
		kk = 0;
		for (jj = 1; jj < v; jj++) {
			if (lowcost[jj] != 0 && lowcost[jj] < min) {
				min = lowcost[jj];
				kk = jj;
			}
		}

		end[ii-1].from = underline[kk];
		end[ii-1].to = kk;
		end[ii-1].weight = lowcost[kk];
		lowcost[kk] = 0;

		for (jj = 1; jj < v; jj++) {					//������µ����������Сֵ
			if (lowcost[jj] != 0 && gragh[kk][jj] < lowcost[jj]) {		
				lowcost[jj] = gragh[kk][jj];			
				underline[jj] = kk;
			}
		}
	}

	for (i = 0; i < v-1; i++) {							//��һ������(from,to�н�С�ķ���ǰ��)
		if (end[i].from > end[i].to) {
			char a = end[i].from;
			end[i].from = end[i].to;
			end[i].to = a;
		}
	}


	for (i = 0; i < v - 2; i++)							//��from��˳������
	{
		for (j = 0; j < v - 2 - i; j++)
		{
			if (end[j].from > end[j + 1].from)
			{
				VtoV temp = end[j];
				end[j] = end[j + 1];
				end[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < v - 1; i++) {							//��ͬfrom ��ͷ��������
		int k = 0;
		char aa = end[i].from;
		for (j = i; j < v - 1; j++) {
			if (aa != end[j].from) {
				break;
			}
			k++;
		}


		if (k == 2) {
			if (end[i].to > end[i + 1].to) {
				VtoV temp = end[i];
				end[i] = end[i + 1];
				end[i + 1] = temp;
			}
		}
		else if (k > 2) {
			int i1, i2;
			for (i1 = i; i1 < k+i-1; i1++)							//��from��˳������
			{
				for (i2 = i; i2 < k+i - 1 - i1; i2++)
				{
					if (end[i2].to > end[i2 + 1].to)
					{
						VtoV temp = end[i2];
						end[i2] = end[i2 + 1];
						end[i2 + 1] = temp;
					}
				}
			}


		}
	}

	for (i = 0; i < v - 1; i++) {
		cout << (char)(end[i].from + 'A') << "-" << (char)(end[i].to + 'A') << "-" << end[i].weight<<endl;
	}


}