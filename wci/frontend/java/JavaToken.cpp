/**
 * <h1>PascalToken</h1>
 *
 * <p>Base class for Pascal token classes.</p>
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

map<string, PascalTokenType> PascalToken::RESERVED_WORDS;
map<string, PascalTokenType> PascalToken::SPECIAL_SYMBOLS;
map<PascalTokenType, string> PascalToken::SPECIAL_SYMBOL_NAMES;

bool PascalToken::INITIALIZED = false;

void PascalToken::initialize()
{
    if (INITIALIZED) return;

    vector<string> rw_strings =
    {
        "AND", "ARRAY", "BEGIN", "CASE", "CONST", "DIV", "DO", "DOWNTO",
        "ELSE", "END", "FILE", "FOR", "FUNCTION", "GOTO", "IF", "IN",
        "LABEL", "NIL", "OF", "OR", "PACKED", "PROCEDURE",
        "PROGRAM", "RECORD", "REPEAT", "SET", "THEN", "TO", "TYPE",
        "UNTIL", "VAR", "WHILE", "WITH"
    };

    vector<PascalTokenType> rw_keys =
    {
        PascalTokenType::AND,
        PascalTokenType::ARRAY,
        PascalTokenType::BEGIN,
        PascalTokenType::CASE,
        PascalTokenType::CONST,
        PascalTokenType::DIV,
        PascalTokenType::DO,
        PascalTokenType::DOWNTO,

        PascalTokenType::ELSE,
        PascalTokenType::END,
        PascalTokenType::FILE,
        PascalTokenType::FOR,
        PascalTokenType::FUNCTION,
        PascalTokenType::GOTO,
        PascalTokenType::IF,
        PascalTokenType::IN,

        PascalTokenType::LABEL,
        PascalTokenType::NIL,
        PascalTokenType::OF,
        PascalTokenType::OR,
        PascalTokenType::PACKED,
        PascalTokenType::PROCEDURE,

        PascalTokenType::PROGRAM,
        PascalTokenType::RECORD,
        PascalTokenType::REPEAT,
        PascalTokenType::SET,
        PascalTokenType::THEN,
        PascalTokenType::TO,
        PascalTokenType::TYPE,

        PascalTokenType::UNTIL,
        PascalTokenType::VAR,
        PascalTokenType::WHILE,
        PascalTokenType::WITH
    };

    for (int i = 0; i < rw_strings.size(); i++)
    {
        RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
    }

    vector<string> ss_strings =
    {
//        "+", "-", "*", "/", ":=", ".", ",", ";", ":", "'", "=", "<>",
//        "<", "<=", ">=", ">", "(", ")", "[", "]", "{", "}",  "^", ".."

		"~", "!", "@", "%", "^", "&", "*", "-", "+", "=", "|", "/", ":",
		";", "?", "<", ">", ".", ",", "'", "\"", "(", ")", "[", "]", "{", "}",
		"++", "--", "<<", ">>", "<=", ">=", "+=", "-=", "*=", "/=", "==", "|=",
		"%=", "&=", "^=", "!=", "<<=", ">>=", "||", "&&", "//", "/*", "*/"
    };

    vector<PascalTokenType> ss_keys =
    {
		PascalTokenType::BIT_COMPLEMENT,
		PascalTokenType::NOT,
		PascalTokenType::ANNOTATION,
		PascalTokenType::MOD,
		PascalTokenType::BIT_EXCLUSIVE_OR,
		PascalTokenType::BIT_AND,

		PascalTokenType::MULT,
		PascalTokenType::MINUS,
		PascalTokenType::PLUS,
		PascalTokenType::EQUALS,
		PascalTokenType::BIT_INLCUSIVE_OR,
		PascalTokenType::SLASH,
		PascalTokenType::COLON,

		PascalTokenType::SEMICOLON,
		PascalTokenType::QUESTION_MARK,
		PascalTokenType::LESS_THAN,
		PascalTokenType::GREATER_THAN,
		PascalTokenType::DOT,
		PascalTokenType::COMMA,

		PascalTokenType::QUOTE,
		PascalTokenType::DOUBLE_QUOTE,
		PascalTokenType::LEFT_PAREN,
		PascalTokenType::RIGHT_PAREN,
		PascalTokenType::LEFT_BRACKET,
		PascalTokenType::RIGHT_BRACKET,

		PascalTokenType::LEFT_BRACE,
		PascalTokenType::RIGHT_BRACE,
		PascalTokenType::PLUS_PLUS,
		PascalTokenType::MINUS_MINUS,
		PascalTokenType::SIGNED_LEFT_SHIFT,

		PascalTokenType::SIGNED_RIGHT_SHIFT,
		PascalTokenType::LESS_EQUALS,
		PascalTokenType::GREATER_EQUALS,
		PascalTokenType::PLUS_EQUALS,
		PascalTokenType::MINUS_EQUALS,

		PascalTokenType::MULT_EQUALS,
		PascalTokenType::SLASH_EQUALS,
		PascalTokenType::EQUALS_EQUALS,
		PascalTokenType::EXCLUSIVE_OR_EQUALS,

		PascalTokenType::MOD_EQUALS,
		PascalTokenType::AND_EQUALS,
		PascalTokenType::INCLUSIVE_OR_EQUALS,
		PascalTokenType::NOT_EQUALS,
		PascalTokenType::LEFT_SHIFT_EQUALS,

		PascalTokenType::RIGHT_SHIFT_EQUALS,
		PascalTokenType::LOGIC_OR,
		PascalTokenType::LOGIC_AND,
		PascalTokenType::SLASH_SLASH,
		PascalTokenType::SLASH_STAR,
		PascalTokenType::STAR_SLASH,
//        PascalTokenType::PLUS,
//        PascalTokenType::MINUS,
//        PascalTokenType::STAR,
//        PascalTokenType::SLASH,
//        PascalTokenType::COLON_EQUALS,
//        PascalTokenType::DOT,
//        PascalTokenType::COMMA,
//        PascalTokenType::SEMICOLON,
//        PascalTokenType::COLON,
//        PascalTokenType::QUOTE,
//        PascalTokenType::EQUALS,
//        PascalTokenType::NOT_EQUALS,
//
//        PascalTokenType::LESS_THAN,
//        PascalTokenType::LESS_EQUALS,
//        PascalTokenType::GREATER_EQUALS,
//        PascalTokenType::GREATER_THAN,
//        PascalTokenType::LEFT_PAREN,
//        PascalTokenType::RIGHT_PAREN,
//        PascalTokenType::LEFT_BRACKET,
//        PascalTokenType::RIGHT_BRACKET,
//        PascalTokenType::LEFT_BRACE,
//        PascalTokenType::RIGHT_BRACE,
//        PascalTokenType::UP_ARROW,
//        PascalTokenType::DOT_DOT
//
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
//        "PLUS", "MINUS", "STAR", "SLASH", "COLON_EQUALS", "DOT", "COMMA",
//        "SEMICOLON", "COLON", "QUOTE", "EQUALS", "NOT_EQUALS",
//
//        "LESS_THAN", "LESS_EQUALS", "GREATER_EQUALS", "GREATER_THAN",
//        "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET",
//        "LEFT_BRACE", "RIGHT_BRACE", "UP_ARROW", "DOT_DOT"
    };

    for (int i = 0; i < ss_names.size(); i++)
    {
        SPECIAL_SYMBOL_NAMES[ss_keys[i]] = ss_names[i];
    }

    INITIALIZED = true;
}

PascalToken::PascalToken(Source *source) throw (string)
    : Token(source)
{
    initialize();
}

}}}  // namespace wci::frontend::java
