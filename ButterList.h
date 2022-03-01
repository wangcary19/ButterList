//
// Created by Cary Wang on 2/23/22.
//

#ifndef SPRING2022_DS_BUTTERLIST_H
#define SPRING2022_DS_BUTTERLIST_H

#include "ButterNode.h"
#include <string>
#include <iostream>
using namespace std;

class ButterList {
private:
public:
    int size = 0;
    ButterNode* start;
    ButterNode* end;

    ButterList();
    ~ButterList();

    //Utility and hidden functions
    void idxupdate(int start_at = 0);
    void idxdowndate(int start_at = 0);
    void printlist(int mode);
    void printreverse();
    void printnode(int user_idx);

    //List methods
    void append(int user_key, string user_value = "");
    void prepend(int user_key, string user_value = "");
    void insert_after(int user_idx, int user_key, string user_value = "");

    void remove_at(int user_idx);
    void remove_key(int user_key);
    void remove_val(string user_val);

    //Stack, queue, and deque functions
        //Add at front
        void push(int user_key) {prepend(user_key);}
        void push_front(int user_key) {prepend(user_key);}

        //Remove front
        void pop() {remove_at(0);}
        void dequeue() {remove_at(0);}
        void pop_front() {remove_at(0);}

        //Add at back
        void enqueue(int user_key) {append(user_key);}
        void push_back(int user_key) {append(user_key);}

        //Remove back
        void pop_back() {remove_at(size - 1);}

        //View top
        int peek() {
            if (isempty()) {
                cout << "Container empty!" << endl;
                return INT_MAX;}
            else {
            return start->get_key();
            }
        }
        int peek_front() {peek();}

        //View back
        int peek_back() {
            if (isempty()) {
                cout << "Container empty!" << endl;
                return INT_MAX;
            } else {
                return end->get_key();
            }
        }

        //Empty
        bool isempty() {
            if (size == 0) {
                return true;
            }
            else {
                return false;
            }
        }

        //Length
        int len() {return size;}
};


#endif //SPRING2022_DS_BUTTERLIST_H
