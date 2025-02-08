#include <hw06.h>
#include <gtest/gtest.h>

TEST(Hw06Tests, Test1)
{
    auto rows = 5, seats_per_row = 8;
    Hall hall = create_hall(1, rows, seats_per_row);
    Session session = create_session(1, "Die Hard", hall);

    auto avail_seats = get_available_seats(hall);
    auto expected_seats = rows * seats_per_row;
    EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test2)
{
  auto rows = 5, seats_per_row = 15;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // reserve 2 seats
  auto reserved_seats = 2;
  reserve_seat(session, 1, 3);
  reserve_seat(session, 2, 5);

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = rows * seats_per_row - reserved_seats;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test3)
{
  auto rows = 3, seats_per_row = 5;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // reserve 1 seat
  reserve_seat(session, 1, 3);
  cancel_reservation(session, 1, 3);

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = rows * seats_per_row;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test4)
{
  auto rows = 3, seats_per_row = 5;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // reserve 1 seat
  reserve_seat(session, 1, 3);
  auto reserve_stat = reserve_seat(session, 1, 3);
  auto expected_stat = false;
  EXPECT_EQ(expected_stat, reserve_stat);
}

TEST(Hw06Tests, Test5)
{
  auto rows = 1, seats_per_row = 1;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // reserve 1 seat
  reserve_seat(session, 0, 0);
  auto free_seats = get_available_seats(hall);
  auto free_expected_seats = rows * seats_per_row - 1;
  std::cout << free_seats << std::endl;
  EXPECT_EQ(free_expected_seats, free_seats);
}

TEST(Hw06Tests, Test6)
{
  auto rows = 3, seats_per_row = 5;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // reserve 1 seat
  reserve_seat(session, 1, 3);
  auto reserve_stat = reserve_seat(session, 1, 3);
  auto expected_stat = false;
  EXPECT_EQ(expected_stat, reserve_stat);
}

TEST(Hw06Tests, Test7)
{
  auto rows = 4, seats_per_row = 6;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // reserve all seats
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < seats_per_row; ++j) {
      reserve_seat(session, i, j);
    }
  }

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = 0;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test8)
{
  auto rows = 4, seats_per_row = 6;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // reserve and then cancel all seats
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < seats_per_row; ++j) {
      reserve_seat(session, i, j);
      cancel_reservation(session, i, j);
    }
  }

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = rows * seats_per_row;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test9)
{
  auto rows = 4, seats_per_row = 6;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // reserve some seats and check if they are reserved
  reserve_seat(session, 1, 1);
  reserve_seat(session, 2, 2);
  reserve_seat(session, 3, 3);

  auto reserved_status1 = reserve_seat(session, 1, 1);
  auto reserved_status2 = reserve_seat(session, 2, 2);
  auto reserved_status3 = reserve_seat(session, 3, 3);

  EXPECT_FALSE(reserved_status1);
  EXPECT_FALSE(reserved_status2);
  EXPECT_FALSE(reserved_status3);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
