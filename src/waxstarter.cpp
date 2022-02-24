#include <waxstarter.hpp>

ACTION waxstarter::sayhi(name user, string message) {
    require_auth(user);

    // save data to blockchain
    messages.emplace(user, [&](messages_s &row) {
        row.user = user;
        row.message = message;
    });
}