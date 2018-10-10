#pragma once

#include <vector>

namespace bears{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   "seed-east.bearshares.com:2001",          // bearshares
   "seed-central.bearshares.com:2001",       // bearshares
   "seed-west.bearshares.com:2001",          // bearshares
   "bears-seed1.abit-more.com:2001",      // abit
   "52.74.152.79:2001",                   // smooth.witness
   "seed.bearsd.com:34191",               // roadscape
   "anyx.co:2001",                        // anyx
   "seed.xeldal.com:12150",               // xeldal
   "seed.bearsnodes.com:2001",            // wackou
   "seed.liondani.com:2016",              // liondani
   "gtg.bears.house:2001",                // gtg
   "seed.jesta.us:2001",                  // jesta
   "bearsd.pharesim.me:2001",             // pharesim
   "5.9.18.213:2001",                     // pfunk
   "lafonabears.com:2001",                // lafona
   "seed.rossco99.com:2001",              // rossco99
   "bears-seed.altcap.io:40696",          // ihashfury
   "seed.roelandp.nl:2001",               // roelandp
   "bears.global:2001",                   // klye
   "seed.ebears.ws:2001",                 // good-karma
   "seed.timcliff.com:2001",              // timcliff
   "104.199.118.92:2001",                 // clayop
   "seed.bearsviz.com:2001",              // ausbitbank
   "bears-seed.lukestokes.info:2001",     // lukestokes
   "seed.bearsian.info:2001",             // drakos
   "seed.followbtcnews.com:2001",         // followbtcnews
   "node.mahdiyari.info:2001",            // mahdiyari
   "seed.curiebears.com:2001",            // curie
   "seed.riverbears.com:2001",            // riverhead
   "148.251.237.104:2001",                // bears-bounty
   "seed1.blockbrothers.io:2001",         // blockbrothers
   "bearsseed-fin.privex.io:2001",        // privex
   "seed.jamzed.pl:2001",                 // jamzed
   "seed1.cryptobot.news:2001",           // libertyranger
   "seed.thecryptodrive.com:2001",        // thecryptodrive
   "seed.brandonfrye.us:2001",            // brandonfrye
   "seed.firepower.ltd:2001"              // firepower
};
#endif

} } } // bears::plugins::p2p
