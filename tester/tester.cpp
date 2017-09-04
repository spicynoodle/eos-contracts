#include <tester/tester.hpp>
#include <eoslib/print.hpp>

namespace tester {
   using namespace eos;

   void sendMsg( const tester::Message& msg ) {
      print("Hello, World: ");
      print(*(msg.message));
      print("\n");
   }
}

using namespace tester;

extern "C" {
    void init()  {}

    void apply( uint64_t code, uint64_t action ) {
       if( code == N(tester) ) {
          if( action == N(message) ) 
             tester::sendMsg( currentMessage< tester::Message >() );
      }
    }
}
