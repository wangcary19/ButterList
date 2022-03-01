//
// Created by Cary Wang on 2/23/22.
//

#ifndef SPRING2022_DS_BUTTERNODE_H
#define SPRING2022_DS_BUTTERNODE_H

#include <string>
using namespace std;

class ButterNode {
private:
    //Data:
    int key;
    string value;
public:
    //Identifiers:
    int idx;
    ButterNode* prev;
    ButterNode* next;

    //Functions:;
    ButterNode(int user_key, string user_value, int given_idx);
    ~ButterNode() = default;

    int get_key(){return key;}
    void set_key(int user_key){key = user_key;}

    string get_value(){return value;}
    void set_value(string user_value){value = user_value;}
};


#endif //SPRING2022_DS_BUTTERNODE_H
