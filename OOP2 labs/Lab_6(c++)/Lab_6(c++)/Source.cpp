#include <iostream>
#include "Header.h"
using namespace std;

TNode* Create(int data)
{
	TNode* node = new TNode;
	node->data = data;
	node->right = NULL;
	node->left = NULL;
	return node;
}

void Insert(TNode* root, TNode* node)
{
	if (node->data < root->data) {
		if (root->left != NULL) {
			Insert(root->left, node);
		}
		else {
			root->left = node;
		}
	}
	else {
		if (root->right != NULL) {
			Insert(root->right, node);
		}
		else {
			root->right = node;
		}
	}
}

TNode* GenerateTree(int size)
{
	srand((unsigned int)time(NULL));
	TNode* tree = Create(rand() % 90 + 10);
	for (int i = 1; i < size; i++) {
		Insert(tree, Create(rand() % 90 + 10));
	}
	return tree;
}

int NumOfLevels(TNode* tree)
{
	if (tree == NULL) {
		return 0;
	}
	return max(NumOfLevels(tree->right), NumOfLevels(tree->left)) + 1;
}

void PrintTree(TNode* tree)
{
	if (tree == NULL) {
		return;
	}
	cout << tree->data << " ";
	PrintTree(tree->right);
	PrintTree(tree->left);

}

int NumOnTheLevel(TNode* tree, int n, int level, int num)
{
	if (tree == NULL) {
		return num;
	}
	if (level++ == n) {
		num++;
	}
	num = NumOnTheLevel(tree->left, n, level, num);
	num = NumOnTheLevel(tree->right, n, level, num);
	return num;
}

void PrintLevel(TNode* tree, int n, int level) 
{
	if (tree == NULL) {
		return;
	}
	if (level++ == n) {
		cout << tree->data << " ";
	}
	PrintLevel(tree->right, n, level);
    PrintLevel(tree->left, n, level);

}