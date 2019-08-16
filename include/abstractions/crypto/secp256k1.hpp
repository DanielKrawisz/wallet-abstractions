// Copyright (c) 2018-2019 Daniel Krawisz
// Distributed under the Open BSV software license, see the accompanying file LICENSE.

#ifndef ABSTRACTIONS_CRYPTO_SECP256K1
#define ABSTRACTIONS_CRYPTO_SECP256K1

#include <data/crypto/secp256k1.hpp>
#include <abstractions/crypto/hash/sha256.hpp>
#include <abstractions/crypto/hash/ripemd160.hpp>
#include <abstractions/wallet/address.hpp>

namespace abstractions::secp256k1 {
    
    using signature = data::crypto::secp256k1::signature;
    
    using secret = data::crypto::secp256k1::secret;
    
    using compressed_pubkey = data::crypto::secp256k1::compressed_pubkey;
    using uncompressed_pubkey = data::crypto::secp256k1::uncompressed_pubkey;
    
    inline ripemd160::digest address(const compressed_pubkey& p) {
        return ripemd160::hash<data::crypto::secp256k1::compressed_pubkey_size>(p);
    }
    
    inline ripemd160::digest address(const uncompressed_pubkey& p) {
        return ripemd160::hash<data::crypto::secp256k1::uncompressed_pubkey_size>(p);
    }
    
    inline ripemd160::digest address_uncompressed(const secret& s) {
        return address(s.to_public_uncompressed());
    }
    
    inline ripemd160::digest address_compressed(const secret& s) {
        return address(s.to_public_compressed());
    }
    
} 

#endif

