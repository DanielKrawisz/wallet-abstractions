//
// Created by nekosune on 16/08/2019.
//
//
#include <data/types.hpp>
#include <abstractions/wallet/keys.hpp>
#include <abstractions/wallet/address.hpp>
#include "gtest/gtest.h"

struct test_data {
    data::string secret_wif;
    data::string secret_wif_uncompressed;
    data::string pubkey_hex;
    data::string pubkey_hex_uncompressed;
    data::string addr_58;
    data::string cashaddr;

    test_data(data::string pSecret_wif,
              data::string pSecret_wif_uncompressed,
              data::string pPubkey_hex,
              data::string pPubkey_hex_uncompressed,
              data::string pAddr_58,
              data::string pCashaddr) : secret_wif{pSecret_wif}, secret_wif_uncompressed{pSecret_wif_uncompressed},
                                        pubkey_hex{pPubkey_hex}, pubkey_hex_uncompressed{pPubkey_hex_uncompressed},
                                        addr_58{pAddr_58}, cashaddr{pCashaddr} {}
};

class Stage1Test : public testing::TestWithParam<test_data> {
public:
    abstractions::bitcoin::secret SecretWIF;
    abstractions::bitcoin::secret SecretWIFUncompressed;
    abstractions::bitcoin::pubkey PubkeyHex;
    abstractions::bitcoin::pubkey PubkeyHexUncompressed;
    abstractions::bitcoin::address AddressBase58;
    abstractions::bitcoin::address AddressCashaddr;
protected:
    void SetUp() override {
        SecretWIF = abstractions::bitcoin::secret(GetParam().secret_wif);

    }

};

TEST_P(Stage1Test,SecretWIFValid) {
    EXPECT_TRUE(this->SecretWIF.valid()) << "Secret WIF is not valid";
}


test_data test_dat[] = {
        test_data("L2rW8amvjR19iSZ1wVU9keXBqEjQ9fMSCw9bsSKSmSCXTxqfz2Bn",
                  "5K6KqPc6q8FXyWogBXvH2jV8tiB4S5AALUDpmxadei44jTV6p4S",
                  "02DE7A990579BCA352633D340F05E7E7158661B0DCA0BA40A5AB5E0328A312216F",
                  "04DE7A990579BCA352633D340F05E7E7158661B0DCA0BA40A5AB5E0328A312216FF40F50C2B6E03D863B19B9B679787FB75634F8BD00C2F2400196999CC9AB8E76",
                  "1AWfki61q1phyV1SA6Ytp38c9Ft5kipwV8",
                  "qp59tzmez92uts6y8pk72ax0dvee6an9agq3wk4zkh"),
        test_data("KzmVx4hyCB6GAQoxMQae8GnokPG2hrJCP6Z7EjZS9MJZhf7pbpmW",
                  "5Jcun6poGDi4tXKLnrkRGhHGaPiU7zPUW2FyhGXupf8c3xFKwA5",
                  "023EA79C33BC21008356CA4C0E06A896014D94AD5216F54C44A3A94E1C8B39B1B1",
                  "043EA79C33BC21008356CA4C0E06A896014D94AD5216F54C44A3A94E1C8B39B1B1F252B4B35D4CA96B8C6D7601A75D36F06BDB333B0E4F0C13C5E4004E49C5FE2A",
                  "1DKsEVtWQ6QGWBQ32fVDuCYQasxawApdqm",
                  "qzrn9mwtv7hm8ezuanh3wk78wumtflc9msjqmh7pu4"),
        test_data("L2HMpTWtyCdQkhL1tTQDSP4ssw7DVazacTBEzkAv1DSi8jjask6a",
                  "5JxpK17mrSHrnhQLgkbG42q1CYHpEj94Y9CPCixGBUHhb32UErf",
                  "03F063CDE7542B8FA3BC55739B44DA63B38AEE8583CD9E3C351D0BB2F5968D6805",
                  "04F063CDE7542B8FA3BC55739B44DA63B38AEE8583CD9E3C351D0BB2F5968D6805BBB8F5C9ACEBB8DA15610B68DE0B2EE6441BD54D1893E06618C8E320010DCA17",
                  "13GYJRir1xn5cyVWqLzQPaiZr9BLJdfKAv",
                  "qqvwp852xycjuf5erjyq0d7rnvyc0vsj0vjrmn0rpw"),
        test_data("L1vXPxhPFAe5taRGcmxcUuKKmmnbV1Q59TazBTFwHsVugRhQbGJU",
                  "5Jt6XaTpdjxyqqojWQKwiDJkDs2GWuerRaDEQfaHqEFhwGeMMo3",
                  "035A5CA5E685803CB8CD54198F3CFD71187F85F940EAECCE0D5D6551911306738C",
                  "045A5CA5E685803CB8CD54198F3CFD71187F85F940EAECCE0D5D6551911306738C636205F2C171613EBDA6A345D1078D359B985C829B6E4715BC93BBEDD4E7740B",
                  "1DXj3zwApeKaSCyEZD5Pjkzai8p5XmwxzY",
                  "qzyhz96ud6hz40mmzw4nlgv5f7pk7dzxnqe9dp23lh")
};
INSTANTIATE_TEST_SUITE_P(Stage1Tests,Stage1Test,testing::ValuesIn(test_dat));