#include<iostream>
#include<string>
#include <cstring>
using namespace std;
enum Tag {
	LINK, THREAD
};
 
class Node {
public:
	char data;
	Node* left;
	Node* right;
	Tag lTag;
	Tag rTag;
	Node(const char &c):data(c),left(NULL),right(NULL),lTag(LINK),rTag(LINK){}
};
 
class Tree {
private:
	Node* root;
//	int i = 0;
public:
	void traverse(){
		Node* cur = root;
		while (cur) {
			while (cur&&cur->lTag != THREAD) {
				cur = cur->left;
			}
			cout << cur->data << ' ';
			while (cur&&cur->rTag == THREAD) {
				cur = cur->right;
				cout << cur->data << ' ';
			}
			if (cur) {
				cur = cur->right;
			}
		}
	}
 
	Tree(const char* s){
		createTree(root, s);
	}
 
	void threadTree() {
		Node* pre = NULL;
		carryOutThread(root, pre);
		//cout << i;
	}
	
protected:
	void createTree(Node* &root, const char* &s) {
		if (*s != ' '&&*s != '\0') {
			root = new Node(*s);
			//i++;
			createTree(root->left, ++s);
			if (*s != '\0')
				createTree(root->right, ++s);
		}
	}
 
	void carryOutThread(Node* &root, Node* &pre) {
		if (root) {
			carryOutThread(root->left, pre);
			if (root->left == NULL) {
				root->lTag = THREAD;
				root->left = pre;
			}
			if (pre&&pre->right == NULL) {
				pre->rTag = THREAD;
				pre->right = root;
			}
			pre = root;
			carryOutThread(root->right, pre);
		}
	}
};
 
int main() {
	string s;
	getline(cin, s);
	char ss[100];
	strcpy(ss, s.c_str());
	Tree t(ss);
	t.threadTree();
	t.traverse();
	return 0;
}