#include <iomanip>
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
#include "node.h"
#include <sstream>
using namespace std;

node::node(record record_)
{
	this->data = record_;
}
