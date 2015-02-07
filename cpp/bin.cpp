#include "dictClass.h"
#include <fstream>
using namespace std;

int main() {
    ifstream dict;
    dict.open("Dictionary/Dictionary.txt");

    dictType dictionary;
    dictEntry new_word;
    string hold;

    if (dict.is_open()) {
        getline(dict, hold);
        new_word.word = hold.substr(hold.find(":")+1);
        getline(dict, hold);
        new_word.summary = hold.substr(hold.find(":")+1);
        new_word.definition = "";

        //while (!dict.eof()) {
        for(int i = 0; i < 10; i++) {
	    getline(dict, hold);
            if (hold[0] == 'd') {
	        new_word.definition += (hold.substr(hold.find(":")+1) + "\n");
	    }
            else {
	        dictionary.addEntry(new_word);
	        new_word.word = hold.substr(hold.find(":")+1);
                getline(dict, hold);
                new_word.summary = hold.substr(hold.find(":")+1);
	        new_word.definition = "";
	    }
        }

	cout << new_word.word << endl << new_word.summary << endl << new_word.definition << endl;
	dict.close();
    }
    else {
	cout << "File not found\n";
    }
    return 0;
}
