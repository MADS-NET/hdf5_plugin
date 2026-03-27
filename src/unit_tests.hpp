#include <cmath>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace Mads {

constexpr double kEps = 1e-12;

bool approx_equal(double a, double b, double eps = kEps) {
  return std::fabs(a - b) <= eps;
}

bool starts_with(const std::string &value, const std::string &prefix) {
  return value.rfind(prefix, 0) == 0;
}

bool ends_with(const std::string &value, const std::string &suffix) {
  if (suffix.size() > value.size()) return false;
  return std::equal(suffix.rbegin(), suffix.rend(), value.rbegin());
}

bool doesnt_throw(const std::function<void()> &func, const std::string &message) {
  try {
    func();
    return true;
  } catch (const std::exception &e) {
    std::cerr << "[FAIL] " << message << ": '" << e.what() << "'\n";
    return false;
  }
}

bool require(bool condition, const std::string &message) {
  if (!condition) {
    std::cerr << "[FAIL] " << message << '\n';
    return false;
  }
  return true;
}

} // namespace Mads
