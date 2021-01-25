#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__
//implementation of templated class binary search tree

#include <vector>
#include <functional>

enum traversalType { preOrder, inOrder, postOrder };

template <class KEY, class DATA>
class binarySearchTree {
private:
	struct node {
		KEY key;
		node* leftSuccessor;
		node* rightSuccessor;
		DATA data;

		//automatically choose left or right
		void addSuccessor(node* newNode) {
			if (newNode->key < this->key)
				if (this->leftSuccessor)
					this->leftSuccessor->addSuccessor(newNode);
				else
					this->leftSuccessor = newNode;
			else
				if (this->rightSuccessor)
					this->rightSuccessor->addSuccessor(newNode);
				else
					this->rightSuccessor = newNode;
		}
		node(const KEY& key, const DATA& data) {
			leftSuccessor = rightSuccessor = NULL;
			this->key = key;
			this->data = data;
		}
	};

	node* root;
public:
	// construct/destruct:
	binarySearchTree() {
		root = NULL;
	}
	~binarySearchTree() {
		clear();
	}

	// public methods:
	DATA* search(const KEY& key) {//Depth first
		node* tmp;
		if (this->root)
			return &(searchPRVT(key, this->root, tmp)->data);
		else
			return NULL;
	}

	//std::function used instead of raw pointer to be able to pass capturing lambdas
	
	//uses func(DATA&, KEY) on each node in traversal order(pre-, post-, in- fix)
	void forEach(traversalType traversal, std::function<void(DATA&, KEY)> func) { 
		switch (traversal) {
		case preOrder:
			forEachPreOrder(func, this->root);
			break;
		case inOrder:
			forEachInOrder(func, this->root);
			break;
		case postOrder:
			forEachPostOrder(func, this->root);
			break;
		}
	}

	//uses func(DATA&, KEY) on each node in level left to right
	void forEachInLevel(int level, std::function<void(DATA&, KEY)> func) {
		forEachInLevelPRVT(level, func, this->root);
	}

	int height() {
		return heightPRVT(this->root);
	}

	//deletes all nodes
	void clear() {
		clearPRVT(root);
		root = NULL;
	}

	void addNode(const DATA& data, const KEY& key) {
		node* newNode = new node(key, data);
		if (this->root)
			this->root->addSuccessor(newNode);
		else
			this->root = newNode;
	}

	//find and delete node by key
	void deleteNode(const KEY& value) {
		node* predecessor = root, * newNode;
		node* deletable = searchPRVT(value, this->root, predecessor);
		if (!deletable)
			return;//pass
		else if (deletable->rightSuccessor && deletable->leftSuccessor) {
			int predecessorHeight = 0;
			node* inOrderPredecessor = deletable->rightSuccessor;
			while (inOrderPredecessor->leftSuccessor) {
				inOrderPredecessor = inOrderPredecessor->leftSuccessor;
				predecessorHeight++;
			}
			int successorHeight = 0;
			node* inOrderSuccessor = deletable->leftSuccessor;
			while (inOrderSuccessor->rightSuccessor) {
				inOrderSuccessor = inOrderSuccessor->rightSuccessor;
				successorHeight++;
			}
			newNode = (successorHeight > predecessorHeight) ? inOrderSuccessor : inOrderPredecessor;//take the one from lowest level
			searchPRVT(newNode->key, this->root, predecessor);//predecessor of newNode
			deletable->key = newNode->key;//replace key&value in deletable with ones from newNode
			deletable->data = newNode->data;
			deletable = newNode;//to delete out of if
			newNode = NULL;
		}
		else//one or no sucessors
			newNode = !deletable->rightSuccessor ? deletable->leftSuccessor : deletable->rightSuccessor;//choosing single available successor or NULL
		disconnect(predecessor, deletable, newNode);
		delete deletable;
	}
private:
	//replaces succesor of predecessor with newSuccessor
	void disconnect(node* predecessor, node* successor, node* newSuccessor) {
		if (predecessor->leftSuccessor == successor)
			predecessor->leftSuccessor = newSuccessor;
		else if (predecessor->rightSuccessor == successor)
			predecessor->rightSuccessor = newSuccessor;
	}

	void clearPRVT(node* currentNode) {
		if (!currentNode)
			return;
		if (currentNode->leftSuccessor)
			clearPRVT(currentNode->leftSuccessor);
		if (currentNode->rightSuccessor)
			clearPRVT(currentNode->rightSuccessor);
		delete currentNode;
	}

	node* searchPRVT(const KEY& key, node* currentNode, node*& predcessor) {
		if (currentNode->key == key)
			return currentNode;
		else if (key < currentNode->key)
			if (currentNode->leftSuccessor) {
				predcessor = currentNode;
				return searchPRVT(key, currentNode->leftSuccessor, predcessor);
			}
			else
				return NULL;
		else //if (key > currentNode->key)
			if (currentNode->rightSuccessor) {
				predcessor = currentNode;
				return searchPRVT(key, currentNode->rightSuccessor, predcessor);
			}
			else
				return NULL;
	}

	void forEachPreOrder(std::function<void(DATA&, KEY)> func, node* currentNode) {
		if (!currentNode)
			return;
		func(currentNode->data, currentNode->key);
		if (currentNode->leftSuccessor)
			forEachPreOrder(func, currentNode->leftSuccessor);
		if (currentNode->rightSuccessor)
			forEachPreOrder(func, currentNode->rightSuccessor);
	}

	void forEachInOrder(std::function<void(DATA&, KEY)> func, node* currentNode) {
		if (!currentNode)
			return;
		if (currentNode->leftSuccessor)
			forEachInOrder(func, currentNode->leftSuccessor);
		func(currentNode->data, currentNode->key);
		if (currentNode->rightSuccessor)
			forEachInOrder(func, currentNode->rightSuccessor);
	}

	void forEachPostOrder(std::function<void(DATA&, KEY)> func, node* currentNode) {
		if (!currentNode)
			return;
		if (currentNode->leftSuccessor)
			forEachPostOrder(func, currentNode->leftSuccessor);
		if (currentNode->rightSuccessor)
			forEachPostOrder(func, currentNode->rightSuccessor);
		func(currentNode->data, currentNode->key);
	}

	void forEachInLevelPRVT(int level, std::function<void(DATA&, KEY)> func, node* currentNode) {
		if (!currentNode || level < 1)
			return;
		else if (level == 1)
			func(currentNode->data, currentNode->key);
		else//level > 1
			if (currentNode->leftSuccessor)
				forEachInLevelPRVT(level - 1, func, currentNode->leftSuccessor);
			if (currentNode->rightSuccessor)
				forEachInLevelPRVT(level - 1, func, currentNode->rightSuccessor);
	}

	int heightPRVT(node* currentNode) {
		if (!currentNode)
			return 0;
		else {
			int lheight = heightPRVT(currentNode->leftSuccessor);
			int rheight = heightPRVT(currentNode->rightSuccessor);
			return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
		}
	}
};
#endif