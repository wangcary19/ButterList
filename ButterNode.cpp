//
// Created by Cary Wang on 2/23/22.
//

#include "ButterNode.h"
#include <string>
#include <utility>
using namespace std;

ButterNode::ButterNode(int user_key, string user_value, int given_idx):key(user_key), value(std::move(user_value)), idx(given_idx) {
    prev = nullptr;
    next = nullptr;
}