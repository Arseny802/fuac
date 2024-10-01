#include <iostream>
#include <optional>
#include <vector>

template<typename T>
bool array_is_sorted(const std::vector<T> &data) {
  for (size_t i = 1; i < data.size(); ++i) {
    if (data[i - 1] > data[i]) {
      return false;
    }
  }

  return true;
}

template<typename T>
std::optional<typename std::vector<T>::size_type> binary_search(
    const std::vector<T> &data, T value) {
  if (!array_is_sorted(data)) {
    return std::nullopt;
  }

  if (data.back() < value) {
    return std::nullopt;
  }

  using st = typename std::vector<T>::size_type;
  st left = 0;
  st right = data.size();

  while (right != left) {
    st mid = (right + left) / 2;

    if (mid > 0 && mid < data.size() &&
        (mid == left || mid == right)) {
      return std::nullopt;
    }

    if (data[mid] == value) {
      return mid;
    } else if (data[mid] > value) {
      right = mid;
    } else {
      left = mid;
    }
  }

  return std::nullopt;
}

int main() {
  std::cout << "bs1: " << binary_search({1, 2, 4, 56, 4545, 6666}, 1).value_or(-1) << std::endl;
  std::cout << "bs2: " << binary_search({1, 2, 4, 56, 4545, 6666}, 2).value_or(-1) << std::endl;
  std::cout << "bs3: " << binary_search({1, 2, 4, 56, 4545, 6666}, 4).value_or(-1) << std::endl;
  std::cout << "bs4: " << binary_search({1, 2, 4, 56, 4545, 6666}, 56).value_or(-1) << std::endl;
  std::cout << "bs5: " << binary_search({1, 2, 4, 56, 4545, 6666}, 4545).value_or(-1) << std::endl;
  std::cout << "bs6: " << binary_search({1, 2, 4, 56, 4545, 6666}, 6666).value_or(-1) << std::endl;
  std::cout << "bs7: " << binary_search({1, 2, 4, 56, 4545, 6666}, 6667).value_or(-1) << std::endl;
  std::cout << "bs8: " << binary_search({1, 2, 4, 56, 4545, 6666}, 0).value_or(-1) << std::endl;
  std::cout << "bs9: " << binary_search({1, 2, 4, 56, 4545, 6666}, 3).value_or(-1) << std::endl;
  return 0;
}
