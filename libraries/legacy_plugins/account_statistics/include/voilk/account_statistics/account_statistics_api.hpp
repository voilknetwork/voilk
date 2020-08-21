#pragma once

#include <voilk/account_statistics/account_statistics_plugin.hpp>

#include <fc/api.hpp>

namespace voilk { namespace app {
   struct api_context;
} }

namespace voilk { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl;
}

class account_statistics_api
{
   public:
      account_statistics_api( const voilk::app::api_context& ctx );

      void on_api_startup();

   private:
      std::shared_ptr< detail::account_statistics_api_impl > _my;
};

} } // voilk::account_statistics

FC_API( voilk::account_statistics::account_statistics_api, )