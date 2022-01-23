#pragma once
#include "head.h"
#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;

int main()
{

	int n, s, m;	//n为总人数，s起始位置，m间隔

	cin >> n;
	cin >> s;
	cin >> m;

	int x = 1;
	Node *p = NULL, *h = NULL, *r = NULL;
	while (x <= n) {
		p = (Node*)malloc(sizeof(Node));
		p->data = x;
		if (h == NULL)
		{
			h = p;
			r = p;
		}
		else {
			r->next = p;
			r = p;
		}


		x++;
	}
	p->next = h;

	p = h;

	/*
		while (p != NULL) {
			printf("%d", p->data);
			p = p->next;
		}
		*/

	int i = 1;
	while (i < s) {
		p = p->next;
		i++;
	}
	Node *a;

	int iii = 1;
	while (iii <= n) {
		for (int i = 1; i < (m - 1); i++) {
			p = p->next;
		}

		if (m == 1) {
			while (p->next != h) {
				p = p->next;
			}
			printf("%d", p->next->data);
			p->next = p->next->next;
			h = p->next;
		}
		else {
			a = p;
			printf("%d", a->next->data);
			a->next = a->next->next;
		}



		for (int i = 1; i < m; i++) {
			p = p->next;
		}
		iii++;
		if (iii <= n)
			printf(" ");
	}

	//system("pause");
}


