/**
 * <h1>PascalStringToken</h1>
 *
 * <p> Pascal string tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "JavaCharacterToken.h"

#include <string>
#include "../JavaError.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::java;

JavaCharacterToken::JavaCharacterToken(Source *source) throw (string)
        : JavaToken(source)
{
    extract();
}

void JavaCharacterToken::extract() throw (string)
{
    string value_str = "";

    char current_ch = next_char();  // consume initial quote
    text += "'";

    // Replace any whitespace character with a blank.
    if (isspace(current_ch)) current_ch = ' ';

    // Handles single forward slash
    if (current_ch == '\\') {
        text += current_ch;
        value_str += current_ch;
        current_ch = next_char();  // consume character
    }

    // Handles All other characters
    if ((current_ch != '\'') && (current_ch != EOF))
    {
        text += current_ch;
        value_str  += current_ch;
        current_ch = next_char();  // consume character
    }

    // Handles single quote next to single quote
    if (current_ch == '\'' && (peek_char() == '\''))
    {
        text += current_ch;
        value_str  += current_ch;
        current_ch = next_char();  // consume character

        text += current_ch;
        type = (TokenType) PT_CHAR;
        value = new DataValue(value_str);

        next_char(); // consume final quote
    }
    else if (current_ch == '\'')
    {
        next_char();  // consume final quote
        text += '\'';
        type = (TokenType) PT_CHAR;
        value = new DataValue(value_str);
    }
    else
    {
        type = (TokenType) PT_ERROR;
        value = new DataValue((int) UNEXPECTED_EOF);
    }
}

}}}}  // namespace wci::frontend::java::tokens
