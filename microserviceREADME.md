1. How to request data from the microservice:
My program is a .exe executable file which means that it communicates through using system calls.  You request data from it by initiating the .exe program, which in turn starts the python code file.  You also request info by filling out the text input fields when prompted to do so.

2. How to receive data from the microservice:
This microservice searches for strings in a specified text document. The user receives data from the microservice in the form of the results of the text search.  If the text you search for is found, the program will inform you of this, and return a value of true, so that this microservice can be used by other microservices. In contrast, if nothing is found, it will return a false value.

The following is my UML sequence diagram:
![image](https://github.com/SawyerFedderly/CS361/assets/131832431/eeced676-138d-4bef-9357-6ceb0af9b4d0)
