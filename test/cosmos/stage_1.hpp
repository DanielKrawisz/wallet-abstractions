// Copyright (c) 2019 Daniel Krawisz
// Distributed under the Open BSV software license, see the accompanying file LICENSE.

#ifndef TEST_COSMOS_STAGE_1
#define TEST_COSMOS_STAGE_1

#include <abstractions/wallet/keys.hpp>
#include <abstractions/wallet/address.hpp>
#include <data/for_each.hpp>

#include "gtest/gtest.h"

namespace abstractions::bitcoin::cosmos::test {
    struct failure {};
    
    class one {
        secret SecretWIF;
        secret SecretWIFUncompressed;
        pubkey PubkeyHex;
        pubkey PubkeyHexUncompressed;
        address AddressBase58;
        address AddressCashaddr;
    public:
        one(string secret_wif,
            string secret_wif_uncompressed,
            string pubkey_hex,
            string pubkey_hex_uncompressed,
            string addr_58,
            string cashaddr);
        
        secret key() const {
            return SecretWIF;
        }
        
        static vector<one> cases();
        
    };
    
    vector<secret> keys();
    
}

#endif 
