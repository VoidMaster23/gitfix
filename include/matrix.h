#pragma once

#include <iostream>
#include <memory>

class Matrix2d {
 public:
  Matrix2d(size_t rows, size_t cols)
      : rows_(rows),
        cols_(cols),
        data_(std::make_unique<int[]>(rows * cols)) {}

  int& operator()(size_t row, size_t col) {
    return data_[row * cols_ + col];
  }

  const int operator()(size_t row, size_t col) const {
    return data_[row * cols_ + col];
  }

  size_t rows() const { return rows_; }
  size_t cols() const { return cols_; }

 private:
  size_t rows_, cols_;
  std::unique_ptr<int[]> data_;
};