#include <sys/types.h>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& a, std::vector<int>& b) {
      uint a_start = 0, b_start = 0;
      uint a_end = a.size(), b_end = b.size();

      struct Data {
        std::vector<int>& arr;
        uint start;
        uint end;
        uint median;
      };
      Data a_data{a, 0, static_cast<uint>(a.size()), 0}, b_data{b, 0, static_cast<uint>(b.size()), 0};

      auto median = [](const std::vector<int>& v) {
        size_t n = v.size();
        return n % 2 ? v[n / 2] : (v[n / 2 - 1] + v[n / 2]) / 2.0;
      };

      do {
        double ma = median(a);
        double mb = median(b);
        if (ma == mb) {
          return ma;
        } else if (ma < mb) {
          std::swap(a_start, a_end);
          std::swap(a, b);
          std::swap(b_start, b_end);
        }
      } while (a_start < a_end && b_start < b_end);

      return 0.0;
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