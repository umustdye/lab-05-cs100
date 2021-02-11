#ifndef SELECT_CONTAINS
#define SELECT_CONTAINS

#include "select.hpp"

class Select_Contains : public Select_Column {
    private:
        std::string val;

    public:
        Select_Contains(const Spreadsheet *sheet, std::string col, std::string val) : Select_Column(sheet, col), val(val) {}
        ~Select_Contains() {}
        bool select(const std::string &str) const {
            if(val.size() > str.size()) return false;
            if(val.empty()) return true;
            for(int i = 0, j = 0; i < str.size(); ++i) {
                if(val[j] == str[i]) {
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
