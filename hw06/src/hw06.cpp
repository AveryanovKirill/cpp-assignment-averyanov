#include <hw06.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <memory>
#include <vector>



Hall create_hall(int id, int rows, int seats_per_row)
{
  std::vector<std::vector<bool>> hall_array(rows, std::vector<bool>(seats_per_row));
  return Hall{ id, rows, seats_per_row, hall_array };
}

Session create_session(int id, const std::string& movie_title, Hall& hall)
{
  return Session{ id, movie_title, hall };
}

bool reserve_seat(Session& session, int row, int seat_number)
{
  if (!session.hall.hall_array[row][seat_number])
  {
    session.hall.hall_array[row][seat_number] = true;
    return true;
  }
  return false;
}

bool cancel_reservation(Session& session, int row, int seat_number)
{
  if (session.hall.hall_array[row][seat_number])
  {
    session.hall.hall_array[row][seat_number] = false;
    return true;
  }
  return false;
}

void display_hall(const Hall& hall)
{
  auto hall_array = hall.hall_array;
  for (int i = 0; i < hall_array.size(); i++)
  {
    for (int j = 0; j < hall_array[i].size(); j++)
    {
      std::cout << hall_array[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int get_available_seats(const Hall& hall)
{
  int count_free = 0;
  auto hall_array = hall.hall_array;
  for (int i = 0; i < hall_array.size(); i++)
  {
    for (int j = 0; j < hall_array[i].size(); j++)
    {
      if (!hall_array[i][j])
        count_free += 1;
    }
  }
  return count_free;
}