#pragma once
#include "allhead.h"

using namespace std;


class TNode
{
public:
	char num;			//�ڵ�����
	TNode* left;
	TNode* right;
	TNode* parent;

	int wight;			//Ȩ��

	string flag;		//����ʱ��
	float flu = 0.0;
	string code;


	TNode()
	{
		parent=left = right = NULL;
		num = 0;
	}
	TNode(char op)
	{
		parent=left = right = NULL;
		num = op;

	}
	TNode(char op, int w) {
		parent=left = right = NULL;
		num = op;
		wight = w;
		flag = "-1";
	}
};

struct numNode {
	char word;
	int times;
};