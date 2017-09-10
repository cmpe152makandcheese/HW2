/**
 * <h1>PascalStringToken</h1>
 *
 * <p> Pascal string tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_PASCAL_TOKENS_PASCALSTRINGTOKEN_H_
#define WCI_FRONTEND_PASCAL_TOKENS_PASCALSTRINGTOKEN_H_

#include <string>

#include "../JavaToken.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend::java;

class PascalStringToken : public PascalToken
{
public:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    PascalStringToken(Source *source) throw (string);

protected:
    /**
     * Extract a Pascal string token from the source.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};

}}}}  // namespace wci::frontend::pascal::tokens

#endif /* WCI_FRONTEND_PASCAL_TOKENS_PASCALSTRINGTOKEN_H_ */
