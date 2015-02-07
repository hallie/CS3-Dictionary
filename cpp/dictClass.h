#include <string>
#include <iostream>

struct dictEntry {
    std::string word;
    std::string summary;
    std::string definition;
};

struct node {
    dictEntry info;
    node* left;
    node* right;
};

class dictType {
    private:
	node* root;
        void addEntry(dictEntry e, node* leaf);

    public:
        dictType();
        void addEntry(dictEntry e);
	void deleteEntry(std::string word);
	void findEntry(std::string word, node* leaf);
        void print(node* leaf);
};

dictType::dictType() {
    root = NULL;
}

void dictType::addEntry(dictEntry e) {
    if (root == NULL) {
	std::cout << "Setting root to " << e.word << std::endl;
        root = new node;
        root->info = e;
        root->left = NULL;
        root->right = NULL;
    }
    else {
	std::cout << "adding " << e.word << std::endl;
        addEntry(e, root);
    }
}

void dictType::addEntry(dictEntry e, node* leaf) {
    if (e.word < leaf->info.word) {
        if (leaf->left != NULL) {
            addEntry(e, leaf->left);
        }
        else {
            leaf->left = new node;
	    leaf->left->info = e;
	    leaf->left->left = NULL;
	    leaf->left->right = NULL;
	}
    }
    else {
        if (leaf->right != NULL) {
            addEntry(e, leaf->right);
	}
	else {
	    leaf->right = new node;
	    leaf->right->info = e;
	    leaf->right->left = NULL;
	    leaf->right->right = NULL;
	}
    }
}

void dictType::deleteEntry(std::string word) {}

void dictType::findEntry(std::string word, node* leaf) {
    if (leaf != NULL) {
	if (word == leaf->info.word) {
	    print(leaf);
	}
	else if (word < leaf->info.word) {
	    findEntry(word, leaf->left);
	}
	else {
	    findEntry(word, leaf->right);
	}
    }
    else {
	std::cout << "Word not found";
    }
}

void dictType::print(node* leaf) {
    std::cout << leaf->info.word << std::endl;
    std::cout << leaf->info.definition;
}
