#pragma once
#include <voilk/plugins/block_api/block_api_objects.hpp>

#include <voilk/protocol/types.hpp>
#include <voilk/protocol/transaction.hpp>
#include <voilk/protocol/block_header.hpp>

#include <voilk/plugins/json_rpc/utility.hpp>

namespace voilk { namespace plugins { namespace block_api {

/* get_block_header */

struct get_block_header_args
{
   uint32_t block_num;
};

struct get_block_header_return
{
   optional< block_header > header;
};

/* get_block */
struct get_block_args
{
   uint32_t block_num;
};

struct get_block_return
{
   optional< api_signed_block_object > block;
};

} } } // voilk::block_api

FC_REFLECT( voilk::plugins::block_api::get_block_header_args,
   (block_num) )

FC_REFLECT( voilk::plugins::block_api::get_block_header_return,
   (header) )

FC_REFLECT( voilk::plugins::block_api::get_block_args,
   (block_num) )

FC_REFLECT( voilk::plugins::block_api::get_block_return,
   (block) )

