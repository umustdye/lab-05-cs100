#ifndef SELECT_OR
#define SELECT_OR

#include "select.hpp"

class Select_Or : public Select {
    private:
        Select *left;
        Select *right;

    public:
        Select_Or(Select *left, Select *right) : left(left), right(right) {}
        ~Select_Or() {
            delete left;
            delete right;
        }
        bool select(const Spreadsheet *sheet, int row) const override {
            return left->select(sheet, row) || right->select(sheet, row);
        }
};

#endif
