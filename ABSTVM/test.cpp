#include <boost/spirit/include/classic_push_back_actor.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/classic_core.hpp>
#include <boost/variant.hpp>
#include <string>
#include <vector>
#include <iostream>

using namespace boost::spirit;

template <typename Iterator, typename Skipper>
struct my_grammar : qi::grammar<Iterator, Skipper>
{
	my_grammar() : my_grammar::base_type{value}
	{
		value = (op | push | comment | assert) >> eol;
		push = lit("push") >> (
								lit("int8(")>>int_>>lit(")")
								| lit("int16(")>>int_>>lit(")")
								| lit("int32(")>>int_>>lit(")")
								| lit("float(")>>double_>>lit(")")
								| lit("double(")>>double_>>lit(")")
				             )  
							>> *(comment)
							;
		eol = lit("\n");
		comment = lit(";;");
		assert = lit("assert") >> (int_ | double_) >> *(comment);
		op = (lit("add") | lit("sub") | lit("mul") | lit("div") 
			| lit("mod")| lit("print") | lit("pop") | lit("dump") | lit("exit")) >> *(comment);
	}

	qi::rule<Iterator, Skipper> value, op , assert;
	qi::rule<Iterator, Skipper> push, comment;
};

struct print : public boost::static_visitor<>
{
	template <typename T>
		void operator()(T t) const
		{
			std::cout << std::boolalpha << t << ';';
		}
};

int main()
{
	std::string s;
	while (1)
	{
		std::getline(std::cin, s);
		if (s.empty() || s[0] == 'q' || s[0] == 'Q')
			break;

		auto it = s.begin();
		my_grammar<std::string::iterator, ascii::space_type> g;
		std::vector<boost::variant<int, bool>> v;
		if (qi::phrase_parse(it, s.end(), g, ascii::space))
			std::cout << "Parsing Succesful\n";
		else
			std::cout << "Parsing Failed\n";
	}
}

