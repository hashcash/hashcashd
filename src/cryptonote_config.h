// Copyright (c) 2014-2018, The Monero Project
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#pragma once

#include <string>
#include <vector>
#include <boost/uuid/uuid.hpp>

#define CRYPTONOTE_DNS_TIMEOUT_MS                       20000

#define CRYPTONOTE_MAX_BLOCK_NUMBER                     ((uint64_t)(-1))
#define CRYPTONOTE_MAX_BLOCK_SIZE                       500000000  // block header blob limit, never used!
#define CRYPTONOTE_GETBLOCKTEMPLATE_MAX_BLOCK_SIZE      196608 //size of block (bytes) that is the maximum that miners will produce
#define CRYPTONOTE_MAX_TX_SIZE                          1000000000
#define CRYPTONOTE_PUBLIC_ADDRESS_TEXTBLOB_VER          0
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW            10
#define CURRENT_TRANSACTION_VERSION                     2
#define CURRENT_BLOCK_MAJOR_VERSION                     1
#define CURRENT_BLOCK_MINOR_VERSION                     0
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT              60*60*2
#define CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE             10

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW               60

// MONEY_SUPPLY - total number coins to be generated
#define MONEY_SUPPLY                                    ((uint64_t)(-1))
#define EMISSION_SPEED_FACTOR_PER_MINUTE                (32)
#define FINAL_SUBSIDY_PER_MINUTE                        ((uint64_t)100)

#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                 100
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2    60000 //size of block (bytes) after which reward for block calculated using block size
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1    20000 //size of block (bytes) after which reward for block calculated using block size - before first fork
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5    300000 //size of block (bytes) after which reward for block calculated using block size - second change, from v5
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE          600
#define CRYPTONOTE_DISPLAY_DECIMAL_POINT                2
// COIN - number of smallest units in one coin
#define COIN                                            ((uint64_t)100) // pow(10, 2)

#define FEE_PER_KB_OLD                                  ((uint64_t)1) // pow(10, 10)
#define FEE_PER_KB                                      ((uint64_t)10) // 2 * pow(10, 9)
#define DYNAMIC_FEE_PER_KB_BASE_FEE                     ((uint64_t)2) // 2 * pow(10,9)
#define DYNAMIC_FEE_PER_KB_BASE_BLOCK_REWARD            ((uint64_t)1000000000) // 10 * pow(10,12)
#define DYNAMIC_FEE_PER_KB_BASE_FEE_V5                  ((uint64_t)2) // ((uint64_t)2 * (uint64_t)CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2 / CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5)

#define ORPHANED_BLOCKS_MAX_COUNT                       100


#define DIFFICULTY_TARGET_V2                            600  // seconds
#define DIFFICULTY_TARGET_V1                            600  // seconds - before first fork
#define DIFFICULTY_WINDOW                               720 // blocks
#define DIFFICULTY_LAG                                  15  // !!!
#define DIFFICULTY_CUT                                  60  // timestamps to cut after sorting
#define DIFFICULTY_BLOCKS_COUNT                         DIFFICULTY_WINDOW + DIFFICULTY_LAG


#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V1   DIFFICULTY_TARGET_V1 * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V2   DIFFICULTY_TARGET_V2 * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS       1


#define DIFFICULTY_BLOCKS_ESTIMATE_TIMESPAN             DIFFICULTY_TARGET_V1 //just alias; used by tests


#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT          10000  //by default, blocks ids count in synchronizing
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT_PRE_V4       100    //by default, blocks count in blocks downloading
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT              20     //by default, blocks count in blocks downloading

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                    (86400*3) //seconds, three days
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME     604800 //seconds, one week

#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT           1000

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                  1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                   5000

#define P2P_DEFAULT_CONNECTIONS_COUNT                   8
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                  60           //secondes
#define P2P_DEFAULT_PACKET_MAX_SIZE                     50000000     //50000000 bytes maximum packet size
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                  250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                  5000       //5 seconds
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT             2000       //2 seconds
#define P2P_DEFAULT_INVOKE_TIMEOUT                      60*2*1000  //2 minutes
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT            5000       //5 seconds
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT       70
#define P2P_DEFAULT_ANCHOR_CONNECTIONS_COUNT            2

#define P2P_FAILED_ADDR_FORGET_SECONDS                  (60*60)     //1 hour
#define P2P_IP_BLOCKTIME                                (60*60*24)  //24 hour
#define P2P_IP_FAILS_BEFORE_BLOCK                       10
#define P2P_IDLE_CONNECTION_KILL_INTERVAL               (5*60) //5 minutes

#define P2P_SUPPORT_FLAG_FLUFFY_BLOCKS                  0x01
#define P2P_SUPPORT_FLAGS                               P2P_SUPPORT_FLAG_FLUFFY_BLOCKS

#define ALLOW_DEBUG_COMMANDS

#define CRYPTONOTE_NAME                         "hashcash"
#define CRYPTONOTE_POOLDATA_FILENAME            "poolstate.bin"
#define CRYPTONOTE_BLOCKCHAINDATA_FILENAME      "data.mdb"
#define CRYPTONOTE_BLOCKCHAINDATA_LOCK_FILENAME "lock.mdb"
#define P2P_NET_DATA_FILENAME                   "p2pstate.bin"
#define MINER_CONFIG_FILE_NAME                  "miner_conf.json"

