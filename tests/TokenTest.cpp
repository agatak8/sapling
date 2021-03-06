#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "TokenTest"
#include <boost/test/unit_test.hpp>
#include "../token/Token.h"

BOOST_AUTO_TEST_SUITE(TokenTest)

BOOST_AUTO_TEST_CASE(get_type_after_default_constructor_returns_eot) {
    Token t;
    BOOST_CHECK_EQUAL(t.getType(), TokenType::EOT);
}

BOOST_AUTO_TEST_CASE(get_type_after_type_constructor_returns_given_type) {
    Token t1(TokenType::CURLY_BRACE_OPEN), t2(TokenType::LESS_THAN), t3(TokenType::LET);
    BOOST_CHECK_EQUAL(t1.getType(), TokenType::CURLY_BRACE_OPEN);
    BOOST_CHECK_EQUAL(t2.getType(), TokenType::LESS_THAN);
    BOOST_CHECK_EQUAL(t3.getType(), TokenType::LET);
}

BOOST_AUTO_TEST_CASE(get_type_after_set_int_returns_int_value) {
    Token t;
    t.setInt(413);
    BOOST_CHECK_EQUAL(t.getType(), TokenType::INT_VALUE);
}

BOOST_AUTO_TEST_CASE(get_int_after_set_int_returns_integer) {
    Token t;
    t.setInt(413);
    BOOST_CHECK_EQUAL(t.getInt(), 413);
}

BOOST_AUTO_TEST_CASE(get_string_after_set_string_returns_string) {
    Token t;
    t.setString("string123");
    BOOST_CHECK_EQUAL(t.getString(), "string123");
}

BOOST_AUTO_TEST_SUITE_END()