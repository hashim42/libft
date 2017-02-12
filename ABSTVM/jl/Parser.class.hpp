
class Parser {

	Parser(std::string const & filename);
	Parser(); //read stdin

	void load() throw();
	void verify() const throw();

	void execute() const throw();
	
	class ParserException : public std::exception {
		ParserException();
		virtual ~ParserException() throw();
		ParserException(ParserException const &);
		ParserException &operator=(ParserException const &);
		virtual std::string &what() const throw();
	}
}
