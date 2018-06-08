/**
 * Uses the median filter algorithm from N. Wirth’s book, implementation by N. Devillard.
 *
 * @author Ryan Benasutti, WPI
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef _OKAPI_MEDIANFILTER_HPP_
#define _OKAPI_MEDIANFILTER_HPP_

#include "okapi/filter/filter.hpp"
#include <algorithm>
#include <array>
#include <cstddef>

namespace okapi {
template <std::size_t n> class MedianFilterArgs : public FilterArgs {};

/**
 * @param n number of taps in the filter
 */
template <std::size_t n> class MedianFilter : public Filter {
  public:
  MedianFilter() : middleIndex((((n)&1) ? ((n) / 2) : (((n) / 2) - 1))) {
  }

  /**
   * Filters a value, like a sensor reading.
   *
   * @param ireading new measurement
   * @return filtered result
   */
  virtual double filter(const double ireading) override {
    data[index++] = ireading;
    if (index >= n) {
      index = 0;
    }

    return kth_smallset();
  }

  /**
   * Returns the previous output from filter.
   *
   * @return the previous output from filter
   */
  virtual double getOutput() const override {
    return output;
  }

  protected:
  std::array<double, n> data{0};
  std::size_t index = 0;
  double output = 0;
  const size_t middleIndex;

  /**
   * Algorithm from N. Wirth’s book, implementation by N. Devillard.
   */
  double kth_smallset() {
    std::array<double, n> dataCopy = data;
    size_t i, j, l, m;
    double x;
    l = 0;
    m = n - 1;

    while (l < m) {
      x = dataCopy[middleIndex];
      i = l;
      j = m;
      do {
        while (dataCopy[i] < x) {
          i++;
        }
        while (x < dataCopy[j]) {
          j--;
        }
        if (i <= j) {
          const double t = dataCopy[i];
          dataCopy[i] = dataCopy[j];
          dataCopy[j] = t;
          i++;
          j--;
        }
      } while (i <= j);
      if (j < middleIndex)
        l = i;
      if (middleIndex < i)
        m = j;
    }

    return dataCopy[middleIndex];
  }
};
} // namespace okapi

#endif
