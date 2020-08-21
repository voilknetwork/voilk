#pragma once

#include <voilk/protocol/asset.hpp>

namespace voilk { namespace chain { namespace util {

using voilk::protocol::asset;
using voilk::protocol::price;

inline asset to_vsd( const price& p, const asset& voilk )
{
   FC_ASSERT( voilk.symbol == VOILK_SYMBOL );
   if( p.is_null() )
      return asset( 0, VSD_SYMBOL );
   return voilk * p;
}

inline asset to_voilk( const price& p, const asset& vsd )
{
   FC_ASSERT( vsd.symbol == VSD_SYMBOL );
   if( p.is_null() )
      return asset( 0, VOILK_SYMBOL );
   return vsd * p;
}

} } }
