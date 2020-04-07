// Copyright 2020 Kuzhelev Anton

#ifndef MODULES_PRIME_NUMBERS_INCLUDE_TPRIME_NUMS_H_
#define MODULES_PRIME_NUMBERS_INCLUDE_TPRIME_NUMS_H_

#pragma once

#include <vector>
#include <utility>

class TPrime_Nums {
 public:
    TPrime_Nums(int left, int right);
    std::pair<int, int> GetInterval();
    std::vector<int> Get_Prime_Nums();
    void SetInterval(std::pair<int, int> interval);
 private:
    int left_edge, right_edge;
};

#endif  // MODULES_PRIME_NUMBERS_INCLUDE_TPRIME_NUMS_H_
