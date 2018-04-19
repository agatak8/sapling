#pragma once
#include "../token/Token.h"
#include "IO.h"
#include <memory>
#include <functional>

class Scanner {
    public:
        Scanner(std::shared_ptr<InputReader> reader);
        Token getNextToken();
    private:
        std::function<bool(char)> whiteSpace = [](char c) -> bool { return c <= ' '; };
        std::function<bool(char)> alphanumericOrUnderscore = [](char c) -> bool { 
            return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
        };
        std::function<bool(char)> digit = [](char c) -> bool { 
            return (c >= '0' && c <= '9');
        };
        std::function<bool(char)> stringable = [](char c) -> bool { 
            return (c >= ' ' && c <= '~' && c != '"');
        };

        bool alphaToken();
        bool equalsCharacterToken();
        bool braceToken();
        bool valueToken();
        bool separatorToken();
        bool operatorToken();
        bool eotToken();

        void readNextToken();

        void throwUnknownToken();
        void throwInvalidString();

        Token currentToken;
        std::shared_ptr<InputReader> reader;
};