#include <iostream>
#include "grammar.h"
#include <cassert>

using namespace std;

int	main()
{
	assert(Grammar::isDigit("0"));
	assert(Grammar::isDigit("1"));
	assert(Grammar::isDigit("3.14"));
	assert(Grammar::isDigit("-2"));
	assert(Grammar::isDigit("-4.414"));
	assert(!Grammar::isDigit("a"));
	assert(!Grammar::isDigit("-b"));
	assert(!Grammar::isDigit("a1"));
	assert(!Grammar::isDigit("-c3.6"));

	assert(Grammar::isGrammar("+")); 
	assert(Grammar::isGrammar("-")); 
	assert(Grammar::isGrammar("*")); 
	assert(Grammar::isGrammar("/")); 
	assert(Grammar::isGrammar("^")); 

	assert(!Grammar::isGrammar("a")); 
	assert(!Grammar::isGrammar("-a")); 
	assert(!Grammar::isGrammar("1")); 
	assert(!Grammar::isGrammar("3.2")); 
	assert(!Grammar::isGrammar("-4")); 
	assert(!Grammar::isGrammar("-5.666")); 

	assert(Grammar::isLeft("+"));
	assert(Grammar::isLeft("-"));
	assert(Grammar::isLeft("*"));
	assert(Grammar::isLeft("/"));
	assert(!Grammar::isLeft("^"));

	assert(Grammar::priority("+"));
	assert(Grammar::priority("-"));
	assert(Grammar::priority("*"));
	assert(Grammar::priority("/"));
	assert(Grammar::priority("^"));

	cout << "OK" << endl;
}
