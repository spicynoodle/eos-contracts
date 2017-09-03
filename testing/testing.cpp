#include <testing/testing.hpp> /// defines transfer struct
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
      /*
      setAuthority( "currencya", "transfer", "anyone" );
      setAuthority( "currencyb", "transfer", "anyone" );
      registerHandler( "apply", "currencya", "transfer" );
      registerHandler( "apply", "currencyb", "transfer" );
      */
   }

//   void validate( uint64_t code, uint64_t action ) { }
//   void precondition( uint64_t code, uint64_t action ) { }
   /**
    *  The apply method implements the dispatch of events to this contract
    */
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
