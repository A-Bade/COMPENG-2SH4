/*
 * SLLNode.cpp
 *
 *  Created on: Nov. 17, 2021
 *      Author: moham
 */

#include "SLLNode.h"

SLLNode::SLLNode (int i, SLLNode* n) {
        value = i;
        next = n;
}
SLLNode::SLLNode () {
        value = 0;
        next = NULL;
}
