#pragma once

#include "../csvreader/csvreader.hpp"

namespace func {
CSVReader<CSVRowCombi> csvreaderCombiner(CSVReader<CSVRow>& reader1,
                                         CSVReader<CSVRow>& reader2);
// 合并两个 csv
}  // namespace func
