#include "manage.h"
#include <limits.h>
#include <gtest/gtest.h>

using namespace std;

TEST(ExampleTest, Sample) {
  RoomManage rm(5);

  vector<int> as = {0,1,2,3,4};
  EXPECT_EQ(rm.CheckAvailableRooms(0, 10), as);
  EXPECT_EQ(rm.CheckTimeOfRoom(0, 0), 0);
  EXPECT_EQ(rm.CheckTimeOfRoom(0, 1), 1);

  rm.UseRoom(1, 1, 3);
  as = {0,2,3,4};
  EXPECT_EQ(rm.CheckAvailableRooms(0, 10), as);
  EXPECT_EQ(rm.CheckAvailableRooms(1, 3), as);
  EXPECT_EQ(rm.CheckTimeOfRoom(1, 2), 3);
  EXPECT_EQ(rm.CheckTimeOfRoom(0, 0), 0);



  rm.UseRoom(2, 2, 4);
  as = {0, 3, 4};
  EXPECT_EQ(rm.CheckAvailableRooms(0, 10), as);
  as = {0, 1, 3, 4};
  EXPECT_EQ(rm.CheckAvailableRooms(3, 10), as);

  EXPECT_EQ(rm.CheckTimeOfRoom(1, 2), 3);
  EXPECT_EQ(rm.CheckTimeOfRoom(1, 5), 5);

  EXPECT_EQ(rm.CheckTimeOfRoom(2, 0), 0);
  EXPECT_EQ(rm.CheckTimeOfRoom(2, 3), 4);


}



