#pragma once
struct TNode
{
	int data;
	TNode *right, *left;
};

TNode* Create(int data);
void Insert(TNode* root, TNode* node);
TNode* GenerateTree(int size);
int NumOfLevels(TNode* tree);
int NumOnTheLevel(TNode* tree, int n, int level, int num);
void PrintLevel(TNode* tree, int n, int level);
void PrintTree(TNode* tree);