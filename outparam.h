#include <utility>

template<typename T>
class Out
{
   private:
   struct OutRefHolder
   {
     T& ref_;
     explicit OutRefHolder(T& ref) : ref_(ref) 
     {}
    };

   public:
   Out(OutRefHolder&& oref) : ref_(oref.ref_)
   {}
   Out(Out&& o) : ref_(o.ref_)
   {}

   template <typename Q>
   void operator=(Q&& q)
   {
     ref_ = std::forward<Q>(q);
   }

   template <typename Y>
   friend typename Out<Y>::OutRefHolder out(Y& ref);

   private:
   Out(const Out&);
   Out();

   T& ref_;
};

template <typename Y>
typename Out<Y>::OutRefHolder out(Y& ref)
{
  return typename Out<Y>::OutRefHolder(ref);
}

   

 
