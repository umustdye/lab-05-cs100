#ifndef __SELECT_NOT_CPP__
#define __SELECT_NOT_CPP__

#include "select.hpp"

class Select_Not : public Select
{
    private:
        Select *query;
    
    public:
        Select_Not(Select *query)
        {
            this->query = query;
        }

        ~Select_Not()
        {
            delete query;
        }

        bool select(const Spreadsheet *sheet, int row)
            const override
            {
                return !query->select(sheet, row);
            }
};


#endif /*__SELECT_NOT_CPP__*/
