#include <testing/testing.hpp>
#include <eoslib/print.hpp>

using namespace testing;
using namespace eos;

namespace testing {
  void sendMsg(Msg msg){
     msg::print();
  }   
} // namespace exchange

extern "C" {
   void init() {
   }

   void apply( uint64_t code, uint64_t action ) {
      if( code == N(testing) ) {
         switch( action ) {
            case N(msg):
               sendMsg( currentMessage<testing::Msg>() );
               break;
            default:
               assert( false, "unknown action" );
         }
      } 
   }
}
