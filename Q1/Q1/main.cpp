#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <conio.h>

using namespace std;

const string message = "Bgc-bfufb tegaedppqna ql aggv zge xof tegaedppfe'l lgjb.\nXof adpf vflqanfe logjbvn'x hf pdwqna d cgebv qn coqro xof tbdkfe ql mjlx d lpdbb tdex. Xof tbdkfe QL XOF HGLL; qx'l kgje vjxk xg fnxfexdqn oqp ge ofe.\nZgrjl ql d pdxxfe gz vfrqvqna codx xoqnal kgj def ngx agqna xg vg.\nXof rglx gz dvvqna d zfdxjef qln'x mjlx xof xqpf qx xdwfl xg rgvf qx. Xof rglx dblg qnrbjvfl xof dvvqxqgn gz dn ghlxdrbf xg zjxjef fstdnlqgn. Xof xeqrw ql xg tqrw xof zfdxjefl xodx vgn'x zqaox fdro gxofe. - Mgon Rdepdrw.\n(ccc.adpdljxed.rgp/uqfc/nfcl/234346?utkjpvbjr)\n(ccc.hedqnkijgxf.rgp/ijgxfl/djxogel/m/mgon_rdepdrw.oxpb)";

const string freqLang = "TEOAISRHNUCMDLGWFPYKJBVQX";
vector<pair<char, int>> table;

bool sortByValue(pair<char, int>& a, pair<char, int>& b) {
    return a.second > b.second;
}

void sortVector(vector<pair<char, int>>& vec) {
    std::sort(vec.begin(), vec.end(), sortByValue);
}

int getIndex(vector<pair<char, int>>& vec, char c)
{
    //we'll create an iterator for our vector with lambda to find
    //the first element that matches our 'c' key
    auto it = find_if(vec.begin(), vec.end(), [&](pair<char, int>& p)
    { return p.first == c; });

    //if the iterator finds a match, returns the distance from 
    //the beginning to the iterator
    if (it != vec.end())
        return distance(vec.begin(), it);
    else
        return -1;
}

void processChar(char c)
{
    //if character is not a lower case letter, do nothing
    if (!isalpha(c))
        return;

    //look up table for existing pair
    for (int i = 0; i < table.size(); i++)
        if (table.at(i).first == c)
        {
            table.at(i).second++;
            return;
        }

    //insert new pair if no pair was found
    pair<char, int> t_pair = { c, 1 };
    table.push_back(t_pair);
}

void decryptMessage(string message, string freqLang)
{
    vector<int> upper_pos;  // this will keep track of uppercase letters

    //we'll iterate through the message
    for (int i = 0; i < message.length(); i++)
    {
        //first, we'll keep track of uppercase letters
        if (isupper(message[i]))
            upper_pos.push_back(i);

        //we'll process each character, using tolower() to simplify the query
        processChar(tolower(message[i]));
    }

    //now we'll sort our vector by the value
    sortVector(table);

    //we'll now decrypt the message
    int id;
    for (int i = 0; i < message.length(); i++)
    {
        if (!isalpha(message[i]))
            continue;
        id = getIndex(table, tolower(message[i]));
        message[i] = tolower(freqLang[id]);
    }

    //returning the uppercase to their positions  
    for (int i = 0; i < upper_pos.size(); i++)
    {
        message[upper_pos[i]] = toupper(message[upper_pos[i]]);
    }

    //we can finally print the real message
    for (int i = 0; i < message.length(); i++)
        cout << message[i];
}

int main() {
    decryptMessage(message, freqLang);
    getch();
}