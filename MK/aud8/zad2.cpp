//
// Created by Stefan Andonov on 25.4.23.
//

#include<iostream>
#include<cstring>
using namespace std;

class TennisPlayer {
protected:
    char fullName [50];
    bool playsInLeague;
public:
    TennisPlayer(char *fullName, bool playsInLeague) : playsInLeague(playsInLeague) {
        strcpy(this->fullName ,fullName);
    }

    friend ostream &operator<<(ostream &os, const TennisPlayer &player) {
        os << "Tennis Player Name: " << player.fullName << " Plays in league: " << (player.playsInLeague ? "YES" : "NO");
        return os;
    }
};

class RankedTennisPlayer : public TennisPlayer {
private:
    int rank;
public:
    RankedTennisPlayer(char *fullName, bool playsInLeague, int rank) : TennisPlayer(fullName, playsInLeague){
        this->rank = rank;
    }

    RankedTennisPlayer(const TennisPlayer & tp, int rank) : TennisPlayer(tp){
        this->rank = rank;
    }

    friend ostream &operator<<(ostream &os, const RankedTennisPlayer &player) {
        os << "Ranked " << static_cast<const TennisPlayer &>(player) << " Rank: " << player.rank;
        return os;
    }
};

int main () {
    TennisPlayer tp ("Stefan", false);
    cout << tp << endl;

    RankedTennisPlayer rtp ("Novak Gjokovic", true, 1);
    cout << rtp << endl;

    RankedTennisPlayer rtp2 (tp, 100);
    cout << rtp2 << endl;
    return 0;
}
