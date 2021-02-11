#include "gtest/gtest.h"
#include "select_and.hpp"
#include "select_contains.hpp"
#include "select.hpp"
#include "spreadsheet.hpp"
#include <string>
#include <sstream>


void fillSheetAnd(Spreadsheet &sheet)
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

TEST(Select_And, emptySheet1)
{
    Spreadsheet sheet;
    sheet.set_column_names({"Name", "Job"});
    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "", ""), new Select_Contains(&sheet, "", "")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "");
}



TEST(Select_And, emptySheet2)
{
    Spreadsheet sheet;
    sheet.set_column_names({"Name", "Job"});
    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "Name", "Barbara"), new Select_Contains(&sheet, "", "")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "");
}



TEST(Select_And, emptySheet3)
{
    Spreadsheet sheet;
    sheet.set_column_names({"Name", "Job"});
    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "Name", "Barbara"), new Select_Contains(&sheet, "Job", "Financing")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "");
}


TEST(Select_And, emptySheetEmptyColumn1)
{
    Spreadsheet sheet;
    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "", ""), new Select_Contains(&sheet, "", "")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "");
}



TEST(Select_And, emptySheetEmptyColumn2)
{
    Spreadsheet sheet;
    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "Name", "Barbaba"), new Select_Contains(&sheet, "", "")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "");
}



TEST(Select_And, emptySheetEmptyColumn3)
{
    Spreadsheet sheet;
    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "Name", "Barbara"), new Select_Contains(&sheet, "Job", "Financing")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "");
}



TEST(Select_And, columnDNE)
{
    Spreadsheet sheet;
    fillSheetAnd(sheet);
    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "Grade", "A"), new Select_Contains(&sheet, "Major", "computer science")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "");
}


TEST(Select_And, valueDNE)
{
    Spreadsheet sheet;
    fillSheetAnd(sheet);
    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "Last", "Smith"), new Select_Contains(&sheet, "Major", "computer science")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "");
}



TEST(Select_And, oneRow)
{
    Spreadsheet sheet;
    fillSheetAnd(sheet);
    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "Last", "Dole"), new Select_Contains(&sheet, "Major", "computer engineering")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "Diane Dole 20 computer engineering \n");
}



TEST(Select_And, moreThanOneRow)
{
    Spreadsheet sheet;
    fillSheetAnd(sheet);
    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "Age", "21"), new Select_Contains(&sheet, "Major", "computer science")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "Brian Becker 21 computer science \nCarol Conners 21 computer science \nSarah Summers 21 computer science \n");
}


TEST(Select_And, fullSheetEmptyQuery)
{
    Spreadsheet sheet;
    fillSheetAnd(sheet);
    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "", ""), new Select_Contains(&sheet, "", "")));
    std::stringstream ss;
    sheet.print_selection(ss);
    std::string s = ss.str();
    EXPECT_EQ(s, "");
}
