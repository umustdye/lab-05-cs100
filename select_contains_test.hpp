#include "gtest/gtest.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include "select_contains.hpp"
#include "spreadsheet.hpp"
using std::stringstream;

void fillSheet(Spreadsheet &sheet) {
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});
}


//SELECT_CONTAINS TEST
TEST(Select_Contains, EmptyQuery) {
    //Initialize test
    stringstream strm;
    Spreadsheet sheet;
    fillSheet(sheet);
    sheet.set_selection(new Select_Contains(&sheet, "Last", ""));
    
    //Run test
    sheet.print_selection(strm);

    //Assert
    EXPECT_EQ("", strm.str());
}

TEST(Select_Contains, BadColumn) {
    //Initialize test
    stringstream strm;
    Spreadsheet sheet;
    fillSheet(sheet);
    sheet.set_selection(new Select_Contains(&sheet, "last", "Dole"));
    
    //Run test
    sheet.print_selection(strm);

    //Assert
    EXPECT_EQ("", strm.str());
}

TEST(Select_Contains, WholeString) {
    //Initialize test
    stringstream strm, ans;
    Spreadsheet sheet;
    fillSheet(sheet);
    sheet.set_selection(new Select_Contains(&sheet, "Last", "Dole"));
    
    std::string str;
    std::fstream file("test_answers/whole_string.txt", std::ios::in);
    while(getline(file, str)) {
        ans<<str<<std::endl;
    }

    //Run test
    sheet.print_selection(strm);

    //Assert
    EXPECT_EQ(ans.str(), strm.str());
}

TEST(Select_Contains, PartialString) {
    //Initialize test
    stringstream strm, ans;
    Spreadsheet sheet;
    fillSheet(sheet);
    sheet.set_selection(new Select_Contains(&sheet, "Last", "on"));
    
    std::string str;
    std::fstream file("test_answers/partial_string.txt", std::ios::in);
    while(getline(file, str)) {
        ans<<str<<std::endl;
    }

    //Run test
    sheet.print_selection(strm);

    //Assert
    EXPECT_EQ(ans.str(), strm.str());
}
