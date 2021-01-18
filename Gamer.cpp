#include "Gamer.h"

using namespace std;


    string Gamer::get_nick(void) const { return m_nick; }
    char Gamer::get_sign(void) const { return m_sign; }
    void Gamer::set_nick(string nick) { m_nick = nick; }
    void Gamer::set_sign(char sign) { m_sign = sign; }

ostream& operator<<(ostream& out, const Gamer& data)
{// operator wyjœcia
    out << "Player " << data.get_nick() << " selected: " << data.get_sign();
    return out;
}

istream& operator>>(istream& in, Gamer& dane)
{// operator wejœcia
    string v1;
    string v2;
    cout << "Enter nickname: ";
    in >> v1;
    dane.set_nick(v1);
    cout << "Enter sign: ";
    in >> v2;
    if (v2.size() > 1)
        do
        {
            cout << "Enter just one sign: ";
            in >> v2;
        } while (v2.size() > 1);
    dane.set_sign(v2[0]);

    return in;
}