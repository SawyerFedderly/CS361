1. How to request data from the microservice:

My program is a .exe executable file which means that it communicates through using system calls.  You can put the following text in a python program to call the .exe microservice:

import os

cwd = os.getcwd()

program = cwd + "/file_text_search.exe"

os.startfile(program)

Example call:

os.startfile(program) --> (calls microservice)

Code that reads content of specified text file and searches for specified text string:

searchFile = open(fileName, "r") --> (opens text file with inputted name)

searchData = searchFile.read() --> (reads text file data)

searchString = input("Input the string of text you wish to search for: ") --> (specify string to search for)

if searchString in searchData: return true or false if not found --> (return search result)

2. How to receive data from the microservice:

This microservice searches for strings in a specified text document. The user receives data from the microservice in the form of the results of the text search.  If the text you search for is found, the program will inform you of this, and return a value of true, so that this microservice can be used by the main program. In contrast, if nothing is found, it will return a false value.

In order to receive data from the microservice, you need to successfully access the text file that you intend to search through.  The text file must be in the same folder as the main program and microservice.


The following is my UML sequence diagram:
![Screenshot 2023-05-24 221828](https://github.com/SawyerFedderly/CS361/assets/131832431/b6ec6476-3985-49b4-9e8b-76dcdb7add94)
