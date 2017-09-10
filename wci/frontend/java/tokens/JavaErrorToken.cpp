/**
 * <h1>PascalErrorToken</h1>
 *
 * <p>Pascal error token.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "JavaErrorToken.h"

#include "../../Token.h"
#include "../JavaToken.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend::java;

PascalErrorToken::PascalErrorToken(Source *source, PascalErrorCode error_code,
                                   string token_text)
    throw (string)
    : PascalToken(source)
{
    type = (TokenType) PT_ERROR;
    text = token_text;
    value = new DataValue((int) error_code);
}

void PascalErrorToken::extract() throw (string)
{
    // do nothing
}

}}}}  // namespace wci::frontend::pascal::tokens
