//
// Created by Stefan Andonov on 13.3.23.
//

#include<iostream>

using namespace std;

class EmailMessage {
private:
    char sender [20]; //email address
    char receiver [20];
    char subject [20];
    char body [1000];
public:
    EmailMessage(char * _sender,
                 char * _receiver,
                 char * _subject = "",
                 char * _body = "" ) {
        strcpy(sender, _sender);
        strcpy(receiver, _receiver);
        strcpy(subject, _subject);
        strcpy(body, _body);

    }
};

int main () {
    return 0;
}