#ifndef SELECT_CONTAINS
#define SELECT_CONTAINS

#include "select.hpp"

using std::tolower;

class Select_Contains : public Select_Column {
    private:
        std::string val;

    public:
        Select_Contains(const Spreadsheet *sheet, std::string col, std::string val) : Select_Column(sheet, col), val(val) {}
        ~Select_Contains() {}
        bool select(const std::string &str) const {
            if(val.empty() || val.size() > str.size()) return false;
            for(int i = 0, j = 0; i < str.size(); ++i) {
                if(tolower(val[j]) == tolower(str[i])) {
                    ++j;
                    if(j == val.size()) return true;
                } else {
                    j = 0;
                }
            }
            return false;
        }
};

#endif
