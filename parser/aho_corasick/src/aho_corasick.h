#ifndef INCLUDE_ACS_AHOCORASICK
#define INCLUDE_ACS_AHOCORASICK

#include <string>
#include <unordered_map>
#include <memory>
#include <utility>

namespace ACS {

using std::string;

class State;

const int PATTERN_SIZE_MAX = 26;
const char START_STATE_NAME = 'A';

class ACSearch {
public:
    //
    // CREATORS
    //
    ACSearch(const string& pattern);

    //
    // ACCESSORS
    //

    // return index of first match.
    // will return -1 if does not found any match
    int match(const string& source) const;

private:

    using UMapStrToSptState = std::unordered_map<string, std::shared_ptr<State>>;
    using UMapCharToStr = std::unordered_map<char, string>;

    void buildNFA();
    void buildDFA();

    // calculate name of next state based on d_NFA_map
    UMapCharToStr getNextStateNames(State* state) const;

    // pattern need search
    string d_pattern;
    UMapStrToSptState d_NFA_map;
    UMapStrToSptState d_DFA_map;
};

inline
ACSearch::ACSearch(const string& pattern)
: d_pattern(pattern)
{
    buildNFA();
    buildDFA();
}

} // namespace ACS

#endif // INCLUDE_ACS_AHOCORASICK
