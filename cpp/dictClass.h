#include <string>
#include <iostream>

struct dictEntry {		//Creating a type to hold dictionary entries
    std::string word;		//  The dictionary word
    std::string pronunciation;	//  The pronunciation
    std::string definition;	//  The definition
};

struct node {			//Creating the node type
    dictEntry info;		//  Holds the dictionary entry
    node *left;			//  The left child of the entry
    node *right;		//  The right child of the entry
};

class dictType {		//Creating a class to hold all of the entries
    private:
	node *root;				//The root of the tree
        void addEntry(node *e, node *leaf);	//The recursive function for
						//  adding to the tree
	node *findEntry(std::string word, node *leaf);
        void print(node *leaf);
    public:
        dictType();
        void addEntry(dictEntry e);		//Calls to add entry from main
	void deleteEntry(std::string word);	//Calls to delete from main
	void findEntry(std::string word); 	//Calls find from main
};

dictType::dictType() {
    root = NULL;	//Sets the root to NULL upon initialization
}

void dictType::addEntry(dictEntry e) {
    if (root == NULL) {
        root = new node;
        root->info = e;
        root->left = NULL;
        root->right = NULL;
    }
    else {
        node *entry = new node;
        entry->info = e;
        entry->left = NULL;
        entry->right = NULL;
        addEntry(entry, root);
    }
}

void dictType::addEntry(node *e, node *leaf) {
    if (e->info.word < leaf->info.word) {
        if (leaf->left != NULL) {
            addEntry(e, leaf->left);
        }
        else {
	    leaf->left = e;
	}
    }
    else {
        if (leaf->right != NULL) {
            addEntry(e, leaf->right);
	}
	else {
	    leaf->right = e;
	}
    }
}

void dictType::deleteEntry(std::string word) {
    node *hold;
    hold = findEntry(word, root);
    if (hold->left != NULL) {
        print(hold->left);
	addEntry(hold->left, root);
    }
    if (hold->right != NULL) {
	print(hold->right);
	addEntry(hold->right, root);
    }
    delete hold;
}

void dictType::findEntry(std::string word) {
    if (root != NULL) {
        node *entry = new node;
	entry = findEntry(word, root);
        if (entry != NULL) {
	    print(entry);
	}
        else {
	    std::cout << "Word Not Found\n";
	}
    }
    else {
        std::cout << "Word Not Found\n";
    }
}

node* dictType::findEntry(std::string word, node *leaf) {
    if (leaf != NULL) {
	if (word == leaf->info.word) {
	    print(leaf);
	    return leaf;
	}
	else if (word < leaf->info.word) {
	    return findEntry(word, leaf->left);
	}
	else {
	    return findEntry(word, leaf->right);
	}
    }
    std::cout << "Word Not Found\n";
    return NULL;
}

void dictType::print(node *leaf) {
    std::cout << leaf->info.word << std::endl;
    std::cout << leaf->info.definition << std:: endl;

    std::cout << "Left Branch: ";
    if (leaf->left != NULL) { std::cout << leaf->left->info.word << std::endl; }
    else { std::cout << "NULL\n"; }
    std::cout << "Right Branch: ";
    if (leaf->right != NULL) { std::cout << leaf->right->info.word << std::endl; }
    else { std::cout << "NULL\n"; }
}
