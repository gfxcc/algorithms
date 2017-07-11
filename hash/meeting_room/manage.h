#include <yong/head.h>

class RoomManage {
  using Map = map<int, list<pair<int, bool>>>;
  Map mp_;
  int room_;
public:

  RoomManage(int room) : room_(room) {
    mp_[0] = list<pair<int, bool>>();
  }

  // O(n)  n -> usage
  vector<int> CheckAvailableRooms(int start, int end) {
    unordered_set<int> rooms;
    for (int i = 0; i < room_; i++)
      rooms.insert(i);

    for (auto iter = mp_.begin(); iter != mp_.end() && iter->first <= end; iter++) {
      for (auto ele : iter->second) {
        if (ele.second == true)
          rooms.erase(ele.first);
        else if (iter->first <= start)
          rooms.insert(ele.first);
      }
    }

    vector<int> ret(rooms.begin(), rooms.end());
    sort(ret.begin(), ret.end());
    return ret;
  }

  void UseRoom(int id, int start, int end) {
    mp_[start].push_back({id, true});
    mp_[end].push_back({id, false});;
  }

  int CheckTimeOfRoom(int id, int start) {
    bool f = true;
    for (auto iter = mp_.begin(); iter != mp_.end(); iter++) {
      for (auto ele : iter->second) {
        if (ele.first == id)
          f = !ele.second;
      }
      if (iter->first >= start && f)
        return iter->first;
    }
    return start;
  }
};
