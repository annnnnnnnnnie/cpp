#include <algorithm>
#include <numeric>

class Solution {
public:
  void smooth(const double *in, double *out, int N, int h) {
    if (h >= N - 1) {
      smoothEverything(in, out, N);
      return;
    } else if (h == 0) {
      std::copy_n(in, N, out);
      return;
    } else {
      double *padded_in = new double[N + 2 * h];
      
      std::fill(padded_in, padded_in + (N + 2 * h), 0);
      std::copy_n(in, N, padded_in + h);
      double currentSum = std::accumulate(padded_in, padded_in + 2 * h + 1, 0);
      for(int i = 0; i < N ; i++) {
        out[i] = currentSum / (2 * h + 1);
        currentSum -= padded_in[i];
        currentSum += padded_in[i + 2 * h + 1];
      }

      delete padded_in;
      return;
    }
  }

  void smoothEverything(const double *in, double *out, int N) {
    double total = std::accumulate(in, in + N, 0);
    double avg = total / N;
    std::fill(out, out + N, avg);
  }
};