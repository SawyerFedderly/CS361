import time

# before running this file, it is important to note that both this file as well as the text file you intend to search through
# must be inside the same folder, and the console must be opened to that specific folder otherwise the program will tell you
# that the file name you searched for doesn't exist.

def text_search():
    # ask user for name of input file
    fileName = input("Input name of text file to search in: ")
    searchFile = open(fileName, "r")

    # check if the file opens successfully
    if searchFile.closed:
        print("Error opening input file!")
        exit(); # use return instead?
    
    # read and close text file
    searchData = searchFile.read()
    time.sleep(1)
    searchFile.close()

    # ask user for text string to search for
    searchString = input("Input the string of text you wish to search for: ")

    # return search results
    if searchString in searchData:
        print("Result(s) found!")
        return True
    else:
        print("No results found.")
        return False


text_search()