#include "dictClass.h"
#include <fstream>

int main() {
    std::ifstream dict;
    dict.open("Dictionary/Dictionary.txt");

    dictType dictionary;
    dictEntry new_word;
    std::string hold;

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

	std::cout << new_word.word << std::endl << new_word.summary << std::endl << new_word.definition << std::endl;
	dict.close();
    }
    else {
	std::cout << "File not found\n";
    }
    return 0;
}
