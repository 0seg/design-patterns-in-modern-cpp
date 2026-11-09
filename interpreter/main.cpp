#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <cctype>
#include <utility>

// TOKENS

enum class TokenType {
    Number,
    Plus,
    Minus,
    Multiply,
    Divide,
    LeftParen,
    RightParen,
    EndOfFile
};

struct Token {
    TokenType type;
    std::string value;
};

// LEXER

class Lexer {
private:
    std::string input;
    std::size_t position = 0;

    char currentChar() const {
        if (position >= input.size())
            return '\0';

        return input[position];
    }

    void advance() {
        ++position;
    }

    void skipWhitespace() {
        while (std::isspace(static_cast<unsigned char>(currentChar())))
            advance();
    }

    Token makeNumber() {
        std::string number;

        while (std::isdigit(static_cast<unsigned char>(currentChar()))) {
            number += currentChar();
            advance();
        }

        return {TokenType::Number, number};
    }

public:
    explicit Lexer(std::string text) : input(std::move(text)) {}

    std::vector<Token> tokenize() {
        std::vector<Token> tokens;

        while (position < input.size()) {
            skipWhitespace();

            char c = currentChar();

            if (c == '\0')
                break;

            if (std::isdigit(static_cast<unsigned char>(c))) {
                tokens.push_back(makeNumber());
                continue;
            }

            switch (c) {
                case '+':
                    tokens.push_back({TokenType::Plus, "+"});
                    break;

                case '-':
                    tokens.push_back({TokenType::Minus, "-"});
                    break;

                case '*':
                    tokens.push_back({TokenType::Multiply, "*"});
                    break;

                case '/':
                    tokens.push_back({TokenType::Divide, "/"});
                    break;

                case '(':
                    tokens.push_back({TokenType::LeftParen, "("});
                    break;

                case ')':
                    tokens.push_back({TokenType::RightParen, ")"});
                    break;

                default:
                    throw std::runtime_error(
                        std::string("Invalid character: ") + c
                    );
            }

            advance();
        }

        tokens.push_back({TokenType::EndOfFile, ""});

        return tokens;
    }
};

// AST

struct Expression {
    virtual ~Expression() = default;
    virtual int interpret() const = 0;
};

struct NumberExpression : Expression {
    int value;

    explicit NumberExpression(int number) : value(number) {}

    int interpret() const override {
        return value;
    }
};

struct BinaryExpression : Expression {
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
    TokenType operation;

    BinaryExpression(
        std::unique_ptr<Expression> lhs,
        TokenType op,
        std::unique_ptr<Expression> rhs
    )
        : left(std::move(lhs)),
          right(std::move(rhs)),
          operation(op) {}

    int interpret() const override {
        int lhs = left->interpret();
        int rhs = right->interpret();

        switch (operation) {
            case TokenType::Plus:
                return lhs + rhs;

            case TokenType::Minus:
                return lhs - rhs;

            case TokenType::Multiply:
                return lhs * rhs;

            case TokenType::Divide:
                if (rhs == 0)
                    throw std::runtime_error("Division by zero");

                return lhs / rhs;

            default:
                throw std::runtime_error("Unknown operator");
        }
    }
};

// PARSER

class Parser {
private:
    std::vector<Token> tokens;
    std::size_t position = 0;

    Token currentToken() const {
        return tokens[position];
    }

    void eat(TokenType expected) {
        if (currentToken().type != expected)
            throw std::runtime_error("Invalid syntax");

        ++position;
    }

    std::unique_ptr<Expression> factor() {
        Token token = currentToken();

        if (token.type == TokenType::Number) {
            eat(TokenType::Number);

            return std::make_unique<NumberExpression>(
                std::stoi(token.value)
            );
        }

        if (token.type == TokenType::LeftParen) {
            eat(TokenType::LeftParen);

            auto node = expression();

            eat(TokenType::RightParen);

            return node;
        }

        throw std::runtime_error("Expected a number or '('");
    }

    std::unique_ptr<Expression> term() {
        auto node = factor();

        while (
            currentToken().type == TokenType::Multiply ||
            currentToken().type == TokenType::Divide
        ) {
            TokenType op = currentToken().type;
            eat(op);

            node = std::make_unique<BinaryExpression>(
                std::move(node),
                op,
                factor()
            );
        }

        return node;
    }

    std::unique_ptr<Expression> expression() {
        auto node = term();

        while (
            currentToken().type == TokenType::Plus ||
            currentToken().type == TokenType::Minus
        ) {
            TokenType op = currentToken().type;
            eat(op);

            node = std::make_unique<BinaryExpression>(
                std::move(node),
                op,
                term()
            );
        }

        return node;
    }

public:
    explicit Parser(std::vector<Token> input)
        : tokens(std::move(input)) {}

    std::unique_ptr<Expression> parse() {
        auto node = expression();

        if (currentToken().type != TokenType::EndOfFile)
            throw std::runtime_error("Unexpected token");

        return node;
    }
};

// MAIN

int main() {
    std::cout << "Handmade Interpreter\n";
    std::cout << "Enter an expression or type 'exit'.\n\n";

    std::string input;

    while (true) {
        std::cout << "> ";

        if (!std::getline(std::cin, input))
            break;

        if (input == "exit")
            break;

        if (input.empty())
            continue;

        try {
            Lexer lexer(input);

            auto tokens = lexer.tokenize();

            Parser parser(std::move(tokens));

            auto tree = parser.parse();

            std::cout << "= " << tree->interpret() << "\n";
        }
        catch (const std::exception& error) {
            std::cout << "Error: " << error.what() << "\n";
        }
    }

    return 0;
}
