// Copyright (c) 2019 Daniel Krawisz
// Distributed under the Open BSV software license, see the accompanying file LICENSE.

#include <abstractions/wallet/address.hpp>
#include <abstractions/wallet/keys.hpp>
#include <bitcoin/system/wallet/payment_address.hpp>
#include <abc/src/cashaddr.h>
#include <abstractions/crypto/address.hpp>


namespace abstractions::bitcoin {

    address::address(const pubkey &p) : address{p.address()} {};

    address::address(const secret &s) : address{s.address()} {};

    namespace bitcoin_address {
        address read(const string &base58) {
            libbitcoin::system::wallet::payment_address addr{base58};
            if (!addr) return {};
            libbitcoin::system::short_hash tmp{};
            return {address::digest{data::uint<data::ripemd160::size>{addr.hash()}}};
        }

        data::string write(const address &a) {
            return libbitcoin::system::wallet::payment_address{(const std::array<byte, 20> &) (a)}.encoded();
        }
    }

    namespace cashaddr {
        string prefix = "bitcoincash";

        address read(const string &s) {
            auto p = abc::cashaddr::Decode(s, prefix);
            if (p.first == "") return {};
            data::uint<data::ripemd160::size> addr;
            std::copy_n(p.second.begin(), data::ripemd160::size, addr.begin());
            return {address::digest{data::uint<data::ripemd160::size>{addr}}};
        }

        data::string write(const address& a) {
            std::vector<byte> v{20};
            std::copy(a.Digest.Digest.begin(), a.Digest.Digest.end(), v.begin());
            return abc::cashaddr::Encode(prefix, v);
        }

    }
}
