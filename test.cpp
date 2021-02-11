#include "spreadsheet.hpp"
#include "spreadsheet_test.hpp"
#include "select_contains.hpp"
#include "select_contains_test.hpp"
#include "select_or.hpp"
#include "select_or_test.hpp"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
