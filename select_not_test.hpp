#include "gtest/gtest.h"
#include "select_not.hpp"
#include "select_contains.hpp"
#include "select.hpp"
#include "spreadsheet.hpp"
#include <string>
#include <sstream>
#include <fstream>


void fillSheetNot(Spreadsheet &sheet)
{
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

TEST(Select_Not, emptySheet1)
{
    Spreadsheet sheet;
    sheet.set_column_names({"Name", "Job"});
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "", "")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "");
}



TEST(Select_Not, emptySheet2)
{
    Spreadsheet sheet;
    sheet.set_column_names({"Name", "Job"});
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "Name", "Barbara")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "");
}



TEST(Select_Not, emptySheetEmptyColumn1)
{
    Spreadsheet sheet;
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "", "")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "");
}



TEST(Select_Not, emptySheetEmptyColumn2)
{
    Spreadsheet sheet;
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "Name", "Barbaba")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "");
}



TEST(Select_Not, columnDNE)
{
    Spreadsheet sheet;
    fillSheetNot(sheet);
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "Grade", "A")));
    std::stringstream ans, strm;
    std::string str;
    std::fstream file("test_answers/null_select.txt", std::ios::in);
    while(getline(file, str)) {
        ans<<str<<std::endl;
    }

    //Run test
    sheet.print_selection(strm);

    //Assert
    EXPECT_EQ(ans.str(), strm.str());
}


TEST(Select_Not, valueExist)
{
    Spreadsheet sheet;
    fillSheetNot(sheet);
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "Last", "Dole")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "Amanda Andrews 22 business \nBrian Becker 21 computer science \nCarol Conners 21 computer science \nJoe Jackson 21 mathematics \nSarah Summers 21 computer science \nGeorge Genius 9 astrophysics \n");
}


