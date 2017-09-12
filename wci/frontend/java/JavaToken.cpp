/**
 * <h1>JavaToken</h1>
 *
 * <p>Base class for Java token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "JavaToken.h"

#include <string>
#include <vector>
#include <map>

namespace wci { namespace frontend { namespace java {

using namespace std;

map<string, JavaTokenType> JavaToken::RESERVED_WORDS;
map<string, JavaTokenType> JavaToken::SPECIAL_SYMBOLS;
map<JavaTokenType, string> JavaToken::SPECIAL_SYMBOL_NAMES;

bool JavaToken::INITIALIZED = false;

void JavaToken::initialize()
{
    if (INITIALIZED) return;

    vector<string> rw_strings =
    {
		"abstract", "break", "case", "char", "class", "const", "continue", "do",
		"double", "else", "enum", "extends", "float", "for", "goto", "if"
		"int", "long", "native", "return", "short", "package", "protected", "static",
		"switch", "super", "this", "throw", "void", "volatile", "while"
    };

    vector<JavaTokenType> rw_keys =
    {
		JavaTokenType::ABSTRACT,
		JavaTokenType::BREAK,
		JavaTokenType::CASE,
		JavaTokenType::CHAR,
		JavaTokenType::CLASS,
		JavaTokenType::CONST,
		JavaTokenType::CONTINUE,
		JavaTokenType::DO,

		JavaTokenType::DOUBLE,
		JavaTokenType::ELSE,
		JavaTokenType::ENUM,
		JavaTokenType::EXTENDS,
		JavaTokenType::FLOAT,
		JavaTokenType::FOR,
		JavaTokenType::GOTO,
		JavaTokenType::IF,

		JavaTokenType::INT,
		JavaTokenType::LONG,
		JavaTokenType::NATIVE,
		JavaTokenType::RETURN,
		JavaTokenType::SHORT,
		JavaTokenType::PACKAGE,
		JavaTokenType::PROTECTED,
		JavaTokenType::BIT_COMPLEMENT,

		JavaTokenType::SWITCH,
		JavaTokenType::SUPER,
		JavaTokenType::THIS,
		JavaTokenType::THROW,
		JavaTokenType::VOID,
		JavaTokenType::VOLATILE,
		JavaTokenType::WHILE
    };

    for (int i = 0; i < rw_strings.size(); i++)
    {
        RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
    }

    vector<string> ss_strings =
    {
		"~", "!", "@", "%", "^", "&", "*", "-", "+", "=", "|", "/", ":",
		";", "?", "<", ">", ".", ",", "'", "\"", "(", ")", "[", "]", "{", "}",
		"++", "--", "<<", ">>", "<=", ">=", "+=", "-=", "*=", "/=", "==", "|=",
		"%=", "&=", "^=", "!=", "<<=", ">>=", "||", "&&", "//", "/*", "*/"
    };

    vector<JavaTokenType> ss_keys =
    {
		JavaTokenType::BIT_COMPLEMENT,
		JavaTokenType::NOT,
		JavaTokenType::ANNOTATION,
		JavaTokenType::MOD,
		JavaTokenType::BIT_EXCLUSIVE_OR,
		JavaTokenType::BIT_AND,

		JavaTokenType::MULT,
		JavaTokenType::MINUS,
		JavaTokenType::PLUS,
		JavaTokenType::EQUALS,
		JavaTokenType::BIT_INLCUSIVE_OR,
		JavaTokenType::SLASH,
		JavaTokenType::COLON,

		JavaTokenType::SEMICOLON,
		JavaTokenType::QUESTION_MARK,
		JavaTokenType::LESS_THAN,
		JavaTokenType::GREATER_THAN,
		JavaTokenType::DOT,
		JavaTokenType::COMMA,

		JavaTokenType::QUOTE,
		JavaTokenType::DOUBLE_QUOTE,
		JavaTokenType::LEFT_PAREN,
		JavaTokenType::RIGHT_PAREN,
		JavaTokenType::LEFT_BRACKET,
		JavaTokenType::RIGHT_BRACKET,

		JavaTokenType::LEFT_BRACE,
		JavaTokenType::RIGHT_BRACE,
		JavaTokenType::PLUS_PLUS,
		JavaTokenType::MINUS_MINUS,
		JavaTokenType::SIGNED_LEFT_SHIFT,

		JavaTokenType::SIGNED_RIGHT_SHIFT,
		JavaTokenType::LESS_EQUALS,
		JavaTokenType::GREATER_EQUALS,
		JavaTokenType::PLUS_EQUALS,
		JavaTokenType::MINUS_EQUALS,

		JavaTokenType::MULT_EQUALS,
		JavaTokenType::SLASH_EQUALS,
		JavaTokenType::EQUALS_EQUALS,
		JavaTokenType::EXCLUSIVE_OR_EQUALS,

		JavaTokenType::MOD_EQUALS,
		JavaTokenType::AND_EQUALS,
		JavaTokenType::INCLUSIVE_OR_EQUALS,
		JavaTokenType::NOT_EQUALS,
		JavaTokenType::LEFT_SHIFT_EQUALS,

		JavaTokenType::RIGHT_SHIFT_EQUALS,
		JavaTokenType::LOGIC_OR,
		JavaTokenType::LOGIC_AND,
		JavaTokenType::SLASH_SLASH,
		JavaTokenType::SLASH_STAR,
		JavaTokenType::STAR_SLASH
    };

    for (int i = 0; i < ss_strings.size(); i++)
    {
        SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
    }

    vector<string> ss_names =
    {
		"BIT_COMPLEMENT", "NOT", "ANNOTATION", "MOD", "BIT_EXCLUSIVE_OR", "BIT_AND",
		"MULT", "MINUS", "PLUS", "EQUALS", "BIT_INLCUSIVE_OR", "SLASH", "COLON",
		"SEMICOLON", "QUESTION_MARK", "LESS_THAN", "GREATER_THAN", "DOT", "COMMA",
		"QUOTE", "DOUBLE_QUOTE", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET",
		"LEFT_BRACE", "RIGHT_BRACE", "PLUS_PLUS", "MINUS_MINUS", "SIGNED_LEFT_SHIFT",
		"SIGNED_RIGHT_SHIFT", "LESS_EQUALS", "GREATER_EQUALS", "PLUS_EQUALS", "MINUS_EQUALS",
		"MULT_EQUALS", "SLASH_EQUALS", "EQUALS_EQUALS", "EXCLUSIVE_OR_EQUALS",
		"MOD_EQUALS", "AND_EQUALS", "INCLUSIVE_OR_EQUALS", "NOT_EQUALS", "LEFT_SHIFT_EQUALS",
		"RIGHT_SHIFT_EQUALS", "LOGIC_OR", "LOGIC_AND", "SLASH_SLASH", "SLASH_STAR", "STAR_SLASH"
    };

    for (int i = 0; i < ss_names.size(); i++)
    {
        SPECIAL_SYMBOL_NAMES[ss_keys[i]] = ss_names[i];
    }

    INITIALIZED = true;
}

JavaToken::JavaToken(Source *source) throw (string)
    : Token(source)
{
    initialize();
}

}}}  // namespace wci::frontend::java
