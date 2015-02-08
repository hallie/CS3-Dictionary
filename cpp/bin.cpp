#include "dictClass.h"
#include <fstream>

dictType fillDictionary();

int main() {
    dictType dictionary = fillDictionary();
    bool valid = true;
    char instruction;
    std::string word;
    dictEntry entry;
    std::cout << "Dictionay has been built\n";
    do {
        std::cout << "What would you like to do now?\n"
                  << "\t(a) Search Word\n"
                  << "\t(b) Add Entry\n"
		  << "\t(c) Delete Entry\n";
	std::cin >> instruction;
	switch(instruction) {
	    case 'a':     std::cout << "Search Word: ";
			  std::cin >> word;
			  dictionary.findEntry(word);
			  break;
	    case 'b':	  std::cout << "Add Word: ";
			  std::cin >> entry.word;
			  std::cout << "Add Pronunciation: ";
			  std::cin >> entry.pronunciation;
			  std::cout << "Add Definition: ";
			  std::cin >> entry.definition;
			  dictionary.addEntry(entry);
			  break;
	    case 'c':	  std::cout << "Delete Entry: ";
			  std::cin >> word;
			  dictionary.deleteEntry(word);
			  break;
            default:	  valid = false;
			  break;
	}

    } while (valid);

    return 0;
}


dictType fillDictionary() {
    std::ifstream dict;
    dict.open("Dictionary/Dictionary.txt");

    dictType dictionary;
    dictEntry new_word;
    std::string hold;

    if (dict.is_open()) {
        getline(dict, hold);
        new_word.word = hold.substr(hold.find(":")+1);
        getline(dict, hold);
        new_word.pronunciation = hold.substr(hold.find(":")+1);
        new_word.definition = "";

        while (!dict.eof()) {
	    getline(dict, hold);
            if (hold[0] == 'd') {
	        new_word.definition += (hold.substr(hold.find(":")+1) + "\n");
	    }
            else {
	        dictionary.addEntry(new_word);
	        new_word.word = hold.substr(hold.find(":")+1);
                getline(dict, hold);
                new_word.pronunciation = hold.substr(hold.find(":")+1);
	        new_word.definition = "";
	    }
        }

	//std::cout << new_word.word << std::endl << new_word.pronunciation << std::endl << new_word.definition << std::endl;
	dict.close();
    }
    else {
	std::cout << "File not found\n";
    }

    return dictionary;
}
