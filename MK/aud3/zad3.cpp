//
// Created by Stefan Andonov on 15.3.23.
//

#include<iostream>

class EmailMessage {
private:
    char sender[30];
    char receiver [30];
    char subject [50];
    char body [1000];

public:
    EmailMessage(char *_sender = "stefan.andonov@finki.ukim.mk",
                 char *_receiver = "contact@finki.ukim.mk",
                 char *_subject = "EMPTY",
                 char *_body = ""){ //default,constructor so argument
        strcpy(sender, _sender);
        strcpy(receiver, _receiver);
        strcpy(subject, _subject);
        strcpy(body, _body);
    }
};



using namespace std;

int main () {
    return 0;
}