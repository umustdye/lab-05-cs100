#include "spreadsheet.hpp"
#include "select_or.hpp"
#include "select_contains.hpp"
#include "gtest/gtest.h"
#include <sstream>
#include <fstream>

TEST(Select_Or, BothFalse) {
    //Initialize
    std::stringstream strm;
    Spreadsheet sheet;
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
    Select *select = new Select_Or(new Select_Contains(&sheet, "Major", "Band"), new Select_Contains(&sheet, "First", "Heidi"));
    sheet.set_selection(select);

    //Run test
    sheet.print_selection(strm);

    //Assert
    EXPECT_EQ("", strm.str());

    //Run test
}

TEST(Select_Or, LeftFalse) {
    //Initialize
    std::stringstream strm, ans;
    Spreadsheet sheet;
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
    Select *select = new Select_Or(new Select_Contains(&sheet, "Major", "Band"), new Select_Contains(&sheet, "First", "ia"));
    sheet.set_selection(select);

    std::string str;
    std::fstream file("test_answers/or_left.txt", std::ios::in);
    while(getline(file, str)) {
        ans<<str<<std::endl;
    }

    //Run test
    sheet.print_selection(strm);

    //Assert
    EXPECT_EQ(ans.str(), strm.str());
}

TEST(Select_Or, RightFalse) {
    //Initialize
    std::stringstream strm, ans;
    Spreadsheet sheet;
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
    Select *select = new Select_Or(new Select_Contains(&sheet, "Major", "science"), new Select_Contains(&sheet, "First", "Heidi"));
    sheet.set_selection(select);

    std::string str;
    std::fstream file("test_answers/or_right.txt", std::ios::in);
    while(getline(file, str)) {
        ans<<str<<std::endl;
    }

    //Run test
    sheet.print_selection(strm);

    //Assert
    EXPECT_EQ(ans.str(), strm.str());
}

TEST(Select_Or, BothTrue) {
    //Initialize
    std::stringstream strm, ans;
    Spreadsheet sheet;
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
    Select *select = new Select_Or(new Select_Contains(&sheet, "Major", "computer"), new Select_Contains(&sheet, "First", "Dominick"));
    sheet.set_selection(select);

    std::string str;
    std::fstream file("test_answers/or_both.txt", std::ios::in);
    while(getline(file, str)) {
        ans<<str<<std::endl;
    }

    //Run test
    sheet.print_selection(strm);

    //Assert
    EXPECT_EQ(ans.str(), strm.str());
}
