#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

struct TreeNode
{
	int key;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) {
		this->key = value;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class BinarySearchTree
{
public:
	BinarySearchTree() {
		this->root = nullptr;
	}

	void insert(int key) {
		root = insertRecursive(root, key);
	}

	TreeNode* insertRecursive(TreeNode* node, int key) {
		if (node == nullptr)
		{
			return new TreeNode(key);
		}

		if (key < node->key)
		{
			node->left = insertRecursive(node->left, key);
		}
		else if (key > node->key)
		{
			node->right = insertRecursive(node->right, key);
		}
		return node;
	}

	void deleteNode(int key) {
		root = deleteRecursive(root, key);
	}

	TreeNode* deleteRecursive(TreeNode* node, int key) {
		if (node == nullptr) return nullptr;
		if (key < node->key)
		{
			node->left = deleteRecursive(node->left, key);
		}
		else if (key > node->key)
		{
			node->right = deleteRecursive(node->right, key);
		}
		else
		{
			if (node->left == nullptr)
			{
				TreeNode* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr)
			{
				TreeNode* temp = node->left;
				delete node;
				return temp;
			}

			TreeNode* temp = findMin(node->right);
			node->key = temp->key;
			node->right = deleteRecursive(node->right, temp->key);
		}
		return node;
	}

	TreeNode* findMin(TreeNode* node) {
		TreeNode* current = node;
		while (current && current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}

	TreeNode* search(int key) {
		return searchRecursive(root, key);
	}

	TreeNode* searchRecursive(TreeNode* node, int key) {
		if (node == nullptr) return nullptr;	// Key not found
		if (key == node->key) return node;	// Key is found so node is returned
		else if (key < node->key) {
			return searchRecursive(node->left, key);
		}
		else {
			return searchRecursive(node->right, key);
		}
	}

	void treeHeight() {
		int height = calculateHeight(root);
		cout << "Tree Height: " << height << endl;
	}

	int calculateHeight(TreeNode* node) {
		if (node == nullptr) return -1;

		int leftHeight = calculateHeight(node->left);
		int rightHeight = calculateHeight(node->right);
		return 1 + max(leftHeight, rightHeight);
	}

	void printTree() {
		printInOrder(root, 0);
	}

	void printInOrder(TreeNode* node, int indent) {
		if (node == nullptr) return;

		printInOrder(node->right, indent + 8);

		cout << endl << endl << setw(indent) << " " << node->key << endl << endl;
		printInOrder(node->left, indent + 8);
	}

private:
	TreeNode* root;

};