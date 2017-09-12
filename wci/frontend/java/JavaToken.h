/**
 * <h1>JavaToken</h1>
 *
 * <p>Base class for Java token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */

#ifndef WCI_FRONTEND_JAVA_JAVATOKEN_H_
#define WCI_FRONTEND_JAVA_JAVATOKEN_H_

#include <string>
#include <map>
#include "../Token.h"
#include "../Source.h"

namespace wci { namespace frontend { namespace java {

using namespace std;
using namespace wci::frontend;

/**
 * Java token types.
 */
enum class JavaTokenType
{
    // Reserved words.
	ABSTRACT, BREAK, CASE, CHAR, CLASS, CONST, CONTINUE, DO,
	DOUBLE, ELSE, ENUM, EXTENDS, FLOAT, FOR, GOTO, IF,
	INT, LONG, NATIVE, RETURN, SHORT, PACKAGE, PROTECTED, STATIC,
	SWITCH, SUPER, THIS, THROW, VOID, VOLATILE, WHILE,

    // Special symbols.
	BIT_COMPLEMENT, NOT, ANNOTATION, MOD, HAT, BIT_AND,
	MULT, MINUS, PLUS, EQUALS, BIT_INLCUSIVE_OR, SLASH, COLON,
	SEMICOLON, QUESTION_MARK, LESS_THAN, GREATER_THAN, DOT, COMMA,
	QUOTE, DOUBLE_QUOTE, LEFT_PAREN, RIGHT_PAREN, LEFT_BRACKET, RIGHT_BRACKET,
	LEFT_BRACE, RIGHT_BRACE, PLUS_PLUS, MINUS_MINUS, SIGNED_LEFT_SHIFT,
	SIGNED_RIGHT_SHIFT, LESS_EQUALS, GREATER_EQUALS, PLUS_EQUALS, MINUS_EQUALS,
	MULT_EQUALS, SLASH_EQUALS, EQUAL_EQUALS, EXCLUSIVE_OR_EQUALS,
	MOD_EQUALS, AND_EQUALS, INCLUSIVE_OR_EQUALS, NOT_EQUALS, LSHIFT_EQUALS,
	RSHIFT_EQUALS, LOGIC_OR, LOGIC_AND, SLASH_SLASH, SLASH_STAR, STAR_SLASH,

