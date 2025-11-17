#include <cstddef>
#include <sys/types.h>
#include <vector>
#include <memory>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& a, std::vector<int>& b) {

      struct data {
        int* arr;
        size_t start;
        size_t end;
        double median;

        double compute_median() {
          return (median = (end - start) % 2 ? arr[start + (end - start) / 2] : (arr[start + (end - start) / 2 - 1] + arr[start + (end - start) / 2]) / 2.0); // NOLINT
        }
      };
      auto a_data = std::make_unique<struct data>(data{a.data(), 0, a.size(), 0.0});
      auto b_data = std::make_unique<struct data>(data{b.data(), 0, b.size(), 0.0});

      do {
        if (a_data->compute_median() == b_data->compute_median()) {
          return a_data->median;
        } else if (a_data->median < b_data->median) {
          std::swap(a_data, b_data);
        }
        a_data->end = (a_data->start + a_data->end) / 2;
        b_data->start = (b_data->start + b_data->end) / 2;
      } while (a_data->end - a_data->start > 0 && b_data->end - b_data->start > 0);

    }
  };
  




  // std::vector<int> merged;
  // merged.reserve(nums1.size() + nums2.size());
  // size_t i = 0, j = 0;
  // while (i < nums1.size() && j < nums2.size()) {
  //     if (nums1[i] < nums2[j]) {
  //         merged.push_back(nums1[i]);
  //         i++;
  //     } else {
  //         merged.push_back(nums2[j]);
  //         j++;
  //     }
  // }
  // while (i < nums1.size()) {
  //     merged.push_back(nums1[i]);
  //     i++;
  // }
  // while (j < nums2.size()) {
  //     merged.push_back(nums2[j]);
  //     j++;
  // }

  // size_t n = merged.size();
  // if (n % 2 == 1) {
  //     return merged[n / 2];
  // } else {
  //     return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
  // }