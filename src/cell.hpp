#pragma once

#include <memory>

using CellPtr = std::shared_ptr<class Cell>;

class Cell {
public:
	Cell() noexcept;
};