#define THREAD_STACK_SIZE                       5 * 1024 * 1024

#define HF_VERSION_DYNAMIC_FEE                  4
#define HF_VERSION_MIN_MIXIN_4                  6
#define HF_VERSION_MIN_MIXIN_6                  7
#define HF_VERSION_ENFORCE_RCT                  6

#define PER_KB_FEE_QUANTIZATION_DECIMALS        2

#define HASH_OF_HASHES_STEP                     256

// used to overestimate the block reward when estimating a per kB to use
#define BLOCK_REWARD_OVERESTIMATE (10 * 1000000000000)
#define DEFAULT_TXPOOL_MAX_SIZE                 648000000ull // 3 days at 300000, in bytes

#define HARD_FORK_V2 28136
#define HARD_FORK_V3 28137
#define HARD_FORK_V4 28138
#define HARD_FORK_V5 28139
#define HARD_FORK_V6 28130
#define HARD_FORK_V7 28141
#define HARD_FORK_TILL_V1 HARD_FORK_V2 - 1

#define HARD_FORK_TIME_V2 1442763710
#define HARD_FORK_TIME_V3 1458558528
#define HARD_FORK_TIME_V4 1483574400
#define HARD_FORK_TIME_V5 1489520158
#define HARD_FORK_TIME_V6 1503046577
#define HARD_FORK_TIME_V7 1521303150

/*
Following struct is used in blockchain.cpp for hardforks list:

static const struct {
  uint8_t version;
  uint64_t height;
  uint8_t threshold;
  time_t time;
}
*/

#define MAINNET_HARD_FORKS { \
  { 1, 1, 0, 1341378000 }, \
  { 2, HARD_FORK_V2, 0, HARD_FORK_TIME_V2 }, \
  { 3, HARD_FORK_V3, 0, HARD_FORK_TIME_V3 }, \
  { 4, HARD_FORK_V4, 0, HARD_FORK_TIME_V4 }, \
  { 5, HARD_FORK_V5, 0, HARD_FORK_TIME_V5 }, \
  { 6, HARD_FORK_V6, 0, HARD_FORK_TIME_V6 }, \
  { 7, HARD_FORK_V7, 0, HARD_FORK_TIME_V7 }, \
}
  /*
  */

#define TESTNET_HARD_FORKS { \
  { 1, 1, 0, 1341378000 }, \
}

// New constants are intended to go here
namespace config
{
  uint64_t const DEFAULT_FEE_ATOMIC_XMR_PER_KB = 1; // Just a placeholder!  Change me!
  uint8_t const FEE_CALCULATION_MAX_RETRIES = 10;
  uint64_t const DEFAULT_DUST_THRESHOLD = ((uint64_t)1);
  uint64_t const BASE_REWARD_CLAMP_THRESHOLD = ((uint64_t)1); // pow(10, 8)
  std::string const P2P_REMOTE_DEBUG_TRUSTED_PUB_KEY = "0000000000000000000000000000000000000000000000000000000000000000";

  uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x6d72;
  uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x6d73;
  uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x6d74;
  uint16_t const P2P_DEFAULT_PORT = 8080;
  uint16_t const RPC_DEFAULT_PORT = 8081;
  uint16_t const ZMQ_RPC_DEFAULT_PORT = 8082;
  boost::uuids::uuid const NETWORK_ID = { {
      0x44 ,0x54, 0x35, 0x44, 0x84, 0x3A, 0x43, 0x54, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01
    } };
  std::string const GENESIS_TX = "010a01ff000a05029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880715a022a74a3c4c36d32e95633d44ba9a7b8188297b2ac91afecab826b86fabaa70916c8010252d128bc9913d5ee8b702c37609917c2357b2f587e5de5622348a3acd718e5d6d83602b8ed916c56b3a99c9cdf22c7be7ec4e85587e5d40bc46bf6995313c288ad841ee0d403021b452b4ac6c6419e06181f8c9f0734bd5bb132d8b75b44bbcd07dd8f553acba6a0f73602b10ba13e303cbe9abf7d5d44f1d417727abcc14903a74e071abd652ce1bf76dd8092f4010205e440069d10646f1bbfaeee88a2db218017941c5fa7280849126d2372fc64348095f52a029cad2882bba92fb7ecc8136475dae03169839eee05ff3ee3232d0136712f08b78084af5f02c574420256922b0783196e42c98156814e61d9ffa87c1262089be1d42e5f0d2780d0acf30e025a06e36efa49e1662243cee6e6fcf759a39792a9fe7ef80d1e6f98cfe8d489412101e2c32427f0c7fc22176b7edbe1c33b4f2493cdde8cb3f4a0a99724385b847012";
  uint32_t const GENESIS_NONCE = 10000;

  static const uint64_t hard_fork_version_1_till = HARD_FORK_TILL_V1;

