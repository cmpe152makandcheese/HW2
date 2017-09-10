/**
 * <h1>PascalToken</h1>
 *
 * <p>Base class for Pascal token classes.</p>
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
 * Pascal token types.
 */
enum class PascalTokenType
{
    // Reserved words.
	ABSTRACT, BREAK, CASE, CHAR, CLASS, CONST, CONTINUE, DO,
	DOUBLE, ELSE, ENUM, EXTENDS, FLOAT, FOR, GOTO, IF,
	INT, LONG, NATIVE, RETURN, SHORT, PACKAGE, PROTECTED, STATIC,
	SWITCH, SUPER, THIS, THROW, VOID, VOLATILE, WHILE,

    // Special symbols.
	BIT_COMPLEMENT, NOT, ANNOTATION, MOD, BIT_EXCLUSIVE_OR, BIT_AND,
	MULT, MINUS, PLUS, EQUALS, BIT_INLCUSIVE_OR, SLASH, COLON,
	SEMICOLON, QUESTION_MARK, LESS_THAN, GREATER_THAN, DOT, COMMA,
	QUOTE, DOUBLE_QUOTE, LEFT_PAREN, RIGHT_PAREN, LEFT_BRACKET, RIGHT_BRACKET,
	LEFT_BRACE, RIGHT_BRACE, PLUS_PLUS, MINUS_MINUS, SIGNED_LEFT_SHIFT,
	SIGNED_RIGHT_SHIFT, LESS_EQUALS, GREATER_EQUALS, PLUS_EQUALS, MINUS_EQUALS,
	MULT_EQUALS, SLASH_EQUALS, EQUALS_EQUALS, EXCLUSIVE_OR_EQUALS,
	MOD_EQUALS, AND_EQUALS, INCLUSIVE_OR_EQUALS, NOT_EQUALS, LEFT_SHIFT_EQUALS,
	RIGHT_SHIFT_EQUALS, LOGIC_OR, LOGIC_AND, SLASH_SLASH, SLASH_STAR, STAR_SLASH,

    IDENTIFIER, INTEGER, REAL, STRING,
    ERROR, END_OF_FILE,
};

constexpr PascalTokenType PT_ABSTRACT = PascalTokenType::ABSTRACT;
constexpr PascalTokenType PT_BREAK = PascalTokenType::BREAK;
constexpr PascalTokenType PT_CASE = PascalTokenType::CASE;
constexpr PascalTokenType PT_CHAR = PascalTokenType::CHAR;
constexpr PascalTokenType PT_CLASS = PascalTokenType::CLASS;
constexpr PascalTokenType PT_CONST = PascalTokenType::CONST;
constexpr PascalTokenType PT_CONTINUE = PascalTokenType::CONTINUE;
constexpr PascalTokenType PT_DO = PascalTokenType::DO;

constexpr PascalTokenType PT_DOUBLE = PascalTokenType::DOUBLE;
constexpr PascalTokenType PT_ELSE = PascalTokenType::ELSE;
constexpr PascalTokenType PT_ENUM = PascalTokenType::ENUM;
constexpr PascalTokenType PT_EXTENDS = PascalTokenType::EXTENDS;
constexpr PascalTokenType PT_FLOAT = PascalTokenType::FLOAT;
constexpr PascalTokenType PT_FOR = PascalTokenType::FOR;
constexpr PascalTokenType PT_GOTO = PascalTokenType::GOTO;
constexpr PascalTokenType PT_IF = PascalTokenType::IF;

constexpr PascalTokenType PT_INT = PascalTokenType::INT;
constexpr PascalTokenType PT_LONG = PascalTokenType::LONG;
constexpr PascalTokenType PT_NATIVE = PascalTokenType::NATIVE;
constexpr PascalTokenType PT_RETURN = PascalTokenType::RETURN;
constexpr PascalTokenType PT_SHORT = PascalTokenType::SHORT;
constexpr PascalTokenType PT_PACKAGE = PascalTokenType::PACKAGE;
constexpr PascalTokenType PT_PROTECTED = PascalTokenType::PROTECTED;
constexpr PascalTokenType PT_STATIC = PascalTokenType::BIT_COMPLEMENT;

constexpr PascalTokenType PT_SWITCH = PascalTokenType::SWITCH;
constexpr PascalTokenType PT_SUPER = PascalTokenType::SUPER;
constexpr PascalTokenType PT_THIS = PascalTokenType::THIS;
constexpr PascalTokenType PT_THROW = PascalTokenType::THROW;
constexpr PascalTokenType PT_VOID = PascalTokenType::VOID;
constexpr PascalTokenType PT_VOLATILE = PascalTokenType::VOLATILE;
constexpr PascalTokenType PT_WHILE = PascalTokenType::WHILE;

constexpr PascalTokenType PT_BIT_COMPLEMENT = PascalTokenType::BIT_COMPLEMENT;
constexpr PascalTokenType PT_NOT = PascalTokenType::NOT;
constexpr PascalTokenType PT_ANNOTATION = PascalTokenType::ANNOTATION;
constexpr PascalTokenType PT_MOD = PascalTokenType::MOD;
constexpr PascalTokenType PT_BIT_EXCLUSIVE_OR = PascalTokenType::BIT_EXCLUSIVE_OR;
constexpr PascalTokenType PT_BIT_AND = PascalTokenType::BIT_AND;

