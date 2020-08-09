My Speller
My Speller is a program which checks if the word provided by the user is part of a dictionary.
It was written in C++ to be run on Linux operating system.

User first compiles the program by accessing the folder through terminal and typing "make".
This creates executable called "myspeller".

To invocate the program write:
./myspeller <dictionary_name> <maximum_number_of_results>

There are several ways of searching for words:
1. looking for specific word:
	-> type the word into the terminal
	=> word is either found and number of comparisons is printed or
	=> word is not found and user is informed about this
2. looking for words with specific prefix:
	-> use "*" at the end of the prefix e.g. yourPrefix*
	=> total number of matches printed
	=> words matching the prefix printed up to maximum_number_of_results
	=> number of comparisons up-to the first match found printed
3. looking for words with one unknown character:
	-> use "?" in place of the unknown character e.g. wo?d
	=> number of matches printed
	=> words from the dictionary matching the imput with arbitrary character in place of "?"
	printed up to maximum_number_of_results
	=> number of total string comparisons made printed
Search is case-sensitive.

After a query is processed the program will ask the user for another query.
To exit the program type "exit" into the terminal.

My Speller was created by Magdalena Gunkova and Iva Tomevska as part of their Data Structures class at NYU Abu Dhabi in Fall 2018.

We would like to give credit to Khalid Mengal for providing us with the original MAKEFILE which we have modified for this project.

