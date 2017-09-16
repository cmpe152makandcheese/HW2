cmake_minimum_required(VERSION 3.8)
project(Pascal)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Pascal.cpp Pascal.h
        wci/frontend/FrontendFactory.cpp
        wci/frontend/Parser.cpp
        wci/frontend/Scanner.cpp
        wci/frontend/Token.cpp
        wci/frontend/Source.cpp
        wci/frontend/pascal/PascalParserTD.cpp
        wci/frontend/pascal/PascalScanner.cpp
        wci/frontend/pascal/PascalError.cpp
        wci/frontend/pascal/PascalErrorHandler.cpp
        wci/frontend/pascal/PascalToken.cpp
        wci/frontend/pascal/tokens/PascalErrorToken.cpp
        wci/frontend/pascal/tokens/PascalNumberToken.cpp
        wci/frontend/pascal/tokens/PascalSpecialSymbolToken.cpp
        wci/frontend/pascal/tokens/PascalStringToken.cpp
        wci/frontend/pascal/tokens/PascalWordToken.cpp
        wci/backend/BackendFactory.cpp
        wci/backend/Backend.cpp
        wci/backend/interpreter/Executor.cpp
        wci/backend/compiler/CodeGenerator.cpp
        wci/message/Message.cpp
        wci/message/MessageHandler.cpp
        wci/frontend/FrontendFactory.h
        wci/frontend/Parser.h
        wci/frontend/Scanner.h
        wci/frontend/Token.h
        wci/frontend/Source.h
        wci/frontend/pascal/PascalParserTD.h
        wci/frontend/pascal/PascalScanner.h
        wci/frontend/pascal/PascalError.h
        wci/frontend/pascal/PascalErrorHandler.h
        wci/frontend/pascal/PascalToken.h
        wci/frontend/pascal/tokens/PascalErrorToken.h
        wci/frontend/pascal/tokens/PascalNumberToken.h
        wci/frontend/pascal/tokens/PascalSpecialSymbolToken.h
        wci/frontend/pascal/tokens/PascalStringToken.h
        wci/frontend/pascal/tokens/PascalWordToken.h
        wci/backend/BackendFactory.h
        wci/backend/Backend.h
        wci/backend/interpreter/Executor.h
        wci/backend/compiler/CodeGenerator.h
        wci/message/Message.h
        wci/message/MessageHandler.h

        wci/frontend/java/JavaError.h
        wci/frontend/java/JavaErrorHandler.h
        wci/frontend/java/JavaParserTD.h
        wci/frontend/java/JavaScanner.h
        wci/frontend/java/JavaToken.h

        wci/frontend/java/JavaError.cpp
        wci/frontend/java/JavaErrorHandler.cpp
        wci/frontend/java/JavaParserTD.cpp
        wci/frontend/java/JavaScanner.cpp
        wci/frontend/java/JavaToken.cpp

        wci/frontend/java/tokens/JavaErrorToken.cpp
        wci/frontend/java/tokens/JavaNumberToken.cpp
        wci/frontend/java/tokens/JavaSpecialSymbolToken.cpp
        wci/frontend/java/tokens/JavaStringToken.cpp
        wci/frontend/java/tokens/JavaWordToken.cpp

        wci/frontend/java/tokens/JavaErrorToken.h
        wci/frontend/java/tokens/JavaNumberToken.h
        wci/frontend/java/tokens/JavaSpecialSymbolToken.h
        wci/frontend/java/tokens/JavaStringToken.h
        wci/frontend/java/tokens/JavaWordToken.h

        wci/frontend/java/tokens/JavaCharacterToken.cpp
        wci/frontend/java/tokens/JavaCharacterToken.h)
add_executable(Pascal ${SOURCE_FILES})