/*
 * SLLSet.h
 *
 *  Created on: Nov. 17, 2021
 *      Author: moham
 */

#ifndef SRC_SLLSET_H_
#define SRC_SLLSET_H_

#include "SLLNode.h"
#include <string>
#include <string>


class SLLSet {
	private:
		int size;
		SLLNode* head;

	public:
		SLLSet();
		SLLSet(int sortedArray[], int arrSize);
		int getSize();
		SLLSet copy();
		bool isIn(int v);
		void add(int v);
		void remove(int v);
		SLLSet setUnion(SLLSet s);
		SLLSet intersection(SLLSet s);
		SLLSet difference(SLLSet s);
		static SLLSet setUnion(SLLSet sArray[],int size);
	    string toString();
};


#endif /* SRC_SLLSET_H_ */
