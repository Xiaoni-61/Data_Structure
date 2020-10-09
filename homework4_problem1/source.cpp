#include"allhead.h"

int main()
{
	int vertex, edge;
	cin >> vertex;
	cin >> edge;

	VtoV *ss = new VtoV[edge];

	for (int i = 0; i < edge; i++) {
		cin >> ss[i].from;
		cin >> ss[i].to;
		cin >> ss[i].weight;
	}

	construct(vertex, edge, ss);

	//system("pause");
	return 0;
}