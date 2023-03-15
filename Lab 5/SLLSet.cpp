/*
 * SLLSet.cpp
 *
 *  Created on: Nov. 17, 2021
 *      Author: moham
 */


#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet()
{
	size = 0;
	head = NULL;
}

SLLSet::SLLSet(int sortedArray[], int arrSize)
{
	SLLNode* node_next = NULL;
	size = arrSize;
	head = node_next;
	for (int i = arrSize - 1; i >= 0; i--)
	{
		SLLNode* node_prev = new SLLNode(sortedArray[i], node_next);
		node_next = node_prev;
	}
	head = node_next;

}

int SLLSet::getSize()
{
	return size;
}

SLLSet SLLSet::copy(){
	SLLNode* node = head;
	int i = 0;
	int output[size] = {0}; 
	while(node != NULL)
	{
		output[i++]=(node -> value);
		node = node -> next;
	}

	SLLSet* s_copy = new SLLSet(output,size);

	 return *(s_copy);
}
bool SLLSet::isIn(int v){
	SLLNode*node = head; 
		for (int i = 0; i < size; i++)
		{ 
		    	if (node -> value == v)
		    	{
		    		return true;
		    	}
		    	node = node -> next;
		}
			return false;
}

void SLLSet::add(int v)
{
	if(!isIn(v))
	{
		SLLNode* node_old = head;
		SLLNode* node_new = new SLLNode(v,NULL);
		if(size == 0)
		{
			head = node_new;
		}
		else if((node_old->value) > v)
		{
			node_new -> next = head;
			head = node_new;
		}
		else
		{
			for(int i = 0; i < size; i++)
			{
				if((node_old -> next) == NULL || (node_old -> next -> value) > v)
				{
					node_new -> next = node_old -> next;
					node_old -> next = node_new;
					break;
				}
				node_old = node_old -> next;
			}
		}
		size++;

	}
}


void SLLSet::remove(int v)
{
	if (isIn(v))
	{
		SLLNode* currNode = head;
		SLLNode* nextNode = currNode->next;
		if (currNode->value == v)
		{
			head= currNode->next;
			size--;
		}
	else
	{
		while (currNode!=NULL)
		{
			if(nextNode->value == v)
			{
				currNode->next = nextNode->next;
				delete nextNode;
				size--;
			}
			currNode=currNode->next;
			nextNode=nextNode->next;

		}

   }

	}
}

SLLSet SLLSet::setUnion(SLLSet s)
{
	SLLSet* set_final = new SLLSet();
	SLLNode* node_final = new SLLNode();
	set_final -> size = 0;

	SLLNode* node1 = head;
	SLLNode* node2 = s.head;

	if (node1 == NULL && node2 == NULL)
	{
		return *set_final;
	}
	else if (node1 == NULL)
	{
		*set_final = s.copy();
		return *set_final;
	}
	else if (node2 == NULL)
	{
		*set_final = copy();
		return *set_final;
	}

	if (node1 -> value < node2 -> value)
	{
		node_final = new SLLNode(node1->value,NULL);
		node1=node1->next;
	}
	else if(node1->value == node2->value)
	{
		node_final= new SLLNode(node1->value,NULL);
		node1 = node1->next;
		node2 = node2->next;
	}
	else
	{
		node_final = new SLLNode(node2->value,NULL);
		node2=node2 -> next;
	}
	set_final -> head = node_final;
	set_final -> size++;


	while(node1 != NULL && node2 != NULL)
	{
		if (node1->value < node2->value)
		{
			node_final->next = new SLLNode(node1->value,NULL);
			node1=node1->next;
		}
		else if(node1->value == node2->value)
		{
			node_final->next= new SLLNode(node1->value,NULL);
			node1 = node1->next;
			node2 = node2->next;
		}
		else
		{
			node_final->next = new SLLNode(node2->value,NULL);
			node2=node2->next;
		}
		node_final = node_final->next;
		set_final->size++;

	}

	while(node1 != NULL)
	{
		node_final->next =new SLLNode(node1->value,NULL);
		node1=node1->next;
		node_final=node_final->next;
		set_final->size++;
	}
	while(node2!=NULL)
	{
			node_final->next =new SLLNode(node2->value,NULL);
			node2=node2->next;
			node_final=node_final->next;
			set_final->size++;
	}
	return (*set_final);
}
SLLSet SLLSet::intersection(SLLSet s)
{

	SLLNode* node1 = head;
	SLLNode* node2 = s.head;

	SLLNode* node_last = new SLLNode();
	SLLSet* set_last = new SLLSet();
	set_last->size=0;


	if(node1== NULL||node2==NULL )
	{
		return *set_last;
	}
	while(node1!= NULL&&node2!=NULL){
		if(node1->value > node2->value)
		{
			node2 = node2->next;

		}
		else if(node1->value < node2->value)
		{
			node1=node1->next;
		}
		else if(node1->value == node2->value)
		{
			node_last = new SLLNode(node1->value,NULL);
			node1 = node1->next;
			node2 = node2->next;
			set_last -> head = node_last;
			set_last->size++;
			break;
		}
	}

	while(node1!= NULL&&node2!=NULL)
	{
			if(node1->value > node2->value){
				node2=node2->next;
			}
			else if(node1->value < node2->value){
				node1= node1->next;
			}
			else if(node1->value == node2->value){
				node_last->next = new SLLNode(node1->value,NULL);
				node1 = node1->next;
				node2 = node2->next;
				node_last = node_last->next;
				set_last->size++;

			}
		}
	 return *(set_last);
}
SLLSet SLLSet::difference(SLLSet s)
{
	SLLSet list_diff = SLLSet();
	SLLNode* node = head;
	for (int i = 0; i < size; i++)
	{
		if (s.isIn(node->value) == false)
		{
			list_diff.add(node->value);
		}
		node= node->next;
	}
	 return (list_diff);
}
SLLSet SLLSet::setUnion(SLLSet sArray[],int size)
{
	SLLSet* set_final = new SLLSet();
	set_final->size = 0;
	if (size==0)
	{
		return *set_final;
	}
	for (int i = 0; i < size; i++)
	{
		*set_final = set_final->setUnion(sArray[i]);
	}
	 return *(set_final);
}
string SLLSet::toString()
{	SLLNode* node = head;
	string output="";
	while (node!=NULL){
		if (node->next == NULL){
			output+=to_string(node->value);
		}
		else{
		output += to_string(node->value);
		output += ", ";
		}
		node = node->next;
	}
   return output;
}
