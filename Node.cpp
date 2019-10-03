#include "Node.h"
#include <iostream>

const Node* Node::operator->() const
{
	return this;
}