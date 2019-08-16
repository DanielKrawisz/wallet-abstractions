// Copyright (c) 2019 Daniel Krawisz
// Distributed under the Open BSV software license, see the accompanying file LICENSE.

#include <abstractions/wallet/keys.hpp>

namespace abstractions::bitcoin {

    secret::secret(string wif) {
        bytes sec=data::encoding::hex::string(wif);
        std::copy_n(sec.begin(), 32, this->begin());

    };
        namespace wif {
            bool read(const string&, secret&) {
                throw 0;
            }
            
            string write(secret&) {
                throw 0;
            }
            
            bool read(const string&, pubkey&) {
                throw 0;
            }
            
            string write(pubkey&) {
                throw 0;
            }
        }
        
        namespace wif_compressed {
            bool read(const string&, secret&) {
                throw 0;
            }
            
            string write(secret&) {
                throw 0;
            }
            bool read(const string&, pubkey&) {
                throw 0;
            }
            
            string write(pubkey&) {
                throw 0;
            }
        }
        
    }

