/**
 * Header file for the dictionary tree class.
 **/

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
        node *deleteEntry(std::string word, node *leaf);
        void print(node *leaf);
    public:
        dictType();
        void addEntry(dictEntry e);		//Calls to add entry from main
	void deleteEntry(std::string word);	//Calls to delete from main
	void findEntry(std::string word); 	//Calls find from main
        void getLast();				//Retrieves last entry in dict
	void getFirst();			//Retrieves first entry in dict
};

dictType::dictType() {
    root = NULL;	//Sets the root to NULL upon initialization
}

/**
 * [ Public ] Makes the entry a new node at the root if the root is
 *   currently NULL. Otherwise, it turns it into a node and passes
 *   it into the private function along with the root.
 **/
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

/**
 * [ Private ] Adds a node to a leaf. Calls itself recursively until
 *   the right position is found.
 **/
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

/**
 * [ Public ] Finds the word using the find function, and then re-adds its
 *   leaf nodes to the dictionary tree if they exist. Deletes entry.
 **/
void dictType::deleteEntry(std::string word) {
    node *hold;
    hold = deleteEntry(word, root);
    if (hold != NULL) {
        if (hold->left != NULL) {
            //print(hold->left);
	    addEntry(hold->left, root);
        }
        if (hold->right != NULL) {
	    //print(hold->right);
	    addEntry(hold->right, root);
        }
	std::cout << hold->info.word << " has been deleted.\n";
    }
}

node *dictType::deleteEntry(std::string word, node *leaf) {
    node *hold;
    if (leaf != NULL) {
        if (word == leaf->info.word) {
	    hold = leaf;
	    delete leaf;
            return hold;
        }
        else if (word < leaf->info.word) {
            return deleteEntry(word, leaf->left);
        }
        else {
            return deleteEntry(word, leaf->right);
        }
    }
    std::cout << "Word Not Found\n";
    return NULL;
}

/**
 * [ Public ] Function for finding an entry. Calls the private
 *   version of the function if the root of the dictionary
 *   tree isn't NULL.
 **/
void dictType::findEntry(std::string word) {
    if (root != NULL) {
	findEntry(word, root);
    }
    else {
        std::cout << "Word Not Found\n";
    }
}

/**
 * [ Private ] Function for finding an entry using a leaf node.
 * Recursively calls itself using the left or right leaf of the
 *   current leaf, depending on the relative value of the search
 *   word.
 **/
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

/**
 * [ Public ] Gets the most left entry in the tree (the last, alphabetically).
 **/
void dictType::getLast() {
    node *current;
    for (current = root; current->right != NULL; current = current->right);
    std::cout << "The last word in this dictionary is " << current->info.word << std::endl;
}

/**
 * [ Public ] Gets the most right entry in the tree (the first, alphabetically).
 **/
void dictType::getFirst() {
    node *current;
    for (current = root; current->left != NULL; current = current->left);
    std::cout << "The first word in this dictionary is " << current->info.word << std::endl;
}

/**
 * Function for printing the contents of an entry.
 **/
void dictType::print(node *leaf) {
    std::cout << leaf->info.word << std::endl;
    std::cout << leaf->info.pronunciation << std::endl;
    std::cout << leaf->info.definition << std:: endl;

    std::cout << "Left Branch: ";
    if (leaf->left != NULL) { std::cout << leaf->left->info.word << std::endl; }
    else { std::cout << "NULL\n"; }
    std::cout << "Right Branch: ";
    if (leaf->right != NULL) { std::cout << leaf->right->info.word << std::endl; }
    else { std::cout << "NULL\n"; }
}
