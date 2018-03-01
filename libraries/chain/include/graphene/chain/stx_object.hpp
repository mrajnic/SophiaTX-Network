#pragma once

#include <graphene/chain/protocol/types.hpp>
#include <graphene/db/object.hpp>
#include <graphene/db/generic_index.hpp>

#include <fc/reflect/reflect.hpp>
#include <fc/time.hpp>

#include <boost/multi_index/composite_key.hpp>

namespace graphene { namespace chain{

class stx_object : public graphene::db::abstract_object< stx_object >
      {
      public:
         static const uint8_t space_id = implementation_ids;
         static const uint8_t type_id  = impl_stx_object_type;

         account_id_type sender;
         account_id_type receiver;
         string method_type;
         string data;
         time_point_sec created;
         uint32_t block_num;
      };

      struct by_sender;
      struct by_receiver;

      typedef multi_index_container<
      stx_object,
      indexed_by<
         ordered_unique< tag< by_id>,
            member< object, object_id_type, &object::id >
      >,
      ordered_non_unique< tag< by_sender>,
      member<stx_object, account_id_type, &stx_object::sender>
      >,
      ordered_non_unique< tag< by_receiver>,
      member<stx_object, account_id_type, &stx_object::receiver>
      >
      >
      >stx_object_multi_index_type;

      typedef generic_index< stx_object, stx_object_multi_index_type > stx_index;

}}

FC_REFLECT_DERIVED(graphene::chain::stx_object, (graphene::db::object), (sender)(receiver)(method_type)(data)(created)(block_num) )
