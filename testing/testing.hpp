
namespace testing {

   struct Msg {
      AccountName name    = 0;
      
      void print(){
        eos::print("Name: " + name);
      }
   };
