#include <hw05.h>

VecOfStr hw05(const VecOfStr& strings) {
  VecOfStr result;

  auto is_palindrome = [](const std::string& str) {
    std::string filtered;

    for (char c : str) {
      if (std::isalnum(c)) {
        filtered.push_back(std::tolower(c));
      }
    }

    for (size_t i = 0, j = filtered.size() - 1; i < j; ++i, --j) {
      if (filtered[i] != filtered[j]) {
        return false;
      }
    }
    return true;
  };

  for (const auto& s : strings) {
    if (is_palindrome(s)) {
      result.push_back(s);
    }
  }

  return result;
}