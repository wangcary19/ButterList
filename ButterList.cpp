//
// Created by Cary Wang on 2/23/22.
//

#include "ButterList.h"
#include "ButterNode.h"

#include <string>
#include <iostream>
using namespace std;

//Constructor
ButterList::ButterList() {
    start = nullptr;
    end = nullptr;
}

//Destructor
ButterList::~ButterList() {
    ButterNode* to_be_del = start;
    while (to_be_del != nullptr) {
        ButterNode* curr_del = to_be_del;
        to_be_del = curr_del->next;
        delete curr_del;
    }
}
//-----------------------------------------------------------------------------------
//idxupdate, fixes "idx" value when prepend is used
void ButterList::idxupdate(int start_at) {
    auto* temp = start;
    if(start_at == 0) {
        while (temp != nullptr) {
            temp->idx++;
            temp = temp->next;
        }
    }
    else {
        while (temp != nullptr) {
            if (temp->idx == start_at) {
                temp->idx++;
                temp = temp->next;
            }
            else {
                temp = temp->next;
            }
        }
    }
}
//idxdowndate, fixes "idx" value when remove is used
void ButterList::idxdowndate(int start_at) {
    auto* temp = start;
    if(start_at == 0) {
        while (temp != nullptr) {
            temp->idx--;
            temp = temp->next;
        }
    }
    else {
        while (temp != nullptr) {
            if (temp->idx == start_at) {
                temp->idx--;
                temp = temp->next;
            }
            else {
                temp = temp->next;
            }
        }
    }
}
//Printlist, prints entire list
void ButterList::printlist(int mode) {
    cout << "{";
    auto* temp = start;
    if (mode == 0) {
        while (temp != nullptr) {
            if (temp == end) {
                cout << "(" << temp->get_key() << ", " << temp->get_value() << ") ";
                break;
            }
            cout << "(" << temp->get_key() << ", " << temp->get_value() << ") ; ";
            temp = temp->next;
        }
    }
    else if (mode == 1) {
        while (temp != nullptr) {
            if (temp == end) {
                cout << temp->get_key();
                break;
            }
            else {
                cout << temp->get_key() << ", ";
                temp = temp->next;
            }
        }
    }
    else if (mode == 2) {
        while (temp != nullptr) {
            if (temp == end) {
                cout << temp->get_value();
                break;
            }
            else {
                cout << temp->get_value() << ", ";
                temp = temp->next;
            }
        }
    }
    cout << "}" << endl;
}
//Printlist, prints entire list
void ButterList::printreverse() {
    cout << "{ ";
    auto* temp = end;
    while (temp != nullptr) {
        cout << "(" << temp->get_key() << ", " << temp->get_value() << ") ; ";
        temp = temp->prev;
    }
    cout << "}" << endl;
}
//Printnode, prints node at index
void ButterList::printnode(int user_idx) {
    auto* temp = start;
    if (user_idx >= size) {
        cout << "Index out of range, please try again." << endl;
    }
    while (temp->idx != user_idx) {
        temp = temp->next;
    }
    cout << "(" << temp->get_key() << ", " << temp->get_value() << ")" << endl;
}
//-----------------------------------------------------------------------------------
//Append, adds to end of list
void ButterList::append(int user_key, string user_value) {
    auto* temp = new ButterNode(user_key, user_value, size);
    size++; //Update total size

    if (start == nullptr and end == nullptr) {
        start = temp;
        end = temp;
    }
    else {
        end->next = temp; //Update old tail's next pointer
        temp->prev = end; //Update new tail's prev pointer
        end = temp; //Update end
    }
}
//Prepend, adds to front of list
void ButterList::prepend(int user_key, string user_value) {
    auto* temp = new ButterNode(user_key, user_value, -1);
    size++; //Update total size
    idxupdate();

    if (start == nullptr and end == nullptr) {
        start = temp;
        end = temp;
    }
    else {
        start->prev = temp; //Update old head's prev pointer
        temp->next = start; //Update new head's next pointer
        start = temp; //Update start
    }
}
//Insert, inserts after the given index
void ButterList::insert_after(int user_idx, int user_key, string user_value){
    auto* fore = start;
    if (size == 0) {
        auto* fresh = new ButterNode(user_key, user_value, size);
        start = fresh;
        end = fresh;
        size++;
    }
    else {
        while (fore->idx != user_idx) { //Walk to point of insertion
            fore = fore->next;
        }
        auto *hind = fore->next;
        auto *at = new ButterNode(user_key, user_value, fore->idx + 1);
        idxupdate(fore->idx + 1); //Update size of ones following before insert

        at->prev = fore; //Update new node prev
        at->next = hind; //Update new node next

        fore->next = at; //Update previous node's next
        hind->prev = at; //Update next node's prev

        size++;
    }
}
//----------------------------------------------------------------------------------
//Remove, remove based on index
void ButterList::remove_at(int user_idx) {
    auto* at = start;
    if (user_idx >= size or size == 0) {
        cout << "Index out of range, please try again." << endl;
        return;
    }
    else if(user_idx == 0 and size == 1) {
        start = nullptr;
        end = nullptr;
        delete at;
        size--;
    }
    else if (user_idx == 0) {
        start = start->next;
        start->prev = nullptr;
        delete at;
        size--;
        idxdowndate();
    }
    else if (user_idx == size - 1) {
        while (at->idx != user_idx){
            at = at->next;
        }
        end = at->prev;
        at->prev->next = nullptr;
        delete at;
        size--;
    }
    else {
        while (at->idx != user_idx) {
            at = at->next;
        }
        at->next->prev = at->prev;
        at->prev->next = at->next;
        idxdowndate(at->idx);
        delete at;
        size--;
    }
}
//Remove, remove based on key
void ButterList::remove_key(int user_key) {
    auto* at = start;
    while (at->get_key() != user_key) {
        at = at->next;
    }
    remove_at(at->idx);
}
//Remove, remove based on value
void ButterList::remove_val(string user_val) {
    auto* at = start;
    while (at->get_value() != user_val) {
        at = at->next;
    }
    remove_at(at->idx);
}