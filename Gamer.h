#ifndef GAMER_H
#define GAMER_H
#include <string>
#include <iostream>
#include <limits>

using namespace std;
class Gamer {
private:
    string m_nick;
    char m_sign;
public:
    Gamer(string const nick = "0", char sign = '0') : m_nick{ nick }, m_sign{ sign }
    {}
    string get_nick(void) const;
    char get_sign(void) const;
    void set_nick(string nick);
    void set_sign(char sign);
};

ostream& operator<<(ostream& out, const Gamer& data);

istream& operator>>(istream& in, Gamer& dane);

#endif