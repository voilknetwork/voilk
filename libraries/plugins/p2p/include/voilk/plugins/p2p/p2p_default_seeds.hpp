#pragma once

#include <vector>

namespace voilk{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   "seed.voilk.com:3331"
};
#endif

} } } // voilk::plugins::p2p
