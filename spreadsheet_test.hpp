#include "gtest/gtest.h"
#include <sstream>
#include <fstream>
using std::stringstream;

// SPREADSHEET TEST
TEST(SpreadsheetTest, NullSelect) {
    //Initialize test
    stringstream strm, ans;
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
    
    std::string str;
    std::fstream file("test_answers/null_select.txt", std::ios::in);
    while(getline(file, str)) {
        ans<<str<<std::endl;
    }

    //Run test
    sheet.print_selection(strm);

    //Assert
    EXPECT_EQ(strm.str(), ans.str());
}
