#pragma once
class TNode
{
public:
	char num;			//�ڵ�����
	TNode* left;
	TNode* right;
	int s; int t;//�������Ĳ���ʹ��
	TNode()
	{
		left = right = NULL;
		num = 0;
	}
	TNode(char op)
	{
		left = right = NULL;
		num = op;
	}
};