#include "node.h"
#include <cstddef>
#define sentinel '*'
node::node()
{
	data = sentinel;
	priority = 0;
	next = NULL;
	left = NULL;
	right = NULL;
}