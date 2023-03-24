//
// Created by Stefan Andonov on 24.3.23.
//


#include<iostream>
#include<cstring>

using namespace std;

class Team {
private:
    char name[30];
    char city[30];
    int foundingYear;
public:
    Team(char *_name = "", char *_city = "", int foundingYear = 1999) : foundingYear(foundingYear) {
        strcpy(name, _name);
        strcpy(city, _city);
    }

    Team(const Team &other) {
        cout << "Team copy-constructor" << endl;
        strcpy(name, other.name);
        strcpy(city, other.city);
        foundingYear = other.foundingYear;
    }

    ~Team() {
        //do nothing
    }

    void print() {
        cout << "Team: " << name << " from city: " << city << " (" << foundingYear << ")" << endl;
    }

    const char *getName() const {
        return name;
    }

    const char *getCity() const {
        return city;
    }

    int getFoundingYear() const {
        return foundingYear;
    }
};

class Game {
private:
    Team home;
    Team away;
    int homeGoals;
    int awayGoals;
public:
    Game(Team &_home, Team &_away, int homeGoals, int awayGoals) :
            homeGoals(homeGoals),
            awayGoals(awayGoals) {
        home = _home;
        away = _away;

    }

    Game(const Game &other) {
        home = other.home;
        away = other.away;
        homeGoals = other.homeGoals;
        awayGoals = other.awayGoals;
    }

    void print() {
        cout << "Game between: " << endl;
        cout << "Home: ";
        home.print();
        cout << "Away: ";
        away.print();
        cout << "Result - " << homeGoals << ":" << awayGoals << endl;
    }

    bool rematch(Game other) {
        return strcmp(home.getName(), other.away.getName()) == 0
               && strcmp(away.getName(), other.home.getName()) == 0;
    }

};



int main() {
    Team team1("Barca", "Barcelona", 1899);
    Team team2("Real Madrid", "Madrid", 1900);

    Game game(team1, team2, 5, 3);

    Game game2(team2, team1, 3, 3);


    game.print();
    game2.print();
    cout << game.rematch(game2);
    cout << game2.rematch(game);
    return 0;
}
