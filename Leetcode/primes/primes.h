#include <vector>
#include <complex>
#include <algorithm>

using namespace std;
vector<int> GetPrimes(int n) {
  vector<bool> is_prime(n, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2, r = sqrt(n); i <= r; i++) {
    if (!is_prime[i])
      continue;
    for (int j = i * i; j < n; j += i * 2)
      is_prime[j] = false;
  }

  vector<int> ret;
  for (int i = 0; i < n; i++)
    if (is_prime[i])
      ret.emplace_back(i);
  return ret;
}

bool IsPrime(int num) {
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  for (int i = 3; i <= sqrt(num); i += 2) {
    if (num % i == 0)
      return false;
  }
  return true;
}
