#include <strings>

struct dictEntry {
    string word;
    string definition;
};

struct node {
    dictEntry info;
    node* left;
    node* right;
};

class dictType {
    private:
	node* root;
    public:
        dictType();
        void addEntry(dictEntry e);
	void deleteEntry(string word);
	void findEntry(string word);
}

dictType::dictType() {
    node* root = NULL;
}

void dictType::addEntry() {}
void dictType::deleteEntry() {}
void dictType::findEntry() {}