    IDENTIFIER, INTEGER, REAL, STRING,
    ERROR, END_OF_FILE,
};

constexpr JavaTokenType PT_ABSTRACT = JavaTokenType::ABSTRACT;
constexpr JavaTokenType PT_BREAK = JavaTokenType::BREAK;
constexpr JavaTokenType PT_CASE = JavaTokenType::CASE;
constexpr JavaTokenType PT_CHAR = JavaTokenType::CHAR;
constexpr JavaTokenType PT_CLASS = JavaTokenType::CLASS;
constexpr JavaTokenType PT_CONST = JavaTokenType::CONST;
constexpr JavaTokenType PT_CONTINUE = JavaTokenType::CONTINUE;
constexpr JavaTokenType PT_DO = JavaTokenType::DO;

constexpr JavaTokenType PT_DOUBLE = JavaTokenType::DOUBLE;
constexpr JavaTokenType PT_ELSE = JavaTokenType::ELSE;
constexpr JavaTokenType PT_ENUM = JavaTokenType::ENUM;
constexpr JavaTokenType PT_EXTENDS = JavaTokenType::EXTENDS;
constexpr JavaTokenType PT_FLOAT = JavaTokenType::FLOAT;
constexpr JavaTokenType PT_FOR = JavaTokenType::FOR;
constexpr JavaTokenType PT_GOTO = JavaTokenType::GOTO;
constexpr JavaTokenType PT_IF = JavaTokenType::IF;

constexpr JavaTokenType PT_INT = JavaTokenType::INT;
constexpr JavaTokenType PT_LONG = JavaTokenType::LONG;
constexpr JavaTokenType PT_NATIVE = JavaTokenType::NATIVE;
constexpr JavaTokenType PT_RETURN = JavaTokenType::RETURN;
constexpr JavaTokenType PT_SHORT = JavaTokenType::SHORT;
constexpr JavaTokenType PT_PACKAGE = JavaTokenType::PACKAGE;
constexpr JavaTokenType PT_PROTECTED = JavaTokenType::PROTECTED;
constexpr JavaTokenType PT_STATIC = JavaTokenType::BIT_COMPLEMENT;

constexpr JavaTokenType PT_SWITCH = JavaTokenType::SWITCH;
constexpr JavaTokenType PT_SUPER = JavaTokenType::SUPER;
constexpr JavaTokenType PT_THIS = JavaTokenType::THIS;
constexpr JavaTokenType PT_THROW = JavaTokenType::THROW;
constexpr JavaTokenType PT_VOID = JavaTokenType::VOID;
constexpr JavaTokenType PT_VOLATILE = JavaTokenType::VOLATILE;
constexpr JavaTokenType PT_WHILE = JavaTokenType::WHILE;

constexpr JavaTokenType PT_BIT_COMPLEMENT = JavaTokenType::BIT_COMPLEMENT;
constexpr JavaTokenType PT_NOT = JavaTokenType::NOT;
constexpr JavaTokenType PT_ANNOTATION = JavaTokenType::ANNOTATION;
constexpr JavaTokenType PT_MOD = JavaTokenType::MOD;
constexpr JavaTokenType PT_HAT = JavaTokenType::HAT;
constexpr JavaTokenType PT_BIT_AND = JavaTokenType::BIT_AND;

constexpr JavaTokenType PT_MULT = JavaTokenType::MULT;
constexpr JavaTokenType PT_MINUS = JavaTokenType::MINUS;
constexpr JavaTokenType PT_PLUS = JavaTokenType::PLUS;
constexpr JavaTokenType PT_EQUALS = JavaTokenType::EQUALS;
constexpr JavaTokenType PT_BIT_INLCUSIVE_OR = JavaTokenType::BIT_INLCUSIVE_OR;
constexpr JavaTokenType PT_SLASH = JavaTokenType::SLASH;
constexpr JavaTokenType PT_COLON = JavaTokenType::COLON;

constexpr JavaTokenType PT_SEMICOLON = JavaTokenType::SEMICOLON;
constexpr JavaTokenType PT_QUESTION_MARK = JavaTokenType::QUESTION_MARK;
constexpr JavaTokenType PT_LESS_THAN = JavaTokenType::LESS_THAN;
constexpr JavaTokenType PT_GREATER_THAN = JavaTokenType::GREATER_THAN;
constexpr JavaTokenType PT_DOT = JavaTokenType::DOT;
constexpr JavaTokenType PT_COMMA = JavaTokenType::COMMA;

constexpr JavaTokenType PT_QUOTE = JavaTokenType::QUOTE;
constexpr JavaTokenType PT_DOUBLE_QUOTE = JavaTokenType::DOUBLE_QUOTE;
constexpr JavaTokenType PT_LEFT_PAREN = JavaTokenType::LEFT_PAREN;
constexpr JavaTokenType PT_RIGHT_PAREN = JavaTokenType::RIGHT_PAREN;
constexpr JavaTokenType PT_LEFT_BRACKET = JavaTokenType::LEFT_BRACKET;
constexpr JavaTokenType PT_RIGHT_BRACKET = JavaTokenType::RIGHT_BRACKET;

constexpr JavaTokenType PT_LEFT_BRACE = JavaTokenType::LEFT_BRACE;
constexpr JavaTokenType PT_RIGHT_BRACE = JavaTokenType::RIGHT_BRACE;
constexpr JavaTokenType PT_PLUS_PLUS = JavaTokenType::PLUS_PLUS;
constexpr JavaTokenType PT_MINUS_MINUS = JavaTokenType::MINUS_MINUS;
constexpr JavaTokenType PT_SIGNED_LEFT_SHIFT = JavaTokenType::SIGNED_LEFT_SHIFT;

constexpr JavaTokenType PT_SIGNED_RIGHT_SHIFT = JavaTokenType::SIGNED_RIGHT_SHIFT;
constexpr JavaTokenType PT_LESS_EQUALS = JavaTokenType::LESS_EQUALS;
constexpr JavaTokenType PT_GREATER_EQUALS = JavaTokenType::GREATER_EQUALS;
constexpr JavaTokenType PT_PLUS_EQUALS = JavaTokenType::PLUS_EQUALS;
constexpr JavaTokenType PT_MINUS_EQUALS = JavaTokenType::MINUS_EQUALS;

constexpr JavaTokenType PT_MULT_EQUALS = JavaTokenType::MULT_EQUALS;
constexpr JavaTokenType PT_SLASH_EQUALS = JavaTokenType::SLASH_EQUALS;
constexpr JavaTokenType PT_EQUAL_EQUALS = JavaTokenType::EQUAL_EQUALS;
constexpr JavaTokenType PT_EXCLUSIVE_OR_EQUALS = JavaTokenType::EXCLUSIVE_OR_EQUALS;

constexpr JavaTokenType PT_MOD_EQUALS = JavaTokenType::MOD_EQUALS;
constexpr JavaTokenType PT_AND_EQUALS = JavaTokenType::AND_EQUALS;
constexpr JavaTokenType PT_INCLUSIVE_OR_EQUALS = JavaTokenType::INCLUSIVE_OR_EQUALS;
constexpr JavaTokenType PT_NOT_EQUALS = JavaTokenType::NOT_EQUALS;
constexpr JavaTokenType PT_LSHIFT_EQUALS = JavaTokenType::LSHIFT_EQUALS;

constexpr JavaTokenType PT_RSHIFT_EQUALS = JavaTokenType::RSHIFT_EQUALS;
constexpr JavaTokenType PT_LOGIC_OR = JavaTokenType::LOGIC_OR;
constexpr JavaTokenType PT_LOGIC_AND = JavaTokenType::LOGIC_AND;
constexpr JavaTokenType PT_SLASH_SLASH = JavaTokenType::SLASH_SLASH;
constexpr JavaTokenType PT_SLASH_STAR = JavaTokenType::SLASH_STAR;
constexpr JavaTokenType PT_STAR_SLASH = JavaTokenType::STAR_SLASH;

constexpr JavaTokenType PT_IDENTIFIER = JavaTokenType::IDENTIFIER;
constexpr JavaTokenType PT_INTEGER = JavaTokenType::INTEGER;
constexpr JavaTokenType PT_REAL = JavaTokenType::REAL;
constexpr JavaTokenType PT_STRING = JavaTokenType::STRING;
constexpr JavaTokenType PT_ERROR = JavaTokenType::ERROR;
constexpr JavaTokenType PT_END_OF_FILE = JavaTokenType::END_OF_FILE;

class JavaToken : public Token
{
public:
    static map<string, JavaTokenType> RESERVED_WORDS;
    static map<string, JavaTokenType> SPECIAL_SYMBOLS;
    static map<JavaTokenType, string> SPECIAL_SYMBOL_NAMES;

protected:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    JavaToken(Source *source) throw (string);

private:
    static bool INITIALIZED;

    /**
     * Initialize the static maps.
     */
    static void initialize();
};

}}}  // namespace wci::frontend::java

#endif /* WCI_FRONTEND_JAVA_JAVATOKEN_H_ */
