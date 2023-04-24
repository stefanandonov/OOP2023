//
// Created by Stefan Andonov on 24.4.23.
//

#include<iostream>
#include<cstring>
using namespace std;

class TennisPlayer {
protected:
    char fullName [50];
    bool playsInLeague;
public:
    TennisPlayer(char *fullName = "Stefan", bool playsInLeague = false) : playsInLeague(playsInLeague) {
        strcpy(this->fullName, fullName);
    }

    friend ostream &operator<<(ostream &os, const TennisPlayer &player) {
        os << "Tennis Player with name: " << player.fullName << " Plays in league?: " << (player.playsInLeague ? "yes" : "no");
        return os;
    }
};

class RankedTennisPlayer : public TennisPlayer {
private:
    int rank;
public:
    RankedTennisPlayer(char *fullName = "Stefan", bool playsInLeague = false, int rank = 1000) : TennisPlayer(fullName, playsInLeague) {

        this->rank = rank;
    }

    friend ostream &operator<<(ostream &os, const RankedTennisPlayer &player) {
        os << "Ranked " << static_cast<const TennisPlayer &>(player) << " rank: " << player.rank;
        return os;
    }


};

int main () {
    RankedTennisPlayer rtp ("Novak Gjokovikj", true, 1);
    cout << rtp << endl;

    TennisPlayer tp = rtp;
    cout << tp << endl;
    return 0;
}