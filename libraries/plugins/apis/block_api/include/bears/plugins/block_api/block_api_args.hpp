#pragma once
#include <bears/plugins/block_api/block_api_objects.hpp>

#include <bears/protocol/types.hpp>
#include <bears/protocol/transaction.hpp>
#include <bears/protocol/block_header.hpp>

#include <bears/plugins/json_rpc/utility.hpp>

namespace bears { namespace plugins { namespace block_api {

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

} } } // bears::block_api

FC_REFLECT( bears::plugins::block_api::get_block_header_args,
   (block_num) )

FC_REFLECT( bears::plugins::block_api::get_block_header_return,
   (header) )

FC_REFLECT( bears::plugins::block_api::get_block_args,
   (block_num) )

FC_REFLECT( bears::plugins::block_api::get_block_return,
   (block) )