constexpr PascalTokenType PT_MULT = PascalTokenType::MULT;
constexpr PascalTokenType PT_MINUS = PascalTokenType::MINUS;
constexpr PascalTokenType PT_PLUS = PascalTokenType::PLUS;
constexpr PascalTokenType PT_EQUALS = PascalTokenType::EQUALS;
constexpr PascalTokenType PT_BIT_INLCUSIVE_OR = PascalTokenType::BIT_INLCUSIVE_OR;
constexpr PascalTokenType PT_SLASH = PascalTokenType::SLASH;
constexpr PascalTokenType PT_COLON = PascalTokenType::COLON;

constexpr PascalTokenType PT_SEMICOLON = PascalTokenType::SEMICOLON;
constexpr PascalTokenType PT_QUESTION_MARK = PascalTokenType::QUESTION_MARK;
constexpr PascalTokenType PT_LESS_THAN = PascalTokenType::LESS_THAN;
constexpr PascalTokenType PT_GREATER_THAN = PascalTokenType::GREATER_THAN;
constexpr PascalTokenType PT_DOT = PascalTokenType::DOT;
constexpr PascalTokenType PT_COMMA = PascalTokenType::COMMA;

constexpr PascalTokenType PT_QUOTE = PascalTokenType::QUOTE;
constexpr PascalTokenType PT_DOUBLE_QUOTE = PascalTokenType::DOUBLE_QUOTE;
constexpr PascalTokenType PT_LEFT_PAREN = PascalTokenType::LEFT_PAREN;
constexpr PascalTokenType PT_RIGHT_PAREN = PascalTokenType::RIGHT_PAREN;
constexpr PascalTokenType PT_LEFT_BRACKET = PascalTokenType::LEFT_BRACKET;
constexpr PascalTokenType PT_RIGHT_BRACKET = PascalTokenType::RIGHT_BRACKET;

constexpr PascalTokenType PT_LEFT_BRACE = PascalTokenType::LEFT_BRACE;
constexpr PascalTokenType PT_RIGHT_BRACE = PascalTokenType::RIGHT_BRACE;
constexpr PascalTokenType PT_PLUS_PLUS = PascalTokenType::PLUS_PLUS;
constexpr PascalTokenType PT_MINUS_MINUS = PascalTokenType::MINUS_MINUS;
constexpr PascalTokenType PT_SIGNED_LEFT_SHIFT = PascalTokenType::SIGNED_LEFT_SHIFT;

constexpr PascalTokenType PT_SIGNED_RIGHT_SHIFT = PascalTokenType::SIGNED_RIGHT_SHIFT;
constexpr PascalTokenType PT_LESS_EQUALS = PascalTokenType::LESS_EQUALS;
constexpr PascalTokenType PT_GREATER_EQUALS = PascalTokenType::GREATER_EQUALS;
constexpr PascalTokenType PT_PLUS_EQUALS = PascalTokenType::PLUS_EQUALS;
constexpr PascalTokenType PT_MINUS_EQUALS = PascalTokenType::MINUS_EQUALS;

constexpr PascalTokenType PT_MULT_EQUALS = PascalTokenType::MULT_EQUALS;
constexpr PascalTokenType PT_SLASH_EQUALS = PascalTokenType::SLASH_EQUALS;
constexpr PascalTokenType PT_EQUALS_EQUALS = PascalTokenType::EQUALS_EQUALS;
constexpr PascalTokenType PT_EXCLUSIVE_OR_EQUALS = PascalTokenType::EXCLUSIVE_OR_EQUALS;

constexpr PascalTokenType PT_MOD_EQUALS = PascalTokenType::MOD_EQUALS;
constexpr PascalTokenType PT_AND_EQUALS = PascalTokenType::AND_EQUALS;
constexpr PascalTokenType PT_INCLUSIVE_OR_EQUALS = PascalTokenType::INCLUSIVE_OR_EQUALS;
constexpr PascalTokenType PT_NOT_EQUALS = PascalTokenType::NOT_EQUALS;
constexpr PascalTokenType PT_LEFT_SHIFT_EQUALS = PascalTokenType::LEFT_SHIFT_EQUALS;

constexpr PascalTokenType PT_RIGHT_SHIFT_EQUALS = PascalTokenType::RIGHT_SHIFT_EQUALS;
constexpr PascalTokenType PT_LOGIC_OR = PascalTokenType::LOGIC_OR;
constexpr PascalTokenType PT_LOGIC_AND = PascalTokenType::LOGIC_AND;
constexpr PascalTokenType PT_SLASH_SLASH = PascalTokenType::SLASH_SLASH;
constexpr PascalTokenType PT_SLASH_STAR = PascalTokenType::SLASH_STAR;
constexpr PascalTokenType PT_STAR_SLASH = PascalTokenType::STAR_SLASH;

constexpr PascalTokenType PT_IDENTIFIER = PascalTokenType::IDENTIFIER;
constexpr PascalTokenType PT_INTEGER = PascalTokenType::INTEGER;
constexpr PascalTokenType PT_REAL = PascalTokenType::REAL;
constexpr PascalTokenType PT_STRING = PascalTokenType::STRING;
constexpr PascalTokenType PT_ERROR = PascalTokenType::ERROR;
constexpr PascalTokenType PT_END_OF_FILE = PascalTokenType::END_OF_FILE;

class PascalToken : public Token
{
public:
    static map<string, PascalTokenType> RESERVED_WORDS;
    static map<string, PascalTokenType> SPECIAL_SYMBOLS;
    static map<PascalTokenType, string> SPECIAL_SYMBOL_NAMES;

protected:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    PascalToken(Source *source) throw (string);

private:
    static bool INITIALIZED;

    /**
     * Initialize the static maps.
     */
    static void initialize();
};

}}}  // namespace wci::frontend::java

#endif /* WCI_FRONTEND_JAVA_JAVATOKEN_H_ */
