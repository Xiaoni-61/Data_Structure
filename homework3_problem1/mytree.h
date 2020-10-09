#pragma once
class TNode
{
public:
	char num;			//节点数据
	TNode* left;
	TNode* right;
	int s; int t;//计算树的层数使用
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