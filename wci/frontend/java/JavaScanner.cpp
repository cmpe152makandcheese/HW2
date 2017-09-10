/**
 * <h1>PascalScanner</h1>
 *
 * <p>The Pascal scanner.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "JavaScanner.h"

#include <iostream>
#include "../Source.h"
#include "JavaError.h"
#include "JavaToken.h"
#include "tokens/JavaErrorToken.h"
#include "tokens/JavaNumberToken.h"
#include "tokens/JavaSpecialSymbolToken.h"
#include "tokens/JavaStringToken.h"
#include "tokens/JavaWordToken.h"

namespace wci { namespace frontend { namespace java {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::java::tokens;

PascalScanner::PascalScanner(Source *source) : Scanner(source)
{
}

Token *PascalScanner::extract_token() throw (string)
{
    skip_white_space();

    Token *token;
    char current_ch = current_char();
    string string_ch = " ";

    string_ch[0] = current_ch;

    // Construct the next token.  The current character determines the
    // token type.
    if (current_ch == Source::END_OF_FILE)
    {
        token = nullptr;
    }
    else if (isalpha(current_ch))
    {
        token = new PascalWordToken(source);
    }
    else if (isdigit(current_ch))
    {
        token = new PascalNumberToken(source);
    }
    else if (current_ch == '\'')
    {
        token = new PascalStringToken(source);
    }
    else if (PascalToken::SPECIAL_SYMBOLS.find(string_ch)
                != PascalToken::SPECIAL_SYMBOLS.end())
    {
        token = new PascalSpecialSymbolToken(source);
    }
    else
    {
        token = new PascalErrorToken(source, INVALID_CHARACTER, string_ch);
        next_char();  // consume character
    }

    return token;
}

void PascalScanner::skip_white_space() throw (string)
{
    char current_ch = current_char();
    bool block_comment_finish = false;

    while (isspace(current_ch) || (current_ch == '/')) {

        // Start of a comment?
        if (current_ch == '/')
        {
        	char peek_ch = peek_char();

//        	current_ch = next_char(); // consume to check next character
        	// One line comment
        	if (peek_ch == '/')
        	{
        		// Consume whole line
        		do
				{
        			current_ch = next_char();  // consume comment characters
				} while (current_ch != Source::END_OF_LINE);
        	}
        	// Block comment
        	else if (peek_ch == '*')
        	{
        		// Consume /*
        		current_ch = next_char();
        		current_ch = next_char();
        		do
				{
        			if (block_comment_finish)
					{
						if (current_ch == '/')
						{
							current_ch = next_char();
							break;
						}
						else if (current_ch != '*')
						{
							block_comment_finish = false;
						}
						current_ch = next_char();
					}
        			if (current_ch == '*' && !block_comment_finish)
        			{
        				block_comment_finish = true;
        			}
					current_ch = next_char();  // consume comment characters
				} while (current_ch != Source::END_OF_FILE);
        	}
        	else
        	{
        		// It is not a comment, it is only a single /
        		break;
        	}
        }

        // Not a comment.
        else current_ch = next_char();  // consume whitespace character
    }
}

}}} // namespace wci::frontend::java
