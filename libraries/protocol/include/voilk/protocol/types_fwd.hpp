#pragma once

namespace fc {
class uint128;
class variant;
} // fc

namespace voilk { namespace protocol {
template< typename Storage = fc::uint128 >
class fixed_string_impl;

class asset_symbol_type;
class legacy_voilk_asset_symbol_type;
struct legacy_voilk_asset;
} } // voilk::protocol

namespace fc { namespace raw {

template<typename Stream>
inline void pack( Stream& s, const uint128& u );
template<typename Stream>
inline void unpack( Stream& s, uint128& u );

template< typename Stream, typename Storage >
inline void pack( Stream& s, const voilk::protocol::fixed_string_impl< Storage >& u );
template< typename Stream, typename Storage >
inline void unpack( Stream& s, voilk::protocol::fixed_string_impl< Storage >& u );

template< typename Stream >
inline void pack( Stream& s, const voilk::protocol::asset_symbol_type& sym );
template< typename Stream >
inline void unpack( Stream& s, voilk::protocol::asset_symbol_type& sym );

template< typename Stream >
inline void pack( Stream& s, const voilk::protocol::legacy_voilk_asset_symbol_type& sym );
template< typename Stream >
inline void unpack( Stream& s, voilk::protocol::legacy_voilk_asset_symbol_type& sym );

} // raw

template< typename Storage >
inline void to_variant( const voilk::protocol::fixed_string_impl< Storage >& s, fc::variant& v );
template< typename Storage >
inline void from_variant( const variant& v, voilk::protocol::fixed_string_impl< Storage >& s );

inline void to_variant( const voilk::protocol::asset_symbol_type& sym, fc::variant& v );

inline void from_variant( const fc::variant& v, voilk::protocol::legacy_voilk_asset& leg );
inline void to_variant( const voilk::protocol::legacy_voilk_asset& leg, fc::variant& v );

} // fc
