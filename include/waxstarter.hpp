#pragma once

#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

CONTRACT waxstarter : public contract {
   public:
    using contract::contract;

    // define actions in here
    ACTION sayhi(name user, string message);

   private:
    // define tables in here
    TABLE messages_s {
        name user;
        string message;

        uint64_t primary_key() const { return user.value; };
    };

    // define table and types
    typedef multi_index<"messages"_n, messages_s> messages_t;

    // initialize tables (do this only if all data is owned by the contract itself)
    messages_t messages = messages_t(_self, _self.value);
};