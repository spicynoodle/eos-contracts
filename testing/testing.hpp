#include <eoslib/eos.hpp>

namespace testing {

   struct Msg {
      AccountName name    = 0;
      
      void print(){
        eos::print("Name: TODO");
      }
   };
