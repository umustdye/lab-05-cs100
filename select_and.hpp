#ifndef __SELECT_AND_CPP__
#define __SELECT_AND_CPP__

#include "select.hpp"


class Select_And: public Select
{
	private:
		Select* left;
		Select* right;

	public:
		
		Select_And(Select* left, Select* right)
		{
 			this->left = left;
			this->right = right;
		}
		

		~Select_And()
		{
			delete left;
			delete right;
		}

		bool select(const Spreadsheet *sheet, int row) 
		const override
		{
			return left->select(sheet, row) && right->select(sheet, row);
		}
};

#endif //__SELECT_AND_CPP__
