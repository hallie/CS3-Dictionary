#include "dictClass.h"
#include <fstream>

dictType fillDictionary();		    //Prototypes
std::string to_upper(std::string s);

int main() {
    dictType dictionary = fillDictionary(); //Creating the dictionary
//  dictType dictionary;
    bool valid = true;			      //Checks for valid entry
    char instruction;			      //Gets the next instruction
    dictEntry entry;			      //An entry for holding commands

    std::cout
<<"******************************************************************\n"
<<"* ________  .__        __  .__                                   *\n"
<<"* \\______ \\ |__| _____/  |_|__| ____   ____ _____ _______ ___.__.*\n"
<<"*  |    |  \\|  |/ ___\\   __\\  |/  _ \\ /    \\\\__  \\\\_  __ <   |  |*\n"
<<"*  |    `   \\  \\  \\___|  | |  (  <_> )   |  \\/ __ \\|  | \\/\\___  |*\n"
<<"* /_______  /__|\\___  >__| |__|\\____/|___|  (____  /__|   / ____|*\n"
<<"*         \\/        \\/                    \\/     \\/       \\/     *\n"
<<"******************************************************************\n";


    do {
	//Prompts the user to input an instruction.
        std::cout << "\nWhat would you like to do now?\n"
                  << "\t(a) Search Word\n"
                  << "\t(b) Add Entry\n"
		  << "\t(c) Delete Entry\n";
	std::cin >> instruction;
	switch(instruction) {
			  //Prompts for a word, and then searches for it.
	    case 'a':     std::cout << "Search Word: ";
			  std::cin >> entry.word;
			  dictionary.findEntry(to_upper(entry.word));
			  break;
			  //Prompts for an entry, and then adds it.
	    case 'b':	  std::cout << "Add Word: ";
			  std::cin >> entry.word;
			  entry.word = to_upper(entry.word);
			  std::cout << "Add Pronunciation: ";
			  std::cin >> entry.pronunciation;
			  std::cout << "Add Definition: ";
			  std::cin >> entry.definition;
			  dictionary.addEntry(entry);
			  break;
			  //Prompts for a word to delete, and removes it.
	    case 'c':	  std::cout << "Delete Entry: ";
			  std::cin >> entry.word;
			  dictionary.deleteEntry(to_upper(entry.word));
			  break;
			  //Declares the entry invalid if none of the above.
            default:	  valid = false;
			  break;
	}
    } while (valid);

    return 0;
}

/**
 *Function to fill the dictionary tree from the text file.
 **/
dictType fillDictionary() {
    //Declaring the dictionary text file and opening it.
    std::ifstream dict;
    dict.open("Dictionary/Dictionary.txt");
    //Declaring the new dictionary tree, an entry, and a string for holding.
    dictType dictionary;
    dictEntry new_word;
    std::string hold;

    if (dict.is_open()) {    //Checking to make sure the file exists.
	//Because we know that the first line is a word, we can make it the
	// first entry word (after the "word:").
        getline(dict, hold);
	new_word.word = hold.substr(hold.find(":")+1);
	//Same for the second line, which is the pronunciation
        getline(dict, hold);
        new_word.pronunciation = hold.substr(hold.find(":")+1);
        new_word.definition = "";

        while (!dict.eof()) {	  //While not at the end of the file
	    //If the first character of the line is a 'd', then we know we're
	    //  still looking at a definition. So we just add it to the
	    //  current entry's definition.
	    getline(dict, hold);
            if (hold[0] == 'd') {
	        new_word.definition += ('\t' + hold.substr(hold.find(":")+1) + "\n");
	    }
	    //If not a 'd', it must be a new word. So we add that now complete
	    //  entry to the dictionary tree, and begin a new one.
            else {
	        dictionary.addEntry(new_word);
	        new_word.word = hold.substr(hold.find(":")+1);
                getline(dict, hold);
                new_word.pronunciation = hold.substr(hold.find(":")+1);
	        new_word.definition = "";
	    }
        }
	dict.close();
    }
    else {  //If the file doesn't exist, this is the error message.
	std::cout << "File not found\n";
    }

    return dictionary;
}

/**
 *This function converts all strings to uppercase using their ASCII ID numbers.
 *Because the lowercase letters begin at 97, and the uppercase begin at 65, we
 *  can just subtract 32 if the integer value of the character is greater than
 *  97, and then convert it back to a character to add to the new string. 
 **/
std::string to_upper(std::string s) {
    std::string upper = "";
    for(int i = 0; i < s.length(); i++) {
	if (int(s[i]) >= 97) {
	    upper += char(int(s[i]) - 32);
	}
        else {
	    upper += s[i];
	}
    }
    return upper;
}