  namespace testnet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 159;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 160;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 161;
    uint16_t const P2P_DEFAULT_PORT = 18080;
    uint16_t const RPC_DEFAULT_PORT = 18081;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 18082;
    boost::uuids::uuid const NETWORK_ID = { {
        0x44 ,0x54, 0x35, 0x44, 0x84, 0x3A, 0x43, 0x54, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01
      } };
    std::string const GENESIS_TX = "010a01ff000a05029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880715a022a74a3c4c36d32e95633d44ba9a7b8188297b2ac91afecab826b86fabaa70916c8010252d128bc9913d5ee8b702c37609917c2357b2f587e5de5622348a3acd718e5d6d83602b8ed916c56b3a99c9cdf22c7be7ec4e85587e5d40bc46bf6995313c288ad841ee0d403021b452b4ac6c6419e06181f8c9f0734bd5bb132d8b75b44bbcd07dd8f553acba6a0f73602b10ba13e303cbe9abf7d5d44f1d417727abcc14903a74e071abd652ce1bf76dd8092f4010205e440069d10646f1bbfaeee88a2db218017941c5fa7280849126d2372fc64348095f52a029cad2882bba92fb7ecc8136475dae03169839eee05ff3ee3232d0136712f08b78084af5f02c574420256922b0783196e42c98156814e61d9ffa87c1262089be1d42e5f0d2780d0acf30e025a06e36efa49e1662243cee6e6fcf759a39792a9fe7ef80d1e6f98cfe8d4894121019f83ca17ece14276e465b1c4cdb02595baf973d79fa5eef12d7d254626a375e3";
    /*
        0x12 ,0x30, 0xF1, 0x71 , 0x61, 0x04 , 0x41, 0x61, 0x17, 0x31, 0x00, 0x82, 0x16, 0xA1, 0xA1, 0x11
      } }; // Bender's daydream
    std::string const GENESIS_TX = "013c01ff0001ffffffffffff03029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121017767aafcde9be00dcfd098715ebcf7f410daebc582fda69d24a28e9d0bc890d1";
    */
    uint32_t const GENESIS_NONCE = 10001;

    static const uint64_t hard_fork_version_1_till = 2;
  }

  namespace stagenet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 24;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 25;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 36;
    uint16_t const P2P_DEFAULT_PORT = 38080;
    uint16_t const RPC_DEFAULT_PORT = 38081;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 38082;
    boost::uuids::uuid const NETWORK_ID = { {
        0x12 ,0x30, 0xF1, 0x71 , 0x61, 0x04 , 0x41, 0x61, 0x17, 0x31, 0x00, 0x82, 0x16, 0xA1, 0xA1, 0x12
      } }; // Bender's daydream
    std::string const GENESIS_TX = "013c01ff0001ffffffffffff0302df5d56da0c7d643ddd1ce61901c7bdc5fb1738bfe39fbe69c28a3a7032729c0f2101168d0c4ca86fb55a4cf6a36d31431be1c53a3bd7411bb24e8832410289fa6f3b";
    uint32_t const GENESIS_NONCE = 10002;
  }
}

namespace cryptonote
{
  enum network_type : uint8_t
  {
    MAINNET = 0,
    TESTNET,
    STAGENET,
    FAKECHAIN,
    UNDEFINED = 255
  };
  struct config_t
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX;
    uint16_t const P2P_DEFAULT_PORT;
    uint16_t const RPC_DEFAULT_PORT;
    uint16_t const ZMQ_RPC_DEFAULT_PORT;
    boost::uuids::uuid const NETWORK_ID;
    std::string const GENESIS_TX;
    uint32_t const GENESIS_NONCE;
  };
  inline const config_t& get_config(network_type nettype)
  {
    static const config_t mainnet = {
      ::config::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::P2P_DEFAULT_PORT,
      ::config::RPC_DEFAULT_PORT,
      ::config::ZMQ_RPC_DEFAULT_PORT,
      ::config::NETWORK_ID,
      ::config::GENESIS_TX,
      ::config::GENESIS_NONCE
    };
    static const config_t testnet = {
      ::config::testnet::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::testnet::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::testnet::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::testnet::P2P_DEFAULT_PORT,
      ::config::testnet::RPC_DEFAULT_PORT,
      ::config::testnet::ZMQ_RPC_DEFAULT_PORT,
      ::config::testnet::NETWORK_ID,
      ::config::testnet::GENESIS_TX,
      ::config::testnet::GENESIS_NONCE
    };
    static const config_t stagenet = {
      ::config::stagenet::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::stagenet::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::stagenet::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::stagenet::P2P_DEFAULT_PORT,
      ::config::stagenet::RPC_DEFAULT_PORT,
      ::config::stagenet::ZMQ_RPC_DEFAULT_PORT,
      ::config::stagenet::NETWORK_ID,
      ::config::stagenet::GENESIS_TX,
      ::config::stagenet::GENESIS_NONCE
    };
    switch (nettype)
    {
      case MAINNET: return mainnet;
      case TESTNET: return testnet;
      case STAGENET: return stagenet;
      case FAKECHAIN: return mainnet;
      default: throw std::runtime_error("Invalid network type");
    }
  };
}
