#pragma once

#include <vector>

namespace bears{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   "seed.bearshares.com:3331"
};
#endif

} } } // bears::plugins::p2p
