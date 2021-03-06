#include "arbitrage_tester.hpp"

BOOST_AUTO_TEST_SUITE(on_transfer_tests)

BOOST_FIXTURE_TEST_CASE(arbitrage_asserts_on_transfer_test, arbitrage_tester)
try {
    WASM_ASSERT("on_transfer: deposit account is not exist",
                iq.transfer(N(alice), arb.contract, asset::from_string("1.000 IQ"), ""));
}
FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE(on_transfer_test, arbitrage_tester)
try {
    extended_symbol iq_token_sym{symbol(SY(3, IQ)), N(everipediaiq)};
    SUCCESS(arb.open(N(alice), N(alice), iq_token_sym, N(alice)));

    SUCCESS(iq.transfer(N(alice), arb.contract, asset::from_string("1.000 IQ"), ""));

    auto alice_deposit = arb.get_deposit(N(alice), 0);
    auto balance = alice_deposit["balance"].get_object();
    
    BOOST_REQUIRE_EQUAL(alice_deposit["id"], fc::variant(0)); 
    REQUIRE_MATCHING_OBJECT(balance, mvo()("quantity", "1.000 IQ")("contract", "everipediaiq"));
}
FC_LOG_AND_RETHROW()

BOOST_AUTO_TEST_SUITE_END()
