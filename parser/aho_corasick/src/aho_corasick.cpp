#include "aho_corasick.h"
#include "state.h"

#include <queue>
#include <iostream>

using namespace std;

namespace ACS {

using UMapCharToStr = std::unordered_map<char, string>;

int ACSearch::match(const string& source) const
{

    return -1;
}

//
// private
//

void ACSearch::buildNFA()
{
    // create start state for NFA
    string startName(1, START_STATE_NAME);
    auto currState = d_NFA_map.insert(UMapStrToSptState::value_type(startName,
                                make_shared<State>(startName))).first->second;

    char currChar = startName[0];
    for (char c : d_pattern) {
        string stateName(1, ++currChar);
        auto nextState = make_shared<State>(stateName);

        d_NFA_map.insert(UMapStrToSptState::value_type(stateName, nextState));

        currState->addPath(c, nextState.get());
        currState = nextState;
    }
    currState->isTerminal(true);
}

void ACSearch::buildDFA()
{
    // create start satte for DFA
    string startName(1, START_STATE_NAME);
    auto currState = d_DFA_map.insert(UMapStrToSptState::value_type(startName,
                                make_shared<State>(startName))).first->second;

    queue<State*> level;
    level.push(currState.get());
    int cnt = 1;

    while (!level.empty()) {
        State* cur = level.front();
        level.pop();

        // build next state from cur
        UMapCharToStr nextStateMap = getNextStateNames(cur);

        for (auto iter = nextStateMap.cbegin(); iter != nextStateMap.cend(); ++iter) {

            // exist state in DFA
            if (d_DFA_map.find(iter->second) != d_DFA_map.end()) {
                continue;
            }

            auto newDFAState = make_shared<State>(iter->second);

            d_DFA_map.insert(UMapStrToSptState::value_type(iter->second, newDFAState));
            cur->addPath(iter->first, newDFAState.get());

            level.push(newDFAState.get());
        }

        if (--cur == 0) {
            cnt = level.size();
        }
    }
}

UMapCharToStr ACSearch::getNextStateNames(State* state) const
{
    UMapCharToStr nextStateMap;

    for_each(state->name().cbegin(), state->name().cend(), [&](char c) {
        string nameInNFA(1, c);

        State* stateInNFA = d_NFA_map.find(nameInNFA)->second.get();

        for (int i = 0; i != 128; i++) {
            const State* nextState =  stateInNFA->nextState(i);
            if (nullptr == nextState) {
                continue;
            }
            nextStateMap[i].push_back(nextState->name()[0]);
        }
    });
    return nextStateMap;
}

} // namespace ACS



