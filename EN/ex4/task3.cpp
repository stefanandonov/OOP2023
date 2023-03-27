//
// Created by Stefan Andonov on 22.3.23.
//

#include<iostream>
#include<cstring>

using namespace std;

class Team {
private:
    char name[20];
    int foundingYear;
    char city[20];
public:
    Team(char *_name = "", int _foundingYear = 1890, char *_city = "") { //2in1 nescafe constructor
        strcpy(name, _name);
        foundingYear = _foundingYear;
        strcpy(city, _city);
    }

    Team(const Team &other) {
        cout << "The copy constructor of the class Team is called!" << endl;
        strcpy(name, other.name);
        foundingYear = other.foundingYear;
        strcpy(city, other.city);
    }

    void print() {
        cout << name << " " << city << " (" << foundingYear << ")" << endl;
    }

    const char *getName() const {
        return name;
    }

    int getFoundingYear() const {
        return foundingYear;
    }

    const char *getCity() const {
        return city;
    }

    friend class Game;
};

class Game { //composition of two teams
private:
    Team home;
    Team away;
    int homeGoals;
    int awayGoals;
public:
    Game(Team _home, Team _away, int _homeGoals = 0, int _awayGoals = 0) { //2in1 constructor
        home = _home;
        away = _away;
        homeGoals = _homeGoals;
        awayGoals = _awayGoals;
    }

    Game(const Game &other) {
        cout << "The copy constructor of the class Game is called!" << endl;
        home = other.home;
        away = other.away;
        homeGoals = other.homeGoals;
        awayGoals = other.awayGoals;
    }

    void print() {
        cout << "Home: ";
        home.print();
        cout << "Away: ";
        away.print();
        cout << "Result - " << homeGoals << ":" << awayGoals;
    }

    bool rematch(Game & other) {
        return strcmp(home.name, other.away. name) == 0
               && strcmp(away.name, other.home.name) == 0;
    }

    Team &getHome() {
        return home;
    }

    Team &getAway() {
        return away;
    }

    int getHomeGoals() const {
        return homeGoals;
    }

    int getAwayGoals() const {
        return awayGoals;
    }
};

void rematch(Game & first, Game & second) {
    if (first.rematch(second)) {
        int totalGoalsTeam1 = first.getHomeGoals() + second.getAwayGoals();
        int totalGoalsTeam2 = first.getAwayGoals() + second.getHomeGoals();
        if (totalGoalsTeam1 > totalGoalsTeam2) {
            cout << "WINNER:" << endl;
            first.getHome().print();
        } else if (totalGoalsTeam1 < totalGoalsTeam2){
            cout << "WINNER:" << endl;
            first.getAway().print();
        } else {
            cout << "DRAW";
        }
    } else {
        cout << "Not a rematch";
    }
}

int main() {
    Team team1("Barca", 1899, "Barcelona");
    Team team2("Real Madrid", 1891, "Madrid");
    Team team3("Chelsea", 1900, "London");

    Game game(team1, team2, 5, 3);
    Game second(team2, team1, 6, 4);


//    game.print();

    rematch(game ,second); //we are calling the implicit copy-constructor of Game twice.


    return 0;
}
